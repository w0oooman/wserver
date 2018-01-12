#ifdef _MSC_VER
#include  <process.h> 
#include <assert.h>
#else
#include <atomic.h>
#endif
#include  <iostream>
#include  "SocketArray.h"
#include  "NetMgr.h"
#include  "define.h"


CNetMgr::CNetMgr()
{
	dwMaxCount_ = 0;
	dwListenPort_ = 0;
	dwThreadNum_ = 0;
	hRSIOCP_ = NULL;
	hThreadEvent_ = NULL;
	phRSThreadHandle_ = NULL;
	hHeartBeatThreadHandle_ = NULL;
	hAcceptThread_ = 0;
	hRSThread_ = 0;
	dwRoundIndex_ = 0;
	SocketArray_ = NULL;
	pKernelMgr_ = NULL;
	bIsRunning_ = true;
	bIsSpecialClient_ = false;
	dwTotalRecvLen_ = RCV_SIZE;
	dwTotalSendLen_ = SND_SIZE;
	pQueueBatchMsg_ = NULL;
	pQueueBatchMsg_ = new CLockFreeMgr;
}

CNetMgr::~CNetMgr()
{
	bIsRunning_ = false;
	CNetBase::CloseSocket();

	for (int i = 0; i < dwThreadNum_; i++)
	{
		if (hRSIOCP_){
			PostQueuedCompletionStatus(hRSIOCP_, 0, NULL, NULL);
		}
	}

	for (int i = 0; i < dwThreadNum_; i++)
	{
		Log(LOG_THREAD, "waiting rs thread:%d", i + 1);
		::WaitForSingleObject(phRSThreadHandle_[i], 10000);
		::CloseHandle(phRSThreadHandle_[i]);
		Log(LOG_THREAD, "end rs thread:%d", i + 1);
	}

	//TerminateThread((UINT)hAcceptThread_, 0);
	::CloseHandle((HANDLE)hAcceptThread_);

	::WaitForSingleObject(hHeartBeatThreadHandle_, 10000);
	::CloseHandle((HANDLE)hHeartBeatThreadHandle_);

	SAFE_DELETE(SocketArray_);
	pKernelMgr_ = NULL;
	hThreadEvent_ = NULL;
	phRSThreadHandle_ = NULL;
	hHeartBeatThreadHandle_ = NULL;
	delete pQueueBatchMsg_;
	pQueueBatchMsg_ = NULL;
}

bool CNetMgr::Init(DWORD dwMaxCount, DWORD dwListenPort, IKernelMgr* pKernelMgr)
{
	try
	{
		SocketArray_ = new CSocketArray;
		if (NULL == SocketArray_) return false;

		dwMaxCount_ = dwMaxCount;
		dwListenPort_ = dwListenPort;
		SocketArray_->Init(dwMaxCount_);

		pKernelMgr_ = pKernelMgr;
	}
	catch (...)
	{
		Log_ThreadPosition();
		return false;
	}

	return true;
}

void CNetMgr::SetBuffLen(DWORD dwRecvLen, DWORD dwSendLen)
{
	if (dwRecvLen > 0 && dwSendLen > 0)
	{
		dwTotalRecvLen_ = dwRecvLen;
		dwTotalSendLen_ = dwSendLen;
	}
}

DWORD CNetMgr::GetRoundIndex()
{
	//这里单线程调用,不使用原子锁也可,多线程的话需要加锁
#ifdef _MSC_VER
	InterlockedIncrement(&dwRoundIndex_);
#else
	atomic_add(1, &dwRoundIndex_);
#endif
	if (dwRoundIndex_ > 4000000000) dwRoundIndex_ = 1;

	return dwRoundIndex_;
}
  
void CNetMgr::CloseSocket(CTCPSocket* pTCPSocket, DWORD dwRoundIndex)
{
	if (NULL == pTCPSocket) return;

	if (pTCPSocket->CloseSocket(dwRoundIndex))
	{
		pKernelMgr_->PrepareCloseConnect(pTCPSocket->GetConnectID());
		pTCPSocket->ResetData();
		DeleteSocket(pTCPSocket);
	}
}
 
void CNetMgr::CloseSocket(ULLONG llConnectID)
{
	CloseSocket(GetFixedItem(INDEX_SPLIT(llConnectID)), ROUNDINDEX_SPLIT(llConnectID));
}

