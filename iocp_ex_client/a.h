#pragma once
#include <WinSock2.h>
  
class CCriSec
{
private:
	CRITICAL_SECTION  cs_;

public:
	inline CCriSec()
	{	
		//InitializeCriticalSection(&cs_);
		//旋转 2048次。如果该临界区在旋转操作期间变为可用，该调用线程就避免了等待操作。”
		//旋转计数可以在多处理器计算机上提供更佳性能，其原因在于在一个循环中旋转通常要快于进入内核模式等待状态。
		InitializeCriticalSectionAndSpinCount(&cs_,2048);     
    }
	inline ~CCriSec(){DeleteCriticalSection(&cs_);}

	inline void Lock(){EnterCriticalSection(&cs_);}                          //阻塞

	inline bool TryLock()                                                    //非阻塞
	{	
		if(TryEnterCriticalSection(&cs_)==0)     
		    return false;
	    else
		    return true;
    }

	inline void UnLock(){LeaveCriticalSection(&cs_);}

};        

class CLockMgr
{
private:
	UINT nLockCount_;
	CCriSec*  pCriSec_;
public:
	CLockMgr(CCriSec* pCriSec,bool bAuto=true);
	~CLockMgr();
	void Lock();
	void UnLock();
};#pragma once
#include <Winsock2.h>
#include "netError.h"
 
class CNetBase
{
private:
	SOCKET       m_socket;
	sockaddr_in  m_sockaddr; 
public:
	CNetBase();
	~CNetBase();
//private:
//	bool  WSAInit();
//	bool  WSAUnInit();
public:
	virtual bool  CreateSocket();
	virtual bool  Connect();
	inline void   SetSockAddr(sockaddr_in &addr){m_sockaddr=addr;}
	inline SOCKET GetSocket(){return m_socket;}
};                                                #pragma once
#include "NetBase.h"
#include "lock.h"
#define CLIENT_SND_SIZE   20000
#define CLIENT_RCV_SIZE   20000
 
class CTCPSocket
{
public:
	CTCPSocket();
	~CTCPSocket();

public:
	bool SendData();
	bool RecvData();
};

class CNetMgr:public CNetBase
{
private:
	CCriSec   SendLock_;
	CCriSec   RecvLock_;
	CCriSec   PrintLock_;
	char      szSendbuf_[CLIENT_SND_SIZE];     //发送数据buffer
	char      szRecvBuf_[CLIENT_RCV_SIZE];     //接收数据buffer
	DWORD     dwSendLen_;
	DWORD     dwRecvLen_;
	DWORD     dwCheckCode_;

public:
	CNetMgr();
	~CNetMgr();
private:
	CCriSec& GetSendLock(){return SendLock_;}
	CCriSec& GetRecvLock(){return RecvLock_;}
	CCriSec& GetPrintLock(){return PrintLock_;}


public:
	bool Init(LPCTSTR lpIP,USHORT usPort);
	bool Start();
	bool SendData(DWORD dwMainID,DWORD dwSubID,DWORD dwHandID);                                        //发送消息，不包含内容
	bool SendData(DWORD dwMainID,DWORD dwSubID,DWORD dwHandID,char* pMsgData,DWORD dwMsgLen);          //发送消息，包含内容及内容长度
	bool SendData(char* pAllMsgData,DWORD dwAllMsgLen);                                                //发送消息，包含所有信息长度
	bool CheckSendData();
	bool RecvData();
	bool OnNetMessage(char* pMsgData,DWORD dwMsgLen);
	static unsigned int __stdcall SendThread(void *pData);
	static unsigned int __stdcall RecvThread(void *pData);
};                                                  #pragma once
#include "../global/singleton.h"
 
class CWSAInit:public TSingleton<CWSAInit>
{
public:
	CWSAInit(){}
	~CWSAInit(){}
	bool  WSAInit()
	{
		WSADATA wsaData;
		int error=0;

		error=WSAStartup(MAKEWORD(2,0),&wsaData);
		if( error == SOCKET_ERROR )
		{
			char errorBuffer[ 100 ];

			error = WSAGetLastError();
			if( error == WSAVERNOTSUPPORTED )
			{
				sprintf( errorBuffer, "Startup() - WSAStartup() error.\nRequested v2.0(highest v2.2), found only v%d.%d.", 
					LOBYTE( wsaData.wVersion ),
					HIBYTE( wsaData.wVersion ) );
				WSACleanup();
			}
			else
				sprintf( errorBuffer, "Startup() - WSAStartup() error %d", WSAGetLastError() );

			throw CNetErr(errorBuffer);
		}

		return true;
	}
	bool  WSAUnInit()
	{
		WSACleanup();
		return true;
	}
};                                                  