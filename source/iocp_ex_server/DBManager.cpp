
#include <sstream>
#include "DBManager.h"
using namespace std;

#ifdef _MSC_VER
#ifdef _WIN64
#pragma comment(lib, "..\\3rd\\redis-3.0\\bin\\x64\\hiredis.lib")
#pragma comment(lib, "..\\3rd\\redis-3.0\\bin\\x64\\Win32_Interop.lib")
#else
#pragma comment(lib, "..\\3rd\\redis-3.0\\bin\\Win32\\hiredis.lib")
#pragma comment(lib, "..\\3rd\\redis-3.0\\bin\\Win32\\Win32_Interop.lib")
#endif
#endif

#define REDIS_MAX_NUM       100  //redis最大字符限制长度(set/list/hash名最大数)
#define REDIS_MAX_LEN       32   //redis字符最大长度


#define DB_TABLE_USERINFO  "userinfo"
#define REDIS_TYPE_SET     "set"
#define REDIS_TYPE_HASH    "hash"

enum e_redis_name
{
	e_userinfo_all = 0,
	e_userinfo_account_set,
	e_userinfo_roleid_set,

	e_userinfo_roleid_account,
	e_userinfo_roleid_pwd,
	e_userinfo_roleid_rolename,
	e_userinfo_rolename_roleid,


	e_name_max = REDIS_MAX_NUM,
};

enum e_userdata
{
	e_usermoney = 0,
	e_userdiamond,
	e_userpoint,


	e_userdatamax,
};

static const char *const g_userdata[e_userdatamax] = {
	" money ", " diamond ", " point "
};

CDBManager::CDBManager()
{
	m_pRedisContext = NULL;
	m_pUserData = NULL;

	m_key = new char*[REDIS_MAX_NUM];
	memset(m_key, 0, REDIS_MAX_NUM);
	for (int i = 0; i < REDIS_MAX_NUM; i++)
	{
		m_key[i] = new char[REDIS_MAX_LEN];
		memset(m_key[i], 0, REDIS_MAX_LEN);
	}

	m_pUserData = new CUserData;
	m_vecData.clear();

	InitRedisName();
}

CDBManager::~CDBManager()
{
	if (m_key)
	{
		for (int i = 0; i < REDIS_MAX_NUM; i++)
		{
			delete[]m_key[i];
		}
		delete[]m_key;
	}
	m_vecData.clear();
	delete m_pUserData;
}

void CDBManager::InitRedisName()
{
	strcpy(m_key[e_userinfo_account_set], "userinfo_account_set");
	strcpy(m_key[e_userinfo_roleid_set], "userinfo_userid_set");
	strcpy(m_key[e_userinfo_roleid_account], "userinfo_account_hash");
	strcpy(m_key[e_userinfo_roleid_pwd], "userinfo_pwd_hash");
	strcpy(m_key[e_userinfo_roleid_rolename], "userinfo_rolename_hash");
	strcpy(m_key[e_userinfo_rolename_roleid], "userinfo_rnrid_hash");
}

//记得把mysql的dll库文件放在 exe目录/工程调试目录(调试时) 下!!!
//否则会出现各种错误,比如返回101错误(MYSQL_DATA_TRUNCATED)...
bool CDBManager::BindUserInfo(QueryResult *qr, CUserData *pUserData, bool ismult/* = false*/)
{
	//获取玩家数据字段太多,用new,在堆中分配内存，而不是栈，查询字段
	//较少的数据，可以直接用栈!!如可以这样:QueryBind<2> bind;
	QueryBind< 7 > *bind = new QueryBind < 7 > ;

	(*bind)[0].BindString(pUserData->m_szAccountName, sizeof(pUserData->m_szAccountName));
	(*bind)[1].BindString(pUserData->m_szPassWord, sizeof(pUserData->m_szPassWord));
	(*bind)[2].BindLong((long*)&pUserData->m_dwRoleID);
	(*bind)[3].BindString(pUserData->m_szRoleName, sizeof(pUserData->m_szRoleName));
	(*bind)[4].BindLong((long*)&pUserData->m_dwMoney);
	(*bind)[5].BindLong((long*)&pUserData->m_dwDiamond);
	(*bind)[6].BindLong((long*)&pUserData->m_dwPoint);

	if (ismult)
	{
		bool flag = false;
		int ret = qr->FetchResult(*bind);
		while (ret == 0)
		{
			DB2Redis(pUserData);
			Log("LoadUserData roleid = %d", pUserData->m_dwRoleID);
			flag = true;
			ret = qr->FetchResult(*bind);
		}

		delete[]bind;
		if (!flag) Log("BindUserInfo errid=%d:%s.", ret, MysqlError());
		return true;
	}
	else
	{
		if (qr->FetchResult(*bind) == 0)
		{
			DB2Redis(pUserData);
			delete[]bind;
			return true;
		}
	}


	//获取玩家数据字段太多,用new,在堆中分配内存，而不是栈，查询字段
	//较少的数据，可以直接用栈!!如可以这样:QueryBind<2> bind;
	//QueryBind< 8 > bind;

	//bind[0].BindString(pUserData->m_szAccountName, sizeof(pUserData->m_szAccountName));
	//bind[1].BindString(pUserData->m_szPassWord, sizeof(pUserData->m_szPassWord));
	//bind[2].BindLong((long*)&pUserData->m_dwRoleID);
	//bind[3].BindString(pUserData->m_szRoleName, sizeof(pUserData->m_szRoleName));
	//bind[4].BindLong((long*)&pUserData->m_dwMoney);
	//bind[5].BindLong((long*)&pUserData->m_dwDiamond);
	//bind[6].BindLong((long*)&pUserData->m_dwPoint);

	//if (ismult)
	//{
	//	while (qr->FetchResult(bind) == 0)
	//	{
	//		DB2Redis(pUserData);
	//	}
	//	return true;
	//}
	//else
	//{
	//	if (qr->FetchResult(bind) == 0)
	//	{
	//		DB2Redis(pUserData);
	//		return true;
	//	}
	//}

	return false;
}

