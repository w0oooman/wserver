
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

#pragma once

__declspec(dllimport) unsigned int __cdecl _clearfp(void);
#pragma warning(push)
#pragma warning(disable: 4141)
__declspec(dllimport) unsigned int __cdecl _controlfp(unsigned int _NewValue, unsigned int _Mask);
#pragma warning(pop)
__declspec(dllimport) void __cdecl _set_controlfp(unsigned int _NewValue, unsigned int _Mask);
__declspec(dllimport) errno_t __cdecl _controlfp_s(unsigned int *_CurrentState, unsigned int _NewValue, unsigned int _Mask);
__declspec(dllimport) unsigned int __cdecl _statusfp(void);
__declspec(dllimport) void __cdecl _fpreset(void);

__declspec(dllimport) void __cdecl _statusfp2(unsigned int *_X86_status, unsigned int *_SSE2_status);

__declspec(dllimport) unsigned int __cdecl _control87(unsigned int _NewValue, unsigned int _Mask);

__declspec(dllimport) int __cdecl __control87_2(unsigned int _NewValue, unsigned int _Mask,
	unsigned int* _X86_cw, unsigned int* _Sse2_cw);

__declspec(dllimport) extern int * __cdecl __fpecode(void);

__declspec(dllimport) double __cdecl _copysign(double _Number, double _Sign);
__declspec(dllimport) double __cdecl _chgsign(double _X);
__declspec(dllimport) double __cdecl _scalb(double _X, long _Y);
__declspec(dllimport) double __cdecl _logb(double _X);
__declspec(dllimport) double __cdecl _nextafter(double _X, double _Y);
__declspec(dllimport) int    __cdecl _finite(double _X);
__declspec(dllimport) int    __cdecl _isnan(double _X);
__declspec(dllimport) int    __cdecl _fpclass(double _X);

__declspec(dllimport) void __cdecl fpreset(void);

#pragma once

#pragma once

#pragma pack(push,8)

struct lconv {
	char *decimal_point;
	char *thousands_sep;
	char *grouping;
	char *int_curr_symbol;
	char *currency_symbol;
	char *mon_decimal_point;
	char *mon_thousands_sep;
	char *mon_grouping;
	char *positive_sign;
	char *negative_sign;
	char int_frac_digits;
	char frac_digits;
	char p_cs_precedes;
	char p_sep_by_space;
	char n_cs_precedes;
	char n_sep_by_space;
	char p_sign_posn;
	char n_sign_posn;
	wchar_t *_W_decimal_point;
	wchar_t *_W_thousands_sep;
	wchar_t *_W_int_curr_symbol;
	wchar_t *_W_currency_symbol;
	wchar_t *_W_mon_decimal_point;
	wchar_t *_W_mon_thousands_sep;
	wchar_t *_W_positive_sign;
	wchar_t *_W_negative_sign;
};

__declspec(dllimport) int __cdecl _configthreadlocale(int _Flag);
__declspec(dllimport) char * __cdecl setlocale(int _Category, const char * _Locale);
__declspec(dllimport) struct lconv * __cdecl localeconv(void);
__declspec(dllimport) _locale_t __cdecl _get_current_locale(void);
__declspec(dllimport) _locale_t __cdecl _create_locale(int _Category, const char * _Locale);
__declspec(dllimport) void __cdecl _free_locale(_locale_t _Locale);

__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "_get_current_locale" " instead. See online help for details.")) __declspec(dllimport) _locale_t __cdecl __get_current_locale(void);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "_create_locale" " instead. See online help for details.")) __declspec(dllimport) _locale_t __cdecl __create_locale(int _Category, const char * _Locale);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "_free_locale" " instead. See online help for details.")) __declspec(dllimport) void __cdecl __free_locale(_locale_t _Locale);

__declspec(dllimport) wchar_t * __cdecl _wsetlocale(int _Category, const wchar_t * _Locale);
__declspec(dllimport) _locale_t __cdecl _wcreate_locale(int _Category, const wchar_t * _Locale);

#pragma pack(pop)

#pragma once

__declspec(dllimport) extern int * __cdecl _errno(void);

errno_t __cdecl _set_errno(int _Value);
errno_t __cdecl _get_errno(int * _Value);

__declspec(dllimport) extern unsigned long  __cdecl __threadid(void);

__declspec(dllimport) extern uintptr_t __cdecl __threadhandle(void);

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

static int str_len(lua_State *L) {
	size_t l;
	luaL_checklstring(L, 1, &l);
	lua_pushinteger(L, (lua_Integer)l);
	return 1;
}

static lua_Integer posrelat(lua_Integer pos, size_t len) {
	if (pos >= 0) return pos;
	else if (0u - (size_t)pos > len) return 0;
	else return (lua_Integer)len + pos + 1;
}

static int str_sub(lua_State *L) {
	size_t l;
	const char *s = luaL_checklstring(L, 1, &l);
	lua_Integer start = posrelat(luaL_checkinteger(L, 2), l);
	lua_Integer end = posrelat(luaL_optinteger(L, 3, -1), l);
	if (start < 1) start = 1;
	if (end > (lua_Integer)l) end = l;
	if (start <= end)
		lua_pushlstring(L, s + start - 1, (size_t)(end - start) + 1);
	else lua_pushstring(L, "" "");
	return 1;
}

static int str_reverse(lua_State *L) {
	size_t l, i;
	luaL_Buffer b;
	const char *s = luaL_checklstring(L, 1, &l);
	char *p = luaL_buffinitsize(L, &b, l);
	for (i = 0;
		i < l;
		i++)
		p[i] = s[l - i - 1];
	luaL_pushresultsize(&b, l);
	return 1;
}

static int str_lower(lua_State *L) {
	size_t l;
	size_t i;
	luaL_Buffer b;
	const char *s = luaL_checklstring(L, 1, &l);
	char *p = luaL_buffinitsize(L, &b, l);
	for (i = 0;
		i < l;
		i++)
		p[i] = tolower(((unsigned char)(s[i])));
	luaL_pushresultsize(&b, l);
	return 1;
}

static int str_upper(lua_State *L) {
	size_t l;
	size_t i;
	luaL_Buffer b;
	const char *s = luaL_checklstring(L, 1, &l);
	char *p = luaL_buffinitsize(L, &b, l);
	for (i = 0;
		i < l;
		i++)
		p[i] = toupper(((unsigned char)(s[i])));
	luaL_pushresultsize(&b, l);
	return 1;
}

static int str_rep(lua_State *L) {
	size_t l, lsep;
	const char *s = luaL_checklstring(L, 1, &l);
	lua_Integer n = luaL_checkinteger(L, 2);
	const char *sep = luaL_optlstring(L, 3, "", &lsep);
	if (n <= 0) lua_pushstring(L, "" "");
	else if (l + lsep < l || l + lsep >(sizeof(size_t) < sizeof(int) ? ((size_t)(~(size_t)0)) : (size_t)(2147483647)) / n)
		return luaL_error(L, "resulting string too large");
	else {
		size_t totallen = (size_t)n * l + (size_t)(n - 1) * lsep;
		luaL_Buffer b;
		char *p = luaL_buffinitsize(L, &b, totallen);
		while (n-- > 1) {
			memcpy(p, s, l * sizeof(char));
			p += l;
			if (lsep > 0) {
				memcpy(p, sep, lsep * sizeof(char));
				p += lsep;
			}
		}
		memcpy(p, s, l * sizeof(char));
		luaL_pushresultsize(&b, totallen);
	}
	return 1;
}

static int str_byte(lua_State *L) {
	size_t l;
	const char *s = luaL_checklstring(L, 1, &l);
	lua_Integer posi = posrelat(luaL_optinteger(L, 2, 1), l);
	lua_Integer pose = posrelat(luaL_optinteger(L, 3, posi), l);
	int n, i;
	if (posi < 1) posi = 1;
	if (pose > (lua_Integer)l) pose = l;
	if (posi > pose) return 0;
	if (pose - posi >= 2147483647)
		return luaL_error(L, "string slice too long");
	n = (int)(pose - posi) + 1;
	luaL_checkstack(L, n, "string slice too long");
	for (i = 0;
		i < n;
		i++)
		lua_pushinteger(L, ((unsigned char)(s[posi + i - 1])));
	return n;
}

