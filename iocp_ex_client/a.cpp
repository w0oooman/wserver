#include "lock.h"
 
CLockMgr::CLockMgr(CCriSec* pCriSec,bool bAuto/*=true*/)
{
	nLockCount_=0;
	pCriSec_=pCriSec;
	if(bAuto)  Lock();
}

CLockMgr::~CLockMgr()
{
	if(pCriSec_) 
	{
		while(nLockCount_>0)
		    UnLock();
		pCriSec_=NULL;
	}
}

void CLockMgr::Lock()
{
	if(pCriSec_)
	{
		nLockCount_++;
		pCriSec_->Lock();
	}
}

void CLockMgr::UnLock()
{
	if(pCriSec_)
	{
		nLockCount_--;
		pCriSec_->UnLock();
	}
}                                                 #include <iostream>
#include "netError.h"
#include "NetMgr.h"
#include "WSAInit.h"
#include "define.h"
using namespace std;
 
void getServerIp(char* ipAddr,int nLen);
bool Unicode2Mulbytes(char* pDest,wchar_t *pSrc);

int main()
{
	try
	{
		CWSAInit::InstancePtr()->WSAInit();



		CNetMgr  NetMgr;
		char szIP[50]={0};
		getServerIp(szIP,sizeof(szIP));
		NetMgr.Init(szIP,SERVER_PORT);
		cout<<"connecting..."<<endl;
		NetMgr.Start();
		cout<<"connect success!"<<endl;

		
		while(1) Sleep(200);

		CWSAInit::InstancePtr()->WSAUnInit();
		CWSAInit::ExitInstance();

	}
	catch(CNetErr &err){cout<<(char*)err<<endl;}
	catch(...){}
	system("pause");
	return 0;
}


void getServerIp(char* ipAddr,int nLen)
{
	try
	{
		TCHAR ipW[50];
		memset(ipW,0,sizeof(ipW));

		TCHAR BytesW[MAX_PATH];
		memset(BytesW,0,sizeof(BytesW));
		//int nNum=::GetCurrentDirectory(MAX_PATH,BytesW);         //如果在调试,获取的路径是工程路径不是exe路径(虽然也可以把config.ini拷到工程路径,但不智能)
		int nNum=::GetModuleFileName(NULL,BytesW,MAX_PATH);
		if(0==nNum)
			throw CNetErr("get server ip failed!");

		for(int i=lstrlen(BytesW);i>0;i--)
		{
			if(TEXT('\\')==BytesW[i-1])
			{
				BytesW[i-1]='\0';
				break;
			}
		}
		lstrcat(BytesW,TEXT("\\config.ini"));

		DWORD dwBytes=::GetPrivateProfileString(TEXT("server"),TEXT("serverip"),TEXT(""),ipW,nLen,/*TEXT("config.ini")*/BytesW);
		if(0==ipW[0])
		{
			char cError[100];
			memset(cError,0,sizeof(cError));
			sprintf(cError,"%s%d","get server ip failed,error id:",GetLastError());
			throw CNetErr(cError);
		}

		//if(false==Unicode2Mulbytes(ipAddr,ipW))
		//	throw CNetErr("Unicode2Mulbytes error!");
		lstrcpy(ipAddr,ipW);
	}
	catch(CNetErr&e)
	{
		cout<<(char*)e<<endl;
	}
}

bool Unicode2Mulbytes(char* pDest,wchar_t *pSrc)
{
	if(pSrc==NULL||pDest==NULL)
		return false;

	int nDestLen=WideCharToMultiByte(CP_ACP,0,pSrc,-1,NULL,0,NULL,NULL);
	if(0==nDestLen)
		return false;
	WideCharToMultiByte(CP_ACP,0,pSrc,-1,pDest,nDestLen,NULL,NULL);
}#include "NetBase.h"

#pragma comment(lib,"ws2_32.lib");
 
CNetBase::CNetBase()
{
	m_socket=INVALID_SOCKET;
	memset(&m_sockaddr,0,sizeof(m_sockaddr));
	//WSAInit();
}

CNetBase::~CNetBase()
{
	//WSAUnInit();
}

//bool CNetBase::WSAInit()
//{
//	WSADATA wsaData;
//	int error=0;
//
//	error=WSAStartup(MAKEWORD(2,0),&wsaData);
//	if( error == SOCKET_ERROR )
//	{
//		char errorBuffer[ 100 ];
//
//		error = WSAGetLastError();
//		if( error == WSAVERNOTSUPPORTED )
//		{
//			sprintf( errorBuffer, "Startup() - WSAStartup() error.\nRequested v2.0(highest v2.2), found only v%d.%d.", 
//				LOBYTE( wsaData.wVersion ),
//				HIBYTE( wsaData.wVersion ) );
//			WSACleanup();
//		}
//		else
//			sprintf( errorBuffer, "Startup() - WSAStartup() error %d", WSAGetLastError() );
//
//		throw CNetErr(errorBuffer);
//	}
//
//	return true;
//}
//
//bool CNetBase::WSAUnInit()
//{
//	WSACleanup();
//	return true;
//}