bool CNetMgr::Start()
{
	//收发线程数=CPU核心个数*2
	SYSTEM_INFO si;
	GetSystemInfo(&si);
	dwThreadNum_ = si.dwNumberOfProcessors * 2;
	if (dwThreadNum_ < 2) dwThreadNum_ = 2;

	//创建事件
	hThreadEvent_ = ::CreateEvent(NULL, 0, 0, NULL);
	if (NULL == hThreadEvent_)  throw CNetErr("Create thread event failed!", true);

	//分配句柄
	phRSThreadHandle_ = new HANDLE[dwThreadNum_];
	if (NULL == phRSThreadHandle_)  throw CNetErr("new thread handle failed!", true);

	//发送/接收 端口
	hRSIOCP_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	if (NULL == hRSIOCP_)       throw CNetErr("create rs io failed!", true);

	//socket操作
	if (!CreateSocket()) return false;
	if (!Bind(dwListenPort_)) return false;
	if (!Listen()) return false;

	//连接线程
	tagThreadData ThreadData;
	ThreadData.event = hThreadEvent_;
	ThreadData.iocp = hRSIOCP_;
	ThreadData.netmgr = this;
	hAcceptThread_ = ::_beginthreadex(NULL, 0, AcceptThread, &ThreadData, 0, NULL);
	if (NULL == hAcceptThread_)  throw("create accept thread failed!");
	::WaitForSingleObject(hThreadEvent_, INFINITE);
	::ResetEvent(hThreadEvent_);

	//收发线程
	ThreadData.event = hThreadEvent_;
	ThreadData.iocp = hRSIOCP_;
	ThreadData.netmgr = this;
	for (int i = 0; i < dwThreadNum_; i++)
	{
		phRSThreadHandle_[i] = (HANDLE)::_beginthreadex(NULL, 0, RSThread, &ThreadData, 0, NULL);
		if (NULL == phRSThreadHandle_[i])  throw("create RS thread failed!");
		::WaitForSingleObject(hThreadEvent_, INFINITE);
		::ResetEvent(hThreadEvent_);
	}

	pQueueBatchMsg_->SetLimitSize(BATCH_QUEUE_LIMIT_SIZE);

	//心跳线程
	ThreadData.event = hThreadEvent_;
	ThreadData.iocp = NULL;
	ThreadData.netmgr = this;
	hHeartBeatThreadHandle_ = (HANDLE)::_beginthreadex(NULL, 0, HeartBeatThread, &ThreadData, 0, NULL);
	if (NULL == hHeartBeatThreadHandle_)  throw("create accept thread failed!");
	::WaitForSingleObject(hThreadEvent_, INFINITE);
	::ResetEvent(hThreadEvent_);

	return true;
}

unsigned int CNetMgr::AcceptThread(void* pData)
{
	tagThreadData *ThreadData = (tagThreadData*)pData;
	CNetMgr *pNetMgr = (CNetMgr *)ThreadData->netmgr;
	HANDLE  hIOCP = ThreadData->iocp;
	HANDLE  hCreateIOCP = NULL;
	sockaddr_in addr;
	INT   nLen = sizeof(addr);
	SOCKET socketClient;

	::SetEvent(ThreadData->event);

	while (pNetMgr->bIsRunning_)
	{
		CTCPSocket *pTCPSocket = NULL;
		socketClient = INVALID_SOCKET;
		try
		{
			socketClient = WSAAccept(pNetMgr->GetSocket(), (sockaddr*)&addr, &nLen, 0, 0);
			if (INVALID_SOCKET == socketClient) 
			{
				if (WSAGetLastError() == WSAENOTSOCK)
					break;
				continue; 
			}

			pTCPSocket = pNetMgr->NewSocket();
			if (pTCPSocket != NULL)
			{
				if (NULL == pTCPSocket->GetNetMgr())
				{
					pTCPSocket->SetNetMgr(pNetMgr);
				}

				pTCPSocket->Attach(socketClient, addr, pNetMgr->GetRoundIndex());
				hCreateIOCP = CreateIoCompletionPort((HANDLE)socketClient, hIOCP, (ULONG_PTR)pTCPSocket, 0);
				if (NULL == hCreateIOCP)        throw "accept error!";

				//准备接收
				if (!pTCPSocket->RecvData())  throw "accept error!";

				//连接成功
				//CDConnectSuccessMsg msg;
				//msg.size_ = sizeof(CDConnectSuccessMsg);
				//msg.m_dwKey = MESSAGE_CHECK_CODE + socketClient * 19;
				//if (!pTCPSocket->SendData(pTCPSocket->GetRoundIndex(), (char*)&msg, sizeof(CDConnectSuccessMsg)))
				//{
				//	pNetMgr->CloseSocket(pTCPSocket, pTCPSocket->GetRoundIndex()); continue;
				//}
			}
			else
			{
				CNetMsgHead MsgHead(CNetMsgHead::NETMSG_SERVER_FULL);
				MsgHead.size_ = sizeof(CNetMsgHead);
				send(socketClient, (char*)&MsgHead, sizeof(CNetMsgHead), 0);
				Log(LOG_THREAD, "server full!");
				throw "server full!";
			}
		}
		catch (...)
		{
			Log_ThreadPosition();
			::closesocket(socketClient);
			pNetMgr->CloseSocket(pTCPSocket, pTCPSocket == NULL ? 0 : pTCPSocket->GetRoundIndex());
		}
	}

	return 0;
}

