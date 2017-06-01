#include "NetMgr.h"
#include <process.h>
#include <iostream>
using namespace std;
CLock     PrintLock_;
 
CNetMgrC::CNetMgrC()
{
	CoInitialize(NULL);
	WSAInitC();

    share_srand(GetTickCount());
	szSendbuf_ = 0;
	szRecvBuf_ = 0;
	szSendbuf_ = new char[CLIENT_SND_SIZE];
	szRecvBuf_ = new char[CLIENT_RCV_SIZE];
	memset(szSendbuf_, 0, CLIENT_SND_SIZE);
	memset(szRecvBuf_, 0, CLIENT_RCV_SIZE);
	dwSendLen_=0;
	dwRecvLen_=0;
	dwCheckCode_=0;
	memset(&RecvOverLPData_, 0, sizeof(RecvOverLPData_));
}

CNetMgrC::~CNetMgrC()
{
	WSAUnInitC();
	CoUninitialize();
}

bool CNetMgrC::Init(LPCTSTR lpIP, USHORT usPort)
{
	if(NULL==lpIP) return false;

	sockaddr_in addr;
	addr.sin_addr.S_un.S_addr=inet_addr(lpIP);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(usPort);
	SetSockAddr(addr);

	return true;
}

bool CNetMgrC::PrepareRecv()
{
	CLockMgr LockMgr(&GetLock());
	RecvOverLPData_.wsabuf.len = 0;
	DWORD dwRecvBytes = 0, dwFlags = 0;
	if ((WSARecv(GetSocket(), &RecvOverLPData_.wsabuf, 1, &dwRecvBytes, &dwFlags, &RecvOverLPData_.overlapped, NULL) == SOCKET_ERROR)
		&& WSAGetLastError() != WSA_IO_PENDING)
	{
		Log("WSARecv error:%d", GetLastError());
		return false;
    }
	return true;
}

//bool CNetMgrC::Start()
//{
//	if(!CreateSocket()) return false;
//	if(!Connect())      return false;
//
//	hEvent_=::CreateEvent(NULL,0,0,NULL);
//	if(NULL==hEvent_)  throw "create event failed!";
//
//	//创建收发线程
//	HANDLE hThread=(HANDLE)_beginthreadex(NULL,0,RecvThread,this,0,NULL);
//	if(NULL==hThread) throw "create recv thread failed!";
//	::WaitForSingleObject(hEvent_,INFINITE);
//	::ResetEvent(hEvent_);
//
//	hThread=(HANDLE)_beginthreadex(NULL,0,SendThread,this,0,NULL);
//	if(NULL==hThread) throw "create send thread failed!";
//
//
//	return true;
//}

int  g_limit = 101;
int  g_temp = 0; //whb
int  g_rand = 0;

unsigned int CNetMgrC::SendThread(void *pData)
{
	if(NULL==pData)  return -1;

	CNetMgrC *pNetMgr = (CNetMgrC*)pData;

	while(1)
	{
		share_sleep(10);//whb

		BYTE byCount=share_rand()%15+3;
		WORD wSize=sizeof(NetMsgHead);

		char szSendBuf[MAX_MESSAGE_LENGTH];memset(szSendBuf,0,sizeof(szSendBuf));

		for(int i=0;i<byCount;i++)
		{
			szSendBuf[i]=share_rand()%26+'a';
		}

		CLockMgr LockMgr(&pNetMgr->GetLock());
		static int nSendNum=0;
		nSendNum++;
		if(51==nSendNum) share_sleep(2000);//whb
		if (g_limit == nSendNum) {
			//*(int*)(378927) = 1;//whb 让程序崩溃
			break;
		}

		if(1)
		{
			CLockMgr LockPrint(&PrintLock_);
			cout<<"------"<<nSendNum<<'_'<<(int)byCount<<'_'<<"------"<<szSendBuf<<endl;
		}

		if (!pNetMgr->SendData(/*mmd_player_login*/mmd_message_test, 0, szSendBuf, byCount))  break;
	}
	
	share_sleep(10000);
	//closesocket(pNetMgr->GetSocket());
	//if (g_temp != g_limit) MessageBox(NULL,"error.",NULL,0);
	return 0;
}


unsigned int CNetMgrC::RecvThread(void *pData)
{
	if(NULL==pData)  return -1;

	CNetMgrC *pNetMgr = (CNetMgrC*)pData;
	//SetEvent(pNetMgr->hEvent_);

	share_srand(GetTickCount());
	//g_rand = share_rand() % 2;
	int num = share_rand()%95+5;
	int count = 0;

	while(1)
	{
		try
		{
			share_sleep(1);
			if (!pNetMgr->OnRecvComplete())
				break;
			count++;
			if (g_rand && num == count)
				exit(0);
		}
		catch (char* e)
		{
			cout << e << endl;
			break;
		}
		catch(...)
		{
			cout << "error."<< endl;
			break;
		}
	}
	return 0;
}

