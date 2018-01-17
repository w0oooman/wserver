#include  <process.h> 
#include  "KernelMgr.h"
#include  "NetMgr.h"

//线程检测定时器触发间隔(越小定时越精确，但CPU也更耗性能)
#define WHEEL_TIMER_TICK_SPLIT (WHEEL_TIMER_TICK / 20)

struct tagReadData
{
	HANDLE        event;
	HANDLE        iocp;
	IKernelMgr   *kernelmgr;
	CLockFreeMgr/*CQueueMsg*/*   msg;
	void         *data;  //额外数据
};


MKernelMgr::MKernelMgr()
{
	bIsRunning_ = true;
	hEvent_ = NULL;
	pTimerMgr_ = NULL;
	pQueueNormalMsg_ = NULL;
	pQueueNormalMsg_ = new CLockFreeMgr;

	pTimerMgr_ = new CTimerMgr(this);

	//创建事件
	hEvent_ = ::CreateEvent(NULL, 0, 0, NULL);
	if (NULL == hEvent_) Log(LOG_THREAD, "Create event failed!");
}

MKernelMgr::~MKernelMgr()
{
	bIsRunning_ = false;
	delete pQueueNormalMsg_;
	pQueueNormalMsg_ = NULL;
	SAFE_DELETE(pTimerMgr_);
}

bool MKernelMgr::GetIsRunning()
{
	return bIsRunning_;
}
CLockFreeMgr *MKernelMgr::GetNormalQueue()
{
	return pQueueNormalMsg_;
}

unsigned int MKernelMgr::TimerThread(void *pData)
{
	if (NULL == pData)  return -1;

	tagReadData    *ThreadData = static_cast<tagReadData*>(pData);
	IKernelMgr*     pKernelMgr = ThreadData->kernelmgr;
	CTimerMgr      *pWheelTimerMgr = (CTimerMgr *)ThreadData->data;

	::SetEvent(ThreadData->event);
	if (NULL == pKernelMgr)  return -1;

	DWORD  dwTime = GetTickCount();//timeGetTime();

	while (pKernelMgr->GetIsRunning())
	{
		if (GetTickCount() - dwTime < WHEEL_TIMER_TICK_SPLIT)
		{
			DWORD dwTimeTemp = WHEEL_TIMER_TICK_SPLIT / 2;
			if (dwTimeTemp < 10) dwTimeTemp = 10;      //windows 精度10ms左右
			share_sleep(dwTimeTemp);
			continue;
		}

		//CWheelTimerMgrEx::Instance()->RunEvent();
		pWheelTimerMgr->RunEvent();

		dwTime = GetTickCount();
	}

	return 0;
}

int MKernelMgr::AddEvent(int timerID, int interval, TimerCallBackFunc func/* = NULL*/, void *data/* = NULL*/, int type /*= CTimerMgr::CIRCLE*/)
{
	return pTimerMgr_/*CWheelTimerMgrEx::Instance()*/->AddEvent(timerID, interval, func, data, type);
}

bool MKernelMgr::RemoveEvent(int timerID)
{
	return pTimerMgr_/*CWheelTimerMgrEx::Instance()*/->RemoveEvent(timerID);
}

void MKernelMgr::RemoveAllEvent()
{
	pTimerMgr_->RemoveAllEvent();
}

//是否存在定时器ID
bool MKernelMgr::IsExistTimerID(int timerID)
{
	return pTimerMgr_->IsExistTimerID(timerID);
}

void MKernelMgr::DeleteTimerData(const void *data)
{

}

void MKernelMgr::HandleTimerEvent(IKernelMgr* pKernelMgr, void* pTimeData)
{
	tagWheelTimer *pTagTimer = (tagWheelTimer*)pTimeData;
	if (pKernelMgr->IsExistTimerID(pTagTimer->timerID))
	{
		if (pTagTimer->func && !IsBadReadPtr(pTagTimer->func, sizeof(int*)))
			((TimerCallBackFunc)(pTagTimer->func))(pTagTimer->data);
		else
			pKernelMgr->OnEvent(pTagTimer->timerID, pTagTimer->data);

		if (CTimerMgr::CIRCLE != pTagTimer->type)
			pKernelMgr->RemoveEvent(pTagTimer->timerID);
	}
}

void MKernelMgr::OnEvent(int timerID, void *data)
{
	//printf("OnEvent timerID=%d\n",timerID);//whb
}



