#include "DistriClientHandle.h"

CDistriClientHandle::CDistriClientHandle()
{
	
}

CDistriClientHandle::~CDistriClientHandle()
{
	LogAll();
}

bool CDistriClientHandle::Init(LPCTSTR lpIP, USHORT usPort)
{
	try
	{
		if (!CClientCKernelMgr::Init(lpIP, usPort)) return false;
	}
	catch (...)
	{
		Log(LOG_DSERVER, "error file=%s,line=%d,function=%d,ErrorID=%d", __FILE__, __LINE__, __FUNCTION__, GetLastError());
		return false;
	}

	return true;
}

bool CDistriClientHandle::Start()
{
	return CClientCKernelMgr::Start();
}

bool CDistriClientHandle::OnNetMessage(const void* pData, DWORD dwSize)
{
	NetMsgHead* pNetMsg = (NetMsgHead*)pData;
	void *pNetData = (char *)(pNetMsg + 1);
	if (pNetMsg->dwSize != dwSize)
	{
		throw CNetErr("msg length not equal.");
		return false;
	}

	return true;
}

//定时器消息
void CDistriClientHandle::OnEvent(int timerID, void *data)
{
	printf("CDistriClientHandle::OnEvent timerID=%d,*data=%d\n",timerID,(int)data);
}