#ifdef _MSC_VER
#include <windows.h>
#else
#include <errno.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "IniParser.h"
using namespace std;


CIniParser::CIniParser()
{
	m_szFormatStr = NULL;
	m_szFileName = NULL;
}

CIniParser::~CIniParser()
{
	Close();
	delete []m_szFormatStr;
	delete []m_szFileName;
}

char* CIniParser::FormatStr(const char* format, ...)
{
	va_list header;
	va_start(header, format);

#ifdef _MSC_VER
	vsprintf_s((char*)m_szFormatStr, INI_STRING_LEN, format, header);
#else
	vsprintf((char*)m_szErrorStr, format, header);
#endif

	va_end(header);
	return (char*)m_szFormatStr;
}

int CIniParser::GetLine(char* buff, int bytes)
{
	if (!buff) return 0;
	if (0 == bytes){
		buff[0] = '\0';
		return 0;
	}

	int nums = 0;
	bool bLineEnd = false;
	while (bytes-- > 0)
	{
		char character = m_fstream.get();
		buff[nums++] = character;
		if (character == '\n')
		{
			bLineEnd = true;
			break;
		}
	}

	if (!bLineEnd)
	{
		while (1)
		{
			//跨平台,windows下"\r\n"会转化成'\n'
			if (m_fstream.get() == '\n' || m_fstream.eof())
			{
				break;
			}
		}
	}

	return nums;
}

bool CIniParser::Open()
{
	if (m_fstream.is_open())
	{
		m_fstream.close();
	}

	if (NULL == m_szFormatStr)
	{
		m_szFormatStr = new char[INI_STRING_LEN];
	}

	m_fstream.open(m_szFileName, ios::in | ios::out);
	if (m_fstream.is_open())
		return true;

	return false;
}

bool CIniParser::Judge(const char* line, int bytes, char character)
{
	if (!line)
	{
		return true;
	}

	for (int i = 0; i < bytes; i++)
	{
		if ('\0' == line[i] || ' ' == line[i] || '\n' == line[i] || '\r' == line[i])
		{
			continue;
		}
		if (line[i] != character)
		{
			return false;
		}
		return true;
	}
	return false;
}

bool CIniParser::IsNotes(const char* line, int bytes)
{
	return Judge(line, bytes, '#');
}

bool CIniParser::IsSection(const char* line, int bytes)
{
	if (IsNotes(line, bytes)) return false;

	return Judge(line, bytes, '[');
}

bool CIniParser::IsSection(const char* line, const char* section, int bytes)
{
	char buff[INI_STRING_LEN];
	memset(buff, 0, sizeof(buff));
#ifdef _MSC_VER
	sprintf_s(buff, "[%s]", section);
#else
	sprintf(buff, "[%s]", section);
#endif
	if (IsSection(line, bytes) && strstr(line, buff))
	{
		return true;
	}

	return false;
}

bool CIniParser::IsKey(const char* line, int bytes)
{
	if (!IsNotes(line, bytes) && !IsSection(line, bytes))
	{
		return true;
	}
	return false;
}

char* CIniParser::GetKey(char* line, const char* key, int bytes)
{
	char buff[INI_STRING_LEN];
	int len = GetOneString(line, bytes, buff, sizeof(buff)-1);
	int truelen = strlen(buff);
	if (truelen > 0 && memcmp(buff, key, truelen) == 0)
	{
		len += GetOneString(line + len, bytes, buff, sizeof(buff)-1);
		truelen = strlen(buff);
		if (truelen > 0 && memcmp(buff, "=", strlen("=")) == 0)
		{
			len += GetOneString(line + len, bytes, buff, sizeof(buff)-1);
			truelen = strlen(buff);
			if (truelen > 0)
			{
				memcpy(line, buff, truelen);
				line[truelen] = 0;
				return line;
			}
		}
	}

	return NULL;
}

int CIniParser::GetOneString(const char* line, int bytes, char* outbuf, int outlen)
{
	int nNotNullBytes = 0;

	int i = 0;
	for (; i < bytes; i++)
	{
		if (' ' == line[i])
		{
			if (nNotNullBytes){ break; }
			continue;
		}
		if (nNotNullBytes + 1 > outlen) { break; }
		outbuf[nNotNullBytes] = line[i];
		nNotNullBytes++;
	}
	
	outbuf[nNotNullBytes] = 0;
	return i;
}

char* CIniParser::GetData(const char* section, const char* key, char* buffer, int bufsize)
{
	while (!m_fstream.eof())
	{
		memset(buffer, 0, bufsize);
		//istream &stream = m_fstream.getline(buffer, bufsize);
		//int bytes = stream.gcount();
		int bytes = GetLine(buffer, bufsize);
		if (IsSection(buffer, section, bytes))
		{
			while (!m_fstream.eof())
			{
				int bytes = GetLine(buffer, bufsize);
				if (IsNotes(buffer, bytes)) continue;
				if (IsSection(buffer, bytes)) break;
				if (GetKey(buffer, key, bytes))
				{
					return buffer;
				}
			}
			break;
		}
	}

	return NULL;
}

char* CIniParser::GetLastError()
{
#ifdef _MSC_VER
	int err = ::GetLastError();
	switch (err)
	{
	case 2:
		return FormatStr("系统找不到指定的文件【%s】.", m_szFileName);
		break;
	case 3:
		return FormatStr("系统找不到指定的路径【%s】.", m_szFileName);
		break;
	case 4:
		return FormatStr("系统无法打开文件【%s】.", m_szFileName);
		break;
	case 5:
		return FormatStr("【%s】拒绝访问.", m_szFileName);
		break;
	default:
		return FormatStr("【%s】unknow errorno:%d", m_szFileName, err);
		break;
}
#else
	int err = errno;
	if (errno > 0){
		return FormatStr("【%s】%s.", m_szFileName, strerror(errno));
	}
	else{
		return "no error."
	}
#endif
	return "unknow error";
}

bool CIniParser::Open(const char* szFileName)
{
	if (m_szFileName)
	{
		delete []m_szFileName;
		m_szFileName = NULL;
	}

	int len = strlen(szFileName);
	m_szFileName = new char[len + 1];
	memcpy(m_szFileName, szFileName, len);
	m_szFileName[len] = 0;

	return Open();
}

void CIniParser::Close()
{
	if (m_fstream.is_open())
	{
		m_fstream.close();
	}

	if (NULL != m_szFormatStr)
	{
		delete []m_szFormatStr;
		m_szFormatStr = NULL;
	}
}

char* CIniParser::GetIniString(const char* section, const char* key, char* buffer, int bufsize, char* default/* = ""*/)
{
	if (!section || !key || section[0] == '\0' || key[0] == '\0')
		return default;

	Open();
	if (!m_fstream.is_open())
		return default;

	char * ret = GetData(section, key, buffer, bufsize);
	if (NULL == ret)
	{
		int len = min(bufsize, strlen(default));
		memcpy(buffer, default, len);
		if (len < bufsize) len += 1;
		buffer[len - 1] = 0;
		ret = buffer;
	}

	return ret;
}

int CIniParser::GetIniInt(const char* section, const char* key, int default/* = 0*/)
{
	if (!section || !key || memcmp(section, "", sizeof("")) == 0 || memcmp(key, "", sizeof("")) == 0)
		return default;

	Open();
	if (!m_fstream.is_open())
		return default;

	char buff[INI_STRING_LEN];
	char * ret = GetData(section, key, (char*)buff, INI_STRING_LEN);
	if (NULL == ret) return default;

	return atoi(ret);
}