CKernelMgr::CKernelMgr()
{
#ifdef _MSC_VER
	CoInitialize(NULL);
	//CWSAInit::InstancePtr()->WSAInit();
	//CWheelTimerMgrEx::Instance();
	WSAInit();
#else
#endif

	hQueueNormalIOCP_ = NULL;
	hQueueDBIOCP_ = NULL;
	hQueueTimerIOCP_ = NULL;
	hNormalThreadHandle_ = NULL;
	hBatchThreadHandle_ = NULL;
	hDBThreadHandle_ = NULL;
	hTimerThreadHandle_ = NULL;
	pNetMgr_ = NULL;
	pQueueDBMsg_ = NULL;
	pQueueDBMsg_ = new CLockFreeMgr;
}

CKernelMgr::~CKernelMgr()
{
	bIsRunning_ = false;

	Log(LOG_THREAD, "closing server...");

#ifdef _MSC_VER
	if (hQueueNormalIOCP_)
	    PostQueuedCompletionStatus(hQueueNormalIOCP_, 0, NULL, NULL);
	if (hQueueDBIOCP_)
	    PostQueuedCompletionStatus(hQueueDBIOCP_, 0, NULL, NULL); 

	if (hNormalThreadHandle_)
	    WaitForSingleObject(hNormalThreadHandle_, 10000);
	if (hBatchThreadHandle_)
	    WaitForSingleObject(hBatchThreadHandle_, 10000);
	if (hDBThreadHandle_)
	    WaitForSingleObject(hDBThreadHandle_, 10000);
	if (hTimerThreadHandle_)
	    WaitForSingleObject(hTimerThreadHandle_, 10000);

	if (hNormalThreadHandle_)
	    ::CloseHandle(hNormalThreadHandle_);
	if (hBatchThreadHandle_)
	    ::CloseHandle(hDBThreadHandle_);
	if (hDBThreadHandle_)
	    ::CloseHandle(hDBThreadHandle_);
	if (hTimerThreadHandle_)
	    ::CloseHandle(hTimerThreadHandle_);

	SAFE_DELETE(pNetMgr_);

	delete pQueueDBMsg_;
	pQueueDBMsg_ = NULL;

	//CWSAInit::InstancePtr()->WSAUnInit();
	//CWSAInit::ExitInstance();
	//CWheelTimerMgrEx::ExitInstance();

	WSAUnInit();
	CoUninitialize();
#else
#endif
	hNormalThreadHandle_ = NULL;
	hBatchThreadHandle_ = NULL;
	hDBThreadHandle_ = NULL;
	hTimerThreadHandle_ = NULL;
}

CNetMgr* CKernelMgr::GetNetMgr()
{
	return pNetMgr_;
}

bool CKernelMgr::Init(DWORD dwMaxCount, DWORD dwListenPort)
{
	try
	{
		pNetMgr_ = new CNetMgr;
		//pNetMgr_ = shared_ptr <CNetMgr>(new CNetMgr);
		if (NULL == pNetMgr_) return false;

		if (!pNetMgr_->Init(dwMaxCount, dwListenPort, this)) return false;
	
	}
	catch (...)
	{
		Log_ThreadPosition();
		return false;
	}

	return true;
}

void CKernelMgr::SetBuffLen(DWORD dwRecvLen, DWORD dwSendLen)
{
	pNetMgr_->SetBuffLen(dwRecvLen, dwSendLen);
}

DWORD CKernelMgr::GetMaxCount()
{
	return pNetMgr_->GetMaxCount();
}

void CKernelMgr::SetIsSpecialClient(bool bIsSpecialClient)
{
	pNetMgr_->SetIsSpecialClient(bIsSpecialClient);
}

void CKernelMgr::SetMsgConnectID(CNetMsgHead *pDestMsg, CNetMsgHead *pSourceMsg)
{
	pDestMsg->reserve1_ = pSourceMsg->reserve1_;
	pDestMsg->reserve2_ = pSourceMsg->reserve2_;
}

