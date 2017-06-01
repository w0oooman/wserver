#include "GatewayServerLogin.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif

CGatewayServerLogin::CGatewayServerLogin()
{
	m_pGatewayServer = NULL;
}

CGatewayServerLogin::~CGatewayServerLogin()
{
	m_pGatewayServer = NULL;
}

bool CGatewayServerLogin::Init(DWORD dwMaxCount, DWORD dwListenPort)
{
	try
	{
		if (!CKernelMgr::Init(dwMaxCount, dwListenPort)) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CGatewayServerLogin::Start()
{
	SetIsSpecialClient(true);
	return CKernelMgr::Start();
}

CGatewayServer* CGatewayServerLogin::GetGatewayServerPtr()
{
	return m_pGatewayServer;
}

void CGatewayServerLogin::SetGatewayServerPtr(CGatewayServer* pGatewayServer)
{
	m_pGatewayServer = pGatewayServer;
}


void CGatewayServerLogin::OnEvent(int timerID, void *data)
{

}

void CGatewayServerLogin::OnCloseConnect(ULLONG llConnectID)
{

}

bool CGatewayServerLogin::OnLoginComplete(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize)
{
	CDLoginMsg* pLogin = (CDLoginMsg*)pNetMsgHead;
	//ULLONG llConnectID = CONNECTID_MIXEX(pLogin);
	if (CDLoginMsg::LOGIN_SUCCESS == pLogin->m_wRes)
	{
		CUserGateWayInfo *pUserGateWayInfo = new CUserGateWayInfo;
		if (pUserGateWayInfo)
		{
			pUserGateWayInfo->wServerIndex = pLogin->m_wServerIndex;
			m_pGatewayServer->SetUserGateWayInfo(llConnectID, pUserGateWayInfo);
		}
	}
	return m_pGatewayServer->SendData(llConnectID, pLogin, dwSize);
}

bool CGatewayServerLogin::OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;
	ULLONG llUserConnectID = CONNECTID_MIXEX(pMsgHead);

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_USER_REGISTER://注册
	{

	}break;
	case CNetMsgHead::NETMSG_USER_LOGIN://登录  
	{
		OnLoginComplete(llConnectID, pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_ENTER://进入
	{
		m_pGatewayServer->SendData(llConnectID, pMsgHead, dwSize);
	}break;
	default:
	{
		Log("【warning】gateway login unhandle msg:%d", pMsgHead->protocol_);
	}
		break;
	}

	return true;
}

bool CGatewayServerLogin::OnUserRegister(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize)
{
	if (dwSize != sizeof(CURegisterMsg))
	{
		m_pGatewayServer->SendVersionError(llConnectID);
		return false;
	}

	//发给登录服处理
	return SendData(pNetMsgHead, dwSize);
}

bool CGatewayServerLogin::OnUserLogin(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize)
{
	if (m_pGatewayServer->GetUserGateWayInfo(llConnectID))
	{
		CDLoginMsg Login;
		Login.m_wRes = CDLoginMsg::LOGIN_ONLINE;
		m_pGatewayServer->SendData(llConnectID, pNetMsgHead, dwSize);
		return true;
	}

	//发给登录服处理
	SendData(pNetMsgHead, dwSize);
	return true;
}

//用户进入
bool CGatewayServerLogin::OnUserEnter(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize)
{
	//记得判断是否未登录选角色就直接进入!! whb

	//发给登录服处理
	SendData(pNetMsgHead, dwSize);
	return true;
}