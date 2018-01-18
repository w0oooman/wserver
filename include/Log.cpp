#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include "Log.h"
#include "define.h"

using namespace std;

#define WRITELEN           1024  //存到多长就写一次文件
#define WRITETIME          3     //写一次文件的时间间隔
#define WRILELOG_TIMES     10    //写文件达到次数则关闭一次文件

#define OUTEST_FOLDER "LOGS"     //最外层文件夹名字


#include "lock.h"
CLock    g_lock;
#define  LOG_LOCK() CLockMgr lockMgr(&g_lock);
#define  LOG_UNLOCK()

//#define  LOG_LOCK()
//#define  LOG_UNLOCK()


const char* GetStringTime()
{
	static char buffer[64];

	SYSTEMTIME s;
	GetLocalTime(&s);

	sprintf_s(buffer, "%d-%02d-%02d %02d:%02d:%02d", s.wYear, s.wMonth, s.wDay, s.wHour, s.wMinute, s.wSecond);

	return buffer;
}

const char* GetStringDayTime()
{
	static char buffer[64];

	SYSTEMTIME s;
	GetLocalTime(&s);

	sprintf_s(buffer, "%s/【%d-%02d-%02d】", OUTEST_FOLDER, s.wYear, s.wMonth, s.wDay);

	return buffer;
}

class CFileHandle
{
private:
	int m_nWriteTimes;
private:
	ofstream   m_stream;
	char       m_file[MAX_PATH];
public:
	char        m_buf[LOG_MAXBUFFEREX];
	__int64     m_time;
	DWORD       m_len;
public:
	CFileHandle()
	{
		m_time = 0;
		m_len = 0;
		m_nWriteTimes = 0;
	}
	virtual ~CFileHandle()
	{
		if (m_stream.is_open())
		{
			if (m_len){
				WriteLog(true);
			}
			m_stream.close();
		}	
	}

public:
	void init(const char* filename, const char* dir)
	{
		//使用dir : 开服使用文件夹
		//使用folder: 每天使用文件夹
		sprintf_s(m_file, sizeof(m_file), "%s/%s", dir, filename);
	}

	void open()
	{
		if (m_stream.is_open()){
			m_stream.close();
		}
		m_stream.open(m_file, ios::app);

#ifdef _MSC_VER
		SetLastError(0);//〖183〗-当文件已存在时，无法创建该文件
#else
#endif
	}

	void Write()
	{
		m_stream << m_buf;
		m_stream.flush();
		m_len = 0;

		/*
		注意几种特殊情况printf的结果:
		Log("%d 20%% 100%%", 777); -> 过滤后:777 20% 100% -> 打印结果:777 20%
		Log("%d 20%%q100%%", 888); -> 过滤后:888 20%q100% -> 打印结果:888 20q100
		*/
		printf(m_buf);  //whb
	}

	BOOL WriteLog(bool bIsLogAll)
	{
		if (!m_stream.is_open())
		{
			open();
		}

		if (m_stream.is_open())
		{
			Write();
			if (++m_nWriteTimes >= WRILELOG_TIMES || bIsLogAll) //whb
			{
				m_nWriteTimes = 0;
				m_stream.close();
			}
		}
		return TRUE;
	}
};

class CFileHandleMgr
{
public:
	CFileHandleMgr(){
		//所有记录的外层目录
		if (_access(OUTEST_FOLDER, 0) == -1)
		{
			if (0 != _mkdir(OUTEST_FOLDER))
			{
#ifdef _MSC_VER
				CreateDirectory(OUTEST_FOLDER, 0);
				GetLastError();
#endif
			}
		}

		const char* folder = GetStringDayTime();
		bool flag = true;
		if (_access(folder, 0) == -1)
		{
			if (0 != _mkdir(folder))
			{
#ifdef _MSC_VER
				CreateDirectory(folder, 0);
				GetLastError();
#endif
			}
		}

		m_log = new CFileHandle();
		m_log->init("log.txt", folder);

		m_thread = new CFileHandle();
		m_thread->init("thread.txt", folder);

		m_debug = new CFileHandle();
		m_debug->init("debug.txt", folder);

		m_db = new CFileHandle();
		m_db->init("db.txt", folder);

		m_dserver = new CFileHandle();
		m_dserver->init("dserver.txt", folder);

		m_dclient = new CFileHandle();
		m_dclient->init("dclient.txt", folder);
	}
	virtual ~CFileHandleMgr(){
		SAFE_DELETE(m_log);
		SAFE_DELETE(m_thread);
		SAFE_DELETE(m_debug);
		SAFE_DELETE(m_db);
		SAFE_DELETE(m_dserver);
		SAFE_DELETE(m_dclient);
	}
public:
	CFileHandle *m_log;    //放在某文件中
	CFileHandle *m_thread; //多线程
	CFileHandle *m_debug;  //放在另一个文件
	CFileHandle *m_db;
	CFileHandle *m_dserver;//分布式 服务端
	CFileHandle *m_dclient;//分布式 客户端
};