unsigned int CNetMgr::RSThread(void* pData)
{
	tagThreadData *ThreadData = (tagThreadData*)pData;
	CNetMgr *pNetMgr = (CNetMgr *)ThreadData->netmgr;
	HANDLE  hIOCP = ThreadData->iocp;

	::SetEvent(ThreadData->event);

	DWORD dwTransfer = 0;
	CTCPSocket      *pTCPSocket = NULL;

	//OL = CONTAINING_RECORD(OL, NETOVERLAPPED, overlapped)
	NETOVERLAPPED   *pNetOL = NULL;

	while (pNetMgr->bIsRunning_)
	{
		dwTransfer = 0; pTCPSocket = NULL; pNetOL = NULL;
		try
		{
			GetQueuedCompletionStatus(hIOCP, &dwTransfer, (PULONG_PTR)&pTCPSocket, (LPOVERLAPPED*)&pNetOL, INFINITE);

			//PostQueuedCompletionStatus(hRSIOCP_,0,NULL,NULL); 结束此线程时满足条件
			if (NULL == pTCPSocket && NULL == pNetOL && 0 == dwTransfer)  break;

			switch (pNetOL->type)
			{
			case SOCKET_RCV:

#ifdef IS_USE_CIRCLE_BUFFER
				pTCPSocket->OnRecvCompleteCircle(pNetOL->roundindex);
#else
				pTCPSocket->OnRecvComplete(pNetOL->roundindex);
#endif
				break;
			case SOCKET_SND:
				pTCPSocket->OnSendComplete(dwTransfer, pNetOL);
				break;
			}
		}

		catch (...)
		{
			
		}
	}

	return 0;
}

//心跳、群发、定时delete资源等
unsigned int CNetMgr::HeartBeatThread(void* pData)
{
	tagThreadData *ThreadData = (tagThreadData*)pData;
	CNetMgr *pNetMgr = (CNetMgr *)ThreadData->netmgr;

	::SetEvent(ThreadData->event);
	DWORD  dwTime = GetTickCount();//timeGetTime();
	char   szBuf[MAX_MESSAGE_LENGTH + 512];
	tagQueueData *pQueueData = (tagQueueData*)szBuf;

	while (pNetMgr->bIsRunning_)
	{
		//群发数据
		while (pNetMgr->GetBatchQueue()->GetData(pQueueData, sizeof(szBuf)))
		{
			CNetMsgHead * pMsgHead = (CNetMsgHead*)(&pQueueData->pQueueData);
			pNetMgr->SendBatchData(pMsgHead, pMsgHead->size_);
		}

		if (GetTickCount() < dwTime + (HEART_BEAT_TEST_TIME+3) * 1000)
		{
			share_sleep(1);
			continue;
		}
		
		//心跳处理
		CLockMgr LockMgr(&pNetMgr->GetSocketArrayLock());
		int nActiveCount = pNetMgr->GetSocketArray()->GetActiveCount();
		CTCPSocket **ppTempTCPSocketSet = pNetMgr->GetSocketArray()->GetTempActiveItemPPtrSet();
		LockMgr.UnLock();

		for (int i = 0; i < nActiveCount; i++)
		{
			CTCPSocket* pTCPSocket = ppTempTCPSocketSet[i];
			if (pTCPSocket != NULL)
			{
				if (pTCPSocket->GetHeartBeatTimes() == HEART_BEAT_CUT_TIMES)
				{
					CLockMgr LockMgr(pTCPSocket->GetLock());
					if (pTCPSocket->IsValidSocket())
					{
						//若前端异常断开(关机、拔网线等),则此时通过心跳关闭socket.一般情况此时bRecving_ == true
						//因此此时只会简单的closesocket而不会释放资源，但是调用::closesocket(socket_);
						//后GetQueuedCompletionStatus会立刻相应进入OnRecvComplete函数，进而使bRecving_ == false,
						//进而触发释放资源的行为!!
						pNetMgr->CloseSocket(pTCPSocket, pTCPSocket->GetRoundIndex());
					}
					continue;
				}
				else
				{
					pTCPSocket->AddHeartBeatTimes();
				}
			}
		}

		dwTime = GetTickCount();
	}

	return 0;
}

CTCPSocket* CNetMgr::NewSocket()
{
	CLockMgr LockMgr(&SockArrayLock_);
	return SocketArray_->GetItem();
}

bool CNetMgr::DeleteSocket(CTCPSocket* pTCPSocket)
{
	if (NULL == pTCPSocket) return false;
	CLockMgr LockMgr(&SockArrayLock_);
	return SocketArray_->RemoveItem(pTCPSocket);
}

UINT CNetMgr::GetFixArrayIndex()
{
	CLockMgr LockMgr(&SockArrayLock_);
	return SocketArray_->GetFixIndex();
}

CTCPSocket* CNetMgr::GetFixedItem(UINT index)
{
	CLockMgr LockMgr(&SockArrayLock_);
	return SocketArray_->GetFixedItem(index);
}

CTCPSocket* CNetMgr::GetActiveItem(UINT index)
{
	CLockMgr LockMgr(&SockArrayLock_);
	return SocketArray_->GetActiveItem(index);
}

CSocketArray* CNetMgr::GetSocketArray()
{
	return SocketArray_;
}

CLock& CNetMgr::GetSocketArrayLock()
{
	return SockArrayLock_;
}

