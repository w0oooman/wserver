
#pragma once

#pragma once

#pragma region Input Buffer SAL 1 compatibility macros

#pragma endregion Input Buffer SAL 1 compatibility macros

#pragma once

#pragma pack(push,8)

#pragma once

#pragma pack(push,8)

typedef __w64 unsigned int   uintptr_t;

typedef char *  va_list;

#pragma pack(pop)

typedef __w64 unsigned int   size_t;

typedef size_t rsize_t;

typedef __w64 int            intptr_t;

typedef __w64 int            ptrdiff_t;

typedef unsigned short wchar_t;

typedef unsigned short wint_t;
typedef unsigned short wctype_t;

typedef int errno_t;

typedef __w64 long __time32_t;

typedef __int64 __time64_t;

typedef __time64_t time_t;

__declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);
__declspec(dllimport) __declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(void);

__declspec(dllimport) __declspec(noreturn)
void __cdecl _invoke_watson(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t);

struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct * pthreadlocinfo;
typedef struct threadmbcinfostruct * pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct
{
	pthreadlocinfo locinfo;
	pthreadmbcinfo mbcinfo;
} _locale_tstruct, *_locale_t;

typedef struct localerefcount {
	char *locale;
	wchar_t *wlocale;
	int *refcount;
	int *wrefcount;
} locrefcount;

typedef struct threadlocaleinfostruct {
	int refcount;
	unsigned int lc_codepage;
	unsigned int lc_collate_cp;
	unsigned int lc_time_cp;
	locrefcount lc_category[6];
	int lc_clike;
	int mb_cur_max;
	int * lconv_intl_refcount;
	int * lconv_num_refcount;
	int * lconv_mon_refcount;
	struct lconv * lconv;
	int * ctype1_refcount;
	unsigned short * ctype1;
	const unsigned short * pctype;
	const unsigned char * pclmap;
	const unsigned char * pcumap;
	struct __lc_time_data * lc_time_curr;
	wchar_t * locale_name[6];
} threadlocinfo;

#pragma pack(pop)

__declspec(dllimport) extern int * __cdecl _errno(void);

errno_t __cdecl _set_errno(int _Value);
errno_t __cdecl _get_errno(int * _Value);

#pragma once

void __declspec(dllimport) __cdecl _vacopy(va_list *, va_list);

#pragma once

#pragma pack(push,8)

struct _iobuf {
	char *_ptr;
	int   _cnt;
	char *_base;
	int   _flag;
	int   _file;
	int   _charbuf;
	int   _bufsiz;
	char *_tmpfname;
};
typedef struct _iobuf FILE;

__declspec(dllimport) FILE * __cdecl __iob_func(void);

typedef __int64 fpos_t;

__declspec(dllimport) int __cdecl _filbuf(FILE * _File);
__declspec(dllimport) int __cdecl _flsbuf(int _Ch, FILE * _File);

__declspec(dllimport) FILE * __cdecl _fsopen(const char * _Filename, const char * _Mode, int _ShFlag);

__declspec(dllimport) void __cdecl clearerr(FILE * _File);

__declspec(dllimport) errno_t __cdecl clearerr_s(FILE * _File);

__declspec(dllimport) int __cdecl fclose(FILE * _File);
__declspec(dllimport) int __cdecl _fcloseall(void);

__declspec(dllimport) FILE * __cdecl _fdopen(int _FileHandle, const char * _Mode);

__declspec(dllimport) int __cdecl feof(FILE * _File);
__declspec(dllimport) int __cdecl ferror(FILE * _File);
__declspec(dllimport) int __cdecl fflush(FILE * _File);
__declspec(dllimport) int __cdecl fgetc(FILE * _File);
__declspec(dllimport) int __cdecl _fgetchar(void);
__declspec(dllimport) int __cdecl fgetpos(FILE * _File, fpos_t * _Pos);
__declspec(dllimport) char * __cdecl fgets(char * _Buf, int _MaxCount, FILE * _File);

__declspec(dllimport) int __cdecl _fileno(FILE * _File);

__declspec(dllimport) char * __cdecl _tempnam(const char * _DirName, const char * _FilePrefix);

__declspec(dllimport) int __cdecl _flushall(void);
__declspec(dllimport) FILE * __cdecl fopen(const char * _Filename, const char * _Mode);

__declspec(dllimport) errno_t __cdecl fopen_s(FILE ** _File, const char * _Filename, const char * _Mode);

__declspec(dllimport) int __cdecl fprintf(FILE * _File, const char * _Format, ...);

__declspec(dllimport) int __cdecl fprintf_s(FILE * _File, const char * _Format, ...);

__declspec(dllimport) int __cdecl fputc(int _Ch, FILE * _File);
__declspec(dllimport) int __cdecl _fputchar(int _Ch);
__declspec(dllimport) int __cdecl fputs(const char * _Str, FILE * _File);
__declspec(dllimport) size_t __cdecl fread(void * _DstBuf, size_t _ElementSize, size_t _Count, FILE * _File);

__declspec(dllimport) size_t __cdecl fread_s(void * _DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE * _File);

__declspec(dllimport) FILE * __cdecl freopen(const char * _Filename, const char * _Mode, FILE * _File);

__declspec(dllimport) errno_t __cdecl freopen_s(FILE ** _File, const char * _Filename, const char * _Mode, FILE * _OldFile);

