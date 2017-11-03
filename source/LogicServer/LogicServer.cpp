#include "LogicServer.h"
#include "IniParser.h"
#include "LogicServerLogin.h"
#include "TimerID.h"
#include "LuaManager.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif

extern CLuaManager g_Script;
CLogicServerLogin  *m_pLogicServerLogin;
CDSaveDataMsg *m_pSaveData;

//使用定时器的方式重新加载脚本，保证加载脚本和
//游戏逻辑在一个一个线程内进行，防止出错!!
void ResetLuaScript(void *data)
{
	g_Script.RefreshLua();
}

CLogicServer::CLogicServer()
{
	m_pSaveData = NULL;
	m_pSaveData = new CDSaveDataMsg;
	m_pPlayerMgr = NULL;
	m_pPlayerMgr = new CPlayerMgr;
	m_pLogicServerLogin = NULL;
	m_pLogicServerLogin = new CLogicServerLogin;

	AddEvent(timer_delay_remove_player, TIMER_DELAY_REMOVE_PLAYER_TIME);
}

CLogicServer::~CLogicServer()
{
	g_Script.ServerDown();

	delete m_pSaveData;;
	m_pSaveData = NULL;
	delete m_pPlayerMgr;
	m_pPlayerMgr = NULL;

	/* 放到最后 */
	delete m_pLogicServerLogin;
	m_pLogicServerLogin = NULL;
}

bool CLogicServer::Init()
{
	try
	{
		char  LogicIP[64];
		int   nLogicPort;
		char  LogicLoginIP[64];
		int   nLogicLoginPort;

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
				parser.GetIniString("gateway", "ip", LogicIP, sizeof(LogicIP), "127.0.0.1");
				nLogicPort = parser.GetIniInt("gateway", "logic_gateway_port", DISTRI_GATE_LOGIC_PORT);
				parser.GetIniString("login", "ip", LogicLoginIP, sizeof(LogicLoginIP), "127.0.0.1");
				nLogicLoginPort = parser.GetIniInt("login", "logic_login_port", DISTRI_LOGIN_LOGIC_PORT);
				parser.Close();
			}
		}

		m_pLogicServerLogin->SetLogicServerPtr(this);
		if (!CClientCKernelMgr::Init(LogicIP, nLogicPort)) return false;
		if (!m_pLogicServerLogin->Init(LogicLoginIP, nLogicLoginPort)) return false;
		if (!UseLua()) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CLogicServer::Start()
{
	if (!CClientCKernelMgr::Start()) return false;
	if (!m_pLogicServerLogin->Start()) return false;
	return true;
}

bool CLogicServer::SendBatchData(const void* pAllMsgData, DWORD dwAllMsgLen)
{
	if (dwAllMsgLen < sizeof(CNetMsgHead)) return false;

	CNetMsgHead* pNetMsgHead = (CNetMsgHead*)pAllMsgData;
	pNetMsgHead->reserve1_ = 0;
	pNetMsgHead->reserve2_ = 0;
	return SendData(pNetMsgHead, dwAllMsgLen);
}

void CLogicServer::OnEvent(int timerID, void *data)
{
	if (timerID > timer_server_normal_begin && timerID < timer_server_normal_end)
	{
		switch (timerID)
		{
		case timer_delay_remove_player:
		{
			m_pPlayerMgr->CleanPlayerData();
		}break;
		default:
			Log("CLogicServer unhandle timerID:%d", timerID);
			break;
		}
	}
	else if (timerID > timer_lua_begin && timerID < timer_lua_end)
	{
		g_Script.OnEvent(timerID, data);
	}
	else
	{
		Log("CLogicServer unhandle timerID:%d", timerID);
	}

}

