
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

void __declspec(dllimport) __cdecl _vacopy(va_list *, va_list);

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

struct UpVal {
	TValue *v;
	lu_mem refcount;
	union {
		struct {
			UpVal *next;
			int touched;
		} open;
		TValue value;
	} u;
};

extern Proto *luaF_newproto(lua_State *L);
extern CClosure *luaF_newCclosure(lua_State *L, int nelems);
extern LClosure *luaF_newLclosure(lua_State *L, int nelems);
extern void luaF_initupvals(lua_State *L, LClosure *cl);
extern UpVal *luaF_findupval(lua_State *L, StkId level);
extern void luaF_close(lua_State *L, StkId level);
extern void luaF_freeproto(lua_State *L, Proto *f);
extern const char *luaF_getlocalname(const Proto *func, int local_number,
	int pc);

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

extern LClosure* luaU_undump(lua_State* L, ZIO* Z, const char* name);

extern int luaU_dump(lua_State* L, const Proto* f, lua_Writer w,
	void* data, int strip);

extern int luaV_equalobj(lua_State *L, const TValue *t1, const TValue *t2);
extern int luaV_lessthan(lua_State *L, const TValue *l, const TValue *r);
extern int luaV_lessequal(lua_State *L, const TValue *l, const TValue *r);
extern int luaV_tonumber_(const TValue *obj, lua_Number *n);
extern int luaV_tointeger(const TValue *obj, lua_Integer *p, int mode);
extern void luaV_finishget(lua_State *L, const TValue *t, TValue *key,
	StkId val, const TValue *slot);
extern void luaV_finishset(lua_State *L, const TValue *t, TValue *key,
	StkId val, const TValue *slot);
extern void luaV_finishOp(lua_State *L);
extern void luaV_execute(lua_State *L);
extern void luaV_concat(lua_State *L, int total);
extern lua_Integer luaV_div(lua_State *L, lua_Integer x, lua_Integer y);
extern lua_Integer luaV_mod(lua_State *L, lua_Integer x, lua_Integer y);
extern lua_Integer luaV_shiftl(lua_Integer x, lua_Integer y);
extern void luaV_objlen(lua_State *L, StkId ra, const TValue *rb);

const char lua_ident[] =
"$LuaVersion: " "Lua " "5" "." "3" "." "3" "  Copyright (C) 1994-2016 Lua.org, PUC-Rio" " $"
"$LuaAuthors: " "R. Ierusalimschy, L. H. de Figueiredo, W. Celes" " $";

static TValue *index2addr(lua_State *L, int idx) {
	CallInfo *ci = L->ci;
	if (idx > 0) {
		TValue *o = ci->func + idx;
		((void)0);
		if (o >= L->top) return ((TValue *)((&luaO_nilobject_)));
		else return o;
	}
	else if (!((idx) <= (-1000000 - 1000))) {
		((void)0);
		return L->top + idx;
	}
	else if (idx == (-1000000 - 1000))
		return &(L->l_G)->l_registry;
	else {
		idx = (-1000000 - 1000) - idx;
		((void)0);
		if (((((ci->func))->tt_) == ((6 | (1 << 4)))))
			return ((TValue *)((&luaO_nilobject_)));
		else {
			CClosure *func = ((&((((union GCUnion *)((((ci->func)->value_).gc))))->cl.c)));
			return (idx <= func->nupvalues) ? &func->upvalue[idx - 1] : ((TValue *)((&luaO_nilobject_)));
		}
	}
}

static void growstack(lua_State *L, void *ud) {
	int size = *(int *)ud;
	luaD_growstack(L, size);
}

extern int lua_checkstack(lua_State *L, int n) {
	int res;
	CallInfo *ci = L->ci;
	((void)0);
	((void)0);
	if (L->stack_last - L->top > n)
		res = 1;
	else {
		int inuse = ((int)((L->top - L->stack))) + 5;
		if (inuse > 1000000 - n)
			res = 0;
		else
			res = (luaD_rawrunprotected(L, &growstack, &n) == 0);
	}
	if (res && ci->top < L->top + n)
		ci->top = L->top + n;
	((void)0);
	return res;
}

extern void lua_xmove(lua_State *from, lua_State *to, int n) {
	int i;
	if (from == to) return;
	((void)0);
	((void)0);
	((void)0);
	((void)0);
	from->top -= n;
	for (i = 0;
		i < n;
		i++) {
				{
					TValue *io1 = (to->top);
					*io1 = *(from->top + i);
					(void)to;
					((void)0);
				};
		to->top++;
	}
	((void)0);
}

extern lua_CFunction lua_atpanic(lua_State *L, lua_CFunction panicf) {
	lua_CFunction old;
	((void)0);
	old = (L->l_G)->panic;
	(L->l_G)->panic = panicf;
	((void)0);
	return old;
}

extern const lua_Number *lua_version(lua_State *L) {
	static const lua_Number version = 503;
	if (L == ((void *)0)) return &version;
	else return (L->l_G)->version;
}

extern int lua_absindex(lua_State *L, int idx) {
	return (idx > 0 || ((idx) <= (-1000000 - 1000)))
		? idx
		: ((int)((L->top - L->ci->func))) + idx;
}

extern int lua_gettop(lua_State *L) {
	return ((int)((L->top - (L->ci->func + 1))));
}

extern void lua_settop(lua_State *L, int idx) {
	StkId func = L->ci->func;
	((void)0);
	if (idx >= 0) {
		((void)0);
		while (L->top < (func + 1) + idx)
			((L->top++)->tt_ = (0));
		L->top = (func + 1) + idx;
	}
	else {
		((void)0);
		L->top += idx + 1;
	}
	((void)0);
}

static void reverse(lua_State *L, StkId from, StkId to) {
	for (;
		from < to;
		from++, to--) {
		TValue temp;
		{
			TValue *io1 = (&temp);
			*io1 = *(from);
			(void)L;
			((void)0);
		};
		{
			TValue *io1 = (from);
			*io1 = *(to);
			(void)L;
			((void)0);
		};
		{
			TValue *io1 = (to);
			*io1 = *(&temp);
			(void)L;
			((void)0);
		};
	}
}

