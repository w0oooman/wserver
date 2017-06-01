#include "LoginServerLogic.h"
#include "IniParser.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif


CLoginServerLogic::CLoginServerLogic()
{
	m_pLoginServer = NULL;
	m_pServerRegister = NULL;
	m_pServerRegister = new CServerRegister;
}

CLoginServerLogic::~CLoginServerLogic()
{
	m_pLoginServer = NULL;
	delete m_pServerRegister;
	m_pServerRegister = NULL;
}

bool CLoginServerLogic::Init()
{
	try
	{
		CIniParser parser;
		int LogicServerNums;
		USHORT LoginLogicPort;

		if (!parser.Open(SERVER_CONFIG)){
			parser.Close();
			Log(parser.GetLastError());
			throw(1);
		}
		else
		{
			LogicServerNums = parser.GetIniInt("gateway", "logicserver_nums_limit", 1);
			LoginLogicPort = parser.GetIniInt("login", "logic_login_port", DISTRI_LOGIN_LOGIC_PORT);

			parser.Close();
		}

		m_pServerRegister->Init(LogicServerNums);
		if (!CKernelMgr::Init(LogicServerNums, LoginLogicPort)) throw "loginlogic server kernel init error.";
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CLoginServerLogic::Start()
{
	try
	{
		Log("starting LoginLogicServer...");
		if (!CKernelMgr::Start()) throw "gate server kernel start error.";
		Log("start LoginLogicServer finish!");
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

void CLoginServerLogic::OnEvent(int timerID, void *data)
{

}

void CLoginServerLogic::OnCloseConnect(ULLONG llConnectID)
{
	m_pServerRegister->ServerUnRegister(llConnectID);
}

bool CLoginServerLogic::OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
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
		
	}break;
	case CNetMsgHead::NETMSG_USER_ENTER:       //进入
	{
		CDUserData2LogicMsg *pDUserData = (CDUserData2LogicMsg*)pData;
		SendData2LogicServer(pDUserData->m_wServerIndex, pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_SAVE_DATA:        //保存数据
	{
		m_pLoginServer->GetLoginServerDBPtr()->SendData(pMsgHead, dwSize);
	}break;
	case CNetMsgHead::NETMSG_SERVER_REGISTER://服务器注册
	{
		m_pServerRegister->ServerRegister(llConnectID);
	}break;
	case CNetMsgHead::NETMSG_USER_OFFLINE:     //下线
	case CNetMsgHead::NETMSG_USER_MOVE:        //移动消息
	case CNetMsgHead::NETMSG_USER_CHAT:        //聊天消息
	case CNetMsgHead::NETMSG_USER_BATTLE:      //战斗消息
	case CNetMsgHead::NETMSG_SEND_SCRIPT:      //脚本消息
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
		Log("unhandle msg:%d", pMsgHead->protocol_);
		break;
	}

	return true;
}

void CLoginServerLogic::SetLoginServerPtr(CLoginServer *pLoginServer)
{
	m_pLoginServer = pLoginServer;
}

bool CLoginServerLogic::SendDataByIndex(WORD wServerIndex, CNetMsgHead* pAllMsgData, DWORD dwAllMsgLen)
{
	ULLONG llLogicConnectID = m_pServerRegister->GetServerConnectID(wServerIndex);
	return SendData(llLogicConnectID, pAllMsgData, dwAllMsgLen);
}

void CLoginServerLogic::SendData2LogicServer(WORD wServerIndex, CNetMsgHead *pNetMsgHead, DWORD dwSize)
{
	//分发给用户所在的逻辑服务器
	if (m_pServerRegister->GetMaxCount() > 1)
	{
		SendDataByIndex(wServerIndex, pNetMsgHead, dwSize);
	}
	//只有一个逻辑服务器
	else
	{
		SendData(pNetMsgHead, dwSize);
	}
}