CLockFreeMgr* CNetMgr::GetBatchQueue()
{
	return pQueueBatchMsg_;
}

DWORD CNetMgr::GetMaxCount()
{ 
	return dwMaxCount_; 
}

bool CNetMgr::IsSpecialClient()
{
	return bIsSpecialClient_;
}

void CNetMgr::SetIsSpecialClient(bool bIsSpecialClient)
{
	bIsSpecialClient_ = bIsSpecialClient;
}

bool CNetMgr::OnNetMessage(ULLONG llConnectID, const char* pData, DWORD dwSize)
{
	if (pKernelMgr_ != NULL)
		return pKernelMgr_->OnSocketRead(llConnectID, pData, dwSize);
	return  false;
}

bool CNetMgr::SendBatchDataOld(DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen)
{
	CLockMgr LockMgr(&SockArrayLock_);
	int nActiveCount = SocketArray_->GetActiveCount();
	CTCPSocket **ppTempTCPSocketSet = SocketArray_->GetTempActiveItemPPtrSet();
	LockMgr.UnLock();

	for (int i = 0; i < nActiveCount; i++)
	{
		CTCPSocket* pTCPSocket = ppTempTCPSocketSet[i];
		if (pTCPSocket != NULL)
		{
			CLockMgr LockMgr(pTCPSocket->GetLock());
			if (pTCPSocket->IsValidSocket())
				pTCPSocket->SendDataOld(dwMainID, dwSubID, pMsgData, dwMsgLen, pTCPSocket->GetRoundIndex());
		}
	}
	return true;
}

bool CNetMgr::SendBatchData(void* pMsgData, DWORD dwMsgLen)
{
	CLockMgr LockMgr(&SockArrayLock_);
	int nActiveCount = SocketArray_->GetActiveCount();
	CTCPSocket **ppTempTCPSocketSet = SocketArray_->GetTempActiveItemPPtrSet();
	LockMgr.UnLock();

	for (int i = 0; i < nActiveCount; i++)
	{
		CTCPSocket* pTCPSocket = ppTempTCPSocketSet[i];
		if (pTCPSocket != NULL)
		{
			CLockMgr LockMgr(pTCPSocket->GetLock());
			if (pTCPSocket->IsValidSocket())
				pTCPSocket->SendData(pTCPSocket->GetRoundIndex(), (char*)pMsgData, dwMsgLen);
		}
	}
	return true;
}

bool CNetMgr::SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, DWORD dwRoundIndex)
{
	CTCPSocket *pTCPSocket = GetFixedItem(dwIndex);
	if (pTCPSocket != NULL)
		return pTCPSocket->SendDataOld(dwMainID, dwSubID, dwRoundIndex);

	return false;
}

bool CNetMgr::SendDataOld(DWORD dwIndex, void* pAllMsgData, DWORD dwAllMsgLen, DWORD dwRoundIndex)
{
	CTCPSocket *pTCPSocket = GetFixedItem(dwIndex);
	if (pTCPSocket != NULL)
		return pTCPSocket->SendDataOld(pAllMsgData, dwAllMsgLen, dwRoundIndex);

	return false;
}

bool CNetMgr::SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen, DWORD dwRoundIndex)
{
	CTCPSocket *pTCPSocket = GetFixedItem(dwIndex);
	if (pTCPSocket != NULL)
		return pTCPSocket->SendDataOld(dwMainID, dwSubID, pMsgData, dwMsgLen, dwRoundIndex);

	return false;
}

bool CNetMgr::SendData(ULLONG llConnectID, void* pAllMsgData, DWORD dwAllMsgLen)
{
	CTCPSocket *pTCPSocket = GetFixedItem(INDEX_SPLIT(llConnectID));
	if (pTCPSocket != NULL)
		return pTCPSocket->SendData(ROUNDINDEX_SPLIT(llConnectID), pAllMsgData, dwAllMsgLen);

	return false;
}

bool CNetMgr::SendData(void* pAllMsgData, DWORD dwAllMsgLen)
{
	if (1 == dwMaxCount_)
	{
		CTCPSocket *pTCPSocket = GetFixedItem(0);
		if (pTCPSocket != NULL)
			return pTCPSocket->SendData(pAllMsgData, dwAllMsgLen);
	}
	else
	{
		Log(LOG_THREAD, "【 error 】: call SendData para miss.");
	}

	return false;
}





CClientNetMgr::CClientNetMgr()
{
	share_srand(GetTickCount());
	sendBuf_ = NULL;
	recvBuf_ = NULL;
	dwSendLen_ = 0;
	dwRecvLen_ = 0;
	dwCheckCode_ = 0;
	hEvent_ = NULL;
	hRSThreadHandle_ = NULL;
	hRSIOCP_ = NULL;
	pKernelMgr_ = NULL;
	bIsRunning_ = true;
	bSending_ = false;
	bIsNetCuted_ = true;
	dwTotalRecvLen_ = CLIENT_RCV_SIZE;
	dwTotalSendLen_ = CLIENT_SND_SIZE;
	bIsListHaveData_ = false;
}

