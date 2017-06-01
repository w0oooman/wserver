#include "ServerLogicHandle.h"
#include "TimerID.h"
#include "IniParser.h"

CServerLogicHandle::CServerLogicHandle()
{
	m_pMainMgr = NULL;
	m_pPlayerMgr = NULL;
}

CServerLogicHandle::~CServerLogicHandle()
{
	SAFE_DELETE(m_pPlayerMgr);
	m_pMainMgr = NULL;
}

bool CServerLogicHandle::Init(CMainMgr *pMainMgr)
{
	if (NULL == pMainMgr)
		return false;

	m_pMainMgr = pMainMgr;

	try
	{
		m_pPlayerMgr = new CPlayerMgr;
		if (NULL == m_pPlayerMgr) return false;

		if (!m_pPlayerMgr->Init(m_pMainMgr)) return false;
		if (m_pPlayerMgr->GetIsDelayRemove())
		{
			m_pMainMgr->AddEvent(timer_delay_remove_player, TIMER_DELAY_REMOVE_PLAYER_TIME/5);
		}
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CServerLogicHandle::OnMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_USER_REGISTER://注册
	{
	
	}break;
	case CNetMsgHead::NETMSG_USER_LOGIN://登录  
	{
		//在内存中
		//if ()
		//{
		//
		//}
		//读数据库
		//else
		{
			m_pMainMgr->HandleDBData(llConnectID, "123", 3, db_player_login);  //whb
		}
	}break;
	case CNetMsgHead::NETMSG_USER_OFFLINE://下线(前端请求后端把自己的资源立即释放)
	{

	}break;
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

		bool ret = false;
		ret = m_pMainMgr->SendData(llConnectID, pMsgHead, dwSize);
		//ret = m_pMainMgr->SendBatchData(pMsgHead, dwSize);

		char buf[1024] = {0};
		memcpy(buf, (char*)(pMsgHead+1), pMsgHead->size_-sizeof(CNetMsgHead));
		printf("------%s-----sum=%d\n", buf, i);
		//HandleDBData(pData,pMsgHead->dwSize,dwIndex,dwRoundIndex,db_get_login_times);

		if (!ret)
		{
			Log("SendData error,ID=%d", GetLastError());
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
		if (nTestNums*100 == i)
		{
			DWORD tt = GetTickCount() - dwTime;
			Log("all  %d分%d秒%d毫秒\n", tt / 1000 / 60, tt / 1000 % 60, tt % 1000);
		}
	}
		break;
	}
	return true;
}

void CServerLogicHandle::OnEvent(int timerID, void *data)
{
	switch (timerID)
	{
	case timer_server_normal_begin:
	{
	    
	}break;
	case timer_delay_remove_player:
	{
		m_pPlayerMgr->CleanPlayerData();
	}break;
	default:
	{
		Log_Position();
	}break;
	}
}

//移除玩家
void CServerLogicHandle::OnCloseConnect(ULLONG llConnectID)
{
	m_pPlayerMgr->RemovePlayer(llConnectID);
}

void CServerLogicHandle::OnLoginComplete(ULLONG llConnectID, BYTE byResult, CPlayer *pPlayer)
{
	//成功
	if (smd_login_success == byResult)
	{
		m_pPlayerMgr->AddPlayer(pPlayer);
		//m_pMainMgr->SendData(pPlayer->m_dwIndex, mmd_player_login, byResult, 数据,数据长度,pPlayer->m_dwRoundIndex);
	}
	//失败
	else  
	{
		CDLoginMsg login;
		login.m_wRes = byResult;
		m_pMainMgr->SendData(llConnectID, &login, sizeof(login));
	}
}