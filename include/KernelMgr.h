#ifndef __KERNELMGR_H__
#define __KERNELMGR_H__
#include  <memory>
#include  "IKernelMgr.h"
#include  "TimerMgr.h"
#include  "NetError.h"

//index和roundindex的合体与拆分
#define   CONNECTID_MIX(index, RoundIndex)             ((ULLONG)(RoundIndex) << 32 | (ULLONG)(index))
#define   INDEX_SPLIT(llConnectID)                     (DWORD)((llConnectID) & 0xFFFFFFFF)
#define   ROUNDINDEX_SPLIT(llConnectID)                (DWORD)((llConnectID) >> 32)
#define   CONNECTID_MIXEX(pNetHead)                    CONNECTID_MIX(((CNetMsgHead*)(pNetHead))->reserve1_, ((CNetMsgHead*)(pNetHead))->reserve2_)
#define   RESERVE_SETCONNECTID(pNetHead, llConnectID)  ((CNetMsgHead*)(pNetHead))->reserve1_ = INDEX_SPLIT(llConnectID);((CNetMsgHead*)(pNetHead))->reserve2_ = ROUNDINDEX_SPLIT(llConnectID);


class CClientNetMgr;
class CQueueMsg;
class CLockFreeQueue;
class CTimerMgr;

class KERNEL_ENGINE_CLASS MKernelMgr :public IKernelMgr
{
protected:
	bool           bIsRunning_;            //是否退出
	CLockFreeMgr  *pQueueNormalMsg_;       //读取队列
	CTimerMgr     *pTimerMgr_;             //定时器管理
	HANDLE         hEvent_;                //等待事件
	     
public:
	MKernelMgr();
	virtual ~MKernelMgr();
private:
	virtual bool PrepareCloseConnect(ULLONG llConnectID){ return true; }
public:
	virtual bool Init(DWORD dwMaxCount, DWORD dwListenPort){ return true; }
	virtual bool Start(){ return true; }
	virtual CNetMgr* GetNetMgr(){ return NULL; }
	virtual bool SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, DWORD dwRoundIndex){ return true; }
	virtual bool SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, const void* pMsgData, DWORD dwMsgLen, DWORD dwRoundIndex){ return true; }
	virtual bool SendDataOld(DWORD dwIndex, const void* pAllMsgData, DWORD dwAllMsgLen, DWORD dwRoundIndex){ return true; }
	virtual bool SendData(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen){ return true; }
	virtual bool CloseConnect(ULLONG llConnectID){ return true; }
	virtual bool OnSocketRead(ULLONG llConnectID, const char* pData, DWORD dwSize){ return true; }
	virtual void OnCloseConnect(ULLONG llConnectID){ }
	virtual bool OnNormalMsgHandleOld(ULLONG llConnectID, NetMsgHead* pMsgHead, const void* pData){ return true; }
	virtual bool OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize){ return true; }
	virtual bool OnDBMsghandle(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType){ return true; }
public:
	virtual bool GetIsRunning();
	virtual CLockFreeMgr *GetNormalQueue();

	//timer 模块
public:
	//定时器线程
	static unsigned int __stdcall TimerThread(void *pData);

	//定时器相应函数,类似于WINDOWS的OnTimer
	//若AddEvent中func！=NULL，则会调用func函数，传入参数为data
	virtual void OnEvent(int timerID, void *data);

	//加入定时器事件,类似于WINDOWS的SetTimer
	//timerID: 定时器ID
	//seconds: 定时时间
	//fun:定时回调函数,若fun==NULL,则在OnEvent中响应
	//data:携带的数据,若数据是整数5,可以类似"(int*)(5)"这样传给data,若传的是一个指针,则需要程序员自己管理此指针,因此,传入临时指针是不行的!!
	//type:循环定时器或者只执行一次的定时器
	//timerID 和 func不能同时为0！！timerID为0则会自动分配一个ID
	//返回值：timerID或自动分配的ID,返回值<=0表示添加事件失败.
	int AddEvent(int timerID, int interval, TimerCallBackFunc func = NULL, void *data = NULL, int type = CTimerMgr::CIRCLE);

	//移除定时器事件,类似于WINDOWS的KillTimer
	bool RemoveEvent(int timerID);

	//移除所有事件
	void RemoveAllEvent();

	//是否存在定时器ID
	virtual bool IsExistTimerID(int timerID);

	//删除用户数据
	virtual void DeleteTimerData(const void *data);

	//处理定时器事件
	virtual void HandleTimerEvent(IKernelMgr* pKernelMgr, void* pTimeData);

};

