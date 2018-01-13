#ifndef __SERVER_LOGIC_HANDLE__H__
#define __SERVER_LOGIC_HANDLE__H__
#include "MainMgr.h"
#include "PlayerMgr.h"

class CMainMgr;
class CPlayerMgr;

#define  TIMER_DELAY_REMOVE_PLAYER_TIME (10*1000)

//游戏服务器逻辑处理
class CServerLogicHandle
{
public:
	CServerLogicHandle();
	virtual ~CServerLogicHandle();
private:
	CMainMgr     *m_pMainMgr;
	CPlayerMgr   *m_pPlayerMgr;        //玩家管理接口
public:
	bool  Init(CMainMgr *pMainMgr);
	bool  OnMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize);
	//定时器事件
	void  OnEvent(int timerID, void *data);
	//移除玩家
	void  OnCloseConnect(ULLONG llConnectID);
public:
	//登录完成.byResult:0 成功; > 0 失败错误码
	void OnLoginComplete(ULLONG llConnectID, BYTE byResult, CPlayer *pPlayer);
};

#endif