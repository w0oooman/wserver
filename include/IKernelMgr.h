#ifndef __IKERNELMGR__H__
#define __IKERNELMGR__H__
#include "define.h"

class CNetMgr;
class CLockFreeMgr;

class IKernelMgr
{
	friend CNetMgr;
public:
	virtual bool Init(DWORD dwMaxCount, DWORD dwListenPort) = 0;
	virtual bool Start() = 0;

public:
	virtual CNetMgr* GetNetMgr() = 0;
	virtual bool GetIsRunning() = 0;
	virtual CLockFreeMgr *GetNormalQueue() = 0;
	//发送消息，不包含内容
	virtual bool SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID, DWORD dwRoundIndex) = 0;
	//发送消息，包含内容及内容长度
	virtual bool SendDataOld(DWORD dwIndex, DWORD dwMainID, DWORD dwSubID,const void* pMsgData, DWORD dwMsgLen, DWORD dwRoundIndex) = 0;
	//发送消息，包含所有信息长度
	virtual bool SendDataOld(DWORD dwIndex, const void* pAllMsgData, DWORD dwAllMsgLen, DWORD dwRoundIndex) = 0;
	//发送消息，包含所有信息长度
	virtual bool SendData(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen) = 0;
	virtual bool CloseConnect(ULLONG llConnectID) = 0;
	virtual void OnEvent(int timerID, void *data) = 0;
	virtual bool RemoveEvent(int timerID) = 0;
	//是否存在定时器ID
	virtual bool IsExistTimerID(int timerID) = 0;
	//删除用户数据
	virtual void DeleteTimerData(const void *data) = 0;
	//处理定时器事件
	virtual void HandleTimerEvent(IKernelMgr* pKernelMgr, void* pTimeData) = 0;
private:
	//关闭socket
	virtual bool  PrepareCloseConnect(ULLONG llConnectID) = 0;
public:
	//数据读取
	virtual bool  OnSocketRead(ULLONG llConnectID, const char* pData, DWORD dwSize) = 0;
	//释放玩家数据
	virtual void  OnCloseConnect(ULLONG llConnectID) = 0;
public:
	//普通消息处理
	virtual bool  OnNormalMsgHandleOld(ULLONG llConnectID, NetMsgHead* pMsgHead, const void* pData) = 0;
	virtual bool  OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize) = 0;
	//数据库消息处理
	virtual bool  OnDBMsghandle(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType) = 0;
};

#endif