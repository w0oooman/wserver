#ifndef __GATEWAY_SERVERLOGIN_H__
#define __GATEWAY_SERVERLOGIN_H__
#include "GatewayServer.h"
#include "NetMsg.h"
class CGatewayServer;


/***********************************************************
*网关服务器分布式服务,用于与登录服务器通信
***********************************************************/

///*final (VS2013不支持)*/class CGatewayServer : public CKernelMgr, virtual public CNoInherit < CGatewayServer > //不要继承此类
class CGatewayServerLogin : public CKernelMgr
{
private:
	CGatewayServer   *m_pGatewayServer;

public:
	CGatewayServerLogin();
	~CGatewayServerLogin();
public:
	virtual void OnEvent(int timerID, void *data);
	virtual void OnCloseConnect(ULLONG llConnectID);
private:
	bool  OnLoginComplete(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize);
public:
	bool  Init(DWORD dwMaxCount, DWORD dwListenPort);
	bool  Start();

	CGatewayServer* GetGatewayServerPtr();
	void SetGatewayServerPtr(CGatewayServer* pGatewayServer);

	//消息处理
	bool  OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);

	//用户注册
	bool  OnUserRegister(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize);

	//用户登录
	bool  OnUserLogin(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize);

	//用户进入
	bool  OnUserEnter(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize);
};


#endif