bool CDBManager::IsUserInRedis(DWORD dwUserID)
{
	if (redis_sismember("sismember %s %d", m_key[e_userinfo_roleid_set], dwUserID))
		return true;
	return false;
}

bool CDBManager::InitRedis(char *ip, int port)
{
	//初始化redis并链接
	//WSADATA wsaData;
	//WSAStartup(MAKEWORD(2, 1), &wsaData);
	Log("connecting redis server...");
	m_pRedisContext = redisConnect(ip, port);
	if (m_pRedisContext->err) {
		redisFree(m_pRedisContext);
		Log("connecting redis server failed.");
		return false;
	}
	Log("connecting redis server success.");
	return true;
}

bool CDBManager::VExecDB(QueryResult *qr, const char *format, va_list header, Arguments args)
{
	vsprintf_s(m_command, DB_COMMAND_LEN, format, header);

	qr->Reset();
	if (/*ExecuteSql*/ExecuteStmt(m_command, strlen(m_command), qr, args) == 0 && qr->AffectedRows() > 0)
	{
		return true;
	}
	return false;
}

bool CDBManager::ExecDB(QueryResult *qr, const char *format, ...)
{
	va_list header;
	va_start(header, format);
	vsprintf_s(m_command, DB_COMMAND_LEN, format, header);
	va_end(header);

	qr->Reset();
	if (/*ExecuteSql*/ExecuteStmt(m_command, strlen(m_command), qr) == 0 && qr->AffectedRows() > 0)
	{
		return true;
	}
	return false;
}

bool CDBManager::UpdateDBData(const char *sql, ...)
{
	bool ret = false;

	if (KeepAlive(0))
	{
		QueryResult qr;

		va_list header;
		va_start(header, sql);
		ret = VExecDB(&qr, sql, header);
		va_end(header);
	}
	return ret;
}

bool CDBManager::UpdateDBData(Arguments args, const char *sql, ...)
{
	bool ret = false;

	if (KeepAlive(0))
	{
		QueryResult qr;

		va_list header;
		va_start(header, sql);
		ret = VExecDB(&qr, sql, header, args);
		va_end(header);
	}
	return ret;
}

bool CDBManager::redis_write(const char *format, va_list header)
{
	redisReply* rp = (redisReply*)redisvCommand(m_pRedisContext, format, header);

	if (NULL == rp) return false;

	if (rp->type == REDIS_REPLY_INTEGER/* && 1 == rp->integer*/)
	{
		freeReplyObject(rp);
		return true;
	}

	freeReplyObject(rp);
	return false;
}

bool CDBManager::redis_write(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisvCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return false;

	if (rp->type == REDIS_REPLY_INTEGER/* && 1 == rp->integer*/)
	{
		freeReplyObject(rp);
		return true;
	}

	freeReplyObject(rp);
	return false;
}

bool CDBManager::redis_hset(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	bool ret = redis_write(format, header);
	va_end(header);

	return ret;
}

bool CDBManager::redis_sadd(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	bool ret = redis_write(format, header);
	va_end(header);

	return ret;
}

bool CDBManager::redis_del(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	bool ret = redis_write(format, header);
	va_end(header);

	return ret;
}

