#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include  <iostream>
using namespace std;

template<class T>
class TSingleton
{
public:
	static T* InstancePtr()
	{
		if (NULL == instance_)
			instance_ = new T;
		return instance_;
	}

	static T&  Instance()
	{
		if (NULL == instance_)
			instance_ = new T;
		return *instance_;
	}

	static void ExitInstance()
	{
		if (instance_ != NULL)
		{
			delete instance_;
			instance_ = NULL;
		}
	}
protected:
	TSingleton(){}
	//µ÷ÓÃExitInstanceÎö¹¹
	virtual ~TSingleton(){}

private:
	static T* instance_;
};
template<class T>
T* TSingleton<T>::instance_ = NULL;


template<class T>
class CNoInherit
{
	friend T;
private:
	CNoInherit(){}
	virtual ~CNoInherit(){}
};


#endif