static int str_char(lua_State *L) {
	int n = lua_gettop(L);
	int i;
	luaL_Buffer b;
	char *p = luaL_buffinitsize(L, &b, n);
	for (i = 1;
		i <= n;
		i++) {
		lua_Integer c = luaL_checkinteger(L, i);
		((void)((((unsigned char)(c)) == c) || luaL_argerror(L, (i), ("value out of range"))));
		p[i - 1] = ((unsigned char)(c));
	}
	luaL_pushresultsize(&b, n);
	return 1;
}

static int writer(lua_State *L, const void *b, size_t size, void *B) {
	(void)L;
	luaL_addlstring((luaL_Buffer *)B, (const char *)b, size);
	return 0;
}

static int str_dump(lua_State *L) {
	luaL_Buffer b;
	int strip = lua_toboolean(L, 2);
	luaL_checktype(L, 1, 6);
	lua_settop(L, 1);
	luaL_buffinit(L, &b);
	if (lua_dump(L, writer, &b, strip) != 0)
		return luaL_error(L, "unable to dump given function");
	luaL_pushresult(&b);
	return 1;
}

typedef struct MatchState {
	const char *src_init;
	const char *src_end;
	const char *p_end;
	lua_State *L;
	int matchdepth;
	unsigned char level;
	struct {
		const char *init;
		ptrdiff_t len;
	} capture[32];
} MatchState;

static const char *match(MatchState *ms, const char *s, const char *p);

static int check_capture(MatchState *ms, int l) {
	l -= '1';
	if (l < 0 || l >= ms->level || ms->capture[l].len == (-1))
		return luaL_error(ms->L, "invalid capture index %%%d", l + 1);
	return l;
}

static int capture_to_close(MatchState *ms) {
	int level = ms->level;
	for (level--;
		level >= 0;
		level--)
		if (ms->capture[level].len == (-1)) return level;
	return luaL_error(ms->L, "invalid pattern capture");
}

static const char *classend(MatchState *ms, const char *p) {
	switch (*p++) {
	case '%': {
		if (p == ms->p_end)
			luaL_error(ms->L, "malformed pattern (ends with '%%')");
		return p + 1;
	}
	case '[': {
		if (*p == '^') p++;
		do {
			if (p == ms->p_end)
				luaL_error(ms->L, "malformed pattern (missing ']')");
			if (*(p++) == '%' && p < ms->p_end)
				p++;
		} while (*p != ']');
		return p + 1;
	}
	default: {
		return p;
	}
	}
}

static int match_class(int c, int cl) {
	int res;
	switch (tolower(cl)) {
	case 'a': res = isalpha(c);
		break;
	case 'c': res = iscntrl(c);
		break;
	case 'd': res = isdigit(c);
		break;
	case 'g': res = isgraph(c);
		break;
	case 'l': res = islower(c);
		break;
	case 'p': res = ispunct(c);
		break;
	case 's': res = isspace(c);
		break;
	case 'u': res = isupper(c);
		break;
	case 'w': res = isalnum(c);
		break;
	case 'x': res = isxdigit(c);
		break;
	case 'z': res = (c == 0);
		break;
	default: return (cl == c);
	}
	return (islower(cl) ? res : !res);
}

static int matchbracketclass(int c, const char *p, const char *ec) {
	int sig = 1;
	if (*(p + 1) == '^') {
		sig = 0;
		p++;
	}
	while (++p < ec) {
		if (*p == '%') {
			p++;
			if (match_class(c, ((unsigned char)(*p))))
				return sig;
		}
		else if ((*(p + 1) == '-') && (p + 2 < ec)) {
			p += 2;
			if (((unsigned char)(*(p - 2))) <= c && c <= ((unsigned char)(*p)))
				return sig;
		}
		else if (((unsigned char)(*p)) == c) return sig;
	}
	return !sig;
}

static int singlematch(MatchState *ms, const char *s, const char *p,
	const char *ep) {
	if (s >= ms->src_end)
		return 0;
	else {
		int c = ((unsigned char)(*s));
		switch (*p) {
		case '.': return 1;
		case '%': return match_class(c, ((unsigned char)(*(p + 1))));
		case '[': return matchbracketclass(c, p, ep - 1);
		default:  return (((unsigned char)(*p)) == c);
		}
	}
}

static const char *matchbalance(MatchState *ms, const char *s,
	const char *p) {
	if (p >= ms->p_end - 1)
		luaL_error(ms->L, "malformed pattern (missing arguments to '%%b')");
	if (*s != *p) return ((void *)0);
	else {
		int b = *p;
		int e = *(p + 1);
		int cont = 1;
		while (++s < ms->src_end) {
			if (*s == e) {
				if (--cont == 0) return s + 1;
			}
			else if (*s == b) cont++;
		}
	}
	return ((void *)0);
}

static const char *max_expand(MatchState *ms, const char *s,
	const char *p, const char *ep) {
	ptrdiff_t i = 0;
	while (singlematch(ms, s + i, p, ep))
		i++;

	while (i >= 0) {
		const char *res = match(ms, (s + i), ep + 1);
		if (res) return res;
		i--;
	}
	return ((void *)0);
}

static const char *min_expand(MatchState *ms, const char *s,
	const char *p, const char *ep) {
	for (;
		;
		) {
		const char *res = match(ms, s, ep + 1);
		if (res != ((void *)0))
			return res;
		else if (singlematch(ms, s, p, ep))
			s++;
		else return ((void *)0);
	}
}

static const char *start_capture(MatchState *ms, const char *s,
	const char *p, int what) {
	const char *res;
	int level = ms->level;
	if (level >= 32) luaL_error(ms->L, "too many captures");
	ms->capture[level].init = s;
	ms->capture[level].len = what;
	ms->level = level + 1;
	if ((res = match(ms, s, p)) == ((void *)0))
		ms->level--;
	return res;
}

static const char *end_capture(MatchState *ms, const char *s,
	const char *p) {
	int l = capture_to_close(ms);
	const char *res;
	ms->capture[l].len = s - ms->capture[l].init;
	if ((res = match(ms, s, p)) == ((void *)0))
		ms->capture[l].len = (-1);
	return res;
}

static const char *match_capture(MatchState *ms, const char *s, int l) {
	size_t len;
	l = check_capture(ms, l);
	len = ms->capture[l].len;
	if ((size_t)(ms->src_end - s) >= len &&
		memcmp(ms->capture[l].init, s, len) == 0)
		return s + len;
	else return ((void *)0);
}

static const char *match(MatchState *ms, const char *s, const char *p) {
	if (ms->matchdepth-- == 0)
		luaL_error(ms->L, "pattern too complex");
init:
	if (p != ms->p_end) {
		switch (*p) {
		case '(': {
			if (*(p + 1) == ')')
				s = start_capture(ms, s, p + 2, (-2));
			else
				s = start_capture(ms, s, p + 1, (-1));
			break;
		}
		case ')': {
			s = end_capture(ms, s, p + 1);
			break;
		}
		case '$': {
			if ((p + 1) != ms->p_end)
				goto dflt;
			s = (s == ms->src_end) ? s : ((void *)0);
			break;
		}
		case '%': {
			switch (*(p + 1)) {
			case 'b': {
				s = matchbalance(ms, s, p + 2);
				if (s != ((void *)0)) {
					p += 4;
					goto init;
				}
				break;
			}
			case 'f': {
				const char *ep;
				char previous;
				p += 2;
				if (*p != '[')
					luaL_error(ms->L, "missing '[' after '%%f' in pattern");
				ep = classend(ms, p);
				previous = (s == ms->src_init) ? '\0' : *(s - 1);
				if (!matchbracketclass(((unsigned char)(previous)), p, ep - 1) &&
					matchbracketclass(((unsigned char)(*s)), p, ep - 1)) {
					p = ep;
					goto init;
				}
				s = ((void *)0);
				break;
			}
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9': {
				s = match_capture(ms, s, ((unsigned char)(*(p + 1))));
				if (s != ((void *)0)) {
					p += 2;
					goto init;
				}
				break;
			}
			default: goto dflt;
			}
			break;
		}
		default: dflt : {
			const char *ep = classend(ms, p);

			if (!singlematch(ms, s, p, ep)) {
				if (*ep == '*' || *ep == '?' || *ep == '-') {
					p = ep + 1;
					goto init;
				}
				else
					s = ((void *)0);
			}
			else {
				switch (*ep) {
				case '?': {
					const char *res;
					if ((res = match(ms, s + 1, ep + 1)) != ((void *)0))
						s = res;
					else {
						p = ep + 1;
						goto init;
					}
					break;
				}
				case '+':
					s++;

				case '*':
					s = max_expand(ms, s, p, ep);
					break;
				case '-':
					s = min_expand(ms, s, p, ep);
					break;
				default:
					s++;
					p = ep;
					goto init;
				}
			}
			break;
		}
		}
	}
	ms->matchdepth++;
	return s;
}