redisReply* CDBManager::redis_hget(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisvCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return NULL;

	if (rp->type != REDIS_REPLY_STRING)
	{
		freeReplyObject(rp);
		return NULL;
	}

	return rp;
}

redisReply* CDBManager::redis_sscan(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisvCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return NULL;

	if (rp->type != REDIS_REPLY_ARRAY)
	{
		freeReplyObject(rp);
		return NULL;
	}

	return rp;
}

redisReply* CDBManager::redis_hmget(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisvCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return NULL;

	if (rp->type != REDIS_REPLY_ARRAY)
	{
		freeReplyObject(rp);
		return NULL;
	}

	return rp;
}

bool CDBManager::redis_sismember(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisvCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return false;

	if (rp->type == REDIS_REPLY_INTEGER && 1 == rp->integer)
	{
		freeReplyObject(rp);
		return true;
	}

	freeReplyObject(rp);
	return false;
}

bool CDBManager::redis_hmset(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisvCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return false;

	if (rp->type == REDIS_REPLY_STATUS && strcmp(rp->str, "OK") == 0)
	{
		freeReplyObject(rp);
		return true;
	}

	freeReplyObject(rp);
	return false;
}

redisReply* CDBManager::redis_spop(const char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisvCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return NULL;

	if (rp->type != REDIS_REPLY_STRING)
	{
		freeReplyObject(rp);
		return NULL;
	}

	return rp;
}

void CDBManager::DB2Redis(CUserData *pUserData)
{
	if (!pUserData) return;

	//集合
	redis_sadd("sadd %s %s", m_key[e_userinfo_account_set], pUserData->m_szAccountName);
	redis_sadd("sadd %s %d", m_key[e_userinfo_roleid_set], pUserData->m_dwRoleID);
	redis_sadd("sadd %s %s", pUserData->m_szAccountName, pUserData->m_szRoleName);

	//字符串
	redis_hset("hset %s %d %s", m_key[e_userinfo_roleid_account], pUserData->m_dwRoleID, pUserData->m_szAccountName);
	redis_hset("hset %s %d %s", m_key[e_userinfo_roleid_pwd], pUserData->m_dwRoleID, pUserData->m_szPassWord);
	redis_hset("hset %s %d %s", m_key[e_userinfo_roleid_rolename], pUserData->m_dwRoleID, pUserData->m_szRoleName);
	redis_hset("hset %s %s %d", m_key[e_userinfo_rolename_roleid], pUserData->m_szRoleName, pUserData->m_dwRoleID);

	//数字
	stringstream redisCmd;
	redisCmd << "hmset role_" << pUserData->m_dwRoleID <<
		g_userdata[e_usermoney] << pUserData->m_dwMoney <<
		g_userdata[e_userdiamond] << pUserData->m_dwDiamond <<
		g_userdata[e_userpoint] << pUserData->m_dwPoint;
	string cmd = redisCmd.str();
	redis_hmset(cmd.c_str());
}

void CDBManager::GetUserStrData(redisReply* rp, char* pDestBuf, DWORD dwDestBufLen)
{
	if (rp)
	{
		if (rp->str)
		{
			memcpy(pDestBuf, rp->str, dwDestBufLen);
		}
		freeReplyObject(rp);
	}
}

void CDBManager::Redis2Memory(CUserData *pUserData, DWORD dwUserID)
{
	if (!pUserData || 0 == dwUserID) return;

	pUserData->m_dwRoleID = dwUserID;

	redisReply* rp = redis_hget("hget %s %d", m_key[e_userinfo_roleid_account], dwUserID);
	GetUserStrData(rp, pUserData->m_szAccountName, sizeof(pUserData->m_szAccountName));

	rp = redis_hget("hget %s %d", m_key[e_userinfo_roleid_pwd], dwUserID);
	GetUserStrData(rp, pUserData->m_szPassWord, sizeof(pUserData->m_szPassWord));

	rp = redis_hget("hget %s %d", m_key[e_userinfo_roleid_rolename], dwUserID);
	GetUserStrData(rp, pUserData->m_szRoleName, sizeof(pUserData->m_szRoleName));


	stringstream redisCmd;
	redisCmd << "hmget role_" << dwUserID <<
		g_userdata[e_usermoney] << g_userdata[e_userdiamond] << g_userdata[e_userpoint];
	string cmd = redisCmd.str();
	rp = redis_hmget(cmd.c_str());
	if (rp)
	{
		redisReply *rptemp;
		for (int i = 0; i < rp->elements; i++)
		{
			rptemp = rp->element[i];
			switch (i)
			{
			case e_usermoney:
				pUserData->m_dwMoney = rptemp->type == REDIS_REPLY_NIL ? 0 : atoi(rptemp->str);
				break;
			case e_userdiamond:
				pUserData->m_dwDiamond = rptemp->type == REDIS_REPLY_NIL ? 0 : atoi(rptemp->str);
				break;
			case e_userpoint:
				pUserData->m_dwPoint = rptemp->type == REDIS_REPLY_NIL ? 0 : atoi(rptemp->str);
				break;
			default:
				break;
			}
		}
	}
}