CFileHandleMgr __LogMgr;  //缺点:占用有限的栈内存!!
static char    __szFormatBuff[LOG_MAXBUFFER];

BOOL Log_Logic(CFileHandle *handle, const char* szFormat, va_list header, bool bIsLogAll)
{
	BOOL ret = FALSE;
	int lentemp = strlen("\r");
	DWORD &len = handle->m_len;
	time_t NowTime = ::time(0);

	if (NowTime >= handle->m_time + 1)
	{
		const char* temp = "=>";
		const char* timeptr = GetStringTime();
		int value = LOG_MAXBUFFER - len - lentemp * 3;
		sprintf_s(handle->m_buf + len, value > 0 ? value : 0, "%s%s\n", temp, timeptr);
		len += strlen(handle->m_buf + len);
		handle->m_time = NowTime;
	}

	//filter
	int nFormatLen = min(strlen(szFormat), LOG_MAXBUFFER - 1);
	memcpy(__szFormatBuff, szFormat, nFormatLen);
	__szFormatBuff[nFormatLen] = 0;
	//LogFilter((char*)__szFormatBuff, nFormatLen);

	int value = LOG_MAXBUFFER - len - lentemp * 3;
	//vsprintf_s(handle->m_buf + len, value > 0 ? value : 0, __szFormatBuff, header);
	//vsnprintf_s(handle->m_buf + len, value > 0 ? value : 0, _TRUNCATE, __szFormatBuff, header);
	/* 发现使用_vsnprintf函数,当传入非法format参数时不会有问题,因此不用调用LogFilter.还不清楚原理!!注:需预定义_CRT_SECURE_NO_WARNINGS */ 
	_vsnprintf(handle->m_buf + len, value > 0 ? value : 0, __szFormatBuff, header);

	len = strlen(handle->m_buf);
	handle->m_buf[len] = '\n'; len += lentemp;
	handle->m_buf[len] = '\0';

	//if (NowTime >= handle->m_time + WRITETIME || len >= WRITELEN)  //超过一定时间 或 数据到达一定长度 就存一次文件  //whb
	{
		ret = handle->WriteLog(bIsLogAll);
	}

	return ret;
}

CFileHandle *GetHandleByType(char type)
{
	CFileHandle *handle = NULL;

	switch (type)
	{
	case LOG_NORMAL:
	{
		handle = __LogMgr.m_log;
	}break;
	case LOG_THREAD:
	{
		handle = __LogMgr.m_thread;
	}break;
	case LOG_DEBUG:
	{
		handle = __LogMgr.m_debug;
	}break;
	case LOG_DB:
	{
		handle = __LogMgr.m_db;
	}break;
	case LOG_DSERVER:
	{
		handle = __LogMgr.m_dserver;
	}break;
	case LOG_DCLIENT:
	{
		handle = __LogMgr.m_dclient;
	}break;
	default:
		break;
	}

	return handle;
}

//应该注意的是,这里使用的是变长参数,当类似于这种：Log("%d 100%.", 10);
//会导致程序崩溃,应该成Log("%d 100%%.", 10);但是某些返回错误值很难避免
//这种情况,比如mysql连接时返回错误"execute command denied to user 'sa'@'%' for"
//则同样会崩溃,可以在Log函数中对这种非法情况统一判断,但是消耗太大,现在先暂时在
//mysql中进行特殊处理下?以后可以把LOG独立成一个单独的服务器，则即使崩溃了也不
//影响在线用户!!
BOOL Log(const char* szFormat, ...)
{
	va_list header;
	va_start(header, szFormat);
	BOOL ret = Log_Logic(__LogMgr.m_log, szFormat, header, false);
	va_end(header);

	return ret;
}

