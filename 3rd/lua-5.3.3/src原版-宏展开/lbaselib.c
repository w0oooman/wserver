
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

__declspec(dllimport) const unsigned short * __cdecl __pctype_func(void);

__declspec(dllimport) extern const unsigned short *_pctype;

__declspec(dllimport) extern const unsigned short _wctype[];

__declspec(dllimport) const wctype_t * __cdecl __pwctype_func(void);

__declspec(dllimport) extern const wctype_t *_pwctype;

__declspec(dllimport) int __cdecl _isctype(int _C, int _Type);
__declspec(dllimport) int __cdecl _isctype_l(int _C, int _Type, _locale_t _Locale);
__declspec(dllimport) int __cdecl isalpha(int _C);
__declspec(dllimport) int __cdecl _isalpha_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl isupper(int _C);
__declspec(dllimport) int __cdecl _isupper_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl islower(int _C);
__declspec(dllimport) int __cdecl _islower_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl isdigit(int _C);
__declspec(dllimport) int __cdecl _isdigit_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl isxdigit(int _C);
__declspec(dllimport) int __cdecl _isxdigit_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl isspace(int _C);
__declspec(dllimport) int __cdecl _isspace_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl ispunct(int _C);
__declspec(dllimport) int __cdecl _ispunct_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl isblank(int _C);
__declspec(dllimport) int __cdecl _isblank_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl isalnum(int _C);
__declspec(dllimport) int __cdecl _isalnum_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl isprint(int _C);
__declspec(dllimport) int __cdecl _isprint_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl isgraph(int _C);
__declspec(dllimport) int __cdecl _isgraph_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iscntrl(int _C);
__declspec(dllimport) int __cdecl _iscntrl_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl toupper(int _C);
__declspec(dllimport) int __cdecl tolower(int _C);
__declspec(dllimport) int __cdecl _tolower(int _C);
__declspec(dllimport) int __cdecl _tolower_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl _toupper(int _C);
__declspec(dllimport) int __cdecl _toupper_l(int _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl __isascii(int _C);
__declspec(dllimport) int __cdecl __toascii(int _C);
__declspec(dllimport) int __cdecl __iscsymf(int _C);
__declspec(dllimport) int __cdecl __iscsym(int _C);

__declspec(dllimport) int __cdecl iswalpha(wint_t _C);
__declspec(dllimport) int __cdecl _iswalpha_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswupper(wint_t _C);
__declspec(dllimport) int __cdecl _iswupper_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswlower(wint_t _C);
__declspec(dllimport) int __cdecl _iswlower_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswdigit(wint_t _C);
__declspec(dllimport) int __cdecl _iswdigit_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswxdigit(wint_t _C);
__declspec(dllimport) int __cdecl _iswxdigit_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswspace(wint_t _C);
__declspec(dllimport) int __cdecl _iswspace_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswpunct(wint_t _C);
__declspec(dllimport) int __cdecl _iswpunct_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswblank(wint_t _C);
__declspec(dllimport) int __cdecl _iswblank_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswalnum(wint_t _C);
__declspec(dllimport) int __cdecl _iswalnum_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswprint(wint_t _C);
__declspec(dllimport) int __cdecl _iswprint_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswgraph(wint_t _C);
__declspec(dllimport) int __cdecl _iswgraph_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswcntrl(wint_t _C);
__declspec(dllimport) int __cdecl _iswcntrl_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswascii(wint_t _C);

__declspec(dllimport) wint_t __cdecl towupper(wint_t _C);
__declspec(dllimport) wint_t __cdecl _towupper_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) wint_t __cdecl towlower(wint_t _C);
__declspec(dllimport) wint_t __cdecl _towlower_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl iswctype(wint_t _C, wctype_t _Type);
__declspec(dllimport) int __cdecl _iswctype_l(wint_t _C, wctype_t _Type, _locale_t _Locale);

