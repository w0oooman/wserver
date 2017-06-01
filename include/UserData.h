#ifndef __USER_DATA_H__
#define __USER_DATA_H__
#include "define.h"

class CUserData
{
public:
	DWORD  m_dwRoleID;        //玩家ID
	char   m_szAccountName[USER_NAME_MAX_LEN];  //玩家帐号
	char   m_szRoleName[USER_NAME_MAX_LEN];     //玩机角色名
	char   m_szPassWord[USER_PWD_MAX_LEN];      //密码
	DWORD  m_dwMoney;          //金币
	DWORD  m_dwDiamond;        //钻石
	DWORD  m_dwPoint;          //积分 
public:
	CUserData()
	{
		Reset();
	}
	~CUserData()
	{

	}
	void Reset()
	{
		m_dwMoney = 0;
		m_dwDiamond = 0;
		m_dwPoint = 0;
		m_dwRoleID = 0;
		memset(m_szAccountName, 0, sizeof(m_szAccountName));
		memset(m_szRoleName, 0, sizeof(m_szRoleName));
		memset(m_szPassWord, 0, sizeof(m_szPassWord));
	}
};

#endif