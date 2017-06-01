#ifndef __LOCK__H__
#define __LOCK__H__

#ifdef _MSC_VER
#include <WinSock2.h>
#else
#include <atomic.h>
#endif
#include "define.h"
#include "KernelDefine.h"

class KERNEL_ENGINE_CLASS CLock
{
private:
#ifdef _MSC_VER
	CRITICAL_SECTION  cs_;
#else
#endif

public:
	CLock();
	~CLock();

	//阻塞
	inline void Lock();

	//非阻塞,可进入返回true
	inline bool TryLock();

	inline void UnLock();
};        

class KERNEL_ENGINE_CLASS CLockMgr
{
private:
	UINT    nLockCount_;
	CLock*  pLock_;
public:
	/*bAuto为真则自动调用Lock(),不需要单独调用Lock()
	  而析构时不管bAuto值为多少,锁释放数量不为0都会
	  调用UnLock().
	*/
	CLockMgr(CLock* pLock, bool bAuto = true);
	~CLockMgr();
	void Lock();
	void UnLock();
};

#endif