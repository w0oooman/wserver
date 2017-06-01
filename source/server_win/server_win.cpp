// server_win.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Resource.h"
#include  "dump.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SERVER_WIN, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SERVER_WIN));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SERVER_WIN));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SERVER_WIN);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



//
//
//#define MAX_LOADSTRING 100
//
//// 全局变量：
//HINSTANCE hInst;								// 当前实例
//TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
//TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名
//
//HWND hMainWnd;
//HWND hInfo;
//HWND hInput;
//
//WNDPROC OldProc;
//char InputBuffer[256] = { 0 };
//LRESULT CALLBACK ReloadEditWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//void ExplainCommand(LPCSTR szCommand);
//
//// 此代码模块中包含的函数的前向声明：
//ATOM				MyRegisterClass(HINSTANCE hInstance);
//BOOL				InitInstance(HINSTANCE, int);
//LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
//
//
//int  _tWinMain(HINSTANCE hInstance,
//	HINSTANCE hPrevInstance,
//	LPTSTR    lpCmdLine,
//	int       nCmdShow)
//{
//	//将在本目录下生成一个Exception.dmp使用windbg或者直接用vs 打开，启用调试就能定位问题
//	//SetUnhandledExceptionFilter(GPTUnhandledExceptionFilter);
//	InitMinDump();
//
//
//	MSG msg;
//	HACCEL hAccelTable;
//	{
//
//		//szIniFilename = lpCmdLine;
//		//if (szIniFilename == "")
//		//	szIniFilename = "server.ini";
//
//		//SYSTEMTIME s;
//		//GetLocalTime(&s);
//		//sprintf(szDirname, "[%d-%d-%d]", s.wYear, s.wMonth, s.wDay, (LPCSTR)szIniFilename);
//		//CreateDirectory( (LPCSTR)szDirname, NULL );
//		//strcat( szDirname, "\\" );
//
//		// 初始化全局字符串
//		//LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//		//LoadString(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
//		strcpy(szWindowClass, "xyd_zoneserver");
//		MyRegisterClass(hInstance);
//
//		// 执行应用程序初始化：
//		if (!InitInstance(hInstance, nCmdShow))
//		{
//			return FALSE;
//		}
//
//		//hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_MY);
//
//
//		CMainMgr  *__MainMgr = new CMainMgr;
//		if (!__MainMgr->Init(MAX_CLIENT_NUM, SERVER_PORT)) return Log("初始化失败.");
//		cout << "starting..." << endl;
//		if (!__MainMgr->Start()) return Log("启动失败.");
//		cout << "start finish!" << endl;
//
//
//		// 主消息循环：
//		while (true)
//		{
//			if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
//			{
//				if (GetMessage(&msg, NULL, 0, 0) == 0)
//					break;
//
//				if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//				{
//					TranslateMessage(&msg);
//					DispatchMessage(&msg);
//				}
//			}
//			else
//			{
//
//			}
//		}
//
//		SAFE_DELETE(__MainMgr);
//		share_sleep(1000);
//	}
//
//	return (int)msg.wParam;
//}
//                   
//
////
////  函数：MyRegisterClass()
////
////  目的：注册窗口类。
////
////  注释：
////
////    仅当希望在已添加到 Windows 95 的
////    “RegisterClassEx”函数之前此代码与 Win32 系统兼容时，
////    才需要此函数及其用法。调用此函数
////    十分重要，这样应用程序就可以获得关联的
////   “格式正确的”小图标。
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//	WNDCLASSEX wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);
//
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = (WNDPROC)WndProc;
//	wcex.cbClsExtra = 0;
//	wcex.cbWndExtra = 0;
//	wcex.hInstance = hInstance;
//	wcex.hIcon = LoadIcon(hInstance, (const char *)IDI_MY);
//	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = NULL;//(LPCTSTR)IDC_MY;
//	wcex.lpszClassName = szWindowClass;
//	wcex.hIconSm = LoadIcon(wcex.hInstance, (const char *)IDI_SMALL);
//
//	return RegisterClassEx(&wcex);
//}
//
////
////   函数：InitInstance(HANDLE, int)
////
////   目的：保存实例句柄并创建主窗口
////
////   注释：
////
////        在此函数中，我们在全局变量中保存实例句柄并
////        创建和显示主程序窗口。
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//
//	hInst = hInstance; // 将实例句柄存储在全局变量中
//
//	hMainWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//		0, 0, 640, 480, NULL, NULL, hInstance, NULL);
//
//	if (!hMainWnd)
//	{
//		return FALSE;
//	}
//
//	RECT rect;
//	GetClientRect(hMainWnd, &rect);
//
//#define __input_h 17
//#define __input_x 46
//
//	hInfo = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILDWINDOW | WS_VISIBLE | WS_VSCROLL | ES_READONLY | ES_MULTILINE,
//		0, 0, rect.right, rect.bottom - __input_h, hMainWnd, (HMENU)IDC_INFO, hInstance, NULL);
//
//	if (!hInfo)
//	{
//		return FALSE;
//	}
//
//	SetWindowFont(hInfo, CreateFont(12, 6, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, "新宋体"), 1);
//
//	hInput = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILDWINDOW | WS_VISIBLE,
//		__input_x, rect.bottom - __input_h, rect.right - __input_x, __input_h, hMainWnd, (HMENU)IDC_INPUT, hInstance, NULL);
//
//	if (!hInput)
//	{
//		return FALSE;
//	}
//
//	SetWindowFont(hInput, CreateFont(12, 6, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, "新宋体"), 1);
//
//	OldProc = (WNDPROC)(_W64 LONG)SetWindowLong(hInput, GWL_WNDPROC, (LONG)(_W64 LONG)ReloadEditWndProc);
//
//	SetWindowFont(CreateWindowEx(WS_EX_CLIENTEDGE, "Static", "CMD：〉", WS_CHILDWINDOW | WS_VISIBLE | SS_CENTER,
//		0, rect.bottom - __input_h, __input_x, __input_h, hMainWnd, (HMENU)IDC_INPUT, hInstance, NULL), CreateFont(12, 6, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, "新宋体"), 1);
//
//	ShowWindow(hMainWnd, nCmdShow);
//	UpdateWindow(hMainWnd);
//
//	return TRUE;
//}
//
////
////  函数：WndProc(HWND, unsigned, WORD, LONG)
////
////  目的：处理主窗口的消息。
////
////  WM_COMMAND	- 处理应用程序菜单
////  WM_PAINT	- 绘制主窗口
////  WM_DESTROY	- 发送退出消息并返回
////
////
//
//static bool echo = true;
//void AddInfo(LPCSTR Info)
//{
//	if (!echo)
//		return;
//
//	static int max_size = 0;
//
//	int size = lstrlen(Info) + 1;
//
//	int max = (int)SendMessage(hInfo, EM_GETLIMITTEXT, 0, 0);
//
//	if (max_size + size > max)
//	{
//		int curlc = (int)SendMessage(hInfo, EM_GETLINECOUNT, 0, 0);
//		int repcc = (int)SendMessage(hInfo, EM_LINEINDEX, curlc / 10, 0);
//
//		if (repcc < size)
//		{
//			repcc = -1;
//			max_size = 0;
//		}
//		else
//		{
//			max_size -= repcc;
//		}
//
//		SendMessage(hInfo, EM_SETSEL, 0, repcc);
//		SendMessage(hInfo, EM_REPLACESEL, 0, (LPARAM)"");
//	}
//
//	max_size += size;
//
//	SendMessage(hInfo, EM_SETSEL, max, max);
//	SendMessage(hInfo, EM_REPLACESEL, 0, (LPARAM)Info);
//
//	//extern dwt::stringkey<char[256]> szDirname;
//	//if (szDirname[0]) {
//	//	static std::string filename = szDirname + "run.log";
//	//	static time_t prevTick = 0;
//	//	if (prevTick != time(NULL)) {
//	//		prevTick = time(NULL);
//	//		char tickstr[64];
//	//		SYSTEMTIME s;
//	//		GetLocalTime(&s);
//	//		int len = sprintf(tickstr, "*=> %d-%02d-%02d %02d:%02d:%02d\r\n", s.wYear, s.wMonth, s.wDay, s.wHour, s.wMinute, s.wSecond);
//	//		TraceData(filename.c_str(), (LPVOID)tickstr, len);
//	//	}
//	//	TraceData(filename.c_str(), (LPVOID)Info, size - 1);
//	//}
//}