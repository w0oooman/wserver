
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

__declspec(dllimport) extern int * __cdecl _errno(void);

errno_t __cdecl _set_errno(int _Value);
errno_t __cdecl _get_errno(int * _Value);

__declspec(dllimport) extern unsigned long  __cdecl __threadid(void);

__declspec(dllimport) extern uintptr_t __cdecl __threadhandle(void);

#pragma once

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

typedef size_t lu_mem;
typedef ptrdiff_t l_mem;

typedef unsigned char lu_byte;

typedef union {
	lua_Number n;
	double u;
	void *s;
	lua_Integer i;
	long l;
} L_Umaxalign;

typedef double l_uacNumber;
typedef long long l_uacInt;

typedef unsigned int Instruction;

extern const lu_byte luai_ctype_[0xff + 2];

typedef struct GCObject GCObject;

struct GCObject {
	GCObject *next;
	lu_byte tt;
	lu_byte marked;
};

typedef union Value {
	GCObject *gc;
	void *p;
	int b;
	lua_CFunction f;
	lua_Integer i;
	lua_Number n;
} Value;

typedef struct lua_TValue {
	Value value_;
	int tt_;
} TValue;

typedef TValue *StkId;

typedef struct TString {
	GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte extra;
	lu_byte shrlen;
	unsigned int hash;
	union {
		size_t lnglen;
		struct TString *hnext;
	} u;
} TString;

typedef union UTString {
	L_Umaxalign dummy;
	TString tsv;
} UTString;

typedef struct Udata {
	GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte ttuv_;
	struct Table *metatable;
	size_t len;
	union Value user_;
} Udata;

typedef union UUdata {
	L_Umaxalign dummy;
	Udata uv;
} UUdata;

typedef struct Upvaldesc {
	TString *name;
	lu_byte instack;
	lu_byte idx;
} Upvaldesc;

typedef struct LocVar {
	TString *varname;
	int startpc;
	int endpc;
} LocVar;

typedef struct Proto {
	GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte numparams;
	lu_byte is_vararg;
	lu_byte maxstacksize;
	int sizeupvalues;
	int sizek;
	int sizecode;
	int sizelineinfo;
	int sizep;
	int sizelocvars;
	int linedefined;
	int lastlinedefined;
	TValue *k;
	Instruction *code;
	struct Proto **p;
	int *lineinfo;
	LocVar *locvars;
	Upvaldesc *upvalues;
	struct LClosure *cache;
	TString  *source;
	GCObject *gclist;
} Proto;

typedef struct UpVal UpVal;

typedef struct CClosure {
	GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte nupvalues;
	GCObject *gclist;
	lua_CFunction f;
	TValue upvalue[1];
} CClosure;

typedef struct LClosure {
	GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte nupvalues;
	GCObject *gclist;
	struct Proto *p;
	UpVal *upvals[1];
} LClosure;

typedef union Closure {
	CClosure c;
	LClosure l;
} Closure;

typedef union TKey {
	struct {
		Value value_;
		int tt_;
		int next;
	} nk;
	TValue tvk;
} TKey;

typedef struct Node {
	TValue i_val;
	TKey i_key;
} Node;

typedef struct Table {
	GCObject *next;
	lu_byte tt;
	lu_byte marked;
	lu_byte flags;
	lu_byte lsizenode;
	unsigned int sizearray;
	TValue *array;
	Node *node;
	Node *lastfree;
	struct Table *metatable;
	GCObject *gclist;
} Table;

extern const TValue luaO_nilobject_;

extern int luaO_int2fb(unsigned int x);
extern int luaO_fb2int(int x);
extern int luaO_utf8esc(char *buff, unsigned long x);
extern int luaO_ceillog2(unsigned int x);
extern void luaO_arith(lua_State *L, int op, const TValue *p1,
	const TValue *p2, TValue *res);
extern size_t luaO_str2num(const char *s, TValue *o);
extern int luaO_hexavalue(int c);
extern void luaO_tostring(lua_State *L, StkId obj);
extern const char *luaO_pushvfstring(lua_State *L, const char *fmt,
	va_list argp);
