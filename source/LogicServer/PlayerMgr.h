#ifndef __PLAYER_MGR_H__
#define __PLAYER_MGR_H__
#include <unordered_map>
#include "lock.h"
#include "Player.h"
#define  TIMER_DELAY_REMOVE_PLAYER_TIME (10*60*1000)

using namespace std;

//一个线程add/remove 另一个线程get,需要加锁
class CPlayerMgr
{
public:
	CPlayerMgr();
	virtual ~CPlayerMgr();
private:
	bool         m_bIsDelayRemove;    //是否延迟移除
	CLock        m_lockPlayerMgr;     //玩家管理锁
	time_t       m_tCleanTime;        //清理时间


	//key=玩家ID，value=玩家类 指针
	std::unordered_map<DWORD, CPlayer*> m_mapPlayerRoleID;

	//key=连接ID，value=玩家类 指针
	std::unordered_map<ULLONG, CPlayer*> m_mapPlayerConnectID;

private:
	//玩家是否存在
	CPlayer* IsExistPlayer(DWORD dwRoleID);
	CPlayer* IsExistPlayer(ULLONG llConnectID);

public:
	bool Init();
	inline DWORD  GetIsDelayRemove()const { return m_bIsDelayRemove; }
	inline void   SetIsDelayRemove(bool bIsDelayRemove) { m_bIsDelayRemove = bIsDelayRemove; }

	//增加玩家
	int  AddPlayer(DWORD dwRoleID, CPlayer *pPlayer);
	int  AddPlayer(ULLONG llConnectID, CPlayer *pPlayer);
	int  AddPlayer(CPlayer *pPlayer);

	//删除玩家
	bool RemovePlayer(DWORD dwRoleID);
	bool RemovePlayer(ULLONG llConnectID);
	bool RemovePlayer(CPlayer *pPlayer);

	//获取玩家数据
	CPlayer* GetPlayerDataByPlayerID(DWORD dwRoleID);
	CPlayer* GetPlayerDataByConnectID(ULLONG llConnectID);
	CPlayer* GetPlayerDataByRoleName(char* pRoleName);

	//清扫数据
	void CleanPlayerData();
};

#endif // !__PLAYER_MGR_H__
