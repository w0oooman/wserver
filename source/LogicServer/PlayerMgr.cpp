#include <time.h>
#include "PlayerMgr.h"

CPlayerMgr::CPlayerMgr()
{
	m_bIsDelayRemove = false;
	m_mapPlayerRoleID.clear();
	m_mapPlayerConnectID.clear();
	m_tCleanTime = time(0);
}

CPlayerMgr::~CPlayerMgr()
{
	for (auto it = m_mapPlayerRoleID.begin();it != m_mapPlayerRoleID.end();it++)
	{
		SAFE_DELETE(it->second);
	}

	m_mapPlayerRoleID.clear();
	m_mapPlayerConnectID.clear();
}

bool CPlayerMgr::Init()
{
	return true;
}

CPlayer* CPlayerMgr::IsExistPlayer(DWORD dwRoleID)
{
	auto it = m_mapPlayerRoleID.find(dwRoleID);
	if (it != m_mapPlayerRoleID.end())
	{
		return it->second;
	}

	return NULL;
}

CPlayer* CPlayerMgr::IsExistPlayer(ULLONG llConnectID)
{
	auto it = m_mapPlayerConnectID.find(llConnectID);
	if (it != m_mapPlayerConnectID.end())
	{
		return it->second;
	}

	return NULL;
}

//增加玩家
int CPlayerMgr::AddPlayer(DWORD dwRoleID, CPlayer *pPlayer)
{
	if (!pPlayer) return 0;

	CLockMgr lockMgr(&m_lockPlayerMgr);

	bool ret = RemovePlayer(dwRoleID);
	if (ret)
	{
		m_mapPlayerRoleID.insert(pair<DWORD, CPlayer*>(dwRoleID, pPlayer));
		m_mapPlayerConnectID.insert(pair<ULLONG, CPlayer*>(pPlayer->GetPlayerConnectID(), pPlayer));
	}

	lockMgr.UnLock();

	pPlayer->SaveData(SAVE_POINT, 20+rand()%10);//whb test

	if(ret) Log(LOG_THREAD, "CPlayerMgr add player ID = %d", dwRoleID);
	return 1;
}

//增加玩家
int CPlayerMgr::AddPlayer(ULLONG llConnectID, CPlayer *pPlayer)
{
	if (!pPlayer) return 0;

	CLockMgr lockMgr(&m_lockPlayerMgr);

	bool ret = RemovePlayer(llConnectID);
	DWORD dwRoleID = 0;
	if (ret)
	{
		dwRoleID = pPlayer->GetPlayerRoleID();
		m_mapPlayerRoleID.insert(pair<DWORD, CPlayer*>(dwRoleID, pPlayer));
		m_mapPlayerConnectID.insert(pair<ULLONG, CPlayer*>(llConnectID, pPlayer));
	}

	lockMgr.UnLock();

	if (ret) Log(LOG_THREAD, "CPlayerMgr add player ID = %d", dwRoleID);
	return 1;
}

//增加玩家
int CPlayerMgr::AddPlayer(CPlayer *pPlayer)
{
	if (!pPlayer) return 0;

	AddPlayer(pPlayer->GetPlayerRoleID(), pPlayer);
}

//删除玩家
bool CPlayerMgr::RemovePlayer(DWORD dwRoleID)
{
	CPlayer *pPlayer = IsExistPlayer(dwRoleID);
	if (pPlayer)
	{
		if (m_bIsDelayRemove)
		{
			pPlayer->SetIsWillRemove(true);
			pPlayer->SetCutTime(time(0));
			return false;
		}

		CLockMgr lockMgr(&m_lockPlayerMgr);

		ULLONG llConncetID = pPlayer->GetPlayerConnectID();
		m_mapPlayerRoleID.erase(dwRoleID);

		if (IsExistPlayer(llConncetID))
		{
			m_mapPlayerConnectID.erase(llConncetID);
		}

		lockMgr.UnLock();

		SAFE_DELETE(pPlayer);

		Log(LOG_THREAD, "CPlayerMgr remove player ID = %d", dwRoleID);
	}
	return true;
}

//删除玩家
bool CPlayerMgr::RemovePlayer(ULLONG llConnectID)
{
	CPlayer *pPlayer = IsExistPlayer(llConnectID);
	if (pPlayer)
	{
		if (m_bIsDelayRemove)
		{
			pPlayer->SetIsWillRemove(true);
			pPlayer->SetCutTime(time(0));
			return false;
		}

		CLockMgr lockMgr(&m_lockPlayerMgr);

		DWORD dwRoleID = pPlayer->GetPlayerRoleID();
		m_mapPlayerConnectID.erase(llConnectID);

		if (IsExistPlayer(dwRoleID))
		{
			m_mapPlayerRoleID.erase(dwRoleID);
		}

		lockMgr.UnLock();

		SAFE_DELETE(pPlayer);

		Log(LOG_THREAD, "CPlayerMgr remove player ID = %d", dwRoleID);
	}
	return true;
}

//删除玩家
bool CPlayerMgr::RemovePlayer(CPlayer *pPlayer)
{
	return RemovePlayer(pPlayer->GetPlayerConnectID());
}

//获取玩家数据
CPlayer* CPlayerMgr::GetPlayerDataByPlayerID(DWORD dwRoleID)
{
	CLockMgr lockMgr(&m_lockPlayerMgr);
	return IsExistPlayer(dwRoleID);
}

//获取玩家数据
CPlayer* CPlayerMgr::GetPlayerDataByConnectID(ULLONG llConnectID)
{
	CLockMgr lockMgr(&m_lockPlayerMgr);
	return IsExistPlayer(llConnectID);
}

CPlayer* CPlayerMgr::GetPlayerDataByRoleName(char* pRoleName)
{
	if (NULL == pRoleName || strncmp(pRoleName, "", 1) == 0)
		return NULL;

	CLockMgr lockMgr(&m_lockPlayerMgr);

	for (auto it = m_mapPlayerRoleID.begin(); it != m_mapPlayerRoleID.end(); it++)
	{
		CPlayer *pPlayer = it->second;
		if (pPlayer)
		{
			if (strncmp(pRoleName, pPlayer->GetRoleName(), pPlayer->GetRoleNameLen()) == 0)
			{
				return pPlayer;
			}
		}
	}

	return NULL;
}

void CPlayerMgr::CleanPlayerData()
{
	m_tCleanTime = time(0);

	CLockMgr lockMgr(&m_lockPlayerMgr);

	for (auto it = m_mapPlayerRoleID.begin(); it != m_mapPlayerRoleID.end();)
	{
		CPlayer *pPlayer = it->second;
		if (pPlayer)
		{
			ULLONG llConnectID = pPlayer->GetPlayerConnectID();
			if (pPlayer->GetIsWillRemove() && m_tCleanTime >= pPlayer->GetCutTime() + TIMER_DELAY_REMOVE_PLAYER_TIME)
			{
				m_mapPlayerRoleID.erase(it++);
				m_mapPlayerConnectID.erase(llConnectID);
			}
			else
			{
				it++;
			}
		}
	}
}