static const char *lmemfind(const char *s1, size_t l1,
	const char *s2, size_t l2) {
	if (l2 == 0) return s1;
	else if (l2 > l1) return ((void *)0);
	else {
		const char *init;
		l2--;
		l1 = l1 - l2;
		while (l1 > 0 && (init = (const char *)memchr(s1, *s2, l1)) != ((void *)0)) {
			init++;
			if (memcmp(init, s2 + 1, l2) == 0)
				return init - 1;
			else {
				l1 -= init - s1;
				s1 = init;
			}
		}
		return ((void *)0);
	}
}

static void push_onecapture(MatchState *ms, int i, const char *s,
	const char *e) {
	if (i >= ms->level) {
		if (i == 0)
			lua_pushlstring(ms->L, s, e - s);
		else
			luaL_error(ms->L, "invalid capture index %%%d", i + 1);
	}
	else {
		ptrdiff_t l = ms->capture[i].len;
		if (l == (-1)) luaL_error(ms->L, "unfinished capture");
		if (l == (-2))
			lua_pushinteger(ms->L, (ms->capture[i].init - ms->src_init) + 1);
		else
			lua_pushlstring(ms->L, ms->capture[i].init, l);
	}
}

static int push_captures(MatchState *ms, const char *s, const char *e) {
	int i;
	int nlevels = (ms->level == 0 && s) ? 1 : ms->level;
	luaL_checkstack(ms->L, nlevels, "too many captures");
	for (i = 0;
		i < nlevels;
		i++)
		push_onecapture(ms, i, s, e);
	return nlevels;
}

static int nospecials(const char *p, size_t l) {
	size_t upto = 0;
	do {
		if (strpbrk(p + upto, "^$*+?.([%-"))
			return 0;
		upto += strlen(p + upto) + 1;
	} while (upto <= l);
	return 1;
}

static void prepstate(MatchState *ms, lua_State *L,
	const char *s, size_t ls, const char *p, size_t lp) {
	ms->L = L;
	ms->matchdepth = 200;
	ms->src_init = s;
	ms->src_end = s + ls;
	ms->p_end = p + lp;
}

static void reprepstate(MatchState *ms) {
	ms->level = 0;
	((void)0);
}

static int str_find_aux(lua_State *L, int find) {
	size_t ls, lp;
	const char *s = luaL_checklstring(L, 1, &ls);
	const char *p = luaL_checklstring(L, 2, &lp);
	lua_Integer init = posrelat(luaL_optinteger(L, 3, 1), ls);
	if (init < 1) init = 1;
	else if (init > (lua_Integer)ls + 1) {
		lua_pushnil(L);
		return 1;
	}

	if (find && (lua_toboolean(L, 4) || nospecials(p, lp))) {

		const char *s2 = lmemfind(s + init - 1, ls - (size_t)init + 1, p, lp);
		if (s2) {
			lua_pushinteger(L, (s2 - s) + 1);
			lua_pushinteger(L, (s2 - s) + lp);
			return 2;
		}
	}
	else {
		MatchState ms;
		const char *s1 = s + init - 1;
		int anchor = (*p == '^');
		if (anchor) {
			p++;
			lp--;
		}
		prepstate(&ms, L, s, ls, p, lp);
		do {
			const char *res;
			reprepstate(&ms);
			if ((res = match(&ms, s1, p)) != ((void *)0)) {
				if (find) {
					lua_pushinteger(L, (s1 - s) + 1);
					lua_pushinteger(L, res - s);
					return push_captures(&ms, ((void *)0), 0) + 2;
				}
				else
					return push_captures(&ms, s1, res);
			}
		} while (s1++ < ms.src_end && !anchor);
	}
	lua_pushnil(L);
	return 1;
}

static int str_find(lua_State *L) {
	return str_find_aux(L, 1);
}

static int str_match(lua_State *L) {
	return str_find_aux(L, 0);
}

typedef struct GMatchState {
	const char *src;
	const char *p;
	const char *lastmatch;
	MatchState ms;
} GMatchState;

static int gmatch_aux(lua_State *L) {
	GMatchState *gm = (GMatchState *)lua_touserdata(L, ((-1000000 - 1000) - (3)));
	const char *src;
	gm->ms.L = L;
	for (src = gm->src;
		src <= gm->ms.src_end;
		src++) {
		const char *e;
		reprepstate(&gm->ms);
		if ((e = match(&gm->ms, src, gm->p)) != ((void *)0) && e != gm->lastmatch) {
			gm->src = gm->lastmatch = e;
			return push_captures(&gm->ms, src, e);
		}
	}
	return 0;
}

static int gmatch(lua_State *L) {
	size_t ls, lp;
	const char *s = luaL_checklstring(L, 1, &ls);
	const char *p = luaL_checklstring(L, 2, &lp);
	GMatchState *gm;
	lua_settop(L, 2);
	gm = (GMatchState *)lua_newuserdata(L, sizeof(GMatchState));
	prepstate(&gm->ms, L, s, ls, p, lp);
	gm->src = s;
	gm->p = p;
	gm->lastmatch = ((void *)0);
	lua_pushcclosure(L, gmatch_aux, 3);
	return 1;
}

