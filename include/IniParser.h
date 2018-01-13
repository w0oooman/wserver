#ifndef  __INI_PARSER_H__
#define  __INI_PARSER_H__
#include <fstream>
#define  INI_STRING_LEN  128

class CIniParser
{
private:
	char          *m_szFileName;
	std::fstream   m_fstream;
	char          *m_szFormatStr;
	//char           m_szFormatStr[INI_STRING_LEN];
public:
	CIniParser();
	virtual ~CIniParser();
private:
	char* __cdecl FormatStr(const char* format, ...);
	bool  Open();
	int   GetLine(char* buff, int bytes);      //读取一行,返回读取字节数,bytes:最大读取字节
	bool  Judge(const char* line, int bytes, char character);
	bool  IsNotes(const char* line, int bytes);//是否是注释#
	bool  IsSection(const char* line, int bytes);
	bool  IsSection(const char* line, const char* section, int bytes);
	bool  IsKey(const char* line, int bytes);                  //判断某行是否是key
	char* GetKey(char* line, const char* key, int bytes);//找到section后,判断某行是否是要找的key
	int   GetOneString(const char* line, int bytes, char* outbuf, int outlen); // 获取一个字符串
	char* GetData(const char* section, const char* key, char* buffer, int bufsize);
public:
	char* GetLastError();
	bool  Open(const char* szFileName);
	void  Close();
	char* GetIniString(const char* section, const char* key, char* buffer, int bufsize, char* default = "");
	int   GetIniInt(const char* section, const char* key, int default = 0);
};

#endif