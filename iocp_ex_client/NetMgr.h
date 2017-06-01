#ifndef __NETMGRC_H__
#define __NETMGRC_H__
#include "NetBase.h"
#include "lock.h"
#include "../include/NetMsg.h"
#include "../source/kernel/NetMgr.h"
#define CLIENT_SND_SIZE   2048
#define CLIENT_RCV_SIZE   1024*24
 
class CTCPSocket
{
public:
	CTCPSocket();
	~CTCPSocket();

public:
	bool SendData();
	bool RecvData();
};

class CNetMgrC:public CNetBase
{
private:
	CLock     SingleLock_;
	char     *szSendbuf_;     //发送数据buffer
	char     *szRecvBuf_;     //接收数据buffer
	DWORD     dwSendLen_;
	DWORD     dwRecvLen_;
	DWORD     dwCheckCode_;
	HANDLE    hEvent_;                         //等待事件
	NETOVERLAPPED RecvOverLPData_;

public:
	CNetMgrC();
	~CNetMgrC();
private:
	CLock&   GetLock(){ return SingleLock_; }


public:
	bool Init(LPCTSTR lpIP,USHORT usPort);
	bool PrepareRecv();
	//bool Start();
	bool SendData(DWORD dwMainID,DWORD dwSubID);                                        //发送消息，不包含内容
	bool SendData(DWORD dwMainID, DWORD dwSubID, void* pMsgData, DWORD dwMsgLen);       //发送消息，包含内容及内容长度
	bool SendData(CNetMsgHead* pNetMsgHead, DWORD dwAllMsgLen);                         //发送消息，包含所有信息长度
	bool CheckSendData();
	bool OnRecvComplete();
	bool OnNetMessage(char* pMsgData,DWORD dwMsgLen);
	static unsigned int __stdcall SendThread(void *pData);
	static unsigned int __stdcall RecvThread(void *pData);
};                                                  

#endif