extern const char *luaO_pushfstring(lua_State *L, const char *fmt, ...);
extern void luaO_chunkid(char *out, const char *source, size_t len);

typedef enum {
	TM_INDEX,
	TM_NEWINDEX,
	TM_GC,
	TM_MODE,
	TM_LEN,
	TM_EQ,
	TM_ADD,
	TM_SUB,
	TM_MUL,
	TM_MOD,
	TM_POW,
	TM_DIV,
	TM_IDIV,
	TM_BAND,
	TM_BOR,
	TM_BXOR,
	TM_SHL,
	TM_SHR,
	TM_UNM,
	TM_BNOT,
	TM_LT,
	TM_LE,
	TM_CONCAT,
	TM_CALL,
	TM_N
} TMS;

extern const char *const luaT_typenames_[(9 + 2)];

extern const char *luaT_objtypename(lua_State *L, const TValue *o);

extern const TValue *luaT_gettm(Table *events, TMS event, TString *ename);
extern const TValue *luaT_gettmbyobj(lua_State *L, const TValue *o,
	TMS event);
extern void luaT_init(lua_State *L);

extern void luaT_callTM(lua_State *L, const TValue *f, const TValue *p1,
	const TValue *p2, TValue *p3, int hasres);
extern int luaT_callbinTM(lua_State *L, const TValue *p1, const TValue *p2,
	StkId res, TMS event);
extern void luaT_trybinTM(lua_State *L, const TValue *p1, const TValue *p2,
	StkId res, TMS event);
extern int luaT_callorderTM(lua_State *L, const TValue *p1,
	const TValue *p2, TMS event);

extern void __declspec(noreturn) luaM_toobig(lua_State *L);

extern void *luaM_realloc_(lua_State *L, void *block, size_t oldsize,
	size_t size);
extern void *luaM_growaux_(lua_State *L, void *block, int *size,
	size_t size_elem, int limit,
	const char *what);

typedef struct Zio ZIO;

typedef struct Mbuffer {
	char *buffer;
	size_t n;
	size_t buffsize;
} Mbuffer;

extern void luaZ_init(lua_State *L, ZIO *z, lua_Reader reader,
	void *data);
extern size_t luaZ_read(ZIO* z, void *b, size_t n);

struct Zio {
	size_t n;
	const char *p;
	lua_Reader reader;
	void *data;
	lua_State *L;
};

extern int luaZ_fill(ZIO *z);

struct lua_longjmp;

#pragma once

typedef int sig_atomic_t;

extern void * * __cdecl __pxcptinfoptrs(void);

__declspec(dllimport) void(__cdecl * __cdecl signal(int _SigNum, void(__cdecl * _Func)(int)))(int);

__declspec(dllimport) int __cdecl raise(int _SigNum);

typedef struct stringtable {
	TString **hash;
	int nuse;
	int size;
} stringtable;

typedef struct CallInfo {
	StkId func;
	StkId	top;
	struct CallInfo *previous, *next;
	union {
		struct {
			StkId base;
			const Instruction *savedpc;
		} l;
		struct {
			lua_KFunction k;
			ptrdiff_t old_errfunc;
			lua_KContext ctx;
		} c;
	} u;
	ptrdiff_t extra;
	short nresults;
	lu_byte callstatus;
} CallInfo;

typedef struct global_State {
	lua_Alloc frealloc;
	void *ud;
	l_mem totalbytes;
	l_mem GCdebt;
	lu_mem GCmemtrav;
	lu_mem GCestimate;
	stringtable strt;
	TValue l_registry;
	unsigned int seed;
	lu_byte currentwhite;
	lu_byte gcstate;
	lu_byte gckind;
	lu_byte gcrunning;
	GCObject *allgc;
	GCObject **sweepgc;
	GCObject *finobj;
	GCObject *gray;
	GCObject *grayagain;
	GCObject *weak;
	GCObject *ephemeron;
	GCObject *allweak;
	GCObject *tobefnz;
	GCObject *fixedgc;
	struct lua_State *twups;
	unsigned int gcfinnum;
	int gcpause;
	int gcstepmul;
	lua_CFunction panic;
	struct lua_State *mainthread;
	const lua_Number *version;
	TString *memerrmsg;
	TString *tmname[TM_N];
	struct Table *mt[9];
	TString *strcache[53][2];
} global_State;

