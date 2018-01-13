#pragma  once

#include  "NetMgr.h"
#include  "TCPSocket.h"
class CTCPSocket;

class CSocketArray
{
private:
	UINT            nLimitCount_;            //限制人数
	UINT            nActiveCount_;           //在线人数
	UINT            nNowMaxCount_;           //当前最大容量
	CTCPSocket    **ppTCPFixedSocketArray_;  //socket固定指针数组
	CTCPSocket    **ppTCPSocketArray_;       //socket活动指针数组
	CTCPSocket    **ppTempTCPSocketArray_;   //socket临时活动指针数组
public:
	CSocketArray();
	virtual ~CSocketArray();
private:
	void         UnInit();
public:
	bool         Init(UINT nMaxCount);
	CTCPSocket*  GetFixedItem(UINT index);               //固定项
	CTCPSocket*  GetActiveItem(UINT index);              //活动项
	UINT         GetActiveCount();
	CTCPSocket** GetTempActiveItemPPtrSet();             //获取活动的ptr集合
	int          GetFixIndex();
	CTCPSocket*  GetItem();
	bool         RemoveItem(CTCPSocket* pTCPSocket);
};