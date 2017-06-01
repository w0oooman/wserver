#include "SqlServerHandle.h"
//#include "../proto_file/proto/test.pb.h"

#pragma comment(lib,"sqlserver.lib")
//#ifdef _DEBUG
//#pragma comment(lib,"../proto_file/libprotobuf_d.lib")
//#else
//#pragma comment(lib,"../proto_file/libprotobuf.lib")
//#endif

CSqlServerHandle::CSqlServerHandle()
{
	pMsgMgr_=NULL;
}

CSqlServerHandle::~CSqlServerHandle()
{
	LogAll();
	DBAide_.SetDataBase(NULL);
	if(DBAide_.GetDataBase())
		DBAide_.GetDataBase()->CloseConnection();
}

bool CSqlServerHandle::Init(CMainMgr *pMsgMgr)
{
	if(NULL==pMsgMgr) return false;

	pMsgMgr_=pMsgMgr;

	return true;
}

bool CSqlServerHandle::InitDB(CHAR * szDBAddress,WORD wDBPort,CHAR * szDBName,CHAR* szDBUser,CHAR* szDBPass)
{
	try
	{
		//if(!DBAide_.SetDataBase(pDataBase)) return false;
		if(NULL==DBAide_.GetDataBase())       return false;

		if(!(IDataBase*)(DBAide_.GetDataBase())->SetConnectionInfo(szDBAddress,wDBPort,szDBName,szDBUser,szDBPass)) 
			return false;

		DBAide_.GetDataBase()->OpenConnection();
	}
	catch (IDataBaseException * pIException)
	{
		//错误信息
		LPCTSTR pszDescribe=pIException->GetExceptionDescribe();
		//CTraceService::TraceString(pszDescribe,TraceLevel_Exception);
		return false;
	}

	return true;
}

bool CSqlServerHandle::OnMsgHandle(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType)
{
	switch (wDBType)
	{
	case db_player_login:
	{
		//处理登录

		//返回结果
		//m_pMainMgr->GetServerLogicHandlePtr()->OnLoginComplete();
	}break;
	case db_get_login_times:
	{
		return OnLoginTime(llConnectID, pData, dwSize, wDBType);
	}break;
	default:break;
	}

	return true;
}

//test whb
//#pragma pack(push,1)
struct tagMyTest
{
	int a;
	char e;
	DWORD b;
	char c[6];
	SYSTEMTIME st;
	long d;
	tagMyTest()
	{
        memset(c,0,sizeof(c));
	}
};
//#pragma pack(pop)
bool CSqlServerHandle::OnLoginTime(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType)
{
	//try
	//{
	//	//结构判断
	//	//if(dwSize!=sizeof(登陆次数结构体)) return false;

	//	DBAide_.ResetParameter();
	//	DBAide_.AddParameter(TEXT("@ByteNum"),dwSize-sizeof(NetMsgHead));

	//	//存入/访问二进制数据 test whb
	//	tagMyTest test;SYSTEMTIME st;GetLocalTime(&st);
	//	test.a = 1;test.e='e';test.b = 2;test.d = 3;memcpy(test.c,"hello",5);test.st = st;
	//	int nLen = sizeof(tagMyTest);
	//	//直接memcpy不行!!!需要先序列化再调用AddParameter才行!!
	//	//unique_ptr<CHAR> buf(new CHAR[nLen+1]);
	//	//memset(buf.get(),0,nLen+1);
	//	//memcpy(buf.get(),&test,nLen);
	//	//DBAide_.AddParameter(TEXT("@CharData"),(LPCSTR)buf.get());

	//	//CHAR *buf = new CHAR[nLen+1];
	//	//memset(buf,0,nLen+1);
	//	//memcpy(buf,(CHAR*)&test,nLen);
	//	//DBAide_.AddParameter(TEXT("@CharData"),buf);
	//	//SAFE_DELETE_ARRAY(buf)

	//	//protobuf
	//	GOOGLE_PROTOBUF_VERIFY_VERSION;
	//	CMyTest mytest;
	//	mytest.set_a(1);
	//	mytest.set_b(2);
	//	string mystr;
	//	mytest.SerializeToString(&mystr);

	//	DBAide_.AddParameter(TEXT("@CharData"),mystr.c_str());

	//	//第二个参数true表示有select返回值
	//	LONG lResultCode=DBAide_.ExecuteProcess(TEXT("SP_LoginTimes"),true);
	//	if(0==lResultCode)
	//	{
	//		Byte_Sum ByteSum;
	//		ByteSum.llByteSum=DBAide_.GetValue_LONGLONG(TEXT("ByteNum"));
	//		SYSTEMTIME stTest;
	//		DBAide_.GetValue_SystemTime(TEXT("UpdateTime"),stTest);  //访问数据库时间 whb
	//		/////访问二进制数据 whb
	//		//tagMyTest tt;
	//		//DBAide_.GetValue_String("data",(LPSTR)&tt,nLen);
	//		//protobuf
	//		TCHAR outbuf[1024]={0};
	//		DBAide_.GetValue_String("data",(LPSTR)&outbuf,0);
	//		CMyTest testout;
	//		string strout(outbuf,sizeof(outbuf)-1);  //lstrlen(outbuf)会导致数据丢失
	//		testout.ParseFromString(strout);
	//		return pMsgMgr_->OnDBHandleResult(llConnectID, &ByteSum, sizeof(ByteSum), wDBType);
	//	}
	//}
	//catch(IDataBaseException * pIException)
	//{
	//	return false;
	//}
	return true;
}


bool CSqlServerHandle::OnDBHandleResult(ULLONG llConnectID, const void* pData, DWORD dwSize, WORD wDBType)
{
	switch (wDBType)
	{
	case db_get_login_times:
	{
		return OnLoginResult(llConnectID, pData, dwSize);
	}break;
	default:break;
	}

	return true;
}


bool CSqlServerHandle::OnLoginResult(ULLONG llConnectID, const void* pData, DWORD dwSize)
{
	//char buf[MAX_MESSAGE_LENGTH] = { 0 };
	//NetMsgHead *pMsgHead = (NetMsgHead*)buf;
	//pMsgHead->dwMainID = mmd_message_test;
	//pMsgHead->dwSize = dwSize + sizeof(NetMsgHead);
	//if (dwSize > 0) memcpy(buf + sizeof(NetMsgHead), pData, dwSize);

	//pMsgMgr_->SendData(dwIndex, buf, pMsgHead->dwSize, dwRoundIndex);

	//static DWORD dwTime = 0;
	//static int nCount = 0; Byte_Sum* pByteSum = (Byte_Sum*)pData;
	//nCount++; if (1 == nCount) dwTime = GetTickCount();
	////cs.Lock();
	//std::cout << "-----总包" << nCount << "__socket index__" << dwIndex << "__包大小__" << pMsgHead->dwSize - sizeof(NetMsgHead) << '_' << "-----" << pByteSum->llByteSum/*(char*)pData*/ << std::endl;
	//if (2000 == nCount) cout << "time:" << GetTickCount() - dwTime << endl;
	////cs.UnLock();


	return true;
}
