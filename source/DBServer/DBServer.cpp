#include "DBServer.h"
#include "IniParser.h"
#include "SaveType.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif

CDBServer::CDBServer()
{
	m_bSuccess = false;
	m_pDBmanager = NULL;
}

CDBServer::~CDBServer()
{
	if (m_bSuccess)
	{
		m_pDBmanager->SaveUserData(true);
	}
	delete m_pDBmanager;
	m_pDBmanager = NULL;
}

bool CDBServer::Init(DWORD dwMaxCount, DWORD dwListenPort)
{
	try
	{
		CIniParser parser;
		char  szDBIP[64];
		char  szRedisIP[64];
		char  szDBName[64];
		char  szDBAccount[64];
		char  szDBPwd[64];
		int   nRedisPort;

		if (!parser.Open(SERVER_CONFIG)){
			Log(parser.GetLastError());
			throw(1);
		}
		else
		{
			parser.GetIniString("DB", "db_ip", szDBIP, sizeof(szDBIP), "127.0.0.1");
			parser.GetIniString("DB", "redis_ip", szRedisIP, sizeof(szRedisIP), "127.0.0.1");
			parser.GetIniString("DB", "db_name", szDBName, sizeof(szDBName), "test");
			parser.GetIniString("DB", "db_account", szDBAccount, sizeof(szDBAccount), "root");
			parser.GetIniString("DB", "db_password", szDBPwd, sizeof(szDBPwd), "000000");
			nRedisPort = parser.GetIniInt("DB", "redis_port", 6379);
		}

		m_pDBmanager = new CDBManager;
		if (!m_pDBmanager->InitRedis(szRedisIP, nRedisPort)) throw "InitRedis error.";
		//if (!m_pDBmanager->InitDB(szDBAccount, szDBPwd, szDBIP, szDBName)) throw "InitDB error"; //db链接暂时注释 whb

		if (!CKernelMgr::Init(dwMaxCount, dwListenPort)) throw "DB server kernel init error.";

	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CDBServer::Start()
{
	try
	{
		//m_pDBmanager->LoadUserData();//db链接暂时注释 whb

		if (!CKernelMgr::Start()) throw "gate server kernel start error.";
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	m_bSuccess = true;
	return true;
}

void CDBServer::OnEvent(int timerID, void *data)
{

}

bool CDBServer::OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_USER_REGISTER:    //注册
	{

	}break;
	case CNetMsgHead::NETMSG_USER_LOGIN:       //登录
	{
		CULoginMsg *pLoginMsg = (CULoginMsg*)pData;
		//帐号判断/密码判断等操作 whb

		CDLoginMsg  dLoginMsg;
		if (m_pDBmanager->GetRoleListByAccount(dLoginMsg.m_szRoleList, sizeof(dLoginMsg.m_szRoleList), pLoginMsg->m_account))
		{
			int nSize = sizeof(CDLoginMsg);
			nSize = nSize - (sizeof(dLoginMsg.m_szRoleList) - strlen(dLoginMsg.m_szRoleList));
			SendData(&dLoginMsg, nSize);
		}
	}break;
	case CNetMsgHead::NETMSG_USER_ENTER:       //用户进入
	{
		CUEnterMsg *pEnterMsg = (CUEnterMsg*)pData;
		CUserData *pUserData = m_pDBmanager->GetUserData(pEnterMsg->m_rolename);
		CDEnterMsg dEnterMsg;
		if (pUserData)
		{
			dEnterMsg.m_wRes = CDEnterMsg::ENTER_SUCCESS;
			CDUserData2LogicMsg DUserData;
			DUserData.m_UserData = *pUserData;
			DUserData.m_wServerIndex = pEnterMsg->m_wServerIndex;
			SetMsgConnectID(&DUserData, pEnterMsg);
			SendData(&DUserData, sizeof(DUserData));
		}
		else
		{
			dEnterMsg.m_wRes = CDEnterMsg::ENTER_NOTEXIST;
		}

		SetMsgConnectID(&dEnterMsg, pEnterMsg);
		dEnterMsg.m_wServerIndex = pEnterMsg->m_wServerIndex;
		SendData(&dEnterMsg, sizeof(dEnterMsg));
	}break;
	case CNetMsgHead::NETMSG_SAVE_DATA:        //保存数据
	{
		SaveData(pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_OFFLINE:       //下线
	case CNetMsgHead::NETMSG_USER_MOVE:          //移动消息
	case CNetMsgHead::NETMSG_USER_CHAT:          //聊天消息
	case CNetMsgHead::NETMSG_USER_BATTLE:        //战斗消息
	case CNetMsgHead::NETMSG_SEND_SCRIPT:        //脚本消息
	case CNetMsgHead::NETMSG_MY_TEST:
	{
		static int i = 0;
		static DWORD dwTime = 0;
		i++;

		//bool ret = false;
		//ret = SendData(llConnectID, pMsgHead, dwSize);
		////ret = SendBatchData(pMsgHead, dwSize);

		//char buf[1024] = { 0 };
		//memcpy(buf, (char*)(pMsgHead + 1), pMsgHead->size_ - sizeof(CNetMsgHead));
		////printf("------%s-----sum=%d\n", buf, i); //whb
		////HandleDBData(pData,pMsgHead->dwSize,dwIndex,dwRoundIndex,db_get_login_times);

		//if (!ret)
		//{
		//	Log("SendData error,ID=%d", GetLastError());
		//	break;
		//}

		//static int  nTestNums = 0;
		//if (1 == i)
		//{
		//	CIniParser parser;
		//	char  LogicIP[64];

		//	if (!parser.Open(SERVER_CONFIG)){
		//		Log("open error...");
		//	}
		//	else
		//	{
		//		nTestNums = parser.GetIniInt("gateway", "user_test_nums", 1);
		//	}

		//	dwTime = GetTickCount();
		//}
		//if (nTestNums * 100 == i)
		//{
		//	DWORD tt = GetTickCount() - dwTime;
		//	Log("all  %d分%d秒%d毫秒\n", tt / 1000 / 60, tt / 1000 % 60, tt % 1000);
		//}
		//return true;

	}break;
	//case CNetMsgHead::NETMSG_MY_TEST:
	{

	}break;
	default:
		Log("DBServer msg unhandle msg:%d", pMsgHead->protocol_);
		break;
	}

	return true;
}

void CDBServer::SaveData(CNetMsgHead *pNetMsgHead, DWORD dwSize)
{
	CDSaveDataMsg* pSaveData = (CDSaveDataMsg*)pNetMsgHead;
	short shType = pSaveData->m_shType;
	switch (shType)
	{
	case SAVE_MONEY:
	{

	}break;
	case SAVE_DIAMOND:
	{

	}break;
	case SAVE_POINT:
	{
		DWORD dwPoint = *(DWORD*)(pSaveData->m_szData);
		m_pDBmanager->SaveUserPoint(pSaveData->m_dwID, dwPoint, GetSaveDBType(shType) == SAVE_DB_ATONCE ? true : false);
	}break;
	case SAVE_USER_ALL:
	{

	}break;
	default:
		Log("DBServer save unhandle type:%d", shType);
		break;
	}
}