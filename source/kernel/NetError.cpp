#include  "netError.h"
#ifdef _MSC_VER
#include <WinSock2.h>
#else
#include<errno.h>
#endif

CNetErr::CNetErr(string strErrorinfo) 
	:m_strErrorinfo(strErrorinfo)
{

}

CNetErr::CNetErr(string strErrorinfo, bool bIsJoin)
	: m_strErrorinfo(strErrorinfo)
{
	if (bIsJoin)
	{
		SetErrorinfo();
	}
}

CNetErr::CNetErr()
{
	if (m_strErrorinfo.empty())
	{
		SetErrorinfo();
	}
}

CNetErr::~CNetErr()
{
	m_strErrorinfo.clear();
}

int CNetErr::GetErrorID()
{
	int error_number = 0;

#ifdef _MSC_VER
	error_number = WSAGetLastError();
	if (0 == error_number) error_number = GetLastError();
#else
	error_number = errno;
#endif

	return error_number;
}

void CNetErr::SetErrorinfo()
{
	int error_number = GetErrorID();
	char errorBuffer[512];

#ifdef _MSC_VER
	LPWSTR lpErrorBuffer = NULL;
	::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL, error_number, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), reinterpret_cast<LPTSTR>(&lpErrorBuffer), 0, NULL);
	sprintf_s(errorBuffer, " error:errno=%d -> %s", error_number, lpErrorBuffer);
	LocalFree(lpErrorBuffer);
#else
	sprintf(, "error!,errno = %d,%s", error_number, strerror(error_number));
#endif

	m_strErrorinfo.append(errorBuffer);
}

CNetErr::operator string()
{
	return m_strErrorinfo;
}

CNetErr::operator char*()
{
	return const_cast<char*>(m_strErrorinfo.c_str());
}

