#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "define.h"
class CDBManager;
#include "UserData.h"
#include "DBManager.h"


class CPlayer : public CUserData
{
	friend CDBManager;
public:
	CPlayer();
	~CPlayer();
private:
	ULLONG m_llConnectID;     //玩家连接ID

	//char   m_szPassWord[USER_PWD_MAX_LEN];    //密码

	bool   m_bIsWillRemove;   //是否将移除玩家
	DWORD  m_dwCutTimer;      //玩家离线时间

public:
	inline DWORD  GetPlayerConnectID()const { return m_llConnectID; }
	inline DWORD  GetPlayerID()const { return m_dwRoleID; }
	inline const char* const GetPlayerAccountName()const { return (char*)m_szAccountName; }
	inline const char* const GetPlayerRoleName()const { return (char*)m_szRoleName; }
	inline DWORD  GetIsWillRemove()const { return m_bIsWillRemove; }
	inline DWORD  GetCutTime()const { return m_dwCutTimer; }
	inline DWORD  GetAccountNameLen(){ return sizeof(m_szAccountName); }
	inline DWORD  GetRoleNameLen(){ return sizeof(m_szRoleName); }

	inline void   SetPlayerConnectID(ULLONG llConnectID) { m_llConnectID = llConnectID; }
	inline void   SetPlayerID(DWORD dwPlayerID) { m_dwRoleID = dwPlayerID; }
	inline char*  SetPlayerName(char *pPlayerAccountName) { memcpy(m_szAccountName, pPlayerAccountName, min(lstrlen(pPlayerAccountName), USER_NAME_MAX_LEN)); }
	inline char*  SetPlayerRoleName(char *pPlayerRoleName) { memcpy(m_szRoleName, pPlayerRoleName, min(lstrlen(pPlayerRoleName), USER_NAME_MAX_LEN)); }
	inline void   SetIsWillRemove(bool bIsWillRemove) { m_bIsWillRemove = bIsWillRemove; }
	inline void   SetCutTime(DWORD dwCutTimer) { m_dwCutTimer = dwCutTimer; }
};

#endif // !__PLAYER_H__
