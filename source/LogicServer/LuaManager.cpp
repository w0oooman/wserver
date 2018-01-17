#include <math.h>
#include "LuaManager.h"
#include "Log.h"
#include "TimerID.h"
#include "common.h"
#include "LogicServer.h"

extern "C"
{
#include "lauxlib.h"
#include "lualib.h"
}

#pragma comment(lib,"lua.lib")


#define REGISTER_FUNCTION(ls,func) \
    lua_register(ls, #func, L##_##func)

#define REGISTER_FUNCTION_EX(ls,func) \
	extern int L##_##func(lua_State *L); \
    lua_register(ls, #func, L##_##func)

//1024 * 1024 * 10
#define FILESIZE (10485760)

CLuaManager  g_Script;

CLuaManager::CLuaManager()
{
	m_ls = NULL;
	m_pManager = NULL;
	m_nTimerID = timer_generate_lua_begin;
	LoadLua();
}

CLuaManager::~CLuaManager()
{
	CloseLua();
	m_ls = NULL;
}

void CLuaManager::LoadLua()
{
	m_ls = luaL_newstate();
	if (!m_ls)
	{
		Log("lua new state error.");
		return;
	}

	luaL_checkversion(m_ls);
	lua_gc(m_ls, LUA_GCSTOP, 0);    /* stop collector during initialization */
	luaL_openlibs(m_ls);            /* open libraries */
	lua_gc(m_ls, LUA_GCRESTART, 0);

	REGISTER_FUNCTION_EX(m_ls, Dofile);
}

void CLuaManager::CloseLua()
{
	lua_close(m_ls);
	m_ls = NULL;
}

void CLuaManager::Reset()
{
	CloseLua();
	LoadLua();
}

//刷新脚本  保证和游戏逻辑同属一个线程!!防止出错
void CLuaManager::RefreshLua()
{
	dofile(LUA_DOFILE_INIT_FILE);
}

void CLuaManager::Init(CLogicServer *pMainMgr)
{
	m_pManager = pMainMgr;
	Register();
	RefreshLua();
}

void CLuaManager::OnEvent(int timerID, void *data)
{
	switch (timerID)
	{
	case timer_lua_1_minute:
	{
		CallFunc(m_ls, "SI_EachOneMinute");
	}break;
	case timer_lua_10_minute:
	{
		CallFunc(m_ls, "SI_EachTenMinute");
	}break;
	case timer_lua_1_hour:
	{
		CallFunc(m_ls, "SI_EachOneHour");
	}break;
	default:break;
	}
}

int CLuaManager::dofile(const char* filename)
{
	lua_pushstring(m_ls,filename);

	extern int L_Dofile(lua_State *L);
	return L_Dofile(m_ls);
}

void CLuaManager::Register()
{
	REGISTER_FUNCTION_EX(m_ls, Log);
	REGISTER_FUNCTION(m_ls, LoadTable);
	REGISTER_FUNCTION(m_ls, SaveTable);
	REGISTER_FUNCTION(m_ls, SetEvent);
	REGISTER_FUNCTION(m_ls, ClrEvent);
}

void CLuaManager::ServerStart()
{
	CallFunc(m_ls, "OnServerStart");
	//ExecuteLuaFunc("function_test", 2, (lua_Number)1, (lua_Number)2); //whb test
}

void CLuaManager::ServerDown()
{
	CallFunc(m_ls, "OnServerDwon");
}

static int w_lua_error(lua_State *L)
{
	const char* pErrorMsg = lua_tostring(L, -1);

	if (pErrorMsg)
		luaL_traceback(L, L, pErrorMsg, 1);
	else
		lua_pushliteral(L, "no error");

	return 1;
}

bool CLuaManager::Call(lua_State *L, int stackPos)
{
	int curPos = lua_gettop(L);
	if (stackPos >= curPos)
		return false;

	if (lua_pcall(L, curPos - stackPos - 2, LUA_MULTRET, stackPos + 1) != 0)
	{
		char temp[1024];
		sprintf_s(temp, "%s\r\n", lua_tostring(L, -1));
		Log(temp);
		lua_settop(L, stackPos);
		return false;
	}

	lua_settop(L, stackPos);
	return true;
}

#define PREPARE_CALL_LUA()                                      \
	if ( ( name == NULL ) || ( name[0] == 0 ) ) return false;   \
	int stackPos = lua_gettop( L );                          \
	lua_pushcfunction(L, w_lua_error);                       \
	lua_getglobal( L, name );                                \
	if (!lua_isfunction( L, -1 )) { lua_pop( L, 2 ); return false; }

#define CALL_LUA()                                              \
	if ( !Call(L, stackPos ) ) return false; return true;

bool CLuaManager::CallFunc(lua_State *L, const char *name)
{
	PREPARE_CALL_LUA();
	CALL_LUA();
}

// 执行LUA函数
bool CLuaManager::ExecuteLuaFunc(const char *pFuncName, unsigned short wParaNum, ...)
{
	const char* name = pFuncName;
	lua_State *L = m_ls;
	PREPARE_CALL_LUA()

	//把参数压入LUA栈
	va_list header;
	va_start(header, wParaNum);
	for (unsigned short i = 0; i < wParaNum; i++)
	{
		lua_Number iArg = va_arg(header, lua_Number);
		lua_pushnumber(m_ls, iArg);
	}
	va_end(header);

	CALL_LUA()
}

void PrintLuaStack(lua_State *L)
{
	int top = lua_gettop(L);
	Log("Type:%d", top);
	for (int i = 1; i <= lua_gettop(L); ++i)
	{
		switch (lua_type(L, i))
		{
		case LUA_TNIL:
			Log("\t%s", lua_typename(L, lua_type(L, i)));
			break;
		case LUA_TBOOLEAN:
			Log( "\t%s	%s", lua_typename(L, lua_type(L, i)), lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TLIGHTUSERDATA:
			Log( "\t%s	0x%08p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
			break;
		case LUA_TNUMBER:
			Log( "\t%s	%f", lua_typename(L, lua_type(L, i)), lua_tonumber(L, i));
			break;
		case LUA_TSTRING:
			Log( "\t%s	%s", lua_typename(L, lua_type(L, i)), lua_tostring(L, i));
			break;
		case LUA_TTABLE:
			Log( "\t%s	0x%08p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
			break;
		case LUA_TFUNCTION:
			Log( "\t%s()	0x%08p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
			break;
		case LUA_TUSERDATA:
			Log( "\t%s	0x%08p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
			break;
		case LUA_TTHREAD:
			Log( "\t%s", lua_typename(L, lua_type(L, i)));
			break;
		}
	}
}


int CLuaManager::L_LoadTable(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		const char* tablename = static_cast<const char *>(lua_tostring(L, 1));
		FILE *file = NULL;
		int errorcode = fopen_s(&file, tablename, "rb");
		if (0 == errorcode && file)
		{
			fseek(file, 0, SEEK_END);
			long fsize = ftell(file);
			fseek(file, 0, SEEK_SET);
			if (fsize <= 0)
			{
				lua_newtable(L);
				fclose(file);
				return 1;
			}

			BYTE  *pBuff = NULL;
			pBuff = new BYTE[fsize];
			if (NULL == pBuff)
			{
				Log("LoadTable too big,filename=%s,size=%d", tablename, fsize);
				fclose(file);
				lua_pushnil(L);
				return 0;
			}

			memset(pBuff, 0, fsize * sizeof(BYTE));
			size_t  lfsize = fread(pBuff, sizeof(BYTE), fsize, file);
			int ck = luaEx_Unserialize(L, pBuff);
			if (ck <= 0)
			{
				Log("unserialize error:%s", lua_tostring(L, -1));
				fclose(file);
				SAFE_DELETE_ARRAY(pBuff);
				lua_pushnil(L);
				return 1;
			}
			fclose(file);
			SAFE_DELETE_ARRAY(pBuff);
			return 1;
		}
	}
	lua_newtable(L);
	return 1;
}

int CLuaManager::L_SaveTable(lua_State *L)
{
	if (lua_isstring(L, 1) && lua_istable(L, 2))
	{
		const char* tablename = static_cast<const char *>(lua_tostring(L, 1));
		FILE *file = NULL;
		int errorcode = fopen_s(&file, tablename, "wb");
		if (0 == errorcode && file)
		{
			BYTE *luabuffer = new BYTE[FILESIZE];
			memset(luabuffer, 0, FILESIZE * sizeof(BYTE));
			int nSeriLen = luaEx_Serialize(L, 2, luabuffer, FILESIZE);
			if (nSeriLen <= 0)
			{
				Log("serialize error:%s", lua_tostring(L,-1));
				SAFE_DELETE_ARRAY(luabuffer);
				fclose(file);
				lua_pushnumber(L, 0);
				return 1;
			}
			fwrite(luabuffer, sizeof(BYTE), nSeriLen, file);
			fclose(file);
			lua_pushnumber(L, 1);
			SAFE_DELETE_ARRAY(luabuffer);
			return 1;
		}
	}
	return 1;
}

int CLuaManager::AddEvent(int timerID, int interval, TimerCallBackFunc func/* = NULL*/, void *data/* = NULL*/, int type /*= CTimerMgr::CIRCLE*/)
{
	//重新计算timerID,便于管理,同时方便delete数据
	if (0 == timerID) timerID = ++m_nTimerID;
	return m_pManager->AddEvent(timerID, interval, func, data, type);
}

bool CLuaManager::ClrEvent(int timerID)
{
	bool ret = m_pManager->RemoveEvent(timerID);
	if (ret)
	{
		m_nTimerID--;
		if (m_nTimerID < timer_generate_lua_begin) 
			m_nTimerID = timer_generate_lua_begin;
	}
	return ret;
}

bool CLuaManager::OnLuaEvent(void *data)
{
	LUAEvent *para = static_cast<LUAEvent*>(data);
	lua_State *L = g_Script.GetLuaState();

	int num = para->m_para.size();
	char *name = para->m_func;

	PREPARE_CALL_LUA();
	for (int i = 0; i < num; i++)
	{
		LUAEventData *pedata = para->m_para[i];
		switch (pedata->type)
		{
		case LUA_TNUMBER:
			if (LUA_INTEGER(pedata->n) == pedata->n)
				lua_pushinteger(L, pedata->n);
			else
			    lua_pushnumber(L, pedata->n);
			break;
		case LUA_TSTRING:
			lua_pushstring(L, pedata->str);
			break;
		case LUA_TBOOLEAN:
			lua_pushboolean(L, pedata->n);
			break;
		default:
			lua_pushnil(L);
			break;
		}
	}
	CALL_LUA();
}

void CLuaManager::DeleteTimerData(const void *data)
{
	LUAEvent *para = const_cast<LUAEvent*>(static_cast<const LUAEvent*>(data));
	delete para;
}

LUAEvent *SetEventPara(lua_State *L)
{
	int tvalue = lua_tonumber(L, 2);
	const char* func = lua_tostring(L, 3);

	LUAEvent *para = new LUAEvent;
	if (para)
	{
		para->m_interval = tvalue;
		int funclen = strlen(func);
		para->m_func = new char[funclen + 1];
		para->m_func[funclen] = 0;
		memcpy(para->m_func, func, funclen);

		int top = lua_gettop(L);
		for (int i = 5; i <= top; i++)
		{
			LUAEventData *data = new LUAEventData;
			if (!data) break;
			switch (lua_type(L, i))
			{
			case LUA_TNUMBER:
				data->type = LUA_TNUMBER;
				data->n = lua_tonumber(L, i);
				break;
			case LUA_TSTRING:
			{
				data->type = LUA_TSTRING;
				const char* str = lua_tostring(L, i);
				int len = strlen(str);
				data->str = new char[len + 1];
				data->str[len] = 0;
				memcpy(data->str, str, len);
				break;
			}
			case LUA_TBOOLEAN:
				data->type = LUA_TBOOLEAN;
				data->n = lua_toboolean(L, i);
				break;
			default:
				data->type = LUA_TNIL;
				Log("【warning】:setevent unhandle type:%s",lua_typename(L, lua_type(L, i)));
				break;
			}

			para->m_para.push_back(data);
		}
	}

	return para;
}

int CLuaManager::L_SetEvent(lua_State *L)
{
	int t1 = lua_type(L, 1);
	// 定时器ID
	if (t1 != LUA_TNUMBER && t1 != LUA_TNIL)
	{
		Log("set event para1 not number or nil!");
		return 0;
	}
	// 时间
	if (lua_type(L, 2) != LUA_TNUMBER)
	{
		Log("set event para2 not number!");
		return 0;
	}
	// 回调函数
	if (lua_type(L, 3) != LUA_TSTRING)
	{
		Log("set event para3 not string!");
		return 0;
	}
	int timerType = 0;
	// 是否循环定时(0:循环定时 >0:只运行一次)
	if (lua_type(L, 4) == LUA_TNUMBER)
	{
		timerType = lua_tonumber(L, 2);
	}

	int timerID = 0;
	if (LUA_TNUMBER == t1)
	{
		timerID = lua_tonumber(L, 1);
		if (timerID < 0) timerID = 0;
	}

	timerID = g_Script.AddEvent(timerID, lua_tonumber(L, 2), (TimerCallBackFunc)&CLuaManager::OnLuaEvent, SetEventPara(L), timerType);
	lua_pushnumber(L, timerID);
	return 1;
}

int CLuaManager::L_ClrEvent(lua_State *L)
{
	if (lua_type(L, 1) != LUA_TNUMBER)
	{
		Log("clr event para1 not number");
		return 0;
	}

	lua_pushnumber(L, g_Script.ClrEvent(lua_tonumber(L, 1)));
	return 1;
}

int L_Dofile(lua_State *L) {
	if (lua_type(L, -1) != LUA_TSTRING) {
		Log("dofile : error arg1.");
		lua_pushnumber(L, 0);
		return 0;
	}

	const char *szFileName = static_cast<const char*>(lua_tostring(L, -1));
	if (!szFileName)
	{
		Log("dofile : error filename.");
		lua_pushnumber(L, 0);
		return 0;
	}
		
	int top = lua_gettop(L);
	if (luaL_dofile(L, szFileName) != 0)
	{
		LPCSTR str = lua_tostring(L, -1);
		if (str)
		{
			Log(str);
		}
		lua_pop(L,1);
		lua_settop(L, top);
		return 0;
	}
	lua_settop(L, top);
	lua_pushnumber(L, 1);

	return 1;
}

int L_Log(lua_State *L)
{
	const char *szLog = static_cast<const char*>(lua_tostring(L, 1));

	if (!szLog)
	{
		Log("L_Log : error szLog.");
		return 0;
	}

	//Log("%s%s","【Lua log】:",szLog);
	Log(szLog);

	return 1;
}
