#ifndef __TCP_SOCKET__H__
#define __TCP_SOCKET__H__

#include  "define.h"
#include  "NetMgr.h"
#include  "lock.h"

//不放在define.h，否则稍有改动会重新编译大量文件

//操作类型
#define   SOCKET_RCV        1
#define   SOCKET_SND        2

//ip地址最大长度
#define   IPADDRESS_MAX_LENGTH   (32)

//索引不合法定义
#define   TCPSOCKET_INVALID_INDEX  (~0)

//发送重叠限制
#define   SEND_OVERLAPPED_LIMIT  (10)

class CNetMgr;
class CTCPSocket
{
	friend /*class*/ CNetMgr;

private:
	bool            bRecving_;                      //是否接收完成
	bool            bSending_;                      //是否发送完成
	SOCKET          socket_;                        //客户端socket
	CNetMgr        *pNetMgr_;                       //网络管理
	DWORD           dwIndex_;                       //客户端索引
	DWORD           dwRoundIndex_;                  //循环索引
	sockaddr_in     addr_;                          //客户端地址
	char            ipAddr_[IPADDRESS_MAX_LENGTH];  //客户端IP
	BYTE            byLoseHeartBeatTimes_;          //未收到心跳次数

	NETOVERLAPPED   SendOverLPData_;                //发送结构
	NETOVERLAPPED   RecvOverLPData_;                //接收结构
	char           *sendBuf_;                       //发送缓冲
	char           *recvBuf_;                       //接收缓冲
	DWORD           dwSendLen_;                     //当前发送长度
	DWORD           dwRecvLen_;                     //当前接收长度
	CLock           SingleLock_;                    //锁

#ifdef IS_USE_CIRCLE_BUFFER
	char           *recvTmpBuf_;                    //环形缓冲临时buf
	DWORD           m_dwRecvBegin;                  //环形缓冲区起始
	DWORD           m_dwRecvEnd;                    //环形缓冲区结束
#endif

	DWORD           dwTotalRecvLen_;                //接收缓冲大小
	DWORD           dwTotalSendLen_;                //发送缓冲大小  

	bool            bIsListHaveData_;               //是否发送链表有数据
	CDoubleRingList<tagSData> List_;                //发送buffer满后数据存链表

public:
	CTCPSocket(DWORD dwIndex);
	virtual ~CTCPSocket();

private:
	bool IsValidRoundIndex(DWORD dwRoundIndex)const;
	void PushSendList(void* pSendData, DWORD dwSendLen);
	void SetIndex(DWORD dwIndex);

public:
	bool IsCanClose();
	void ResetData();
	void Attach(SOCKET soc, sockaddr_in &addr, DWORD dwRoundIndex);
	bool RecvData();
	bool SendDataOld(DWORD dwMainID, DWORD dwSubID, DWORD dwRoundIndex);                                    //发送消息，不包含内容
	bool SendDataOld(DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen, DWORD dwRoundIndex);    //发送消息，包含内容及内容长度
	bool SendDataOld(void* pAllMsgData, DWORD dwAllMsgLen, DWORD dwRoundIndex);                             //发送消息，包含所有信息长度
	bool SendData(DWORD dwRoundIndex, void* pAllMsgData, DWORD dwAllMsgLen);                                //发送消息，包含所有信息长度
	bool SendData(void* pAllMsgData, DWORD dwAllMsgLen);                                                    //消息转发，包含所有信息长度

	bool WSASendData();
	bool OnRecvComplete(DWORD dwRoundIndex);
#ifdef IS_USE_CIRCLE_BUFFER
	bool OnRecvCompleteCircle(DWORD dwRoundIndex);
#endif
	bool OnSendComplete(DWORD dwSendCount, NETOVERLAPPED* pNetOL);
	bool CloseSocket(DWORD dwRoundIndex);
	bool IsValidSocket();

	void     SetNetMgr(CNetMgr* pNetMgr);
	DWORD    GetIndex();
	DWORD    GetRoundIndex();
	ULLONG   GetConnectID();
	CNetMgr* GetNetMgr();
	inline   SOCKET GetSocket();
	BYTE     GetHeartBeatTimes();
	void     AddHeartBeatTimes();
	char*    GetIpAddress() const;
	CLock*   GetLock() const;
	void     SetRecvStatus(bool bRecving);
	void     SetSendStatus(bool bSending);
};

#endif
