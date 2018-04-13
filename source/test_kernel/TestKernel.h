#ifndef __TEST_KERNEL_H__
#define __TEST_KERNEL_H__
#include "KernelMgr.h"
#include "NetMsg.h"
#include "ServerRegister.h"


class CTestKernel : public CKernelMgr
{
public:
	CTestKernel();
	virtual ~CTestKernel();
public:
	virtual void OnEvent(int timerID, void *data);
	virtual void OnCloseConnect(ULLONG llConnectID);

public:
	bool  Init();
	bool  Start();

	//消息处理(返回false会关闭当前连接)
	bool  OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);
};

#endif