#include <iostream>
#include <process.h>
#include <time.h>
#include "define.h"
#include "NetMsg.h"
#include "IniParser.h"
#include "dump.h"
#include "NetMgr.h"
void getServerIp(char* ipAddr, int nLen);
bool Unicode2Mulbytes(char* pDest, wchar_t *pSrc);
#pragma comment(lib,"kernel.lib")

const int threadNums = 10;
const int eachClientSendNums_ = 100;
int       nTestNums;
int       nClientNums_ = 0;
CNetMgrC *pNetMgr = NULL;
int sendSumTimes_ = 0;
bool bIsRandCloseSocket_ = false;

CLock lockSendSumTimes_;
CLock testLock;

struct threadData
{
	HANDLE event;
	int data;
};
HANDLE    hRSIOCP_;

bool SendTestData(CNetMgrC *pClient, int &nSendNum);
bool SendLoginData(CNetMgrC *pClient);
bool SendEnterData(CNetMgrC *pClient);

//1、自己另写一套
unsigned int __stdcall RecvThread(void *data)
{
	threadData* ThreadData = (threadData*)data;
	int initV = ThreadData->data;
	SetEvent(ThreadData->event);

	DWORD dwTransfer = 0;
	BOOL  BRet;
	CNetMgrC      *pNetMgrC = NULL;

	OverLappedStruct        *OL = NULL;

	while (1)
	{
		BRet = 0; dwTransfer = 0; pNetMgrC = NULL; OL = NULL;
		try
		{
			BRet = GetQueuedCompletionStatus(hRSIOCP_, &dwTransfer, (PULONG_PTR)&pNetMgrC, (LPOVERLAPPED*)&OL, INFINITE);
			pNetMgrC->OnRecvComplete();
		}
		catch (...)
		{
			Log("GetQueuedCompletionStatus error:%d", GetLastError());
		}
	}

	return 0;
}

unsigned int __stdcall SendThread(void *data)
{
	threadData* ThreadData = (threadData*)data;
	int nInitV = ThreadData->data;
	SetEvent(ThreadData->event);

	while (1)
	{
		CNetMgrC *pClient = NULL;
		if (1)
		{
			CLockMgr LockMgr(&testLock);
			if (nClientNums_ >= nTestNums) break;
			pClient = &pNetMgr[nClientNums_];
			nClientNums_++;
		}

		int nSendNum = 0;
		int rand_value = share_rand() % 3;
		while (1)
		{
			if (bIsRandCloseSocket_)
			{
				if (rand_value == 1 && eachClientSendNums_/2 == nSendNum){
					pClient->CloseSocket();
					break;
				}
			}

			bool ret = SendTestData(pClient, nSendNum);
			//bool ret = SendLoginData(pClient);
			//bool ret = SendEnterData(pClient);

			if (!ret) break;
		}
	}

	Log(LOG_THREAD, "sendSumTimes = %d", sendSumTimes_);

	return 0;
}

int main()
{
	InitMinDump();
	share_srand(time(0));
	try
	{
		//读取配置
		CIniParser parser;
		char  LogicIP[64];
		int   nLogicPort;

		if (!parser.Open(SERVER_CONFIG)){
			parser.Close();
			throw("error...");
		}
		else
		{
			parser.GetIniString("gateway", "ip", LogicIP, sizeof(LogicIP), "127.0.0.1");
			nLogicPort = parser.GetIniInt("gateway", "user_port", GATESERVER_PORT);

			nTestNums = parser.GetIniInt("gateway", "user_test_nums", 1);
			parser.Close();
		}

		pNetMgr = new CNetMgrC[nTestNums];
		//绑定IOCP
		hRSIOCP_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
		for (int i = 0; i < nTestNums; i++)
		{
			CNetMgrC *pNetMgrTmp = &pNetMgr[i];
			pNetMgrTmp->Init(LogicIP, nLogicPort);
			pNetMgrTmp->CreateSocket();
			if (!CreateIoCompletionPort((HANDLE)pNetMgrTmp->GetSocket(), hRSIOCP_, (ULONG_PTR)pNetMgrTmp, 0)){
				throw CNetErr("CreateIoCompletionPort err.");
			}
			pNetMgrTmp->Connect();
			pNetMgrTmp->PrepareRecv();
		}

		//创建线程
		HANDLE threadEvent = CreateEvent(NULL, 0, 0, NULL);
		threadData ThreadData;
		ThreadData.event = threadEvent;
		ThreadData.data = 0;
		for (int i = 0; i < threadNums; i++)
		{
			(HANDLE)::_beginthreadex(NULL, 0, RecvThread, &ThreadData, 0, NULL);
			::WaitForSingleObject(ThreadData.event, INFINITE);
			::ResetEvent(ThreadData.event);

			(HANDLE)::_beginthreadex(NULL, 0, SendThread, &ThreadData, 0, NULL);
			::WaitForSingleObject(ThreadData.event, INFINITE);
			::ResetEvent(ThreadData.event);
		}

		while (1) share_sleep(2000);
	}
	catch (CNetErr &err){
		cout << (char*)err << endl;
	}
	catch (...){
	}

	while (1) share_sleep(2000);
	system("pause");
	//delete[]pClientTest;
	return 0;
}