__declspec(dllimport) int __cdecl __iswcsymf(wint_t _C);
__declspec(dllimport) int __cdecl _iswcsymf_l(wint_t _C, _locale_t _Locale);
__declspec(dllimport) int __cdecl __iswcsym(wint_t _C);
__declspec(dllimport) int __cdecl _iswcsym_l(wint_t _C, _locale_t _Locale);

__declspec(dllimport) int __cdecl isleadbyte(int _C);
__declspec(dllimport) int __cdecl _isleadbyte_l(int _C, _locale_t _Locale);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "iswctype" " instead. See online help for details.")) __declspec(dllimport) int __cdecl is_wctype(wint_t _C, wctype_t _Type);

__declspec(dllimport) extern int __mb_cur_max;

__declspec(dllimport) int __cdecl ___mb_cur_max_func(void);
__declspec(dllimport) int __cdecl ___mb_cur_max_l_func(_locale_t);

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

typedef void(__cdecl *_purecall_handler)(void);

__declspec(dllimport) _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
__declspec(dllimport) _purecall_handler __cdecl _get_purecall_handler(void);

typedef void(__cdecl *_invalid_parameter_handler)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t);

__declspec(dllimport) _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
__declspec(dllimport) _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

__declspec(dllimport) extern int * __cdecl _errno(void);

errno_t __cdecl _set_errno(int _Value);
errno_t __cdecl _get_errno(int * _Value);

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

void __declspec(dllimport) __cdecl _vacopy(va_list *, va_list);

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

extern int (luaopen_base)(lua_State *L);

extern int (luaopen_coroutine)(lua_State *L);

extern int (luaopen_table)(lua_State *L);

extern int (luaopen_io)(lua_State *L);

extern int (luaopen_os)(lua_State *L);

extern int (luaopen_string)(lua_State *L);

extern int (luaopen_utf8)(lua_State *L);

extern int (luaopen_bit32)(lua_State *L);

extern int (luaopen_math)(lua_State *L);

extern int (luaopen_debug)(lua_State *L);

extern int (luaopen_package)(lua_State *L);

extern void (luaL_openlibs)(lua_State *L);

static int luaB_print(lua_State *L) {
	int n = lua_gettop(L);
	int i;
	lua_getglobal(L, "tostring");
	for (i = 1;
		i <= n;
		i++) {
		const char *s;
		size_t l;
		lua_pushvalue(L, -1);
		lua_pushvalue(L, i);
		lua_callk(L, (1), (1), 0, ((void *)0));
		s = lua_tolstring(L, -1, &l);
		if (s == ((void *)0))
			return luaL_error(L, "'tostring' must return a string to 'print'");
		if (i > 1) fwrite(("\t"), sizeof(char), (1), (&__iob_func()[1]));
		fwrite((s), sizeof(char), (l), (&__iob_func()[1]));
		lua_settop(L, -(1) - 1);
	}
	(fwrite(("\n"), sizeof(char), (1), (&__iob_func()[1])), fflush((&__iob_func()[1])));
	return 0;
}

static const char *b_str2int(const char *s, int base, lua_Integer *pn) {
	lua_Unsigned n = 0;
	int neg = 0;
	s += strspn(s, " \f\n\r\t\v");
	if (*s == '-') {
		s++;
		neg = 1;
	}
	else if (*s == '+') s++;
	if (!isalnum((unsigned char)*s))
		return ((void *)0);
	do {
		int digit = (isdigit((unsigned char)*s)) ? *s - '0'
			: (toupper((unsigned char)*s) - 'A') + 10;
		if (digit >= base) return ((void *)0);
		n = n * base + digit;
		s++;
	} while (isalnum((unsigned char)*s));
	s += strspn(s, " \f\n\r\t\v");
	*pn = (lua_Integer)((neg) ? (0u - n) : n);
	return s;
}

