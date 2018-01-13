#ifndef __KERNEL_MSG_H__
#define __KERNEL_MSG_H__
#include <windows.h>

//////**********结构**************/////
//old消息头
struct NetMsgHead
{
	DWORD    dwSize;      //消息长度
	DWORD    dwMainID;    //主消息ID
	DWORD    dwSubID;     //子消息ID
	DWORD    dwReserve;   //保留字节
};

//new消息头
class CNetMsgHead
{
public:
	WORD     size_;       //数据长度
	WORD     protocol_;   //协议
	DWORD    reserve1_;   //保留字节1
	DWORD    reserve2_;   //保留字节2
public:
	CNetMsgHead(WORD protocol){ protocol_ = protocol; }
	virtual ~CNetMsgHead(){}
public:
	enum
	{
		NETMSG_GET_SERVERLIST = 1,       //获取服务器列表
		NETMSG_SERVER_REGISTER,          //内部服务器注册
		NETMSG_USERDATA_2LOGIC,          //用户登录成功,将用户数据发送到逻辑服
		NETMSG_SAVE_DATA,                //保存数据

		NETMSG_HEART_BEAT = 100,         //心跳
		NETMSG_CONNECT_SUCESS,           //连接成功
		NETMSG_SERVER_FULL,              //服务器爆满
		NETMSG_VERSION_UNSAME,           //前后端版本不一致
		NETMSG_USER_REGISTER,            //注册
		NETMSG_USER_LOGIN,               //登录/获取角色列表
		NETMSG_USER_ENTER,               //用户进入
		NETMSG_USER_OFFLINE,             //用户下线
		NETMSG_USER_MOVE,                //移动消息
		NETMSG_USER_CHAT,                //聊天消息
		NETMSG_USER_BATTLE,              //战斗消息
		NETMSG_SEND_SCRIPT,              //脚本消息

		NETMSG_MY_TEST = 1000, //测试
	};
};

//=============================================================================================
//连接成功
class CDConnectSuccessMsg :public CNetMsgHead
{
public:
	DWORD m_dwKey;//秘钥
	CDConnectSuccessMsg() :CNetMsgHead(CNetMsgHead::NETMSG_CONNECT_SUCESS)
	{

	}
	virtual ~CDConnectSuccessMsg(){};
};
//.............................................................................................

struct Byte_Sum
{
	LONGLONG llByteSum;
};



#endif