#ifndef __LOGIN_SERVERDB_H__
#define __LOGIN_SERVERDB_H__
#include "KernelMgr.h"
#include "NetMsg.h"
class CLoginServer;

/***********************************************************
*登录服务器,与DB服务器通信(处理玩家注册/登录等)
***********************************************************/

class CLoginServerDB : public CClientCKernelMgr
{
private:
	CLoginServer     *m_pLoginServer;
public:
	CLoginServerDB();
	virtual ~CLoginServerDB();
public:
	virtual void OnEvent(int timerID, void *data);

	//消息处理
	virtual bool OnNetMessage(const void* pData, DWORD dwSize);


public:
	bool  Init();
	bool  Start();

	CLoginServer* GetLoginServerPtr();
	void  SetLoginServerPtr(CLoginServer *pLoginServer);
};

#endif