#include <stdio.h>
#include <time.h>
#include <WinSock2.h>
#include "TimerMgr.h"
#include "Log.h"
#include "TimerID.h"
#include "QueueMsg.h"

#ifdef WHEEL_TIMER_LOCK
#include "KernelMgr.h"
#endif

#define TVN_BITS 6
#define TVR_BITS 8
#define TVN_SIZE (1 << TVN_BITS)
#define TVR_SIZE (1 << TVR_BITS)
#define TVN_MASK (TVN_SIZE - 1)
#define TVR_MASK (TVR_SIZE - 1)
#define OFFSET(N) (TVR_SIZE + (N) *TVN_SIZE)
#define INDEX(V, N) ((V >> (TVR_BITS + (N) *TVN_BITS)) & TVN_MASK)

#define WHEEL_NUM (TVR_SIZE + 4*TVN_SIZE)
#define DELETE_TIMERNODE(node) \
	if(node->next_ != node){ \
	    node->pre_->next_ = node->next_; \
	    node->next_->pre_ = node->pre_; \
	} \
	delete node;

//////////////////////////////////////////////////////////////////////////
CTimerNode::CTimerNode()
{
	pre_ = this;
	next_ = this;
}

CTimerNode::~CTimerNode()
{

}

void CTimerNode::InitNode(int timerID, int interval, TimerCallBackFunc func, void *data, int type)
{
	holdtime_ = interval + CTimerMgr::GetNowTimeEx();

	timerID_ = timerID;
	interval_ = interval;
	func_ = func;
	data_ = data;
	type_ = type;
}

#ifdef WHEEL_TIMER_LOCK
CTimerMgr::CTimerMgr(IKernelMgr *pKernelMgr)
:minTimerID_(timer_generate_begin)
{
	timerNode_ = new CTimerNode[WHEEL_NUM];
	runNums_ = GetNowTimeEx();
	pKernelMgr_ = pKernelMgr;
}
#endif
CTimerMgr::CTimerMgr()
:minTimerID_(timer_generate_begin)
{
	timerNode_ = new CTimerNode[WHEEL_NUM];
	runNums_ = GetNowTimeEx();
}

CTimerMgr::~CTimerMgr()
{
	if (timerNode_)
	{
		RemoveAllEvent();
		delete[]timerNode_;
	}
}

void CTimerMgr::RunEvent()
{
#ifdef WHEEL_TIMER_LOCK
	CLockMgr LockMgr(&timerLock_);
#endif
	unsigned long long now = GetNowTimeEx();
	while (runNums_ <= now)
	{
		int index = runNums_ & TVR_MASK;
		if (!index &&
			!Cascade(OFFSET(0), INDEX(runNums_, 0)) &&
			!Cascade(OFFSET(1), INDEX(runNums_, 1)) &&
			!Cascade(OFFSET(2), INDEX(runNums_, 2)))
		{
			Cascade(OFFSET(3), INDEX(runNums_, 3));
		}
		++runNums_;
		HandleNode(index);
	}
}

int CTimerMgr::AddEvent(int timerID, int interval, TimerCallBackFunc func/* = NULL*/, void *data/* = NULL*/, int type/* = CIRCLE*/)
{
	if (timerID < 0 && NULL == func)
	{
		Log("add event err.");
		return 0;
	}
		
	if (0 == timerID)
	{
		if ((timerID = GenerateTimerID()) == 0)
			return 0;
	}

	if (interval < WHEEL_TIMER_TICK) interval = WHEEL_TIMER_TICK;
	interval = (interval + WHEEL_TIMER_TICK / 2) / WHEEL_TIMER_TICK;

	CTimerNode *node = new CTimerNode();
	node->InitNode(timerID, interval, func, data, (int)type);
	timerIDmap_.insert(pair<int, int>(timerID, (int)node));
	AddNode(node);
	return timerID;
}

void CTimerMgr::OnEvent(int timerID)
{
	Log(LOG_THREAD, "-----OnEvent timerID = ¡¾%d¡¿---- time(0)=¡¾%d¡¿", timerID, GetTickCount());
}

bool CTimerMgr::RemoveEvent(int timerID)
{
#ifdef WHEEL_TIMER_LOCK
	CLockMgr LockMgr(&timerLock_);
#endif

	std::unordered_map<int, int>::iterator it = timerIDmap_.find(timerID);
	if (timerID > 0 && it != timerIDmap_.end())
	{
		CTimerNode *node = (CTimerNode *)(it->second);
		timerIDmap_.erase(timerID);

		if (timerID >= timer_generate_lua_begin)
		{
#ifdef WHEEL_TIMER_LOCK
			pKernelMgr_->GetNormalQueue()->AddData((char*)node->data_, sizeof(void*), QMD_DELETE_TIMERDATA);
#endif
		}
		else if (timerID > timer_generate_begin && timerID < timer_generate_lua_begin)
		{
			minTimerID_--;
		}

		DELETE_TIMERNODE(node);
		return true;
	}
	return false;
}