void CDBManager::Redis2Memory(CUserData *pUserData, char *rolename)
{
	if (!pUserData) return;

	DWORD dwUserID = 0;
	redisReply* rp = redis_hget("hget %s %s", m_key[e_userinfo_rolename_roleid], rolename);
	if (rp)
	{
		if (rp->str)
		{
			dwUserID = atoi(rp->str);
		}
		freeReplyObject(rp);
	}

	Redis2Memory(pUserData, dwUserID);
}

//开服加载
void CDBManager::LoadUserData()
{
	if (KeepAlive(0))
	{
		QueryResult qr;
		if (ExecDB(&qr, "CALL SP_LoadData"))
		{
			m_pUserData->Reset();
			BindUserInfo(&qr, m_pUserData, true);
		}
	}
}

//关服保存
void CDBManager::SaveUserData(bool quit/* = false*/)
{
	if (quit)
	{
		redisReply *rp = redis_spop("spop %s", m_key[e_userinfo_roleid_set]);
		while (rp)
		{
			if (rp->str)
			{
				DWORD dwUserID = 0;
				dwUserID = atoi(rp->str);
				if (dwUserID > 0)
				{
					UnLoadUserData(dwUserID, true);
				}
			}
			freeReplyObject(rp);
			rp = redis_spop("spop %s", m_key[e_userinfo_roleid_set]);
		}
	}
	else
	{
		m_vecData.clear();
		GetRedisSetData(&m_vecData, m_key[e_userinfo_roleid_set]);
		vector<string>::iterator it = m_vecData.begin();
		for (; it != m_vecData.end(); it++)
		{
			DWORD dwUserID = atoi((*it).c_str());
			SaveUserData(dwUserID, true);
		}
		m_vecData.clear();
	}
}

//加载数据
CUserData *CDBManager::LoadUserData(DWORD dwUserID)
{
	if (KeepAlive(0))
	{
		QueryResult qr;
		if (ExecDB(&qr, "CALL SP_LoadUserData_UserID (%d)", dwUserID))
		{
			m_pUserData->Reset();
			if (BindUserInfo(&qr, m_pUserData, false))
			{
				return m_pUserData;
			}
		}
	}

	return NULL;
}

//加载数据
CUserData *CDBManager::LoadUserData(char *rolename)
{
	if (KeepAlive(0))
	{
		QueryResult qr;
		if (ExecDB(&qr, "CALL SP_LoadUserData_RoleName (%s)", rolename))
		{
			m_pUserData->Reset();

			if (BindUserInfo(&qr, m_pUserData, false))
			{
				return m_pUserData;
			}
		}
	}

	return NULL;
}

CUserData *CDBManager::LoadUserDataByAccount(char *account)
{
	if (KeepAlive(0))
	{
		QueryResult qr;
		if (ExecDB(&qr, "CALL SP_LoadUserData_Account (%s)", account))
		{
			m_pUserData->Reset();

			if (BindUserInfo(&qr, m_pUserData, true))
			{
				return m_pUserData;
			}
		}
	}
	return NULL;
}

void CDBManager::RemoveUserFromRedis(DWORD dwUserID)
{
	char *rolename = GetUserName(dwUserID);
	char *account = GetUserAccount(dwUserID);

	redis_del("srem %s %s", m_key[e_userinfo_account_set], account);
	redis_del("srem %s %d", m_key[e_userinfo_roleid_set], dwUserID);
	redis_del("srem %s %s", account, rolename);

	redis_del("hdel %s %d", m_key[e_userinfo_roleid_account], dwUserID);
	redis_del("hdel %s %d", m_key[e_userinfo_roleid_pwd], dwUserID);
	redis_del("hdel %s %d", m_key[e_userinfo_roleid_rolename], dwUserID);
	redis_del("hdel %s %s", m_key[e_userinfo_rolename_roleid], rolename);

	//后面加的一些数据还未做删除处理 whb
}