struct lua_State {
	GCObject *next;
	lu_byte tt;
	lu_byte marked;
	unsigned short nci;
	lu_byte status;
	StkId top;
	global_State *l_G;
	CallInfo *ci;
	const Instruction *oldpc;
	StkId stack_last;
	StkId stack;
	UpVal *openupval;
	GCObject *gclist;
	struct lua_State *twups;
	struct lua_longjmp *errorJmp;
	CallInfo base_ci;
	volatile lua_Hook hook;
	ptrdiff_t errfunc;
	int stacksize;
	int basehookcount;
	int hookcount;
	unsigned short nny;
	unsigned short nCcalls;
	sig_atomic_t hookmask;
	lu_byte allowhook;
};

union GCUnion {
	GCObject gc;
	struct TString ts;
	struct Udata u;
	union Closure cl;
	struct Table h;
	struct Proto p;
	struct lua_State th;
};

extern void luaE_setdebt(global_State *g, l_mem debt);
extern void luaE_freethread(lua_State *L, lua_State *L1);
extern CallInfo *luaE_extendCI(lua_State *L);
extern void luaE_freeCI(lua_State *L);
extern void luaE_shrinkCI(lua_State *L);

extern void __declspec(noreturn) luaG_typeerror(lua_State *L, const TValue *o,
	const char *opname);
extern void __declspec(noreturn) luaG_concaterror(lua_State *L, const TValue *p1,
	const TValue *p2);
extern void __declspec(noreturn) luaG_opinterror(lua_State *L, const TValue *p1,
	const TValue *p2,
	const char *msg);
extern void __declspec(noreturn) luaG_tointerror(lua_State *L, const TValue *p1,
	const TValue *p2);
extern void __declspec(noreturn) luaG_ordererror(lua_State *L, const TValue *p1,
	const TValue *p2);
extern void __declspec(noreturn) luaG_runerror(lua_State *L, const char *fmt, ...);
extern const char *luaG_addinfo(lua_State *L, const char *msg,
	TString *src, int line);
extern void __declspec(noreturn) luaG_errormsg(lua_State *L);
extern void luaG_traceexec(lua_State *L);

typedef void(*Pfunc) (lua_State *L, void *ud);

extern int luaD_protectedparser(lua_State *L, ZIO *z, const char *name,
	const char *mode);
extern void luaD_hook(lua_State *L, int event, int line);
extern int luaD_precall(lua_State *L, StkId func, int nresults);
extern void luaD_call(lua_State *L, StkId func, int nResults);
extern void luaD_callnoyield(lua_State *L, StkId func, int nResults);
extern int luaD_pcall(lua_State *L, Pfunc func, void *u,
	ptrdiff_t oldtop, ptrdiff_t ef);
extern int luaD_poscall(lua_State *L, CallInfo *ci, StkId firstResult,
	int nres);
extern void luaD_reallocstack(lua_State *L, int newsize);
extern void luaD_growstack(lua_State *L, int n);
extern void luaD_shrinkstack(lua_State *L);
extern void luaD_inctop(lua_State *L);

extern void __declspec(noreturn) luaD_throw(lua_State *L, int errcode);
extern int luaD_rawrunprotected(lua_State *L, Pfunc f, void *ud);

extern void luaC_fix(lua_State *L, GCObject *o);
extern void luaC_freeallobjects(lua_State *L);
extern void luaC_step(lua_State *L);
extern void luaC_runtilstate(lua_State *L, int statesmask);
extern void luaC_fullgc(lua_State *L, int isemergency);
extern GCObject *luaC_newobj(lua_State *L, int tt, size_t sz);
extern void luaC_barrier_(lua_State *L, GCObject *o, GCObject *v);
extern void luaC_barrierback_(lua_State *L, Table *o);
extern void luaC_upvalbarrier_(lua_State *L, UpVal *uv);
extern void luaC_checkfinalizer(lua_State *L, GCObject *o, Table *mt);
extern void luaC_upvdeccount(lua_State *L, UpVal *uv);

