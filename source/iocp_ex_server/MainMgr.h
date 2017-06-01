#ifndef __MAINMGR_H__
#define __MAINMGR_H__
#include "KernelMgr.h"
#include "SqlServerHandle.h"
#include "singleton.h"
#include "NetMsg.h"
#include "ServerLogicHandle.h"
#include "MySqlHandle.h"
#include "DistriServerHandle.h"

//#define  _USE_MYSQL_  //_USE_SQLSERVER_

class CKernelMgr;
class CSqlServerHandle;
class CServerLogicHandle;
class CMySqlHandle;
class CDistriServerHandle;


//服务器主管理类
//不要继承此类
/*final (VS2013不支持)*/class CMainMgr :public CKernelMgr, virtual public CNoInherit < CMainMgr >
{
public:
	CMainMgr();
	~CMainMgr();
private:
	//CKernelMgr * pKernelMgr_;    //内核管理类
	CSqlServerHandle         *m_pSqlServer;        //数据库接口
	CMySqlHandle             *m_pMySql;            //数据库接口
	CServerLogicHandle       *m_pServerLogic;      //服务器逻辑
	CDistriServerHandle      *m_pDServerHandle;    //分布式服务端
public:
	virtual void OnEvent(int timerID, void *data);

	//释放玩家数据
	virtual void OnCloseConnect(ULLONG llConnectID);
	virtual void DeleteTimerData(const void *data);
public:
	bool  Init(DWORD dwMaxCount, DWORD dwListenPort);
	bool  Start();

	bool  UseSqlServer();
	bool  UseMySql();
	bool  UseLua();

	//分布式服务端
	bool  InitDistri(DWORD dwMaxCount, DWORD dwListenPort);
	bool  StartDistri();

	//普通消息处理
	bool  OnNormalMsgHandleOld(NetMsgHead* pMsgHead, const void* pData, DWORD dwIndex, DWORD dwRoundIndex);
	bool OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);
	//数据库消息处理
	bool  OnDBMsghandle(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType);

	//重新加载脚本
	void ResetScript();
public:
	inline  CSqlServerHandle* GetSqlServerPtr(){ return m_pSqlServer; }
	inline  CMySqlHandle* GetMySqlPtr(){ return m_pMySql; }
	inline  CServerLogicHandle* GetServerLogicHandlePtr(){ return m_pServerLogic; }
};


#endif