#include "LogicServerLogin.h"
#include "IniParser.h"
#include "LogicServer.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif

CLogicServerLogin::CLogicServerLogin()
{
	m_pLogicServer = NULL;
}

CLogicServerLogin::~CLogicServerLogin()
{
	m_pLogicServer = NULL;
}

bool CLogicServerLogin::Init(LPCTSTR lpIP, USHORT usPort)
{
	try
	{
		if (!CClientCKernelMgr::Init(lpIP, usPort)) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CLogicServerLogin::Start()
{
	return CClientCKernelMgr::Start();
}

void CLogicServerLogin::SetLogicServerPtr(CLogicServer *pLogicServer)
{
	m_pLogicServer = pLogicServer;
}

void CLogicServerLogin::OnEvent(int timerID, void *data)
{

}


bool CLogicServerLogin::OnNetMessage(const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_USER_ENTER://进入
	{

	}break; 
	case CNetMsgHead::NETMSG_USERDATA_2LOGIC://同步数据
	{
		m_pLogicServer->UserData2Logic((CDUserData2LogicMsg*)pData);
	}break;
	case CNetMsgHead::NETMSG_USER_OFFLINE://下线
	{
		CDUserOfflineMsg *pUserOffline = (CDUserOfflineMsg *)pData;
		OnCloseConnect(CONNECTID_MIXEX(pUserOffline));
	}break;
	case CNetMsgHead::NETMSG_MY_TEST:
	{

	}
		break;
	default:
		Log("CLogicServerLogin unhandle msg:%d", pMsgHead->protocol_);
		break;
	}


	return true;
}

void CLogicServerLogin::OnCloseConnect(ULLONG llConnectID)
{
	m_pLogicServer->OnCloseConnect(llConnectID);
}