bool CKernelMgr::Start()
{
	try
	{
		//普通端口
		hQueueNormalIOCP_ = ::CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
		if (NULL == hQueueNormalIOCP_)       throw CNetErr("create normal queue io failed!", true);
		//数据库端口
		hQueueDBIOCP_ = ::CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
		if (NULL == hQueueDBIOCP_)           throw CNetErr("create db queue io failed!", true);
		//定时器端口
		//hQueueTimerIOCP_ = ::CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
		//if (NULL == hQueueTimerIOCP_)           throw CNetErr("create timer queue io failed!", true);

		//设置端口
		pQueueNormalMsg_->SetQueueIOCP(hQueueNormalIOCP_);
		pQueueDBMsg_->SetQueueIOCP(hQueueDBIOCP_);
		//QueueTimerMsg_.SetQueueIOCP(hQueueTimerIOCP_);

		//设置大小
		pQueueNormalMsg_->SetLimitSize(NORMAL_QUEUE_LIMIT_SIZE);
		pQueueDBMsg_->SetLimitSize(DB_QUEUE_LIMIT_SIZE);
		//QueueTimerMsg_.SetLimitSize(TIMER_QUEUE_LIMIT_SIZE);

		//普通线程
		tagReadData ThreadData;
		ThreadData.event = hEvent_;
		ThreadData.iocp = hQueueNormalIOCP_;
		ThreadData.kernelmgr = this;
		//ThreadData.msgmgr = pMsgMgr_;
		ThreadData.msg = pQueueNormalMsg_;
		hNormalThreadHandle_ = (HANDLE)::_beginthreadex(NULL, 0, QueueThread, &ThreadData, 0, NULL);
		if (NULL == hNormalThreadHandle_)  throw CNetErr("create Queue thread failed!", true);
		::WaitForSingleObject(hEvent_, INFINITE);
		::ResetEvent(hEvent_);

		//数据库线程
		ThreadData.iocp = hQueueDBIOCP_;
		ThreadData.msg = pQueueDBMsg_;
		hDBThreadHandle_ = (HANDLE)::_beginthreadex(NULL, 0, QueueThread, &ThreadData, 0, NULL);
		if (NULL == hDBThreadHandle_)  throw CNetErr("create Queue thread failed!", true);
		::WaitForSingleObject(hEvent_, INFINITE);
		::ResetEvent(hEvent_);

		//定时器线程
		ThreadData.iocp = hQueueNormalIOCP_;
		ThreadData.msg = pQueueNormalMsg_;
		ThreadData.data = pTimerMgr_;
		hTimerThreadHandle_ = (HANDLE)::_beginthreadex(NULL, 0, TimerThread, &ThreadData, 0, NULL);
		if (NULL == hTimerThreadHandle_)  throw CNetErr("create Queue thread failed!", true);
		::WaitForSingleObject(hEvent_, INFINITE);
		::ResetEvent(hEvent_);

		//启动核心网络
		if (pNetMgr_ != NULL)  return pNetMgr_->Start();	
	}
	catch (CNetErr &err)
	{
		Log(LOG_THREAD, (char*)err);
	}
	catch (...)
	{
		Log_ThreadPosition();
	}

	return false;
}

bool CKernelMgr::OnSocketRead(ULLONG llConnectID, const char* pData, DWORD dwSize)
{
	return pQueueNormalMsg_->AddData(llConnectID, pData, dwSize, QMD_NORMAL_DATA);
}

//关闭socket
bool CKernelMgr::PrepareCloseConnect(ULLONG llConnectID)
{
	return pQueueNormalMsg_->AddData(llConnectID, QMD_CLOSE_SOCKET);
}

bool CKernelMgr::CloseConnect(ULLONG llConnectID)
{
	CNetMgr* pNetMgr = GetNetMgr();
	if (pNetMgr != NULL)
	{
		pNetMgr->CloseSocket(llConnectID);
		return true;
	}
	return false;
}

//释放玩家数据
void CKernelMgr::OnCloseConnect(ULLONG llConnectID)
{

}

unsigned int CKernelMgr::QueueThread(void *pData)
{
	tagReadData   *ThreadData = static_cast<tagReadData*>(pData);
	HANDLE         hQueueIOCP = ThreadData->iocp;
	IKernelMgr*    pKernelMgr = ThreadData->kernelmgr;
	CLockFreeMgr/*CQueueMsg*/*     pQueueMsg = ThreadData->msg;

	::SetEvent(ThreadData->event);
	if (NULL == pKernelMgr)  return -1;

	int   nQueueBufLen = 1024 * 8;//MAX_MESSAGE_LENGTH + 512;
	char *pQueueBuf = new char[nQueueBufLen];
	tagQueueData *pQueueData = reinterpret_cast<tagQueueData*>(pQueueBuf);

	LPOVERLAPPED OL;
	DWORD dwTransfer;
	ULONG_PTR    ulKey;
	while (pKernelMgr->GetIsRunning())
	{
		dwTransfer = 0, ulKey = 0, OL = NULL;
		try
		{
			GetQueuedCompletionStatus(hQueueIOCP, &dwTransfer, (PULONG_PTR)&ulKey, (LPOVERLAPPED*)&OL, INFINITE);
			if (0 == dwTransfer/*&&0==dwRe*/)  break;

			//可优化：使用AddData时new的内存,减少再copy一次的资源浪费 whb
			//但存在一定风险：内存操作一旦越界，将崩服，但使用szBuf不太可能越界
			if (!pQueueMsg->GetData(pQueueData, nQueueBufLen))   continue;

			switch (pQueueData->byQueueType)
			{
			case QMD_NORMAL_DATA:
			{
				if (!pKernelMgr->OnNormalMsgHandle(pQueueData->llConnectID, pQueueData->pQueueData, pQueueData->dwSize))
					pKernelMgr->CloseConnect(pQueueData->llConnectID);
				break;
			}
			case QMD_DB_DATA:
				pKernelMgr->OnDBMsghandle(pQueueData->llConnectID, (NetMsgHead*)(pQueueData->pQueueData) + 1, pQueueData->dwSize, pQueueData->wDBType);
				break;
			case QMD_TIMER_DATA:
			{
#ifdef WHEEL_TIMER_LOCK
				pKernelMgr->HandleTimerEvent(pKernelMgr, (tagWheelTimer *)(pQueueData->pQueueData));
#endif
			}
				break;
			case QMD_DELETE_TIMERDATA:
				pKernelMgr->DeleteTimerData(pQueueData->pData);
				break;
			case QMD_CLOSE_SOCKET:
				pKernelMgr->OnCloseConnect(pQueueData->llConnectID);
				break;
			}
		}
		catch (...)
		{
			
		}
	}

	delete []pQueueBuf;
	return 0;
}

