#include "DBServer.h"

#ifdef _WIN64
#pragma comment(lib, "..\\3rd\\redis-3.0\\bin\\x64\\hiredis.lib")
#pragma comment(lib, "..\\3rd\\redis-3.0\\bin\\x64\\Win32_Interop.lib")
#else
#pragma comment(lib, "..\\3rd\\redis-3.0\\bin\\Win32\\hiredis.lib")
#pragma comment(lib, "..\\3rd\\redis-3.0\\bin\\Win32\\Win32_Interop.lib")
#endif

#define REDIS_MAX_NUM       100  //redis最大数(set/list/hash名最大数)
#define REDIS_MAX_LEN       32   //redis字符最大长度


#define DB_TABLE_USERINFO  "userinfo"
#define REDIS_TYPE_SET     "set"
#define REDIS_TYPE_HASH    "hash"

enum e_redis_name
{
    e_userinfo_account_set = 0,
	e_userinfo_userid_set,
	e_userinfo_account_roleid,   //key:account=userid
	e_userinfo_account,
	e_userinfo_rolename_roleid,  //key:rolename=userid
	e_userinfo_rolename,
	e_userinfo_money,
	e_userinfo_diamond,
	e_userinfo_point,


	e_name_max = REDIS_MAX_NUM,
};

CDBServer::CDBServer()
{
	m_pRedisContext = NULL;

	m_key = new char*[REDIS_MAX_NUM];
	memset(m_key, 0, REDIS_MAX_NUM);
	for (int i = 0; i < REDIS_MAX_NUM; i++)
	{
		m_key[i] = new char[REDIS_MAX_LEN];
		memset(m_key[i], 0, REDIS_MAX_LEN);
	}
	
	InitRedisName();
}

CDBServer::~CDBServer()
{
	if (m_key)
	{
		for (int i = 0; i < REDIS_MAX_NUM; i++)
		{
			delete []m_key[i];
		}
		delete[]m_key;
	}
}

void CDBServer::InitRedisName()
{
	strcpy(m_key[e_userinfo_account_set], "userinfo_account_set");
	strcpy(m_key[e_userinfo_userid_set], "userinfo_userid_set");
	//strcpy(m_key[e_userinfo_account_roleid], "userinfo_au_hash");
	strcpy(m_key[e_userinfo_account], "userinfo_account_hash");
	strcpy(m_key[e_userinfo_rolename_roleid], "userinfo_rna_hash");
	strcpy(m_key[e_userinfo_rolename], "userinfo_rolename_hash");
	strcpy(m_key[e_userinfo_money], "userinfo_money_hash");
	strcpy(m_key[e_userinfo_diamond], "userinfo_diamond_hash");
	strcpy(m_key[e_userinfo_point], "userinfo_point_hash");
}

bool CDBServer::BindUserInfo(QueryResult *qr, CPlayer *player, bool ismult/* = false*/)
{
	//获取玩家数据字段太多,用new,在堆中分配内存，而不是栈，查询字段
	//较少的数据，可以直接用栈!!如可以这样:QueryBind<2> bind;
	QueryBind< 7 > *bind = new QueryBind < 7 > ;

	(*bind)[0].BindString(player->m_PlayerData->m_szAccountName, sizeof(player->m_PlayerData->m_szAccountName));
	(*bind)[1].BindString(player->m_szPassWord, sizeof(player->m_szPassWord));
	(*bind)[2].BindLong((long*)&player->m_PlayerData->m_dwRoleID);
	(*bind)[3].BindString(player->m_PlayerData->m_szRoleName, sizeof(player->m_PlayerData->m_szRoleName));
	(*bind)[4].BindLong((long*)&player->m_PlayerData->m_dwRoleID);
	(*bind)[5].BindLong((long*)&player->m_PlayerData->m_dwMoney);
	(*bind)[6].BindLong((long*)&player->m_PlayerData->m_dwDiamond);
	(*bind)[7].BindLong((long*)&player->m_PlayerData->m_dwPoint);

	if (ismult)
	{
		while (qr->FetchResult(*bind) == 0)
		{
			DB2Redis(player);
		}
		delete bind;
		return true;
	}
	else
	{
		if (qr->FetchResult(*bind) == 0)
		{
			DB2Redis(player);
			delete bind;
			return true;
		}
	}

	return false;
}