enum RESERVED {

	TK_AND = 257, TK_BREAK,
	TK_DO, TK_ELSE, TK_ELSEIF, TK_END, TK_FALSE, TK_FOR, TK_FUNCTION,
	TK_GOTO, TK_IF, TK_IN, TK_LOCAL, TK_NIL, TK_NOT, TK_OR, TK_REPEAT,
	TK_RETURN, TK_THEN, TK_TRUE, TK_UNTIL, TK_WHILE,

	TK_IDIV, TK_CONCAT, TK_DOTS, TK_EQ, TK_GE, TK_LE, TK_NE,
	TK_SHL, TK_SHR,
	TK_DBCOLON, TK_EOS,
	TK_FLT, TK_INT, TK_NAME, TK_STRING
};

typedef union {
	lua_Number r;
	lua_Integer i;
	TString *ts;
} SemInfo;

typedef struct Token {
	int token;
	SemInfo seminfo;
} Token;

typedef struct LexState {
	int current;
	int linenumber;
	int lastline;
	Token t;
	Token lookahead;
	struct FuncState *fs;
	struct lua_State *L;
	ZIO *z;
	Mbuffer *buff;
	Table *h;
	struct Dyndata *dyd;
	TString *source;
	TString *envn;
} LexState;

extern void luaX_init(lua_State *L);
extern void luaX_setinput(lua_State *L, LexState *ls, ZIO *z,
	TString *source, int firstchar);
extern TString *luaX_newstring(LexState *ls, const char *str, size_t l);
extern void luaX_next(LexState *ls);
extern int luaX_lookahead(LexState *ls);
extern void __declspec(noreturn) luaX_syntaxerror(LexState *ls, const char *s);
extern const char *luaX_token2str(LexState *ls, int token);

typedef enum {
	VVOID,

	VNIL,
	VTRUE,
	VFALSE,
	VK,
	VKFLT,
	VKINT,
	VNONRELOC,

	VLOCAL,
	VUPVAL,
	VINDEXED,

	VJMP,

	VRELOCABLE,

	VCALL,
	VVARARG
} expkind;

typedef struct expdesc {
	expkind k;
	union {
		lua_Integer ival;
		lua_Number nval;
		int info;
		struct {
			short idx;
			lu_byte t;
			lu_byte vt;
		} ind;
	} u;
	int t;
	int f;
} expdesc;

typedef struct Vardesc {
	short idx;
} Vardesc;

typedef struct Labeldesc {
	TString *name;
	int pc;
	int line;
	lu_byte nactvar;
} Labeldesc;

typedef struct Labellist {
	Labeldesc *arr;
	int n;
	int size;
} Labellist;

typedef struct Dyndata {
	struct {
		Vardesc *arr;
		int n;
		int size;
	} actvar;
	Labellist gt;
	Labellist label;
} Dyndata;

struct BlockCnt;

typedef struct FuncState {
	Proto *f;
	struct FuncState *prev;
	struct LexState *ls;
	struct BlockCnt *bl;
	int pc;
	int lasttarget;
	int jpc;
	int nk;
	int np;
	int firstlocal;
	short nlocvars;
	lu_byte nactvar;
	lu_byte nups;
	lu_byte freereg;
} FuncState;

extern LClosure *luaY_parser(lua_State *L, ZIO *z, Mbuffer *buff,
	Dyndata *dyd, const char *name, int firstchar);

extern unsigned int luaS_hash(const char *str, size_t l, unsigned int seed);
extern unsigned int luaS_hashlongstr(TString *ts);
extern int luaS_eqlngstr(TString *a, TString *b);
extern void luaS_resize(lua_State *L, int newsize);
extern void luaS_clearcache(global_State *g);
extern void luaS_init(lua_State *L);
extern void luaS_remove(lua_State *L, TString *ts);
extern Udata *luaS_newudata(lua_State *L, size_t s);
extern TString *luaS_newlstr(lua_State *L, const char *str, size_t l);
extern TString *luaS_new(lua_State *L, const char *str);
extern TString *luaS_createlngstrobj(lua_State *L, size_t l);

