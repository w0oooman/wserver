#include "DistriServerHandle.h"
#include "MainMgr.h"

CDistriServerHandle::CDistriServerHandle()
{
	m_pMainMgr = NULL;
}

CDistriServerHandle::~CDistriServerHandle()
{
	LogAll();
	m_pMainMgr = NULL;
}

bool CDistriServerHandle::Init(DWORD dwMaxCount, DWORD dwListenPort, CMainMgr* pMainMgr)
{
	try
	{
		m_pMainMgr = pMainMgr;
		if (!CKernelMgr::Init(dwMaxCount, dwListenPort)) return false;
	}
	catch (...)
	{
		Log(LOG_DSERVER, "CDistriServerHandle catch error ID=%d", GetLastError());
		return false;
	}

	return true;
}

bool CDistriServerHandle::Start()
{
	return CKernelMgr::Start();
}

bool CDistriServerHandle::OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
{
	if (NULL == pData)  return false;
	CNetMsgHead *pMsgHead = (CNetMsgHead*)pData;

	switch (pMsgHead->protocol_)
	{

	}

	return false;
}

bool CDistriServerHandle::OnDBMsghandle(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType)
{
	return true;
}

void CDistriServerHandle::OnEvent(int timerID, void *data)
{
	printf("CDistriServerHandle::OnEvent timerID=%d,data=%d\n", timerID, (int)data);//whb
}