static int luaB_tonumber(lua_State *L) {
	if ((lua_type(L, (2)) <= 0)) {
		luaL_checkany(L, 1);
		if (lua_type(L, 1) == 3) {
			lua_settop(L, 1);
			return 1;
		}
		else {
			size_t l;
			const char *s = lua_tolstring(L, 1, &l);
			if (s != ((void *)0) && lua_stringtonumber(L, s) == l + 1)
				return 1;

		}
	}
	else {
		size_t l;
		const char *s;
		lua_Integer n = 0;
		lua_Integer base = luaL_checkinteger(L, 2);
		luaL_checktype(L, 1, 4);
		s = lua_tolstring(L, 1, &l);
		((void)((2 <= base && base <= 36) || luaL_argerror(L, (2), ("base out of range"))));
		if (b_str2int(s, (int)base, &n) == s + l) {
			lua_pushinteger(L, n);
			return 1;
		}
	}
	lua_pushnil(L);
	return 1;
}

static int luaB_error(lua_State *L) {
	int level = (int)luaL_optinteger(L, 2, 1);
	lua_settop(L, 1);
	if (lua_type(L, 1) == 4 && level > 0) {
		luaL_where(L, level);
		lua_pushvalue(L, 1);
		lua_concat(L, 2);
	}
	return lua_error(L);
}

static int luaB_getmetatable(lua_State *L) {
	luaL_checkany(L, 1);
	if (!lua_getmetatable(L, 1)) {
		lua_pushnil(L);
		return 1;
	}
	luaL_getmetafield(L, 1, "__metatable");
	return 1;
}

static int luaB_setmetatable(lua_State *L) {
	int t = lua_type(L, 2);
	luaL_checktype(L, 1, 5);
	((void)((t == 0 || t == 5) || luaL_argerror(L, (2), ("nil or table expected"))));
	if (luaL_getmetafield(L, 1, "__metatable") != 0)
		return luaL_error(L, "cannot change a protected metatable");
	lua_settop(L, 2);
	lua_setmetatable(L, 1);
	return 1;
}

static int luaB_rawequal(lua_State *L) {
	luaL_checkany(L, 1);
	luaL_checkany(L, 2);
	lua_pushboolean(L, lua_rawequal(L, 1, 2));
	return 1;
}

static int luaB_rawlen(lua_State *L) {
	int t = lua_type(L, 1);
	((void)((t == 5 || t == 4) || luaL_argerror(L, (1), ("table or string expected"))));
	lua_pushinteger(L, lua_rawlen(L, 1));
	return 1;
}

static int luaB_rawget(lua_State *L) {
	luaL_checktype(L, 1, 5);
	luaL_checkany(L, 2);
	lua_settop(L, 2);
	lua_rawget(L, 1);
	return 1;
}

static int luaB_rawset(lua_State *L) {
	luaL_checktype(L, 1, 5);
	luaL_checkany(L, 2);
	luaL_checkany(L, 3);
	lua_settop(L, 3);
	lua_rawset(L, 1);
	return 1;
}

static int luaB_collectgarbage(lua_State *L) {
	static const char *const opts[] = {
		"stop", "restart", "collect",
		"count", "step", "setpause", "setstepmul",
		"isrunning", ((void *)0)
	};
	static const int optsnum[] = {
		0, 1, 2,
		3, 5, 6, 7,
		9
	};
	int o = optsnum[luaL_checkoption(L, 1, "collect", opts)];
	int ex = (int)luaL_optinteger(L, 2, 0);
	int res = lua_gc(L, o, ex);
	switch (o) {
	case 3: {
		int b = lua_gc(L, 4, 0);
		lua_pushnumber(L, (lua_Number)res + ((lua_Number)b / 1024));
		return 1;
	}
	case 5: case 9: {
		lua_pushboolean(L, res);
		return 1;
	}
	default: {
		lua_pushinteger(L, res);
		return 1;
	}
	}
}

static int luaB_type(lua_State *L) {
	int t = lua_type(L, 1);
	((void)((t != (-1)) || luaL_argerror(L, (1), ("value expected"))));
	lua_pushstring(L, lua_typename(L, t));
	return 1;
}

