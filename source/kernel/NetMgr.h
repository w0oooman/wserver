#ifndef __NETMGR_H__
#define __NETMGR_H__
#include  "NetBase.h"
#include  "define.h"
#include  "KernelDefine.h"
#include  "lock.h"
#include  "TimerMgr.h"
#include  "QueueMsg.h"
#include  "IKernelMgr.h"
#include  "KernelMgr.h"

class IKernelMgr;
class CClientCKernelMgr;
class CSocketArray;
class CTCPSocket;

struct OverLappedStruct
{
	OVERLAPPED    overlapped;
	WSABUF        wsabuf;
	unsigned char type;
	unsigned char issendbuff;
	DWORD         roundindex;
};
typedef struct OverLappedStruct NETOVERLAPPED;

typedef struct tagSendData
{
	char *buf;
	DWORD len;
}
tagSData;

class CNetMgr :public CNetBase
{
private:
	CSocketArray    *SocketArray_;
	CLock            SockArrayLock_;   //sock数组锁

	DWORD            dwMaxCount_;      //最大连接
	DWORD            dwListenPort_;    //监听端口
	DWORD            dwThreadNum_;     //收发线程数
	DWORD            dwRoundIndex_;    //循环索引

	HANDLE           hThreadEvent_;    //线程事件
	HANDLE          *phRSThreadHandle_;           //收发线程句柄
	HANDLE           hHeartBeatThreadHandle_;     //心跳线程句柄

	HANDLE           hRSIOCP_;         //接收/发送完全端口
	UINT             hAcceptThread_;   //连接线程句柄
	UINT             hRSThread_;       //收发线程句柄
	IKernelMgr     *pKernelMgr_;       //内核管理类
	bool             bIsRunning_;      //是否退出
	bool             bIsSpecialClient_;//是否为特殊客户机连接

	DWORD            dwTotalRecvLen_;  //接收缓冲大小
	DWORD            dwTotalSendLen_;  //发送缓冲大小

	CLockFreeMgr    *pQueueBatchMsg_;  //群发队列

public:
	CNetMgr();
	~CNetMgr();

private:
	CTCPSocket*       NewSocket();                            //生成一个客户端实例
	bool              DeleteSocket(CTCPSocket* pTCPSocket);   //销毁一个客户端实例
	UINT              GetFixArrayIndex();
	CTCPSocket*       GetFixedItem(UINT index);               //固定项
	CTCPSocket*       GetActiveItem(UINT index);              //活动项
	CSocketArray*     GetSocketArray();
	CLock&            GetSocketArrayLock();

public:
	bool              Init(DWORD dwMaxCount, DWORD dwListenPort,IKernelMgr* pKernelMgr);
	bool              Start();
	void              SetBuffLen(DWORD dwRecvLen, DWORD dwSendLen);  //设置缓冲
	void              CloseSocket(CTCPSocket* pTCPSocket, DWORD dwRoundIndex);
	void              CloseSocket(ULLONG llConnectID);
	bool              OnNetMessage(ULLONG llConnectID, const char* pData, DWORD dwSize);
	DWORD             GetRoundIndex();
	CLockFreeMgr*     GetBatchQueue();
	DWORD             GetMaxCount();
	bool              IsSpecialClient();
	void              SetIsSpecialClient(bool bIsSpecialClient);


	bool SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, DWORD dwRoundIndex);                                      //发送消息，不包含内容
	bool SendDataOld(DWORD dwIndex, void* pAllMsgData, DWORD dwAllMsgLen, DWORD dwRoundIndex);                               //发送消息，不包含内容
	bool SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen, DWORD dwRoundIndex);      //发送消息，包含内容及内容长度
	bool SendData(ULLONG llConnectID, void* pAllMsgData, DWORD dwAllMsgLen);                                                 //发送消息，包含所有信息长度
	bool SendData(void* pAllMsgData, DWORD dwAllMsgLen);                                                                     //消息转发
	bool SendBatchDataOld(DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen);                                    //群发消息
	bool SendBatchData(void* pMsgData, DWORD dwMsgLen);                                                               //群发消息

	static unsigned int __stdcall AcceptThread(void* pData);       //连接线程
	static unsigned int __stdcall RSThread(void* pData);           //发送/接收 线程
	static unsigned int __stdcall HeartBeatThread(void* pData);    //心跳线程
};


#include "CommonList.h"
//客户端管理类
class CClientNetMgr:public CNetBase
{
public:
	CClientNetMgr();
	~CClientNetMgr();
private:
	char     *szRecvBuf_;                      //接收数据buffer
	char     *szSendBuf_;                      //发送数据buffer
	DWORD     dwCheckCode_;
	HANDLE    hEvent_;                         //等待事件
	HANDLE    hRSThreadHandle_;                //收发线程句柄
	HANDLE    hRSIOCP_;
	bool      bIsRunning_;                     //是否退出
	bool      bSending_;                       //是否正发送
	bool      bIsNetCuted_;                    //网络是否断开/未连上


	CClientCKernelMgr *pKernelMgr_;            //内核管理类
	NETOVERLAPPED      SendOverLPData_;        //发送结构
	NETOVERLAPPED      RecvOverLPData_;        //接收结构

	DWORD     dwRecvLen_;                      //当前接收长度
	DWORD     dwSendLen_;                      //当前发送长度
	DWORD     dwTotalRecvLen_;                 //接收缓冲大小
	DWORD     dwTotalSendLen_;                 //发送缓冲大小   

	CLock     SendLock_;                       //发送锁
	CLock     RecvLock_;                       //接收锁
	CLock     NetCutedLock_;                   //操作网络断开标志的锁

	bool      bIsListHaveData_;                //是否发送链表有数据
	CDoubleRingList<tagSData> List_;           //发送buffer满后数据存链表

private:
	bool PrepareRecv();
	bool OnRecvCompleteOld(DWORD dwTransNum);
	bool OnRecvComplete(DWORD dwTransNum);
	bool OnSendComplete(DWORD dwSendCount, NETOVERLAPPED* pNetOL);
	static unsigned int __stdcall RSThread(void *pData);
	bool WSASendData();
	void PushSendList(void* pSendData, DWORD dwSendLen);

public:
	virtual void CloseSocket();
public:
	bool   ReConnect();                          //重连
	inline HANDLE GetEvent();
	IKernelMgr *GetKernelMgr();
	HANDLE GetIOCPHandle();

public:
	bool Init(LPCTSTR lpIP, USHORT usPort, CClientCKernelMgr *pKernelMgr);
	bool Start();
	void ResetData();
	bool SendDataOld(DWORD dwMainID, DWORD dwSubID);                                        //发送消息，不包含内容
	bool SendDataOld(DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen);        //发送消息，包含内容及内容长度
	bool SendDataOld(void* pAllMsgData, DWORD dwAllMsgLen);                                 //发送消息，包含所有信息长度
	bool SendData(void* pAllMsgData, DWORD dwAllMsgLen);                                    //发送消息，包含所有信息长度
	bool CheckSendData();
	void SetBuffLen(DWORD dwRecvLen, DWORD dwSendLen);
	void SetNetCutedStatus(bool bIsNetCuted);
	bool IsNetCuted();  //网络是否断开

};


#endif