bool CNetBase::CreateSocket()
{
	if(m_socket!=INVALID_SOCKET) return false;

	m_socket=WSASocket(AF_INET,SOCK_STREAM,0,NULL,0,WSA_FLAG_OVERLAPPED);
	if(INVALID_SOCKET==m_socket)
	{
		char err[50];
		memset(err,0,sizeof(err));
		int errNum=WSAGetLastError();
		if(WSANOTINITIALISED==errNum)
			sprintf(err,"%s","CreatePlapped()---socket isn't initialised!");
		else
			sprintf(err,"%s","CSocketS::CreatePlapped()---create socket error!");
		throw CNetErr(err);
	}

	return true;
}

bool  CNetBase::Connect()
{
	if(INVALID_SOCKET==m_socket)
		throw("socket not created or created failed!");

	int nConnect=connect(m_socket,(sockaddr*)&m_sockaddr,sizeof(m_sockaddr));
	if(SOCKET_ERROR==nConnect)
	{
		closesocket(m_socket);
		int err=WSAGetLastError();
		switch(err)
		{
		case WSAEADDRINUSE:
			throw CNetErr("the addr is using!");break;
		case WSAECONNREFUSED:
			throw CNetErr("connect is refused by server!");break;
		case WSAEAFNOSUPPORT:
			throw CNetErr("sin_familly is not right!");break;
		default:
			throw CNetErr("connect failed!");break;		 
		}
		return false;
	}
	return true;
}


#include "NetMgr.h"
#include "define.h"
#include <process.h>
#include <iostream>
using namespace std;
 
CNetMgr::CNetMgr()
{
    srand(GetTickCount());
	memset(szSendbuf_,0,sizeof(szSendbuf_));
	memset(szRecvBuf_,0,sizeof(szRecvBuf_));
	dwSendLen_=0;
	dwRecvLen_=0;
	dwCheckCode_=0;
}

CNetMgr::~CNetMgr()
{

}

bool CNetMgr::Init(LPCTSTR lpIP,USHORT usPort)
{
	if(NULL==lpIP) return false;

	sockaddr_in addr;
	addr.sin_addr.S_un.S_addr=inet_addr(lpIP);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(usPort);
	SetSockAddr(addr);

	return true;
}

bool CNetMgr::Start()
{
	if(!CreateSocket()) return false;
	if(!Connect())      return false;

	//创建收发线程
	HANDLE hThread=(HANDLE)_beginthreadex(NULL,0,SendThread,this,0,NULL);
	if(NULL==hThread) throw "create send thread failed!";

	hThread=(HANDLE)_beginthreadex(NULL,0,RecvThread,this,0,NULL);
	if(NULL==hThread) throw "create recv thread failed!";


	return true;
}

unsigned int CNetMgr::SendThread(void *pData)
{
	if(NULL==pData)  return -1;

	CNetMgr *pNetMgr=(CNetMgr*)pData;

	while(1)
	{
		Sleep(10);

		BYTE byCount=rand()%20;
		WORD wSize=sizeof(NetMsgHead);

		char szSendBuf[MAX_MESSAGE_LENGTH];memset(szSendBuf,0,sizeof(szSendBuf));

		for(int i=0;i<byCount;i++)
		{
			szSendBuf[i]=rand()%26+'a';
		}

		CLockMgr LockMgr(&pNetMgr->GetSendLock());
		static int nSendNum=0;
		nSendNum++;
		if(51==nSendNum) Sleep(2000);
		if(101==nSendNum) break;

		if(1)
		{
			CLockMgr LockPrint(&pNetMgr->GetPrintLock());
			cout<<"------"<<nSendNum<<'_'<<(int)byCount<<'_'<<"------"<<szSendBuf<<endl;
		}

        pNetMgr->SendData(MMD_MESSAGE_TEST,0,0,szSendBuf,byCount);
	}
	return 0;
}


unsigned int CNetMgr::RecvThread(void *pData)
{
	if(NULL==pData)  return -1;

	CNetMgr *pNetMgr=(CNetMgr*)pData;

	while(1)
	{
		try
		{
			Sleep(1);
			pNetMgr->RecvData();
		}
		catch(...)
		{
	
		}
	}
	return 0;
}

