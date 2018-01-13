#ifndef __DB_MANAMER__H__
#define __DB_MANAMER__H__
#include <vector>
#include "MysqlDBProcess.h"
#include "UserData.h"
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif
#include "..\3rd\redis-3.0\deps\hiredis\hiredis.h"
#ifdef __cplusplus
}
#endif

extern enum e_redis_name;

#define DB_COMMAND_LEN       512
#define DB_LOADREDIS_MAX     15000      //加载到redis的最大用户量

class CDBManager :public mysql::CQuery
{
private:
	redisContext *m_pRedisContext;
	char   m_command[DB_COMMAND_LEN];
	char   m_szAccountName[USER_NAME_MAX_LEN + 1];  //玩家帐号
	char   m_szRoleName[USER_NAME_MAX_LEN + 1];     //玩机角色名
	char **m_key;

	CUserData      *m_pUserData;
	vector<string>  m_vecData;
public:
	CDBManager();
	virtual ~CDBManager();

private:
	void InitRedisName();
	bool BindUserInfo(QueryResult *qr, CUserData *pUserData, bool ismult = false);
	bool IsUserInRedis(DWORD dwUserID);
	bool VExecDB(QueryResult *qr, const char *format, va_list header, Arguments args = Arguments(0, 0));
	bool ExecDB(QueryResult *qr, const char *format, ...);

	/**********************************************************
	DB2Redis和Redis2Memory参数CPlayer改成定义的其它类，达到重载目的
	************************************************************/
	//加载数据到redis
	void DB2Redis(CUserData *pUserData);
	//加载redis数据到内存
	void Redis2Memory(CUserData *pUserData, DWORD dwUserID);
	void Redis2Memory(CUserData *pUserData, char *rolename);

	//获取用户字符数据
	void GetUserStrData(redisReply* rp, char* pDestBuf, DWORD dwDestBufLen);

	//操作redis函数
private:
	//reids写操作(大部分操作：hset、hdel、del、sadd等都可以调用此函数)
	bool redis_write(const char *format, va_list header);
	bool redis_write(const char *format, ...);

	bool redis_hset(const char *format, ...);
	bool redis_sadd(const char *format, ...);
	bool redis_del(const char *format, ...);
	bool redis_sismember(const char *format, ...);
	bool redis_hmset(const char *format, ...);

	redisReply* redis_spop(const char *format, ...);
	redisReply* redis_hget(const char *format, ...);
	redisReply* redis_sscan(const char *format, ...);
	redisReply* redis_hmget(const char *format, ...);

private:
	//update insert delete...
	bool UpdateDBData(const char *sql, ...);
	bool UpdateDBData(Arguments args, const char *sql, ...);

	//加载数据到redis
	CUserData *LoadUserData(DWORD dwUserID);
	CUserData *LoadUserData(char *rolename);
	CUserData *LoadUserDataByAccount(char *account);
	//移除数据
	void RemoveUserFromRedis(DWORD dwUserID);
	//卸载数据
	//nojudge:判断是否存在该用户（false:需要判断,true:不判断）
	void UnLoadUserData(DWORD dwUserID, bool nojudge = false);

	//获取redis集合中数据
	void GetRedisSetData(vector<string>* pVecData, char* pSetKey)
	{
		redisReply *rp = redis_sscan("sscan %s 0", pSetKey);

		while (rp)
		{
			int left = 0;
			if (REDIS_REPLY_ARRAY == rp->type && 2 == rp->elements)
			{
				redisReply *rp1 = rp->element[0]; //rp1->str is the itertor
				redisReply *rp2 = rp->element[1]; //rp2->element is the data
				if (REDIS_REPLY_STRING == rp1->type) left = atoi(rp1->str);

				int elements = rp2->elements;
				if (elements > 0)
				{
					for (int i = 0; i < elements; i++)
					{
						redisReply *rp_ele = rp2->element[i];

						switch (rp_ele->type)
						{
						case REDIS_REPLY_INTEGER:
						{
							char buf[20];
							memset(buf, 0, sizeof(buf));
							_i64toa(rp_ele->integer, buf, 10);
							pVecData->push_back(buf);
						}
							break;
						case REDIS_REPLY_STRING:
							pVecData->push_back(rp_ele->str);
							break;
						default:
							break;
						}
					}
				}
			}

			freeReplyObject(rp);

			//next iterator
			if (left > 0)
				rp = redis_sscan("sscan %s %d", pSetKey, left);
			else
				break;
		}
	}

public:
	bool InitRedis(char *ip, int port);

	//开服加载
	void LoadUserData();

	//关服保存
	//quit:是否是关服
	void SaveUserData(bool quit = false);

	//保存数据
	void SaveUserData(DWORD dwUserID, bool nojudge = false);

	//获取角色名
	char *GetUserName(DWORD dwUserID);
	//获取账号
	char *GetUserAccount(DWORD dwUserID);
	//获取用户ID
	DWORD GetUserID(char *rolename);

	//获取用户数据,redis没有则从数据库拉
	CUserData *GetUserData(DWORD dwUserID);
	CUserData *GetUserData(char *rolename);

	bool GetRoleListByAccount(char* buffer, DWORD dwSize, char *account);
};

#define UPDATE_USER_DATA          "update UserInfo set money = %d, diamond = %d, point = %d, LastLoginTime = now() where RoleID = %d"
#define UPDATE_USER_DATA_BIND     "update UserInfo set money = ?,  diamond = ?,  point = ?   where RoleID = %d"

#endif