extern const TValue *luaH_getint(Table *t, lua_Integer key);
extern void luaH_setint(lua_State *L, Table *t, lua_Integer key,
	TValue *value);
extern const TValue *luaH_getshortstr(Table *t, TString *key);
extern const TValue *luaH_getstr(Table *t, TString *key);
extern const TValue *luaH_get(Table *t, const TValue *key);
extern TValue *luaH_newkey(lua_State *L, Table *t, const TValue *key);
extern TValue *luaH_set(lua_State *L, Table *t, const TValue *key);
extern Table *luaH_new(lua_State *L);
extern void luaH_resize(lua_State *L, Table *t, unsigned int nasize,
	unsigned int nhsize);
extern void luaH_resizearray(lua_State *L, Table *t, unsigned int nasize);
extern void luaH_free(lua_State *L, Table *t);
extern int luaH_next(lua_State *L, Table *t, StkId key);
extern int luaH_getn(Table *t);

static const char *const luaX_tokens[] = {
	"and", "break", "do", "else", "elseif",
	"end", "false", "for", "function", "goto", "if",
	"in", "local", "nil", "not", "or", "repeat",
	"return", "then", "true", "until", "while",
	"//", "..", "...", "==", ">=", "<=", "~=",
	"<<", ">>", "::", "<eof>",
	"<number>", "<integer>", "<name>", "<string>"
};

static void __declspec(noreturn) lexerror(LexState *ls, const char *msg, int token);

static void save(LexState *ls, int c) {
	Mbuffer *b = ls->buff;
	if (((b)->n) + 1 > ((b)->buffsize)) {
		size_t newsize;
		if (((b)->buffsize) >= (sizeof(size_t) < sizeof(lua_Integer) ? ((size_t)(~(size_t)0)) : (size_t)(9223372036854775807i64)) / 2)
			lexerror(ls, "lexical element too long", 0);
		newsize = ((b)->buffsize) * 2;
		((b)->buffer = ((char *)(luaM_realloc_(ls->L, ((b)->buffer), ((b)->buffsize)*sizeof(char), (newsize)*sizeof(char)))), (b)->buffsize = newsize);
	}
	b->buffer[((b)->n)++] = ((char)(c));
}

void luaX_init(lua_State *L) {
	int i;
	TString *e = (luaS_newlstr(L, "" "_ENV", (sizeof("_ENV") / sizeof(char)) - 1));
	luaC_fix(L, ((&(((union GCUnion *)((e)))->gc))));
	for (i = 0;
		i < (((int)(TK_WHILE - 257 + 1)));
		i++) {
		TString *ts = luaS_new(L, luaX_tokens[i]);
		luaC_fix(L, ((&(((union GCUnion *)((ts)))->gc))));
		ts->extra = ((lu_byte)((i + 1)));
	}
}

const char *luaX_token2str(LexState *ls, int token) {
	if (token < 257) {
		((void)0);
		return luaO_pushfstring(ls->L, "'%c'", token);
	}
	else {
		const char *s = luaX_tokens[token - 257];
		if (token < TK_EOS)
			return luaO_pushfstring(ls->L, "'%s'", s);
		else
			return s;
	}
}

static const char *txtToken(LexState *ls, int token) {
	switch (token) {
	case TK_NAME: case TK_STRING:
	case TK_FLT: case TK_INT:
		save(ls, '\0');
		return luaO_pushfstring(ls->L, "'%s'", ((ls->buff)->buffer));
	default:
		return luaX_token2str(ls, token);
	}
}

static void __declspec(noreturn) lexerror(LexState *ls, const char *msg, int token) {
	msg = luaG_addinfo(ls->L, msg, ls->source, ls->linenumber);
	if (token)
		luaO_pushfstring(ls->L, "%s near %s", msg, txtToken(ls, token));
	luaD_throw(ls->L, 3);
}

