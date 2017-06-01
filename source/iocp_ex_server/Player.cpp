#include "Player.h"

CPlayer::CPlayer()
{
	m_llConnectID = 0;
	m_bIsWillRemove = false;
	m_dwCutTimer = 0;
	memset(m_szPassWord, 0 ,sizeof(m_szPassWord));
}

CPlayer::~CPlayer()
{
}