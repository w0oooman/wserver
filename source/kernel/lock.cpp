#include  "lock.h"

#ifdef _MSC_VER
CLock::CLock()
{
	//InitializeCriticalSection(&cs_);
	//旋转 2048次(据说4000比较好)。如果该临界区在旋转操作期间变为可用，该调用线程就避免了等待操作。”
	//旋转计数可以在多处理器计算机上提供更佳性能，其原因在于在一个循环中旋转通常要快于进入内核模式等待状态。
	InitializeCriticalSectionAndSpinCount(&cs_, 4000);
}
CLock::~CLock()
{ 
	DeleteCriticalSection(&cs_); 
}

//阻塞
void CLock::Lock()
{ 
	EnterCriticalSection(&cs_); 
}                         

//非阻塞
bool CLock::TryLock()                                                    
{
	if (TryEnterCriticalSection(&cs_) == 0)
		return false;
	else
		return true;
}

void CLock::UnLock()
{ 
	LeaveCriticalSection(&cs_);
}
#else
CLock::CLock()
{
}
CLock::~CLock()
{
}

//阻塞
void CLock::Lock()
{
}

//非阻塞
bool CLock::TryLock()
{
    return true;
}

void CLock::UnLock()
{
}
#endif

CLockMgr::CLockMgr(CLock* pLock, bool bAuto/*=true*/)
{
	nLockCount_ = 0;
	pLock_ = pLock;
	if(bAuto)  Lock();
}

CLockMgr::~CLockMgr()
{
	if (pLock_)
	{
		while(nLockCount_>0)
		    UnLock();
		pLock_ = NULL;
	}
}

void CLockMgr::Lock()
{
	if (pLock_)
	{
		pLock_->Lock();
		nLockCount_++;
	}
}

void CLockMgr::UnLock()
{
	if (pLock_)
	{
		nLockCount_--;
		pLock_->UnLock();
	}
}                                                 