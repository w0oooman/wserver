#ifndef __COMMONLIST_H__
#define __COMMONLIST_H__
#include "define.h"


//双向环形链表
template<typename TYPE>
class CDoubleRingList
{
private:
	struct CDRingList
	{
		CDRingList *pre_;
		CDRingList *next_;
		TYPE        data_;
	};
private:
	CDRingList  head_;
	DWORD       count_;
public:
	CDoubleRingList()
	{
		head_.pre_ = head_.next_ = &head_;
		count_ = 0;
	}
	virtual ~CDoubleRingList()
	{
		Clear();
	}
public:
	void PUSHBack(TYPE data)
	{
		CDRingList* node = new CDRingList;
		node->data_ = data;
		node->next_ = &head_;
		node->pre_ = head_.pre_;
		head_.pre_->next_ = node;
		head_.pre_ = node;
		count_++;
	}
	bool POPFront(TYPE* data)
	{
		if (&head_ == head_.next_)
		{
			return false;
		}

		CDRingList* node = head_.next_;
		node->next_->pre_ = &head_;
		head_.next_ = node->next_;
		*data = node->data_;
		delete node;
		count_--;
		return true;
	}
	bool POPFront()
	{
		if (&head_ == head_.next_)
		{
			return false;
		}

		CDRingList* node = head_.next_;
		node->next_->pre_ = &head_;
		head_.next_ = node->next_;
		delete node;
		count_--;
		return true;
	}
	bool Front(TYPE* data)
	{
		if (&head_ == head_.next_)
		{
			return false;
		}

		*data = head_.next_->data_;
		return true;
	}
	bool FrontPData(TYPE** data)
	{
		if (&head_ == head_.next_)
		{
			return false;
		}

		*data = &head_.next_->data_;
		return true;
	}
	DWORD GetCount()
	{
		return count_;
	}
	void Clear()
	{	
		//if (typeid(TYPE).name() == typeid(char*).name())
		while (POPFront());
		count_ = 0;
	}
};





//单向环形链表
template<typename TYPE>
class CSingleRingList
{
private:
	struct CSRingList
	{
		CSRingList *next_;
		TYPE        data_;
	};
private:
	CSRingList  head_;
	CSRingList *tail_;
	DWORD       count_;
public:
	CSingleRingList()
	{
		head_.next_ = &head_;
		tail_ = &head_;
		count_ = 0;
	}
	virtual ~CSingleRingList()
	{
		Clear();
	}
public:
	void PUSHBack(TYPE data)
	{
		CSRingList* node = new CSRingList;
		node->data_ = data;
		tail_->next_ = node;
		node->next_ = &head_;
		tail_ = node;
		count_++;
	}
	bool POPFront(TYPE* data)
	{
		if (&head_ == head_.next_)
		{
			return false;
		}

		CSRingList* n_node = head_.next_;
		CSRingList* nn_node = n_node->next_;
		head_.next_ = nn_node;
		*data = n_node->data_;
		count_--;
		if (0 == count_) tail_ = &head_;
		delete n_node;
		return true;
	}
	bool POPFront()
	{
		if (&head_ == head_.next_)
		{
			return false;
		}

		CSRingList* n_node = head_.next_;
		CSRingList* nn_node = n_node->next_;
		head_.next_ = nn_node;
		count_--;
		if (0 == count_) tail_ = &head_;
		delete n_node;
		return true;
	}
	DWORD GetCount()
	{
		return count_;
	}
	void Clear()
	{
		while (POPFront());
		count_ = 0;
	}
};

#endif