bool CDBServer::IsUserInRedis(DWORD dwUserID)
{
	if (redis_sismember("sismember %s %d", m_key[e_userinfo_userid_set], dwUserID))
		return true;
	return false;
}

bool CDBServer::InitRedis(char *ip, int port)
{
	//初始化redis并链接
	//WSADATA wsaData;
	//WSAStartup(MAKEWORD(2, 1), &wsaData);
	m_pRedisContext = redisConnect(ip, port);
	if (m_pRedisContext->err) {
		redisFree(m_pRedisContext);
		return false;
	}
	return true;
}

bool CDBServer::ExecDB(QueryResult *qr, char *format, ...)
{
	va_list header;
	va_start(header, format);
	sprintf_s(m_command, DB_COMMAND_LEN, format, header);
	va_end(header);

	qr->Reset();
	if (ExecuteStmt(m_command, strlen(m_command), qr) == 0 && qr->AffectedRows() > 0)
	{
		return true;
	}
	return false;
}

bool CDBServer::UpdateDBData(char *sql, ...)
{
	bool ret = false;

	if (KeepAlive(0))
	{
		QueryResult qr;

		va_list header;
		va_start(header, sql);
		ret = ExecDB(&qr, sql, header);
		va_end(header);
	}
	return ret;
}

bool CDBServer::redis_write(char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisCommand(m_pRedisContext, format, header);
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

bool CDBServer::redis_hset(char *format, ...)
{
	va_list header;
	va_start(header, format);
	bool ret = redis_write(format, header);
	va_end(header);

	return ret;
}

bool CDBServer::redis_sadd(char *format, ...)
{
	va_list header;
	va_start(header, format);
	bool ret = redis_write(format, header);
	va_end(header);

	return ret;
}

bool CDBServer::redis_del(char *format, ...)
{
	va_list header;
	va_start(header, format);
	bool ret = redis_write(format, header);
	va_end(header);

	return ret;
}

redisReply* CDBServer::redis_hget(char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return NULL;

	if (rp->type != REDIS_REPLY_STRING)
	{
		freeReplyObject(rp);
		return NULL;
	}

	return rp;
}

bool CDBServer::redis_sismember(char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisCommand(m_pRedisContext, format, header);
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

redisReply* CDBServer::redis_spop(char *format, ...)
{
	va_list header;
	va_start(header, format);
	redisReply* rp = (redisReply*)redisCommand(m_pRedisContext, format, header);
	va_end(header);

	if (NULL == rp) return NULL;

	if (rp->type != REDIS_REPLY_STRING)
	{
		freeReplyObject(rp);
		return NULL;
	}

	return rp;
}

void CDBServer::DB2Redis(CPlayer *player)
{
	if (!player) return;
	//char buff[256] = {0};
	//帐号
	redis_sadd("sadd %s %s", m_key[e_userinfo_account_set], player->m_PlayerData->m_szAccountName);
	////角色ID
	redis_sadd("sadd %s %d", m_key[e_userinfo_userid_set], player->m_PlayerData->m_dwRoleID);

	//test
	//sprintf_s(buff, "hset %s %d %s", m_key[e_userinfo_account], player->m_PlayerData->m_dwRoleID, player->m_PlayerData->m_szAccountName);
	//redis_hset(buff);
	//redis_hset("hset %s %d %s", "hefsdf", 12, "nihaoaap");
	//redis_hset("hset %s %s %d", m_key[e_userinfo_account], player->m_PlayerData->m_szAccountName, player->m_PlayerData->m_dwRoleID);
	//redisReply* rp = (redisReply*)redisCommand(m_pRedisContext, "hset %s %d %s", m_key[e_userinfo_account], player->m_PlayerData->m_dwRoleID, player->m_PlayerData->m_szAccountName);


	//redis_hset("hset %s %s %d", m_key[e_userinfo_account_roleid], player->m_PlayerData->m_szAccountName, player->m_PlayerData->m_dwRoleID);

	redis_hset("hset %s %d %s", m_key[e_userinfo_account], player->m_PlayerData->m_dwRoleID, player->m_PlayerData->m_szAccountName);
	redis_hset("hset %s %s %d", m_key[e_userinfo_rolename_roleid], player->m_PlayerData->m_szRoleName, player->m_PlayerData->m_dwRoleID);
	redis_hset("hset %s %d %s", m_key[e_userinfo_rolename], player->m_PlayerData->m_dwRoleID, player->m_PlayerData->m_szRoleName);
	redis_hset("hset %s %d %d", m_key[e_userinfo_money], player->m_PlayerData->m_dwRoleID, player->m_PlayerData->m_dwMoney);
	redis_hset("hset %s %d %d", m_key[e_userinfo_diamond], player->m_PlayerData->m_dwRoleID, player->m_PlayerData->m_dwDiamond);
	redis_hset("hset %s %d %d", m_key[e_userinfo_point], player->m_PlayerData->m_dwRoleID, player->m_PlayerData->m_dwPoint);
}

void CDBServer::Redis2Memory(CPlayer *player, DWORD dwUserID)
{
	if (!player || 0 == dwUserID) return;

	player->m_PlayerData->m_dwRoleID = dwUserID;

	redisReply* rp = redis_hget("hget %s %d", m_key[e_userinfo_account], dwUserID);
	if (rp)
	{
		if (rp->str)
		{
			memcpy(player->m_PlayerData->m_szAccountName, rp->str, sizeof(player->m_PlayerData->m_szAccountName));
		}
		freeReplyObject(rp);
	}

	rp = redis_hget("hget %s %d", m_key[e_userinfo_rolename], dwUserID);
	if (rp)
	{
		if (rp->str)
		{
			memcpy(player->m_PlayerData->m_szRoleName, rp->str, sizeof(player->m_PlayerData->m_szRoleName));
		}
		freeReplyObject(rp);
	}

	rp = redis_hget("hget %s %d", m_key[e_userinfo_money], dwUserID);
	if (rp)
	{
		if (rp->str)
		{
			player->m_PlayerData->m_dwMoney = atoi(rp->str);
		}
		freeReplyObject(rp);
	}

	rp = redis_hget("hget %s %d", m_key[e_userinfo_diamond], dwUserID);
	if (rp)
	{
		if (rp->str)
		{
			player->m_PlayerData->m_dwDiamond = atoi(rp->str);
		}
		freeReplyObject(rp);
	}

	rp = redis_hget("hget %s %d", m_key[e_userinfo_point], dwUserID);
	if (rp)
	{
		if (rp->str)
		{
			player->m_PlayerData->m_dwPoint = atoi(rp->str);
		}
		freeReplyObject(rp);
	}
}

void CDBServer::Redis2Memory(CPlayer *player, char *rolename)
{
	if (!player) return;

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

	Redis2Memory(player, dwUserID);
}

//开服加载
void CDBServer::LoadData()
{
	if (KeepAlive(0))
	{
		QueryResult qr;
		if (ExecDB(&qr, "CALL SP_LoadData"))
		{
			CPlayer *player = new CPlayer;

			BindUserInfo(&qr, player, true);
			delete player;
		}
	}
}

//关服保存
void CDBServer::SaveData(bool quit/* = false*/)
{
	redisReply *rp = redis_spop("spop %s", m_key[e_userinfo_userid_set]);
	while (rp)
	{
		if (rp->str)
		{
			DWORD dwUserID = 0;
			dwUserID = atoi(rp->str);
			if (dwUserID > 0)
			{
				if (quit)
					UnLoadUserData(dwUserID);
				else
					SaveUserData(dwUserID);
			}
		}
		freeReplyObject(rp);
		rp = redis_spop("spop %s", m_key[e_userinfo_userid_set]);
	}
}

//加载数据
CPlayer *CDBServer::LoadUserData(DWORD dwUserID)
{
	if (KeepAlive(0))
	{
		QueryResult qr;
		if (ExecDB(&qr, "CALL SP_LoadUserData_UserID (%d)", dwUserID))
		{
			CPlayer *player = new CPlayer;

			if (BindUserInfo(&qr, player, false))
			{
				return player;
			}

			delete player;
		}
	}

	return NULL;
}

//加载数据
CPlayer *CDBServer::LoadUserData(char *rolename)
{
	if (KeepAlive(0))
	{
		QueryResult qr;
		if (ExecDB(&qr, "CALL SP_LoadUserData_RoleName (%d)", rolename))
		{
			CPlayer *player = new CPlayer;

			if (BindUserInfo(&qr, player, false))
			{
				return player;
			}

			delete player;
		}
	}

	return NULL;
}

void CDBServer::RemoveUserFromRedis(DWORD dwUserID)
{
	char *rolename = GetUserName(dwUserID);
	char *account = GetUserAccount(dwUserID);

	redis_del("del %s %s", m_key[e_userinfo_account_set], account);
	redis_del("del %s %d", m_key[e_userinfo_userid_set], dwUserID);

	redis_del("del %s %s", m_key[e_userinfo_rolename_roleid], rolename);

	redis_del("del %s %d", m_key[e_userinfo_account], dwUserID);
	redis_del("del %s %d", m_key[e_userinfo_rolename], dwUserID);
	redis_del("del %s %d", m_key[e_userinfo_money], dwUserID);
	redis_del("del %s %d", m_key[e_userinfo_diamond], dwUserID);
	redis_del("del %s %d", m_key[e_userinfo_point], dwUserID);
}

//卸载数据
void CDBServer::UnLoadUserData(DWORD dwUserID)
{
	if (!IsUserInRedis(dwUserID))
		return;

	SaveUserData(dwUserID);
	RemoveUserFromRedis(dwUserID);
}

//保存数据
void CDBServer::SaveUserData(DWORD dwUserID)
{
	if (!IsUserInRedis(dwUserID))
		return;

	DWORD dwMoney = 0, dwDiamond = 0, dwPoint = 0;
	redisReply* rp = redis_hget("hget %s %d", m_key[e_userinfo_money], dwUserID);
	if (rp)
	{
		if (rp->str)
		{
			dwMoney = atoi(rp->str);
		}
		freeReplyObject(rp);
	}

	rp = redis_hget("hget %s %d", m_key[e_userinfo_diamond], dwUserID);
	if (rp)
	{
		if (rp->str)
		{
			dwDiamond = atoi(rp->str);
		}
		freeReplyObject(rp);
	}

	rp = redis_hget("hget %s %d", m_key[e_userinfo_point], dwUserID);
	if (rp)
	{
		if (rp->str)
		{
			dwPoint = atoi(rp->str);
		}
		freeReplyObject(rp);
	}

	UpdateDBData(UPDATE_USER_DATA, dwMoney, dwDiamond, dwPoint, dwUserID);
}

//获取角色名
char *CDBServer::GetUserName(DWORD dwUserID)
{
	redisReply *rp = redis_hget("hget %s %d", m_key[e_userinfo_rolename], dwUserID);
	m_szRoleName[0] = 0;
	if (rp)
	{
		if (rp->str)
		{
			int len = min(strlen(rp->str), PLAYER_NAME_MAX_LEN);
			memcpy(m_szRoleName, rp->str, len);
			m_szRoleName[len] = 0;
		}
		freeReplyObject(rp);
	}

	return m_szRoleName;
}

//获取账户名
char *CDBServer::GetUserAccount(DWORD dwUserID)
{
	redisReply *rp = redis_hget("hget %s %d", m_key[e_userinfo_account], dwUserID);
	m_szAccountName[0] = 0;
	if (rp)
	{
		if (rp->str)
		{
			int len = min(strlen(rp->str), PLAYER_NAME_MAX_LEN);
			memcpy(m_szAccountName, rp->str, len);
			m_szAccountName[len] = 0;
		}
		freeReplyObject(rp);
	}

	return m_szAccountName;
}

//获取用户ID
DWORD CDBServer::GetUserID(char *rolename)
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
CPlayer *CDBServer::GetUserData(DWORD dwUserID)
{
	if (IsUserInRedis(dwUserID))
	{
		CPlayer *player = new CPlayer;
		Redis2Memory(player, dwUserID);
		return player;
	}
	else
	{
		return LoadUserData(dwUserID);
	}

	return NULL;
}

CPlayer *CDBServer::GetUserData(char *rolename)
{
	redisReply *rp = redis_hget("hget %s %s", m_key[e_userinfo_rolename_roleid], rolename);

	DWORD dwUserID = 0;
	if (rp && rp->str) dwUserID = atoi(rp->str);
	if (rp) freeReplyObject(rp);

	if (dwUserID > 0)
	{
		CPlayer *player = new CPlayer;
		Redis2Memory(player, dwUserID);
		return player;
	}
	else
	{
		return LoadUserData(rolename);
	}

	return NULL;
}
