#ifndef __DB_SERVER_H__
#define __DB_SERVER_H__
#include "KernelMgr.h"
#include "NetMsg.h"
#include "DBManager.h"

/***********************************************************
*数据库服务器
***********************************************************/

class CDBServer : public CKernelMgr
{
private:
	bool           m_bSuccess;   //是否初始化/启动成功
	CDBManager    *m_pDBmanager;
public:
	CDBServer();
	~CDBServer();
public:
	virtual void OnEvent(int timerID, void *data);

public:
	bool  Init(DWORD dwMaxCount, DWORD dwListenPort);
	bool  Start();

	//消息处理(返回false会关闭当前连接)
	bool  OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);

	void  SaveData(CNetMsgHead *pNetMsgHead, DWORD dwSize);
};

#endif