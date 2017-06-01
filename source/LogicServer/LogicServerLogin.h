#ifndef __LOGIC_SERVER_LOGIN_H__
#define __LOGIC_SERVER_LOGIN_H__
#include "KernelMgr.h"
#include "NetMsg.h"
class CLogicServer;

/***********************************************************
*逻辑服务器,与登录服务器通信
***********************************************************/

class CLogicServerLogin : public CClientCKernelMgr
{
private:
	CLogicServer   *m_pLogicServer;
public:
	CLogicServerLogin();
	~CLogicServerLogin();
public:
	virtual void OnEvent(int timerID, void *data);

	//消息处理(返回false会关闭当前连接)
	virtual bool OnNetMessage(const void* pData, DWORD dwSize);


public:
	bool  Init(LPCTSTR lpIP, USHORT usPort);
	bool  Start();
	void  SetLogicServerPtr(CLogicServer *pLogicServer);
	void  OnCloseConnect(ULLONG llConnectID);

};

#endif