bool CLogicServer::OnNetMessage(const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_USER_MOVE://移动消息
	{

	}break;
	case CNetMsgHead::NETMSG_USER_CHAT://聊天消息
	{

	}break;
	case CNetMsgHead::NETMSG_USER_BATTLE://战斗消息
	{

	}break;
	case CNetMsgHead::NETMSG_SEND_SCRIPT://脚本消息
	{

	}break;
	case CNetMsgHead::NETMSG_MY_TEST:
	{
		static int i = 0;
		static DWORD dwTime = 0;
		i++;

		if (i % 10000 == 0)
		{
			Log("client i%%1000 = 0,i/10000=%d", i/10000);
		}
		if (i % 1000 == 0)
		{
			char buf[1024] = { 0 };
			memcpy(buf, (char*)(pMsgHead + 1), pMsgHead->size_ - sizeof(CNetMsgHead));
			Log("s client i %% 1000 == 0 ------%s-----sum=%d", buf, i);
		}

		bool ret = false;
		//ret  = SendData(dwIndex, pMsgHead->dwMainID, pMsgHead->dwSubID, (char*)pData, pMsgHead->dwSize - sizeof(NetMsgHead), dwRoundIndex);
		//ret = SendData(pMsgHead, dwMsgLen);
		ret = SendBatchData(pMsgHead, dwSize);

		char buf[1024] = { 0 };
		memcpy(buf, (char*)(pMsgHead + 1), pMsgHead->size_ - sizeof(CNetMsgHead));
		//printf("------%s-----sum=%d\n", buf, i); //whb
		//HandleDBData(pData,pMsgHead->dwSize,dwIndex,dwRoundIndex,db_get_login_times);

		if (!ret)
		{
			Log("SendData error,ID=%d,i=%d", GetLastError(), i);
			break;
		}

		static int  nTestNums = 0;
		if (1 == i)
		{
			CIniParser parser;
			char  LogicIP[64];

			if (!parser.Open(SERVER_CONFIG)){
				Log("open error...");
			}
			else
			{
				nTestNums = parser.GetIniInt("gateway", "user_test_nums", 1);
			}

			dwTime = GetTickCount();
		}
		if (nTestNums * 100 == i)
		{
			DWORD tt = GetTickCount() - dwTime;
			Log("s client all  %d分%d秒%d毫秒\n", tt / 1000 / 60, tt / 1000 % 60, tt % 1000);
		}
	}
		break;
	default:
		Log("unhandle msg:%d", pMsgHead->protocol_);
		break;
	}


	return true;
}

void CLogicServer::OnCloseConnect(ULLONG llConnectID)
{
	m_pPlayerMgr->RemovePlayer(llConnectID);
}

void CLogicServer::UserData2Logic(CDUserData2LogicMsg *pUserData2Logic)
{
	if (!pUserData2Logic) return;

	CDUserData2LogicMsg *pDUserData2Logic = (CDUserData2LogicMsg*)pUserData2Logic;
	CPlayer *pPlayer = new CPlayer;
	pPlayer->SetUserData(&pDUserData2Logic->m_UserData);
	pPlayer->SetPlayerConnectID(CONNECTID_MIXEX(pDUserData2Logic));
	m_pPlayerMgr->AddPlayer(pPlayer);

	Log(LOG_THREAD, "用户登录，数据同步到逻辑服，用户ID=%d", pDUserData2Logic->m_UserData.m_dwRoleID);
}


bool CLogicServer::UseLua()
{
	try
	{
		//初始化LUA环境
		g_Script.Init(this);
		g_Script.ServerStart();
		AddEvent(timer_lua_1_minute, 1 * 1000);
		AddEvent(timer_lua_10_minute, 10 * 60 * 1000);
		AddEvent(timer_lua_1_hour, 60 * 60 * 1000);
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

void CLogicServer::DeleteTimerData(const void *data)
{
	g_Script.DeleteTimerData(data);
}

//重新加载脚本
void CLogicServer::ResetScript()
{
	AddEvent(0, WHEEL_TIMER_TICK, &ResetLuaScript);
}