#include <assert.h>
#include "TCPSocket.h"

#define  IS_VALID_ROUNDINDEX(dwRoundIndex) \
	if (0 == (dwRoundIndex) || (dwRoundIndex) != dwRoundIndex_) {\
        return false; \
	}


CTCPSocket::CTCPSocket(DWORD dwIndex)
{
	dwIndex_ = dwIndex;//TCPSOCKET_INVALID_INDEX;
	pNetMgr_ = NULL;
	sendBuf_ = NULL;
	recvBuf_ = NULL;
	socket_ = INVALID_SOCKET;
	bSending_ = false;
	bRecving_ = false;

	byLoseHeartBeatTimes_ = 0;
	dwTotalRecvLen_ = RCV_SIZE;
	dwTotalSendLen_ = SND_SIZE;
	bIsListHaveData_ = false;

#ifdef IS_USE_CIRCLE_BUFFER
	recvTmpBuf_ = NULL;
#endif
}

CTCPSocket::~CTCPSocket()
{
	dwIndex_ = TCPSOCKET_INVALID_INDEX;
	pNetMgr_ = NULL;
	bIsListHaveData_ = false;
	delete []sendBuf_;
	delete []recvBuf_;

#ifdef IS_USE_CIRCLE_BUFFER
	delete[]recvTmpBuf_;
#endif
}

bool CTCPSocket::IsCanClose()
{
	if (socket_ != INVALID_SOCKET)
	{
#ifdef _DEBUG
		char buf[100] = { 0 };
		sprintf_s(buf, "close socket:%d???bRecving_=%d,bSending_=%d\n", socket_, bRecving_, bSending_);
		OutputDebugString(buf);
#endif
		::closesocket(socket_);
	}

	if (false == bRecving_ && false == bSending_)
	{
		return true;
	}
	return false;
}

void CTCPSocket::ResetData()
{
#ifdef _DEBUG
	char buf[100] = { 0 };
	memset(buf, 0, sizeof(buf));
	sprintf_s(buf, "close socket:%d\n", socket_);
	OutputDebugString(buf);
#endif

	socket_ = INVALID_SOCKET;

	memset(&addr_, 0, sizeof(addr_));
	memset(&SendOverLPData_, 0, sizeof(SendOverLPData_));
	memset(&RecvOverLPData_, 0, sizeof(RecvOverLPData_));

	SendOverLPData_.type = SOCKET_SND;
	SendOverLPData_.wsabuf.buf = sendBuf_;
	RecvOverLPData_.type = SOCKET_RCV;
	RecvOverLPData_.wsabuf.buf = recvBuf_;

	dwSendLen_ = 0;
	dwRecvLen_ = 0;
	dwRoundIndex_ = 0;
	byLoseHeartBeatTimes_ = 0;

	bIsListHaveData_ = false;
	List_.Clear();

#ifdef IS_USE_CIRCLE_BUFFER
	m_dwRecvBegin = 0;
	m_dwRecvEnd = 0;
#endif
}

bool CTCPSocket::IsValidRoundIndex(DWORD dwRoundIndex)const
{
	if (0 == dwRoundIndex || dwRoundIndex != dwRoundIndex_)
	{
		//Log(LOG_THREAD, "..........no equal  %d,%d,%d\n", dwRoundIndex, dwRoundIndex_, socket_);//whb
		return false;
	}
		
	return true;
}

void CTCPSocket::PushSendList(void* pSendData, DWORD dwSendLen)
{
	if (dwSendLen > MAX_SEND_LIMIT)
	{
		Log(LOG_THREAD, "server:send data falied:too long! limit=%d,sendlen=%d", MAX_SEND_LIMIT, dwSendLen);
		return;
	}

	tagSData tagSendData;
	tagSendData.buf = new char[dwSendLen];
	tagSendData.len = dwSendLen;
	memcpy(tagSendData.buf, (char*)pSendData, dwSendLen);
	List_.PUSHBack(tagSendData);
}

void CTCPSocket::SetIndex(DWORD dwIndex)
{
	dwIndex_ = dwIndex;
}

bool CTCPSocket::CloseSocket(DWORD dwRoundIndex)
{
	CLockMgr SLockMgr(&SingleLock_);

	IS_VALID_ROUNDINDEX(dwRoundIndex);

	return IsCanClose();
}

void CTCPSocket::Attach(SOCKET soc, sockaddr_in &addr, DWORD dwRoundIndex)
{
	CLockMgr SLockMgr(&SingleLock_);
	socket_ = soc;
	addr_ = addr;
	memcpy(ipAddr_,inet_ntoa(addr_.sin_addr),sizeof(ipAddr_));
	dwRoundIndex_ = dwRoundIndex;
}

