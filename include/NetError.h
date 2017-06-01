#ifndef __NETERROR_H__
#define __NETERROR_H__
#include  <string>
#include  "define.h"
using namespace std;

class KERNEL_ENGINE_CLASS CNetErr
{
private:
	string m_strErrorinfo;
public:
	//自己生成错误
	CNetErr(string strErrorinfo);
	//半自动生成错误
	CNetErr(string strErrorinfo, bool bIsJoin);
	//自动生成错误
	CNetErr();
	~CNetErr();
private:
	int  GetErrorID();
	void SetErrorinfo();
public:
	string GetErrText(){ return m_strErrorinfo; }
	operator string();
	operator char*();

};

#endif