#ifndef  __MSGDEFINE__H__
#define  __MSGDEFINE__H__
#include "KernelMsg.h"
#include "UserData.h"

//最大连接数
#define  MAX_CLIENT_NUM        300

//服务器配置
#define SERVER_CONFIG "../server.ini"
#define TEST_SERVER_CONFIG "./server.ini"

#define  GATESERVER_PORT           (8890)                      //网关服务器端口
#define  DISTRI_GATE_LOGIN_PORT    (GATESERVER_PORT+1)         //网关服S-登录服C 端口
#define  DISTRI_GATE_LOGIC_PORT    (DISTRI_GATE_LOGIN_PORT+1)  //网关服S-逻辑服C 端口
#define  DISTRI_DB_LOGIN_PORT      (DISTRI_GATE_LOGIC_PORT+1)  //DB服S-登录服C 端口
#define  DISTRI_LOGIN_LOGIC_PORT   (DISTRI_DB_LOGIN_PORT+1)    //登录服S-游戏服C 端口

//帐号长度
#define  ACCOUNT_LEN       32
//密码长度
#define  PASSWORD_LEN      32
//角色名长度
#define  ROLENAME_LEN      32
//角色列表长度
#define  ROLELIST_LEN      128


///////////////////////////////////////////////
////////////////网络协议定义///////////////////
///////////////////////////////////////////////

//=============================================================================================
//用户登录成功,将用户数据发送到逻辑服
class CDUserData2LogicMsg : public CNetMsgHead
{
public:
	WORD      m_wServerIndex;
	CUserData m_UserData;
	CDUserData2LogicMsg() : CNetMsgHead(CNetMsgHead::NETMSG_USERDATA_2LOGIC)
	{
		size_ = sizeof(CDUserData2LogicMsg);
	}
	virtual ~CDUserData2LogicMsg(){}
};
//.............................................................................................

//=============================================================================================
//前后端版本不一致
class CDVersionErrorMsg : public CNetMsgHead
{
public:
	CDVersionErrorMsg() : CNetMsgHead(CNetMsgHead::NETMSG_VERSION_UNSAME)
	{
		size_ = sizeof(CDVersionErrorMsg);
	}
	virtual ~CDVersionErrorMsg(){}
};
//.............................................................................................

//=============================================================================================
//保存数据
class CDSaveDataMsg : public CNetMsgHead
{
public:
	DWORD  m_dwID;    //角色ID/帮会ID等
	short  m_shType;
	char   m_szData[1 << 16];
	CDSaveDataMsg() : CNetMsgHead(CNetMsgHead::NETMSG_SAVE_DATA)
	{
		size_ = sizeof(CDVersionErrorMsg);
	}
	virtual ~CDSaveDataMsg(){}
};
//.............................................................................................

//=============================================================================================
//注册帐号-上行
class CURegisterMsg : public CNetMsgHead
{
public:
	char m_account[ACCOUNT_LEN];
	char m_password[PASSWORD_LEN];
	CURegisterMsg() : CNetMsgHead(CNetMsgHead::NETMSG_USER_REGISTER)
	{
		memset(m_account,0,sizeof(m_account));
		memset(m_password, 0, sizeof(m_password));
		size_ = sizeof(CURegisterMsg);
	}
	~CURegisterMsg(){}
};

//注册帐号-下行
class CDRegisterMsg : public CNetMsgHead
{
public:
	WORD  m_wRes;
	CDRegisterMsg() : CNetMsgHead(CNetMsgHead::NETMSG_USER_REGISTER)
	{
		size_ = sizeof(CDRegisterMsg);
	}
	virtual ~CDRegisterMsg(){}
	enum 
	{
		REG_SUCCESS = 1,//注册成功
		REG_EXIST,//帐号已经存在
		REG_ACCOUNT_SHORT,//帐号太短
		REG_ACCOUNT_LONG,//帐号过长
		REG_PWD_SHORT,//密码太短
		REG_PWD_LONG,//密码过长
	};
};
//.............................................................................................

//=============================================================================================
//登录/获取角色列表
class CULoginMsg : public CNetMsgHead
{
public:
	WORD m_wServerIndex; //登录的服务器号
	char m_account[ACCOUNT_LEN];
	char m_password[PASSWORD_LEN];
	CULoginMsg() :CNetMsgHead(CNetMsgHead::NETMSG_USER_LOGIN)
	{
		memset(m_account, 0, sizeof(m_account));
		memset(m_password, 0, sizeof(m_password));
		size_ = sizeof(CULoginMsg);
	}
	virtual ~CULoginMsg(){}
};

