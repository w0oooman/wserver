#include "GatewayServerLogic.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif

CGatewayServerLogic::CGatewayServerLogic()
{
	m_pGatewayServer = NULL;
	m_pServerRegister = NULL;
	m_pServerRegister = new CServerRegister;
}

CGatewayServerLogic::~CGatewayServerLogic()
{
	m_pGatewayServer = NULL;
	delete m_pServerRegister;
	m_pServerRegister = NULL;
}

bool CGatewayServerLogic::Init(DWORD dwMaxCount, DWORD dwListenPort)
{
	try
	{
		m_pServerRegister->Init(dwMaxCount);

		if (!CKernelMgr::Init(dwMaxCount, dwListenPort)) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CGatewayServerLogic::Start()
{
	SetIsSpecialClient(true);
	return CKernelMgr::Start();
}

CGatewayServer* CGatewayServerLogic::GetGatewayServerPtr()
{
	return m_pGatewayServer;
}

void CGatewayServerLogic::SetGatewayServerPtr(CGatewayServer* pGatewayServer)
{
	m_pGatewayServer = pGatewayServer;
}

void CGatewayServerLogic::OnEvent(int timerID, void *data)
{

}

void CGatewayServerLogic::OnCloseConnect(ULLONG llConnectID)
{
	m_pServerRegister->ServerUnRegister(llConnectID);
}

bool CGatewayServerLogic::OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;
	ULLONG llUserConnectID = CONNECTID_MIXEX(pMsgHead);

	switch (pMsgHead->protocol_)
	{
	case CNetMsgHead::NETMSG_SERVER_REGISTER://·þÎñÆ÷×¢²á
	{
		m_pServerRegister->ServerRegister(llConnectID);
	}break;
	default:
	{   
		static int i = 0;
		static DWORD dwTime = 0;
		i++;

		if (i % 100 == 0)
		{
			Log("CGatewayServerLogic i%%1000 = 0,i/100=%d", i / 100);
		}

		bool ret = false;
		if (0 == llUserConnectID)
			ret = m_pGatewayServer->SendBatchData(pMsgHead, dwSize);
		else
		    ret = m_pGatewayServer->SendData(llUserConnectID, pMsgHead, dwSize);
		return true;//whb
		//ret = m_pMainMgr->SendBatchData(pMsgHead, dwSize);

		char buf[1024] = { 0 };
		memcpy(buf, (char*)(pMsgHead + 1), pMsgHead->size_ - sizeof(CNetMsgHead));
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
				parser.Close();
				Log("open error...");
			}
			else
			{
				nTestNums = parser.GetIniInt("gateway", "user_test_nums", 1);
				parser.Close();
			}

			dwTime = GetTickCount();
		}
		if (nTestNums * 100 == i)
		{
			DWORD tt = GetTickCount() - dwTime;
			Log("all  %d·Ö%dÃë%dºÁÃë\n", tt / 1000 / 60, tt / 1000 % 60, tt % 1000);
		}
	}break;
	}

	return true;
}

bool CGatewayServerLogic::SendDataByIndex(WORD wServerIndex, CNetMsgHead* pAllMsgData, DWORD dwAllMsgLen)
{
	ULLONG llLogicConnectID = m_pServerRegister->GetServerConnectID(wServerIndex);
	return SendData(llLogicConnectID, pAllMsgData, dwAllMsgLen);
}