#ifndef __TIMERMGR_H__
#define __TIMERMGR_H__
#include <unordered_map>
#ifdef _MSC_VER
# include <sys/timeb.h>
#else
# include <sys/time.h>
#endif

#include "lock.h"
#ifdef WHEEL_TIMER_LOCK
#include "IKernelMgr.h"
class IKernelMgr;
#endif

using namespace std;

#define WHEEL_TIMER_TICK   50  //最小单位(ms)
typedef void (*TimerCallBackFunc)(void *);


class CTimerMgr;
class CTimerNode
{
	friend CTimerMgr;
public:
	CTimerNode();
	~CTimerNode();
private:
	CTimerNode *pre_;
	CTimerNode *next_;

	unsigned long long holdtime_;
	
	int   timerID_;
	int   interval_;
	TimerCallBackFunc func_;
	void *data_;
	int   type_;
public:
	void InitNode(int timerID, int interval, TimerCallBackFunc func, void *data, int type);
};

class KERNEL_ENGINE_CLASS CTimerMgr
{
public:
	CTimerMgr();
	~CTimerMgr();

#ifdef WHEEL_TIMER_LOCK
public:
	CTimerMgr(IKernelMgr *pKernelMgr);
private:
	CLock       timerLock_;
	IKernelMgr *pKernelMgr_;
#endif

private:
	std::unordered_map<int, int>   timerIDmap_;
	//every node is a ring list.
	CTimerNode  *timerNode_;
	int   minTimerID_;
	unsigned long long runNums_;
public:
	enum eTimerType
	{
		CIRCLE = 0,
		ONCE,
	};

public:
	void  RunEvent();
	int   AddEvent(int timerID, int interval, TimerCallBackFunc func = NULL, void *data = NULL, int type = CTimerMgr::CIRCLE);
	virtual void  OnEvent(int timerID);
	bool  RemoveEvent(int timerID);
	void  RemoveAllEvent();
	bool  IsExistTimerID(int timerID);
public:
	static unsigned long long GetNowTime();
	static unsigned long long GetNowTimeEx();
private:
	void AddNode(CTimerNode* node);
	int  GenerateTimerID();
	int  Cascade(int offset, int index);
	void HandleNode(int index);
};

#endif