void CTimerMgr::RemoveAllEvent()
{
#ifdef WHEEL_TIMER_LOCK
	CLockMgr LockMgr(&timerLock_);
#endif

	std::unordered_map<int, int>::iterator it = timerIDmap_.begin();
	for (; it != timerIDmap_.end(); )
	{
		CTimerNode *node = (CTimerNode *)(it++->second);
		RemoveEvent(node->timerID_);
	}
	minTimerID_ = timer_generate_begin;
}

bool CTimerMgr::IsExistTimerID(int timerID)
{
#ifdef WHEEL_TIMER_LOCK
	CLockMgr LockMgr(&timerLock_);
#endif
	if (timerID > 0 && timerIDmap_.find(timerID) != timerIDmap_.end())
	{
		return true;
	}
	return false;
}

unsigned long long CTimerMgr::GetNowTime()
{
#ifdef _MSC_VER
	_timeb timebuffer;
	_ftime_s(&timebuffer);
	unsigned long long ret = timebuffer.time;
	ret = ret * 1000 + timebuffer.millitm;
	return ret;
#else
	timeval tv;
	::gettimeofday(&tv, 0);
	unsigned long long ret = tv.tv_sec;
	return ret * 1000 + tv.tv_usec / 1000;
#endif
}

unsigned long long CTimerMgr::GetNowTimeEx()
{
	return (GetNowTime() / WHEEL_TIMER_TICK)/* * WHEEL_TIMER_TICK*/;
}

void CTimerMgr::AddNode(CTimerNode* node)
{
#ifdef WHEEL_TIMER_LOCK
	CLockMgr LockMgr(&timerLock_);
#endif
	unsigned long long holdtime = node->holdtime_;
	unsigned long long left = holdtime - runNums_;
	int index = 0;

	if (left < TVR_SIZE)
	{
		index = holdtime & TVR_MASK;
	}
	else if (left < 1 << (TVR_BITS + TVN_BITS))
	{
		index = OFFSET(0) + INDEX(holdtime, 0);
	}
	else if (left < 1 << (TVR_BITS + 2 * TVN_BITS))
	{
		index = OFFSET(1) + INDEX(holdtime, 1);
	}
	else if (left < 1 << (TVR_BITS + 3 * TVN_BITS))
	{
		index = OFFSET(2) + INDEX(holdtime, 2);
	}
	else if ((long long)left < 0)
	{
		index = runNums_ & TVR_MASK;
	}
	else
	{
		if (left > 0xffffffffUL)
		{
			left = 0xffffffffUL;
			holdtime = left + runNums_;
		}
		index = OFFSET(3) + INDEX(holdtime, 3);
	}
	//Log("AddNode holetime = %lld,index=%d now index = %d node=%d", holdtime, index, runNums_&TVR_MASK, (int)node);
	CTimerNode *startNode = &timerNode_[index];
	node->pre_ = startNode->pre_;
	node->next_ = startNode;
	startNode->pre_->next_ = node;
	startNode->pre_ = node;
	//Log("AddNodestartNode,node=%d,node->next=%d,node->next->next=%d", (int)&startNode, (int)startNode->next_, (int)startNode->next_->next_);

}

int CTimerMgr::GenerateTimerID()
{
#ifdef WHEEL_TIMER_LOCK
	CLockMgr LockMgr(&timerLock_);
#endif
	while (timerIDmap_.find(minTimerID_) != timerIDmap_.end())
	{
		minTimerID_++;
		if (minTimerID_ >= timer_generate_lua_begin)
		{
			Log(LOG_THREAD, "no free timerID to use!!! now diff=%d", minTimerID_ - timer_generate_begin);
			return 0;
		}
	}

	return minTimerID_;
}

int CTimerMgr::Cascade(int offset, int index)
{
	CTimerNode *startNode = &timerNode_[offset + index];
	while (startNode->next_ != startNode)
	{
		CTimerNode *node = startNode->next_;
		node->pre_->next_ = node->next_;
		node->next_->pre_ = node->pre_;
		AddNode(node);
	}

	return index;
}

void CTimerMgr::HandleNode(int index)
{
	CTimerNode *startNode = &timerNode_[index];
	while (startNode->next_ != startNode)
	{
		CTimerNode *node = startNode->next_;
		bool flag = false;
		//remove self and self point to self
		node->pre_->next_ = node->next_;
		node->next_->pre_ = node->pre_;
		node->pre_ = node->next_ = node;

		if (CIRCLE == node->type_)
		{
			node->holdtime_ = node->interval_ + GetNowTimeEx();
			AddNode(node); flag = true;
		}

#ifdef WHEEL_TIMER_LOCK
		tagWheelTimer tagTimer;
		tagTimer.timerID = node->timerID_;
		tagTimer.func = node->func_;
		tagTimer.data = node->data_;
		tagTimer.type = node->type_;
		pKernelMgr_->GetNormalQueue()->AddData((char*)&tagTimer, sizeof(tagTimer), QMD_TIMER_DATA);
#else
		if (node->func_)
			((TimerCallBackFunc)(node->func_))(node->data_);
		else
			OnEvent(node->timerID_);

		if (false == flag)
			RemoveEvent(node->timerID_);
#endif
	}
}