static int pairsmeta(lua_State *L, const char *method, int iszero,
	lua_CFunction iter) {
	if (luaL_getmetafield(L, 1, method) == 0) {
		luaL_checktype(L, 1, 5);
		lua_pushcclosure(L, (iter), 0);
		lua_pushvalue(L, 1);
		if (iszero) lua_pushinteger(L, 0);
		else lua_pushnil(L);
	}
	else {
		lua_pushvalue(L, 1);
		lua_callk(L, (1), (3), 0, ((void *)0));
	}
	return 3;
}

static int luaB_next(lua_State *L) {
	luaL_checktype(L, 1, 5);
	lua_settop(L, 2);
	if (lua_next(L, 1))
		return 2;
	else {
		lua_pushnil(L);
		return 1;
	}
}

static int luaB_pairs(lua_State *L) {
	return pairsmeta(L, "__pairs", 0, luaB_next);
}

static int ipairsaux(lua_State *L) {
	lua_Integer i = luaL_checkinteger(L, 2) + 1;
	lua_pushinteger(L, i);
	return (lua_geti(L, 1, i) == 0) ? 1 : 2;
}

static int luaB_ipairs(lua_State *L) {

	luaL_checkany(L, 1);
	lua_pushcclosure(L, (ipairsaux), 0);
	lua_pushvalue(L, 1);
	lua_pushinteger(L, 0);
	return 3;

}

static int load_aux(lua_State *L, int status, int envidx) {
	if (status == 0) {
		if (envidx != 0) {
			lua_pushvalue(L, envidx);
			if (!lua_setupvalue(L, -2, 1))
				lua_settop(L, -(1) - 1);
		}
		return 1;
	}
	else {
		lua_pushnil(L);
		lua_rotate(L, (-2), 1);
		return 2;
	}
}

static int luaB_loadfile(lua_State *L) {
	const char *fname = (luaL_optlstring(L, (1), (((void *)0)), ((void *)0)));
	const char *mode = (luaL_optlstring(L, (2), (((void *)0)), ((void *)0)));
	int env = (!(lua_type(L, (3)) == (-1)) ? 3 : 0);
	int status = luaL_loadfilex(L, fname, mode);
	return load_aux(L, status, env);
}

static const char *generic_reader(lua_State *L, void *ud, size_t *size) {
	(void)(ud);
	luaL_checkstack(L, 2, "too many nested functions");
	lua_pushvalue(L, 1);
	lua_callk(L, (0), (1), 0, ((void *)0));
	if ((lua_type(L, (-1)) == 0)) {
		lua_settop(L, -(1) - 1);
		*size = 0;
		return ((void *)0);
	}
	else if (!lua_isstring(L, -1))
		luaL_error(L, "reader function must return a string");
	(lua_copy(L, -1, (5)), lua_settop(L, -(1) - 1));
	return lua_tolstring(L, 5, size);
}

static int luaB_load(lua_State *L) {
	int status;
	size_t l;
	const char *s = lua_tolstring(L, 1, &l);
	const char *mode = (luaL_optlstring(L, (3), ("bt"), ((void *)0)));
	int env = (!(lua_type(L, (4)) == (-1)) ? 4 : 0);
	if (s != ((void *)0)) {
		const char *chunkname = (luaL_optlstring(L, (2), (s), ((void *)0)));
		status = luaL_loadbufferx(L, s, l, chunkname, mode);
	}
	else {
		const char *chunkname = (luaL_optlstring(L, (2), ("=(load)"), ((void *)0)));
		luaL_checktype(L, 1, 6);
		lua_settop(L, 5);
		status = lua_load(L, generic_reader, ((void *)0), chunkname, mode);
	}
	return load_aux(L, status, env);
}

static int dofilecont(lua_State *L, int d1, lua_KContext d2) {
	(void)d1;
	(void)d2;
	return lua_gettop(L) - 1;
}