BOOL Log(char type, const char* szFormat, ...)
{
	CFileHandle *handle = GetHandleByType(type);
	if (!handle) return FALSE;
	BOOL ret;

	if (LOG_THREAD == type)
	{
		LOG_LOCK();

		va_list header;
		va_start(header, szFormat);
		ret = Log_Logic(handle, szFormat, header, false);
		va_end(header);

		LOG_UNLOCK();
	}
	else
	{
		va_list header;
		va_start(header, szFormat);
		ret = Log_Logic(handle, szFormat, header, false);
		va_end(header);
	}

	return ret;
}

//保存所有未保存的数据
BOOL LogAll()
{
	for (int i = LOG_NORMAL; i < LOG_MAX; i++)
	{
		CFileHandle *handle = GetHandleByType(i);
		if (!handle) continue;

		if (handle->m_len > 0)
			handle->m_time = 0;  //确保此次能正常保存
		else
			continue;

		BOOL ret = Log_Logic(handle, "---------log all---------", (va_list)"", true);

		return ret;
	}

	return FALSE;
}


#define LOG_FILTER_STRING '*'
char LogFilterHandle(char* buffer, size_t index)
{
	char next = buffer[index];
	switch (next)
	{
	case 'd':
	case 's':
	case 'c':
	case 'f':
	case 'i':
	case 'o':
	case 'u':
	case 'x':
	case 'p':
	case 'a':
	case 'A':
	case 'C':
	case 'S':
	case 'X':
	case 'g':
	case 'G':
	case 'e':
	case 'E':
	case '%':
		break;
	default:
		buffer[index - 1] = LOG_FILTER_STRING;
		return 1;
		break;
	}

	return 0;
}

//过滤掉不合法的变长参数如"Log("%d,100%",1)"，正确应为"Log("%d,100%%",1)"，
//但此函数经处理为"Log("%d,100*",1)",避免程序在vsprintf_s类似接口处崩溃.
//以上只是预防格式参数问题但是如果出现类似Log("%d%s",123);则此函数暂时无能为力.
//还不完善,比如大于一个字节的:%I64u、%.nf、%hs等暂未处理
void LogFilter(char* buffer, size_t size)
{
	if (size > 0)
	{
		int  i    = 0;
		char flag = 0;
		for (; i < size - 1; i++)
		{
			flag = 0;
			if (buffer[i] == '%')
			{
				flag = LogFilterHandle(buffer, ++i);
			}
		}

		if (i < size)
		{
			//倒数第2个字符是'%'
			if (1 == flag)
			{
				LogFilterHandle(buffer, i);
			}
			//最后一个字符是'%'
			else if ('%' == buffer[i])
			{
				buffer[i] = LOG_FILTER_STRING;
			}
		}
	}
}



//%a       浮点数、十六进制数字和p - 记数法（Ｃ９９）
//%A　　　　浮点数、十六进制数字和p - 记法（Ｃ９９）
//%c　　　　 一个字符(char)
//% C           一个ISO宽字符
//%d　　　　有符号十进制整数(int)（%ld、%Ld：长整型数据(long), %hd：输出短整形。）　
//%e　　　　浮点数、e - 记数法
//%E　　　　浮点数、Ｅ - 记数法
//%f　　　　 单精度浮点数(默认float)、十进制记数法（%.nf  这里n表示精确到小数位后n位.十进制计数）
//%g　　　　根据数值不同自动选择％f或％e．
//%G　　　　根据数值不同自动选择％f或％e.
//%i              有符号十进制数（与％d相同）
//%o　　　　无符号八进制整数
//%p　　　   指针
//%s　　　　 对应字符串char*（%s == %hs == %hS 输出 窄字符）
//%S             对应宽字符串WCAHR*（%ws == %S 输出宽字符串）
//%u　　　   无符号十进制整数(unsigned int)
//% x　　　　使用十六进制数字０f的无符号十六进制整数　
//%X　　　   使用十六进制数字０f的无符号十六进制整数
//%%　　　  打印一个百分号
//%I64d
//用于INT64 或者 long long
//%I64u
//用于UINT64 或者 unsigned long long
//%I64x
//用于64位16进制数据

//①%：表示格式说明的起始符号，不可缺少。
//② - ：有 - 表示左对齐输出，如省略表示右对齐输出。
//③0：有0表示指定空位填0, 如省略表示指定空位不填。
//④m.n：m指域宽，即对应的输出项在输出设备上所占的字符数。n指精度。用于说明输出的实型数的小数位数。为指定n时，隐含的精度为n = 6位。
//⑤l或h : l对整型指long型，对实型指double型。h用于将整型的格式字符修正为short型