bool SendTestData(CNetMgrC *pClient, int &nSendNum)
{
	int nCount = share_rand() % 15 + 15;
	//BYTE byCount = 9;//whb
	CTestMsg test;

	for (int i = 0; i < nCount; i++)
	{
		test.buf[i] = share_rand() % 26 + 'a';
	}

	if (eachClientSendNums_ == nSendNum) return false;
	nSendNum++;

	int addCount = 0;
	if (1){
		CLockMgr lockMgr(&lockSendSumTimes_);
		++sendSumTimes_;
		char bufTmp[10] = { 0 };
		itoa(sendSumTimes_, bufTmp, 10);
		addCount = strlen(bufTmp);
		sprintf_s(&test.buf[nCount], sizeof(test.buf), "%s", bufTmp);
	}

	int nSize = sizeof(CNetMsgHead)+nCount + addCount;
	if (!pClient->SendData(&test, nSize))
	{
		Log(LOG_THREAD, "client send data error.\n");
		return false;
	}

	return true;
}

bool SendLoginData(CNetMgrC *pClient)
{
	CULoginMsg login;
	memcpy(login.m_account, "wojiushiwo", strlen("wojiushiwo"));
	memcpy(login.m_password, "123456", strlen("123456"));
	if (!pClient->SendData(&login, sizeof(login)))
	{
		Log(LOG_THREAD, "client send data error.\n");
		return false;
	}
	return false;//发送一次就退出
}

bool SendEnterData(CNetMgrC *pClient)
{
	CUEnterMsg enter;
	enter.m_wServerIndex = 1;
	memcpy(enter.m_rolename, "Liubei", strlen("Liubei"));
	if (!pClient->SendData(&enter, sizeof(enter)))
	{
		Log(LOG_THREAD, "client send data error.\n");
		return false;
	}
	return false;//发送一次就退出
}


//2、使用kernel库
//CLock printLock;
//class CClientTest :public CClientCKernelMgr
//{
//public:
//	virtual bool OnNetMessage(const char* pMsgData, DWORD dwMsgLen)
//	{
//		static int i = 0;
//		char buf[1024] = { 0 };
//		CNetMsgHead *pNetMsgHead = (CNetMsgHead*)pMsgData;
//		memcpy(buf, (char*)(pNetMsgHead + 1), dwMsgLen - sizeof(CNetMsgHead));
//		CLockMgr LockMgr(&printLock);
//		i++;
//		printf("--------%s-------%d\n", buf, i);
//		return true;
//	}
//};
//
//int   nInitV = 0;
//unsigned int __stdcall test_thread(void *data)
//{
//	threadData* ThreadData = (threadData*)data;
//	int initV = ThreadData->data;
//	SetEvent(ThreadData->event);
//
//	while (1)
//	{
//		CClientTest *pClient = NULL;
//		if (1)
//		{
//			CLockMgr LockMgr(&testLock);
//			if (nInitV >= nTestNums) break;
//			pClient = &pClientTest[nInitV];
//			nInitV++;
//		}
//
//		int nSendNum = 0;
//		while (1)
//		{
//			BYTE byCount = share_rand() % 15 + 3;
//			CTestMsg test;
//
//			for (int i = 0; i < byCount; i++)
//			{
//				test.buf[i] = share_rand() % 26 + 'a';
//			}
//
//			if (100 == nSendNum) break;
//			nSendNum++;
//			
//			test.size_ = sizeof(CNetMsgHead) + byCount;
//			if (!pClient->SendData(&test, test.size_))
//			{
//				Log("client send data error.\n");
//				break;
//			}
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	InitMinDump();
//	try
//	{
//		//读取配置
//		CIniParser parser;
//		char  LogicIP[64];
//		int   nLogicPort;
//
//		if (!parser.Open(SERVER_CONFIG)){
//			throw("error...");
//		}
//		else
//		{
//			parser.GetIniString("gateway", "ip", LogicIP, sizeof(LogicIP), "127.0.0.1");
//			nLogicPort = parser.GetIniInt("gateway", "user_port", GATESERVER_PORT);
//
//			nTestNums = parser.GetIniInt("gateway", "user_test_nums", 1);
//		}
//
//		//初始化
//		pClientTest = new CClientTest[nTestNums];
//		for (int i = 0; i < nTestNums; i++)
//		{
//			pClientTest[i].Init(LogicIP, nLogicPort);
//			pClientTest[i].Start();
//			cout << "start all thread success! connect nums="<< i+1 << endl;
//			//Sleep(10);
//		}
//
//		//创建线程
//		HANDLE threadEvent = CreateEvent(NULL, 0, 0, NULL);
//		threadData ThreadData;
//		ThreadData.event = threadEvent;
//		ThreadData.data = 0;
//		for (int i = 0; i < threadNums; i++)
//		{
//			(HANDLE)::_beginthreadex(NULL, 0, test_thread, &ThreadData, 0, NULL);
//			::WaitForSingleObject(ThreadData.event, INFINITE);
//          ::ResetEvent(ThreadData.event);
//		}
//	
//	}
//	catch (CNetErr &err){
//		cout << (char*)err << endl;
//	}
//	catch (...){
//	}
//
//	while (1) share_sleep(2000);
//	system("pause");
//	//delete[]pClientTest;
//	return 0;
//}

bool Unicode2Mulbytes(char* pDest,wchar_t *pSrc)
{
	if(pSrc==NULL||pDest==NULL)
		return false;

	int nDestLen=WideCharToMultiByte(CP_ACP,0,pSrc,-1,NULL,0,NULL,NULL);
	if(0==nDestLen)
		return false;
	WideCharToMultiByte(CP_ACP,0,pSrc,-1,pDest,nDestLen,NULL,NULL);
}