bool CTCPSocket::RecvData()
{
	CLockMgr LockMgr(&SingleLock_);

	bRecving_ = true;

	DWORD dwRecvBytes = 0, dwFlags = 0;
	//RecvOverLPData_.wsabuf.buf=recvBuf_+dwRecvLen_;  //wsabuf.len=0时，此句其实没什么用
	//RecvOverLPData_.wsabuf.buf=recvBuf_+m_dwRecvBegin;
	RecvOverLPData_.wsabuf.len = 0; //设为0，有数据时用recv接收,节约非分页内存!  
	RecvOverLPData_.roundindex = dwRoundIndex_;
	if ((WSARecv(socket_, &RecvOverLPData_.wsabuf, 1, &dwRecvBytes, &dwFlags, &RecvOverLPData_.overlapped, NULL) == SOCKET_ERROR)
		&& WSAGetLastError() != WSA_IO_PENDING)
	{

#ifdef _DEBUG
		char buf[50];
		memset(buf, 0, sizeof(buf));
		sprintf_s(buf, "WSARecv error,will close socket:%d\n", socket_);
		OutputDebugString(buf);
#endif
		bRecving_ = false;
		pNetMgr_->CloseSocket(this, dwRoundIndex_);
		return false;
	}

	return true;
}


bool CTCPSocket::SendDataOld(DWORD dwMainID, DWORD dwSubID, DWORD dwRoundIndex)
{
	CLockMgr LockMgr(&SingleLock_);       

	IS_VALID_ROUNDINDEX(dwRoundIndex);

	if (sizeof(NetMsgHead) + dwSendLen_ > dwTotalSendLen_)       return false;

	NetMsgHead *pMsgHead = (NetMsgHead*)(sendBuf_ + dwSendLen_);
	pMsgHead->dwSize = sizeof(NetMsgHead);
	pMsgHead->dwMainID = dwMainID;
	pMsgHead->dwSubID = dwSubID;
	pMsgHead->dwReserve = 0;

	dwSendLen_ += sizeof(NetMsgHead);

	return WSASendData();
}

bool CTCPSocket::SendDataOld(DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen, DWORD dwRoundIndex)
{
	CLockMgr LockMgr(&SingleLock_);       

	IS_VALID_ROUNDINDEX(dwRoundIndex);

	if (NULL == pMsgData) return false;

	DWORD dwLen = sizeof(NetMsgHead) + dwMsgLen;
	if (/*dwMsgLen > MAX_MESSAGE_LENGTH || dwLen > MAX_MESSAGE_LENGTH||*/ dwLen + dwSendLen_ > dwTotalSendLen_)
	{ 
		Log(LOG_THREAD, "send buff full.AllLen=%d,CurLen=%d,MsgLen=%d,", dwTotalSendLen_, dwSendLen_, dwLen);
		WSASendData();
		return false;
	}

	NetMsgHead *pMsgHead = (NetMsgHead*)(sendBuf_ + dwSendLen_);
	pMsgHead->dwSize = sizeof(NetMsgHead) + dwMsgLen;
	pMsgHead->dwMainID = dwMainID;
	pMsgHead->dwSubID = dwSubID;
	pMsgHead->dwReserve = 0;

	memcpy(sendBuf_ + dwSendLen_ + sizeof(NetMsgHead), (char*)pMsgData, dwMsgLen);
	dwSendLen_ += pMsgHead->dwSize;

	return WSASendData();
}

bool CTCPSocket::SendDataOld(void* pAllMsgData, DWORD dwAllMsgLen, DWORD dwRoundIndex)
{
	CLockMgr LockMgr(&SingleLock_);      

	IS_VALID_ROUNDINDEX(dwRoundIndex);

	if (NULL == pAllMsgData)      return false;

	if (/*dwAllMsgLen < sizeof(NetMsgHead) || dwAllMsgLen > MAX_MESSAGE_LENGTH ||*/ dwAllMsgLen > dwTotalSendLen_ - dwSendLen_)
	{
		Log(LOG_THREAD, "send buff full.AllLen=%d,CurLen=%d,MsgLen=%d,", dwTotalSendLen_, dwSendLen_, dwAllMsgLen);
		WSASendData();
		return false;
	}
	memcpy(sendBuf_ + dwSendLen_, (char*)pAllMsgData, dwAllMsgLen);
	dwSendLen_ += dwAllMsgLen;

	return WSASendData();
}

