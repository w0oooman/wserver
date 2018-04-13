#include "MainMgr.h"
#include "TimerID.h"
#include "LuaManager.h"
//#pragma comment(lib,"kernel.lib")

extern CLuaManager g_Script;


//使用定时器的方式重新加载脚本，保证加载脚本和
//游戏逻辑在一个一个线程内进行，防止出错!!
void ResetLuaScript(void *data)
{
	g_Script.RefreshLua();
}

CMainMgr::CMainMgr()
{
	m_pSqlServer = NULL;
	m_pMySql = NULL;
	m_pServerLogic = NULL;
	m_pDServerHandle = NULL;
}

CMainMgr::~CMainMgr()
{
	g_Script.ServerDown();
	LogAll();
	SAFE_DELETE(m_pSqlServer);
	SAFE_DELETE(m_pMySql);
	SAFE_DELETE(m_pServerLogic);
	SAFE_DELETE(m_pDServerHandle);
}

bool CMainMgr::Init(DWORD dwMaxCount, DWORD dwListenPort)
{
	try
	{
		m_pServerLogic = new CServerLogicHandle;
		if (NULL == m_pServerLogic) return false;

		if (!CKernelMgr::Init(dwMaxCount, dwListenPort)) return false;

		if (!m_pServerLogic->Init(this)) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CMainMgr::Start()
{
	return CKernelMgr::Start();
}

bool CMainMgr::UseSqlServer()
{
	try
	{
		m_pSqlServer = new CSqlServerHandle;
		if (NULL == m_pSqlServer) return false;
		if (m_pSqlServer != NULL)
		{
			if (!m_pSqlServer->Init(this)) return false;
			if(!m_pSqlServer->InitDB(TEXT("127.0.0.1"),1433,TEXT("test_db"),TEXT("test"),TEXT("whb"))) return false;  //whb
		}
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CMainMgr::UseMySql()
{
	try
	{
		m_pMySql = new CMySqlHandle;
		if (NULL == m_pMySql) return false;
		if (m_pMySql != NULL)
		{
			if (!m_pMySql->Init(this)) return false;
			if (!m_pMySql->InitDB(TEXT("root"), TEXT("000000"), TEXT("127.0.0.1"), TEXT("test_db"))) return false;
			m_pMySql->Example(); //whb test
		}
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

bool CMainMgr::UseLua()
{
	try
	{
		//初始化LUA环境
		g_Script.Init(this);
		g_Script.ServerStart();
		AddEvent(timer_lua_1_minute, 60 * 1000);
		AddEvent(timer_lua_10_minute, 10 * 60 * 1000);
		AddEvent(timer_lua_1_hour, 60 * 60 * 1000);
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}

//分布式服务端
bool CMainMgr::InitDistri(DWORD dwMaxCount, DWORD dwListenPort)
{
	try
	{
		m_pDServerHandle = new CDistriServerHandle;
		if (NULL == m_pDServerHandle) return false;

		if (!m_pDServerHandle->Init(dwMaxCount, dwListenPort, this)) return false;
	}
	catch (...)
	{
		Log_Position();
		return false;
	}

	return true;
}
bool CMainMgr::StartDistri()
{
	return m_pDServerHandle->Start();
}

bool CMainMgr::OnNormalMsgHandleOld(NetMsgHead* pMsgHead, const void* pData, DWORD dwIndex, DWORD dwRoundIndex)
{
	//return m_pServerLogic->OnMsgHandle(pMsgHead, pData, dwIndex, dwRoundIndex);
	return true;
}

bool CMainMgr::OnNormalMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize)
{
	return m_pServerLogic->OnMsgHandle(llConnectID, pData, dwSize);
}

bool CMainMgr::OnDBMsghandle(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType)
{
	if (m_pSqlServer)
	{
		return m_pSqlServer->OnMsgHandle(llConnectID, pData, dwSize, wDBType);
	}
	else if (m_pMySql)
	{
		return m_pMySql->OnMsgHandle(llConnectID, pData, dwSize, wDBType);
	}
	else
	{
		//log whb
	}

	return true;
}

//重新加载脚本
void CMainMgr::ResetScript()
{
	AddEvent(0, WHEEL_TIMER_TICK, &ResetLuaScript);
}

void CMainMgr::OnEvent(int timerID, void *data)
{
	//Log("----------CMainMgr::OnEvent timerID=%d,data=%d,time=%d", timerID, (int)data, time(0));//whb
	if (timerID > timer_db_begin && timerID < timer_db_end)
	{

	}
	else if (timerID > timer_server_normal_begin && timerID < timer_server_normal_end)
	{

	}
	else if (timerID > timer_lua_begin && timerID < timer_lua_end)
	{
		g_Script.OnEvent(timerID, data);
	}
	else
	{
		//Log("invalid timerID=%d, file=%s,line=%d", timerID, __FILE__, __LINE__);  //whb 要放开
	}
}

//释放玩家数据
void CMainMgr::OnCloseConnect(ULLONG llConnectID)
{
	m_pServerLogic->OnCloseConnect(llConnectID);
}

void CMainMgr::DeleteTimerData(const void *data)
{
	g_Script.DeleteTimerData(data);
}