bool CNetMgrC::OnRecvComplete()
{
	CLockMgr LockMgr(&GetLock());

	int nRe=recv(GetSocket(),szRecvBuf_+dwRecvLen_,CLIENT_RCV_SIZE-dwRecvLen_,0);
	if(nRe>0||(0==nRe&&CLIENT_RCV_SIZE==dwRecvLen_))
	{		
		//if(1){CLockMgr LockPrint(&PrintLock_);
		//cout<<"________recv:"<<nRe<<endl;}

		dwRecvLen_+=nRe;
		CNetMsgHead * pMsgHead = (CNetMsgHead*)szRecvBuf_;
		DWORD dwMsgSize=pMsgHead->size_;

		while (dwRecvLen_ >= sizeof(CNetMsgHead) && dwRecvLen_ >= dwMsgSize)
		{
			if (dwMsgSize<sizeof(CNetMsgHead)/* || dwMsgSize>MAX_MESSAGE_LENGTH*/)        throw "非法数据包!";

			OnNetMessage(szRecvBuf_,dwMsgSize);

			memmove(szRecvBuf_,szRecvBuf_+dwMsgSize,dwRecvLen_-dwMsgSize);
			dwRecvLen_-=dwMsgSize;
			dwMsgSize = pMsgHead->size_;
		}
	}
	else if (nRe < 0)
	{
		Log(LOG_THREAD, "recv error 1.ID = %d", WSAGetLastError());
		return false;
	}
	else
	{
		Log(LOG_THREAD, "recv error 2.ID = %d", WSAGetLastError());
		return false;
	}

	return PrepareRecv();
}

bool CNetMgrC::SendData(DWORD dwMainID, DWORD dwSubID)
{
	
	return true;
}

bool CNetMgrC::SendData(DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen)
{
	if(NULL==pMsgData)  return false;

    NetMsgHead *pMsgHead=(NetMsgHead*)(szSendbuf_+dwSendLen_);
	int nSize=sizeof(NetMsgHead);
	pMsgHead->dwMainID=dwMainID;
	pMsgHead->dwSubID=dwSubID;
	pMsgHead->dwSize=dwMsgLen+nSize;
	pMsgHead->dwReserve=dwCheckCode_;

	memcpy(szSendbuf_+dwSendLen_+nSize,pMsgData,dwMsgLen);
	dwSendLen_+=nSize+dwMsgLen;

	return CheckSendData();
}

bool CNetMgrC::SendData(CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen)
{
	pNetMsgHead->size_ = dwAllMsgLen;
	int ret = send(GetSocket(), (char*)pNetMsgHead, dwAllMsgLen, 0);
	if (!ret) return false;

	return true;
}

bool CNetMgrC::CheckSendData()
{
	NetMsgHead* pMsgHead=(NetMsgHead*)szSendbuf_;
	DWORD &dwSize=pMsgHead->dwSize;

	while(dwSendLen_>sizeof(NetMsgHead))
	{
		if(dwSize<sizeof(NetMsgHead)) throw "invalid message!";
		if(dwSize>MAX_MESSAGE_LENGTH) throw "message too long!";
		if(dwSize>dwSendLen_)         throw "not full message!";

		int nRe=send(GetSocket(),szSendbuf_,dwSize,0);  //发送A包
		if(nRe>0)
		{
			int dwSizeTmp=dwSize;
			memmove(szSendbuf_,szSendbuf_+nRe,dwSendLen_-nRe);
			dwSendLen_-=nRe;

			if(nRe==dwSizeTmp)  continue;               //A包完成
			else if(nRe<dwSizeTmp)                      //A未完成
			{
				int nSendSize=dwSizeTmp-nRe;
				for(int i=0;i<5;i++)                    //继续发A包
				{
					nRe=send(GetSocket(),szSendbuf_,nSendSize,0);
					memmove(szSendbuf_,szSendbuf_+nRe,dwSendLen_-nRe);
					dwSendLen_-=nRe;

					if(nRe==nSendSize) break;
					else if(nRe>0&&nRe<nSendSize)
					{
						if(5==i) throw "send error for 5 times!";
						nSendSize-=nRe;
						share_sleep(30);
					}
					else throw "send error!";
				}
			}
			else throw "send error!";
		}
		else return false;
	}

	return true;
}

bool CNetMgrC::OnNetMessage(char* pMsgData, DWORD dwMsgLen)
{
	g_temp++;
	CNetMsgHead* pNetMsg = (CNetMsgHead*)pMsgData;

	char buf[MAX_MESSAGE_LENGTH+1]={0};
	memcpy(buf, pMsgData + sizeof(CNetMsgHead), dwMsgLen - sizeof(CNetMsgHead));
	if (pNetMsg->protocol_ != CNetMsgHead::NETMSG_CONNECT_SUCESS)
	{
		CLockMgr LockPrint(&PrintLock_);
		static int nNum = 0;
		static DWORD dwTime = GetTickCount();
		nNum++;
		//cout << "******" << nNum << "_" << dwMsgLen - sizeof(CNetMsgHead) << "_******" << buf << endl;
		//Log("*****%d_%d_******%s", nNum, dwMsgLen - sizeof(CNetMsgHead), buf);


		if (1 == nNum) dwTime = GetTickCount();
		if ((nNum % 100 == 0))
		{
			Log("client recv num = %d", nNum);
			if (nNum % 1000 == 0)
			{
				DWORD tt = GetTickCount() - dwTime;
				Log("--client i=%d--,  %d分%d秒%d毫秒\n", nNum, tt / 1000 / 60, tt / 1000 % 60, tt % 1000);
			}
		}
	}

	switch (pNetMsg->protocol_)
	{
	case mmd_server_full:
		{
		    CLockMgr LockPrint(&PrintLock_);
			cout<<"server full!"<<endl;
		}
		break;
	//case mmd_connect_success:
	//	dwCheckCode_=(pNetMsg->dwReserve-MESSAGE_CHECK_CODE)/19;
	//	//cout << "mmd_connect_success"<< endl;
	//	::SetEvent(hEvent_);
	//    break;
	}

	return true;
}
