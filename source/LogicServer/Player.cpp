#include "Player.h"

CPlayer::CPlayer()
{
	m_llConnectID = 0;
	m_bIsWillRemove = false;
	m_dwCutTimer = ~0;
	m_pUserData = NULL;
}

CPlayer::~CPlayer()
{
	delete m_pUserData;
	m_pUserData = NULL;
}

void CPlayer::SetUserData(CUserData *pUserData)
{
	if (!m_pUserData)
	{
		m_pUserData = new CUserData;
	}

	*m_pUserData = *pUserData;
}

void CPlayer::SaveData(short type, const void *pData, DWORD dwSize)
{
	m_pSaveData->m_dwID = GetPlayerRoleID();
	memcpy(m_pSaveData->m_szData, pData, dwSize);
	m_pSaveData->m_shType = type;
	m_pLogicServerLogin->SendData(m_pSaveData, (DWORD)(&(((CDSaveDataMsg*)0)->m_szData)) + dwSize);
}