__declspec(dllimport) int __cdecl fscanf(FILE * _File, const char * _Format, ...);
__declspec(dllimport) int __cdecl _fscanf_l(FILE * _File, const char * _Format, _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

__declspec(dllimport) int __cdecl fscanf_s(FILE * _File, const char * _Format, ...);

__declspec(dllimport) int __cdecl _fscanf_s_l(FILE * _File, const char * _Format, _locale_t _Locale, ...);
#pragma warning(pop)
__declspec(dllimport) int __cdecl fsetpos(FILE * _File, const fpos_t * _Pos);
__declspec(dllimport) int __cdecl fseek(FILE * _File, long _Offset, int _Origin);
__declspec(dllimport) long __cdecl ftell(FILE * _File);

__declspec(dllimport) int __cdecl _fseeki64(FILE * _File, __int64 _Offset, int _Origin);
__declspec(dllimport) __int64 __cdecl _ftelli64(FILE * _File);

__declspec(dllimport) size_t __cdecl fwrite(const void * _Str, size_t _Size, size_t _Count, FILE * _File);
__declspec(dllimport) int __cdecl getc(FILE * _File);
__declspec(dllimport) int __cdecl getchar(void);
__declspec(dllimport) int __cdecl _getmaxstdio(void);

__declspec(dllimport) char * __cdecl gets_s(char * _Buf, rsize_t _Size);

__declspec(dllimport) char * __cdecl gets(char *_Buffer);
int __cdecl _getw(FILE * _File);

__declspec(dllimport) void __cdecl perror(const char * _ErrMsg);

__declspec(dllimport) int __cdecl _pclose(FILE * _File);
__declspec(dllimport) FILE * __cdecl _popen(const char * _Command, const char * _Mode);

__declspec(dllimport) int __cdecl printf(const char * _Format, ...);

__declspec(dllimport) int __cdecl printf_s(const char * _Format, ...);

__declspec(dllimport) int __cdecl putc(int _Ch, FILE * _File);
__declspec(dllimport) int __cdecl putchar(int _Ch);
__declspec(dllimport) int __cdecl puts(const char * _Str);
__declspec(dllimport) int __cdecl _putw(int _Word, FILE * _File);

__declspec(dllimport) int __cdecl remove(const char * _Filename);
__declspec(dllimport) int __cdecl rename(const char * _OldFilename, const char * _NewFilename);
__declspec(dllimport) int __cdecl _unlink(const char * _Filename);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_unlink" ". See online help for details.")) __declspec(dllimport) int __cdecl unlink(const char * _Filename);

__declspec(dllimport) void __cdecl rewind(FILE * _File);
__declspec(dllimport) int __cdecl _rmtmp(void);
__declspec(dllimport) int __cdecl scanf(const char * _Format, ...);
__declspec(dllimport) int __cdecl _scanf_l(const char * _Format, _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

__declspec(dllimport) int __cdecl scanf_s(const char * _Format, ...);

__declspec(dllimport) int __cdecl _scanf_s_l(const char * _Format, _locale_t _Locale, ...);
#pragma warning(pop)
__declspec(dllimport) void __cdecl setbuf(FILE * _File, char * _Buffer);
__declspec(dllimport) int __cdecl _setmaxstdio(int _Max);
__declspec(dllimport) unsigned int __cdecl _set_output_format(unsigned int _Format);
__declspec(dllimport) unsigned int __cdecl _get_output_format(void);
__declspec(dllimport) int __cdecl setvbuf(FILE * _File, char * _Buf, int _Mode, size_t _Size);
__declspec(dllimport) int __cdecl _snprintf_s(char * _DstBuf, size_t _SizeInBytes, size_t _MaxCount, const char * _Format, ...);

__declspec(dllimport) int __cdecl sprintf_s(char * _DstBuf, size_t _SizeInBytes, const char * _Format, ...);

__declspec(dllimport) int __cdecl _scprintf(const char * _Format, ...);
__declspec(dllimport) int __cdecl sscanf(const char * _Src, const char * _Format, ...);
__declspec(dllimport) int __cdecl _sscanf_l(const char * _Src, const char * _Format, _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

__declspec(dllimport) int __cdecl sscanf_s(const char * _Src, const char * _Format, ...);

__declspec(dllimport) int __cdecl _sscanf_s_l(const char * _Src, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _snscanf(const char * _Src, size_t _MaxCount, const char * _Format, ...);
__declspec(dllimport) int __cdecl _snscanf_l(const char * _Src, size_t _MaxCount, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _snscanf_s(const char * _Src, size_t _MaxCount, const char * _Format, ...);
__declspec(dllimport) int __cdecl _snscanf_s_l(const char * _Src, size_t _MaxCount, const char * _Format, _locale_t _Locale, ...);
#pragma warning(pop)
__declspec(dllimport) FILE * __cdecl tmpfile(void);

__declspec(dllimport) errno_t __cdecl tmpfile_s(FILE ** _File);
__declspec(dllimport) errno_t __cdecl tmpnam_s(char * _Buf, rsize_t _Size);

__declspec(dllimport) char * __cdecl tmpnam(char *_Buffer);
__declspec(dllimport) int __cdecl ungetc(int _Ch, FILE * _File);
__declspec(dllimport) int __cdecl vfprintf(FILE * _File, const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vfscanf(FILE * _File, const char * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vfprintf_s(FILE * _File, const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vfscanf_s(FILE * _File, const char * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vprintf(const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vscanf(const char * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vprintf_s(const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vscanf_s(const char * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vsnprintf(char * _DstBuf, size_t _MaxCount, const char * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vsnprintf_s(char * _DstBuf, size_t _DstSize, size_t _MaxCount, const char * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl _vsnprintf_s(char * _DstBuf, size_t _SizeInBytes, size_t _MaxCount, const char * _Format, va_list _ArgList);

#pragma warning(push)
#pragma warning(disable:4793)
__declspec(dllimport) int __cdecl _snprintf(char *_Dest, size_t _Count, const char * _Format, ...);
__declspec(dllimport) int __cdecl _vsnprintf(char *_Dest, size_t _Count, const char * _Format, va_list _Args);
#pragma warning(pop)

__declspec(dllimport) int __cdecl vsprintf_s(char * _DstBuf, size_t _SizeInBytes, const char * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vsscanf_s(const char * _Src, const char * _Format, va_list _ArgList);

#pragma warning(push)
#pragma warning(disable:4793)
__declspec(dllimport) int __cdecl sprintf(char *_Dest, const char * _Format, ...);
__declspec(dllimport) int __cdecl vsprintf(char *_Dest, const char * _Format, va_list _Args);
__declspec(dllimport) int __cdecl vsscanf(const char * _srcBuf, const char * _Format, va_list _ArgList);
#pragma warning(pop)
__declspec(dllimport) int __cdecl _vscprintf(const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _snprintf_c(char * _DstBuf, size_t _MaxCount, const char * _Format, ...);
__declspec(dllimport) int __cdecl _vsnprintf_c(char *_DstBuf, size_t _MaxCount, const char * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl _fprintf_p(FILE * _File, const char * _Format, ...);
__declspec(dllimport) int __cdecl _printf_p(const char * _Format, ...);
__declspec(dllimport) int __cdecl _sprintf_p(char * _Dst, size_t _MaxCount, const char * _Format, ...);
__declspec(dllimport) int __cdecl _vfprintf_p(FILE * _File, const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _vprintf_p(const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _vsprintf_p(char * _Dst, size_t _MaxCount, const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _scprintf_p(const char * _Format, ...);
__declspec(dllimport) int __cdecl _vscprintf_p(const char * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _set_printf_count_output(int _Value);
__declspec(dllimport) int __cdecl _get_printf_count_output(void);

__declspec(dllimport) int __cdecl _printf_l(const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _printf_p_l(const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _printf_s_l(const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vprintf_l(const char * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vprintf_p_l(const char * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vprintf_s_l(const char * _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) int __cdecl _fprintf_l(FILE * _File, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _fprintf_p_l(FILE * _File, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _fprintf_s_l(FILE * _File, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vfprintf_l(FILE * _File, const char * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vfprintf_p_l(FILE * _File, const char * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vfprintf_s_l(FILE * _File, const char * _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) int __cdecl _sprintf_l(char * _DstBuf, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _sprintf_p_l(char * _DstBuf, size_t _MaxCount, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _sprintf_s_l(char * _DstBuf, size_t _DstSize, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vsprintf_l(char * _DstBuf, const char * _Format, _locale_t, va_list _ArgList);
__declspec(dllimport) int __cdecl _vsprintf_p_l(char * _DstBuf, size_t _MaxCount, const char* _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vsprintf_s_l(char * _DstBuf, size_t _DstSize, const char * _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) int __cdecl _scprintf_l(const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _scprintf_p_l(const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vscprintf_l(const char * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vscprintf_p_l(const char * _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) int __cdecl _snprintf_l(char * _DstBuf, size_t _MaxCount, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _snprintf_c_l(char * _DstBuf, size_t _MaxCount, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _snprintf_s_l(char * _DstBuf, size_t _DstSize, size_t _MaxCount, const char * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vsnprintf_l(char * _DstBuf, size_t _MaxCount, const char * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vsnprintf_c_l(char * _DstBuf, size_t _MaxCount, const char *, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vsnprintf_s_l(char * _DstBuf, size_t _DstSize, size_t _MaxCount, const char* _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) FILE * __cdecl _wfsopen(const wchar_t * _Filename, const wchar_t * _Mode, int _ShFlag);

__declspec(dllimport) wint_t __cdecl fgetwc(FILE * _File);
__declspec(dllimport) wint_t __cdecl _fgetwchar(void);
__declspec(dllimport) wint_t __cdecl fputwc(wchar_t _Ch, FILE * _File);
__declspec(dllimport) wint_t __cdecl _fputwchar(wchar_t _Ch);
__declspec(dllimport) wint_t __cdecl getwc(FILE * _File);
__declspec(dllimport) wint_t __cdecl getwchar(void);
__declspec(dllimport) wint_t __cdecl putwc(wchar_t _Ch, FILE * _File);
__declspec(dllimport) wint_t __cdecl putwchar(wchar_t _Ch);
__declspec(dllimport) wint_t __cdecl ungetwc(wint_t _Ch, FILE * _File);

__declspec(dllimport) wchar_t * __cdecl fgetws(wchar_t * _Dst, int _SizeInWords, FILE * _File);
__declspec(dllimport) int __cdecl fputws(const wchar_t * _Str, FILE * _File);
__declspec(dllimport) wchar_t * __cdecl _getws_s(wchar_t * _Str, size_t _SizeInWords);

__declspec(dllimport) wchar_t * __cdecl _getws(wchar_t *_String);
__declspec(dllimport) int __cdecl _putws(const wchar_t * _Str);

__declspec(dllimport) int __cdecl fwprintf(FILE * _File, const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl fwprintf_s(FILE * _File, const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl wprintf(const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl wprintf_s(const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl _scwprintf(const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl vfwprintf(FILE * _File, const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vfwscanf(FILE * _File, const wchar_t * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vfwprintf_s(FILE * _File, const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vfwscanf_s(FILE * _File, const wchar_t * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vwprintf(const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vwscanf(const wchar_t * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vwprintf_s(const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vwscanf_s(const wchar_t * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl swprintf_s(wchar_t * _Dst, size_t _SizeInWords, const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl vswprintf_s(wchar_t * _Dst, size_t _SizeInWords, const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl vswscanf_s(const wchar_t * _Src, const wchar_t * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl vswscanf(const wchar_t * _srcBuf, const wchar_t * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl _swprintf_c(wchar_t * _DstBuf, size_t _SizeInWords, const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _vswprintf_c(wchar_t * _DstBuf, size_t _SizeInWords, const wchar_t * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl _snwprintf_s(wchar_t * _DstBuf, size_t _SizeInWords, size_t _MaxCount, const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl _vsnwprintf_s(wchar_t * _DstBuf, size_t _SizeInWords, size_t _MaxCount, const wchar_t * _Format, va_list _ArgList);

#pragma warning(push)
#pragma warning(disable:4793)
__declspec(dllimport) int __cdecl _snwprintf(wchar_t *_Dest, size_t _Count, const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _vsnwprintf(wchar_t *_Dest, size_t _Count, const wchar_t * _Format, va_list _Args);
#pragma warning(pop)

__declspec(dllimport) int __cdecl _fwprintf_p(FILE * _File, const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _wprintf_p(const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _vfwprintf_p(FILE * _File, const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _vwprintf_p(const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _swprintf_p(wchar_t * _DstBuf, size_t _MaxCount, const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _vswprintf_p(wchar_t * _DstBuf, size_t _MaxCount, const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _scwprintf_p(const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _vscwprintf_p(const wchar_t * _Format, va_list _ArgList);

__declspec(dllimport) int __cdecl _wprintf_l(const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _wprintf_p_l(const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _wprintf_s_l(const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vwprintf_l(const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vwprintf_p_l(const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vwprintf_s_l(const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) int __cdecl _fwprintf_l(FILE * _File, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _fwprintf_p_l(FILE * _File, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _fwprintf_s_l(FILE * _File, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vfwprintf_l(FILE * _File, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vfwprintf_p_l(FILE * _File, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vfwprintf_s_l(FILE * _File, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) int __cdecl _swprintf_c_l(wchar_t * _DstBuf, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _swprintf_p_l(wchar_t * _DstBuf, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _swprintf_s_l(wchar_t * _DstBuf, size_t _DstSize, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vswprintf_c_l(wchar_t * _DstBuf, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vswprintf_p_l(wchar_t * _DstBuf, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vswprintf_s_l(wchar_t * _DstBuf, size_t _DstSize, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) int __cdecl _scwprintf_l(const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _scwprintf_p_l(const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vscwprintf_p_l(const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);

__declspec(dllimport) int __cdecl _snwprintf_l(wchar_t * _DstBuf, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _snwprintf_s_l(wchar_t * _DstBuf, size_t _DstSize, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _vsnwprintf_l(wchar_t * _DstBuf, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl _vsnwprintf_s_l(wchar_t * _DstBuf, size_t _DstSize, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);

#pragma warning(push)
#pragma warning(disable:4141 4996 4793)
__declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(dllimport) int __cdecl _swprintf(wchar_t *_Dest, const wchar_t * _Format, ...);
__declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(dllimport) int __cdecl _vswprintf(wchar_t *_Dest, const wchar_t * _Format, va_list _Args);
__declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(dllimport) int __cdecl __swprintf_l(wchar_t *_Dest, const wchar_t * _Format, _locale_t _Plocinfo, ...);
__declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(dllimport) int __cdecl __vswprintf_l(wchar_t *_Dest, const wchar_t * _Format, _locale_t _Plocinfo, va_list _Args);
#pragma warning(pop)

#pragma once

#pragma warning( push )
#pragma warning( disable : 4793 4412 )
static __inline int swprintf(wchar_t * _String, size_t _Count, const wchar_t * _Format, ...)
{
	va_list _Arglist;
	int _Ret;
	(_Arglist = (va_list)(&(_Format)) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1)));
	_Ret = _vswprintf_c_l(_String, _Count, _Format, ((void *)0), _Arglist);
	(_Arglist = (va_list)0);
	return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
static __inline int __cdecl vswprintf(wchar_t * _String, size_t _Count, const wchar_t * _Format, va_list _Ap)
{
	return _vswprintf_c_l(_String, _Count, _Format, ((void *)0), _Ap);
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4793 4412 )
static __inline int _swprintf_l(wchar_t * _String, size_t _Count, const wchar_t * _Format, _locale_t _Plocinfo, ...)
{
	va_list _Arglist;
	int _Ret;
	(_Arglist = (va_list)(&(_Plocinfo)) + ((sizeof(_Plocinfo) + sizeof(int) - 1) & ~(sizeof(int) - 1)));
	_Ret = _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Arglist);
	(_Arglist = (va_list)0);
	return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
static __inline int __cdecl _vswprintf_l(wchar_t * _String, size_t _Count, const wchar_t * _Format, _locale_t _Plocinfo, va_list _Ap)
{
	return _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Ap);
}
#pragma warning( pop )

__declspec(dllimport) wchar_t * __cdecl _wtempnam(const wchar_t * _Directory, const wchar_t * _FilePrefix);

__declspec(dllimport) int __cdecl _vscwprintf(const wchar_t * _Format, va_list _ArgList);
__declspec(dllimport) int __cdecl _vscwprintf_l(const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
__declspec(dllimport) int __cdecl fwscanf(FILE * _File, const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _fwscanf_l(FILE * _File, const wchar_t * _Format, _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

__declspec(dllimport) int __cdecl fwscanf_s(FILE * _File, const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl _fwscanf_s_l(FILE * _File, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl swscanf(const wchar_t * _Src, const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _swscanf_l(const wchar_t * _Src, const wchar_t * _Format, _locale_t _Locale, ...);

__declspec(dllimport) int __cdecl swscanf_s(const wchar_t *_Src, const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl _swscanf_s_l(const wchar_t * _Src, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _snwscanf(const wchar_t * _Src, size_t _MaxCount, const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _snwscanf_l(const wchar_t * _Src, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl _snwscanf_s(const wchar_t * _Src, size_t _MaxCount, const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _snwscanf_s_l(const wchar_t * _Src, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, ...);
__declspec(dllimport) int __cdecl wscanf(const wchar_t * _Format, ...);
__declspec(dllimport) int __cdecl _wscanf_l(const wchar_t * _Format, _locale_t _Locale, ...);

__declspec(dllimport) int __cdecl wscanf_s(const wchar_t * _Format, ...);

__declspec(dllimport) int __cdecl _wscanf_s_l(const wchar_t * _Format, _locale_t _Locale, ...);
#pragma warning(pop)

__declspec(dllimport) FILE * __cdecl _wfdopen(int _FileHandle, const wchar_t * _Mode);
__declspec(dllimport) FILE * __cdecl _wfopen(const wchar_t * _Filename, const wchar_t * _Mode);
__declspec(dllimport) errno_t __cdecl _wfopen_s(FILE ** _File, const wchar_t * _Filename, const wchar_t * _Mode);
__declspec(dllimport) FILE * __cdecl _wfreopen(const wchar_t * _Filename, const wchar_t * _Mode, FILE * _OldFile);
__declspec(dllimport) errno_t __cdecl _wfreopen_s(FILE ** _File, const wchar_t * _Filename, const wchar_t * _Mode, FILE * _OldFile);

__declspec(dllimport) void __cdecl _wperror(const wchar_t * _ErrMsg);

__declspec(dllimport) FILE * __cdecl _wpopen(const wchar_t *_Command, const wchar_t * _Mode);

__declspec(dllimport) int __cdecl _wremove(const wchar_t * _Filename);
__declspec(dllimport) errno_t __cdecl _wtmpnam_s(wchar_t * _DstBuf, size_t _SizeInWords);

__declspec(dllimport) wchar_t * __cdecl _wtmpnam(wchar_t *_Buffer);

__declspec(dllimport) wint_t __cdecl _fgetwc_nolock(FILE * _File);
__declspec(dllimport) wint_t __cdecl _fputwc_nolock(wchar_t _Ch, FILE * _File);
__declspec(dllimport) wint_t __cdecl _ungetwc_nolock(wint_t _Ch, FILE * _File);

__declspec(dllimport) void __cdecl _lock_file(FILE * _File);
__declspec(dllimport) void __cdecl _unlock_file(FILE * _File);

__declspec(dllimport) int __cdecl _fclose_nolock(FILE * _File);
__declspec(dllimport) int __cdecl _fflush_nolock(FILE * _File);
__declspec(dllimport) size_t __cdecl _fread_nolock(void * _DstBuf, size_t _ElementSize, size_t _Count, FILE * _File);
__declspec(dllimport) size_t __cdecl _fread_nolock_s(void * _DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE * _File);
__declspec(dllimport) int __cdecl _fseek_nolock(FILE * _File, long _Offset, int _Origin);
__declspec(dllimport) long __cdecl _ftell_nolock(FILE * _File);
__declspec(dllimport) int __cdecl _fseeki64_nolock(FILE * _File, __int64 _Offset, int _Origin);
__declspec(dllimport) __int64 __cdecl _ftelli64_nolock(FILE * _File);
__declspec(dllimport) size_t __cdecl _fwrite_nolock(const void * _DstBuf, size_t _Size, size_t _Count, FILE * _File);
__declspec(dllimport) int __cdecl _ungetc_nolock(int _Ch, FILE * _File);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_tempnam" ". See online help for details.")) __declspec(dllimport) char * __cdecl tempnam(const char * _Directory, const char * _FilePrefix);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fcloseall" ". See online help for details.")) __declspec(dllimport) int __cdecl fcloseall(void);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fdopen" ". See online help for details.")) __declspec(dllimport) FILE * __cdecl fdopen(int _FileHandle, const char * _Format);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fgetchar" ". See online help for details.")) __declspec(dllimport) int __cdecl fgetchar(void);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fileno" ". See online help for details.")) __declspec(dllimport) int __cdecl fileno(FILE * _File);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_flushall" ". See online help for details.")) __declspec(dllimport) int __cdecl flushall(void);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fputchar" ". See online help for details.")) __declspec(dllimport) int __cdecl fputchar(int _Ch);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_getw" ". See online help for details.")) __declspec(dllimport) int __cdecl getw(FILE * _File);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_putw" ". See online help for details.")) __declspec(dllimport) int __cdecl putw(int _Ch, FILE * _File);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_rmtmp" ". See online help for details.")) __declspec(dllimport) int __cdecl rmtmp(void);

#pragma pack(pop)

#pragma once

#pragma once

#pragma pack(push,8)

typedef int(__cdecl * _onexit_t)(void);

typedef struct _div_t {
	int quot;
	int rem;
} div_t;

typedef struct _ldiv_t {
	long quot;
	long rem;
} ldiv_t;

typedef struct _lldiv_t {
	long long quot;
	long long rem;
} lldiv_t;

#pragma pack(4)
typedef struct {
	unsigned char ld[10];
} _LDOUBLE;
#pragma pack()

typedef struct {
	double x;
} _CRT_DOUBLE;

typedef struct {
	float f;
} _CRT_FLOAT;

typedef struct {

	long double x;
} _LONGDOUBLE;

#pragma pack(4)
typedef struct {
	unsigned char ld12[12];
} _LDBL12;
#pragma pack()

__declspec(dllimport) extern int __mb_cur_max;

__declspec(dllimport) int __cdecl ___mb_cur_max_func(void);
__declspec(dllimport) int __cdecl ___mb_cur_max_l_func(_locale_t);

typedef void(__cdecl *_purecall_handler)(void);

__declspec(dllimport) _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
__declspec(dllimport) _purecall_handler __cdecl _get_purecall_handler(void);

typedef void(__cdecl *_invalid_parameter_handler)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t);

__declspec(dllimport) _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
__declspec(dllimport) _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

__declspec(dllimport) unsigned long * __cdecl __doserrno(void);

errno_t __cdecl _set_doserrno(unsigned long _Value);
errno_t __cdecl _get_doserrno(unsigned long * _Value);

__declspec(dllimport)  char ** __cdecl __sys_errlist(void);

__declspec(dllimport)  int * __cdecl __sys_nerr(void);

__declspec(dllimport) int *          __cdecl __p___argc(void);
__declspec(dllimport) char ***       __cdecl __p___argv(void);
__declspec(dllimport) wchar_t ***    __cdecl __p___wargv(void);
__declspec(dllimport) char ***       __cdecl __p__environ(void);
__declspec(dllimport) wchar_t ***    __cdecl __p__wenviron(void);

__declspec(dllimport) char **        __cdecl __p__pgmptr(void);
__declspec(dllimport) wchar_t **     __cdecl __p__wpgmptr(void);

__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char ** __argv;
__declspec(dllimport) extern wchar_t ** __wargv;

__declspec(dllimport) extern char ** _environ;
__declspec(dllimport) extern wchar_t ** _wenviron;

__declspec(dllimport) extern char * _pgmptr;
__declspec(dllimport) extern wchar_t * _wpgmptr;

errno_t __cdecl _get_pgmptr(char ** _Value);
errno_t __cdecl _get_wpgmptr(wchar_t ** _Value);

__declspec(dllimport) extern int _fmode;

__declspec(dllimport) errno_t __cdecl _set_fmode(int _Mode);
__declspec(dllimport) errno_t __cdecl _get_fmode(int * _PMode);

__declspec(dllimport) __declspec(noreturn) void __cdecl exit(int _Code);

__declspec(dllimport) __declspec(noreturn) void __cdecl _exit(int _Code);
__declspec(dllimport) __declspec(noreturn) void __cdecl abort(void);

__declspec(dllimport) unsigned int __cdecl _set_abort_behavior(unsigned int _Flags, unsigned int _Mask);

int       __cdecl abs(int _X);
long      __cdecl labs(long _X);
long long __cdecl llabs(long long _X);

__int64    __cdecl _abs64(__int64);

int    __cdecl atexit(void(__cdecl *)(void));

__declspec(dllimport) double  __cdecl atof(const char *_String);
__declspec(dllimport) double  __cdecl _atof_l(const char *_String, _locale_t _Locale);
__declspec(dllimport)  int    __cdecl atoi(const char *_Str);
__declspec(dllimport) int    __cdecl _atoi_l(const char *_Str, _locale_t _Locale);
__declspec(dllimport) long   __cdecl atol(const char *_Str);
__declspec(dllimport) long   __cdecl _atol_l(const char *_Str, _locale_t _Locale);
__declspec(dllimport) long long __cdecl atoll(const char *_Str);
__declspec(dllimport) long long __cdecl _atoll_l(const char *_Str, _locale_t _Locale);

__declspec(dllimport) void * __cdecl bsearch_s(const void * _Key, const void * _Base,
	rsize_t _NumOfElements, rsize_t _SizeOfElements,
	int(__cdecl * _PtFuncCompare)(void *, const void *, const void *), void * _Context);

__declspec(dllimport) void * __cdecl bsearch(const void * _Key, const void * _Base,
	size_t _NumOfElements, size_t _SizeOfElements,
	int(__cdecl * _PtFuncCompare)(const void *, const void *));

__declspec(dllimport) void __cdecl qsort_s(void * _Base,
	rsize_t _NumOfElements, rsize_t _SizeOfElements,
	int(__cdecl * _PtFuncCompare)(void *, const void *, const void *), void *_Context);

__declspec(dllimport) void __cdecl qsort(void * _Base,
	size_t _NumOfElements, size_t _SizeOfElements,
	int(__cdecl * _PtFuncCompare)(const void *, const void *));

unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
unsigned long  __cdecl _byteswap_ulong(unsigned long _Long);
unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
__declspec(dllimport) div_t  __cdecl div(int _Numerator, int _Denominator);

__declspec(dllimport)  char * __cdecl getenv(const char * _VarName);

__declspec(dllimport) errno_t __cdecl getenv_s(size_t * _ReturnSize, char * _DstBuf, rsize_t _DstSize, const char * _VarName);

__declspec(dllimport) errno_t __cdecl _dupenv_s(char **_PBuffer, size_t * _PBufferSizeInBytes, const char * _VarName);

__declspec(dllimport) errno_t __cdecl _itoa_s(int _Value, char * _DstBuf, size_t _Size, int _Radix);

__declspec(dllimport) char * __cdecl _itoa(int _Value, char *_Dest, int _Radix);
__declspec(dllimport) errno_t __cdecl _i64toa_s(__int64 _Val, char * _DstBuf, size_t _Size, int _Radix);
__declspec(dllimport)  char * __cdecl _i64toa(__int64 _Val, char * _DstBuf, int _Radix);
__declspec(dllimport) errno_t __cdecl _ui64toa_s(unsigned __int64 _Val, char * _DstBuf, size_t _Size, int _Radix);
__declspec(dllimport)  char * __cdecl _ui64toa(unsigned __int64 _Val, char * _DstBuf, int _Radix);
__declspec(dllimport) __int64 __cdecl _atoi64(const char * _String);
__declspec(dllimport) __int64 __cdecl _atoi64_l(const char * _String, _locale_t _Locale);
__declspec(dllimport) __int64 __cdecl _strtoi64(const char * _String, char ** _EndPtr, int _Radix);
__declspec(dllimport) __int64 __cdecl _strtoi64_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) unsigned __int64 __cdecl _strtoui64(const char * _String, char ** _EndPtr, int _Radix);
__declspec(dllimport) unsigned __int64 __cdecl _strtoui64_l(const char * _String, char ** _EndPtr, int  _Radix, _locale_t _Locale);
__declspec(dllimport) ldiv_t __cdecl ldiv(long _Numerator, long _Denominator);
__declspec(dllimport) lldiv_t __cdecl lldiv(long long _Numerator, long long _Denominator);

__declspec(dllimport) errno_t __cdecl _ltoa_s(long _Val, char * _DstBuf, size_t _Size, int _Radix);

__declspec(dllimport) char * __cdecl _ltoa(long _Value, char *_Dest, int _Radix);
__declspec(dllimport) int    __cdecl mblen(const char * _Ch, size_t _MaxCount);
__declspec(dllimport) int    __cdecl _mblen_l(const char * _Ch, size_t _MaxCount, _locale_t _Locale);
__declspec(dllimport) size_t __cdecl _mbstrlen(const char * _Str);
__declspec(dllimport) size_t __cdecl _mbstrlen_l(const char *_Str, _locale_t _Locale);
__declspec(dllimport) size_t __cdecl _mbstrnlen(const char *_Str, size_t _MaxCount);
__declspec(dllimport) size_t __cdecl _mbstrnlen_l(const char *_Str, size_t _MaxCount, _locale_t _Locale);
__declspec(dllimport) int    __cdecl mbtowc(wchar_t * _DstCh, const char * _SrcCh, size_t _SrcSizeInBytes);
__declspec(dllimport) int    __cdecl _mbtowc_l(wchar_t * _DstCh, const char * _SrcCh, size_t _SrcSizeInBytes, _locale_t _Locale);
__declspec(dllimport) errno_t __cdecl mbstowcs_s(size_t * _PtNumOfCharConverted, wchar_t * _DstBuf, size_t _SizeInWords, const char * _SrcBuf, size_t _MaxCount);

__declspec(dllimport) size_t __cdecl mbstowcs(wchar_t *_Dest, const char * _Source, size_t _MaxCount);

__declspec(dllimport) errno_t __cdecl _mbstowcs_s_l(size_t * _PtNumOfCharConverted, wchar_t * _DstBuf, size_t _SizeInWords, const char * _SrcBuf, size_t _MaxCount, _locale_t _Locale);

__declspec(dllimport) size_t __cdecl _mbstowcs_l(wchar_t *_Dest, const char * _Source, size_t _MaxCount, _locale_t _Locale);

__declspec(dllimport) int    __cdecl rand(void);

__declspec(dllimport) int    __cdecl _set_error_mode(int _Mode);

__declspec(dllimport) void   __cdecl srand(unsigned int _Seed);
__declspec(dllimport) double __cdecl strtod(const char * _Str, char ** _EndPtr);
__declspec(dllimport) double __cdecl _strtod_l(const char * _Str, char ** _EndPtr, _locale_t _Locale);
__declspec(dllimport) long   __cdecl strtol(const char * _Str, char ** _EndPtr, int _Radix);
__declspec(dllimport) long   __cdecl _strtol_l(const char *_Str, char **_EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) long long  __cdecl strtoll(const char * _Str, char ** _EndPtr, int _Radix);
__declspec(dllimport) long long  __cdecl _strtoll_l(const char * _Str, char ** _EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) unsigned long __cdecl strtoul(const char * _Str, char ** _EndPtr, int _Radix);
__declspec(dllimport) unsigned long __cdecl _strtoul_l(const char * _Str, char **_EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) unsigned long long __cdecl strtoull(const char * _Str, char ** _EndPtr, int _Radix);
__declspec(dllimport) unsigned long long __cdecl _strtoull_l(const char * _Str, char ** _EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) long double __cdecl strtold(const char * _Str, char ** _EndPtr);
__declspec(dllimport) long double __cdecl _strtold_l(const char * _Str, char ** _EndPtr, _locale_t _Locale);
__declspec(dllimport) float __cdecl strtof(const char * _Str, char ** _EndPtr);
__declspec(dllimport) float __cdecl _strtof_l(const char * _Str, char ** _EndPtr, _locale_t _Locale);

__declspec(dllimport) int __cdecl system(const char * _Command);

__declspec(dllimport) errno_t __cdecl _ultoa_s(unsigned long _Val, char * _DstBuf, size_t _Size, int _Radix);

__declspec(dllimport) char * __cdecl _ultoa(unsigned long _Value, char *_Dest, int _Radix);
__declspec(dllimport)  int    __cdecl wctomb(char * _MbCh, wchar_t _WCh);
__declspec(dllimport)  int    __cdecl _wctomb_l(char * _MbCh, wchar_t _WCh, _locale_t _Locale);

__declspec(dllimport) errno_t __cdecl wctomb_s(int * _SizeConverted, char * _MbCh, rsize_t _SizeInBytes, wchar_t _WCh);

__declspec(dllimport) errno_t __cdecl _wctomb_s_l(int * _SizeConverted, char * _MbCh, size_t _SizeInBytes, wchar_t _WCh, _locale_t _Locale);
__declspec(dllimport) errno_t __cdecl wcstombs_s(size_t * _PtNumOfCharConverted, char * _Dst, size_t _DstSizeInBytes, const wchar_t * _Src, size_t _MaxCountInBytes);

__declspec(dllimport) size_t __cdecl wcstombs(char *_Dest, const wchar_t * _Source, size_t _MaxCount);
__declspec(dllimport) errno_t __cdecl _wcstombs_s_l(size_t * _PtNumOfCharConverted, char * _Dst, size_t _DstSizeInBytes, const wchar_t * _Src, size_t _MaxCountInBytes, _locale_t _Locale);

__declspec(dllimport) size_t __cdecl _wcstombs_l(char *_Dest, const wchar_t * _Source, size_t _MaxCount, _locale_t _Locale);

__declspec(dllimport)  __declspec(noalias) __declspec(restrict)    void * __cdecl calloc(__declspec(guard(overflow)) size_t _Count, __declspec(guard(overflow)) size_t _Size);
__declspec(dllimport)                     __declspec(noalias)                                                                             void   __cdecl free(void * _Memory);
__declspec(dllimport)  __declspec(noalias) __declspec(restrict)                              void * __cdecl malloc(__declspec(guard(overflow)) size_t _Size);

__declspec(dllimport) __declspec(noalias) __declspec(restrict)                           void * __cdecl realloc(void * _Memory, __declspec(guard(overflow)) size_t _NewSize);

__declspec(dllimport) __declspec(noalias) __declspec(restrict)                       void * __cdecl _recalloc(void * _Memory, __declspec(guard(overflow)) size_t _Count, __declspec(guard(overflow)) size_t _Size);
__declspec(dllimport)                     __declspec(noalias)                                                                             void   __cdecl _aligned_free(void * _Memory);
__declspec(dllimport) __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_malloc(__declspec(guard(overflow)) size_t _Size, size_t _Alignment);
__declspec(dllimport) __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_offset_malloc(__declspec(guard(overflow)) size_t _Size, size_t _Alignment, size_t _Offset);

__declspec(dllimport) __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_realloc(void * _Memory, __declspec(guard(overflow)) size_t _NewSize, size_t _Alignment);

__declspec(dllimport) __declspec(noalias) __declspec(restrict)                       void * __cdecl _aligned_recalloc(void * _Memory, __declspec(guard(overflow)) size_t _Count, __declspec(guard(overflow)) size_t _Size, size_t _Alignment);

__declspec(dllimport) __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_offset_realloc(void * _Memory, __declspec(guard(overflow)) size_t _NewSize, size_t _Alignment, size_t _Offset);

__declspec(dllimport) __declspec(noalias) __declspec(restrict)                       void * __cdecl _aligned_offset_recalloc(void * _Memory, __declspec(guard(overflow)) size_t _Count, __declspec(guard(overflow)) size_t _Size, size_t _Alignment, size_t _Offset);
__declspec(dllimport)                                                  size_t __cdecl _aligned_msize(void * _Memory, size_t _Alignment, size_t _Offset);

__declspec(dllimport) errno_t __cdecl _itow_s(int _Val, wchar_t * _DstBuf, size_t _SizeInWords, int _Radix);

__declspec(dllimport) wchar_t * __cdecl _itow(int _Value, wchar_t *_Dest, int _Radix);
__declspec(dllimport) errno_t __cdecl _ltow_s(long _Val, wchar_t * _DstBuf, size_t _SizeInWords, int _Radix);

__declspec(dllimport) wchar_t * __cdecl _ltow(long _Value, wchar_t *_Dest, int _Radix);
__declspec(dllimport) errno_t __cdecl _ultow_s(unsigned long _Val, wchar_t * _DstBuf, size_t _SizeInWords, int _Radix);

__declspec(dllimport) wchar_t * __cdecl _ultow(unsigned long _Value, wchar_t *_Dest, int _Radix);
__declspec(dllimport) double __cdecl wcstod(const wchar_t * _Str, wchar_t ** _EndPtr);
__declspec(dllimport) double __cdecl _wcstod_l(const wchar_t *_Str, wchar_t ** _EndPtr, _locale_t _Locale);
__declspec(dllimport) long   __cdecl wcstol(const wchar_t *_Str, wchar_t ** _EndPtr, int _Radix);
__declspec(dllimport) long   __cdecl _wcstol_l(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) long long  __cdecl wcstoll(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix);
__declspec(dllimport) long long  __cdecl _wcstoll_l(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) unsigned long __cdecl wcstoul(const wchar_t *_Str, wchar_t ** _EndPtr, int _Radix);
__declspec(dllimport) unsigned long __cdecl _wcstoul_l(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) unsigned long long __cdecl wcstoull(const wchar_t *_Str, wchar_t ** _EndPtr, int _Radix);
__declspec(dllimport) unsigned long long __cdecl _wcstoull_l(const wchar_t *_Str, wchar_t ** _EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) long double __cdecl wcstold(const wchar_t * _Str, wchar_t ** _EndPtr);
__declspec(dllimport) long double __cdecl _wcstold_l(const wchar_t * _Str, wchar_t ** _EndPtr, _locale_t _Locale);
__declspec(dllimport) float __cdecl wcstof(const wchar_t * _Str, wchar_t ** _EndPtr);
__declspec(dllimport) float __cdecl _wcstof_l(const wchar_t * _Str, wchar_t ** _EndPtr, _locale_t _Locale);

__declspec(dllimport)  wchar_t * __cdecl _wgetenv(const wchar_t * _VarName);
__declspec(dllimport) errno_t __cdecl _wgetenv_s(size_t * _ReturnSize, wchar_t * _DstBuf, size_t _DstSizeInWords, const wchar_t * _VarName);

__declspec(dllimport) errno_t __cdecl _wdupenv_s(wchar_t **_Buffer, size_t *_BufferSizeInWords, const wchar_t *_VarName);

__declspec(dllimport) int __cdecl _wsystem(const wchar_t * _Command);

__declspec(dllimport) double __cdecl _wtof(const wchar_t *_Str);
__declspec(dllimport) double __cdecl _wtof_l(const wchar_t *_Str, _locale_t _Locale);
__declspec(dllimport) int __cdecl _wtoi(const wchar_t *_Str);
__declspec(dllimport) int __cdecl _wtoi_l(const wchar_t *_Str, _locale_t _Locale);
__declspec(dllimport) long __cdecl _wtol(const wchar_t *_Str);
__declspec(dllimport) long __cdecl _wtol_l(const wchar_t *_Str, _locale_t _Locale);
__declspec(dllimport) long long __cdecl _wtoll(const wchar_t *_Str);
__declspec(dllimport) long long __cdecl _wtoll_l(const wchar_t *_Str, _locale_t _Locale);

__declspec(dllimport) errno_t __cdecl _i64tow_s(__int64 _Val, wchar_t * _DstBuf, size_t _SizeInWords, int _Radix);
__declspec(dllimport)  wchar_t * __cdecl _i64tow(__int64 _Val, wchar_t * _DstBuf, int _Radix);
__declspec(dllimport) errno_t __cdecl _ui64tow_s(unsigned __int64 _Val, wchar_t * _DstBuf, size_t _SizeInWords, int _Radix);
__declspec(dllimport)  wchar_t * __cdecl _ui64tow(unsigned __int64 _Val, wchar_t * _DstBuf, int _Radix);
__declspec(dllimport) __int64   __cdecl _wtoi64(const wchar_t *_Str);
__declspec(dllimport) __int64   __cdecl _wtoi64_l(const wchar_t *_Str, _locale_t _Locale);
__declspec(dllimport) __int64   __cdecl _wcstoi64(const wchar_t * _Str, wchar_t ** _EndPtr, int _Radix);
__declspec(dllimport) __int64   __cdecl _wcstoi64_l(const wchar_t * _Str, wchar_t ** _EndPtr, int _Radix, _locale_t _Locale);
__declspec(dllimport) unsigned __int64  __cdecl _wcstoui64(const wchar_t * _Str, wchar_t ** _EndPtr, int _Radix);
__declspec(dllimport) unsigned __int64  __cdecl _wcstoui64_l(const wchar_t *_Str, wchar_t ** _EndPtr, int _Radix, _locale_t _Locale);

__declspec(dllimport) char * __cdecl _fullpath(char * _FullPath, const char * _Path, size_t _SizeInBytes);

__declspec(dllimport) errno_t __cdecl _ecvt_s(char * _DstBuf, size_t _Size, double _Val, int _NumOfDights, int * _PtDec, int * _PtSign);

__declspec(dllimport)  char * __cdecl _ecvt(double _Val, int _NumOfDigits, int * _PtDec, int * _PtSign);
__declspec(dllimport) errno_t __cdecl _fcvt_s(char * _DstBuf, size_t _Size, double _Val, int _NumOfDec, int * _PtDec, int * _PtSign);

__declspec(dllimport)  char * __cdecl _fcvt(double _Val, int _NumOfDec, int * _PtDec, int * _PtSign);
__declspec(dllimport) errno_t __cdecl _gcvt_s(char * _DstBuf, size_t _Size, double _Val, int _NumOfDigits);

__declspec(dllimport)  char * __cdecl _gcvt(double _Val, int _NumOfDigits, char * _DstBuf);

__declspec(dllimport) int __cdecl _atodbl(_CRT_DOUBLE * _Result, char * _Str);
__declspec(dllimport) int __cdecl _atoldbl(_LDOUBLE * _Result, char * _Str);
__declspec(dllimport) int __cdecl _atoflt(_CRT_FLOAT * _Result, const char * _Str);
__declspec(dllimport) int __cdecl _atodbl_l(_CRT_DOUBLE * _Result, char * _Str, _locale_t _Locale);
__declspec(dllimport) int __cdecl _atoldbl_l(_LDOUBLE * _Result, char * _Str, _locale_t _Locale);
__declspec(dllimport) int __cdecl _atoflt_l(_CRT_FLOAT * _Result, const char * _Str, _locale_t _Locale);
unsigned long __cdecl _lrotl(unsigned long _Val, int _Shift);
unsigned long __cdecl _lrotr(unsigned long _Val, int _Shift);
__declspec(dllimport) errno_t   __cdecl _makepath_s(char * _PathResult, size_t _SizeInWords, const char * _Drive, const char * _Dir, const char * _Filename,
	const char * _Ext);

__declspec(dllimport) void __cdecl _makepath(char *_Path, const char * _Drive, const char * _Dir, const char * _Filename, const char * _Ext);

_onexit_t __cdecl _onexit(_onexit_t _Func);

#pragma warning (push)
#pragma warning (disable:6540) 

__declspec(dllimport) int    __cdecl _putenv(const char * _EnvString);
__declspec(dllimport) errno_t __cdecl _putenv_s(const char * _Name, const char * _Value);

unsigned int __cdecl _rotl(unsigned int _Val, int _Shift);
unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val, int _Shift);
unsigned int __cdecl _rotr(unsigned int _Val, int _Shift);
unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val, int _Shift);
#pragma warning (pop)

__declspec(dllimport) errno_t __cdecl _searchenv_s(const char * _Filename, const char * _EnvVar, char * _ResultPath, size_t _SizeInBytes);

__declspec(dllimport) void __cdecl _searchenv(const char * _Filename, const char * _EnvVar, char *_ResultPath);

__declspec(dllimport) void   __cdecl _splitpath(const char * _FullPath, char * _Drive, char * _Dir, char * _Filename, char * _Ext);
__declspec(dllimport) errno_t  __cdecl _splitpath_s(const char * _FullPath,
	char * _Drive, size_t _DriveSize,
	char * _Dir, size_t _DirSize,
	char * _Filename, size_t _FilenameSize,
	char * _Ext, size_t _ExtSize);

__declspec(dllimport) void   __cdecl _swab(char * _Buf1, char * _Buf2, int _SizeInBytes);

__declspec(dllimport) wchar_t * __cdecl _wfullpath(wchar_t * _FullPath, const wchar_t * _Path, size_t _SizeInWords);

__declspec(dllimport) errno_t __cdecl _wmakepath_s(wchar_t * _PathResult, size_t _SIZE, const wchar_t * _Drive, const wchar_t * _Dir, const wchar_t * _Filename,
	const wchar_t * _Ext);

__declspec(dllimport) void __cdecl _wmakepath(wchar_t *_ResultPath, const wchar_t * _Drive, const wchar_t * _Dir, const wchar_t * _Filename, const wchar_t * _Ext);

__declspec(dllimport) int    __cdecl _wputenv(const wchar_t * _EnvString);
__declspec(dllimport) errno_t __cdecl _wputenv_s(const wchar_t * _Name, const wchar_t * _Value);
__declspec(dllimport) errno_t __cdecl _wsearchenv_s(const wchar_t * _Filename, const wchar_t * _EnvVar, wchar_t * _ResultPath, size_t _SizeInWords);

__declspec(dllimport) void __cdecl _wsearchenv(const wchar_t * _Filename, const wchar_t * _EnvVar, wchar_t *_ResultPath);

__declspec(dllimport) void   __cdecl _wsplitpath(const wchar_t * _FullPath, wchar_t * _Drive, wchar_t * _Dir, wchar_t * _Filename, wchar_t * _Ext);
__declspec(dllimport) errno_t __cdecl _wsplitpath_s(const wchar_t * _FullPath,
	wchar_t * _Drive, size_t _DriveSize,
	wchar_t * _Dir, size_t _DirSize,
	wchar_t * _Filename, size_t _FilenameSize,
	wchar_t * _Ext, size_t _ExtSize);

__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "SetErrorMode" " instead. See online help for details.")) __declspec(dllimport) void __cdecl _seterrormode(int _Mode);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "Beep" " instead. See online help for details.")) __declspec(dllimport) void __cdecl _beep(unsigned _Frequency, unsigned _Duration);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "Sleep" " instead. See online help for details.")) __declspec(dllimport) void __cdecl _sleep(unsigned long _Duration);

#pragma warning(push)
#pragma warning(disable: 4141) 
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ecvt" ". See online help for details."))  __declspec(dllimport) char * __cdecl ecvt(double _Val, int _NumOfDigits, int * _PtDec, int * _PtSign);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fcvt" ". See online help for details."))  __declspec(dllimport) char * __cdecl fcvt(double _Val, int _NumOfDec, int * _PtDec, int * _PtSign);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_gcvt" ". See online help for details."))           __declspec(dllimport) char * __cdecl gcvt(double _Val, int _NumOfDigits, char * _DstBuf);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_itoa" ". See online help for details."))           __declspec(dllimport) char * __cdecl itoa(int _Val, char * _DstBuf, int _Radix);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ltoa" ". See online help for details."))           __declspec(dllimport) char * __cdecl ltoa(long _Val, char * _DstBuf, int _Radix);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_putenv" ". See online help for details.")) __declspec(dllimport) int    __cdecl putenv(const char * _EnvString);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_swab" ". See online help for details."))                                                                           __declspec(dllimport) void   __cdecl swab(char * _Buf1, char * _Buf2, int _SizeInBytes);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ultoa" ". See online help for details."))         __declspec(dllimport) char * __cdecl ultoa(unsigned long _Val, char * _Dstbuf, int _Radix);
#pragma warning(pop)
_onexit_t __cdecl onexit(_onexit_t _Func);

#pragma pack(pop)

#pragma once

__declspec(dllimport) void *  __cdecl _memccpy(void * _Dst, const void * _Src, int _Val, size_t _MaxCount);
__declspec(dllimport)  void *  __cdecl memchr(const void * _Buf, int _Val, size_t _MaxCount);
__declspec(dllimport) int     __cdecl _memicmp(const void * _Buf1, const void * _Buf2, size_t _Size);
__declspec(dllimport) int     __cdecl _memicmp_l(const void * _Buf1, const void * _Buf2, size_t _Size, _locale_t _Locale);
int     __cdecl memcmp(const void * _Buf1, const void * _Buf2, size_t _Size);

void *  __cdecl memcpy(void * _Dst, const void * _Src, size_t _Size);

__declspec(dllimport) errno_t  __cdecl memcpy_s(void * _Dst, rsize_t _DstSize, const void * _Src, rsize_t _MaxCount);



void *  __cdecl memset(void * _Dst, int _Val, size_t _Size);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_memccpy" ". See online help for details.")) __declspec(dllimport) void * __cdecl memccpy(void * _Dst, const void * _Src, int _Val, size_t _Size);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_memicmp" ". See online help for details.")) __declspec(dllimport) int __cdecl memicmp(const void * _Buf1, const void * _Buf2, size_t _Size);

__declspec(dllimport) errno_t __cdecl _strset_s(char * _Dst, size_t _DstSize, int _Value);

char * __cdecl _strset(char *_Dest, int _Value);

__declspec(dllimport) errno_t __cdecl strcpy_s(char * _Dst, rsize_t _SizeInBytes, const char * _Src);

char * __cdecl strcpy(char *_Dest, const char * _Source);

__declspec(dllimport) errno_t __cdecl strcat_s(char * _Dst, rsize_t _SizeInBytes, const char * _Src);

char * __cdecl strcat(char *_Dest, const char * _Source);

int     __cdecl strcmp(const char * _Str1, const char * _Str2);
size_t  __cdecl strlen(const char * _Str);
__declspec(dllimport)

size_t  __cdecl strnlen(const char * _Str, size_t _MaxCount);

static __inline

size_t  __cdecl strnlen_s(const char * _Str, size_t _MaxCount)
{
	return (_Str == 0) ? 0 : strnlen(_Str, _MaxCount);
}

__declspec(dllimport) errno_t __cdecl memmove_s(void * _Dst, rsize_t _DstSize, const void * _Src, rsize_t _MaxCount);

__declspec(dllimport)  void *  __cdecl memmove(void * _Dst, const void * _Src, size_t _Size);

__declspec(dllimport) char *  __cdecl _strdup(const char * _Src);

__declspec(dllimport)  char *  __cdecl strchr(const char * _Str, int _Val);
__declspec(dllimport) int     __cdecl _stricmp(const char * _Str1, const char * _Str2);
__declspec(dllimport) int     __cdecl _strcmpi(const char * _Str1, const char * _Str2);
__declspec(dllimport) int     __cdecl _stricmp_l(const char * _Str1, const char * _Str2, _locale_t _Locale);
__declspec(dllimport) int     __cdecl strcoll(const char * _Str1, const  char * _Str2);
__declspec(dllimport) int     __cdecl _strcoll_l(const char * _Str1, const char * _Str2, _locale_t _Locale);
__declspec(dllimport) int     __cdecl _stricoll(const char * _Str1, const char * _Str2);
__declspec(dllimport) int     __cdecl _stricoll_l(const char * _Str1, const char * _Str2, _locale_t _Locale);
__declspec(dllimport) int     __cdecl _strncoll(const char * _Str1, const char * _Str2, size_t _MaxCount);
__declspec(dllimport) int     __cdecl _strncoll_l(const char * _Str1, const char * _Str2, size_t _MaxCount, _locale_t _Locale);
__declspec(dllimport) int     __cdecl _strnicoll(const char * _Str1, const char * _Str2, size_t _MaxCount);
__declspec(dllimport) int     __cdecl _strnicoll_l(const char * _Str1, const char * _Str2, size_t _MaxCount, _locale_t _Locale);
__declspec(dllimport) size_t  __cdecl strcspn(const char * _Str, const char * _Control);
__declspec(dllimport) char *  __cdecl _strerror(const char * _ErrMsg);
__declspec(dllimport) errno_t __cdecl _strerror_s(char * _Buf, size_t _SizeInBytes, const char * _ErrMsg);

__declspec(dllimport) char *  __cdecl strerror(int);

__declspec(dllimport) errno_t __cdecl strerror_s(char * _Buf, size_t _SizeInBytes, int _ErrNum);

__declspec(dllimport) errno_t __cdecl _strlwr_s(char * _Str, size_t _Size);

__declspec(dllimport) char * __cdecl _strlwr(char *_String);
__declspec(dllimport) errno_t __cdecl _strlwr_s_l(char * _Str, size_t _Size, _locale_t _Locale);

__declspec(dllimport) char * __cdecl _strlwr_l(char *_String, _locale_t _Locale);

__declspec(dllimport) errno_t __cdecl strncat_s(char * _Dst, rsize_t _SizeInBytes, const char * _Src, rsize_t _MaxCount);

#pragma warning(push)
#pragma warning(disable:6059)

__declspec(dllimport) char * __cdecl strncat(char *_Dest, const char * _Source, size_t _Count);
#pragma warning(pop)
__declspec(dllimport) int     __cdecl strncmp(const char * _Str1, const char * _Str2, size_t _MaxCount);
__declspec(dllimport) int     __cdecl _strnicmp(const char * _Str1, const char * _Str2, size_t _MaxCount);
__declspec(dllimport) int     __cdecl _strnicmp_l(const char * _Str1, const char * _Str2, size_t _MaxCount, _locale_t _Locale);

__declspec(dllimport) errno_t __cdecl strncpy_s(char * _Dst, rsize_t _SizeInBytes, const char * _Src, rsize_t _MaxCount);

__declspec(dllimport) char * __cdecl strncpy(char *_Dest, const char * _Source, size_t _Count);
__declspec(dllimport) errno_t __cdecl _strnset_s(char * _Str, size_t _SizeInBytes, int _Val, size_t _MaxCount);

__declspec(dllimport) char * __cdecl _strnset(char *_Dest, int _Val, size_t _Count);
__declspec(dllimport)  char *  __cdecl strpbrk(const char * _Str, const char * _Control);
__declspec(dllimport)  char *  __cdecl strrchr(const char * _Str, int _Ch);
__declspec(dllimport) char *  __cdecl _strrev(char * _Str);
__declspec(dllimport) size_t  __cdecl strspn(const char * _Str, const char * _Control);
__declspec(dllimport)  char *  __cdecl strstr(const char * _Str, const char * _SubStr);
__declspec(dllimport) char *  __cdecl strtok(char * _Str, const char * _Delim);

__declspec(dllimport) char *  __cdecl strtok_s(char * _Str, const char * _Delim, char ** _Context);

__declspec(dllimport) errno_t __cdecl _strupr_s(char * _Str, size_t _Size);

__declspec(dllimport) char * __cdecl _strupr(char *_String);
__declspec(dllimport) errno_t __cdecl _strupr_s_l(char * _Str, size_t _Size, _locale_t _Locale);

__declspec(dllimport) char * __cdecl _strupr_l(char *_String, _locale_t _Locale);
__declspec(dllimport) size_t  __cdecl strxfrm(char * _Dst, const char * _Src, size_t _MaxCount);
__declspec(dllimport) size_t  __cdecl _strxfrm_l(char * _Dst, const char * _Src, size_t _MaxCount, _locale_t _Locale);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strdup" ". See online help for details.")) __declspec(dllimport) char * __cdecl strdup(const char * _Src);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strcmpi" ". See online help for details.")) __declspec(dllimport) int __cdecl strcmpi(const char * _Str1, const char * _Str2);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_stricmp" ". See online help for details.")) __declspec(dllimport) int __cdecl stricmp(const char * _Str1, const char * _Str2);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strlwr" ". See online help for details.")) __declspec(dllimport) char * __cdecl strlwr(char * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strnicmp" ". See online help for details.")) __declspec(dllimport) int __cdecl strnicmp(const char * _Str1, const char * _Str, size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strnset" ". See online help for details.")) __declspec(dllimport) char * __cdecl strnset(char * _Str, int _Val, size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strrev" ". See online help for details.")) __declspec(dllimport) char * __cdecl strrev(char * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strset" ". See online help for details."))         char * __cdecl strset(char * _Str, int _Val);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strupr" ". See online help for details.")) __declspec(dllimport) char * __cdecl strupr(char * _Str);

__declspec(dllimport) wchar_t * __cdecl _wcsdup(const wchar_t * _Str);

__declspec(dllimport) errno_t __cdecl wcscat_s(wchar_t * _Dst, rsize_t _SizeInWords, const wchar_t * _Src);

__declspec(dllimport) wchar_t * __cdecl wcscat(wchar_t *_Dest, const wchar_t * _Source);

__declspec(dllimport)  wchar_t * __cdecl wcschr(const wchar_t * _Str, wchar_t _Ch);
__declspec(dllimport) int __cdecl wcscmp(const wchar_t * _Str1, const wchar_t * _Str2);

__declspec(dllimport) errno_t __cdecl wcscpy_s(wchar_t * _Dst, rsize_t _SizeInWords, const wchar_t * _Src);

__declspec(dllimport) wchar_t * __cdecl wcscpy(wchar_t *_Dest, const wchar_t * _Source);
__declspec(dllimport) size_t __cdecl wcscspn(const wchar_t * _Str, const wchar_t * _Control);
__declspec(dllimport) size_t __cdecl wcslen(const wchar_t * _Str);
__declspec(dllimport)

size_t __cdecl wcsnlen(const wchar_t * _Src, size_t _MaxCount);

static __inline

size_t __cdecl wcsnlen_s(const wchar_t * _Src, size_t _MaxCount)
{
	return (_Src == ((void *)0)) ? 0 : wcsnlen(_Src, _MaxCount);
}

__declspec(dllimport) errno_t __cdecl wcsncat_s(wchar_t * _Dst, rsize_t _SizeInWords, const wchar_t * _Src, rsize_t _MaxCount);

#pragma warning(push)
#pragma warning(disable:6059)
__declspec(dllimport) wchar_t * __cdecl wcsncat(wchar_t *_Dest, const wchar_t * _Source, size_t _Count);
#pragma warning(pop)
__declspec(dllimport) int __cdecl wcsncmp(const wchar_t * _Str1, const wchar_t * _Str2, size_t _MaxCount);

__declspec(dllimport) errno_t __cdecl wcsncpy_s(wchar_t * _Dst, rsize_t _SizeInWords, const wchar_t * _Src, rsize_t _MaxCount);

__declspec(dllimport) wchar_t * __cdecl wcsncpy(wchar_t *_Dest, const wchar_t * _Source, size_t _Count);
__declspec(dllimport)  wchar_t * __cdecl wcspbrk(const wchar_t * _Str, const wchar_t * _Control);
__declspec(dllimport)  wchar_t * __cdecl wcsrchr(const wchar_t * _Str, wchar_t _Ch);
__declspec(dllimport) size_t __cdecl wcsspn(const wchar_t * _Str, const wchar_t * _Control);

__declspec(dllimport)  wchar_t * __cdecl wcsstr(const wchar_t * _Str, const wchar_t * _SubStr);
__declspec(dllimport) wchar_t * __cdecl wcstok(wchar_t * _Str, const wchar_t * _Delim);

__declspec(dllimport) wchar_t * __cdecl wcstok_s(wchar_t * _Str, const wchar_t * _Delim, wchar_t ** _Context);

__declspec(dllimport) wchar_t * __cdecl _wcserror(int _ErrNum);
__declspec(dllimport) errno_t __cdecl _wcserror_s(wchar_t * _Buf, size_t _SizeInWords, int _ErrNum);

__declspec(dllimport) wchar_t * __cdecl __wcserror(const wchar_t * _Str);
__declspec(dllimport) errno_t __cdecl __wcserror_s(wchar_t * _Buffer, size_t _SizeInWords, const wchar_t * _ErrMsg);

__declspec(dllimport) int __cdecl _wcsicmp(const wchar_t * _Str1, const wchar_t * _Str2);
__declspec(dllimport) int __cdecl _wcsicmp_l(const wchar_t * _Str1, const wchar_t * _Str2, _locale_t _Locale);
__declspec(dllimport) int __cdecl _wcsnicmp(const wchar_t * _Str1, const wchar_t * _Str2, size_t _MaxCount);
__declspec(dllimport) int __cdecl _wcsnicmp_l(const wchar_t * _Str1, const wchar_t * _Str2, size_t _MaxCount, _locale_t _Locale);
__declspec(dllimport) errno_t __cdecl _wcsnset_s(wchar_t * _Dst, size_t _SizeInWords, wchar_t _Val, size_t _MaxCount);

__declspec(dllimport) wchar_t * __cdecl _wcsnset(wchar_t *_Str, wchar_t _Val, size_t _MaxCount);
__declspec(dllimport) wchar_t * __cdecl _wcsrev(wchar_t * _Str);
__declspec(dllimport) errno_t __cdecl _wcsset_s(wchar_t * _Dst, size_t _SizeInWords, wchar_t _Value);

__declspec(dllimport) wchar_t * __cdecl _wcsset(wchar_t *_Str, wchar_t _Val);

__declspec(dllimport) errno_t __cdecl _wcslwr_s(wchar_t * _Str, size_t _SizeInWords);

__declspec(dllimport) wchar_t * __cdecl _wcslwr(wchar_t *_String);
__declspec(dllimport) errno_t __cdecl _wcslwr_s_l(wchar_t * _Str, size_t _SizeInWords, _locale_t _Locale);

__declspec(dllimport) wchar_t * __cdecl _wcslwr_l(wchar_t *_String, _locale_t _Locale);
__declspec(dllimport) errno_t __cdecl _wcsupr_s(wchar_t * _Str, size_t _Size);

__declspec(dllimport) wchar_t * __cdecl _wcsupr(wchar_t *_String);
__declspec(dllimport) errno_t __cdecl _wcsupr_s_l(wchar_t * _Str, size_t _Size, _locale_t _Locale);

__declspec(dllimport) wchar_t * __cdecl _wcsupr_l(wchar_t *_String, _locale_t _Locale);
__declspec(dllimport) size_t __cdecl wcsxfrm(wchar_t * _Dst, const wchar_t * _Src, size_t _MaxCount);
__declspec(dllimport) size_t __cdecl _wcsxfrm_l(wchar_t * _Dst, const wchar_t *_Src, size_t _MaxCount, _locale_t _Locale);
__declspec(dllimport) int __cdecl wcscoll(const wchar_t * _Str1, const wchar_t * _Str2);
__declspec(dllimport) int __cdecl _wcscoll_l(const wchar_t * _Str1, const wchar_t * _Str2, _locale_t _Locale);
__declspec(dllimport) int __cdecl _wcsicoll(const wchar_t * _Str1, const wchar_t * _Str2);
__declspec(dllimport) int __cdecl _wcsicoll_l(const wchar_t * _Str1, const wchar_t *_Str2, _locale_t _Locale);
__declspec(dllimport) int __cdecl _wcsncoll(const wchar_t * _Str1, const wchar_t * _Str2, size_t _MaxCount);
__declspec(dllimport) int __cdecl _wcsncoll_l(const wchar_t * _Str1, const wchar_t * _Str2, size_t _MaxCount, _locale_t _Locale);
__declspec(dllimport) int __cdecl _wcsnicoll(const wchar_t * _Str1, const wchar_t * _Str2, size_t _MaxCount);
__declspec(dllimport) int __cdecl _wcsnicoll_l(const wchar_t * _Str1, const wchar_t * _Str2, size_t _MaxCount, _locale_t _Locale);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsdup" ". See online help for details.")) __declspec(dllimport) wchar_t * __cdecl wcsdup(const wchar_t * _Str);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsicmp" ". See online help for details.")) __declspec(dllimport) int __cdecl wcsicmp(const wchar_t * _Str1, const wchar_t * _Str2);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsnicmp" ". See online help for details.")) __declspec(dllimport) int __cdecl wcsnicmp(const wchar_t * _Str1, const wchar_t * _Str2, size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsnset" ". See online help for details.")) __declspec(dllimport) wchar_t * __cdecl wcsnset(wchar_t * _Str, wchar_t _Val, size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsrev" ". See online help for details.")) __declspec(dllimport) wchar_t * __cdecl wcsrev(wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsset" ". See online help for details.")) __declspec(dllimport) wchar_t * __cdecl wcsset(wchar_t * _Str, wchar_t _Val);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcslwr" ". See online help for details.")) __declspec(dllimport) wchar_t * __cdecl wcslwr(wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsupr" ". See online help for details.")) __declspec(dllimport) wchar_t * __cdecl wcsupr(wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsicoll" ". See online help for details.")) __declspec(dllimport) int __cdecl wcsicoll(const wchar_t * _Str1, const wchar_t * _Str2);

#pragma once

__declspec(dllimport) extern unsigned long  __cdecl __threadid(void);

__declspec(dllimport) extern uintptr_t __cdecl __threadhandle(void);

typedef struct lua_State lua_State;

typedef double lua_Number;

typedef long long lua_Integer;

typedef unsigned long long lua_Unsigned;

typedef ptrdiff_t lua_KContext;

typedef int(*lua_CFunction) (lua_State *L);

typedef int(*lua_KFunction) (lua_State *L, int status, lua_KContext ctx);

typedef const char * (*lua_Reader) (lua_State *L, void *ud, size_t *sz);

typedef int(*lua_Writer) (lua_State *L, const void *p, size_t sz, void *ud);

typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);

extern const char lua_ident[];

extern lua_State *(lua_newstate)(lua_Alloc f, void *ud);
extern void       (lua_close)(lua_State *L);
extern lua_State *(lua_newthread)(lua_State *L);

extern lua_CFunction(lua_atpanic) (lua_State *L, lua_CFunction panicf);

extern const lua_Number *(lua_version)(lua_State *L);

extern int   (lua_absindex)(lua_State *L, int idx);
extern int   (lua_gettop)(lua_State *L);
extern void  (lua_settop)(lua_State *L, int idx);
extern void  (lua_pushvalue)(lua_State *L, int idx);
extern void  (lua_rotate)(lua_State *L, int idx, int n);
extern void  (lua_copy)(lua_State *L, int fromidx, int toidx);
extern int   (lua_checkstack)(lua_State *L, int n);

extern void  (lua_xmove)(lua_State *from, lua_State *to, int n);

extern int             (lua_isnumber)(lua_State *L, int idx);
extern int             (lua_isstring)(lua_State *L, int idx);
extern int             (lua_iscfunction)(lua_State *L, int idx);
extern int             (lua_isinteger)(lua_State *L, int idx);
extern int             (lua_isuserdata)(lua_State *L, int idx);
extern int             (lua_type)(lua_State *L, int idx);
extern const char     *(lua_typename)(lua_State *L, int tp);

extern lua_Number(lua_tonumberx) (lua_State *L, int idx, int *isnum);
extern lua_Integer(lua_tointegerx) (lua_State *L, int idx, int *isnum);
extern int             (lua_toboolean)(lua_State *L, int idx);
extern const char     *(lua_tolstring)(lua_State *L, int idx, size_t *len);
extern size_t(lua_rawlen) (lua_State *L, int idx);
extern lua_CFunction(lua_tocfunction) (lua_State *L, int idx);
extern void	       *(lua_touserdata)(lua_State *L, int idx);
extern lua_State      *(lua_tothread)(lua_State *L, int idx);
extern const void     *(lua_topointer)(lua_State *L, int idx);

extern void  (lua_arith)(lua_State *L, int op);

extern int   (lua_rawequal)(lua_State *L, int idx1, int idx2);
extern int   (lua_compare)(lua_State *L, int idx1, int idx2, int op);

extern void        (lua_pushnil)(lua_State *L);
extern void        (lua_pushnumber)(lua_State *L, lua_Number n);
extern void        (lua_pushinteger)(lua_State *L, lua_Integer n);
extern const char *(lua_pushlstring)(lua_State *L, const char *s, size_t len);
extern const char *(lua_pushstring)(lua_State *L, const char *s);
extern const char *(lua_pushvfstring)(lua_State *L, const char *fmt,
	va_list argp);
extern const char *(lua_pushfstring)(lua_State *L, const char *fmt, ...);
extern void  (lua_pushcclosure)(lua_State *L, lua_CFunction fn, int n);
extern void  (lua_pushboolean)(lua_State *L, int b);
extern void  (lua_pushlightuserdata)(lua_State *L, void *p);
extern int   (lua_pushthread)(lua_State *L);

extern int (lua_getglobal)(lua_State *L, const char *name);
extern int (lua_gettable)(lua_State *L, int idx);
extern int (lua_getfield)(lua_State *L, int idx, const char *k);
extern int (lua_geti)(lua_State *L, int idx, lua_Integer n);
extern int (lua_rawget)(lua_State *L, int idx);
extern int (lua_rawgeti)(lua_State *L, int idx, lua_Integer n);
extern int (lua_rawgetp)(lua_State *L, int idx, const void *p);

extern void  (lua_createtable)(lua_State *L, int narr, int nrec);
extern void *(lua_newuserdata)(lua_State *L, size_t sz);
extern int   (lua_getmetatable)(lua_State *L, int objindex);
extern int  (lua_getuservalue)(lua_State *L, int idx);

extern void  (lua_setglobal)(lua_State *L, const char *name);
extern void  (lua_settable)(lua_State *L, int idx);
extern void  (lua_setfield)(lua_State *L, int idx, const char *k);
extern void  (lua_seti)(lua_State *L, int idx, lua_Integer n);
extern void  (lua_rawset)(lua_State *L, int idx);
extern void  (lua_rawseti)(lua_State *L, int idx, lua_Integer n);
extern void  (lua_rawsetp)(lua_State *L, int idx, const void *p);
extern int   (lua_setmetatable)(lua_State *L, int objindex);
extern void  (lua_setuservalue)(lua_State *L, int idx);

extern void  (lua_callk)(lua_State *L, int nargs, int nresults,
	lua_KContext ctx, lua_KFunction k);

extern int   (lua_pcallk)(lua_State *L, int nargs, int nresults, int errfunc,
	lua_KContext ctx, lua_KFunction k);

extern int   (lua_load)(lua_State *L, lua_Reader reader, void *dt,
	const char *chunkname, const char *mode);

extern int (lua_dump)(lua_State *L, lua_Writer writer, void *data, int strip);

extern int  (lua_yieldk)(lua_State *L, int nresults, lua_KContext ctx,
	lua_KFunction k);
extern int  (lua_resume)(lua_State *L, lua_State *from, int narg);
extern int  (lua_status)(lua_State *L);
extern int (lua_isyieldable)(lua_State *L);

extern int (lua_gc)(lua_State *L, int what, int data);

extern int   (lua_error)(lua_State *L);

extern int   (lua_next)(lua_State *L, int idx);

extern void  (lua_concat)(lua_State *L, int n);
extern void  (lua_len)(lua_State *L, int idx);

extern size_t(lua_stringtonumber) (lua_State *L, const char *s);

extern lua_Alloc(lua_getallocf) (lua_State *L, void **ud);
extern void      (lua_setallocf)(lua_State *L, lua_Alloc f, void *ud);

typedef struct lua_Debug lua_Debug;

typedef void(*lua_Hook) (lua_State *L, lua_Debug *ar);

extern int (lua_getstack)(lua_State *L, int level, lua_Debug *ar);
extern int (lua_getinfo)(lua_State *L, const char *what, lua_Debug *ar);
extern const char *(lua_getlocal)(lua_State *L, const lua_Debug *ar, int n);
extern const char *(lua_setlocal)(lua_State *L, const lua_Debug *ar, int n);
extern const char *(lua_getupvalue)(lua_State *L, int funcindex, int n);
extern const char *(lua_setupvalue)(lua_State *L, int funcindex, int n);

extern void *(lua_upvalueid)(lua_State *L, int fidx, int n);
extern void  (lua_upvaluejoin)(lua_State *L, int fidx1, int n1,
	int fidx2, int n2);

extern void (lua_sethook)(lua_State *L, lua_Hook func, int mask, int count);
extern lua_Hook(lua_gethook) (lua_State *L);
extern int (lua_gethookmask)(lua_State *L);
extern int (lua_gethookcount)(lua_State *L);

struct lua_Debug {
	int event;
	const char *name;
	const char *namewhat;
	const char *what;
	const char *source;
	int currentline;
	int linedefined;
	int lastlinedefined;
	unsigned char nups;
	unsigned char nparams;
	char isvararg;
	char istailcall;
	char short_src[60];

	struct CallInfo *i_ci;
};

typedef struct luaL_Reg {
	const char *name;
	lua_CFunction func;
} luaL_Reg;

extern void (luaL_checkversion_)(lua_State *L, lua_Number ver, size_t sz);

extern int (luaL_getmetafield)(lua_State *L, int obj, const char *e);
extern int (luaL_callmeta)(lua_State *L, int obj, const char *e);
extern const char *(luaL_tolstring)(lua_State *L, int idx, size_t *len);
extern int (luaL_argerror)(lua_State *L, int arg, const char *extramsg);
extern const char *(luaL_checklstring)(lua_State *L, int arg,
	size_t *l);
extern const char *(luaL_optlstring)(lua_State *L, int arg,
	const char *def, size_t *l);
extern lua_Number(luaL_checknumber) (lua_State *L, int arg);
extern lua_Number(luaL_optnumber) (lua_State *L, int arg, lua_Number def);

extern lua_Integer(luaL_checkinteger) (lua_State *L, int arg);
extern lua_Integer(luaL_optinteger) (lua_State *L, int arg,
	lua_Integer def);

extern void (luaL_checkstack)(lua_State *L, int sz, const char *msg);
extern void (luaL_checktype)(lua_State *L, int arg, int t);
extern void (luaL_checkany)(lua_State *L, int arg);

extern int   (luaL_newmetatable)(lua_State *L, const char *tname);
extern void  (luaL_setmetatable)(lua_State *L, const char *tname);
extern void *(luaL_testudata)(lua_State *L, int ud, const char *tname);
extern void *(luaL_checkudata)(lua_State *L, int ud, const char *tname);

extern void (luaL_where)(lua_State *L, int lvl);
extern int (luaL_error)(lua_State *L, const char *fmt, ...);

extern int (luaL_checkoption)(lua_State *L, int arg, const char *def,
	const char *const lst[]);

extern int (luaL_fileresult)(lua_State *L, int stat, const char *fname);
extern int (luaL_execresult)(lua_State *L, int stat);

extern int (luaL_ref)(lua_State *L, int t);
extern void (luaL_unref)(lua_State *L, int t, int ref);

extern int (luaL_loadfilex)(lua_State *L, const char *filename,
	const char *mode);

extern int (luaL_loadbufferx)(lua_State *L, const char *buff, size_t sz,
	const char *name, const char *mode);
extern int (luaL_loadstring)(lua_State *L, const char *s);

extern lua_State *(luaL_newstate)(void);

extern lua_Integer(luaL_len) (lua_State *L, int idx);

extern const char *(luaL_gsub)(lua_State *L, const char *s, const char *p,
	const char *r);

extern void (luaL_setfuncs)(lua_State *L, const luaL_Reg *l, int nup);

extern int (luaL_getsubtable)(lua_State *L, int idx, const char *fname);

extern void (luaL_traceback)(lua_State *L, lua_State *L1,
	const char *msg, int level);

extern void (luaL_requiref)(lua_State *L, const char *modname,
	lua_CFunction openf, int glb);

typedef struct luaL_Buffer {
	char *b;
	size_t size;
	size_t n;
	lua_State *L;
	char initb[8192];
} luaL_Buffer;

extern void (luaL_buffinit)(lua_State *L, luaL_Buffer *B);
extern char *(luaL_prepbuffsize)(luaL_Buffer *B, size_t sz);
extern void (luaL_addlstring)(luaL_Buffer *B, const char *s, size_t l);
extern void (luaL_addstring)(luaL_Buffer *B, const char *s);
extern void (luaL_addvalue)(luaL_Buffer *B);
extern void (luaL_pushresult)(luaL_Buffer *B);
extern void (luaL_pushresultsize)(luaL_Buffer *B, size_t sz);
extern char *(luaL_buffinitsize)(lua_State *L, luaL_Buffer *B, size_t sz);

typedef struct luaL_Stream {
	FILE *f;
	lua_CFunction closef;
} luaL_Stream;

static int findfield(lua_State *L, int objidx, int level) {
	if (level == 0 || !(lua_type(L, (-1)) == 5))
		return 0;
	lua_pushnil(L);
	while (lua_next(L, -2)) {
		if (lua_type(L, -2) == 4) {
			if (lua_rawequal(L, objidx, -1)) {
				lua_settop(L, -(1) - 1);
				return 1;
			}
			else if (findfield(L, objidx, level - 1)) {
				(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
				lua_pushstring(L, "" ".");
				lua_rotate(L, (-2), 1);
				lua_concat(L, 3);
				return 1;
			}
		}
		lua_settop(L, -(1) - 1);
	}
	return 0;
}

static int pushglobalfuncname(lua_State *L, lua_Debug *ar) {
	int top = lua_gettop(L);
	lua_getinfo(L, "f", ar);
	lua_getfield(L, (-1000000 - 1000), "_LOADED");
	if (findfield(L, top + 1, 2)) {
		const char *name = lua_tolstring(L, (-1), ((void *)0));
		if (strncmp(name, "_G.", 3) == 0) {
			lua_pushstring(L, name + 3);
			(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
		}
		lua_copy(L, -1, top + 1);
		lua_settop(L, -(2) - 1);
		return 1;
	}
	else {
		lua_settop(L, top);
		return 0;
	}
}

static void pushfuncname(lua_State *L, lua_Debug *ar) {
	if (pushglobalfuncname(L, ar)) {
		lua_pushfstring(L, "function '%s'", lua_tolstring(L, (-1), ((void *)0)));
		(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
	}
	else if (*ar->namewhat != '\0')
		lua_pushfstring(L, "%s '%s'", ar->namewhat, ar->name);
	else if (*ar->what == 'm')
		lua_pushstring(L, "" "main chunk");
	else if (*ar->what != 'C')
		lua_pushfstring(L, "function <%s:%d>", ar->short_src, ar->linedefined);
	else
		lua_pushstring(L, "" "?");
}

static int lastlevel(lua_State *L) {
	lua_Debug ar;
	int li = 1, le = 1;

	while (lua_getstack(L, le, &ar)) {
		li = le;
		le *= 2;
	}

	while (li < le) {
		int m = (li + le) / 2;
		if (lua_getstack(L, m, &ar)) li = m + 1;
		else le = m;
	}
	return le - 1;
}

extern void luaL_traceback(lua_State *L, lua_State *L1,
	const char *msg, int level) {
	lua_Debug ar;
	int top = lua_gettop(L);
	int last = lastlevel(L1);
	int n1 = (last - level > 10 + 11) ? 10 : -1;
	if (msg)
		lua_pushfstring(L, "%s\n", msg);
	luaL_checkstack(L, 10, ((void *)0));
	lua_pushstring(L, "" "stack traceback:");
	while (lua_getstack(L1, level++, &ar)) {
		if (n1-- == 0) {
			lua_pushstring(L, "" "\n\t...");
			level = last - 11 + 1;
		}
		else {
			lua_getinfo(L1, "Slnt", &ar);
			lua_pushfstring(L, "\n\t%s:", ar.short_src);
			if (ar.currentline > 0)
				lua_pushfstring(L, "%d:", ar.currentline);
			lua_pushstring(L, "" " in ");
			pushfuncname(L, &ar);
			if (ar.istailcall)
				lua_pushstring(L, "" "\n\t(...tail calls...)");
			lua_concat(L, lua_gettop(L) - top);
		}
	}
	lua_concat(L, lua_gettop(L) - top);
}

extern int luaL_argerror(lua_State *L, int arg, const char *extramsg) {
	lua_Debug ar;
	if (!lua_getstack(L, 0, &ar))
		return luaL_error(L, "bad argument #%d (%s)", arg, extramsg);
	lua_getinfo(L, "n", &ar);
	if (strcmp(ar.namewhat, "method") == 0) {
		arg--;
		if (arg == 0)
			return luaL_error(L, "calling '%s' on bad self (%s)",
			ar.name, extramsg);
	}
	if (ar.name == ((void *)0))
		ar.name = (pushglobalfuncname(L, &ar)) ? lua_tolstring(L, (-1), ((void *)0)) : "?";
	return luaL_error(L, "bad argument #%d to '%s' (%s)",
		arg, ar.name, extramsg);
}

static int typeerror(lua_State *L, int arg, const char *tname) {
	const char *msg;
	const char *typearg;
	if (luaL_getmetafield(L, arg, "__name") == 4)
		typearg = lua_tolstring(L, (-1), ((void *)0));
	else if (lua_type(L, arg) == 2)
		typearg = "light userdata";
	else
		typearg = lua_typename(L, lua_type(L, (arg)));
	msg = lua_pushfstring(L, "%s expected, got %s", tname, typearg);
	return luaL_argerror(L, arg, msg);
}

static void tag_error(lua_State *L, int arg, int tag) {
	typeerror(L, arg, lua_typename(L, tag));
}

extern void luaL_where(lua_State *L, int level) {
	lua_Debug ar;
	if (lua_getstack(L, level, &ar)) {
		lua_getinfo(L, "Sl", &ar);
		if (ar.currentline > 0) {
			lua_pushfstring(L, "%s:%d: ", ar.short_src, ar.currentline);
			return;
		}
	}
	lua_pushfstring(L, "");
}

extern int luaL_error(lua_State *L, const char *fmt, ...) {
	va_list argp;
	(argp = (va_list)(&(fmt)) + ((sizeof(fmt) + sizeof(int) - 1) & ~(sizeof(int) - 1)));
	luaL_where(L, 1);
	lua_pushvfstring(L, fmt, argp);
	(argp = (va_list)0);
	lua_concat(L, 2);
	return lua_error(L);
}

extern int luaL_fileresult(lua_State *L, int stat, const char *fname) {
	int en = (*_errno());
	if (stat) {
		lua_pushboolean(L, 1);
		return 1;
	}
	else {
		lua_pushnil(L);
		if (fname)
			lua_pushfstring(L, "%s: %s", fname, strerror(en));
		else
			lua_pushstring(L, strerror(en));
		lua_pushinteger(L, en);
		return 3;
	}
}

extern int luaL_execresult(lua_State *L, int stat) {
	const char *what = "exit";
	if (stat == -1)
		return luaL_fileresult(L, 0, ((void *)0));
	else {
		;
		if (*what == 'e' && stat == 0)
			lua_pushboolean(L, 1);
		else
			lua_pushnil(L);
		lua_pushstring(L, what);
		lua_pushinteger(L, stat);
		return 3;
	}
}

extern int luaL_newmetatable(lua_State *L, const char *tname) {
	if ((lua_getfield(L, (-1000000 - 1000), (tname))) != 0)
		return 0;
	lua_settop(L, -(1) - 1);
	lua_createtable(L, 0, 2);
	lua_pushstring(L, tname);
	lua_setfield(L, -2, "__name");
	lua_pushvalue(L, -1);
	lua_setfield(L, (-1000000 - 1000), tname);
	return 1;
}

extern void luaL_setmetatable(lua_State *L, const char *tname) {
	(lua_getfield(L, (-1000000 - 1000), (tname)));
	lua_setmetatable(L, -2);
}

extern void *luaL_testudata(lua_State *L, int ud, const char *tname) {
	void *p = lua_touserdata(L, ud);
	if (p != ((void *)0)) {
		if (lua_getmetatable(L, ud)) {
			(lua_getfield(L, (-1000000 - 1000), (tname)));
			if (!lua_rawequal(L, -1, -2))
				p = ((void *)0);
			lua_settop(L, -(2) - 1);
			return p;
		}
	}
	return ((void *)0);
}

extern void *luaL_checkudata(lua_State *L, int ud, const char *tname) {
	void *p = luaL_testudata(L, ud, tname);
	if (p == ((void *)0)) typeerror(L, ud, tname);
	return p;
}

extern int luaL_checkoption(lua_State *L, int arg, const char *def,
	const char *const lst[]) {
	const char *name = (def) ? (luaL_optlstring(L, (arg), (def), ((void *)0))) :
		(luaL_checklstring(L, (arg), ((void *)0)));
	int i;
	for (i = 0;
		lst[i];
		i++)
		if (strcmp(lst[i], name) == 0)
			return i;
	return luaL_argerror(L, arg,
		lua_pushfstring(L, "invalid option '%s'", name));
}

extern void luaL_checkstack(lua_State *L, int space, const char *msg) {
	if (!lua_checkstack(L, space)) {
		if (msg)
			luaL_error(L, "stack overflow (%s)", msg);
		else
			luaL_error(L, "stack overflow");
	}
}

extern void luaL_checktype(lua_State *L, int arg, int t) {
	if (lua_type(L, arg) != t)
		tag_error(L, arg, t);
}

extern void luaL_checkany(lua_State *L, int arg) {
	if (lua_type(L, arg) == (-1))
		luaL_argerror(L, arg, "value expected");
}

extern const char *luaL_checklstring(lua_State *L, int arg, size_t *len) {
	const char *s = lua_tolstring(L, arg, len);
	if (!s) tag_error(L, arg, 4);
	return s;
}

extern const char *luaL_optlstring(lua_State *L, int arg,
	const char *def, size_t *len) {
	if ((lua_type(L, (arg)) <= 0)) {
		if (len)
			*len = (def ? strlen(def) : 0);
		return def;
	}
	else return luaL_checklstring(L, arg, len);
}

extern lua_Number luaL_checknumber(lua_State *L, int arg) {
	int isnum;
	lua_Number d = lua_tonumberx(L, arg, &isnum);
	if (!isnum)
		tag_error(L, arg, 3);
	return d;
}

extern lua_Number luaL_optnumber(lua_State *L, int arg, lua_Number def) {
	return ((lua_type(L, ((arg))) <= 0) ? (def) : luaL_checknumber(L, (arg)));
}

static void interror(lua_State *L, int arg) {
	if (lua_isnumber(L, arg))
		luaL_argerror(L, arg, "number has no integer representation");
	else
		tag_error(L, arg, 3);
}

extern lua_Integer luaL_checkinteger(lua_State *L, int arg) {
	int isnum;
	lua_Integer d = lua_tointegerx(L, arg, &isnum);
	if (!isnum) {
		interror(L, arg);
	}
	return d;
}

extern lua_Integer luaL_optinteger(lua_State *L, int arg,
	lua_Integer def) {
	return ((lua_type(L, ((arg))) <= 0) ? (def) : luaL_checkinteger(L, (arg)));
}

typedef struct UBox {
	void *box;
	size_t bsize;
} UBox;

static void *resizebox(lua_State *L, int idx, size_t newsize) {
	void *ud;
	lua_Alloc allocf = lua_getallocf(L, &ud);
	UBox *box = (UBox *)lua_touserdata(L, idx);
	void *temp = allocf(ud, box->box, box->bsize, newsize);
	if (temp == ((void *)0) && newsize > 0) {
		resizebox(L, idx, 0);
		luaL_error(L, "not enough memory for buffer allocation");
	}
	box->box = temp;
	box->bsize = newsize;
	return temp;
}

static int boxgc(lua_State *L) {
	resizebox(L, 1, 0);
	return 0;
}

static void *newbox(lua_State *L, size_t newsize) {
	UBox *box = (UBox *)lua_newuserdata(L, sizeof(UBox));
	box->box = ((void *)0);
	box->bsize = 0;
	if (luaL_newmetatable(L, "LUABOX")) {
		lua_pushcclosure(L, (boxgc), 0);
		lua_setfield(L, -2, "__gc");
	}
	lua_setmetatable(L, -2);
	return resizebox(L, -1, newsize);
}

extern char *luaL_prepbuffsize(luaL_Buffer *B, size_t sz) {
	lua_State *L = B->L;
	if (B->size - B->n < sz) {
		char *newbuff;
		size_t newsize = B->size * 2;
		if (newsize - B->n < sz)
			newsize = B->n + sz;
		if (newsize < B->n || newsize - B->n < sz)
			luaL_error(L, "buffer too large");

		if (((B)->b != (B)->initb))
			newbuff = (char *)resizebox(L, -1, newsize);
		else {
			newbuff = (char *)newbox(L, newsize);
			memcpy(newbuff, B->b, B->n * sizeof(char));
		}
		B->b = newbuff;
		B->size = newsize;
	}
	return &B->b[B->n];
}

extern void luaL_addlstring(luaL_Buffer *B, const char *s, size_t l) {
	if (l > 0) {
		char *b = luaL_prepbuffsize(B, l);
		memcpy(b, s, l * sizeof(char));
		((B)->n += (l));
	}
}

extern void luaL_addstring(luaL_Buffer *B, const char *s) {
	luaL_addlstring(B, s, strlen(s));
}

extern void luaL_pushresult(luaL_Buffer *B) {
	lua_State *L = B->L;
	lua_pushlstring(L, B->b, B->n);
	if (((B)->b != (B)->initb)) {
		resizebox(L, -2, 0);
		(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
	}
}

extern void luaL_pushresultsize(luaL_Buffer *B, size_t sz) {
	((B)->n += (sz));
	luaL_pushresult(B);
}

extern void luaL_addvalue(luaL_Buffer *B) {
	lua_State *L = B->L;
	size_t l;
	const char *s = lua_tolstring(L, -1, &l);
	if (((B)->b != (B)->initb))
		lua_rotate(L, (-2), 1);
	luaL_addlstring(B, s, l);
	(lua_rotate(L, ((((B)->b != (B)->initb)) ? -2 : -1), -1), lua_settop(L, -(1) - 1));
}

extern void luaL_buffinit(lua_State *L, luaL_Buffer *B) {
	B->L = L;
	B->b = B->initb;
	B->n = 0;
	B->size = 8192;
}

extern char *luaL_buffinitsize(lua_State *L, luaL_Buffer *B, size_t sz) {
	luaL_buffinit(L, B);
	return luaL_prepbuffsize(B, sz);
}

extern int luaL_ref(lua_State *L, int t) {
	int ref;
	if ((lua_type(L, (-1)) == 0)) {
		lua_settop(L, -(1) - 1);
		return (-1);
	}
	t = lua_absindex(L, t);
	lua_rawgeti(L, t, 0);
	ref = (int)lua_tointegerx(L, (-1), ((void *)0));
	lua_settop(L, -(1) - 1);
	if (ref != 0) {
		lua_rawgeti(L, t, ref);
		lua_rawseti(L, t, 0);
	}
	else
		ref = (int)lua_rawlen(L, t) + 1;
	lua_rawseti(L, t, ref);
	return ref;
}

extern void luaL_unref(lua_State *L, int t, int ref) {
	if (ref >= 0) {
		t = lua_absindex(L, t);
		lua_rawgeti(L, t, 0);
		lua_rawseti(L, t, ref);
		lua_pushinteger(L, ref);
		lua_rawseti(L, t, 0);
	}
}

typedef struct LoadF {
	int n;
	FILE *f;
	char buff[512];
} LoadF;

static const char *getF(lua_State *L, void *ud, size_t *size) {
	LoadF *lf = (LoadF *)ud;
	(void)L;
	if (lf->n > 0) {
		*size = lf->n;
		lf->n = 0;
	}
	else {

		if (feof(lf->f)) return ((void *)0);
		*size = fread(lf->buff, 1, sizeof(lf->buff), lf->f);
	}
	return lf->buff;
}

static int errfile(lua_State *L, const char *what, int fnameindex) {
	const char *serr = strerror((*_errno()));
	const char *filename = lua_tolstring(L, (fnameindex), ((void *)0)) + 1;
	lua_pushfstring(L, "cannot %s %s: %s", what, filename, serr);
	(lua_rotate(L, (fnameindex), -1), lua_settop(L, -(1) - 1));
	return (6 + 1);
}

static int skipBOM(LoadF *lf) {
	const char *p = "\xEF\xBB\xBF";
	int c;
	lf->n = 0;
	do {
		c = getc(lf->f);
		if (c == (-1) || c != *(const unsigned char *)p++) return c;
		lf->buff[lf->n++] = c;
	} while (*p != '\0');
	lf->n = 0;
	return getc(lf->f);
}

static int skipcomment(LoadF *lf, int *cp) {
	int c = *cp = skipBOM(lf);
	if (c == '#') {
		do {
			c = getc(lf->f);
		} while (c != (-1) && c != '\n');
		*cp = getc(lf->f);
		return 1;
	}
	else return 0;
}

extern int luaL_loadfilex(lua_State *L, const char *filename,
	const char *mode) {
	LoadF lf;
	int status, readstatus;
	int c;
	int fnameindex = lua_gettop(L) + 1;
	if (filename == ((void *)0)) {
		lua_pushstring(L, "" "=stdin");
		lf.f = (&__iob_func()[0]);
	}
	else {
		lua_pushfstring(L, "@%s", filename);
		lf.f = fopen(filename, "r");
		if (lf.f == ((void *)0)) return errfile(L, "open", fnameindex);
	}
	if (skipcomment(&lf, &c))
		lf.buff[lf.n++] = '\n';
	if (c == "\x1bLua"[0] && filename) {
		lf.f = freopen(filename, "rb", lf.f);
		if (lf.f == ((void *)0)) return errfile(L, "reopen", fnameindex);
		skipcomment(&lf, &c);
	}
	if (c != (-1))
		lf.buff[lf.n++] = c;
	status = lua_load(L, getF, &lf, lua_tolstring(L, (-1), ((void *)0)), mode);
	readstatus = ferror(lf.f);
	if (filename) fclose(lf.f);
	if (readstatus) {
		lua_settop(L, fnameindex);
		return errfile(L, "read", fnameindex);
	}
	(lua_rotate(L, (fnameindex), -1), lua_settop(L, -(1) - 1));
	return status;
}

typedef struct LoadS {
	const char *s;
	size_t size;
} LoadS;

static const char *getS(lua_State *L, void *ud, size_t *size) {
	LoadS *ls = (LoadS *)ud;
	(void)L;
	if (ls->size == 0) return ((void *)0);
	*size = ls->size;
	ls->size = 0;
	return ls->s;
}

extern int luaL_loadbufferx(lua_State *L, const char *buff, size_t size,
	const char *name, const char *mode) {
	LoadS ls;
	ls.s = buff;
	ls.size = size;
	return lua_load(L, getS, &ls, name, mode);
}

extern int luaL_loadstring(lua_State *L, const char *s) {
	return luaL_loadbufferx(L, s, strlen(s), s, ((void *)0));
}

extern int luaL_getmetafield(lua_State *L, int obj, const char *event) {
	if (!lua_getmetatable(L, obj))
		return 0;
	else {
		int tt;
		lua_pushstring(L, event);
		tt = lua_rawget(L, -2);
		if (tt == 0)
			lua_settop(L, -(2) - 1);
		else
			(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
		return tt;
	}
}

extern int luaL_callmeta(lua_State *L, int obj, const char *event) {
	obj = lua_absindex(L, obj);
	if (luaL_getmetafield(L, obj, event) == 0)
		return 0;
	lua_pushvalue(L, obj);
	lua_callk(L, (1), (1), 0, ((void *)0));
	return 1;
}

extern lua_Integer luaL_len(lua_State *L, int idx) {
	lua_Integer l;
	int isnum;
	lua_len(L, idx);
	l = lua_tointegerx(L, -1, &isnum);
	if (!isnum)
		luaL_error(L, "object length is not an integer");
	lua_settop(L, -(1) - 1);
	return l;
}

extern const char *luaL_tolstring(lua_State *L, int idx, size_t *len) {
	if (!luaL_callmeta(L, idx, "__tostring")) {
		switch (lua_type(L, idx)) {
		case 3: {
			if (lua_isinteger(L, idx))
				lua_pushfstring(L, "%I", lua_tointegerx(L, (idx), ((void *)0)));
			else
				lua_pushfstring(L, "%f", lua_tonumberx(L, (idx), ((void *)0)));
			break;
		}
		case 4:
			lua_pushvalue(L, idx);
			break;
		case 1:
			lua_pushstring(L, (lua_toboolean(L, idx) ? "true" : "false"));
			break;
		case 0:
			lua_pushstring(L, "" "nil");
			break;
		default:
			lua_pushfstring(L, "%s: %p", lua_typename(L, lua_type(L, (idx))),
				lua_topointer(L, idx));
			break;
		}
	}
	return lua_tolstring(L, -1, len);
}

extern void luaL_setfuncs(lua_State *L, const luaL_Reg *l, int nup) {
	luaL_checkstack(L, nup, "too many upvalues");
	for (;
		l->name != ((void *)0);
		l++) {
		int i;
		for (i = 0;
			i < nup;
			i++)
			lua_pushvalue(L, -nup);
		lua_pushcclosure(L, l->func, nup);
		lua_setfield(L, -(nup + 2), l->name);
	}
	lua_settop(L, -(nup)-1);
}

extern int luaL_getsubtable(lua_State *L, int idx, const char *fname) {
	if (lua_getfield(L, idx, fname) == 5)
		return 1;
	else {
		lua_settop(L, -(1) - 1);
		idx = lua_absindex(L, idx);
		lua_createtable(L, 0, 0);
		lua_pushvalue(L, -1);
		lua_setfield(L, idx, fname);
		return 0;
	}
}

extern void luaL_requiref(lua_State *L, const char *modname,
	lua_CFunction openf, int glb) {
	luaL_getsubtable(L, (-1000000 - 1000), "_LOADED");
	lua_getfield(L, -1, modname);
	if (!lua_toboolean(L, -1)) {
		lua_settop(L, -(1) - 1);
		lua_pushcclosure(L, (openf), 0);
		lua_pushstring(L, modname);
		lua_callk(L, (1), (1), 0, ((void *)0));
		lua_pushvalue(L, -1);
		lua_setfield(L, -3, modname);
	}
	(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
	if (glb) {
		lua_pushvalue(L, -1);
		lua_setglobal(L, modname);
	}
}

extern const char *luaL_gsub(lua_State *L, const char *s, const char *p,
	const char *r) {
	const char *wild;
	size_t l = strlen(p);
	luaL_Buffer b;
	luaL_buffinit(L, &b);
	while ((wild = strstr(s, p)) != ((void *)0)) {
		luaL_addlstring(&b, s, wild - s);
		luaL_addstring(&b, r);
		s = wild + l;
	}
	luaL_addstring(&b, s);
	luaL_pushresult(&b);
	return lua_tolstring(L, (-1), ((void *)0));
}

static void *l_alloc(void *ud, void *ptr, size_t osize, size_t nsize) {
	(void)ud;
	(void)osize;
	if (nsize == 0) {
		free(ptr);
		return ((void *)0);
	}
	else
		return realloc(ptr, nsize);
}

static int panic(lua_State *L) {
	(fprintf((&__iob_func()[2]), ("PANIC: unprotected error in call to Lua API (%s)\n"), (lua_tolstring(L, (-1), ((void *)0)))), fflush((&__iob_func()[2])));
	return 0;
}

extern lua_State *luaL_newstate(void) {
	lua_State *L = lua_newstate(l_alloc, ((void *)0));
	if (L) lua_atpanic(L, &panic);
	return L;
}

extern void luaL_checkversion_(lua_State *L, lua_Number ver, size_t sz) {
	const lua_Number *v = lua_version(L);
	if (sz != (sizeof(lua_Integer) * 16 + sizeof(lua_Number)))
		luaL_error(L, "core and library have incompatible numeric types");
	if (v != lua_version(((void *)0)))
		luaL_error(L, "multiple Lua VMs detected");
	else if (*v != ver)
		luaL_error(L, "version mismatch: app. needs %f, Lua core provides %f",
		ver, *v);
}

