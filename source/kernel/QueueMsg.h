#ifndef __QUEUEMSG_H__
#define __QUEUEMSG_H__
#include  "lock.h"
#pragma warning(1:4519)

//普通双向链表队列
template<typename TYPE, typename ARG_TYPE = const TYPE&>
class CQueueList
{
protected:
	struct CNode
	{
		CNode* pPrev;
		CNode* pNext;
		TYPE   data;
	};
	CNode*     m_pNodeHead;
	CNode*     m_pNodeTail;
	DWORD      m_dwCount;

public:
	CQueueList();
	~CQueueList();
public:
	DWORD  GetCount() const;
	void   Clear();

	//分配CNode
	bool  PUSHTail(ARG_TYPE newElement);

	//释放CNode(delete CNode)
	TYPE  POPHead();

	//加入一个节点
	void  AddTail(void *node);

	//释放CNode(不delete CNode)
	void* RemoveHead();

	//访问CNode
	TYPE  operator[](const DWORD key);
};







struct tagQueueData
{
	BYTE           byQueueType;   //队列类型
	WORD           wDBType;       //数据库类型
	DWORD          dwSize;        //pQueueData大小

	ULLONG         llConnectID;   //连接ID
	const void    *pData;         //源数据指针

	char           pQueueData[];  //队列数据
};


//队列基类
class CQueueBase
{
protected:
	HANDLE                                    QueueIOCP_;      //队列端口
public:
	CQueueBase();
	virtual ~CQueueBase();
	void    SetLimitSize(DWORD dwLimitSize);
	void    SetQueueIOCP(HANDLE hIOCP);
protected:
	tagQueueData*   AddData(ULLONG llConnectID, const void* pData, DWORD dwSize, BYTE byQueueType, WORD wDBType = 0);
	tagQueueData*   AddDataOld(DWORD dwMainID, DWORD dwSubID, const void* pData, DWORD dwSize, BYTE byQueueType);
	tagQueueData*   AddData(const void* pData, DWORD dwSize, BYTE byQueueType);
	tagQueueData*   AddData(ULLONG llConnectID, BYTE byQueueType);
};


//消息队列
class CQueueMsg:public CQueueBase
{
private:
	CLock                                     QueueLock_;      //队列锁
	CQueueList<tagQueueData*, tagQueueData*>  QueueList_;      //队列表
public:
	CQueueMsg();
	~CQueueMsg();
	bool   AddData(ULLONG llConnectID, const void* pData, DWORD dwSize, BYTE byQueueType, WORD wDBType = 0);
	bool   AddDataOld(DWORD dwMainID, DWORD dwSubID, const void* pData, DWORD dwSize, BYTE byQueueType);
	bool   AddData(const void* pData, DWORD dwSize, BYTE byQueueType);
	bool   AddData(ULLONG llConnectID, BYTE byQueueType);
	bool   GetData(tagQueueData* pData, DWORD dwSize);
};


/************************************************************************/
/* 给队列加一个最大限制，防止用户恶意攻击，造成服务器队列超大，以至于内存消耗严重
   且数据越堆越多，造成正常用户无法正常操作，最终崩服。
*/
/************************************************************************/

//无锁队列
class CLockFreeQueue
{
public:
	DWORD   dwHead_;
	DWORD   dwTail_;
	DWORD   dwSize_;
	void    **ppBuf_;
public:
	CLockFreeQueue(DWORD dwSize);
	~CLockFreeQueue();
};

class CLockFreeMgr:public CQueueBase
{
private:
	CLock            QueueLock_;                                 //队列锁
	DWORD            dwLimitSize_;                               //限制容量
	CLockFreeQueue  *pLockFreeQueue_;                            //队列结构

public:
	CLockFreeMgr();
	~CLockFreeMgr();
private:
	bool   PUSHBack(void *data);
	void*  POPFront();
public:
	void   SetLimitSize(DWORD dwLimitSize);
	bool   AddData(ULLONG llConnectID, const void* pData, DWORD dwSize, BYTE byQueueType, WORD wDBType = 0);
	bool   AddDataOld(DWORD dwMainID, DWORD dwSubID, const void* pData, DWORD dwSize, BYTE byQueueType);
	bool   AddData(const void* pData, DWORD dwSize, BYTE byQueueType);
	bool   AddData(ULLONG llConnectID, BYTE byQueueType);
	bool   GetData(tagQueueData* pData, DWORD dwSize);
};

#endif