static void add_s(MatchState *ms, luaL_Buffer *b, const char *s,
	const char *e) {
	size_t l, i;
	lua_State *L = ms->L;
	const char *news = lua_tolstring(L, 3, &l);
	for (i = 0;
		i < l;
		i++) {
		if (news[i] != '%')
			((void)((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = (news[i])));
		else {
			i++;
			if (!isdigit(((unsigned char)(news[i])))) {
				if (news[i] != '%')
					luaL_error(L, "invalid use of '%c' in replacement string", '%');
				((void)((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = (news[i])));
			}
			else if (news[i] == '0')
				luaL_addlstring(b, s, e - s);
			else {
				push_onecapture(ms, news[i] - '1', s, e);
				luaL_tolstring(L, -1, ((void *)0));
				(lua_rotate(L, (-2), -1), lua_settop(L, -(1) - 1));
				luaL_addvalue(b);
			}
		}
	}
}

static void add_value(MatchState *ms, luaL_Buffer *b, const char *s,
	const char *e, int tr) {
	lua_State *L = ms->L;
	switch (tr) {
	case 6: {
		int n;
		lua_pushvalue(L, 3);
		n = push_captures(ms, s, e);
		lua_callk(L, (n), (1), 0, ((void *)0));
		break;
	}
	case 5: {
		push_onecapture(ms, 0, s, e);
		lua_gettable(L, 3);
		break;
	}
	default: {
		add_s(ms, b, s, e);
		return;
	}
	}
	if (!lua_toboolean(L, -1)) {
		lua_settop(L, -(1) - 1);
		lua_pushlstring(L, s, e - s);
	}
	else if (!lua_isstring(L, -1))
		luaL_error(L, "invalid replacement value (a %s)", lua_typename(L, lua_type(L, (-1))));
	luaL_addvalue(b);
}

static int str_gsub(lua_State *L) {
	size_t srcl, lp;
	const char *src = luaL_checklstring(L, 1, &srcl);
	const char *p = luaL_checklstring(L, 2, &lp);
	const char *lastmatch = ((void *)0);
	int tr = lua_type(L, 3);
	lua_Integer max_s = luaL_optinteger(L, 4, srcl + 1);
	int anchor = (*p == '^');
	lua_Integer n = 0;
	MatchState ms;
	luaL_Buffer b;
	((void)((tr == 3 || tr == 4 || tr == 6 || tr == 5) || luaL_argerror(L, (3), ("string/function/table expected"))));
	luaL_buffinit(L, &b);
	if (anchor) {
		p++;
		lp--;
	}
	prepstate(&ms, L, src, srcl, p, lp);
	while (n < max_s) {
		const char *e;
		reprepstate(&ms);
		if ((e = match(&ms, src, p)) != ((void *)0) && e != lastmatch) {
			n++;
			add_value(&ms, &b, src, e, tr);
			src = lastmatch = e;
		}
		else if (src < ms.src_end)
			((void)((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)), ((&b)->b[(&b)->n++] = (*src++)));
		else break;
		if (anchor) break;
	}
	luaL_addlstring(&b, src, ms.src_end - src);
	luaL_pushresult(&b);
	lua_pushinteger(L, n);
	return 2;
}

#pragma pack(push,8)

struct _exception {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
};

struct _complex {
	double x, y;
};

typedef float float_t;
typedef double double_t;

__declspec(dllimport) extern double _HUGE;

void __cdecl _fperrraise(int _Except);

short __declspec(dllimport) __cdecl _dclass(double _X);
short __declspec(dllimport) __cdecl _ldclass(long double _X);
short __declspec(dllimport) __cdecl _fdclass(float _X);

int __declspec(dllimport) __cdecl _dsign(double _X);
int __declspec(dllimport) __cdecl _ldsign(long double _X);
int __declspec(dllimport) __cdecl _fdsign(float _X);

int __declspec(dllimport) __cdecl _dpcomp(double _X, double _Y);
int __declspec(dllimport) __cdecl _ldpcomp(long double _X, long double _Y);
int __declspec(dllimport) __cdecl _fdpcomp(float _X, float _Y);

short __declspec(dllimport) __cdecl _dtest(double *_Px);
short __declspec(dllimport) __cdecl _ldtest(long double *_Px);
short __declspec(dllimport) __cdecl _fdtest(float *_Px);

short __declspec(dllimport) __cdecl _d_int(double *_Px, short _Xexp);
short __declspec(dllimport) __cdecl _ld_int(long double *_Px, short _Xexp);
short __declspec(dllimport) __cdecl _fd_int(float *_Px, short _Xexp);

short __declspec(dllimport) __cdecl _dscale(double *_Px, long _Lexp);
short __declspec(dllimport) __cdecl _ldscale(long double *_Px, long _Lexp);
short __declspec(dllimport) __cdecl _fdscale(float *_Px, long _Lexp);

short __declspec(dllimport)  __cdecl _dunscale(short *_Pex, double *_Px);
short __declspec(dllimport) __cdecl _ldunscale(short *_Pex, long double *_Px);
short __declspec(dllimport) __cdecl _fdunscale(short *_Pex, float *_Px);

short __declspec(dllimport) __cdecl _dexp(double *_Px, double _Y, long _Eoff);
short __declspec(dllimport) __cdecl _ldexp(long double *_Px, long double _Y, long _Eoff);
short __declspec(dllimport) __cdecl _fdexp(float *_Px, float _Y, long _Eoff);

short __declspec(dllimport) __cdecl _dnorm(unsigned short *_Ps);
short __declspec(dllimport) __cdecl _fdnorm(unsigned short *_Ps);

double __cdecl _dpoly(double _X, const double *_Tab, int _N);
long double __cdecl _ldpoly(long double _X, const long double *_Tab, int _N);
float __cdecl _fdpoly(float _X, const float *_Tab, int _N);

double __declspec(dllimport) __cdecl _dlog(double _X, int _Baseflag);
long double __declspec(dllimport) __cdecl _ldlog(long double _X, int _Baseflag);
float __declspec(dllimport) __cdecl _fdlog(float _X, int _Baseflag);

double __declspec(dllimport) __cdecl _dsin(double _X, unsigned int _Qoff);
long double __declspec(dllimport) __cdecl _ldsin(long double _X, unsigned int _Qoff);
float __declspec(dllimport) __cdecl _fdsin(float _X, unsigned int _Qoff);

typedef union
{
	unsigned short _Sh[8];
	double _Val;
} _double_val;

typedef union
{
	unsigned short _Sh[8];
	float _Val;
} _float_val;

typedef union
{
	unsigned short _Sh[8];
	long double _Val;
} _ldouble_val;

typedef union
{
	unsigned short _Word[8];
	float _Float;
	double _Double;
	long double _Long_double;
} _float_const;

extern const _float_const _Denorm_C, _Inf_C, _Nan_C, _Snan_C, _Hugeval_C;
extern const _float_const _FDenorm_C, _FInf_C, _FNan_C, _FSnan_C;
extern const _float_const _LDenorm_C, _LInf_C, _LNan_C, _LSnan_C;

extern const _float_const _Eps_C, _Rteps_C;
extern const _float_const _FEps_C, _FRteps_C;
extern const _float_const _LEps_C, _LRteps_C;

extern const double _Zero_C, _Xbig_C;
extern const float _FZero_C, _FXbig_C;
extern const long double _LZero_C, _LXbig_C;

int       __cdecl abs(int _X);
long      __cdecl labs(long _X);
long long __cdecl llabs(long long _X);

double  __cdecl acos(double _X);
__declspec(dllimport) double __cdecl acosh(double _X);
double  __cdecl asin(double _X);
__declspec(dllimport) double __cdecl asinh(double _X);
double  __cdecl atan(double _X);
__declspec(dllimport) double __cdecl atanh(double _X);
double  __cdecl atan2(double _Y, double _X);

__declspec(dllimport) double __cdecl cbrt(double _X);
__declspec(dllimport) double __cdecl copysign(double _X, double _Y);
double  __cdecl cos(double _X);
double  __cdecl cosh(double _X);
__declspec(dllimport) double __cdecl erf(double _X);
__declspec(dllimport) double __cdecl erfc(double _X);
double  __cdecl exp(double _X);
__declspec(dllimport) double __cdecl exp2(double _X);
__declspec(dllimport) double __cdecl expm1(double _X);
double  __cdecl fabs(double _X);
__declspec(dllimport) double __cdecl fdim(double _X, double _Y);
__declspec(dllimport) double __cdecl fma(double _X, double _Y, double _Z);
__declspec(dllimport) double __cdecl fmax(double _X, double _Y);
__declspec(dllimport) double __cdecl fmin(double _X, double _Y);
double  __cdecl fmod(double _X, double _Y);
__declspec(dllimport) int __cdecl ilogb(double _X);
__declspec(dllimport) double __cdecl lgamma(double _X);
__declspec(dllimport) long long __cdecl llrint(double _X);
__declspec(dllimport) long long __cdecl llround(double _X);
double  __cdecl log(double _X);
double  __cdecl log10(double _X);
__declspec(dllimport) double __cdecl log1p(double _X);
__declspec(dllimport) double __cdecl log2(double _X);
__declspec(dllimport) double __cdecl logb(double _X);
__declspec(dllimport) long __cdecl lrint(double _X);
__declspec(dllimport) long __cdecl lround(double _X);
__declspec(dllimport) double __cdecl nan(const char *);
__declspec(dllimport) double __cdecl nearbyint(double _X);
__declspec(dllimport) double __cdecl nextafter(double _X, double _Y);
__declspec(dllimport) double __cdecl nexttoward(double _X, long double _Y);
double  __cdecl pow(double _X, double _Y);
__declspec(dllimport) double __cdecl remainder(double _X, double _Y);
__declspec(dllimport) double __cdecl remquo(double _X, double _Y, int *_Z);
__declspec(dllimport) double __cdecl rint(double _X);
__declspec(dllimport) double __cdecl round(double _X);
__declspec(dllimport) double __cdecl scalbln(double _X, long _Y);
__declspec(dllimport) double __cdecl scalbn(double _X, int _Y);
double  __cdecl sin(double _X);
double  __cdecl sinh(double _X);
double  __cdecl sqrt(double _X);
double  __cdecl tan(double _X);
double  __cdecl tanh(double _X);
__declspec(dllimport) double __cdecl tgamma(double _X);
__declspec(dllimport) double __cdecl trunc(double _X);

__declspec(dllimport) double  __cdecl atof(const char *_String);
__declspec(dllimport) double  __cdecl _atof_l(const char *_String, _locale_t _Locale);

__declspec(dllimport) double  __cdecl _cabs(struct _complex _Complex_value);
__declspec(dllimport) double  __cdecl ceil(double _X);

__declspec(dllimport) double __cdecl _chgsign(double _X);
__declspec(dllimport) double __cdecl _copysign(double _Number, double _Sign);

__declspec(dllimport) double  __cdecl floor(double _X);
__declspec(dllimport) double  __cdecl frexp(double _X, int * _Y);
__declspec(dllimport) double  __cdecl _hypot(double _X, double _Y);
__declspec(dllimport) double  __cdecl _j0(double _X);
__declspec(dllimport) double  __cdecl _j1(double _X);
__declspec(dllimport) double  __cdecl _jn(int _X, double _Y);
__declspec(dllimport) double  __cdecl ldexp(double _X, int _Y);

int     __cdecl _matherr(struct _exception * _Except);

__declspec(dllimport) double  __cdecl modf(double _X, double * _Y);
__declspec(dllimport) double  __cdecl _y0(double _X);
__declspec(dllimport) double  __cdecl _y1(double _X);
__declspec(dllimport) double  __cdecl _yn(int _X, double _Y);

__inline double __cdecl hypot(double _X, double _Y)
{
	return _hypot(_X, _Y);
}

__declspec(dllimport) float __cdecl acoshf(float _X);
__declspec(dllimport) float __cdecl asinhf(float _X);
__declspec(dllimport) float __cdecl atanhf(float _X);
__declspec(dllimport) float __cdecl cbrtf(float _X);
__declspec(dllimport) float  __cdecl _chgsignf(float _X);
__declspec(dllimport) float __cdecl copysignf(float _X, float _Y);
__declspec(dllimport) float  __cdecl _copysignf(float _Number, float _Sign);
__declspec(dllimport) float __cdecl erff(float _X);
__declspec(dllimport) float __cdecl erfcf(float _X);
__declspec(dllimport) float __cdecl expm1f(float _X);
__declspec(dllimport) float __cdecl exp2f(float _X);
__declspec(dllimport) float __cdecl fdimf(float _X, float _Y);
__declspec(dllimport) float __cdecl fmaf(float _X, float _Y, float _Z);
__declspec(dllimport) float __cdecl fmaxf(float _X, float _Y);
__declspec(dllimport) float __cdecl fminf(float _X, float _Y);
__declspec(dllimport) float  __cdecl _hypotf(float _X, float _Y);
__declspec(dllimport) int __cdecl ilogbf(float _X);
__declspec(dllimport) float __cdecl lgammaf(float _X);
__declspec(dllimport) long long __cdecl llrintf(float _X);
__declspec(dllimport) long long __cdecl llroundf(float _X);
__declspec(dllimport) float __cdecl log1pf(float _X);
__declspec(dllimport) float __cdecl log2f(float _X);
__declspec(dllimport) float __cdecl logbf(float _X);
__declspec(dllimport) long __cdecl lrintf(float _X);
__declspec(dllimport) long __cdecl lroundf(float _X);
__declspec(dllimport) float __cdecl nanf(const char *);
__declspec(dllimport) float __cdecl nearbyintf(float _X);
__declspec(dllimport) float __cdecl nextafterf(float _X, float _Y);
__declspec(dllimport) float __cdecl nexttowardf(float _X, long double _Y);
__declspec(dllimport) float __cdecl remainderf(float _X, float _Y);
__declspec(dllimport) float __cdecl remquof(float _X, float _Y, int *_Z);
__declspec(dllimport) float __cdecl rintf(float _X);
__declspec(dllimport) float __cdecl roundf(float _X);
__declspec(dllimport) float __cdecl scalblnf(float _X, long _Y);
__declspec(dllimport) float __cdecl scalbnf(float _X, int _Y);
__declspec(dllimport) float __cdecl tgammaf(float _X);
__declspec(dllimport) float __cdecl truncf(float _X);

__declspec(dllimport) int  __cdecl _set_SSE2_enable(int _Flag);

__inline float  __cdecl acosf(float _X)
{
	return (float)acos(_X);
}

__inline float  __cdecl asinf(float _X)
{
	return (float)asin(_X);
}

__inline float  __cdecl atan2f(float _Y, float _X)
{
	return (float)atan2(_Y, _X);
}

__inline float  __cdecl atanf(float _X)
{
	return (float)atan(_X);
}

__inline float  __cdecl ceilf(float _X)
{
	return (float)ceil(_X);
}

__inline float  __cdecl cosf(float _X)
{
	return (float)cos(_X);
}

__inline float  __cdecl coshf(float _X)
{
	return (float)cosh(_X);
}

__inline float  __cdecl expf(float _X)
{
	return (float)exp(_X);
}

__inline float __cdecl fabsf(float _X)
{
	return (float)fabs(_X);
}

__inline float __cdecl floorf(float _X)
{
	return (float)floor(_X);
}

__inline float __cdecl fmodf(float _X, float _Y)
{
	return (float)fmod(_X, _Y);
}

__inline float __cdecl frexpf(float _X, int *_Y)
{
	return (float)frexp(_X, _Y);
}

__inline float __cdecl hypotf(float _X, float _Y)
{
	return _hypotf(_X, _Y);
}

__inline float __cdecl ldexpf(float _X, int _Y)
{
	return (float)ldexp(_X, _Y);
}

__inline float __cdecl log10f(float _X)
{
	return (float)log10(_X);
}

__inline float __cdecl logf(float _X)
{
	return (float)log(_X);
}

__inline float __cdecl modff(float _X, float *_Y)
{
	double _F, _I;
	_F = modf(_X, &_I);
	*_Y = (float)_I;
	return (float)_F;
}

__inline float __cdecl powf(float _X, float _Y)
{
	return (float)pow(_X, _Y);
}

__inline float __cdecl sinf(float _X)
{
	return (float)sin(_X);
}

__inline float __cdecl sinhf(float _X)
{
	return (float)sinh(_X);
}

__inline float __cdecl sqrtf(float _X)
{
	return (float)sqrt(_X);
}

__inline float __cdecl tanf(float _X)
{
	return (float)tan(_X);
}

__inline float __cdecl tanhf(float _X)
{
	return (float)tanh(_X);
}

__declspec(dllimport) long double __cdecl acoshl(long double _X);

__inline long double __cdecl acosl(long double _X)
{
	return acos((double)_X);
}

__declspec(dllimport) long double __cdecl asinhl(long double _X);

__inline long double __cdecl asinl(long double _X)
{
	return asin((double)_X);
}

__inline long double __cdecl atan2l(long double _Y, long double _X)
{
	return atan2((double)_Y, (double)_X);
}

__declspec(dllimport) long double __cdecl atanhl(long double _X);

__inline long double __cdecl atanl(long double _X)
{
	return atan((double)_X);
}

__declspec(dllimport) long double __cdecl cbrtl(long double _X);

__inline long double __cdecl ceill(long double _X)
{
	return ceil((double)_X);
}

__inline long double __cdecl _chgsignl(long double _X)
{
	return _chgsign((double)_X);
}

__declspec(dllimport) long double __cdecl copysignl(long double _X, long double _Y);

__inline long double __cdecl _copysignl(long double _X, long double _Y)
{
	return _copysign((double)_X, (double)_Y);
}

__inline long double __cdecl coshl(long double _X)
{
	return cosh((double)_X);
}

__inline long double __cdecl cosl(long double _X)
{
	return cos((double)_X);
}

__declspec(dllimport) long double __cdecl erfl(long double _X);
__declspec(dllimport) long double __cdecl erfcl(long double _X);

__inline long double __cdecl expl(long double _X)
{
	return exp((double)_X);
}

__declspec(dllimport) long double __cdecl exp2l(long double _X);
__declspec(dllimport) long double __cdecl expm1l(long double _X);

__inline long double __cdecl fabsl(long double _X)
{
	return fabs((double)_X);
}

__declspec(dllimport) long double __cdecl fdiml(long double _X, long double _Y);

__inline long double __cdecl floorl(long double _X)
{
	return floor((double)_X);
}

__declspec(dllimport) long double __cdecl fmal(long double _X, long double _Y, long double _Z);
__declspec(dllimport) long double __cdecl fmaxl(long double _X, long double _Y);
__declspec(dllimport) long double __cdecl fminl(long double _X, long double _Y);

__inline long double __cdecl fmodl(long double _X, long double _Y)
{
	return fmod((double)_X, (double)_Y);
}

__inline long double __cdecl frexpl(long double _X, int *_Y)
{
	return frexp((double)_X, _Y);
}

__declspec(dllimport) int __cdecl ilogbl(long double _X);

__inline long double __cdecl _hypotl(long double _X, long double _Y)
{
	return _hypot((double)_X, (double)_Y);
}

__inline long double __cdecl hypotl(long double _X, long double _Y)
{
	return _hypot((double)_X, (double)_Y);
}

__inline long double __cdecl ldexpl(long double _X, int _Y)
{
	return ldexp((double)_X, _Y);
}

__declspec(dllimport) long double __cdecl lgammal(long double _X);
__declspec(dllimport) long long __cdecl llrintl(long double _X);
__declspec(dllimport) long long __cdecl llroundl(long double _X);

__inline long double __cdecl logl(long double _X)
{
	return log((double)_X);
}

__inline long double __cdecl log10l(long double _X)
{
	return log10((double)_X);
}

__declspec(dllimport) long double __cdecl log1pl(long double _X);
__declspec(dllimport) long double __cdecl log2l(long double _X);
__declspec(dllimport) long double __cdecl logbl(long double _X);
__declspec(dllimport) long __cdecl lrintl(long double _X);
__declspec(dllimport) long __cdecl lroundl(long double _X);

__inline long double __cdecl modfl(long double _X, long double *_Y)
{
	double _F, _I;
	_F = modf((double)_X, &_I);
	*_Y = _I;
	return _F;
}
__declspec(dllimport) long double __cdecl nanl(const char *);
__declspec(dllimport) long double __cdecl nearbyintl(long double _X);
__declspec(dllimport) long double __cdecl nextafterl(long double _X, long double _Y);
__declspec(dllimport) long double __cdecl nexttowardl(long double _X, long double _Y);

__inline long double __cdecl powl(long double _X, long double _Y)
{
	return pow((double)_X, (double)_Y);
}

__declspec(dllimport) long double __cdecl remainderl(long double _X, long double _Y);
__declspec(dllimport) long double __cdecl remquol(long double _X, long double _Y, int *_Z);
__declspec(dllimport) long double __cdecl rintl(long double _X);
__declspec(dllimport) long double __cdecl roundl(long double _X);
__declspec(dllimport) long double __cdecl scalblnl(long double _X, long _Y);
__declspec(dllimport) long double __cdecl scalbnl(long double _X, int _Y);

__inline long double __cdecl sinhl(long double _X)
{
	return sinh((double)_X);
}

__inline long double __cdecl sinl(long double _X)
{
	return sin((double)_X);
}

__inline long double __cdecl sqrtl(long double _X)
{
	return sqrt((double)_X);
}

__inline long double __cdecl tanhl(long double _X)
{
	return tanh((double)_X);
}

__inline long double __cdecl tanl(long double _X)
{
	return tan((double)_X);
}

__declspec(dllimport) long double __cdecl tgammal(long double _X);
__declspec(dllimport) long double __cdecl truncl(long double _X);

__declspec(dllimport) extern double HUGE;

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_j0" ". See online help for details.")) __declspec(dllimport) double  __cdecl j0(double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_j1" ". See online help for details.")) __declspec(dllimport) double  __cdecl j1(double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_jn" ". See online help for details.")) __declspec(dllimport) double  __cdecl jn(int _X, double _Y);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_y0" ". See online help for details.")) __declspec(dllimport) double  __cdecl y0(double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_y1" ". See online help for details.")) __declspec(dllimport) double  __cdecl y1(double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_yn" ". See online help for details.")) __declspec(dllimport) double  __cdecl yn(int _X, double _Y);

