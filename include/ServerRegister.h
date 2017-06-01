#ifndef __SERVER_REGISTER_H__
#define __SERVER_REGISTER_H__
#include "define.h"

//服务器注册(用于客户机与服务机相连时)
class CServerRegister
{
private:
	DWORD    m_dwMaxCount;
	ULLONG  *m_pllConnectID;
public:
	CServerRegister()
	{
		m_dwMaxCount = 0;
		m_pllConnectID = NULL;
	}
	~CServerRegister()
	{
		delete m_pllConnectID;
	}
public:
	void Init(DWORD dwMaxCount)
	{
		if (dwMaxCount > 0)
		{
			m_dwMaxCount = dwMaxCount;
			m_pllConnectID = new ULLONG[dwMaxCount];
			if (!m_pllConnectID) return;
			memset(m_pllConnectID, 0, dwMaxCount);
		}
	}

	DWORD GetMaxCount(){ return m_dwMaxCount; }

	void ServerRegister(ULLONG llConnectID)
	{
		if (0 == llConnectID) return;

		bool bIsRegister = false;
		for (int i = 0; i < m_dwMaxCount; i++)
		{
			if (llConnectID == m_pllConnectID[i])
			{
				bIsRegister = true;
				break;
			}
		}

		if (!bIsRegister)
		{
			for (int i = 0; i < m_dwMaxCount; i++)
			{
				if (0 == m_pllConnectID[i])
				{
					m_pllConnectID[i] = llConnectID;
					bIsRegister = true;
					break;
				}
			}
		}

		if (!bIsRegister)
		{
			Log("server register full!");
		}
	}


	void ServerUnRegister(ULLONG llConnectID)
	{
		for (int i = 0; i < m_dwMaxCount; i++)
		{
			if (llConnectID == m_pllConnectID[i])
			{
				m_pllConnectID[i] = 0;
				break;
			}
		}
	}

	ULLONG GetServerConnectID(WORD wServerIndex)
	{
		if (wServerIndex > 0 && wServerIndex <= m_dwMaxCount)
		{
			return m_pllConnectID[wServerIndex - 1];
		}

		return 0;
	}
};

#endif