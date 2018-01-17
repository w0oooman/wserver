#include "GatewayServer.h"
#include "GatewayServerLogic.h"
#include "GatewayServerLogin.h"
#include "define.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif


CGatewayServer::CGatewayServer()
{
	m_pGatewayServerLogin = NULL;
	m_pGatewayServerLogin = new CGatewayServerLogin;
	m_pGatewayServerLogic = NULL;
	m_pGatewayServerLogic = new CGatewayServerLogic;
}

CGatewayServer::~CGatewayServer()
{
	unordered_map<ULLONG, CUserGateWayInfo*>::iterator it = m_mapUserGWInfo.begin();
	for (; it != m_mapUserGWInfo.end();)
	{
		CUserGateWayInfo* pUserGateWayInfo = static_cast<CUserGateWayInfo*>(it->second);
		delete pUserGateWayInfo;
		m_mapUserGWInfo.erase(it++);
	}

	delete m_pGatewayServerLogin;
	delete m_pGatewayServerLogic;
}

bool CGatewayServer::Init()
{
	m_pGatewayServerLogin->SetGatewayServerPtr(this);
	m_pGatewayServerLogic->SetGatewayServerPtr(this);
	try
	{
		CIniParser parser;
		int UserNums, LoginServerNums, LogicServerNums;
		USHORT UserPort, LoginPort, LogicPort;

		if (!parser.Open(SERVER_CONFIG)){
			parser.Close();
			Log(parser.GetLastError());
			throw(1);
		}
		else
		{
			UserNums = parser.GetIniInt("gateway", "user_nums_limit", 300);
			LoginServerNums = parser.GetIniInt("gateway", "loginserver_nums_limit", 1);
			LogicServerNums = parser.GetIniInt("gateway", "logicserver_nums_limit", 1);

			UserPort = parser.GetIniInt("gateway", "user_port", GATESERVER_PORT);
			LoginPort = parser.GetIniInt("gateway", "login_gateway_port", DISTRI_GATE_LOGIN_PORT);
			LogicPort = parser.GetIniInt("gateway", "logic_gateway_port", DISTRI_GATE_LOGIC_PORT);
			parser.Close();
		}
		
		Log("用户最大连接数：%d", UserNums);
		Log("逻辑服务器最大连接数：%d", LogicServerNums);

		if (!CKernelMgr::Init(UserNums, UserPort)) throw "gate server kernel init error.";
		if (!m_pGatewayServerLogin->Init(LoginServerNums, LoginPort)) throw "ServerLogin init error!";
		if (!m_pGatewayServerLogic->Init(LogicServerNums, LogicPort)) throw "ServerLogic init error!";
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CGatewayServer::Start()
{
	try
	{
		if (!CKernelMgr::Start()) throw "gate server kernel start error.";
		if (!m_pGatewayServerLogin->Start()) throw "NetMgr.Start() error!";
		if (!m_pGatewayServerLogic->Start()) throw "NetMgr.Start() error!";
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

CGatewayServerLogic* CGatewayServer::GetGatewayLogicPtr()
{
	return m_pGatewayServerLogic;
}

CGatewayServerLogin* CGatewayServer::GetGatewayLoginPtr()
{
	return m_pGatewayServerLogin;
}

void CGatewayServer::OnEvent(int timerID, void *data)
{

}

void CGatewayServer::OnCloseConnect(ULLONG llConnectID)
{
	//发送到登录服
	CDUserOfflineMsg dOffline;
	RESERVE_SETCONNECTID(&dOffline, llConnectID);
	m_pGatewayServerLogin->SendData(&dOffline, sizeof(dOffline));

	//移除用户网关信息
	RemoveUserGateWayInfo(llConnectID);
}

bool CGatewayServer::OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;
	RESERVE_SETCONNECTID(pMsgHead, llConnectID);

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_USER_REGISTER:    //注册
	{
		m_pGatewayServerLogin->OnUserRegister(llConnectID, pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_LOGIN:       //登录  
	{
		m_pGatewayServerLogin->OnUserLogin(llConnectID, pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_ENTER:       //进入
	{
		m_pGatewayServerLogin->OnUserEnter(llConnectID, pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_USER_OFFLINE:       //下线
	case CNetMsgHead::NETMSG_USER_MOVE:          //移动消息
	case CNetMsgHead::NETMSG_USER_CHAT:          //聊天消息
	case CNetMsgHead::NETMSG_USER_BATTLE:        //战斗消息
	case CNetMsgHead::NETMSG_SEND_SCRIPT:        //脚本消息
	case CNetMsgHead::NETMSG_MY_TEST:
	{
		SendData2LogicServer(llConnectID, pMsgHead, dwSize);
	}break;
	default:
		Log("unhandle msg:%d", pMsgHead->protocol_);
		break;
	}

	return true;
}

void CGatewayServer::SetUserGateWayInfo(ULLONG llConnectID, CUserGateWayInfo* pUserGateWayInfo)
{
	unordered_map<ULLONG, CUserGateWayInfo*>::iterator it = m_mapUserGWInfo.find(llConnectID);
	if (it != m_mapUserGWInfo.end())
	{
		CUserGateWayInfo* pUserGateWayInfo = static_cast<CUserGateWayInfo*>(it->second);
		delete pUserGateWayInfo;
		m_mapUserGWInfo.erase(it);
	}

	m_mapUserGWInfo.insert(pair<ULLONG, CUserGateWayInfo*>(llConnectID, pUserGateWayInfo));
}

CUserGateWayInfo* CGatewayServer::GetUserGateWayInfo(ULLONG llConnectID)
{
	unordered_map<ULLONG, CUserGateWayInfo*>::iterator it = m_mapUserGWInfo.find(llConnectID);
	if (it != m_mapUserGWInfo.end())
	{
		CUserGateWayInfo* pUserGateWayInfo = static_cast<CUserGateWayInfo*>(it->second);
		return pUserGateWayInfo;
	}
	return NULL;
}

void CGatewayServer::RemoveUserGateWayInfo(ULLONG llConnectID)
{
	unordered_map<ULLONG, CUserGateWayInfo*>::iterator it = m_mapUserGWInfo.find(llConnectID);
	if (it != m_mapUserGWInfo.end())
	{
		m_mapUserGWInfo.erase(it);
	}
}

void CGatewayServer::SendVersionError(ULLONG llConnectID)
{
	CDVersionErrorMsg VersionError;
	SendData(llConnectID, &VersionError, sizeof(CDVersionErrorMsg));
}

void CGatewayServer::SendData2LogicServer(ULLONG llConnectID, CNetMsgHead *pNetMsgHead, DWORD dwSize)
{
	//分发给玩家所在的逻辑服务器
	if (m_pGatewayServerLogic->GetMaxCount() > 1)
	{
		CUserGateWayInfo* pUserGateWayInfo = GetUserGateWayInfo(llConnectID);
		if (pUserGateWayInfo)
		{
			m_pGatewayServerLogic->SendDataByIndex(pUserGateWayInfo->wServerIndex, pNetMsgHead, dwSize);
		}
	}
	//只有一个逻辑服务器
	else
	{
		static int i = 0;
		static DWORD dwTime = 0;
		i++;

		if (i % 10000 == 0)
		{
			Log("gateway i%%1000 = 0,i/10000=%d", i / 10000);
		}//whb
		if (i / 10000 == 10 && i % 10000 == 0)
		{
			char buf[1024] = { 0 };
			memcpy(buf, (char*)(pNetMsgHead + 1), pNetMsgHead->size_ - sizeof(CNetMsgHead));
			Log("server i / 10000 == 10 ------%s-----sum=%d\n", buf, i);
		}

		m_pGatewayServerLogic->SendData(pNetMsgHead, dwSize);
	}
}