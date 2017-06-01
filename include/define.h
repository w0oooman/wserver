#ifndef  __DEFINE__H__
#define  __DEFINE__H__

#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#include  <windows.h>
#endif
#include  "Log.h"
#include  "KernelMsg.h"

#ifdef  KERNEL_EXPORTS
#define KERNEL_ENGINE_CLASS __declspec(dllexport)
#else
#define KERNEL_ENGINE_CLASS __declspec(dllimport)
#endif

#define   USER_NAME_MIN_LEN   6   //玩家名字最小长度
#define   USER_PWD_MIN_LEN    6   //玩家密码最小长度  
#define   USER_NAME_MAX_LEN   32  //玩家名字最大长度
#define   USER_PWD_MAX_LEN    80  //玩家密码最大长度

typedef   unsigned long long    ULLONG;

#define SAFE_DELETE(p) \
{ \
	if ((p) != NULL){ \
	    try{ \
	        delete (p); \
		}\
	    catch (...){}\
	    (p) = NULL; \
	}\
}

#define SAFE_DELETE_ARRAY(p) \
{ \
	if((p)!=NULL){\
	    try{\
		    delete [](p);\
		}\
		catch(...){}\
		(p)=NULL;\
	} \
}

#define SAFE_CLOSE_HANDLE(p,num) \
	for(int i=0;i<(num);i++){\
        if(p[i]!=NULL)\
			CloseHandle(p[i]);\
	}


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX_PATH
#define MAX_PATH          260
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef VOID
#define VOID void
typedef char CHAR;
typedef short SHORT;
typedef long LONG;
#if !defined(MIDL_PASS)
typedef int INT;
#endif
#endif



#if defined _MSC_VER //windows
#define share_sleep(TimeValue) \
	Sleep((TimeValue))
#define share_srand(value) \
	srand(value)
#define share_rand() \
	rand()
#else
#define share_sleep(TimeValue) \
	usleep((TimeValue)*1000);
#define share_srand(value) \
	srandom(value)
#define share_rand() \
	random()

#define SOCKET int
#define INVALID_SOCKET (-1)
#endif

#ifdef _MSC_VER
#define Log_Position()       Log("error file=%s,line=%d,function=%s,ErrorID=%d", __FILE__, __LINE__, __FUNCTION__, GetLastError());
#define Log_ThreadPosition() Log(LOG_THREAD, "error file=%s,line=%d,function=%s,ErrorID=%d", __FILE__, __LINE__, __FUNCTION__, GetLastError());
#endif

#endif