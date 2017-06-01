#ifndef __MYSQLHANDLE_H__
#define __MYSQLHANDLE_H__
#include "MainMgr.h"
#include "MysqlDBProcess.h"
class CMainMgr;

class CMySqlHandle :public mysql::CQuery
{
public:
	CMySqlHandle();
	~CMySqlHandle();
private:
	CMainMgr         *m_pMainMgr;
public:
	bool     Init(CMainMgr *pMainMgr);
	bool     OnMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType);
	bool     OnDBHandleResult(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType);
	void     OnEvent(int timerID, const void *data);
	void     Example();
public:
};

#endif