bool CKernelMgr::SendBatchDataOld(DWORD dwMainID, DWORD dwSubID, const void* pMsgData, DWORD dwMsgLen/*, bool bAddQueue=0*/)
{
	if (NULL == pMsgData) dwMsgLen = 0;
	return pNetMgr_->GetBatchQueue()->AddDataOld(dwMainID, dwSubID, pMsgData, dwMsgLen, QMD_BATCH_DATA);
}

bool CKernelMgr::SendBatchDataOld(const void* pMsgData, DWORD dwMsgLen/*, bool bAddQueue=0*/)
{
	if (NULL == pMsgData) dwMsgLen = 0;
	return pNetMgr_->GetBatchQueue()->AddData(pMsgData, dwMsgLen, QMD_BATCH_DATA);
}

bool CKernelMgr::SendBatchData(const void* pMsgData, DWORD dwMsgLen/*, bool bAddQueue=0*/)
{
	if (NULL == pMsgData) dwMsgLen = 0;
	return pNetMgr_->GetBatchQueue()->AddData(pMsgData, dwMsgLen, QMD_BATCH_DATA);
}

bool CKernelMgr::HandleDBData(ULLONG llConnectID,void* pData, DWORD dwSize, WORD wDBType)
{
	pQueueDBMsg_->AddData(llConnectID, pData, dwSize, QMD_DB_DATA, wDBType);
	return true;
}

bool CKernelMgr::SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, DWORD dwRoundIndex)
{
	return pNetMgr_->SendDataOld(dwIndex, dwMainID, dwSubID, dwRoundIndex);
}

bool CKernelMgr::SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, const void* pMsgData, DWORD dwMsgLen, DWORD dwRoundIndex)
{
	return pNetMgr_->SendDataOld(dwIndex, dwMainID, dwSubID, (void*)pMsgData, dwMsgLen, dwRoundIndex);
}

bool CKernelMgr::SendDataOld(DWORD dwIndex, const void* pAllMsgData, DWORD dwAllMsgLen, DWORD dwRoundIndex)
{
	return pNetMgr_->SendDataOld(dwIndex, (void*)pAllMsgData, dwAllMsgLen, dwRoundIndex);
}

bool CKernelMgr::SendData(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen)
{
	pNetMsgHead->size_ = dwAllMsgLen;
	return pNetMgr_->SendData(llConnectID, (void*)pNetMsgHead, dwAllMsgLen);
}

bool CKernelMgr::SendData(CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen)
{
	pNetMsgHead->size_ = dwAllMsgLen;
	return pNetMgr_->SendData((void*)pNetMsgHead, dwAllMsgLen);
}







CClientCKernelMgr::CClientCKernelMgr()
{
	CoInitialize(NULL);
	WSAInit();

	pNetMgr_ = NULL;
	hTimerThreadHandle_ = NULL;
	hEvent_ = NULL;
}

CClientCKernelMgr::~CClientCKernelMgr()
{
	bIsRunning_ = false;
	WSAUnInit();
	CoUninitialize();

	WaitForSingleObject(hTimerThreadHandle_, 10000);
	::CloseHandle(hTimerThreadHandle_);
	hTimerThreadHandle_ = NULL;

	::CloseHandle(hEvent_);
	hEvent_ = NULL;

	SAFE_DELETE(pNetMgr_);
}