CClientNetMgr::~CClientNetMgr()
{
	bIsRunning_ = false;
	bIsNetCuted_ = true;
	CNetBase::CloseSocket();

	if (hRSIOCP_)
	    PostQueuedCompletionStatus(hRSIOCP_, 0, NULL, NULL);
	if (hRSThreadHandle_)
	    WaitForSingleObject(hRSThreadHandle_, 10000);
	if (hRSThreadHandle_)
	    ::CloseHandle(hRSThreadHandle_);
	hRSThreadHandle_ = NULL;

	SAFE_DELETE_ARRAY(recvBuf_);
	SAFE_DELETE_ARRAY(sendBuf_);

	::CloseHandle(hEvent_);
	hEvent_ = NULL;
	
	pKernelMgr_ = NULL;
	bIsListHaveData_ = false;
}

bool CClientNetMgr::Init(LPCTSTR lpIP, USHORT usPort, CClientCKernelMgr *pKernelMgr)
{
	if (NULL == lpIP) return false;

	sockaddr_in addr;
	addr.sin_addr.S_un.S_addr = inet_addr(lpIP);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(usPort);
	SetSockAddr(addr);

	pKernelMgr_ = pKernelMgr;
	RecvOverLPData_.type = SOCKET_RCV;
	SendOverLPData_.type = SOCKET_SND;

	return true;
}

bool CClientNetMgr::PrepareRecv()
{
	CLockMgr LockMgr(&RecvLock_);

	//客户端就不把wsabuf.len置为0而用recv接收实际数据了,因为不像服务端要处理多个连接因而怕非分页内存不足,客户端不存在这个问题.
	DWORD dwRecvBytes = 0, dwFlags = 0;
	RecvOverLPData_.wsabuf.buf = recvBuf_ + dwRecvLen_;
	RecvOverLPData_.wsabuf.len = min(dwTotalRecvLen_ - dwRecvLen_, dwTotalRecvLen_);
	if ((WSARecv(GetSocket(), &RecvOverLPData_.wsabuf, 1, &dwRecvBytes, &dwFlags, &RecvOverLPData_.overlapped, NULL) == SOCKET_ERROR)
		&& WSAGetLastError() != WSA_IO_PENDING)
	{
		SetNetCutedStatus(true);
		return false;
	}

	return true;
}

HANDLE CClientNetMgr::GetEvent()
{
	return hEvent_; 
}

IKernelMgr *CClientNetMgr::GetKernelMgr()
{
	return pKernelMgr_;
}

HANDLE CClientNetMgr::GetIOCPHandle()
{
	return hRSIOCP_;
}

bool CClientNetMgr::Start()
{
	sendBuf_ = new char[dwTotalSendLen_];
	recvBuf_ = new char[dwTotalRecvLen_];
	if (NULL == sendBuf_ || NULL == recvBuf_) throw CNetErr("new client buf failed!", true);

	hEvent_ = ::CreateEvent(NULL, 0, 0, NULL);
	if (NULL == hEvent_)  throw CNetErr("create event failed!", true);

	//发送/接收 端口
	hRSIOCP_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	if (NULL == hRSIOCP_)       throw CNetErr("create client rs io failed!", true);

	//创建收发线程
	tagThreadData ThreadData;
	ThreadData.event = hEvent_;
	ThreadData.iocp = hRSIOCP_;
	ThreadData.netmgr = this;
	ThreadData.data = pKernelMgr_->GetNormalQueue();
	hRSThreadHandle_ = (HANDLE)_beginthreadex(NULL, 0, RSThread, &ThreadData, 0, NULL);
	if (NULL == hRSThreadHandle_) throw CNetErr("create recv/send thread failed!", true);
	::WaitForSingleObject(hEvent_, INFINITE);
	::ResetEvent(hEvent_);

	if (!CreateSocket()) return false;
	if (!Connect())      return false;
	SetNetCutedStatus(false);
	HANDLE hCreateIOCP = CreateIoCompletionPort((HANDLE)GetSocket(), hRSIOCP_, (ULONG_PTR)NULL, 0);
	if (NULL == hCreateIOCP)        throw CNetErr("client accept error!", true);
	PrepareRecv();

	return true;
}