#pragma pack(pop)

static lua_Number adddigit(char *buff, int n, lua_Number x) {
	lua_Number dd = (lua_Number)floor(x);
	int d = (int)dd;
	buff[n] = (d < 10 ? d + '0' : d - 10 + 'a');
	return x - dd;
}

static int num2straux(char *buff, int sz, lua_Number x) {
	if (x != x || x == _HUGE || x == -_HUGE)
		return ((void)(sz), sprintf(buff, "%.14g", x));
	else if (x == 0) {

		return ((void)(sz), sprintf(buff, "%.14g" "x0p+0", x));
	}
	else {
		int e;
		lua_Number m = (lua_Number)frexp(x, &e);
		int n = 0;
		if (m < 0) {
			buff[n++] = '-';
			m = -m;
		}
		buff[n++] = '0';
		buff[n++] = 'x';
		m = adddigit(buff, n++, m * (1 << (((53) - 1) % 4 + 1)));
		e -= (((53) - 1) % 4 + 1);
		if (m > 0) {
			buff[n++] = (localeconv()->decimal_point[0]);
			do {
				m = adddigit(buff, n++, m * 16);
			} while (m > 0);
		}
		n += ((void)(sz - n), sprintf(buff + n, "p%+d", e));
		((void)0);
		return n;
	}
}

