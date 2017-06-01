#ifndef __IDATABASE_H__
#define __IDATABASE_H__
//#include <afxmt.h>
#include <icrsint.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include<memory>
using namespace std;
#import "C:\Program Files\Common Files\System\ado\MSADO15.DLL" rename_namespace("ADOSE") rename("EOF","EndOfFile")
using namespace ADOSE;

typedef _com_error						CComError;						//COM 错误
typedef _variant_t						CDBVarValue;					//数据库数值


//输出等级
enum enTraceLevel
{
	TraceLevel_Info					=0,									//信息消息
	TraceLevel_Normal				=1,									//普通消息
	TraceLevel_Warning				=2,									//警告消息
	TraceLevel_Exception			=3,									//异常消息
	TraceLevel_Debug				=4,									//调试消息
};

//SQL 异常类型
enum enSQLException
{
	SQLException_None				=0,									//没有异常
	SQLException_Connect			=1,									//连接错误
	SQLException_Syntax				=2,									//语法错误
};

class IDataBase
{
	//连接接口
public:
	//打开连接
	virtual VOID __cdecl OpenConnection()=NULL;
	//关闭连接
	virtual VOID __cdecl CloseConnection()=NULL;
	//连接信息
	virtual bool __cdecl SetConnectionInfo(DWORD dwDBAddr, WORD wPort, LPCTSTR szDBName, LPCTSTR szUser, LPCTSTR szPassword)=NULL;
	//连接信息
	virtual bool __cdecl SetConnectionInfo(LPCTSTR szDBAddr, WORD wPort, LPCTSTR szDBName, LPCTSTR szUser, LPCTSTR szPassword)=NULL;

	//参数接口
public:
	//清除参数
	virtual VOID __cdecl ClearParameters()=NULL;
	//获取参数
	virtual VOID __cdecl GetParameter(LPCTSTR pszParamName, CDBVarValue & DBVarValue)=NULL;
	//插入参数
	virtual VOID __cdecl AddParameter(LPCTSTR pszName, DataTypeEnum Type, ParameterDirectionEnum Direction, LONG lSize, CDBVarValue & DBVarValue)=NULL;

	//控制接口
public:
	//切换记录
	virtual VOID __cdecl NextRecordset()=NULL;
	//关闭记录
	virtual VOID __cdecl CloseRecordset()=NULL;
	//绑定对象
	virtual VOID __cdecl BindToRecordset(CADORecordBinding * pBind)=NULL;

	//记录接口
public:
	//往下移动
	virtual VOID __cdecl MoveToNext()=NULL;
	//移到开头
	virtual VOID __cdecl MoveToFirst()=NULL;
	//是否结束
	virtual bool __cdecl IsRecordsetEnd()=NULL;
	//获取数目
	virtual LONG __cdecl GetRecordCount()=NULL;
	//返回数值
	virtual LONG __cdecl GetReturnValue()=NULL;
	//获取数据
	virtual VOID __cdecl GetRecordsetValue(LPCTSTR pszItem, CDBVarValue & DBVarValue)=NULL;

	//控制接口
public:
	//存储过程
	virtual VOID __cdecl ExecuteProcess(LPCTSTR pszSPName, bool bRecordset)=NULL;
	//执行语句
	virtual VOID __cdecl ExecuteSentence(LPCTSTR pszCommand, bool bRecordset)=NULL;
};

//数据库异常
class IDataBaseException
{
public:
	//异常代码
	virtual HRESULT __cdecl GetExceptionResult()=NULL;
	//异常描述
	virtual LPCTSTR __cdecl GetExceptionDescribe()=NULL;
	//异常类型
	virtual enSQLException __cdecl GetExceptionType()=NULL;
};

#endif