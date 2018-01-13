#ifndef __DISTRI_CLIENT_HANDLE__H__
#define __DISTRI_CLIENT_HANDLE__H__
#include "MainMgr.h"

class CClientMainMgr;

//分布式客户端
class CDistriClientHandle :public CClientCKernelMgr, virtual public CNoInherit < CDistriClientHandle >
{
public:
	CDistriClientHandle();
	virtual ~CDistriClientHandle();
public:
	bool  Init(LPCTSTR lpIP, USHORT usPort);
	bool  Start();
	//消息处理
	bool  OnNetMessage(const void* pData, DWORD dwSize);
	//定时器消息
	virtual void OnEvent(int timerID, void *data);
};

#endif