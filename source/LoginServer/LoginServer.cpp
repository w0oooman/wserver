#include "LoginServer.h"
#include "LoginServerDB.h"

#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif

CLoginServer::CLoginServer()
{
	m_pLoginServerDB = NULL;
	m_pLoginServerDB = new CLoginServerDB;
	m_pLoginServerLogic = NULL;
	m_pLoginServerLogic = new CLoginServerLogic;
}

CLoginServer::~CLoginServer()
{
	delete m_pLoginServerDB;
	delete m_pLoginServerLogic;
}

bool CLoginServer::Init(LPCTSTR lpIP, USHORT usPort)
{
	m_pLoginServerDB->SetLoginServerPtr(this);
	m_pLoginServerLogic->SetLoginServerPtr(this);
	try
	{
		if (!CClientCKernelMgr::Init(lpIP, usPort)) return false;
		if (!m_pLoginServerDB->Init()) return false;
		if (!m_pLoginServerLogic->Init()) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CLoginServer::Start()
{
	try
	{
		if (!CClientCKernelMgr::Start()) Log("登录服连接网关服失败!");
		if (!m_pLoginServerDB->Start()) Log("登录服连接DB服失败!");
		if (!m_pLoginServerLogic->Start()) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

void CLoginServer::OnEvent(int timerID, void *data)
{

}

bool CLoginServer::OnNetMessage(const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;
	ULLONG llConnectID = CONNECTID_MIXEX(pMsgHead);

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_USER_REGISTER://注册
	{
		OnUserRegister(llConnectID, pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_LOGIN://登录
	{
		OnUserLogin(llConnectID, pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_ENTER://进入
	{
		OnUserEnter(llConnectID, pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_OFFLINE://下线
	{
		OnUserOffline(llConnectID, pMsgHead, dwSize);
	}break;
	default:
		Log("loginserver unhandle msg:%d", pMsgHead->protocol_);
		break;
	}

	return true;
}

bool CLoginServer::OnUserRegister(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize)
{
	CURegisterMsg* pURegisterMsg = (CURegisterMsg*)pNetMsgHead;
	int nAccountLen = strlen(pURegisterMsg->m_account);
	int nPosswordLen = strlen(pURegisterMsg->m_password);

	int flag = CDRegisterMsg::REG_SUCCESS;
	if (nAccountLen < USER_NAME_MIN_LEN)
	{
		flag = CDRegisterMsg::REG_ACCOUNT_SHORT;
	}
	else if (nAccountLen > USER_NAME_MAX_LEN)
	{
		flag = CDRegisterMsg::REG_ACCOUNT_LONG;
	}
	else if (nAccountLen > USER_PWD_MIN_LEN)
	{
		flag = CDRegisterMsg::REG_PWD_SHORT;
	}
	else if (nAccountLen > USER_PWD_MAX_LEN)
	{
		flag = CDRegisterMsg::REG_PWD_LONG;
	}

	if (flag != CDRegisterMsg::REG_SUCCESS)
	{
		CDRegisterMsg dRegisterMsg;
		return SendData(&dRegisterMsg, sizeof(dRegisterMsg));
	}

	return m_pLoginServerDB->SendData(pNetMsgHead, dwSize);
}

bool CLoginServer::OnUserLogin(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize)
{
	return m_pLoginServerDB->SendData(pNetMsgHead, dwSize);
}

bool CLoginServer::OnUserEnter(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize)
{
	//记得判断是否未登录选角色就直接进入!! whb

	return m_pLoginServerDB->SendData(pNetMsgHead, dwSize);
}

bool CLoginServer::OnUserOffline(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize)
{
	return m_pLoginServerLogic->SendData(pNetMsgHead, dwSize);
}