unsigned int CClientNetMgr::RSThread(void *pData)
{
	tagThreadData *ThreadData = (tagThreadData*)pData;
	CClientNetMgr *pNetMgr = (CClientNetMgr *)ThreadData->netmgr;
	HANDLE  hIOCP = ThreadData->iocp;
	CLockFreeMgr *pQueueMsg = (CLockFreeMgr *)ThreadData->data;

	::SetEvent(ThreadData->event);

	DWORD dwTransfer = 0;
	PULONG_PTR  pCompletionKey = NULL;
	NETOVERLAPPED      *pNetOL = NULL;  //CONTAINING_RECORD()

	int   nQueueBufLen = 1024 * 64;//MAX_MESSAGE_LENGTH + 512;
	char *pQueueBuf = new char[nQueueBufLen];
	tagQueueData *pQueueData = (tagQueueData*)pQueueBuf;

	while (pNetMgr->bIsRunning_)
	{
		dwTransfer = 0; pCompletionKey = NULL; pNetOL = NULL;
		try
		{
			GetQueuedCompletionStatus(hIOCP, &dwTransfer, (PULONG_PTR)&pCompletionKey, (LPOVERLAPPED*)&pNetOL, INFINITE);

			if (NULL == pNetOL && NULL == pCompletionKey)
			{
				if (0 == dwTransfer){
					break;
				}
				else{
					if (pQueueMsg->GetData(pQueueData, nQueueBufLen)){
						pNetMgr->GetKernelMgr()->HandleTimerEvent(pNetMgr->GetKernelMgr(), (tagWheelTimer *)(&pQueueData->pQueueData));
					}
					continue;
				}
			}

			switch (pNetOL->type)
			{
			case SOCKET_RCV:
				pNetMgr->OnRecvComplete(dwTransfer);
				break;
			case SOCKET_SND:
				pNetMgr->OnSendComplete(dwTransfer, pNetOL);
				break;
			}
		}

		catch (...)
		{

		}
	}

	delete[]pQueueBuf;
	return 0;
}

bool CClientNetMgr::OnRecvCompleteOld(DWORD dwTransNum)
{
	if (0 == dwTransNum)
	{
		SetNetCutedStatus(true);
		return false;
	}

	dwRecvLen_ += dwTransNum;
	if (dwRecvLen_ >= sizeof(((NetMsgHead*)recvBuf_)->dwSize))
	{
		DWORD dwSum = 0; bool bReturn = true;
		while (dwRecvLen_ >= sizeof(NetMsgHead))
		{
			NetMsgHead *pNetMsgHead = (NetMsgHead*)((char*)recvBuf_ + dwSum);
			DWORD dwSize = pNetMsgHead->dwSize;
			if (dwRecvLen_ < dwSize) break;

			if (dwSize < sizeof(NetMsgHead) || dwSize > MAX_MESSAGE_LENGTH)  { bReturn = false; break; }

			//if (CNetMsgHead::NETMSG_CONNECT_SUCESS == pNetMsgHead->dwMainID)
			//{
			//	dwCheckCode_ = (pNetMsgHead->dwReserve - MESSAGE_CHECK_CODE) / 19;
			//}
			//else
			{ 
				NetMsgHead *pNetMsgHead = (NetMsgHead *)((char*)recvBuf_ + dwSum);
				if (!pKernelMgr_->OnNetMessageOld(pNetMsgHead, (char *)(pNetMsgHead + 1), dwSize - sizeof(NetMsgHead)))
				{
					bReturn = false; break;
				}
			}

			dwRecvLen_ -= dwSize;
			dwSum += dwSize;
		}

		memmove(recvBuf_, recvBuf_ + dwSum, dwRecvLen_);

		if (!bReturn)
		{
			SetNetCutedStatus(true);
			return false;
		}
	}

	return PrepareRecv();
}

bool CClientNetMgr::OnRecvComplete(DWORD dwTransNum)
{
	if (0 == dwTransNum)
	{
		SetNetCutedStatus(true);
		return false;
	}

	dwRecvLen_ += dwTransNum;
	if (dwRecvLen_ >= sizeof(((CNetMsgHead*)recvBuf_)->size_))
	{
		DWORD dwSum = 0; bool bReturn = true;
		while (dwRecvLen_ >= sizeof(CNetMsgHead))
		{
			CNetMsgHead *pNetMsgHead = (CNetMsgHead*)((char*)recvBuf_ + dwSum);
			DWORD dwSize = pNetMsgHead->size_;

			if (dwRecvLen_ < dwSize) break;

			//客户机不需要限制dwSize大小,先注释掉
			if (dwSize < sizeof(CNetMsgHead)/* || dwSize > MAX_MESSAGE_LENGTH*/)  { bReturn = false; break; }

			if (!pKernelMgr_->OnNetMessage((char *)pNetMsgHead, dwSize))
			{
				bReturn = false; break;
			}

			dwRecvLen_ -= dwSize;
			dwSum += dwSize;
		}

		memmove(recvBuf_, recvBuf_ + dwSum, dwRecvLen_);

		if (!bReturn)
		{
			SetNetCutedStatus(true);
			return false;
		}
	}

	return PrepareRecv();
}

bool CClientNetMgr::OnSendComplete(DWORD dwSendCount, NETOVERLAPPED* pNetOL)
{
	CLockMgr LockMgr(&SendLock_);
	bSending_ = false;

	if (0 == dwSendCount)
	{
		SetNetCutedStatus(true);
		return false;
	}

	//buff
	if (pNetOL->issendbuff)
	{
		if (dwSendCount <= dwSendLen_)
		{
			dwSendLen_ -= dwSendCount;
			memmove(sendBuf_, sendBuf_ + dwSendCount, dwSendLen_);
			return WSASendData();
		}
	}
	//list
	else
	{
		delete pNetOL->wsabuf.buf;
		return WSASendData();
	}

	return true;
}