class KERNEL_ENGINE_CLASS CKernelMgr :public MKernelMgr
{
private:
	HANDLE         hNormalThreadHandle_;     //普通线程事件
	HANDLE         hBatchThreadHandle_;      //群发线程事件
	HANDLE         hDBThreadHandle_;         //DB线程事件
	HANDLE         hTimerThreadHandle_;      //定时器线程事件

	HANDLE         hQueueNormalIOCP_;        //队列完成端口
	HANDLE         hQueueDBIOCP_;            //数据库端口
	HANDLE         hQueueTimerIOCP_;         //定时器端口

	CLockFreeMgr  *pQueueDBMsg_;             //数据库队列
	
	CNetMgr       *pNetMgr_;                 //网络管理
	
	//“单用shared_ptr 或 结合weak_ptr” 来处理 “类实例已经释放，但类中线程还在运行，且可能访问类中资源时内存访问出错的问题” 但效率不高，所以还是采用事件来处理吧
	//shared_ptr <CNetMgr>   pNetMgr_;         //网络管理 

public:
	CKernelMgr();
	virtual ~CKernelMgr();
public:
	virtual bool Init(DWORD dwMaxCount, DWORD dwListenPort);
	virtual bool Start();

public:
	virtual CNetMgr* GetNetMgr();
	//发送消息，不包含内容
	virtual bool SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, DWORD dwRoundIndex);
	//发送消息，包含内容及内容长度
	virtual bool SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, const void* pMsgData, DWORD dwMsgLen, DWORD dwRoundIndex);
	//发送消息，包含所有信息长度
	virtual bool SendDataOld(DWORD dwIndex, const void* pAllMsgData, DWORD dwAllMsgLen, DWORD dwRoundIndex);
	//发送消息，包含所有信息长度
	virtual bool SendData(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen);

	//发送消息，包含所有信息长度, 用于服务机与单连接客户机通信
	bool SendData(CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen);

	//群发消息
	virtual bool SendBatchDataOld(DWORD dwMainID, DWORD dwSubID, const void* pMsgData, DWORD dwMsgLen/*, bool bAddQueue = 0*/);
	virtual bool SendBatchDataOld(const void* pMsgData, DWORD dwMsgLen/*, bool bAddQueue = 0*/);
	virtual bool SendBatchData(const void* pMsgData, DWORD dwMsgLen/*, bool bAddQueue = 0*/);
	virtual bool HandleDBData(ULLONG llConnectID, void* pData, DWORD dwSize, WORD wDBType);

private:
	//关闭socket
	virtual bool  PrepareCloseConnect(ULLONG llConnectID);

public:
	//数据读取
	virtual bool OnSocketRead(ULLONG llConnectID, const char* pData, DWORD dwSize);
	//关闭连接
	virtual bool CloseConnect(ULLONG llConnectID);
	//释放玩家数据
	virtual void  OnCloseConnect(ULLONG llConnectID);
public:
	//队列线程
	static unsigned int __stdcall QueueThread(void *pData);
	//设置缓冲
	void  SetBuffLen(DWORD dwRecvLen, DWORD dwSendLen);
	DWORD GetMaxCount();
	void  SetIsSpecialClient(bool bIsSpecialClient);
	void  SetMsgConnectID(CNetMsgHead *pDestMsg, CNetMsgHead *pSourceMsg);
};


class KERNEL_ENGINE_CLASS CClientCKernelMgr:public MKernelMgr
{
public:
	CClientCKernelMgr();
	virtual ~CClientCKernelMgr();
private:
	CClientNetMgr*       pNetMgr_;               //网络管理
	HANDLE               hTimerThreadHandle_;    //定时器线程句柄

public:
	virtual bool OnNetMessageOld(NetMsgHead *pNetMsgHead, char* pMsgData, DWORD dwMsgLen);
	virtual bool OnNetMessage(const void* pData, DWORD dwSize);
public:
	//定时发送心跳
	static void SendHeartBeatCallBack(void *data);
	//重连定时
	static void ReConnectCallBack(void *data);
public:
	bool Init(LPCTSTR lpIP, USHORT usPort);
	bool Start();
	CClientNetMgr* GetNetMgrPtr();
	void CloseSocket();
public:
	bool SendDataOld(DWORD dwMainID, DWORD dwSubID);                                        //发送消息，不包含内容
	bool SendDataOld(DWORD dwMainID, DWORD dwSubID, const void* pMsgData, DWORD dwMsgLen);        //发送消息，包含内容及内容长度
	bool SendDataOld(const void* pAllMsgData, DWORD dwAllMsgLen);                                 //发送消息，包含所有信息长度
	bool SendData(CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen);                             //发送消息，包含所有信息长度
};

#endif