static int luaB_dofile(lua_State *L) {
	const char *fname = (luaL_optlstring(L, (1), (((void *)0)), ((void *)0)));
	lua_settop(L, 1);
	if (luaL_loadfilex(L, fname, ((void *)0)) != 0)
		return lua_error(L);
	lua_callk(L, 0, (-1), 0, dofilecont);
	return dofilecont(L, 0, 0);
}

static int luaB_assert(lua_State *L) {
	if (lua_toboolean(L, 1))
		return lua_gettop(L);
	else {
		luaL_checkany(L, 1);
		(lua_rotate(L, (1), -1), lua_settop(L, -(1) - 1));
		lua_pushstring(L, "" "assertion failed!");
		lua_settop(L, 1);
		return luaB_error(L);
	}
}

static int luaB_select(lua_State *L) {
	int n = lua_gettop(L);
	if (lua_type(L, 1) == 4 && *lua_tolstring(L, (1), ((void *)0)) == '#') {
		lua_pushinteger(L, n - 1);
		return 1;
	}
	else {
		lua_Integer i = luaL_checkinteger(L, 1);
		if (i < 0) i = n + i;
		else if (i > n) i = n;
		((void)((1 <= i) || luaL_argerror(L, (1), ("index out of range"))));
		return n - (int)i;
	}
}

static int finishpcall(lua_State *L, int status, lua_KContext extra) {
	if (status != 0 && status != 1) {
		lua_pushboolean(L, 0);
		lua_pushvalue(L, -2);
		return 2;
	}
	else
		return lua_gettop(L) - (int)extra;
}

static int luaB_pcall(lua_State *L) {
	int status;
	luaL_checkany(L, 1);
	lua_pushboolean(L, 1);
	lua_rotate(L, (1), 1);
	status = lua_pcallk(L, lua_gettop(L) - 2, (-1), 0, 0, finishpcall);
	return finishpcall(L, status, 0);
}

static int luaB_xpcall(lua_State *L) {
	int status;
	int n = lua_gettop(L);
	luaL_checktype(L, 2, 6);
	lua_pushboolean(L, 1);
	lua_pushvalue(L, 1);
	lua_rotate(L, 3, 2);
	status = lua_pcallk(L, n - 2, (-1), 2, 2, finishpcall);
	return finishpcall(L, status, 2);
}

static int luaB_tostring(lua_State *L) {
	luaL_checkany(L, 1);
	luaL_tolstring(L, 1, ((void *)0));
	return 1;
}

static const luaL_Reg base_funcs[] = {
		{
			"assert", luaB_assert
		},
		{
			"collectgarbage", luaB_collectgarbage
		},
		{
			"dofile", luaB_dofile
		},
		{
			"error", luaB_error
		},
		{
			"getmetatable", luaB_getmetatable
		},
		{
			"ipairs", luaB_ipairs
		},
		{
			"loadfile", luaB_loadfile
		},
		{
			"load", luaB_load
		},

		{
			"next", luaB_next
		},
		{
			"pairs", luaB_pairs
		},
		{
			"pcall", luaB_pcall
		},
		{
			"print", luaB_print
		},
		{
			"rawequal", luaB_rawequal
		},
		{
			"rawlen", luaB_rawlen
		},
		{
			"rawget", luaB_rawget
		},
		{
			"rawset", luaB_rawset
		},
		{
			"select", luaB_select
		},
		{
			"setmetatable", luaB_setmetatable
		},
		{
			"tonumber", luaB_tonumber
		},
		{
			"tostring", luaB_tostring
		},
		{
			"type", luaB_type
		},
		{
			"xpcall", luaB_xpcall
		},

		{
			"_G", ((void *)0)
		},
		{
			"_VERSION", ((void *)0)
		},
		{
			((void *)0), ((void *)0) }
};

extern int luaopen_base(lua_State *L) {

	((void)lua_rawgeti(L, (-1000000 - 1000), 2));
	luaL_setfuncs(L, base_funcs, 0);

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "_G");

	lua_pushstring(L, "" "Lua " "5" "." "3");
	lua_setfield(L, -2, "_VERSION");
	return 1;
}

