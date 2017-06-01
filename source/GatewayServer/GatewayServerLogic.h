#ifndef __GATEWAY_SERVERLOGIC_H__
#define __GATEWAY_SERVERLOGIC_H__
#include "GatewayServer.h"
#include "NetMsg.h"
#include "ServerRegister.h"
class CGatewayServer;

/***********************************************************
*网关服务器分布式服务,用于与逻辑服务器通信
***********************************************************/

///*final (VS2013不支持)*/class CGatewayServer : public CKernelMgr, virtual public CNoInherit < CGatewayServer > //不要继承此类
class CGatewayServerLogic : public CKernelMgr
{
private:
	CGatewayServer   *m_pGatewayServer;
	CServerRegister  *m_pServerRegister;
public:
	CGatewayServerLogic();
	~CGatewayServerLogic();

public:
	virtual void OnEvent(int timerID, void *data);
	virtual void OnCloseConnect(ULLONG llConnectID);

public:
	bool  Init(DWORD dwMaxCount, DWORD dwListenPort);
	bool  Start();

	CGatewayServer* GetGatewayServerPtr();
	void SetGatewayServerPtr(CGatewayServer* pGatewayServer);

	//消息处理
	bool  OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);

	bool SendDataByIndex(WORD wServerIndex, CNetMsgHead* pAllMsgData, DWORD dwAllMsgLen);
};

#endif