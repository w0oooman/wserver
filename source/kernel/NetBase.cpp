#include  "NetBase.h"

#ifdef _MSC_VER
#pragma comment(lib,"ws2_32.lib")
bool  WSAInit()
{
	WSADATA wsaData;
	int error = 0;

	error = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (error == SOCKET_ERROR)
	{
		char errorBuffer[100];

		error = WSAGetLastError();
		if (error == WSAVERNOTSUPPORTED)
		{
			sprintf_s(errorBuffer, "Startup() - WSAStartup() error.\nRequested v2.0(highest v2.2), found only v%d.%d.",
				LOBYTE(wsaData.wVersion),
				HIBYTE(wsaData.wVersion));
			WSACleanup();
		}
		else
			sprintf_s(errorBuffer, "Startup() - WSAStartup() error %d", WSAGetLastError());

		throw CNetErr(errorBuffer);
	}

	return true;
}
bool  WSAUnInit()
{
	WSACleanup();
	return true;
}
#endif

CNetBase::CNetBase()
{
	memset(&m_sockaddr, 0, sizeof(m_sockaddr));
	m_socket = INVALID_SOCKET;
}

CNetBase::~CNetBase()
{
	if (IsValidSocket())
	{
		CloseSocket();
	}
}

void CNetBase::SetSockAddr(sockaddr_in &addr)
{
	m_sockaddr = addr;
}

void CNetBase::SetRecvSendBuf(SOCKET nSocket, DWORD *dwRecvBuf, DWORD *dwSendBuf)
{
	if (setsockopt(nSocket, SOL_SOCKET, SO_RCVBUF, (const char*)dwRecvBuf, sizeof(int)) == SOCKET_ERROR)
	{
		throw CNetErr("set recv buff error!", true);
	}

	if (setsockopt(nSocket, SOL_SOCKET, SO_SNDBUF, (const char*)dwSendBuf, sizeof(int)) == SOCKET_ERROR)
	{
		throw CNetErr("set send buff error!", true);
	}
}

SOCKET CNetBase::GetSocket()
{
	return m_socket;
}

bool CNetBase::IsValidSocket()
{
	return (INVALID_SOCKET == m_socket ? false : true);
}

bool CNetBase::CreateSocket()
{
	if (IsValidSocket()) return false;

#ifdef _MSC_VER
	m_socket = ::WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (!IsValidSocket())
	{
		throw CNetErr();
	}
#else
#endif

	const int on = 1;
	if (setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof(on)) == SOCKET_ERROR)     //地址复用
		throw CNetErr("set addr reuse failed!", true);


	//发送/接收 windows默认8K
	DWORD dwRecvBuf = 64 * 1024;//设置为64K
	DWORD dwSendBuf = 64 * 1024;//设置为64K
	SetRecvSendBuf(m_socket, &dwRecvBuf, &dwSendBuf);

	//const bool bNodelay=1; 
	//if(setsockopt( m_socket, IPPROTO_TCP,TCP_NODELAY, (char*)&bNodelay,sizeof(bool))==SOCKET_ERROR)  //no delay，发送时不等待返回ACK(需等200ms)，立刻发送下一个包
	//	cout<<"set TCP_NODELAY failed!"<<endl;

	//whb 环形缓冲 设置成非阻塞模式 测试发现使用非阻塞时CPU占用超高!!!
	//unsigned long ul=1;     
	//if(SOCKET_ERROR == ioctlsocket(m_socket,FIONBIO,(unsigned long *)&ul))
	//{
	//	char err[50];
	//	int errNum=WSAGetLastError();
	//	sprintf_s(err,"ioctlsocket()---error num=%d",errNum);
	//	throw CNetErr(err);
	//}

	return true;
}

bool CNetBase::Bind(DWORD dwPort)
{
	if (!IsValidSocket())
		throw CNetErr("socket not created or created failed!");

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(dwPort);
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	int nBind = ::bind(m_socket, (sockaddr*)&addr, sizeof(addr));
	if (SOCKET_ERROR == nBind)
	{
		CloseSocket();
		throw CNetErr();
		return false;
	}

	return true;
}

bool CNetBase::Listen()
{
	if (!IsValidSocket())
		throw CNetErr("socket not created or created failed!");

	int nListen = ::listen(m_socket, 200);
	if (SOCKET_ERROR == nListen)
	{
		CloseSocket();
		throw CNetErr("listen failed.");
		return false;
	}

	return true;
}

bool CNetBase::Accept()
{
	return true;
}

bool  CNetBase::Connect()
{
	if (!IsValidSocket())
		throw CNetErr("socket not created or created failed!");

	Log("connecting...");
	int nConnect = ::connect(m_socket, (sockaddr*)&m_sockaddr, sizeof(m_sockaddr));
	if (SOCKET_ERROR == nConnect)
	{
		CloseSocket();
		throw CNetErr("connect failed!");
		return false;
	}
	Log("connect success!");

	return true;
}

void CNetBase::CloseSocket()
{
#ifdef _MSC_VER
	::closesocket(m_socket);
	m_socket = INVALID_SOCKET;
#else
	::close(m_socket);
	m_socket = INVALID_SOCKET;
#endif
}

void CNetBase::ShutDown(int how)
{
#ifdef _MSC_VER
	if (SD_RECEIVE == how || SD_SEND == how || SD_BOTH == how)
#else
	if (SHUT_RD == how || SHUT_WR == how || SHUT_RDWR == how)
#endif
	{
		::shutdown(m_socket, how);
		//m_socket = INVALID_SOCKET;
	}
}