static int lua_number2strx(lua_State *L, char *buff, int sz,
	const char *fmt, lua_Number x) {
	int n = num2straux(buff, sz, x);
	if (fmt[(sizeof("") / sizeof(char))] == 'A') {
		int i;
		for (i = 0;
			i < n;
			i++)
			buff[i] = toupper(((unsigned char)(buff[i])));
	}
	else if (fmt[(sizeof("") / sizeof(char))] != 'a')
		luaL_error(L, "modifiers for format '%%a'/'%%A' not implemented");
	return n;
}

static void addquoted(luaL_Buffer *b, const char *s, size_t len) {
	((void)((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = ('"')));
	while (len--) {
		if (*s == '"' || *s == '\\' || *s == '\n') {
			((void)((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = ('\\')));
			((void)((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = (*s)));
		}
		else if (iscntrl(((unsigned char)(*s)))) {
			char buff[10];
			if (!isdigit(((unsigned char)(*(s + 1)))))
				((void)(sizeof(buff)), sprintf(buff, "\\%d", (int)((unsigned char)(*s))));
			else
				((void)(sizeof(buff)), sprintf(buff, "\\%03d", (int)((unsigned char)(*s))));
			luaL_addstring(b, buff);
		}
		else
			((void)((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = (*s)));
		s++;
	}
	((void)((b)->n < (b)->size || luaL_prepbuffsize((b), 1)), ((b)->b[(b)->n++] = ('"')));
}

static void checkdp(char *buff, int nb) {
	if (memchr(buff, '.', nb) == ((void *)0)) {
		char point = (localeconv()->decimal_point[0]);
		char *ppoint = memchr(buff, point, nb);
		if (ppoint) *ppoint = '.';
	}
}

static void addliteral(lua_State *L, luaL_Buffer *b, int arg) {
	switch (lua_type(L, arg)) {
	case 4: {
		size_t len;
		const char *s = lua_tolstring(L, arg, &len);
		addquoted(b, s, len);
		break;
	}
	case 3: {
		char *buff = luaL_prepbuffsize(b, (120 + (308)));
		int nb;
		if (!lua_isinteger(L, arg)) {
			lua_Number n = lua_tonumberx(L, (arg), ((void *)0));
			nb = lua_number2strx(L, buff, (120 + (308)), "%" "" "a", n);
			checkdp(buff, nb);
		}
		else {
			lua_Integer n = lua_tointegerx(L, (arg), ((void *)0));
			const char *format = (n == (-9223372036854775807i64 - 1))
				? "0x%" "ll" "x"
				: "%" "ll" "d";
			nb = ((void)((120 + (308))), sprintf(buff, format, n));
		}
		((b)->n += (nb));
		break;
	}
	case 0: case 1: {
		luaL_tolstring(L, arg, ((void *)0));
		luaL_addvalue(b);
		break;
	}
	default: {
		luaL_argerror(L, arg, "value has no literal form");
	}
	}
}

static const char *scanformat(lua_State *L, const char *strfrmt, char *form) {
	const char *p = strfrmt;
	while (*p != '\0' && strchr("-+ #0", *p) != ((void *)0)) p++;
	if ((size_t)(p - strfrmt) >= sizeof("-+ #0") / sizeof(char))
		luaL_error(L, "invalid format (repeated flags)");
	if (isdigit(((unsigned char)(*p)))) p++;
	if (isdigit(((unsigned char)(*p)))) p++;
	if (*p == '.') {
		p++;
		if (isdigit(((unsigned char)(*p)))) p++;
		if (isdigit(((unsigned char)(*p)))) p++;
	}
	if (isdigit(((unsigned char)(*p))))
		luaL_error(L, "invalid format (width or precision too long)");
	*(form++) = '%';
	memcpy(form, strfrmt, ((p - strfrmt) + 1) * sizeof(char));
	form += (p - strfrmt) + 1;
	*form = '\0';
	return p;
}

static void addlenmod(char *form, const char *lenmod) {
	size_t l = strlen(form);
	size_t lm = strlen(lenmod);
	char spec = form[l - 1];
	strcpy(form + l - 1, lenmod);
	form[l + lm - 1] = spec;
	form[l + lm] = '\0';
}

static int str_format(lua_State *L) {
	int top = lua_gettop(L);
	int arg = 1;
	size_t sfl;
	const char *strfrmt = luaL_checklstring(L, arg, &sfl);
	const char *strfrmt_end = strfrmt + sfl;
	luaL_Buffer b;
	luaL_buffinit(L, &b);
	while (strfrmt < strfrmt_end) {
		if (*strfrmt != '%')
			((void)((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)), ((&b)->b[(&b)->n++] = (*strfrmt++)));
		else if (*++strfrmt == '%')
			((void)((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)), ((&b)->b[(&b)->n++] = (*strfrmt++)));
		else {
			char form[32];
			char *buff = luaL_prepbuffsize(&b, (120 + (308)));
			int nb = 0;
			if (++arg > top)
				luaL_argerror(L, arg, "no value");
			strfrmt = scanformat(L, strfrmt, form);
			switch (*strfrmt++) {
			case 'c': {
				nb = ((void)((120 + (308))), sprintf(buff, form, (int)luaL_checkinteger(L, arg)));
				break;
			}
			case 'd': case 'i':
			case 'o': case 'u': case 'x': case 'X': {
				lua_Integer n = luaL_checkinteger(L, arg);
				addlenmod(form, "ll");
				nb = ((void)((120 + (308))), sprintf(buff, form, n));
				break;
			}
			case 'a': case 'A':
				addlenmod(form, "");
				nb = lua_number2strx(L, buff, (120 + (308)), form,
					luaL_checknumber(L, arg));
				break;
			case 'e': case 'E': case 'f':
			case 'g': case 'G': {
				addlenmod(form, "");
				nb = ((void)((120 + (308))), sprintf(buff, form, luaL_checknumber(L, arg)));
				break;
			}
			case 'q': {
				addliteral(L, &b, arg);
				break;
			}
			case 's': {
				size_t l;
				const char *s = luaL_tolstring(L, arg, &l);
				if (form[2] == '\0')
					luaL_addvalue(&b);
				else {
					((void)((l == strlen(s)) || luaL_argerror(L, (arg), ("string contains zeros"))));
					if (!strchr(form, '.') && l >= 100) {

						luaL_addvalue(&b);
					}
					else {
						nb = ((void)((120 + (308))), sprintf(buff, form, s));
						lua_settop(L, -(1) - 1);
					}
				}
				break;
			}
			default: {
				return luaL_error(L, "invalid option '%%%c' to 'format'",
					*(strfrmt - 1));
			}
			}
			((void)0);
			((&b)->n += (nb));
		}
	}
	luaL_pushresult(&b);
	return 1;
}

static const union {
	int dummy;
	char little;
} nativeendian = {
	1
};

struct cD {
	char c;
	union {
		double d;
		void *p;
		lua_Integer i;
		lua_Number n;
	} u;
};

typedef union Ftypes {
	float f;
	double d;
	lua_Number n;
	char buff[5 * sizeof(lua_Number)];
} Ftypes;

typedef struct Header {
	lua_State *L;
	int islittle;
	int maxalign;
} Header;

typedef enum KOption {
	Kint,
	Kuint,
	Kfloat,
	Kchar,
	Kstring,
	Kzstr,
	Kpadding,
	Kpaddalign,
	Knop
} KOption;

static int digit(int c) {
	return '0' <= c && c <= '9';
}

static int getnum(const char **fmt, int df) {
	if (!digit(**fmt))
		return df;
	else {
		int a = 0;
		do {
			a = a * 10 + (*((*fmt)++) - '0');
		} while (digit(**fmt) && a <= ((int)(sizeof(size_t) < sizeof(int) ? ((size_t)(~(size_t)0)) : (size_t)(2147483647)) - 9) / 10);
		return a;
	}
}

static int getnumlimit(Header *h, const char **fmt, int df) {
	int sz = getnum(fmt, df);
	if (sz > 16 || sz <= 0)
		luaL_error(h->L, "integral size (%d) out of limits [1,%d]",
		sz, 16);
	return sz;
}

static void initheader(lua_State *L, Header *h) {
	h->L = L;
	h->islittle = nativeendian.little;
	h->maxalign = 1;
}

static KOption getoption(Header *h, const char **fmt, int *size) {
	int opt = *((*fmt)++);
	*size = 0;
	switch (opt) {
	case 'b': *size = sizeof(char);
		return Kint;
	case 'B': *size = sizeof(char);
		return Kuint;
	case 'h': *size = sizeof(short);
		return Kint;
	case 'H': *size = sizeof(short);
		return Kuint;
	case 'l': *size = sizeof(long);
		return Kint;
	case 'L': *size = sizeof(long);
		return Kuint;
	case 'j': *size = sizeof(lua_Integer);
		return Kint;
	case 'J': *size = sizeof(lua_Integer);
		return Kuint;
	case 'T': *size = sizeof(size_t);
		return Kuint;
	case 'f': *size = sizeof(float);
		return Kfloat;
	case 'd': *size = sizeof(double);
		return Kfloat;
	case 'n': *size = sizeof(lua_Number);
		return Kfloat;
	case 'i': *size = getnumlimit(h, fmt, sizeof(int));
		return Kint;
	case 'I': *size = getnumlimit(h, fmt, sizeof(int));
		return Kuint;
	case 's': *size = getnumlimit(h, fmt, sizeof(size_t));
		return Kstring;
	case 'c':
		*size = getnum(fmt, -1);
		if (*size == -1)
			luaL_error(h->L, "missing size for format option 'c'");
		return Kchar;
	case 'z': return Kzstr;
	case 'x': *size = 1;
		return Kpadding;
	case 'X': return Kpaddalign;
	case ' ': break;
	case '<': h->islittle = 1;
		break;
	case '>': h->islittle = 0;
		break;
	case '=': h->islittle = nativeendian.little;
		break;
	case '!': h->maxalign = getnumlimit(h, fmt, ((size_t)&(((struct cD *)0)->u)));
		break;
	default: luaL_error(h->L, "invalid format option '%c'", opt);
	}
	return Knop;
}

static KOption getdetails(Header *h, size_t totalsize,
	const char **fmt, int *psize, int *ntoalign) {
	KOption opt = getoption(h, fmt, psize);
	int align = *psize;
	if (opt == Kpaddalign) {
		if (**fmt == '\0' || getoption(h, fmt, &align) == Kchar || align == 0)
			luaL_argerror(h->L, 1, "invalid next option for option 'X'");
	}
	if (align <= 1 || opt == Kchar)
		*ntoalign = 0;
	else {
		if (align > h->maxalign)
			align = h->maxalign;
		if ((align & (align - 1)) != 0)
			luaL_argerror(h->L, 1, "format asks for alignment not power of 2");
		*ntoalign = (align - (int)(totalsize & (align - 1))) & (align - 1);
	}
	return opt;
}

static void packint(luaL_Buffer *b, lua_Unsigned n,
	int islittle, int size, int neg) {
	char *buff = luaL_prepbuffsize(b, size);
	int i;
	buff[islittle ? 0 : size - 1] = (char)(n & ((1 << 8) - 1));
	for (i = 1;
		i < size;
		i++) {
		n >>= 8;
		buff[islittle ? i : size - 1 - i] = (char)(n & ((1 << 8) - 1));
	}
	if (neg && size > ((int)sizeof(lua_Integer))) {
		for (i = ((int)sizeof(lua_Integer));
			i < size;
			i++)
			buff[islittle ? i : size - 1 - i] = (char)((1 << 8) - 1);
	}
	((b)->n += (size));
}

static void copywithendian(volatile char *dest, volatile const char *src,
	int size, int islittle) {
	if (islittle == nativeendian.little) {
		while (size-- != 0)
			*(dest++) = *(src++);
	}
	else {
		dest += size - 1;
		while (size-- != 0)
			*(dest--) = *(src++);
	}
}

static int str_pack(lua_State *L) {
	luaL_Buffer b;
	Header h;
	const char *fmt = (luaL_checklstring(L, (1), ((void *)0)));
	int arg = 1;
	size_t totalsize = 0;
	initheader(L, &h);
	lua_pushnil(L);
	luaL_buffinit(L, &b);
	while (*fmt != '\0') {
		int size, ntoalign;
		KOption opt = getdetails(&h, totalsize, &fmt, &size, &ntoalign);
		totalsize += ntoalign + size;
		while (ntoalign-- > 0)
			((void)((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)), ((&b)->b[(&b)->n++] = (0x00)));
		arg++;
		switch (opt) {
		case Kint: {
			lua_Integer n = luaL_checkinteger(L, arg);
			if (size < ((int)sizeof(lua_Integer))) {
				lua_Integer lim = (lua_Integer)1 << ((size * 8) - 1);
				((void)((-lim <= n && n < lim) || luaL_argerror(L, (arg), ("integer overflow"))));
			}
			packint(&b, (lua_Unsigned)n, h.islittle, size, (n < 0));
			break;
		}
		case Kuint: {
			lua_Integer n = luaL_checkinteger(L, arg);
			if (size < ((int)sizeof(lua_Integer)))
				((void)(((lua_Unsigned)n < ((lua_Unsigned)1 << (size * 8))) || luaL_argerror(L, (arg), ("unsigned overflow"))));
			packint(&b, (lua_Unsigned)n, h.islittle, size, 0);
			break;
		}
		case Kfloat: {
			volatile Ftypes u;
			char *buff = luaL_prepbuffsize(&b, size);
			lua_Number n = luaL_checknumber(L, arg);
			if (size == sizeof(u.f)) u.f = (float)n;
			else if (size == sizeof(u.d)) u.d = (double)n;
			else u.n = n;

			copywithendian(buff, u.buff, size, h.islittle);
			((&b)->n += (size));
			break;
		}
		case Kchar: {
			size_t len;
			const char *s = luaL_checklstring(L, arg, &len);
			((void)((len <= (size_t)size) || luaL_argerror(L, (arg), ("string longer than given size"))));
			luaL_addlstring(&b, s, len);
			while (len++ < (size_t)size)
				((void)((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)), ((&b)->b[(&b)->n++] = (0x00)));
			break;
		}
		case Kstring: {
			size_t len;
			const char *s = luaL_checklstring(L, arg, &len);
			((void)((size >= (int)sizeof(size_t) || len < ((size_t)1 << (size * 8))) || luaL_argerror(L, (arg), ("string length does not fit in given size"))));
			packint(&b, (lua_Unsigned)len, h.islittle, size, 0);
			luaL_addlstring(&b, s, len);
			totalsize += len;
			break;
		}
		case Kzstr: {
			size_t len;
			const char *s = luaL_checklstring(L, arg, &len);
			((void)((strlen(s) == len) || luaL_argerror(L, (arg), ("string contains zeros"))));
			luaL_addlstring(&b, s, len);
			((void)((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)), ((&b)->b[(&b)->n++] = ('\0')));
			totalsize += len + 1;
			break;
		}
		case Kpadding: ((void)((&b)->n < (&b)->size || luaL_prepbuffsize((&b), 1)), ((&b)->b[(&b)->n++] = (0x00)));
		case Kpaddalign: case Knop:
			arg--;
			break;
		}
	}
	luaL_pushresult(&b);
	return 1;
}

static int str_packsize(lua_State *L) {
	Header h;
	const char *fmt = (luaL_checklstring(L, (1), ((void *)0)));
	size_t totalsize = 0;
	initheader(L, &h);
	while (*fmt != '\0') {
		int size, ntoalign;
		KOption opt = getdetails(&h, totalsize, &fmt, &size, &ntoalign);
		size += ntoalign;
		((void)((totalsize <= (sizeof(size_t) < sizeof(int) ? ((size_t)(~(size_t)0)) : (size_t)(2147483647)) - size) || luaL_argerror(L, (1), ("format result too large"))));
		totalsize += size;
		switch (opt) {
		case Kstring:
		case Kzstr:
			luaL_argerror(L, 1, "variable-length format");

		default:  break;
		}
	}
	lua_pushinteger(L, (lua_Integer)totalsize);
	return 1;
}

static lua_Integer unpackint(lua_State *L, const char *str,
	int islittle, int size, int issigned) {
	lua_Unsigned res = 0;
	int i;
	int limit = (size <= ((int)sizeof(lua_Integer))) ? size : ((int)sizeof(lua_Integer));
	for (i = limit - 1;
		i >= 0;
		i--) {
		res <<= 8;
		res |= (lua_Unsigned)(unsigned char)str[islittle ? i : size - 1 - i];
	}
	if (size < ((int)sizeof(lua_Integer))) {
		if (issigned) {
			lua_Unsigned mask = (lua_Unsigned)1 << (size * 8 - 1);
			res = ((res ^ mask) - mask);
		}
	}
	else if (size > ((int)sizeof(lua_Integer))) {
		int mask = (!issigned || (lua_Integer)res >= 0) ? 0 : ((1 << 8) - 1);
		for (i = limit;
			i < size;
			i++) {
			if ((unsigned char)str[islittle ? i : size - 1 - i] != mask)
				luaL_error(L, "%d-byte integer does not fit into Lua Integer", size);
		}
	}
	return (lua_Integer)res;
}

static int str_unpack(lua_State *L) {
	Header h;
	const char *fmt = (luaL_checklstring(L, (1), ((void *)0)));
	size_t ld;
	const char *data = luaL_checklstring(L, 2, &ld);
	size_t pos = (size_t)posrelat(luaL_optinteger(L, 3, 1), ld) - 1;
	int n = 0;
	((void)((pos <= ld) || luaL_argerror(L, (3), ("initial position out of string"))));
	initheader(L, &h);
	while (*fmt != '\0') {
		int size, ntoalign;
		KOption opt = getdetails(&h, pos, &fmt, &size, &ntoalign);
		if ((size_t)ntoalign + size > ~pos || pos + ntoalign + size > ld)
			luaL_argerror(L, 2, "data string too short");
		pos += ntoalign;

		luaL_checkstack(L, 2, "too many results");
		n++;
		switch (opt) {
		case Kint:
		case Kuint: {
			lua_Integer res = unpackint(L, data + pos, h.islittle, size,
				(opt == Kint));
			lua_pushinteger(L, res);
			break;
		}
		case Kfloat: {
			volatile Ftypes u;
			lua_Number num;
			copywithendian(u.buff, data + pos, size, h.islittle);
			if (size == sizeof(u.f)) num = (lua_Number)u.f;
			else if (size == sizeof(u.d)) num = (lua_Number)u.d;
			else num = u.n;
			lua_pushnumber(L, num);
			break;
		}
		case Kchar: {
			lua_pushlstring(L, data + pos, size);
			break;
		}
		case Kstring: {
			size_t len = (size_t)unpackint(L, data + pos, h.islittle, size, 0);
			((void)((pos + len + size <= ld) || luaL_argerror(L, (2), ("data string too short"))));
			lua_pushlstring(L, data + pos + size, len);
			pos += len;
			break;
		}
		case Kzstr: {
			size_t len = (int)strlen(data + pos);
			lua_pushlstring(L, data + pos, len);
			pos += len + 1;
			break;
		}
		case Kpaddalign: case Kpadding: case Knop:
			n--;
			break;
		}
		pos += size;
	}
	lua_pushinteger(L, pos + 1);
	return n + 1;
}

static const luaL_Reg strlib[] = {
		{
			"byte", str_byte
		},
		{
			"char", str_char
		},
		{
			"dump", str_dump
		},
		{
			"find", str_find
		},
		{
			"format", str_format
		},
		{
			"gmatch", gmatch
		},
		{
			"gsub", str_gsub
		},
		{
			"len", str_len
		},
		{
			"lower", str_lower
		},
		{
			"match", str_match
		},
		{
			"rep", str_rep
		},
		{
			"reverse", str_reverse
		},
		{
			"sub", str_sub
		},
		{
			"upper", str_upper
		},
		{
			"pack", str_pack
		},
		{
			"packsize", str_packsize
		},
		{
			"unpack", str_unpack
		},
		{
			((void *)0), ((void *)0) }
};

static void createmetatable(lua_State *L) {
	lua_createtable(L, 0, 1);
	lua_pushstring(L, "" "");
	lua_pushvalue(L, -2);
	lua_setmetatable(L, -2);
	lua_settop(L, -(1) - 1);
	lua_pushvalue(L, -2);
	lua_setfield(L, -2, "__index");
	lua_settop(L, -(1) - 1);
}

extern int luaopen_string(lua_State *L) {
	(luaL_checkversion_(L, 503, (sizeof(lua_Integer) * 16 + sizeof(lua_Number))), lua_createtable(L, 0, sizeof(strlib) / sizeof((strlib)[0]) - 1), luaL_setfuncs(L, strlib, 0));
	createmetatable(L);
	return 1;
}