bool CClientNetMgr::WSASendData()
{
	CLockMgr LockMgr(&SendLock_);

	if (false == bSending_)
	{
		if (dwSendLen_ > 0)
		{
			SendOverLPData_.wsabuf.buf = sendBuf_;
			SendOverLPData_.wsabuf.len = dwSendLen_;
			SendOverLPData_.issendbuff = 1;
			bSending_ = true;
		}
		else if (bIsListHaveData_)
		{
			tagSData tagSendData;
			if (List_.POPFront(&tagSendData))
			{
				SendOverLPData_.wsabuf.buf = tagSendData.buf;
				SendOverLPData_.wsabuf.len = tagSendData.len;
				SendOverLPData_.issendbuff = 0;
				bSending_ = true;
				if (List_.GetCount() == 0) bIsListHaveData_ = false;
			}
			else
			{
				bIsListHaveData_ = false;
				Log(LOG_THREAD, "【 error 】: client send list error.count=%d", List_.GetCount());
				return false;
			}
		}

		DWORD dwSendBytes = 0;
		if (bSending_ && 
			WSASend(GetSocket(), &SendOverLPData_.wsabuf, 1, &dwSendBytes, 0, &SendOverLPData_.overlapped, NULL) == SOCKET_ERROR
			&&WSAGetLastError() != WSA_IO_PENDING)
		{
			bSending_ = false;
			SetNetCutedStatus(true);
			Log(LOG_THREAD, "WSASend error.");
			return false;
		}
	}

	return true;
}

void CClientNetMgr::PushSendList(void* pSendData, DWORD dwSendLen)
{
	if (dwSendLen > MAX_SEND_LIMIT)
	{
		Log(LOG_THREAD, "【 error 】: client send data falied:too long! limit=%d,sendlen=%d", MAX_SEND_LIMIT, dwSendLen);
		return;
	}

	tagSData tagSendData;
	tagSendData.buf = new char[dwSendLen];
	tagSendData.len = dwSendLen;
	memcpy(tagSendData.buf, (char*)pSendData, dwSendLen);
	List_.PUSHBack(tagSendData);
}

void CClientNetMgr::CloseSocket()
{
	CNetBase::CloseSocket();
	ResetData();
}

void CClientNetMgr::ResetData()
{
	//断线不清数据
	//dwSendLen_ = 0;
	//dwRecvLen_ = 0;
	//dwCheckCode_ = 0;
	bIsRunning_ = true;
}

bool CClientNetMgr::ReConnect()
{
	bool ret = true;

	if (IsNetCuted())
	{
		Log(LOG_THREAD, "网络重连...");

		CloseSocket();

		try
		{
			ret = CreateSocket();
			if (ret)
			{
				ret = Connect();
			}
		}
		catch (CNetErr &err)
		{
			ret = false;
			Log(LOG_THREAD, (char*)err);
		}
		catch (...)
		{
			ret = false;
			Log_ThreadPosition();
		}
		
		if (ret){
			Log(LOG_THREAD, "重连成功!!!");
			if (!CreateIoCompletionPort((HANDLE)GetSocket(), hRSIOCP_, (ULONG_PTR)NULL, 0)){
				ret = false;
				Log(LOG_THREAD, "创建IOCP完全端口绑定失败!!!");
			}
			else if (!PrepareRecv()){
				ret = false;
				Log(LOG_THREAD, "准备接收数据失败!!!");
			}
			else{
				SetNetCutedStatus(false);
				WSASendData();
			}
		}
		else
			Log(LOG_THREAD, "重连失败!!!");
	}

	return ret;
}

bool CClientNetMgr::SendDataOld(DWORD dwMainID, DWORD dwSubID)
{
	CLockMgr LockMgr(&SendLock_);

	if (sizeof(NetMsgHead) + dwSendLen_ > dwTotalSendLen_)  return false;

	NetMsgHead *pMsgHead = (NetMsgHead*)(sendBuf_ + dwSendLen_);
	int nSize = sizeof(NetMsgHead);
	pMsgHead->dwMainID = dwMainID;
	pMsgHead->dwSubID = dwSubID;
	pMsgHead->dwSize = nSize;
	pMsgHead->dwReserve = dwCheckCode_;

	dwSendLen_ += nSize;

	return WSASendData();
}

bool CClientNetMgr::SendDataOld(DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen)
{
	if (NULL == pMsgData)  return false;

	CLockMgr LockMgr(&SendLock_);

	if (sizeof(NetMsgHead) + dwSendLen_ > dwTotalSendLen_)  return false;

	NetMsgHead *pMsgHead = (NetMsgHead*)(sendBuf_ + dwSendLen_);
	int nSize = sizeof(NetMsgHead);
	pMsgHead->dwMainID = dwMainID;
	pMsgHead->dwSubID = dwSubID;
	pMsgHead->dwSize = dwMsgLen + nSize;
	pMsgHead->dwReserve = dwCheckCode_;

	memcpy(sendBuf_ + dwSendLen_ + nSize, (char*)pMsgData, dwMsgLen);
	dwSendLen_ += nSize + dwMsgLen;

	return WSASendData();
}

