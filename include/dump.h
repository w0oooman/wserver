#ifndef __DUMP_H__
#define __DUMP_H__
#include <stdlib.h>
#include <stdio.h>
#include <ostream>
#ifdef _MSC_VER
#include <windows.h>
#include <DbgHelp.h>
#pragma comment(lib, "dbghelp.lib")

#ifndef _M_IX86  
#error "The following code only works for x86!"  
#endif  

inline BOOL IsDataSectionNeeded(const WCHAR* pModuleName)
{
	if (pModuleName == 0)
	{
		return FALSE;
	}

	WCHAR szFileName[_MAX_FNAME] = L"";
	_wsplitpath_s(pModuleName, NULL, 0, NULL, 0, szFileName, _MAX_FNAME, NULL, 0);

	if (_wcsicmp(szFileName, L"ntdll") == 0)
		return TRUE;

	return FALSE;
}

inline BOOL CALLBACK MiniDumpCallback(PVOID                            pParam,
	const PMINIDUMP_CALLBACK_INPUT   pInput,
	PMINIDUMP_CALLBACK_OUTPUT        pOutput)
{
	if (pInput == 0 || pOutput == 0)
		return FALSE;

	switch (pInput->CallbackType)
	{
	case ModuleCallback:
		if (pOutput->ModuleWriteFlags & ModuleWriteDataSeg)
			if (!IsDataSectionNeeded(pInput->Module.FullPath))
				pOutput->ModuleWriteFlags &= (~ModuleWriteDataSeg);
	case IncludeModuleCallback:
	case IncludeThreadCallback:
	case ThreadCallback:
	case ThreadExCallback:
		return TRUE;
	default:;
	}

	return FALSE;
}

inline void CreateMiniDump(EXCEPTION_POINTERS* pep, LPCTSTR strFileName)
{
	HANDLE hFile = CreateFile(strFileName, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if ((hFile != NULL) && (hFile != INVALID_HANDLE_VALUE))
	{
		MINIDUMP_EXCEPTION_INFORMATION mdei;
		mdei.ThreadId = GetCurrentThreadId();
		mdei.ExceptionPointers = pep;
		mdei.ClientPointers = NULL;

		MINIDUMP_CALLBACK_INFORMATION mci;
		mci.CallbackRoutine = (MINIDUMP_CALLBACK_ROUTINE)MiniDumpCallback;
		mci.CallbackParam = 0;

		//dump信息较多
		MINIDUMP_TYPE mdt = (MINIDUMP_TYPE)(
			MiniDumpWithPrivateReadWriteMemory |
			MiniDumpWithFullMemory |
			MiniDumpWithDataSegs |
			MiniDumpWithHandleData |
			MiniDumpWithFullMemoryInfo |
			MiniDumpWithThreadInfo |
			MiniDumpWithUnloadedModules |
			MiniDumpWithIndirectlyReferencedMemory |
			MiniDumpWithFullAuxiliaryState |
			MiniDumpWithPrivateWriteCopyMemory |
			MiniDumpIgnoreInaccessibleMemory |
			MiniDumpWithTokenInformation |
			MiniDumpFilterMemory
			);
		MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
			hFile, mdt, (pep != 0) ? &mdei : 0, 0, &mci);

		//MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpNormal, (pep != 0) ? &mdei : 0, NULL, &mci);  //普通dump,小

		CloseHandle(hFile);
	}
}




std::ostream& operator<<(std::ostream& os, const EXCEPTION_RECORD& red)
{
	return os << "   Thread ID:" << GetCurrentThreadId()
		<< "   ExceptionCode: " << red.ExceptionCode << "/n"
		<< "   ExceptionFlags: " << red.ExceptionFlags << "/n"
		<< "   ExceptionAddress: " << red.ExceptionAddress << "/n"
		<< "   NumberParameters: " << red.NumberParameters;
}


LONG WINAPI GPTUnhandledExceptionFilter(PEXCEPTION_POINTERS pExceptionInfo)
{
	FILE *fp;
	fopen_s(&fp, "DumpInfo.txt", "a+");
	char buffer[256];
	sprintf_s(buffer, "%s", "   Server Dead,CreatDump!!\n");

	static char __time[1024];
	SYSTEMTIME s;
	GetLocalTime(&s);
	sprintf_s(__time, "[%d-%d-%d %d:%d:%d]", s.wYear, s.wMonth, s.wDay, s.wHour, s.wMinute, s.wSecond);

	fwrite(__time, strlen(__time), 1, fp);
	fwrite(buffer, strlen(buffer), 1, fp);
	fclose(fp);

	//StackWalker sw;
	//sw.ShowCallstack();//actionlog.txt

	CreateMiniDump(pExceptionInfo, "Exception.dmp");
	//std::cerr << "未知错误：" << (*pExceptionInfo->ExceptionRecord) << std::endl;
	//exit(pExceptionInfo->ExceptionRecord->ExceptionCode);

	return EXCEPTION_EXECUTE_HANDLER;    // 程序停止运行
}

// 此函数一旦成功调用，之后对 SetUnhandledExceptionFilter 的调用将无效  
void DisableSetUnhandledExceptionFilter()
{
	void* addr = (void*)GetProcAddress(LoadLibrary("kernel32.dll"), "SetUnhandledExceptionFilter");

	if (addr)
	{
		unsigned char code[16];
		int size = 0;
		code[size++] = 0x33;
		code[size++] = 0xC0;
		code[size++] = 0xC2;
		code[size++] = 0x04;
		code[size++] = 0x00;

		DWORD dwOldFlag, dwTempFlag;
		VirtualProtect(addr, size, PAGE_READWRITE, &dwOldFlag);
		WriteProcessMemory(GetCurrentProcess(), addr, code, size, NULL);
		VirtualProtect(addr, size, dwOldFlag, &dwTempFlag);
	}
}

void InitMinDump()
{
	//注册异常处理函数  
	SetUnhandledExceptionFilter(GPTUnhandledExceptionFilter);

	//使SetUnhandledExceptionFilter  
	DisableSetUnhandledExceptionFilter();
}
#endif
#endif