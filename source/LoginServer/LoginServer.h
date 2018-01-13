#ifndef __LOGIN_SERVER_H__
#define __LOGIN_SERVER_H__
#include "KernelMgr.h"
#include "NetMsg.h"
#include "LoginServerLogic.h"
#include "LoginServerDB.h"

class CLoginServerDB;
class CLoginServerLogic;

/***********************************************************
*登录服务器,与网关服务器通信(处理玩家注册/登录等)
***********************************************************/

///*final (VS2013不支持)*/class CGatewayServer : public CKernelMgr, virtual public CNoInherit < CGatewayServer > //不要继承此类
class CLoginServer : public CClientCKernelMgr
{
private:
	CLoginServerDB      *m_pLoginServerDB;
	CLoginServerLogic   *m_pLoginServerLogic;
public:
	CLoginServer();
	virtual ~CLoginServer();
public:
	virtual void OnEvent(int timerID, void *data);

	//消息处理(返回false会关闭当前连接)
	virtual bool OnNetMessage(const void* pData, DWORD dwSize);

public:
	bool  Init(LPCTSTR lpIP, USHORT usPort);
	bool  Start();
	bool  OnUserRegister(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize);
	bool  OnUserLogin(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize);
	bool  OnUserEnter(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize);
	bool  OnUserOffline(ULLONG llConnectID, CNetMsgHead* pNetMsgHead, DWORD dwSize);

	inline CLoginServerLogic* GetLoginServerLogicPtr(){ return m_pLoginServerLogic; }
	inline CLoginServerDB* GetLoginServerDBPtr(){ return m_pLoginServerDB; }
};

#endif