//登录/获取角色列表
class CDLoginMsg : public CNetMsgHead
{
public:
	WORD  m_wServerIndex;
	WORD  m_wRes;
	char  m_szRoleList[ROLELIST_LEN];
	CDLoginMsg() : CNetMsgHead(CNetMsgHead::NETMSG_USER_LOGIN)
	{
		memset(m_szRoleList, 0, sizeof(m_szRoleList));
		size_ = sizeof(CDLoginMsg);
	}
	~CDLoginMsg(){}
	enum
	{
		LOGIN_UNKNOW = 0,//未知错误
		LOGIN_SUCCESS,//登录成功
		LOGIN_ONLINE,//已经登录
        LOGIN_ACCOUNT_ERR,//帐号不存在
		LOGIN_PWD_ERR,//密码错误
	};
};
//.............................................................................................

//=============================================================================================
//进入-上行
class CUEnterMsg : public CNetMsgHead
{
public:
	WORD  m_wServerIndex;
	char  m_rolename[ROLENAME_LEN];
	CUEnterMsg() : CNetMsgHead(CNetMsgHead::NETMSG_USER_ENTER)
	{
		memset(m_rolename, 0, sizeof(m_rolename));
	}
	virtual ~CUEnterMsg(){}
};

//进入-下行
class CDEnterMsg : public CNetMsgHead
{
public:
	WORD  m_wServerIndex;
	WORD  m_wRes;
	CDEnterMsg() : CNetMsgHead(CNetMsgHead::NETMSG_USER_ENTER)
	{
		size_ = sizeof(CDEnterMsg);
	}
	~CDEnterMsg(){}
	enum
	{
		ENTER_SUCCESS = 1,
		ENTER_NOTEXIST= 2, //角色不存在
	};
};
//.............................................................................................

//=============================================================================================
//聊天
class CUChatMsg : public CNetMsgHead
{
public:
	CUChatMsg() : CNetMsgHead(CNetMsgHead::NETMSG_USER_CHAT)
	{
		size_ = sizeof(CUChatMsg);
	}
	virtual ~CUChatMsg(){}
};
//.............................................................................................

//=============================================================================================
//用户下线
class CDUserOfflineMsg : public CNetMsgHead
{
public:
	CDUserOfflineMsg() : CNetMsgHead(CNetMsgHead::NETMSG_USER_OFFLINE){ }
	virtual ~CDUserOfflineMsg(){}
};

//.............................................................................................

//=============================================================================================
//测试使用
class CTestMsg : public CNetMsgHead
{
public:
	char buf[200];
	CTestMsg() : CNetMsgHead(CNetMsgHead::NETMSG_MY_TEST){ memset(buf, 0, sizeof(buf)); }
	virtual ~CTestMsg(){}
};

//.............................................................................................









//主ID
enum EnumMainID
{
	mmd_connect_success = 1,         //连接成功 发送密钥
	mmd_server_full = 2,             //服务器爆满
	mmd_heart_beat = 3,              //心跳检测

	//上面的消息不要动!!!
	mmd_player_register = 21,        //注册
	mmd_player_login = 22,           //登录
	mmd_player_offline = 23,         //下线
	mmd_message_test = 100,          //自己测试
};

//子ID
//登录
enum EnumSub_Login
{
	smd_login_success = 0,
	smd_login_syserror = 1,     //系统错误
	smd_login_acount_err = 2,   //帐号不存在
	smd_login_pwd_err = 3,      //密码错误
};


//数据库操作
enum DBHandle
{
	db_player_register = 1,
	db_player_login = 2,
	db_get_login_times = 100,          //获取登录次数
};





//主ID
//enum class MainID :unsigned int
//{
//	mmd_connect_success = 1,
//	mmd_server_full = 2,
//};
//下面部分放在cpp文件
//bool operator == (MainID e, int a){
//	return (MainID)a == e;
//}
//bool operator == (int a, MainID e){
//	return (MainID)a == e;
//}
//
//bool operator > (MainID e, int a){
//	return e > (MainID)a;
//}
//bool operator > (int a, MainID e){
//	return (MainID)a > e;
//}

#endif
