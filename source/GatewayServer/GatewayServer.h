#ifndef __GATEWAY_SERVER_H__
#define __GATEWAY_SERVER_H__
#include "KernelMgr.h"
#include "NetMsg.h"
#include "IniParser.h"
class CGatewayServerLogic;
class CGatewayServerLogin;
struct CUserGateWayInfo;

/***********************************************************
*网关服务器,用于与客户端通信,负载均衡、转发客户端请求等
***********************************************************/

///*final (VS2013不支持)*/class CGatewayServer : public CKernelMgr, virtual public CNoInherit < CGatewayServer > //不要继承此类
class CGatewayServer : public CKernelMgr
{
private:
	CGatewayServerLogic  *m_pGatewayServerLogic;
	CGatewayServerLogin  *m_pGatewayServerLogin;
private:
	unordered_map<ULLONG, CUserGateWayInfo*>  m_mapUserGWInfo;
public:
	CGatewayServer();
	~CGatewayServer();
public:
	virtual void OnEvent(int timerID, void *data);
	virtual void OnCloseConnect(ULLONG llConnectID);
public:
	bool  Init();
	bool  Start();

	CGatewayServerLogic* GetGatewayLogicPtr();
	CGatewayServerLogin* GetGatewayLoginPtr();

	//消息处理(返回false会关闭当前连接)
	bool  OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);

	void  SetUserGateWayInfo(ULLONG llConnectID, CUserGateWayInfo* pUserGateWayInfo);
	CUserGateWayInfo* GetUserGateWayInfo(ULLONG llConnectID);
	void  RemoveUserGateWayInfo(ULLONG llConnectID);

	//版本错误
	void SendVersionError(ULLONG llConnectID);

	//发送数据到逻辑服
	bool SendData2LogicServer(ULLONG llConnectID, CNetMsgHead *pNetMsgHead, DWORD dwSize);
};



//用户在网关服信息
struct CUserGateWayInfo
{
	WORD wServerIndex;      //用户登录的逻辑服ID
};

#endif