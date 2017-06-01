#ifndef __LOG_H__
#define __LOG_H__


#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
//#define _WIN32_WINNT 0x400

// Windows 头文件：
#include <windows.h>
#include <windowsx.h>

// C 运行时头文件
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// TODO: 在此处引用程序要求的附加头
#include <commctrl.h>
#include <mmsystem.h>
#include <shlwapi.h>

#include <crtdbg.h>
#include <Shellapi.h>

#include <iostream>
#include <fstream>

#define LOG_MAXBUFFER      2048  //LOG的buf最大长度

enum LOG_TYPE
{
	LOG_NORMAL = 0,
	LOG_THREAD,
	LOG_DEBUG,
	LOG_DB,
	LOG_DSERVER,//分布式服务端
	LOG_DCLIENT,//分布式客户端

	LOG_MAX,
};

//函数对文件操作没有考虑多线程环境,所以写入某个文件时
//应该在单线程环境下!!!否则应使用LOG_THREAD参数
extern BOOL Log(const char* szFormat, ...);             //以LOG_NORMAL方式保存
extern BOOL Log(char type, const char* szFormat, ...);  //指定保存类型
extern BOOL LogAll();                                   //保存所有类型数据


//过滤掉不合法的变长参数如"Log("%d,100%",1)"，正确应为"Log("%d,100%%",1)"，
//但此函数经处理为"Log("%d,100*",1)",避免程序在vsprintf_s类似接口处崩溃.
//以上只是预防格式参数问题但是如果出现类似Log("%d%s",123);则此函数暂时无能为力.
extern void LogFilter(char* buffer, size_t size);      


#endif