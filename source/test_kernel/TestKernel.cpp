//#include "stdafx.h"
#include "TestKernel.h"
#include "IniParser.h"
#ifdef _MSC_VER
#pragma comment(lib, "kernel.lib")
#endif


CTestKernel::CTestKernel()
{

}

CTestKernel::~CTestKernel()
{

}

bool CTestKernel::Init()
{
	try
	{
		CIniParser parser;
		int UserNums, UserPort;
		USHORT UserPor;

		if (!parser.Open(SERVER_CONFIG)){
			parser.Close();
			Log(parser.GetLastError());
			throw(1);
		}
		else
		{
			UserNums = parser.GetIniInt("gateway", "user_nums_limit", 300);
			UserPort = parser.GetIniInt("gateway", "user_port", GATESERVER_PORT);
			parser.Close();
		}

		Log("用户最大连接数：%d", UserNums);

		if (!CKernelMgr::Init(UserNums, UserPort)) throw "CTestKernel server kernel init error.";
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CTestKernel::Start()
{
	try
	{
		Log("starting CTestKernelServer...");
		if (!CKernelMgr::Start()) throw "CTestKernel server kernel start error.";
		Log("start CTestKernelServer finish!");
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

void CTestKernel::OnEvent(int timerID, void *data)
{

}

void CTestKernel::OnCloseConnect(ULLONG llConnectID)
{
	
}

bool CTestKernel::OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
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