bool CClientNetMgr::SendDataOld(void* pAllMsgData, DWORD dwAllMsgLen)
{
	if (NULL == pAllMsgData)  return false;

	CLockMgr LockMgr(&SendLock_);

	if (/*dwAllMsgLen<sizeof(NetMsgHead) || dwAllMsgLen>MAX_MESSAGE_LENGTH || */dwAllMsgLen > dwTotalSendLen_ - dwSendLen_)
	{
		if (!bIsListHaveData_)
		{
			Log(LOG_THREAD, "oldclient:send buff full.AllLen=%d,CurLen=%d,MsgLen=%d,", dwTotalSendLen_, dwSendLen_, dwAllMsgLen);
		}

		PushSendList(pAllMsgData, dwAllMsgLen);
		bIsListHaveData_ = true;
		return WSASendData();
	}

	if (bIsListHaveData_)
	{
		PushSendList(pAllMsgData, dwAllMsgLen);
		return WSASendData();
	}
		
	memcpy(sendBuf_ + dwSendLen_, (char*)pAllMsgData, dwAllMsgLen);
	dwSendLen_ += dwAllMsgLen;

	return WSASendData();
}

bool CClientNetMgr::SendData(void* pAllMsgData, DWORD dwAllMsgLen)
{
	if (NULL == pAllMsgData)  return false;

	CLockMgr LockMgr(&SendLock_);

	if (/*dwAllMsgLen<sizeof(CNetMsgHead) || dwAllMsgLen>MAX_MESSAGE_LENGTH || */dwAllMsgLen > dwTotalSendLen_ - dwSendLen_)
	{
		if (!bIsListHaveData_)
		{
			Log(LOG_THREAD, "client:send buff full.AllLen=%d,CurLen=%d,MsgLen=%d,", dwTotalSendLen_, dwSendLen_, dwAllMsgLen);
		}

		PushSendList(pAllMsgData, dwAllMsgLen);
		bIsListHaveData_ = true;
		return WSASendData();
	}

	if (bIsListHaveData_)
	{
		PushSendList(pAllMsgData, dwAllMsgLen);
		return WSASendData();
	}

	memcpy(sendBuf_ + dwSendLen_, (char*)pAllMsgData, dwAllMsgLen);
	dwSendLen_ += dwAllMsgLen;

	return WSASendData();
}

bool CClientNetMgr::CheckSendData()
{
	NetMsgHead* pMsgHead = (NetMsgHead*)sendBuf_;
	DWORD &dwSize = pMsgHead->dwSize;

	try
	{
		while (dwSendLen_ >= sizeof(NetMsgHead))
		{
			if (dwSize < sizeof(NetMsgHead)) throw "invalid message!";
			if (dwSize > MAX_MESSAGE_LENGTH) throw "message too long!";
			if (dwSize > dwSendLen_)         throw "not full message!";

			int nRe = send(GetSocket(), sendBuf_, dwSize, 0);  //发送A包
			if (nRe > 0)
			{
				int dwSizeTmp = dwSize;
				memmove(sendBuf_, sendBuf_ + nRe, dwSendLen_ - nRe);
				dwSendLen_ -= nRe;

				if (nRe == dwSizeTmp)  continue;               //A包完成
				else if (nRe < dwSizeTmp)                      //A未完成
				{
					int nSendSize = dwSizeTmp - nRe;
					for (int i = 0; i < 5; i++)                    //继续发A包
					{
						nRe = send(GetSocket(), sendBuf_, nSendSize, 0);
						memmove(sendBuf_, sendBuf_ + nRe, dwSendLen_ - nRe);
						dwSendLen_ -= nRe;

						if (nRe == nSendSize) break;
						else if (nRe>0 && nRe < nSendSize)
						{
							if (5 == i) throw "send error for 5 times!";
							nSendSize -= nRe;
							share_sleep(30);
						}
						else throw "send error!";
					}
				}
				else throw "send error!";
			}
			else throw "other error";
		}

	}
	catch (char* str)
	{
		Log(LOG_THREAD, "CheckSendData error.str=%s\n", str);
		return false;
	}
	catch (...)
	{
		Log_ThreadPosition();
		return false;
	}

	return true;
}

void CClientNetMgr::SetBuffLen(DWORD dwRecvLen, DWORD dwSendLen)
{
	if (dwRecvLen > 0 && dwSendLen > 0)
	{
		dwTotalRecvLen_ = dwRecvLen;
		dwTotalSendLen_ = dwSendLen;
	}
}

void CClientNetMgr::SetNetCutedStatus(bool bIsNetCuted)
{
	CLockMgr LockMgr(&NetCutedLock_);
	bIsNetCuted_ = bIsNetCuted;
}

bool CClientNetMgr::IsNetCuted()
{
	CLockMgr LockMgr(&NetCutedLock_);
	return bIsNetCuted_;
}