bool CNetMgr::RecvData()
{
	int nRe=recv(GetSocket(),szRecvBuf_+dwRecvLen_,CLIENT_RCV_SIZE-dwRecvLen_,0);
	if(nRe>0||(0==nRe&&CLIENT_RCV_SIZE==dwRecvLen_))
	{
		dwRecvLen_+=nRe;
		NetMsgHead * pMsgHead=(NetMsgHead*)szRecvBuf_;
		DWORD dwMsgSize=pMsgHead->dwSize;

		while(dwRecvLen_>=sizeof(NetMsgHead)&&dwRecvLen_>=dwMsgSize)
		{
			if(dwMsgSize<sizeof(NetMsgHead)||dwMsgSize>MAX_MESSAGE_LENGTH)        throw "非法数据包!";

			OnNetMessage(szRecvBuf_,dwMsgSize);

			memmove(szRecvBuf_,szRecvBuf_+dwMsgSize,dwRecvLen_-dwMsgSize);
			dwRecvLen_-=dwMsgSize;
			dwMsgSize=pMsgHead->dwSize;
		}
	}

	return true;
}

bool CNetMgr::SendData(DWORD dwMainID,DWORD dwSubID,DWORD dwHandID)
{
	
	return true;
}

bool CNetMgr::SendData(DWORD dwMainID,DWORD dwSubID,DWORD dwHandID,char* pMsgData,DWORD dwMsgLen)
{
	if(NULL==pMsgData)  return false;

    NetMsgHead *pMsgHead=(NetMsgHead*)(szSendbuf_+dwSendLen_);
	int nSize=sizeof(NetMsgHead);
	pMsgHead->dwMainID=dwMainID;
	pMsgHead->dwSubID=dwSubID;
	pMsgHead->dwHnadID=dwHandID;
	pMsgHead->dwSize=dwMsgLen+nSize;
	pMsgHead->dwReserve=dwCheckCode_;

	memcpy(szSendbuf_+dwSendLen_+nSize,pMsgData,dwMsgLen);
	dwSendLen_+=nSize+dwMsgLen;

	return CheckSendData();
}

bool CNetMgr::SendData(char* pAllMsgData,DWORD dwAllMsgLen)
{

	return true;
}

bool CNetMgr::CheckSendData()
{
	NetMsgHead* pMsgHead=(NetMsgHead*)szSendbuf_;
	DWORD &dwSize=pMsgHead->dwSize;

	while(dwSendLen_>sizeof(NetMsgHead))
	{
		if(dwSize<sizeof(NetMsgHead)) throw "invalid message!";
		if(dwSize>MAX_MESSAGE_LENGTH) throw "message too long!";
		if(dwSize>dwSendLen_)         throw "not full message!";

		int nRe=send(GetSocket(),szSendbuf_,dwSize,0);  //发送A包
		if(nRe>0)
		{
			int dwSizeTmp=dwSize;
			memmove(szSendbuf_,szSendbuf_+nRe,dwSendLen_-nRe);
			dwSendLen_-=nRe;

			if(nRe==dwSizeTmp)  continue;               //A包完成
			else if(nRe<dwSizeTmp)                      //A未完成
			{
				int nSendSize=dwSizeTmp-nRe;
				for(int i=0;i<5;i++)                    //继续发A包
				{
					nRe=send(GetSocket(),szSendbuf_,nSendSize,0);
					memmove(szSendbuf_,szSendbuf_+nRe,dwSendLen_-nRe);
					dwSendLen_-=nRe;

					if(nRe==nSendSize) break;
					else if(nRe>0&&nRe<nSendSize)
					{
						if(5==i) throw "send error for 5 times!";
						nSendSize-=nRe;
						Sleep(30);
					}
					else throw "send error!";
				}
			}
			else throw "send error!";
		}
	}


	return true;
}

bool CNetMgr::OnNetMessage(char* pMsgData,DWORD dwMsgLen)
{
	NetMsgHead* pNetMsg=(NetMsgHead*)pMsgData;

	char buf[MAX_MESSAGE_LENGTH+1]={0};
	memcpy(buf,pMsgData+sizeof(NetMsgHead),dwMsgLen-sizeof(NetMsgHead));
	static int nNum=0;
	if(pNetMsg->dwMainID!=MMD_LOGIN_SUCCESS)
	{
		nNum++;

		CLockMgr LockPrint(&GetPrintLock());
		cout<<"******"<<nNum<<"_"<<dwMsgLen-sizeof(NetMsgHead)<<"_******"<<buf<<endl;
	}

	switch(pNetMsg->dwMainID)
	{
	case MMD_LOGIN_SUCCESS:
		dwCheckCode_=(pNetMsg->dwReserve-MESSAGE_CHECK_CODE)/19;
	    break;
	}

	return true;
}
