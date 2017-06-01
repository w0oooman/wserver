#include  "SocketArray.h"

CSocketArray::CSocketArray()
{
	nLimitCount_ = 0;
	nNowMaxCount_ = 0;
	nActiveCount_ = 0;
	ppTCPFixedSocketArray_ = NULL;
	ppTCPSocketArray_ = NULL;
	ppTempTCPSocketArray_ = NULL;
}

CSocketArray::~CSocketArray()
{
	UnInit();
}

bool CSocketArray::Init(UINT nMaxCount)
{
	nLimitCount_ = nMaxCount;

	try
	{
		ppTCPFixedSocketArray_ = new CTCPSocket*[nLimitCount_];
		ppTCPSocketArray_ = new CTCPSocket*[nLimitCount_];
		ppTempTCPSocketArray_ = new CTCPSocket*[nLimitCount_];
		if (NULL == ppTCPSocketArray_ || NULL == ppTCPFixedSocketArray_ || NULL == ppTempTCPSocketArray_)
			return false;

		memset(ppTCPFixedSocketArray_, 0, sizeof(CTCPSocket*)*nLimitCount_);
		memset(ppTCPSocketArray_, 0, sizeof(CTCPSocket*)*nLimitCount_);
		memset(ppTempTCPSocketArray_, 0, sizeof(CTCPSocket*)*nLimitCount_);
	}
	catch (...)
	{
		if (ppTCPFixedSocketArray_) SAFE_DELETE_ARRAY(ppTCPFixedSocketArray_);
		if (ppTCPSocketArray_) SAFE_DELETE_ARRAY(ppTCPSocketArray_);
		if (ppTempTCPSocketArray_) SAFE_DELETE_ARRAY(ppTempTCPSocketArray_);
		Log_ThreadPosition();
		return false;
	}

	return true;
}

void CSocketArray::UnInit()
{
	for (int i = 0; i < nActiveCount_; i++)
	{
		SAFE_DELETE(ppTCPFixedSocketArray_[i]);
	}

	SAFE_DELETE_ARRAY(ppTCPFixedSocketArray_);
	SAFE_DELETE_ARRAY(ppTCPSocketArray_);
	SAFE_DELETE_ARRAY(ppTempTCPSocketArray_);
}

CTCPSocket* CSocketArray::GetFixedItem(UINT index)
{
	if (index >= nNowMaxCount_)  return NULL;

	return ppTCPFixedSocketArray_[index];
}

CTCPSocket* CSocketArray::GetActiveItem(UINT index)
{
	if (index >= nActiveCount_)  return NULL;

	return ppTCPSocketArray_[index];
}

UINT  CSocketArray::GetActiveCount()
{
	return nActiveCount_;
}

CTCPSocket** CSocketArray::GetTempActiveItemPPtrSet()
{
	memcpy(ppTempTCPSocketArray_, ppTCPSocketArray_, sizeof(CTCPSocket*)*nActiveCount_);
	return ppTempTCPSocketArray_;
}

int CSocketArray::GetFixIndex()
{    
	if (nNowMaxCount_ > 0)
		return nNowMaxCount_ - 1;

	return 0;
}

CTCPSocket* CSocketArray::GetItem()
{
	if (nActiveCount_ < nLimitCount_)
	{
		if (nActiveCount_ < nNowMaxCount_)
		{
			return *(ppTCPSocketArray_ + nActiveCount_++);
		}
		else if (nActiveCount_ == nNowMaxCount_)
		{
			CTCPSocket *pTCPSocket = NULL;
			try
			{
				pTCPSocket = new CTCPSocket(nNowMaxCount_);
				if (NULL == pTCPSocket) return NULL;
				*(ppTCPFixedSocketArray_ + nNowMaxCount_) = pTCPSocket;
				*(ppTCPSocketArray_ + nActiveCount_) = pTCPSocket;
				nActiveCount_++;
				nNowMaxCount_++;
				return pTCPSocket;
			}
			catch (...)
			{
				SAFE_DELETE(pTCPSocket);
				return NULL;
			}
		}
		else
		{
			return NULL;
		}
	}

	return NULL;
}

bool CSocketArray::RemoveItem(CTCPSocket* pTCPSocket)
{
	if (NULL == pTCPSocket)return false;

	for (int i = 0; i < nActiveCount_; i++)
	{
		if (pTCPSocket == *(ppTCPSocketArray_ + i))
		{
			CTCPSocket* tmp = pTCPSocket;
			memmove(ppTCPSocketArray_ + i, ppTCPSocketArray_ + i + 1, (nActiveCount_ - i - 1)*sizeof(CTCPSocket*));
			--nActiveCount_;
			*(ppTCPSocketArray_ + nActiveCount_) = tmp;
			break;
		}
	}

	return true;
}
