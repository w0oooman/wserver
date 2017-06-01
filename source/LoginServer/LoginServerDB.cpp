#include "LoginServerDB.h"
#include "LoginServer.h"
#include "IniParser.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif

CLoginServerDB::CLoginServerDB()
{
	m_pLoginServer = NULL;
}

CLoginServerDB::~CLoginServerDB()
{
	m_pLoginServer = NULL;
}

bool CLoginServerDB::Init()
{
	try
	{
		char  DBIP[64];
		int   nDBPort;

		if (1)
		{
			CIniParser parser;
			if (!parser.Open(SERVER_CONFIG)){
				parser.Close();
				Log(parser.GetLastError());
				throw(1);
			}
			else
			{
				parser.GetIniString("DB", "login_db_ip", DBIP, sizeof(DBIP), "127.0.0.1");
				nDBPort = parser.GetIniInt("DB", "login_db_port", DISTRI_DB_LOGIN_PORT);
				parser.Close();
			}
		}
		if (!CClientCKernelMgr::Init(DBIP, nDBPort)) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CLoginServerDB::Start()
{
	try
	{
		Log("starting LoginServerDB...");
		if (!CClientCKernelMgr::Start()) throw "loginDB server kernel start error.";
		Log("start LoginServerDB finish!");
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

CLoginServer* CLoginServerDB::GetLoginServerPtr()
{
	return m_pLoginServer;
}

void CLoginServerDB::SetLoginServerPtr(CLoginServer *pLoginServer)
{
	m_pLoginServer = pLoginServer;
}

void CLoginServerDB::OnEvent(int timerID, void *data)
{

}

bool CLoginServerDB::OnNetMessage(const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_USER_REGISTER://注册
	{
		m_pLoginServer->SendData(pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_LOGIN://登录
	{
		m_pLoginServer->SendData(pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_ENTER://进入
	{
		m_pLoginServer->SendData(pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USERDATA_2LOGIC://将玩家数据同步到逻辑服
	{
		CLoginServerLogic *ptr = m_pLoginServer->GetLoginServerLogicPtr();
		ptr->SendData(pMsgHead, dwSize);
	}break;
	default:
		Log("CLoginServerDB unhandle msg:%d", pMsgHead->protocol_);
		break;
	}


	return true;
}