//卸载数据
void CDBManager::UnLoadUserData(DWORD dwUserID, bool nojudge/* = false*/)
{
	if (!nojudge && !IsUserInRedis(dwUserID))
		return;

	SaveUserData(dwUserID, nojudge);
	//RemoveUserFromRedis(dwUserID); //whb
}

//保存数据
void CDBManager::SaveUserData(DWORD dwUserID, bool nojudge/* = false*/)
{
	if (!nojudge && !IsUserInRedis(dwUserID))
		return;

	m_pUserData->Reset();
	Redis2Memory(m_pUserData, dwUserID);
	bool ret = false;
	//1
	ret = UpdateDBData(UPDATE_USER_DATA, m_pUserData->m_dwMoney, m_pUserData->m_dwDiamond, m_pUserData->m_dwPoint, dwUserID);

	//2
	//QueryBind<3> args;
	//args[0].BindULong(&dwMoney);
	//args[1].BindULong(&dwDiamond);
	//args[2].BindULong(&dwPoint);
	//ret = UpdateDBData(args, UPDATE_USER_DATA_BIND, dwUserID);

	//1、数据库操作失败ret为false;2、更新数据未变化ret为false
	Log("SaveUserData roleid = %d, success = %s", dwUserID, ret ? "true" : "false");
}

//获取角色名
char *CDBManager::GetUserName(DWORD dwUserID)
{
	redisReply *rp = redis_hget("hget %s %d", m_key[e_userinfo_roleid_rolename], dwUserID);
	m_szRoleName[0] = 0;
	if (rp)
	{
		if (rp->str)
		{
			int len = min(strlen(rp->str), USER_NAME_MAX_LEN);
			memcpy(m_szRoleName, rp->str, len);
			m_szRoleName[len] = 0;
		}
		freeReplyObject(rp);
	}

	return m_szRoleName;
}

//获取账户名
char *CDBManager::GetUserAccount(DWORD dwUserID)
{
	redisReply *rp = redis_hget("hget %s %d", m_key[e_userinfo_roleid_account], dwUserID);
	m_szAccountName[0] = 0;
	if (rp)
	{
		if (rp->str)
		{
			int len = min(strlen(rp->str), USER_NAME_MAX_LEN);
			memcpy(m_szAccountName, rp->str, len);
			m_szAccountName[len] = 0;
		}
		freeReplyObject(rp);
	}

	return m_szAccountName;
}

//获取用户ID
DWORD CDBManager::GetUserID(char *rolename)
{
	redisReply *rp = redis_hget("hget %s %s", m_key[e_userinfo_rolename_roleid], rolename);
	DWORD dwUserID = 0;
	if (rp)
	{
		if (rp->str) dwUserID = atoi(rp->str);
		freeReplyObject(rp);
	}

	return dwUserID;
}

//获取用户数据,redis没有则从数据库拉
CUserData *CDBManager::GetUserData(DWORD dwUserID)
{
	if (IsUserInRedis(dwUserID))
	{
		m_pUserData->Reset();
		Redis2Memory(m_pUserData, dwUserID);
		return m_pUserData;
	}
	else
	{
		return LoadUserData(dwUserID);
	}

	return NULL;
}

CUserData *CDBManager::GetUserData(char *rolename)
{
	redisReply *rp = redis_hget("hget %s %s", m_key[e_userinfo_rolename_roleid], rolename);

	DWORD dwUserID = 0;
	if (rp && rp->str) dwUserID = atoi(rp->str);
	if (rp) freeReplyObject(rp);

	if (dwUserID > 0)
	{
		m_pUserData->Reset();
		Redis2Memory(m_pUserData, dwUserID);
		return m_pUserData;
	}
	else
	{
		return LoadUserData(rolename);
	}

	return NULL;
}

//"zhangsan|lisi|hehe"
bool CDBManager::GetRoleListByAccount(char* buffer, DWORD dwSize, char *account)
{
	m_vecData.clear();
	GetRedisSetData(&m_vecData, account);
	if (m_vecData.size() > 0)
	{
		vector<string>::iterator it = m_vecData.begin();
		int nLen = 0;
		for (; it != m_vecData.end(); it++)
		{
			const char* str = (*it).c_str();
			int nLenTmp = strlen(str);
			if (dwSize > nLenTmp)
			{
				strcat(buffer + nLen, str);
				nLen += nLenTmp;
				dwSize -= nLenTmp;
				if (dwSize > 1)
				{
					strcat(buffer + nLen, "|");
					nLen += 1;
					dwSize -= 1;
				}
				else break;
			}
			else
			{
				m_vecData.clear();
				Log("get rolelist buffer too short!!! %s", account);
				return false;
			}
		}
		m_vecData.clear();
		return true;
	}

	return false;
}