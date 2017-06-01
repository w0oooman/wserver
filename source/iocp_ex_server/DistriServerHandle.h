#ifndef __DISTRI_SERVER_HANDLE__H__
#define __DISTRI_SERVER_HANDLE__H__
#include "singleton.h"
#include "KernelMgr.h"

class CMainMgr;

//分布式服务端
class CDistriServerHandle:public CKernelMgr, virtual public CNoInherit < CDistriServerHandle >
{
public:
	CDistriServerHandle();
	~CDistriServerHandle();
private:
	CMainMgr   *m_pMainMgr;  //主管理器
public:
	//普通消息处理
	virtual bool OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);

	//数据库消息处理
	virtual bool  OnDBMsghandle(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType);
	//定时器消息
	virtual void OnEvent(int timerID, void *data);

public:
	bool  Init(DWORD dwMaxCount, DWORD dwListenPort,CMainMgr* pMainMgr);
	bool  Start();

};

#endif