bool CTCPSocket::SendData(DWORD dwRoundIndex, void* pAllMsgData, DWORD dwAllMsgLen)
{
	CLockMgr LockMgr(&SingleLock_);

	IS_VALID_ROUNDINDEX(dwRoundIndex);

	if (NULL == pAllMsgData)      return false;

	if (/*dwAllMsgLen < sizeof(CNetMsgHead) || dwAllMsgLen > MAX_MESSAGE_LENGTH ||*/ dwAllMsgLen > dwTotalSendLen_ - dwSendLen_)
	{
		if (!bIsListHaveData_)
		{
			Log(LOG_THREAD, "send buff full.AllLen=%d,CurLen=%d,MsgLen=%d,", dwTotalSendLen_, dwSendLen_, dwAllMsgLen);
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

bool CTCPSocket::SendData(void* pAllMsgData, DWORD dwAllMsgLen)
{
	CLockMgr LockMgr(&SingleLock_);

	if (NULL == pAllMsgData)      return false;

	if (/*dwAllMsgLen < sizeof(CNetMsgHead) || dwAllMsgLen > MAX_MESSAGE_LENGTH ||*/ dwAllMsgLen > dwTotalSendLen_ - dwSendLen_)
	{
		if (!bIsListHaveData_)
		{
			Log(LOG_THREAD, "send buff full.AllLen=%d,CurLen=%d,MsgLen=%d,", dwTotalSendLen_, dwSendLen_, dwAllMsgLen);
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

bool CTCPSocket::WSASendData()
{
	CLockMgr LockMgr(&SingleLock_);

	if (false == bSending_)
	{
		if (dwSendLen_ > 0)
		{
			SendOverLPData_.wsabuf.buf = sendBuf_;
			SendOverLPData_.wsabuf.len = dwSendLen_;
			SendOverLPData_.roundindex = dwRoundIndex_;
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
				SendOverLPData_.roundindex = dwRoundIndex_;
				SendOverLPData_.issendbuff = 0;
				bSending_ = true;
				if (List_.GetCount() == 0) bIsListHaveData_ = false;
			}
			else
			{
				bIsListHaveData_ = false;
				Log(LOG_THREAD, "【 error 】: server send list error.count=%d", List_.GetCount());
				return false;
			}
		}

		DWORD dwSendBytes = 0;
		if (bSending_ &&
			WSASend(socket_, &SendOverLPData_.wsabuf, 1, &dwSendBytes, 0, &SendOverLPData_.overlapped, NULL) == SOCKET_ERROR
			&&WSAGetLastError() != WSA_IO_PENDING)
		{
			bSending_ = false;

			Log(LOG_THREAD, "WSASendData close.\n");//whb

			pNetMgr_->CloseSocket(this,dwRoundIndex_);

			return false;
		}
	}

	return true;
}

bool CTCPSocket::OnRecvComplete(DWORD dwRoundIndex)
{
	CLockMgr LockMgr(&SingleLock_);

	IS_VALID_ROUNDINDEX(dwRoundIndex);

	assert(true == bRecving_);
	bRecving_ = false;

	int nCount = ::recv(socket_, recvBuf_ + dwRecvLen_, dwTotalRecvLen_ - dwRecvLen_, 0);

	if (nCount <= 0)
	{
		pNetMgr_->CloseSocket(this, dwRoundIndex_);
		Log(LOG_THREAD, "OnRecvComplete <=0.ID=%d", WSAGetLastError());//whb
		return false;
	}

	byLoseHeartBeatTimes_ = 0;
	dwRecvLen_ += nCount;

	//方式1 处理一次消息就memmove
	while (dwRecvLen_ >= sizeof(CNetMsgHead))
	{
		CNetMsgHead *pNetMsgHead = (CNetMsgHead*)recvBuf_;
		DWORD dwSize = pNetMsgHead->size_;
		if (dwRecvLen_ < dwSize) break;

		if (dwSize < sizeof(CNetMsgHead) || dwSize > MAX_MESSAGE_LENGTH)    { pNetMgr_->CloseSocket(this, dwRoundIndex_); return false; }

		//if (((NetMsgHead*)recvBuf_)->dwReserve != socket_)               { pNetMgr_->CloseSocket(this, dwRoundIndex_); return false; }

		if (((CNetMsgHead*)recvBuf_)->protocol_ != CNetMsgHead::NETMSG_HEART_BEAT)
		{
			if (!pNetMgr_->OnNetMessage(CONNECTID_MIX(dwIndex_, dwRoundIndex_), recvBuf_, dwSize)) { pNetMgr_->CloseSocket(this, dwRoundIndex_); return false; }
		}

		dwRecvLen_ -= dwSize;
		memmove(recvBuf_, recvBuf_ + dwSize, dwRecvLen_);
	}

	//方式2 处理完了再memmove
	//DWORD dwSum = 0; bool bReturn = true;
	//while (dwRecvLen_ >= sizeof(CNetMsgHead))
	//{
	//	CNetMsgHead *pNetMsgHead = (CNetMsgHead*)((char*)recvBuf_ + dwSum);
	//	WORD dwSize = pNetMsgHead->size_;
	//	if (dwRecvLen_ < dwSize) break;

	//	if (dwSize < sizeof(CNetMsgHead) || dwSize > MAX_MESSAGE_LENGTH)  { bReturn = false; break; }

	//	//if (pNetMsgHead->dwReserve != socket_) { bReturn = false; break; }

	//	if (((CNetMsgHead*)recvBuf_)->protocol_ != CNetMsgHead::NETMSG_HEART_BEAT)
	//	{
	//		if (!pNetMgr_->OnNetMessage(CONNECTID_MIX(dwIndex_, dwRoundIndex_), recvBuf_, dwSize)) { bReturn = false; break; }
	//	}

	//	dwRecvLen_ -= dwSize;
	//	dwSum += dwSize;
	//}

	//memmove(recvBuf_, recvBuf_ + dwSum, dwRecvLen_);

	//if (!bReturn)
	//{
	//	pNetMgr_->CloseSocket(this, dwRoundIndex_);
	//	return false;
	//}

	return RecvData();
}

//环形缓冲区(后来发现无实际意义，在单个线程这样操作效率只降不升!),后面考虑做的环形缓冲区应该是这样的:
//OnSendComplete 和 SendData函数会频繁出现锁竞争的情况，考虑使用环形缓冲放弃锁从而提高效率!!!  whb
#ifdef IS_USE_CIRCLE_BUFFER
bool CTCPSocket::OnRecvCompleteCircle(DWORD dwRoundIndex)
{
	CLockMgr LockMgr(&SingleLock_);
	IS_VALID_ROUNDINDEX(dwRoundIndex);

	assert(true == bRecving_);
	bRecving_ = false;

	try
	{   //dwTotalRecvLen_ 为2的次方才行
		UINT Len = min(dwTotalRecvLen_, dwTotalRecvLen_ - m_dwRecvBegin + m_dwRecvEnd);   /* 剩余空间长度 */
		UINT L = min(Len, dwTotalRecvLen_ - (m_dwRecvBegin & (dwTotalRecvLen_ - 1)));     /* 环形缓冲剩余右边长度 */
		int nCount = ::recv(socket_, recvBuf_ + (m_dwRecvBegin & (dwTotalRecvLen_ - 1)), L, 0); /* 右边填充 */
		int nLeft = ::recv(socket_, recvBuf_, Len - L, 0); /* 左边填充 */
		if (nLeft > 0)
			nCount += nLeft;

		if (nCount > 0)
		{
			m_dwRecvBegin += nCount;

			Len = min(dwTotalRecvLen_, m_dwRecvBegin - m_dwRecvEnd); /* 数据总长度 */
			if (Len >= dwTotalRecvLen_)   throw "buffer full!";
			L = min(Len, dwTotalRecvLen_ - (m_dwRecvEnd & (dwTotalRecvLen_ - 1))); /* 环形缓冲右边数据长度 */

			if (Len >= sizeof(CNetMsgHead))
			{
				//明天检查buf数组是否溢出 whb
				//消息只复制一次,而非环形缓冲则可能重复复制
				char *pBuf = recvTmpBuf_;
				memcpy(pBuf, recvBuf_ + (m_dwRecvEnd & (dwTotalRecvLen_ - 1)), L);
				memcpy(pBuf + L, recvBuf_, Len - L);
				DWORD dwPos = 0;
				DWORD dwSize = ((CNetMsgHead*)(pBuf + dwPos))->size_;

				while (Len >= sizeof(CNetMsgHead) && Len >= dwSize)
				{
					if (dwSize > MAX_MESSAGE_LENGTH)                                           throw "非法数据包!";

					//if (((CNetMsgHead*)(buf + dwPos))->dwReserve != socket_)                              throw "密钥校验失败!";

					if (!pNetMgr_->OnNetMessage(CONNECTID_MIX(dwIndex_, dwRoundIndex_), recvBuf_, dwSize))     throw "数据处理失败!";

					//whb test
					if (Len < dwSize)
					{
						MessageBox(NULL, TEXT("Len<dwSize"), TEXT("error"), MB_OK);
					}
					if (dwPos > dwTotalRecvLen_)
					{
						MessageBox(NULL, TEXT("dwPos>dwTotalRecvLen_"), TEXT("error"), MB_OK);
					}

					Len -= dwSize;
					dwPos += dwSize;
					m_dwRecvEnd += dwSize;
					dwSize = ((CNetMsgHead*)(pBuf + dwPos))->size_;
				}
			}

			return RecvData();
		}
		else// 1、SOCKET_ERROR==nCount:socket关闭;2、0==nCount:缓冲区(recvBuf_)满
		{
			pNetMgr_->CloseSocket(this, dwRoundIndex_);
			return false;
		}
	}
	catch (...)
	{
		pNetMgr_->CloseSocket(this, dwRoundIndex_);
		return false;
	}

	return true;
}
#endif

bool CTCPSocket::OnSendComplete(DWORD dwSendCount, NETOVERLAPPED* pNetOL)
{
	CLockMgr LockMgr(&SingleLock_);
	bSending_ = false;

	if (0 == dwSendCount)
	{
		pNetMgr_->CloseSocket(this, dwRoundIndex_);
		return false;
	}

	//whb test
	static DWORD dwTime = 0;
	static int i = 0; i++;
	if (1 == i)
	{
		dwTime = GetTickCount();
	}
	if (0 == i%1000)
	{
		DWORD tt = GetTickCount() - dwTime;
		Log("send complete i = %d,time:  %d分%d秒%d毫秒\n",i, tt / 1000 / 60, tt / 1000 % 60, tt % 1000);
	}

	/* buff */
	if (pNetOL->issendbuff)
	{
		if (dwSendCount <= dwSendLen_)
		{
			dwSendLen_ -= dwSendCount;
			memmove(sendBuf_, sendBuf_ + dwSendCount, dwSendLen_);
			return WSASendData();
		}
	}
	/* list */
	else
	{
		delete pNetOL->wsabuf.buf;
		return WSASendData();
	}

	return true;
}

bool CTCPSocket::IsValidSocket()
{
	return (socket_ == INVALID_SOCKET ? false : true);
};

void CTCPSocket::SetNetMgr(CNetMgr* pNetMgr)
{
	pNetMgr_ = pNetMgr;
	if (pNetMgr->IsSpecialClient())
	{
		dwTotalSendLen_ = SND_SIZE_SPECIAL;
		dwTotalRecvLen_ = RCV_SIZE_SPECIAL;
	}
	if (sendBuf_) delete sendBuf_;
	if (recvBuf_) delete recvBuf_;
	sendBuf_ = new char[dwTotalSendLen_];
	recvBuf_ = new char[dwTotalRecvLen_];

#ifdef IS_USE_CIRCLE_BUFFER
	if (recvTmpBuf_) delete recvTmpBuf_;
	recvTmpBuf_ = new char[dwTotalRecvLen_];
#endif

	ResetData();
}

DWORD CTCPSocket::GetIndex()
{
	return dwIndex_;
}

CNetMgr* CTCPSocket::GetNetMgr()
{
	return pNetMgr_;
}

SOCKET CTCPSocket::GetSocket()
{
	//CLockMgr SLockMgr(&SingleLock_);
	return socket_;
}

DWORD CTCPSocket::GetRoundIndex()
{
	//CLockMgr SLockMgr(&SingleLock_);
	return dwRoundIndex_;
}

ULLONG CTCPSocket::GetConnectID()
{
	return CONNECTID_MIX(dwIndex_, dwRoundIndex_);
}

BYTE CTCPSocket::GetHeartBeatTimes()
{
	CLockMgr SLockMgr(&SingleLock_);
	return byLoseHeartBeatTimes_;
}

void CTCPSocket::AddHeartBeatTimes()
{
	CLockMgr SLockMgr(&SingleLock_);
	byLoseHeartBeatTimes_++;
}

char* CTCPSocket::GetIpAddress() const
{
	return (char*)ipAddr_;
}

CLock* CTCPSocket::GetLock() const
{
	return (CLock*)&SingleLock_;
}

void CTCPSocket::SetRecvStatus(bool bRecving)
{
	bRecving_ = bRecving;
}

void CTCPSocket::SetSendStatus(bool bSending)
{
	bSending_ = bSending;
}