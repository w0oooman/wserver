#ifndef __LOGIN_SERVER_LOGIC_H__
#define __LOGIN_SERVER_LOGIC_H__
#include "KernelMgr.h"
#include "NetMsg.h"
#include "ServerRegister.h"
#include "LoginServer.h"
class CLoginServer;

/***********************************************************
*登录服务器服务机,与逻辑服务器通信
***********************************************************/

class CLoginServerLogic : public CKernelMgr
{
private:
	CLoginServer     *m_pLoginServer;
	CServerRegister  *m_pServerRegister;
public:
	CLoginServerLogic();
	~CLoginServerLogic();
public:
	virtual void OnEvent(int timerID, void *data);
	virtual void OnCloseConnect(ULLONG llConnectID);

public:
	bool  Init();
	bool  Start();

	//消息处理(返回false会关闭当前连接)
	bool  OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);
	void  SetLoginServerPtr(CLoginServer *pLoginServer);

	bool  SendDataByIndex(WORD wServerIndex, CNetMsgHead* pAllMsgData, DWORD dwAllMsgLen);
	void  SendData2LogicServer(WORD wServerIndex, CNetMsgHead *pNetMsgHead, DWORD dwSize);
};

#endif