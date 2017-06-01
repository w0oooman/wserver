#ifndef __PLAYER_MGR_H__
#define __PLAYER_MGR_H__
#include <unordered_map>
#include "Player.h"

using namespace std;

class CMainMgr;

class CPlayerMgr
{
public:
	CPlayerMgr();
	~CPlayerMgr();
private:
	CMainMgr    *m_pMainMgr;
	bool         m_bIsDelayRemove;  //是否延迟移除

	//key=玩家ID，value=玩家类 指针
	std::unordered_map<DWORD, CPlayer*> m_PlayerMap;
public:
	bool Init(CMainMgr *pMainMgr);
	inline DWORD  GetIsDelayRemove()const { return m_bIsDelayRemove; }
	inline void   SetIsDelayRemove(bool bIsDelayRemove) { m_bIsDelayRemove = bIsDelayRemove; }

	//玩家是否存在
	bool IsExistPlayer(DWORD dwPlayerID);
	bool IsExistPlayer(char* pPlayerAccountName);

	//增加玩家
	int  AddPlayer(DWORD dwPlayerID, CPlayer *pPlayer);
	int  AddPlayer(CPlayer *pPlayer);

	//删除玩家
	void RemovePlayer(DWORD dwPlayerID);
	void RemovePlayer(CPlayer *pPlayer);
	void RemovePlayer(ULLONG llConnectID);

	//获取玩家数据
	CPlayer* GetPlayerDataByPlayerID(DWORD dwPlayerID);
	CPlayer* GetPlayerDataByConnectID(ULLONG llConnectID);
	CPlayer* GetPlayerDataByAccountName(char* pPlayerAccountName);

	//清扫数据
	void CleanPlayerData();
};

#endif // !__PLAYER_MGR_H__