bool CClientCKernelMgr::Init(LPCTSTR lpIP, USHORT usPort)
{
	try
	{
		pNetMgr_ = new CClientNetMgr;
		if (NULL == pNetMgr_) return false;

		pTimerMgr_ = new CTimerMgr(this);
		if (NULL == pTimerMgr_) return false;

		if (!pNetMgr_->Init(lpIP, usPort, this)) return false;
	}
	catch (...)
	{
		Log_ThreadPosition();
		return false;
	}

	return true;
}

bool CClientCKernelMgr::Start()
{
	bool ret = true;
	try
	{
		ret = pNetMgr_->Start();
		if (!ret) throw CNetErr("连接失败！", true);
	}
	catch (CNetErr &err)
	{
		Log(LOG_THREAD, (char*)err);
		//return false;  //继续运行，以便重连
	}
	catch (...)
	{
		Log_ThreadPosition();
		//return false;  //继续运行，以便重连
	}

	hEvent_ = ::CreateEvent(NULL, 0, 0, NULL);
	if (NULL == hEvent_)  throw CNetErr("create event failed!", true);

	pQueueNormalMsg_->SetQueueIOCP(pNetMgr_->GetIOCPHandle());
	pQueueNormalMsg_->SetLimitSize(CLIENT_NORMAL_QUEUE_SIZE);

	//定时器线程
	tagReadData ThreadData;
	ThreadData.event = hEvent_;
	ThreadData.kernelmgr = this;
	ThreadData.data = pTimerMgr_;
	hTimerThreadHandle_ = (HANDLE)_beginthreadex(NULL, 0, TimerThread, &ThreadData, 0, NULL);
	if (NULL == hTimerThreadHandle_) throw CNetErr("create timer thread failed!", true);
	::WaitForSingleObject(hEvent_, INFINITE);
	::ResetEvent(hEvent_);

	//心跳定时器
	pTimerMgr_->AddEvent(0, HEART_BEAT_TEST_TIME * 1000, &CClientCKernelMgr::SendHeartBeatCallBack, this);

	//重连定时器
	pTimerMgr_->AddEvent(0, CLIENT_RECONNECT_TIME * 1000, &CClientCKernelMgr::ReConnectCallBack, this);

	return ret;
}

CClientNetMgr* CClientCKernelMgr::GetNetMgrPtr()
{
	return pNetMgr_;
}

void CClientCKernelMgr::CloseSocket()
{
	pNetMgr_->CloseSocket();
}

void CClientCKernelMgr::SendHeartBeatCallBack(void *data)
{
	CClientCKernelMgr *pKernelMgr = static_cast<CClientCKernelMgr *>(data);
	if (pKernelMgr && !IsBadReadPtr(pKernelMgr, sizeof(CClientCKernelMgr*)))
	{
		pKernelMgr->SendData(&CNetMsgHead(CNetMsgHead::NETMSG_HEART_BEAT), sizeof(CNetMsgHead));
	}
}

void CClientCKernelMgr::ReConnectCallBack(void *data)
{
	CClientCKernelMgr *pKernelMgr = static_cast<CClientCKernelMgr *>(data);
	if (pKernelMgr && !IsBadReadPtr(pKernelMgr, sizeof(CClientCKernelMgr*)))
	{
		pKernelMgr->GetNetMgrPtr()->ReConnect();
	}
}

bool CClientCKernelMgr::OnNetMessageOld(NetMsgHead *pNetMsgHead, char* pMsgData, DWORD dwMsgLen)
{
	return true;
}

bool CClientCKernelMgr::OnNetMessage(const void* pData, DWORD dwSize)
{
	return true;
}

bool CClientCKernelMgr::SendDataOld(DWORD dwMainID, DWORD dwSubID)
{
	return pNetMgr_->SendDataOld(dwMainID, dwSubID);
}

bool CClientCKernelMgr::SendDataOld(DWORD dwMainID, DWORD dwSubID,const void* pMsgData, DWORD dwMsgLen)
{
	return pNetMgr_->SendDataOld(dwMainID, dwSubID, (void*)pMsgData, dwMsgLen);
}

bool CClientCKernelMgr::SendDataOld(const void* pAllMsgData, DWORD dwAllMsgLen)
{
	return pNetMgr_->SendData((void*)pAllMsgData, dwAllMsgLen);
}

bool CClientCKernelMgr::SendData(CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen)
{
	pNetMsgHead->size_ = dwAllMsgLen;
	return pNetMgr_->SendData((void*)pNetMsgHead, dwAllMsgLen);
}
