#include "QueueMsg.h"
#ifdef _MSC_VER

#else
#include <atomic.h>
#endif

template<typename TYPE, typename ARG_TYPE = const TYPE&>
CQueueList<TYPE, ARG_TYPE>::CQueueList()
{ 
	m_pNodeHead = NULL; m_pNodeTail = NULL; m_dwCount = 0; 
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
CQueueList<TYPE, ARG_TYPE>::~CQueueList()
{ 
	Clear();
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
DWORD CQueueList<TYPE, ARG_TYPE>::GetCount() const
{ 
	return m_dwCount;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
bool CQueueList<TYPE, ARG_TYPE>::PUSHTail(ARG_TYPE newElement)
{
	CNode* pNode = NULL;
	try
	{
		pNode = new CNode;
		if (pNode != NULL)
		{
			if (0 == m_dwCount)
			{
				pNode->pPrev = NULL;
				pNode->pNext = NULL;
				pNode->data = newElement;
				m_pNodeHead = pNode;
				m_pNodeTail = pNode;
			}
			else
			{
				pNode->pPrev = m_pNodeTail;
				pNode->pNext = NULL;
				pNode->data = newElement;
				m_pNodeTail->pNext = pNode;
				m_pNodeTail = pNode;
			}
			++m_dwCount;
			return true;
		}
	}
	catch (...)
	{
		SAFE_DELETE(pNode);
	}
	return false;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
TYPE  CQueueList<TYPE, ARG_TYPE>::operator[](const DWORD key)
{
	//隐患
	TYPE pData = 0;

	if (key < m_dwCount)
	{
		CNode* pNode = m_pNodeHead;
		for (DWORD i = 0; i < m_dwCount; i++)
		{
			if (pNode)
			{
				if (key == i)
					return pNode->data;
				pNode = pNode->next;
			}
			else
			{
				return pData;
			}
		}
	}

	return pData;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
TYPE  CQueueList<TYPE, ARG_TYPE>::POPHead()
{
	TYPE pData = 0;
	if (m_dwCount > 0)
	{
		pData = m_pNodeHead->data;
		if (m_pNodeHead->pNext != NULL)
		{
			m_pNodeHead = m_pNodeHead->pNext;
			SAFE_DELETE(m_pNodeHead->pPrev)
		}
		else
		{
			SAFE_DELETE(m_pNodeHead);
			m_pNodeTail = NULL;
		}
		--m_dwCount;
		return pData;
	}
	return pData;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
void CQueueList<TYPE, ARG_TYPE>::AddTail(void *node)
{
	CNode *pNode = (CNode*)node;
	//if (sizeof(*pNode) != sizeof(CNode))
	//	return;

	if (pNode != NULL)
	{
		if (0 == m_dwCount)
		{
			pNode->pPrev = NULL;
			pNode->pNext = NULL;
			m_pNodeHead = pNode;
			m_pNodeTail = pNode;
		}
		else
		{
			pNode->pPrev = m_pNodeTail;
			pNode->pNext = NULL;
			m_pNodeTail->pNext = pNode;
			m_pNodeTail = pNode;
		}
		++m_dwCount;
	}
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
void* CQueueList<TYPE, ARG_TYPE>::RemoveHead()
{
	if (m_dwCount > 0)
	{
		CNode *pRet = NULL;
		pData = m_pNodeHead->data;
		if (m_pNodeHead->pNext != NULL)
		{
			m_pNodeHead = m_pNodeHead->pNext;
			pRet = m_pNodeHead->pPrev;
			m_pNodeHead->pPrev = NULL;
		}
		else
		{
			pRet = m_pNodeHead;
			m_pNodeHead = NULL;
			m_pNodeTail = NULL;
		}
		--m_dwCount;
		return pRet;
	}
	return NULL;
}

template<typename TYPE, typename ARG_TYPE = const TYPE&>
void CQueueList<TYPE, ARG_TYPE>::Clear()
{
	for (int i = 0; i < m_dwCount; ++i)
	{
		CNode* pNode = m_pNodeHead->pNext;
		SAFE_DELETE(m_pNodeHead);
		m_pNodeHead = pNode;
	}
}






CQueueBase::CQueueBase()
{
	QueueIOCP_ = NULL;
}

CQueueBase::~CQueueBase()
{

}

void CQueueBase::SetLimitSize(DWORD dwLimitSize)
{

}

void CQueueBase::SetQueueIOCP(HANDLE hIOCP)
{
	QueueIOCP_ = hIOCP; 
}

tagQueueData* CQueueBase::AddData(ULLONG llConnectID, const void* pData, DWORD dwSize, BYTE byQueueType, WORD wDBType/* = 0*/)
{
	if (dwSize <= 0)
		return NULL;

	tagQueueData* pAllQueueData = NULL;
	try
	{
		pAllQueueData = new tagQueueData;
		if (NULL == pAllQueueData) return NULL;
	}
	catch (...)
	{
		if (pAllQueueData != NULL) SAFE_DELETE(pAllQueueData);
		return NULL;
	}

	pAllQueueData->byQueueType = byQueueType;
	pAllQueueData->wDBType = wDBType;
	pAllQueueData->llConnectID = llConnectID;
	pAllQueueData->dwSize = dwSize;
	pAllQueueData->pData = pData;

	pAllQueueData->pQueueData = NULL;
	try
	{
		pAllQueueData->pQueueData = new char[dwSize];
		if (NULL == pAllQueueData->pQueueData) return NULL;
	}
	catch (...)
	{
		if (pAllQueueData->pQueueData != NULL) SAFE_DELETE_ARRAY(pAllQueueData->pQueueData);
		if (pAllQueueData != NULL) SAFE_DELETE(pAllQueueData);
		return NULL;
	}

	memcpy(pAllQueueData->pQueueData, pData, dwSize);

	return pAllQueueData;
}

tagQueueData* CQueueBase::AddDataOld(DWORD dwMainID, DWORD dwSubID, const void* pData, DWORD dwSize, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = NULL;
	try
	{
		pAllQueueData = new tagQueueData;
		if (NULL == pAllQueueData) return NULL;
	}
	catch (...)
	{
		if (pAllQueueData != NULL) SAFE_DELETE(pAllQueueData);
		return NULL;
	}

	DWORD dwSizeTemp = sizeof(NetMsgHead) + dwSize;
	pAllQueueData->byQueueType = byQueueType;
	pAllQueueData->dwSize = dwSizeTemp;
	pAllQueueData->pQueueData = NULL;
	pAllQueueData->pData = pData;

	try
	{
		pAllQueueData->pQueueData = new char[dwSizeTemp];
		if (NULL == pAllQueueData->pQueueData) return NULL;
	}
	catch (...)
	{
		if (pAllQueueData->pQueueData != NULL) SAFE_DELETE_ARRAY(pAllQueueData->pQueueData);
		if (pAllQueueData != NULL) SAFE_DELETE(pAllQueueData);
		return NULL;
	}

	NetMsgHead *pHead = (NetMsgHead *)(pAllQueueData->pQueueData);
	pHead->dwMainID = dwMainID;
	pHead->dwSubID = dwSubID;
	pHead->dwSize = dwSizeTemp;

	if (pData != NULL && dwSize > 0)
	    memcpy(pHead+1, pData, dwSize);

	return pAllQueueData;
}

tagQueueData* CQueueBase::AddData(const void* pData, DWORD dwSize, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = NULL;
	try
	{
		pAllQueueData = new tagQueueData;
		if (NULL == pAllQueueData) return NULL;
	}
	catch (...)
	{
		if (pAllQueueData != NULL) SAFE_DELETE(pAllQueueData);
		return NULL;
	}

	pAllQueueData->byQueueType = byQueueType;
	pAllQueueData->dwSize = dwSize;
	pAllQueueData->pQueueData = NULL;
	pAllQueueData->pData = pData;

	try
	{
		pAllQueueData->pQueueData = new char[dwSize];
		if (NULL == pAllQueueData->pQueueData) return NULL;
	}
	catch (...)
	{
		if (pAllQueueData->pQueueData != NULL) SAFE_DELETE_ARRAY(pAllQueueData->pQueueData);
		if (pAllQueueData != NULL) SAFE_DELETE(pAllQueueData);
		return NULL;
	}

	if (pData != NULL && dwSize > 0)
		memcpy(pAllQueueData->pQueueData, pData, dwSize);

	return pAllQueueData;
}

tagQueueData* CQueueBase::AddData(ULLONG llConnectID, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = NULL;
	try
	{
		pAllQueueData = new tagQueueData;
		if (NULL == pAllQueueData) return NULL;
	}
	catch (...)
	{
		if (pAllQueueData != NULL) SAFE_DELETE(pAllQueueData);
		return NULL;
	}

	pAllQueueData->byQueueType = byQueueType;
	pAllQueueData->llConnectID = llConnectID;
	pAllQueueData->dwSize = 0;
	pAllQueueData->pQueueData = NULL;

	return pAllQueueData;
}

CQueueMsg::CQueueMsg()
{
	
}

CQueueMsg::~CQueueMsg()
{

}


bool CQueueMsg::AddData(ULLONG llConnectID, const void* pData, DWORD dwSize, BYTE byQueueType, WORD wDBType/*=0*/)
{
	//if (NULL == pData)   return false;

	tagQueueData* pAllQueueData = CQueueBase::AddData(llConnectID,pData,dwSize,byQueueType,wDBType);
	if (NULL == pAllQueueData) return false;

	CLockMgr LockMgr(&QueueLock_);
	if(QueueList_.PUSHTail(pAllQueueData))
	{
		if (QueueIOCP_)
		{
			::PostQueuedCompletionStatus(QueueIOCP_, 0 == dwSize ? 1 : dwSize, 0, NULL);
		}
		return true;
	}
	
	return false;
}

bool CQueueMsg::AddDataOld(DWORD dwMainID, DWORD dwSubID, const void* pData, DWORD dwSize, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = CQueueBase::AddDataOld(dwMainID, dwSubID, pData, dwSize, byQueueType);
	if (NULL == pAllQueueData) return false;

	CLockMgr LockMgr(&QueueLock_);
	if (QueueList_.PUSHTail(pAllQueueData))
	{
		if (QueueIOCP_)
		{
			::PostQueuedCompletionStatus(QueueIOCP_, 0 == dwSize ? 1 : dwSize, 0, NULL);
		}
		return true;
	}

	return false;
}

bool CQueueMsg::AddData(const void* pData, DWORD dwSize, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = CQueueBase::AddData(pData, dwSize, byQueueType);
	if (NULL == pAllQueueData) return false;

	CLockMgr LockMgr(&QueueLock_);
	if (QueueList_.PUSHTail(pAllQueueData))
	{
		if (QueueIOCP_)
		{
			::PostQueuedCompletionStatus(QueueIOCP_, 0 == dwSize ? 1 : dwSize, 0, NULL);
		}
		return true;
	}

	return false;
}

bool CQueueMsg::AddData(ULLONG llConnectID, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = CQueueBase::AddData(llConnectID, byQueueType);
	if (NULL == pAllQueueData) return false;

	CLockMgr LockMgr(&QueueLock_);
	if (QueueList_.PUSHTail(pAllQueueData))
	{
		if (QueueIOCP_)
		{
			::PostQueuedCompletionStatus(QueueIOCP_, 1, 0, NULL);
		}
		return true;
	}

	return false;
}

bool CQueueMsg::GetData(tagQueueData* pData, DWORD dwSize)
{
	CLockMgr LockMgr(&QueueLock_);

	if (QueueList_.GetCount() <= 0) 
	{
		LockMgr.UnLock();
		return false;
	}

	tagQueueData* pTmpData = QueueList_.POPHead();
	if (NULL == pTmpData)
	{
		LockMgr.UnLock();
		return false;
	}
	LockMgr.UnLock();

	if (pTmpData->dwSize > dwSize) return false;
	//memset(pData, 0, pTmpData->QueueHead.dwSize + dwTmpSize + 1); //可以不要

	pData->byQueueType = pTmpData->byQueueType;
	pData->wDBType = pTmpData->wDBType;
	pData->llConnectID = pTmpData->llConnectID;
	pData->dwSize = pTmpData->dwSize;
	pData->pData = pTmpData->pData;

	memcpy(&pData->pQueueData, pTmpData->pQueueData, pTmpData->dwSize);

	SAFE_DELETE_ARRAY(pTmpData->pQueueData);
	SAFE_DELETE(pTmpData);

	return true;
}




CLockFreeQueue::CLockFreeQueue(DWORD dwSize)
{
	dwHead_ = 0;
	dwTail_ = 0;
	dwSize_ = dwSize;
	ppBuf_ = NULL;

	try
	{
		ppBuf_ = new void*[dwSize_];
		if (NULL == ppBuf_) throw "new null.";
	}
	catch (...)
	{
		if (ppBuf_ != NULL) SAFE_DELETE(ppBuf_);
		throw "new error.";
	}
}

CLockFreeQueue::~CLockFreeQueue()
{
	DWORD dwBegin = dwHead_&(dwSize_ - 1);
	DWORD dwEnd = dwTail_&(dwSize_ - 1);
	tagQueueData *pQueueData = NULL;
	for(int i = dwBegin;i < dwEnd;i++)
	{
	    pQueueData = (tagQueueData*)ppBuf_[i];
		SAFE_DELETE_ARRAY(pQueueData->pQueueData);
		SAFE_DELETE(pQueueData);
	}

	SAFE_DELETE_ARRAY(ppBuf_);
}





CLockFreeMgr::CLockFreeMgr()
{
	dwLimitSize_ = 1;
	pLockFreeQueue_ = NULL;
}

CLockFreeMgr::~CLockFreeMgr()
{
	SAFE_DELETE(pLockFreeQueue_);
}

void CLockFreeMgr::SetLimitSize(DWORD dwLimitSize)
{
	if (dwLimitSize > 0)
	    dwLimitSize_ = dwLimitSize;

	try
	{
		pLockFreeQueue_ = new CLockFreeQueue(dwLimitSize_);
		if (NULL == pLockFreeQueue_) throw "new null.";
	}
	catch (...)
	{
		if (pLockFreeQueue_ != NULL) SAFE_DELETE(pLockFreeQueue_);
		throw "new error.";
	}
}

#ifdef _MSC_VER
#define CAS(a,b,c) (InterlockedCompareExchange((volatile LONG*)a,(LONG)c,(LONG)b) == b)
#else
#define CAS(a,b,c) (__sync_bool_compare_and_swap((volatile LONG*)a,(LONG)b,(LONG)c) == b)
#endif

bool CLockFreeMgr::PUSHBack(void *data)
{
	DWORD head, tail, next;
	while (true)
	{
		head = pLockFreeQueue_->dwHead_;
		tail = pLockFreeQueue_->dwTail_;
		next = tail + 1;

		if (next - head > pLockFreeQueue_->dwSize_)
			return false;
		if (CAS(&pLockFreeQueue_->dwTail_, tail, next))
			break;
	}

	pLockFreeQueue_->ppBuf_[tail&(pLockFreeQueue_->dwSize_ - 1)] = data;
	return true;
}

void* CLockFreeMgr::POPFront()
{
	DWORD head, tail, next;

	while (true)
	{
		head = pLockFreeQueue_->dwHead_;
		tail = pLockFreeQueue_->dwTail_;
		next = head + 1;

		if (head == tail)
			return NULL;

		if (CAS(&pLockFreeQueue_->dwHead_, head, next))
			break;
	}
	return pLockFreeQueue_->ppBuf_[head&(pLockFreeQueue_->dwSize_ - 1)];
}

bool CLockFreeMgr::AddData(ULLONG llConnectID, const void* pData, DWORD dwSize, BYTE byQueueType, WORD wDBType /*= 0*/)
{
	tagQueueData* pAllQueueData = CQueueBase::AddData(llConnectID, pData, dwSize, byQueueType, wDBType);
	if (NULL == pAllQueueData) return false;

	if (!PUSHBack(pAllQueueData))
	{
		Log(LOG_THREAD, "*********lockfree full !!!!!! type = %d**********", byQueueType);
		return false;
	}

	if (QueueIOCP_)
	{
		CLockMgr LockMgr(&QueueLock_);
		::PostQueuedCompletionStatus(QueueIOCP_, 0 == dwSize ? 1 : dwSize, 0, NULL);
	}

	return true;
}

bool CLockFreeMgr::AddDataOld(DWORD dwMainID, DWORD dwSubID, const void* pData, DWORD dwSize, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = CQueueBase::AddDataOld(dwMainID, dwSubID, pData, dwSize, byQueueType);
	if (NULL == pAllQueueData) return false;

	if (!PUSHBack(pAllQueueData))
	{
		Log(LOG_THREAD, "*********lockfree full !!!!!! type = %d**********", byQueueType);
		return false;
	}

	if (QueueIOCP_)
	{
		CLockMgr LockMgr(&QueueLock_);
		::PostQueuedCompletionStatus(QueueIOCP_, 0 == dwSize ? 1 : dwSize, 0, NULL);
	}

	return true;
}

bool CLockFreeMgr::AddData(const void* pData, DWORD dwSize, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = CQueueBase::AddData(pData, dwSize, byQueueType);
	if (NULL == pAllQueueData) return false;

	if (!PUSHBack(pAllQueueData))
	{
		Log(LOG_THREAD, "*********lockfree full !!!!!! type = %d**********", byQueueType);
		return false;
	}

	if (QueueIOCP_)
	{
		CLockMgr LockMgr(&QueueLock_);
		::PostQueuedCompletionStatus(QueueIOCP_, 0 == dwSize ? 1 : dwSize, 0, NULL);
	}

	return true;
}

bool CLockFreeMgr::AddData(ULLONG llConnectID, BYTE byQueueType)
{
	tagQueueData* pAllQueueData = CQueueBase::AddData(llConnectID, byQueueType);
	if (NULL == pAllQueueData) return false;

	if (!PUSHBack(pAllQueueData))
	{
		Log(LOG_THREAD, "*********lockfree full !!!!!! type = %d**********", byQueueType);
		return false;
	}

	if (QueueIOCP_)
	{
		CLockMgr LockMgr(&QueueLock_);
		::PostQueuedCompletionStatus(QueueIOCP_, 1, 0, NULL);
	}

	return true;
}

bool CLockFreeMgr::GetData(tagQueueData* pData, DWORD dwSize)
{
	if (NULL == pData)    return false;

	tagQueueData* data = (tagQueueData*)POPFront();
	if (NULL == data)    return false;

	pData->byQueueType = data->byQueueType;
	pData->wDBType = data->wDBType;
	pData->dwSize = data->dwSize;
	pData->llConnectID = data->llConnectID;
	pData->pData = data->pData;

	memcpy(&pData->pQueueData,data->pQueueData,data->dwSize);

	SAFE_DELETE_ARRAY(data->pQueueData);
	SAFE_DELETE(data);

	return true;
}