extern void lua_rotate(lua_State *L, int idx, int n) {
	StkId p, t, m;
	((void)0);
	t = L->top - 1;
	p = index2addr(L, idx);
	((void)0);
	((void)0);
	m = (n >= 0 ? t - n : p - n - 1);
	reverse(L, p, m);
	reverse(L, m + 1, t);
	reverse(L, p, t);
	((void)0);
}

extern void lua_copy(lua_State *L, int fromidx, int toidx) {
	TValue *fr, *to;
	((void)0);
	fr = index2addr(L, fromidx);
	to = index2addr(L, toidx);
	((void)0);
	{
		TValue *io1 = (to);
		*io1 = *(fr);
		(void)L;
		((void)0);
	};
	if (((toidx) < (-1000000 - 1000)))
		(((((fr)->tt_) & (1 << 6)) && (((((&((((union GCUnion *)((((L->ci->func)->value_).gc))))->cl.c))))->marked) & ((1 << (2)))) && ((((((fr)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(L, ((&(((union GCUnion *)((((&((((union GCUnion *)((((L->ci->func)->value_).gc))))->cl.c))))))->gc))), (((fr)->value_).gc)) : ((void)((0))));

	((void)0);
}

extern void lua_pushvalue(lua_State *L, int idx) {
	((void)0);
	{
		TValue *io1 = (L->top);
		*io1 = *(index2addr(L, idx));
		(void)L;
		((void)0);
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
}

extern int lua_type(lua_State *L, int idx) {
	StkId o = index2addr(L, idx);
	return (((o) != (&luaO_nilobject_)) ? (((((o)->tt_)) & 0x0F)) : (-1));
}

extern const char *lua_typename(lua_State *L, int t) {
	((void)(L));
	((void)0);
	return luaT_typenames_[(t)+1];
}

extern int lua_iscfunction(lua_State *L, int idx) {
	StkId o = index2addr(L, idx);
	return (((((o))->tt_) == ((6 | (1 << 4)))) || (((((o))->tt_) == ((((6 | (2 << 4))) | (1 << 6))))));
}

extern int lua_isinteger(lua_State *L, int idx) {
	StkId o = index2addr(L, idx);
	return ((((o))->tt_) == ((3 | (1 << 4))));
}

extern int lua_isnumber(lua_State *L, int idx) {
	lua_Number n;
	const TValue *o = index2addr(L, idx);
	return (((((o))->tt_) == ((3 | (0 << 4)))) ? (*(&n) = (((o)->value_).n), 1) : luaV_tonumber_(o, &n));
}

extern int lua_isstring(lua_State *L, int idx) {
	const TValue *o = index2addr(L, idx);
	return ((((((((o))->tt_)) & 0x0F)) == (4)) || (((((((o))->tt_)) & 0x0F)) == (3)));
}

extern int lua_isuserdata(lua_State *L, int idx) {
	const TValue *o = index2addr(L, idx);
	return (((((o))->tt_) == (((7) | (1 << 6)))) || ((((o))->tt_) == (2)));
}

extern int lua_rawequal(lua_State *L, int index1, int index2) {
	StkId o1 = index2addr(L, index1);
	StkId o2 = index2addr(L, index2);
	return (((o1) != (&luaO_nilobject_)) && ((o2) != (&luaO_nilobject_))) ? luaV_equalobj(((void *)0), o1, o2) : 0;
}

extern void lua_arith(lua_State *L, int op) {
	((void)0);
	if (op != 12 && op != 13)
		((void)0);
	else {
		((void)0);
		{
			TValue *io1 = (L->top);
			*io1 = *(L->top - 1);
			(void)L;
			((void)0);
		};
		{
			L->top++;
			((void)0);
		};
	}

	luaO_arith(L, op, L->top - 2, L->top - 1, L->top - 2);
	L->top--;
	((void)0);
}

extern int lua_compare(lua_State *L, int index1, int index2, int op) {
	StkId o1, o2;
	int i = 0;
	((void)0);
	o1 = index2addr(L, index1);
	o2 = index2addr(L, index2);
	if (((o1) != (&luaO_nilobject_)) && ((o2) != (&luaO_nilobject_))) {
		switch (op) {
		case 0: i = luaV_equalobj(L, o1, o2);
			break;
		case 1: i = luaV_lessthan(L, o1, o2);
			break;
		case 2: i = luaV_lessequal(L, o1, o2);
			break;
		default: ((void)0);
		}
	}
	((void)0);
	return i;
}

extern size_t lua_stringtonumber(lua_State *L, const char *s) {
	size_t sz = luaO_str2num(s, L->top);
	if (sz != 0)
	{
		L->top++;
		((void)0);
	};
	return sz;
}

extern lua_Number lua_tonumberx(lua_State *L, int idx, int *pisnum) {
	lua_Number n;
	const TValue *o = index2addr(L, idx);
	int isnum = (((((o))->tt_) == ((3 | (0 << 4)))) ? (*(&n) = (((o)->value_).n), 1) : luaV_tonumber_(o, &n));
	if (!isnum)
		n = 0;
	if (pisnum) *pisnum = isnum;
	return n;
}

extern lua_Integer lua_tointegerx(lua_State *L, int idx, int *pisnum) {
	lua_Integer res;
	const TValue *o = index2addr(L, idx);
	int isnum = (((((o))->tt_) == ((3 | (1 << 4)))) ? (*(&res) = (((o)->value_).i), 1) : luaV_tointeger(o, &res, 0));
	if (!isnum)
		res = 0;
	if (pisnum) *pisnum = isnum;
	return res;
}

extern int lua_toboolean(lua_State *L, int idx) {
	const TValue *o = index2addr(L, idx);
	return !(((((o))->tt_) == (0)) || (((((o))->tt_) == (1)) && (((o)->value_).b) == 0));
}

extern const char *lua_tolstring(lua_State *L, int idx, size_t *len) {
	StkId o = index2addr(L, idx);
	if (!(((((((o))->tt_)) & 0x0F)) == (4))) {
		if (!(((((((o))->tt_)) & 0x0F)) == (3))) {
			if (len != ((void *)0)) *len = 0;
			return ((void *)0);
		}
		((void)0);
		luaO_tostring(L, o);
		{
			if ((L->l_G)->GCdebt > 0) {
				(void)0;
				luaC_step(L);
				(void)0;
			};
			((void)0);
		};
		o = index2addr(L, idx);
		((void)0);
	}
	if (len != ((void *)0))
		*len = ((((&((((union GCUnion *)((((o)->value_).gc))))->ts))))->tt == (4 | (0 << 4)) ? (((&((((union GCUnion *)((((o)->value_).gc))))->ts))))->shrlen : (((&((((union GCUnion *)((((o)->value_).gc))))->ts))))->u.lnglen);
	return (((char *)((((&((((union GCUnion *)((((o)->value_).gc))))->ts)))))) + sizeof(UTString));
}

extern size_t lua_rawlen(lua_State *L, int idx) {
	StkId o = index2addr(L, idx);
	switch ((((o)->tt_) & 0x3F)) {
	case (4 | (0 << 4)) : return ((&((((union GCUnion *)((((o)->value_).gc))))->ts)))->shrlen;
	case (4 | (1 << 4)) : return ((&((((union GCUnion *)((((o)->value_).gc))))->ts)))->u.lnglen;
	case 7: return ((&((((union GCUnion *)((((o)->value_).gc))))->u)))->len;
	case 5: return luaH_getn(((&((((union GCUnion *)((((o)->value_).gc))))->h))));
	default: return 0;
	}
}

extern lua_CFunction lua_tocfunction(lua_State *L, int idx) {
	StkId o = index2addr(L, idx);
	if (((((o))->tt_) == ((6 | (1 << 4))))) return (((o)->value_).f);
	else if (((((o))->tt_) == ((((6 | (2 << 4))) | (1 << 6)))))
		return ((&((((union GCUnion *)((((o)->value_).gc))))->cl.c)))->f;
	else return ((void *)0);
}

extern void *lua_touserdata(lua_State *L, int idx) {
	StkId o = index2addr(L, idx);
	switch ((((((o)->tt_)) & 0x0F))) {
	case 7: return ((((char*)((((&((((union GCUnion *)((((o)->value_).gc))))->u)))))) + sizeof(UUdata)));
	case 2: return (((o)->value_).p);
	default: return ((void *)0);
	}
}

extern lua_State *lua_tothread(lua_State *L, int idx) {
	StkId o = index2addr(L, idx);
	return (!((((o))->tt_) == (((8) | (1 << 6))))) ? ((void *)0) : ((&((((union GCUnion *)((((o)->value_).gc))))->th)));
}

extern const void *lua_topointer(lua_State *L, int idx) {
	StkId o = index2addr(L, idx);
	switch ((((o)->tt_) & 0x3F)) {
	case 5: return ((&((((union GCUnion *)((((o)->value_).gc))))->h)));
	case (6 | (0 << 4)) : return ((&((((union GCUnion *)((((o)->value_).gc))))->cl.l)));
	case (6 | (2 << 4)) : return ((&((((union GCUnion *)((((o)->value_).gc))))->cl.c)));
	case (6 | (1 << 4)) : return ((void *)(((size_t)((((o)->value_).f)))));
	case 8: return ((&((((union GCUnion *)((((o)->value_).gc))))->th)));
	case 7: return ((((char*)((((&((((union GCUnion *)((((o)->value_).gc))))->u)))))) + sizeof(UUdata)));
	case 2: return (((o)->value_).p);
	default: return ((void *)0);
	}
}

extern void lua_pushnil(lua_State *L) {
	((void)0);
	((L->top)->tt_ = (0));
	{
		L->top++;
		((void)0);
	};
	((void)0);
}

extern void lua_pushnumber(lua_State *L, lua_Number n) {
	((void)0);
	{
		TValue *io = (L->top);
		((io)->value_).n = (n);
		((io)->tt_ = ((3 | (0 << 4))));
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
}

extern void lua_pushinteger(lua_State *L, lua_Integer n) {
	((void)0);
	{
		TValue *io = (L->top);
		((io)->value_).i = (n);
		((io)->tt_ = ((3 | (1 << 4))));
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
}

extern const char *lua_pushlstring(lua_State *L, const char *s, size_t len) {
	TString *ts;
	((void)0);
	ts = (len == 0) ? luaS_new(L, "") : luaS_newlstr(L, s, len);
	{
		TValue *io = (L->top);
		TString *x_ = (ts);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void)0);
	};
	{
		L->top++;
		((void)0);
	};
	{
		if ((L->l_G)->GCdebt > 0) {
			(void)0;
			luaC_step(L);
			(void)0;
		};
		((void)0);
	};
	((void)0);
	return (((char *)((ts))) + sizeof(UTString));
}

extern const char *lua_pushstring(lua_State *L, const char *s) {
	((void)0);
	if (s == ((void *)0))
		((L->top)->tt_ = (0));
	else {
		TString *ts;
		ts = luaS_new(L, s);
		{
			TValue *io = (L->top);
			TString *x_ = (ts);
			((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void)0);
		};
		s = (((char *)((ts))) + sizeof(UTString));
	}
  {
	  L->top++;
	  ((void)0);
  };
  {
	  if ((L->l_G)->GCdebt > 0) {
		  (void)0;
		  luaC_step(L);
		  (void)0;
	  };
	  ((void)0);
  };
	((void)0);
	return s;
}

extern const char *lua_pushvfstring(lua_State *L, const char *fmt,
	va_list argp) {
	const char *ret;
	((void)0);
	ret = luaO_pushvfstring(L, fmt, argp);
	{
		if ((L->l_G)->GCdebt > 0) {
			(void)0;
			luaC_step(L);
			(void)0;
		};
		((void)0);
	};
	((void)0);
	return ret;
}

extern const char *lua_pushfstring(lua_State *L, const char *fmt, ...) {
	const char *ret;
	va_list argp;
	((void)0);
	(argp = (va_list)(&(fmt)) + ((sizeof(fmt) + sizeof(int) - 1) & ~(sizeof(int) - 1)));
	ret = luaO_pushvfstring(L, fmt, argp);
	(argp = (va_list)0);
	{
		if ((L->l_G)->GCdebt > 0) {
			(void)0;
			luaC_step(L);
			(void)0;
		};
		((void)0);
	};
	((void)0);
	return ret;
}

extern void lua_pushcclosure(lua_State *L, lua_CFunction fn, int n) {
	((void)0);
	if (n == 0) {
			{
				TValue *io = (L->top);
				((io)->value_).f = (fn);
				((io)->tt_ = ((6 | (1 << 4))));
			};
	}
	else {
		CClosure *cl;
		((void)0);
		((void)0);
		cl = luaF_newCclosure(L, n);
		cl->f = fn;
		L->top -= n;
		while (n--) {
				{
					TValue *io1 = (&cl->upvalue[n]);
					*io1 = *(L->top + n);
					(void)L;
					((void)0);
				};

		}
	{
		TValue *io = (L->top);
		CClosure *x_ = (cl);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = ((((6 | (2 << 4))) | (1 << 6))));
		((void)0);
	};
	}
  {
	  L->top++;
	  ((void)0);
  };
  {
	  if ((L->l_G)->GCdebt > 0) {
		  (void)0;
		  luaC_step(L);
		  (void)0;
	  };
	  ((void)0);
  };
	((void)0);
}

extern void lua_pushboolean(lua_State *L, int b) {
	((void)0);
	{
		TValue *io = (L->top);
		((io)->value_).b = ((b != 0));
		((io)->tt_ = (1));
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
}

extern void lua_pushlightuserdata(lua_State *L, void *p) {
	((void)0);
	{
		TValue *io = (L->top);
		((io)->value_).p = (p);
		((io)->tt_ = (2));
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
}

extern int lua_pushthread(lua_State *L) {
	((void)0);
	{
		TValue *io = (L->top);
		lua_State *x_ = (L);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = (((8) | (1 << 6))));
		((void)0);
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
	return ((L->l_G)->mainthread == L);
}

static int auxgetstr(lua_State *L, const TValue *t, const char *k) {
	const TValue *slot;
	TString *str = luaS_new(L, k);
	if ((!((((t))->tt_) == (((5) | (1 << 6)))) ? (slot = ((void *)0), 0) : (slot = luaH_getstr(((&((((union GCUnion *)((((t)->value_).gc))))->h))), str), !((((slot))->tt_) == (0))))) {
			{
				TValue *io1 = (L->top);
				*io1 = *(slot);
				(void)L;
				((void)0);
			};
			{
				L->top++;
				((void)0);
			};
	}
	else {
			{
				TValue *io = (L->top);
				TString *x_ = (str);
				((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
				((io)->tt_ = (((x_->tt) | (1 << 6))));
				((void)0);
			};
			{
				L->top++;
				((void)0);
			};
		luaV_finishget(L, t, L->top - 1, L->top - 1, slot);
	}
	((void)0);
	return (((((L->top - 1)->tt_)) & 0x0F));
}

extern int lua_getglobal(lua_State *L, const char *name) {
	Table *reg = ((&((((union GCUnion *)((((&(L->l_G)->l_registry)->value_).gc))))->h)));
	((void)0);
	return auxgetstr(L, luaH_getint(reg, 2), name);
}

extern int lua_gettable(lua_State *L, int idx) {
	StkId t;
	((void)0);
	t = index2addr(L, idx);
	{
		const TValue *slot;
		if ((!((((t))->tt_) == (((5) | (1 << 6)))) ? (slot = ((void *)0), 0) : (slot = luaH_get(((&((((union GCUnion *)((((t)->value_).gc))))->h))), L->top - 1), !((((slot))->tt_) == (0))))) {
				{
					TValue *io1 = (L->top - 1);
					*io1 = *(slot);
					(void)L;
					((void)0);
				};
		}
		else luaV_finishget(L, t, L->top - 1, L->top - 1, slot);
	};
	((void)0);
	return (((((L->top - 1)->tt_)) & 0x0F));
}

extern int lua_getfield(lua_State *L, int idx, const char *k) {
	((void)0);
	return auxgetstr(L, index2addr(L, idx), k);
}

extern int lua_geti(lua_State *L, int idx, lua_Integer n) {
	StkId t;
	const TValue *slot;
	((void)0);
	t = index2addr(L, idx);
	if ((!((((t))->tt_) == (((5) | (1 << 6)))) ? (slot = ((void *)0), 0) : (slot = luaH_getint(((&((((union GCUnion *)((((t)->value_).gc))))->h))), n), !((((slot))->tt_) == (0))))) {
			{
				TValue *io1 = (L->top);
				*io1 = *(slot);
				(void)L;
				((void)0);
			};
			{
				L->top++;
				((void)0);
			};
	}
	else {
			{
				TValue *io = (L->top);
				((io)->value_).i = (n);
				((io)->tt_ = ((3 | (1 << 4))));
			};
			{
				L->top++;
				((void)0);
			};
		luaV_finishget(L, t, L->top - 1, L->top - 1, slot);
	}
	((void)0);
	return (((((L->top - 1)->tt_)) & 0x0F));
}

extern int lua_rawget(lua_State *L, int idx) {
	StkId t;
	((void)0);
	t = index2addr(L, idx);
	((void)0);
	{
		TValue *io1 = (L->top - 1);
		*io1 = *(luaH_get(((&((((union GCUnion *)((((t)->value_).gc))))->h))), L->top - 1));
		(void)L;
		((void)0);
	};
	((void)0);
	return (((((L->top - 1)->tt_)) & 0x0F));
}

extern int lua_rawgeti(lua_State *L, int idx, lua_Integer n) {
	StkId t;
	((void)0);
	t = index2addr(L, idx);
	((void)0);
	{
		TValue *io1 = (L->top);
		*io1 = *(luaH_getint(((&((((union GCUnion *)((((t)->value_).gc))))->h))), n));
		(void)L;
		((void)0);
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
	return (((((L->top - 1)->tt_)) & 0x0F));
}

extern int lua_rawgetp(lua_State *L, int idx, const void *p) {
	StkId t;
	TValue k;
	((void)0);
	t = index2addr(L, idx);
	((void)0);
	{
		TValue *io = (&k);
		((io)->value_).p = (((void *)(p)));
		((io)->tt_ = (2));
	};
	{
		TValue *io1 = (L->top);
		*io1 = *(luaH_get(((&((((union GCUnion *)((((t)->value_).gc))))->h))), &k));
		(void)L;
		((void)0);
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
	return (((((L->top - 1)->tt_)) & 0x0F));
}

extern void lua_createtable(lua_State *L, int narray, int nrec) {
	Table *t;
	((void)0);
	t = luaH_new(L);
	{
		TValue *io = (L->top);
		Table *x_ = (t);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = (((5) | (1 << 6))));
		((void)0);
	};
	{
		L->top++;
		((void)0);
	};
	if (narray > 0 || nrec > 0)
		luaH_resize(L, t, narray, nrec);
	{
		if ((L->l_G)->GCdebt > 0) {
			(void)0;
			luaC_step(L);
			(void)0;
		};
		((void)0);
	};
	((void)0);
}

extern int lua_getmetatable(lua_State *L, int objindex) {
	const TValue *obj;
	Table *mt;
	int res = 0;
	((void)0);
	obj = index2addr(L, objindex);
	switch ((((((obj)->tt_)) & 0x0F))) {
	case 5:
		mt = ((&((((union GCUnion *)((((obj)->value_).gc))))->h)))->metatable;
		break;
	case 7:
		mt = ((&((((union GCUnion *)((((obj)->value_).gc))))->u)))->metatable;
		break;
	default:
		mt = (L->l_G)->mt[(((((obj)->tt_)) & 0x0F))];
		break;
	}
	if (mt != ((void *)0)) {
			{
				TValue *io = (L->top);
				Table *x_ = (mt);
				((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
				((io)->tt_ = (((5) | (1 << 6))));
				((void)0);
			};
			{
				L->top++;
				((void)0);
			};
		res = 1;
	}
	((void)0);
	return res;
}

extern int lua_getuservalue(lua_State *L, int idx) {
	StkId o;
	((void)0);
	o = index2addr(L, idx);
	((void)0);
	{
		TValue *io = (L->top);
		const Udata *iu = (((&((((union GCUnion *)((((o)->value_).gc))))->u))));
		io->value_ = iu->user_;
		((io)->tt_ = (iu->ttuv_));
		((void)0);
	};
	{
		L->top++;
		((void)0);
	};
	((void)0);
	return (((((L->top - 1)->tt_)) & 0x0F));
}

static void auxsetstr(lua_State *L, const TValue *t, const char *k) {
	const TValue *slot;
	TString *str = luaS_new(L, k);
	((void)0);
	if ((!((((t))->tt_) == (((5) | (1 << 6)))) ? (slot = ((void *)0), 0) : (slot = luaH_getstr(((&((((union GCUnion *)((((t)->value_).gc))))->h))), str), ((((slot))->tt_) == (0)) ? 0 : ((((((L->top - 1)->tt_) & (1 << 6)) && (((((&((((union GCUnion *)((((t)->value_).gc))))->h))))->marked) & ((1 << (2)))) && ((((((L->top - 1)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrierback_(L, ((&((((union GCUnion *)((((t)->value_).gc))))->h)))) : ((void)((0)))), ((void)L, *(((TValue *)(slot))) = *(L->top - 1), ((void)0)), 1))))
		L->top--;
	else {
			{
				TValue *io = (L->top);
				TString *x_ = (str);
				((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
				((io)->tt_ = (((x_->tt) | (1 << 6))));
				((void)0);
			};
			{
				L->top++;
				((void)0);
			};
		luaV_finishset(L, t, L->top - 1, L->top - 2, slot);
		L->top -= 2;
	}
	((void)0);
}

extern void lua_setglobal(lua_State *L, const char *name) {
	Table *reg = ((&((((union GCUnion *)((((&(L->l_G)->l_registry)->value_).gc))))->h)));
	((void)0);
	auxsetstr(L, luaH_getint(reg, 2), name);
}

extern void lua_settable(lua_State *L, int idx) {
	StkId t;
	((void)0);
	((void)0);
	t = index2addr(L, idx);
	{
		const TValue *slot;
		if (!(!((((t))->tt_) == (((5) | (1 << 6)))) ? (slot = ((void *)0), 0) : (slot = luaH_get(((&((((union GCUnion *)((((t)->value_).gc))))->h))), L->top - 2), ((((slot))->tt_) == (0)) ? 0 : ((((((L->top - 1)->tt_) & (1 << 6)) && (((((&((((union GCUnion *)((((t)->value_).gc))))->h))))->marked) & ((1 << (2)))) && ((((((L->top - 1)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrierback_(L, ((&((((union GCUnion *)((((t)->value_).gc))))->h)))) : ((void)((0)))), ((void)L, *(((TValue *)(slot))) = *(L->top - 1), ((void)0)), 1)))) luaV_finishset(L, t, L->top - 2, L->top - 1, slot);
	};
	L->top -= 2;
	((void)0);
}

extern void lua_setfield(lua_State *L, int idx, const char *k) {
	((void)0);
	auxsetstr(L, index2addr(L, idx), k);
}

extern void lua_seti(lua_State *L, int idx, lua_Integer n) {
	StkId t;
	const TValue *slot;
	((void)0);
	((void)0);
	t = index2addr(L, idx);
	if ((!((((t))->tt_) == (((5) | (1 << 6)))) ? (slot = ((void *)0), 0) : (slot = luaH_getint(((&((((union GCUnion *)((((t)->value_).gc))))->h))), n), ((((slot))->tt_) == (0)) ? 0 : ((((((L->top - 1)->tt_) & (1 << 6)) && (((((&((((union GCUnion *)((((t)->value_).gc))))->h))))->marked) & ((1 << (2)))) && ((((((L->top - 1)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrierback_(L, ((&((((union GCUnion *)((((t)->value_).gc))))->h)))) : ((void)((0)))), ((void)L, *(((TValue *)(slot))) = *(L->top - 1), ((void)0)), 1))))
		L->top--;
	else {
			{
				TValue *io = (L->top);
				((io)->value_).i = (n);
				((io)->tt_ = ((3 | (1 << 4))));
			};
			{
				L->top++;
				((void)0);
			};
		luaV_finishset(L, t, L->top - 1, L->top - 2, slot);
		L->top -= 2;
	}
	((void)0);
}

extern void lua_rawset(lua_State *L, int idx) {
	StkId o;
	TValue *slot;
	((void)0);
	((void)0);
	o = index2addr(L, idx);
	((void)0);
	slot = luaH_set(L, ((&((((union GCUnion *)((((o)->value_).gc))))->h))), L->top - 2);
	((void)L, *(slot) = *(L->top - 1), ((void)0));
	((((&((((union GCUnion *)((((o)->value_).gc))))->h))))->flags = 0);
	(((((L->top - 1)->tt_) & (1 << 6)) && (((((&((((union GCUnion *)((((o)->value_).gc))))->h))))->marked) & ((1 << (2)))) && ((((((L->top - 1)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrierback_(L, ((&((((union GCUnion *)((((o)->value_).gc))))->h)))) : ((void)((0))));
	L->top -= 2;
	((void)0);
}

extern void lua_rawseti(lua_State *L, int idx, lua_Integer n) {
	StkId o;
	((void)0);
	((void)0);
	o = index2addr(L, idx);
	((void)0);
	luaH_setint(L, ((&((((union GCUnion *)((((o)->value_).gc))))->h))), n, L->top - 1);
	(((((L->top - 1)->tt_) & (1 << 6)) && (((((&((((union GCUnion *)((((o)->value_).gc))))->h))))->marked) & ((1 << (2)))) && ((((((L->top - 1)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrierback_(L, ((&((((union GCUnion *)((((o)->value_).gc))))->h)))) : ((void)((0))));
	L->top--;
	((void)0);
}

extern void lua_rawsetp(lua_State *L, int idx, const void *p) {
	StkId o;
	TValue k, *slot;
	((void)0);
	((void)0);
	o = index2addr(L, idx);
	((void)0);
	{
		TValue *io = (&k);
		((io)->value_).p = (((void *)(p)));
		((io)->tt_ = (2));
	};
	slot = luaH_set(L, ((&((((union GCUnion *)((((o)->value_).gc))))->h))), &k);
	((void)L, *(slot) = *(L->top - 1), ((void)0));
	(((((L->top - 1)->tt_) & (1 << 6)) && (((((&((((union GCUnion *)((((o)->value_).gc))))->h))))->marked) & ((1 << (2)))) && ((((((L->top - 1)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrierback_(L, ((&((((union GCUnion *)((((o)->value_).gc))))->h)))) : ((void)((0))));
	L->top--;
	((void)0);
}

extern int lua_setmetatable(lua_State *L, int objindex) {
	TValue *obj;
	Table *mt;
	((void)0);
	((void)0);
	obj = index2addr(L, objindex);
	if (((((L->top - 1))->tt_) == (0)))
		mt = ((void *)0);
	else {
		((void)0);
		mt = ((&((((union GCUnion *)((((L->top - 1)->value_).gc))))->h)));
	}
	switch ((((((obj)->tt_)) & 0x0F))) {
	case 5: {
		((&((((union GCUnion *)((((obj)->value_).gc))))->h)))->metatable = mt;
		if (mt) {
			((((((((obj)->value_).gc))->marked) & ((1 << (2)))) && (((mt)->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(L, ((&(((union GCUnion *)(((((obj)->value_).gc))))->gc))), ((&(((union GCUnion *)((mt)))->gc)))) : ((void)((0))));
			luaC_checkfinalizer(L, (((obj)->value_).gc), mt);
		}
		break;
	}
	case 7: {
		((&((((union GCUnion *)((((obj)->value_).gc))))->u)))->metatable = mt;
		if (mt) {
			(((((((&((((union GCUnion *)((((obj)->value_).gc))))->u))))->marked) & ((1 << (2)))) && (((mt)->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(L, ((&(((union GCUnion *)((((&((((union GCUnion *)((((obj)->value_).gc))))->u))))))->gc))), ((&(((union GCUnion *)((mt)))->gc)))) : ((void)((0))));
			luaC_checkfinalizer(L, (((obj)->value_).gc), mt);
		}
		break;
	}
	default: {
		(L->l_G)->mt[(((((obj)->tt_)) & 0x0F))] = mt;
		break;
	}
	}
	L->top--;
	((void)0);
	return 1;
}

extern void lua_setuservalue(lua_State *L, int idx) {
	StkId o;
	((void)0);
	((void)0);
	o = index2addr(L, idx);
	((void)0);
	{
		const TValue *io = (L->top - 1);
		Udata *iu = (((&((((union GCUnion *)((((o)->value_).gc))))->u))));
		iu->user_ = io->value_;
		iu->ttuv_ = ((io)->tt_);
		((void)0);
	};
	(((((L->top - 1)->tt_) & (1 << 6)) && ((((((o)->value_).gc))->marked) & ((1 << (2)))) && ((((((L->top - 1)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(L, ((&(((union GCUnion *)(((((o)->value_).gc))))->gc))), (((L->top - 1)->value_).gc)) : ((void)((0))));
	L->top--;
	((void)0);
}

extern void lua_callk(lua_State *L, int nargs, int nresults,
	lua_KContext ctx, lua_KFunction k) {
	StkId func;
	((void)0);
	((void)0);
	((void)0);
	((void)0);
	((void)0);
	func = L->top - (nargs + 1);
	if (k != ((void *)0) && L->nny == 0) {
		L->ci->u.c.k = k;
		L->ci->u.c.ctx = ctx;
		luaD_call(L, func, nresults);
	}
	else
		luaD_callnoyield(L, func, nresults);
	{
		if ((nresults) == (-1) && L->ci->top < L->top) L->ci->top = L->top;
	};
	((void)0);
}

struct CallS {
	StkId func;
	int nresults;
};

static void f_call(lua_State *L, void *ud) {
	struct CallS *c = ((struct CallS *)(ud));
	luaD_callnoyield(L, c->func, c->nresults);
}

extern int lua_pcallk(lua_State *L, int nargs, int nresults, int errfunc,
	lua_KContext ctx, lua_KFunction k) {
	struct CallS c;
	int status;
	ptrdiff_t func;
	((void)0);
	((void)0);
	((void)0);
	((void)0);
	((void)0);
	if (errfunc == 0)
		func = 0;
	else {
		StkId o = index2addr(L, errfunc);
		((void)0);
		func = ((char *)(o)-(char *)L->stack);
	}
	c.func = L->top - (nargs + 1);
	if (k == ((void *)0) || L->nny > 0) {
		c.nresults = nresults;
		status = luaD_pcall(L, f_call, &c, ((char *)(c.func) - (char *)L->stack), func);
	}
	else {
		CallInfo *ci = L->ci;
		ci->u.c.k = k;
		ci->u.c.ctx = ctx;

		ci->extra = ((char *)(c.func) - (char *)L->stack);
		ci->u.c.old_errfunc = L->errfunc;
		L->errfunc = func;
		((ci->callstatus) = ((ci->callstatus) & ~(1 << 0)) | (L->allowhook));
		ci->callstatus |= (1 << 4);
		luaD_call(L, c.func, nresults);
		ci->callstatus &= ~(1 << 4);
		L->errfunc = ci->u.c.old_errfunc;
		status = 0;
	}
  {
	  if ((nresults) == (-1) && L->ci->top < L->top) L->ci->top = L->top;
  };
	((void)0);
	return status;
}

extern int lua_load(lua_State *L, lua_Reader reader, void *data,
	const char *chunkname, const char *mode) {
	ZIO z;
	int status;
	((void)0);
	if (!chunkname) chunkname = "?";
	luaZ_init(L, &z, reader, data);
	status = luaD_protectedparser(L, &z, chunkname, mode);
	if (status == 0) {
		LClosure *f = ((&((((union GCUnion *)((((L->top - 1)->value_).gc))))->cl.l)));
		if (f->nupvalues >= 1) {

			Table *reg = ((&((((union GCUnion *)((((&(L->l_G)->l_registry)->value_).gc))))->h)));
			const TValue *gt = luaH_getint(reg, 2);

			{
				TValue *io1 = (f->upvals[0]->v);
				*io1 = *(gt);
				(void)L;
				((void)0);
			};
			((((((f->upvals[0])->v)->tt_) & (1 << 6)) && !((f->upvals[0])->v != &(f->upvals[0])->u.value)) ? luaC_upvalbarrier_(L, f->upvals[0]) : ((void)((0))));
		}
	}
	((void)0);
	return status;
}

extern int lua_dump(lua_State *L, lua_Writer writer, void *data, int strip) {
	int status;
	TValue *o;
	((void)0);
	((void)0);
	o = L->top - 1;
	if (((((o))->tt_) == ((((6 | (0 << 4))) | (1 << 6)))))
		status = luaU_dump(L, (((&((((union GCUnion *)((((o)->value_).gc))))->cl.l)))->p), writer, data, strip);
	else
		status = 1;
	((void)0);
	return status;
}

extern int lua_status(lua_State *L) {
	return L->status;
}

extern int lua_gc(lua_State *L, int what, int data) {
	int res = 0;
	global_State *g;
	((void)0);
	g = (L->l_G);
	switch (what) {
	case 0: {
		g->gcrunning = 0;
		break;
	}
	case 1: {
		luaE_setdebt(g, 0);
		g->gcrunning = 1;
		break;
	}
	case 2: {
		luaC_fullgc(L, 0);
		break;
	}
	case 3: {

		res = ((int)((((lu_mem)((g)->totalbytes + (g)->GCdebt)) >> 10)));
		break;
	}
	case 4: {
		res = ((int)((((lu_mem)((g)->totalbytes + (g)->GCdebt)) & 0x3ff)));
		break;
	}
	case 5: {
		l_mem debt = 1;
		lu_byte oldrunning = g->gcrunning;
		g->gcrunning = 1;
		if (data == 0) {
			luaE_setdebt(g, -(((int)((100 * sizeof(TString))))));
			luaC_step(L);
		}
		else {
			debt = ((l_mem)(data)) * 1024 + g->GCdebt;
			luaE_setdebt(g, debt);
			{
				if ((L->l_G)->GCdebt > 0) {
					(void)0;
					luaC_step(L);
					(void)0;
				};
				((void)0);
			};
		}
		g->gcrunning = oldrunning;
		if (debt > 0 && g->gcstate == 7)
			res = 1;
		break;
	}
	case 6: {
		res = g->gcpause;
		g->gcpause = data;
		break;
	}
	case 7: {
		res = g->gcstepmul;
		if (data < 40) data = 40;
		g->gcstepmul = data;
		break;
	}
	case 9: {
		res = g->gcrunning;
		break;
	}
	default: res = -1;
	}
	((void)0);
	return res;
}

extern int lua_error(lua_State *L) {
	((void)0);
	((void)0);
	luaG_errormsg(L);

	return 0;
}

extern int lua_next(lua_State *L, int idx) {
	StkId t;
	int more;
	((void)0);
	t = index2addr(L, idx);
	((void)0);
	more = luaH_next(L, ((&((((union GCUnion *)((((t)->value_).gc))))->h))), L->top - 1);
	if (more) {
			{
				L->top++;
				((void)0);
			};
	}
	else
		L->top -= 1;
	((void)0);
	return more;
}

extern void lua_concat(lua_State *L, int n) {
	((void)0);
	((void)0);
	if (n >= 2) {
		luaV_concat(L, n);
	}
	else if (n == 0) {
			{
				TValue *io = (L->top);
				TString *x_ = (luaS_newlstr(L, "", 0));
				((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
				((io)->tt_ = (((x_->tt) | (1 << 6))));
				((void)0);
			};
			{
				L->top++;
				((void)0);
			};
	}

  {
	  if ((L->l_G)->GCdebt > 0) {
		  (void)0;
		  luaC_step(L);
		  (void)0;
	  };
	  ((void)0);
  };
	((void)0);
}

extern void lua_len(lua_State *L, int idx) {
	StkId t;
	((void)0);
	t = index2addr(L, idx);
	luaV_objlen(L, L->top, t);
	{
		L->top++;
		((void)0);
	};
	((void)0);
}

extern lua_Alloc lua_getallocf(lua_State *L, void **ud) {
	lua_Alloc f;
	((void)0);
	if (ud) *ud = (L->l_G)->ud;
	f = (L->l_G)->frealloc;
	((void)0);
	return f;
}

extern void lua_setallocf(lua_State *L, lua_Alloc f, void *ud) {
	((void)0);
	(L->l_G)->ud = ud;
	(L->l_G)->frealloc = f;
	((void)0);
}

extern void *lua_newuserdata(lua_State *L, size_t size) {
	Udata *u;
	((void)0);
	u = luaS_newudata(L, size);
	{
		TValue *io = (L->top);
		Udata *x_ = (u);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = (((7) | (1 << 6))));
		((void)0);
	};
	{
		L->top++;
		((void)0);
	};
	{
		if ((L->l_G)->GCdebt > 0) {
			(void)0;
			luaC_step(L);
			(void)0;
		};
		((void)0);
	};
	((void)0);
	return ((((char*)((u))) + sizeof(UUdata)));
}

static const char *aux_upvalue(StkId fi, int n, TValue **val,
	CClosure **owner, UpVal **uv) {
	switch ((((fi)->tt_) & 0x3F)) {
	case (6 | (2 << 4)) : {
		CClosure *f = ((&((((union GCUnion *)((((fi)->value_).gc))))->cl.c)));
		if (!(1 <= n && n <= f->nupvalues)) return ((void *)0);
		*val = &f->upvalue[n - 1];
		if (owner) *owner = f;
		return "";
	}
	case (6 | (0 << 4)) : {
		LClosure *f = ((&((((union GCUnion *)((((fi)->value_).gc))))->cl.l)));
		TString *name;
		Proto *p = f->p;
		if (!(1 <= n && n <= p->sizeupvalues)) return ((void *)0);
		*val = f->upvals[n - 1]->v;
		if (uv) *uv = f->upvals[n - 1];
		name = p->upvalues[n - 1].name;
		return (name == ((void *)0)) ? "(*no name)" : (((char *)((name))) + sizeof(UTString));
	}
	default: return ((void *)0);
	}
}

extern const char *lua_getupvalue(lua_State *L, int funcindex, int n) {
	const char *name;
	TValue *val = ((void *)0);
	((void)0);
	name = aux_upvalue(index2addr(L, funcindex), n, &val, ((void *)0), ((void *)0));
	if (name) {
			{
				TValue *io1 = (L->top);
				*io1 = *(val);
				(void)L;
				((void)0);
			};
			{
				L->top++;
				((void)0);
			};
	}
	((void)0);
	return name;
}

extern const char *lua_setupvalue(lua_State *L, int funcindex, int n) {
	const char *name;
	TValue *val = ((void *)0);
	CClosure *owner = ((void *)0);
	UpVal *uv = ((void *)0);
	StkId fi;
	((void)0);
	fi = index2addr(L, funcindex);
	((void)0);
	name = aux_upvalue(fi, n, &val, &owner, &uv);
	if (name) {
		L->top--;
		{
			TValue *io1 = (val);
			*io1 = *(L->top);
			(void)L;
			((void)0);
		};
		if (owner) {
			(((((L->top)->tt_) & (1 << 6)) && (((owner)->marked) & ((1 << (2)))) && ((((((L->top)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(L, ((&(((union GCUnion *)((owner)))->gc))), (((L->top)->value_).gc)) : ((void)((0))));
		}
		else if (uv) {
			((((((uv)->v)->tt_) & (1 << 6)) && !((uv)->v != &(uv)->u.value)) ? luaC_upvalbarrier_(L, uv) : ((void)((0))));
		}
	}
	((void)0);
	return name;
}

static UpVal **getupvalref(lua_State *L, int fidx, int n, LClosure **pf) {
	LClosure *f;
	StkId fi = index2addr(L, fidx);
	((void)0);
	f = ((&((((union GCUnion *)((((fi)->value_).gc))))->cl.l)));
	((void)0);
	if (pf) *pf = f;
	return &f->upvals[n - 1];
}

extern void *lua_upvalueid(lua_State *L, int fidx, int n) {
	StkId fi = index2addr(L, fidx);
	switch ((((fi)->tt_) & 0x3F)) {
	case (6 | (0 << 4)) : {
		return *getupvalref(L, fidx, n, ((void *)0));
	}
	case (6 | (2 << 4)) : {
		CClosure *f = ((&((((union GCUnion *)((((fi)->value_).gc))))->cl.c)));
		((void)0);
		return &f->upvalue[n - 1];
	}
	default: {
		((void)0);
		return ((void *)0);
	}
	}
}

extern void lua_upvaluejoin(lua_State *L, int fidx1, int n1,
	int fidx2, int n2) {
	LClosure *f1;
	UpVal **up1 = getupvalref(L, fidx1, n1, &f1);
	UpVal **up2 = getupvalref(L, fidx2, n2, ((void *)0));
	luaC_upvdeccount(L, *up1);
	*up1 = *up2;
	(*up1)->refcount++;
	if (((*up1)->v != &(*up1)->u.value)) (*up1)->u.open.touched = 1;
	((((((*up1)->v)->tt_) & (1 << 6)) && !((*up1)->v != &(*up1)->u.value)) ? luaC_upvalbarrier_(L, *up1) : ((void)((0))));
}

