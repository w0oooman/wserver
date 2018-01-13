#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "define.h"
#include "UserData.h"
#include "LogicServerLogin.h"
#include "SaveType.h"
extern CLogicServerLogin  *m_pLogicServerLogin;
extern CDSaveDataMsg *m_pSaveData;

class CPlayer
{
public:
	CPlayer();
	virtual ~CPlayer();
private:
	ULLONG m_llConnectID;     //玩家连接ID

	bool   m_bIsWillRemove;   //是否将移除玩家
	DWORD  m_dwCutTimer;      //玩家离线时间
public:
	CUserData  *m_pUserData;  //用户数据
public:
	inline DWORD  GetPlayerRoleID(){ return m_pUserData->m_dwRoleID; }
	inline char*  GetRoleName(){ return m_pUserData->m_szRoleName; }
	inline DWORD  GetRoleNameLen(){ return sizeof(m_pUserData->m_szRoleName); }

	inline ULLONG GetPlayerConnectID()const { return m_llConnectID; }
	inline DWORD  GetIsWillRemove()const { return m_bIsWillRemove; }
	inline DWORD  GetCutTime()const { return m_dwCutTimer; }

	inline void   SetPlayerConnectID(ULLONG llConnectID) { m_llConnectID = llConnectID; }
	inline void   SetIsWillRemove(bool bIsWillRemove) { m_bIsWillRemove = bIsWillRemove; }
	inline void   SetCutTime(DWORD dwCutTimer) { m_dwCutTimer = dwCutTimer; }

	void SetUserData(CUserData *pUserData);

	//保存常规数据(short/int/int64/结构体等)
	template<typename TYPE>
	void SaveData(short type, TYPE value)
	{
		m_pSaveData->m_dwID = GetPlayerRoleID();
		*(TYPE*)(m_pSaveData->m_szData) = value;
		m_pSaveData->m_shType = type;
		m_pLogicServerLogin->SendData(m_pSaveData, (DWORD)(&(((CDSaveDataMsg*)0)->m_szData))+sizeof(value));
	}
	//保存 字符串/结构体 数据
	void SaveData(short type, const void *pData, DWORD dwSize);
public:
	inline DWORD  GetPlayerPoint(){ return m_pUserData->m_dwPoint; }
	inline DWORD  SetPlayerPoint(DWORD dwPoint){ m_pUserData->m_dwPoint = dwPoint; SaveData(SAVE_POINT, dwPoint); }
};

#endif // !__PLAYER_H__