void __declspec(noreturn) luaX_syntaxerror(LexState *ls, const char *msg) {
	lexerror(ls, msg, ls->t.token);
}

TString *luaX_newstring(LexState *ls, const char *str, size_t l) {
	lua_State *L = ls->L;
	TValue *o;
	TString *ts = luaS_newlstr(L, str, l);
	{
		TValue *io = (L->top++);
		TString *x_ = (ts);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void)0);
	};
	o = luaH_set(L, ls->h, L->top - 1);
	if (((((o))->tt_) == (0))) {

			{
				TValue *io = (o);
				((io)->value_).b = (1);
				((io)->tt_ = (1));
			};
			{
				if ((L->l_G)->GCdebt > 0) {
					(void)0;
					luaC_step(L);
					(void)0;
				};
				((void)0);
			};
	}
	else {
		ts = ((&((((union GCUnion *)(((((((const TValue*)((&(((Node *)(((char *)((o))) - (size_t)&(((Node *)0)->i_val))))->i_key.tvk)))))->value_).gc))))->ts)));
	}
	L->top--;
	return ts;
}

static void inclinenumber(LexState *ls) {
	int old = ls->current;
	((void)0);
	(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
	if ((ls->current == '\n' || ls->current == '\r') && ls->current != old)
		(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
	if (++ls->linenumber >= 2147483647)
		lexerror(ls, "chunk has too many lines", 0);
}

void luaX_setinput(lua_State *L, LexState *ls, ZIO *z, TString *source,
	int firstchar) {
	ls->t.token = 0;
	ls->L = L;
	ls->current = firstchar;
	ls->lookahead.token = TK_EOS;
	ls->z = z;
	ls->fs = ((void *)0);
	ls->linenumber = 1;
	ls->lastline = 1;
	ls->source = source;
	ls->envn = (luaS_newlstr(L, "" "_ENV", (sizeof("_ENV") / sizeof(char)) - 1));
	((ls->buff)->buffer = ((char *)(luaM_realloc_(ls->L, ((ls->buff)->buffer), ((ls->buff)->buffsize)*sizeof(char), (32)*sizeof(char)))), (ls->buff)->buffsize = 32);
}

static int check_next1(LexState *ls, int c) {
	if (ls->current == c) {
		(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
		return 1;
	}
	else return 0;
}

static int check_next2(LexState *ls, const char *set) {
	((void)0);
	if (ls->current == set[0] || ls->current == set[1]) {
		(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		return 1;
	}
	else return 0;
}

static int read_numeral(LexState *ls, SemInfo *seminfo) {
	TValue obj;
	const char *expo = "Ee";
	int first = ls->current;
	((void)0);
	(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	if (first == '0' && check_next2(ls, "xX"))
		expo = "Pp";
	for (;
		;
		) {
		if (check_next2(ls, expo))
			check_next2(ls, "-+");
		if ((luai_ctype_[(ls->current) + 1] & ((1 << (4)))))
			(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		else if (ls->current == '.')
			(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		else break;
	}
	save(ls, '\0');
	if (luaO_str2num(((ls->buff)->buffer), &obj) == 0)
		lexerror(ls, "malformed number", TK_FLT);
	if (((((&obj))->tt_) == ((3 | (1 << 4))))) {
		seminfo->i = (((&obj)->value_).i);
		return TK_INT;
	}
	else {
		((void)0);
		seminfo->r = (((&obj)->value_).n);
		return TK_FLT;
	}
}

static int skip_sep(LexState *ls) {
	int count = 0;
	int s = ls->current;
	((void)0);
	(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	while (ls->current == '=') {
		(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		count++;
	}
	return (ls->current == s) ? count : (-count) - 1;
}

static void read_long_string(LexState *ls, SemInfo *seminfo, int sep) {
	int line = ls->linenumber;
	(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	if ((ls->current == '\n' || ls->current == '\r'))
		inclinenumber(ls);
	for (;
		;
		) {
		switch (ls->current) {
		case (-1) : {
			const char *what = (seminfo ? "string" : "comment");
			const char *msg = luaO_pushfstring(ls->L,
				"unfinished long %s (starting at line %d)", what, line);
			lexerror(ls, msg, TK_EOS);
			break;
		}
		case ']': {
			if (skip_sep(ls) == sep) {
				(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
				goto endloop;
			}
			break;
		}
		case '\n': case '\r': {
			save(ls, '\n');
			inclinenumber(ls);
			if (!seminfo) ((ls->buff)->n = 0);
			break;
		}
		default: {
			if (seminfo) (save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
			else (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
		}
		}
	} endloop:
	if (seminfo)
		seminfo->ts = luaX_newstring(ls, ((ls->buff)->buffer) + (2 + sep),
		((ls->buff)->n) - 2 * (2 + sep));
}

static void esccheck(LexState *ls, int c, const char *msg) {
	if (!c) {
		if (ls->current != (-1))
			(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		lexerror(ls, msg, TK_STRING);
	}
}

static int gethexa(LexState *ls) {
	(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	esccheck(ls, (luai_ctype_[(ls->current) + 1] & ((1 << (4)))), "hexadecimal digit expected");
	return luaO_hexavalue(ls->current);
}

static int readhexaesc(LexState *ls) {
	int r = gethexa(ls);
	r = (r << 4) + gethexa(ls);
	((ls->buff)->n -= (2));
	return r;
}

static unsigned long readutf8esc(LexState *ls) {
	unsigned long r;
	int i = 4;
	(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	esccheck(ls, ls->current == '{', "missing '{'");
	r = gethexa(ls);
	while (((save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)))), (luai_ctype_[(ls->current) + 1] & ((1 << (4)))))) {
		i++;
		r = (r << 4) + luaO_hexavalue(ls->current);
		esccheck(ls, r <= 0x10FFFF, "UTF-8 value too large");
	}
	esccheck(ls, ls->current == '}', "missing '}'");
	(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
	((ls->buff)->n -= (i));
	return r;
}

static void utf8esc(LexState *ls) {
	char buff[8];
	int n = luaO_utf8esc(buff, readutf8esc(ls));
	for (;
		n > 0;
		n--)
		save(ls, buff[8 - n]);
}

static int readdecesc(LexState *ls) {
	int i;
	int r = 0;
	for (i = 0;
		i < 3 && (luai_ctype_[(ls->current) + 1] & ((1 << (1))));
		i++) {
		r = 10 * r + ls->current - '0';
		(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	}
	esccheck(ls, r <= 0xff, "decimal escape too large");
	((ls->buff)->n -= (i));
	return r;
}

static void read_string(LexState *ls, int del, SemInfo *seminfo) {
	(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	while (ls->current != del) {
		switch (ls->current) {
		case (-1) :
			lexerror(ls, "unfinished string", TK_EOS);
			break;
		case '\n':
		case '\r':
			lexerror(ls, "unfinished string", TK_STRING);
			break;
		case '\\': {
			int c;
			(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
			switch (ls->current) {
			case 'a': c = '\a';
				goto read_save;
			case 'b': c = '\b';
				goto read_save;
			case 'f': c = '\f';
				goto read_save;
			case 'n': c = '\n';
				goto read_save;
			case 'r': c = '\r';
				goto read_save;
			case 't': c = '\t';
				goto read_save;
			case 'v': c = '\v';
				goto read_save;
			case 'x': c = readhexaesc(ls);
				goto read_save;
			case 'u': utf8esc(ls);
				goto no_save;
			case '\n': case '\r':
				inclinenumber(ls);
				c = '\n';
				goto only_save;
			case '\\': case '\"': case '\'':
				c = ls->current;
				goto read_save;
			case (-1) : goto no_save;
			case 'z': {
				((ls->buff)->n -= (1));
				(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
				while ((luai_ctype_[(ls->current) + 1] & ((1 << (3))))) {
					if ((ls->current == '\n' || ls->current == '\r')) inclinenumber(ls);
					else (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
				}
				goto no_save;
			}
			default: {
				esccheck(ls, (luai_ctype_[(ls->current) + 1] & ((1 << (1)))), "invalid escape sequence");
				c = readdecesc(ls);
				goto only_save;
			}
			}
		read_save:
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));

		only_save:
			((ls->buff)->n -= (1));
			save(ls, c);

		no_save: break;
		}
		default:
			(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
		}
	}
	(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
	seminfo->ts = luaX_newstring(ls, ((ls->buff)->buffer) + 1,
		((ls->buff)->n) - 2);
}

static int llex(LexState *ls, SemInfo *seminfo) {
	((ls->buff)->n = 0);
	for (;
		;
		) {
		switch (ls->current) {
		case '\n': case '\r': {
			inclinenumber(ls);
			break;
		}
		case ' ': case '\f': case '\t': case '\v': {
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			break;
		}
		case '-': {
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (ls->current != '-') return '-';

			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (ls->current == '[') {
				int sep = skip_sep(ls);
				((ls->buff)->n = 0);
				if (sep >= 0) {
					read_long_string(ls, ((void *)0), sep);
					((ls->buff)->n = 0);
					break;
				}
			}

			while (!(ls->current == '\n' || ls->current == '\r') && ls->current != (-1))
				(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			break;
		}
		case '[': {
			int sep = skip_sep(ls);
			if (sep >= 0) {
				read_long_string(ls, seminfo, sep);
				return TK_STRING;
			}
			else if (sep != -1)
				lexerror(ls, "invalid long string delimiter", TK_STRING);
			return '[';
		}
		case '=': {
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '=')) return TK_EQ;
			else return '=';
		}
		case '<': {
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '=')) return TK_LE;
			else if (check_next1(ls, '<')) return TK_SHL;
			else return '<';
		}
		case '>': {
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '=')) return TK_GE;
			else if (check_next1(ls, '>')) return TK_SHR;
			else return '>';
		}
		case '/': {
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '/')) return TK_IDIV;
			else return '/';
		}
		case '~': {
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, '=')) return TK_NE;
			else return '~';
		}
		case ':': {
			(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
			if (check_next1(ls, ':')) return TK_DBCOLON;
			else return ':';
		}
		case '"': case '\'': {
			read_string(ls, ls->current, seminfo);
			return TK_STRING;
		}
		case '.': {
			(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
			if (check_next1(ls, '.')) {
				if (check_next1(ls, '.'))
					return TK_DOTS;
				else return TK_CONCAT;
			}
			else if (!(luai_ctype_[(ls->current) + 1] & ((1 << (1))))) return '.';
			else return read_numeral(ls, seminfo);
		}
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9': {
			return read_numeral(ls, seminfo);
		}
		case (-1) : {
			return TK_EOS;
		}
		default: {
			if ((luai_ctype_[(ls->current) + 1] & ((1 << (0))))) {
				TString *ts;
				do {
					(save(ls, ls->current), (ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z))));
				} while ((luai_ctype_[(ls->current) + 1] & (((1 << (0)) | (1 << (1))))));
				ts = luaX_newstring(ls, ((ls->buff)->buffer),
					((ls->buff)->n));
				seminfo->ts = ts;
				if (((ts)->tt == (4 | (0 << 4)) && (ts)->extra > 0))
					return ts->extra - 1 + 257;
				else {
					return TK_NAME;
				}
			}
			else {
				int c = ls->current;
				(ls->current = (((ls->z)->n--) > 0 ? ((unsigned char)((*(ls->z)->p++))) : luaZ_fill(ls->z)));
				return c;
			}
		}
		}
	}
}

void luaX_next(LexState *ls) {
	ls->lastline = ls->linenumber;
	if (ls->lookahead.token != TK_EOS) {
		ls->t = ls->lookahead;
		ls->lookahead.token = TK_EOS;
	}
	else
		ls->t.token = llex(ls, &ls->t.seminfo);
}

int luaX_lookahead(LexState *ls) {
	((void)0);
	ls->lookahead.token = llex(ls, &ls->lookahead.seminfo);
	return ls->lookahead.token;
}

