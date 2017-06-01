
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

__declspec(dllimport) extern int * __cdecl _errno(void);

errno_t __cdecl _set_errno(int _Value);
errno_t __cdecl _get_errno(int * _Value);

__declspec(dllimport) extern unsigned long  __cdecl __threadid(void);

__declspec(dllimport) extern uintptr_t __cdecl __threadhandle(void);

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

enum OpMode {
	iABC, iABx, iAsBx, iAx
};

typedef enum {

	OP_MOVE,
	OP_LOADK,
	OP_LOADKX,
	OP_LOADBOOL,
	OP_LOADNIL,
	OP_GETUPVAL,

	OP_GETTABUP,
	OP_GETTABLE,

	OP_SETTABUP,
	OP_SETUPVAL,
	OP_SETTABLE,

	OP_NEWTABLE,

	OP_SELF,

	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_MOD,
	OP_POW,
	OP_DIV,
	OP_IDIV,
	OP_BAND,
	OP_BOR,
	OP_BXOR,
	OP_SHL,
	OP_SHR,
	OP_UNM,
	OP_BNOT,
	OP_NOT,
	OP_LEN,

	OP_CONCAT,

	OP_JMP,
	OP_EQ,
	OP_LT,
	OP_LE,

	OP_TEST,
	OP_TESTSET,

	OP_CALL,
	OP_TAILCALL,
	OP_RETURN,

	OP_FORLOOP,

	OP_FORPREP,

	OP_TFORCALL,
	OP_TFORLOOP,

	OP_SETLIST,

	OP_CLOSURE,

	OP_VARARG,

	OP_EXTRAARG
} OpCode;

enum OpArgMask {
	OpArgN,
	OpArgU,
	OpArgR,
	OpArgK
};

extern const lu_byte luaP_opmodes[(((int)(OP_EXTRAARG)) + 1)];

extern const char *const luaP_opnames[(((int)(OP_EXTRAARG)) + 1) + 1];

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

typedef enum BinOpr {
	OPR_ADD, OPR_SUB, OPR_MUL, OPR_MOD, OPR_POW,
	OPR_DIV,
	OPR_IDIV,
	OPR_BAND, OPR_BOR, OPR_BXOR,
	OPR_SHL, OPR_SHR,
	OPR_CONCAT,
	OPR_EQ, OPR_LT, OPR_LE,
	OPR_NE, OPR_GT, OPR_GE,
	OPR_AND, OPR_OR,
	OPR_NOBINOPR
} BinOpr;

typedef enum UnOpr {
	OPR_MINUS, OPR_BNOT, OPR_NOT, OPR_LEN, OPR_NOUNOPR
} UnOpr;

extern int luaK_codeABx(FuncState *fs, OpCode o, int A, unsigned int Bx);
extern int luaK_codeABC(FuncState *fs, OpCode o, int A, int B, int C);
extern int luaK_codek(FuncState *fs, int reg, int k);
extern void luaK_fixline(FuncState *fs, int line);
extern void luaK_nil(FuncState *fs, int from, int n);
extern void luaK_reserveregs(FuncState *fs, int n);
extern void luaK_checkstack(FuncState *fs, int n);
extern int luaK_stringK(FuncState *fs, TString *s);
extern int luaK_intK(FuncState *fs, lua_Integer n);
extern void luaK_dischargevars(FuncState *fs, expdesc *e);
extern int luaK_exp2anyreg(FuncState *fs, expdesc *e);
extern void luaK_exp2anyregup(FuncState *fs, expdesc *e);
extern void luaK_exp2nextreg(FuncState *fs, expdesc *e);
extern void luaK_exp2val(FuncState *fs, expdesc *e);
extern int luaK_exp2RK(FuncState *fs, expdesc *e);
extern void luaK_self(FuncState *fs, expdesc *e, expdesc *key);
extern void luaK_indexed(FuncState *fs, expdesc *t, expdesc *k);
extern void luaK_goiftrue(FuncState *fs, expdesc *e);
extern void luaK_goiffalse(FuncState *fs, expdesc *e);
extern void luaK_storevar(FuncState *fs, expdesc *var, expdesc *e);
extern void luaK_setreturns(FuncState *fs, expdesc *e, int nresults);
extern void luaK_setoneret(FuncState *fs, expdesc *e);
extern int luaK_jump(FuncState *fs);
extern void luaK_ret(FuncState *fs, int first, int nret);
extern void luaK_patchlist(FuncState *fs, int list, int target);
extern void luaK_patchtohere(FuncState *fs, int list);
extern void luaK_patchclose(FuncState *fs, int list, int level);
extern void luaK_concat(FuncState *fs, int *l1, int l2);
extern int luaK_getlabel(FuncState *fs);
extern void luaK_prefix(FuncState *fs, UnOpr op, expdesc *v, int line);
extern void luaK_infix(FuncState *fs, BinOpr op, expdesc *v);
extern void luaK_posfix(FuncState *fs, BinOpr op, expdesc *v1,
	expdesc *v2, int line);
extern void luaK_setlist(FuncState *fs, int base, int nelems, int tostore);

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

static const char *getfuncname(lua_State *L, CallInfo *ci, const char **name);

static int currentpc(CallInfo *ci) {
	((void)0);
	return (((int)((ci->u.l.savedpc) - ((((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))))->p)->code)) - 1);
}

static int currentline(CallInfo *ci) {
	return ((((((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))))->p)->lineinfo) ? ((((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))))->p)->lineinfo[currentpc(ci)] : -1);
}

static void swapextra(lua_State *L) {
	if (L->status == 1) {
		CallInfo *ci = L->ci;
		StkId temp = ci->func;
		ci->func = ((TValue *)((char *)L->stack + (ci->extra)));
		ci->extra = ((char *)(temp)-(char *)L->stack);
	}
}

extern void lua_sethook(lua_State *L, lua_Hook func, int mask, int count) {
	if (func == ((void *)0) || mask == 0) {
		mask = 0;
		func = ((void *)0);
	}
	if (((L->ci)->callstatus & (1 << 1)))
		L->oldpc = L->ci->u.l.savedpc;
	L->hook = func;
	L->basehookcount = count;
	(L->hookcount = L->basehookcount);
	L->hookmask = ((lu_byte)((mask)));
}

extern lua_Hook lua_gethook(lua_State *L) {
	return L->hook;
}

extern int lua_gethookmask(lua_State *L) {
	return L->hookmask;
}

extern int lua_gethookcount(lua_State *L) {
	return L->basehookcount;
}

extern int lua_getstack(lua_State *L, int level, lua_Debug *ar) {
	int status;
	CallInfo *ci;
	if (level < 0) return 0;
	((void)0);
	for (ci = L->ci;
		level > 0 && ci != &L->base_ci;
		ci = ci->previous)
		level--;
	if (level == 0 && ci != &L->base_ci) {
		status = 1;
		ar->i_ci = ci;
	}
	else status = 0;
	((void)0);
	return status;
}

static const char *upvalname(Proto *p, int uv) {
	TString *s = (p->upvalues[uv].name);
	if (s == ((void *)0)) return "?";
	else return (((char *)((s))) + sizeof(UTString));
}

static const char *findvararg(CallInfo *ci, int n, StkId *pos) {
	int nparams = ((&((((union GCUnion *)((((ci->func)->value_).gc))))->cl.l)))->p->numparams;
	if (n >= ((int)((ci->u.l.base - ci->func))) - nparams)
		return ((void *)0);
	else {
		*pos = ci->func + nparams + n;
		return "(*vararg)";
	}
}

static const char *findlocal(lua_State *L, CallInfo *ci, int n,
	StkId *pos) {
	const char *name = ((void *)0);
	StkId base;
	if (((ci)->callstatus & (1 << 1))) {
		if (n < 0)
			return findvararg(ci, -n, pos);
		else {
			base = ci->u.l.base;
			name = luaF_getlocalname((((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))))->p, n, currentpc(ci));
		}
	}
	else
		base = ci->func + 1;
	if (name == ((void *)0)) {
		StkId limit = (ci == L->ci) ? L->top : ci->next->func;
		if (limit - base >= n && n > 0)
			name = "(*temporary)";
		else
			return ((void *)0);
	}
	*pos = base + (n - 1);
	return name;
}

extern const char *lua_getlocal(lua_State *L, const lua_Debug *ar, int n) {
	const char *name;
	((void)0);
	swapextra(L);
	if (ar == ((void *)0)) {
		if (!((((L->top - 1))->tt_) == ((((6 | (0 << 4))) | (1 << 6)))))
			name = ((void *)0);
		else
			name = luaF_getlocalname(((&((((union GCUnion *)((((L->top - 1)->value_).gc))))->cl.l)))->p, n, 0);
	}
	else {
		StkId pos = ((void *)0);
		name = findlocal(L, ar->i_ci, n, &pos);
		if (name) {
				{
					TValue *io1 = (L->top);
					*io1 = *(pos);
					(void)L;
					((void)0);
				};
				{
					L->top++;
					((void)0);
				};
		}
	}
	swapextra(L);
	((void)0);
	return name;
}

extern const char *lua_setlocal(lua_State *L, const lua_Debug *ar, int n) {
	StkId pos = ((void *)0);
	const char *name;
	((void)0);
	swapextra(L);
	name = findlocal(L, ar->i_ci, n, &pos);
	if (name) {
			{
				TValue *io1 = (pos);
				*io1 = *(L->top - 1);
				(void)L;
				((void)0);
			};
		L->top--;
	}
	swapextra(L);
	((void)0);
	return name;
}

static void funcinfo(lua_Debug *ar, Closure *cl) {
	if (((cl) == ((void *)0) || (cl)->c.tt == (6 | (2 << 4)))) {
		ar->source = "=[C]";
		ar->linedefined = -1;
		ar->lastlinedefined = -1;
		ar->what = "C";
	}
	else {
		Proto *p = cl->l.p;
		ar->source = p->source ? (((char *)((p->source))) + sizeof(UTString)) : "=?";
		ar->linedefined = p->linedefined;
		ar->lastlinedefined = p->lastlinedefined;
		ar->what = (ar->linedefined == 0) ? "main" : "Lua";
	}
	luaO_chunkid(ar->short_src, ar->source, 60);
}

static void collectvalidlines(lua_State *L, Closure *f) {
	if (((f) == ((void *)0) || (f)->c.tt == (6 | (2 << 4)))) {
		((L->top)->tt_ = (0));
		{
			L->top++;
			((void)0);
		};
	}
	else {
		int i;
		TValue v;
		int *lineinfo = f->l.p->lineinfo;
		Table *t = luaH_new(L);
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
		{
			TValue *io = (&v);
			((io)->value_).b = (1);
			((io)->tt_ = (1));
		};
		for (i = 0;
			i < f->l.p->sizelineinfo;
			i++)
			luaH_setint(L, t, lineinfo[i], &v);
	}
}

static int auxgetinfo(lua_State *L, const char *what, lua_Debug *ar,
	Closure *f, CallInfo *ci) {
	int status = 1;
	for (;
		*what;
		what++) {
		switch (*what) {
		case 'S': {
			funcinfo(ar, f);
			break;
		}
		case 'l': {
			ar->currentline = (ci && ((ci)->callstatus & (1 << 1))) ? currentline(ci) : -1;
			break;
		}
		case 'u': {
			ar->nups = (f == ((void *)0)) ? 0 : f->c.nupvalues;
			if (((f) == ((void *)0) || (f)->c.tt == (6 | (2 << 4)))) {
				ar->isvararg = 1;
				ar->nparams = 0;
			}
			else {
				ar->isvararg = f->l.p->is_vararg;
				ar->nparams = f->l.p->numparams;
			}
			break;
		}
		case 't': {
			ar->istailcall = (ci) ? ci->callstatus & (1 << 5) : 0;
			break;
		}
		case 'n': {

			if (ci && !(ci->callstatus & (1 << 5)) && ((ci->previous)->callstatus & (1 << 1)))
				ar->namewhat = getfuncname(L, ci->previous, &ar->name);
			else
				ar->namewhat = ((void *)0);
			if (ar->namewhat == ((void *)0)) {
				ar->namewhat = "";
				ar->name = ((void *)0);
			}
			break;
		}
		case 'L':
		case 'f':
			break;
		default: status = 0;
		}
	}
	return status;
}

extern int lua_getinfo(lua_State *L, const char *what, lua_Debug *ar) {
	int status;
	Closure *cl;
	CallInfo *ci;
	StkId func;
	((void)0);
	swapextra(L);
	if (*what == '>') {
		ci = ((void *)0);
		func = L->top - 1;
		((void)0);
		what++;
		L->top--;
	}
	else {
		ci = ar->i_ci;
		func = ci->func;
		((void)0);
	}
	cl = ((((func)->tt_) & 0x1F) == 6) ? ((&((((union GCUnion *)((((func)->value_).gc))))->cl))) : ((void *)0);
	status = auxgetinfo(L, what, ar, cl, ci);
	if (strchr(what, 'f')) {
			{
				TValue *io1 = (L->top);
				*io1 = *(func);
				(void)L;
				((void)0);
			};
			{
				L->top++;
				((void)0);
			};
	}
	swapextra(L);
	if (strchr(what, 'L'))
		collectvalidlines(L, cl);
	((void)0);
	return status;
}

static const char *getobjname(Proto *p, int lastpc, int reg,
	const char **name);

static void kname(Proto *p, int pc, int c, const char **name) {
	if (((c)& (1 << (9 - 1)))) {
		TValue *kvalue = &p->k[((int)(c)& ~(1 << (9 - 1)))];
		if ((((((((kvalue))->tt_)) & 0x0F)) == (4))) {
			*name = (((char *)((((&((((union GCUnion *)((((kvalue)->value_).gc))))->ts)))))) + sizeof(UTString));
			return;
		}

	}
	else {
		const char *what = getobjname(p, pc, c, name);
		if (what && *what == 'c') {
			return;
		}

	}
	*name = "?";
}

static int filterpc(int pc, int jmptarget) {
	if (pc < jmptarget)
		return -1;
	else return pc;
}

static int findsetreg(Proto *p, int lastpc, int reg) {
	int pc;
	int setreg = -1;
	int jmptarget = 0;
	for (pc = 0;
		pc < lastpc;
		pc++) {
		Instruction i = p->code[pc];
		OpCode op = (((OpCode)(((i) >> 0) & ((~((~(Instruction)0) << (6))) << (0)))));
		int a = (((int)(((i) >> (0 + 6)) & ((~((~(Instruction)0) << (8))) << (0)))));
		switch (op) {
		case OP_LOADNIL: {
			int b = (((int)(((i) >> (((0 + 6) + 8) + 9)) & ((~((~(Instruction)0) << (9))) << (0)))));
			if (a <= reg && reg <= a + b)
				setreg = filterpc(pc, jmptarget);
			break;
		}
		case OP_TFORCALL: {
			if (reg >= a + 2)
				setreg = filterpc(pc, jmptarget);
			break;
		}
		case OP_CALL:
		case OP_TAILCALL: {
			if (reg >= a)
				setreg = filterpc(pc, jmptarget);
			break;
		}
		case OP_JMP: {
			int b = ((((int)(((i) >> ((0 + 6) + 8)) & ((~((~(Instruction)0) << ((9 + 9)))) << (0))))) - (((1 << (9 + 9)) - 1) >> 1));
			int dest = pc + 1 + b;

			if (pc < dest && dest <= lastpc) {
				if (dest > jmptarget)
					jmptarget = dest;
			}
			break;
		}
		default:
			if ((luaP_opmodes[op] & (1 << 6)) && reg == a)
				setreg = filterpc(pc, jmptarget);
			break;
		}
	}
	return setreg;
}

static const char *getobjname(Proto *p, int lastpc, int reg,
	const char **name) {
	int pc;
	*name = luaF_getlocalname(p, reg + 1, lastpc);
	if (*name)
		return "local";

	pc = findsetreg(p, lastpc, reg);
	if (pc != -1) {
		Instruction i = p->code[pc];
		OpCode op = (((OpCode)(((i) >> 0) & ((~((~(Instruction)0) << (6))) << (0)))));
		switch (op) {
		case OP_MOVE: {
			int b = (((int)(((i) >> (((0 + 6) + 8) + 9)) & ((~((~(Instruction)0) << (9))) << (0)))));
			if (b < (((int)(((i) >> (0 + 6)) & ((~((~(Instruction)0) << (8))) << (0))))))
				return getobjname(p, pc, b, name);
			break;
		}
		case OP_GETTABUP:
		case OP_GETTABLE: {
			int k = (((int)(((i) >> ((0 + 6) + 8)) & ((~((~(Instruction)0) << (9))) << (0)))));
			int t = (((int)(((i) >> (((0 + 6) + 8) + 9)) & ((~((~(Instruction)0) << (9))) << (0)))));
			const char *vn = (op == OP_GETTABLE)
				? luaF_getlocalname(p, t + 1, pc)
				: upvalname(p, t);
			kname(p, pc, k, name);
			return (vn && strcmp(vn, "_ENV") == 0) ? "global" : "field";
		}
		case OP_GETUPVAL: {
			*name = upvalname(p, (((int)(((i) >> (((0 + 6) + 8) + 9)) & ((~((~(Instruction)0) << (9))) << (0))))));
			return "upvalue";
		}
		case OP_LOADK:
		case OP_LOADKX: {
			int b = (op == OP_LOADK) ? (((int)(((i) >> ((0 + 6) + 8)) & ((~((~(Instruction)0) << ((9 + 9)))) << (0)))))
				: (((int)(((p->code[pc + 1]) >> (0 + 6)) & ((~((~(Instruction)0) << ((9 + 9 + 8)))) << (0)))));
			if ((((((((&p->k[b]))->tt_)) & 0x0F)) == (4))) {
				*name = (((char *)((((&((((union GCUnion *)((((&p->k[b])->value_).gc))))->ts)))))) + sizeof(UTString));
				return "constant";
			}
			break;
		}
		case OP_SELF: {
			int k = (((int)(((i) >> ((0 + 6) + 8)) & ((~((~(Instruction)0) << (9))) << (0)))));
			kname(p, pc, k, name);
			return "method";
		}
		default: break;
		}
	}
	return ((void *)0);
}

static const char *getfuncname(lua_State *L, CallInfo *ci, const char **name) {
	TMS tm = (TMS)0;
	Proto *p = (((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))))->p;
	int pc = currentpc(ci);
	Instruction i = p->code[pc];
	if (ci->callstatus & (1 << 2)) {
		*name = "?";
		return "hook";
	}
	switch ((((OpCode)(((i) >> 0) & ((~((~(Instruction)0) << (6))) << (0)))))) {
	case OP_CALL:
	case OP_TAILCALL:
		return getobjname(p, pc, (((int)(((i) >> (0 + 6)) & ((~((~(Instruction)0) << (8))) << (0))))), name);
	case OP_TFORCALL: {
		*name = "for iterator";
		return "for iterator";
	}

	case OP_SELF: case OP_GETTABUP: case OP_GETTABLE:
		tm = TM_INDEX;
		break;
	case OP_SETTABUP: case OP_SETTABLE:
		tm = TM_NEWINDEX;
		break;
	case OP_ADD: case OP_SUB: case OP_MUL: case OP_MOD:
	case OP_POW: case OP_DIV: case OP_IDIV: case OP_BAND:
	case OP_BOR: case OP_BXOR: case OP_SHL: case OP_SHR: {
		int offset = ((int)(((((OpCode)(((i) >> 0) & ((~((~(Instruction)0) << (6))) << (0)))))))) - ((int)((OP_ADD)));
		tm = ((TMS)(offset + ((int)((TM_ADD)))));
		break;
	}
	case OP_UNM: tm = TM_UNM;
		break;
	case OP_BNOT: tm = TM_BNOT;
		break;
	case OP_LEN: tm = TM_LEN;
		break;
	case OP_CONCAT: tm = TM_CONCAT;
		break;
	case OP_EQ: tm = TM_EQ;
		break;
	case OP_LT: tm = TM_LT;
		break;
	case OP_LE: tm = TM_LE;
		break;
	default: ((void)0);
	}
	*name = (((char *)(((L->l_G)->tmname[tm]))) + sizeof(UTString));
	return "metamethod";
}

static int isinstack(CallInfo *ci, const TValue *o) {
	ptrdiff_t i = o - ci->u.l.base;
	return (0 <= i && i < (ci->top - ci->u.l.base) && ci->u.l.base + i == o);
}

static const char *getupvalname(CallInfo *ci, const TValue *o,
	const char **name) {
	LClosure *c = (((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))));
	int i;
	for (i = 0;
		i < c->nupvalues;
		i++) {
		if (c->upvals[i]->v == o) {
			*name = upvalname(c->p, i);
			return "upvalue";
		}
	}
	return ((void *)0);
}

static const char *varinfo(lua_State *L, const TValue *o) {
	const char *name = ((void *)0);
	CallInfo *ci = L->ci;
	const char *kind = ((void *)0);
	if (((ci)->callstatus & (1 << 1))) {
		kind = getupvalname(ci, o, &name);
		if (!kind && isinstack(ci, o))
			kind = getobjname((((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))))->p, currentpc(ci),
			((int)((o - ci->u.l.base))), &name);
	}
	return (kind) ? luaO_pushfstring(L, " (%s '%s')", kind, name) : "";
}

void __declspec(noreturn) luaG_typeerror(lua_State *L, const TValue *o, const char *op) {
	const char *t = luaT_objtypename(L, o);
	luaG_runerror(L, "attempt to %s a %s value%s", op, t, varinfo(L, o));
}

void __declspec(noreturn) luaG_concaterror(lua_State *L, const TValue *p1, const TValue *p2) {
	if ((((((((p1))->tt_)) & 0x0F)) == (4)) || (((((((p1))->tt_)) & 0x0F)) == (3))) p1 = p2;
	luaG_typeerror(L, p1, "concatenate");
}

void __declspec(noreturn) luaG_opinterror(lua_State *L, const TValue *p1,
	const TValue *p2, const char *msg) {
	lua_Number temp;
	if (!(((((p1))->tt_) == ((3 | (0 << 4)))) ? (*(&temp) = (((p1)->value_).n), 1) : luaV_tonumber_(p1, &temp)))
		p2 = p1;
	luaG_typeerror(L, p2, msg);
}

void __declspec(noreturn) luaG_tointerror(lua_State *L, const TValue *p1, const TValue *p2) {
	lua_Integer temp;
	if (!(((((p1))->tt_) == ((3 | (1 << 4)))) ? (*(&temp) = (((p1)->value_).i), 1) : luaV_tointeger(p1, &temp, 0)))
		p2 = p1;
	luaG_runerror(L, "number%s has no integer representation", varinfo(L, p2));
}

void __declspec(noreturn) luaG_ordererror(lua_State *L, const TValue *p1, const TValue *p2) {
	const char *t1 = luaT_objtypename(L, p1);
	const char *t2 = luaT_objtypename(L, p2);
	if (strcmp(t1, t2) == 0)
		luaG_runerror(L, "attempt to compare two %s values", t1);
	else
		luaG_runerror(L, "attempt to compare %s with %s", t1, t2);
}

const char *luaG_addinfo(lua_State *L, const char *msg, TString *src,
	int line) {
	char buff[60];
	if (src)
		luaO_chunkid(buff, (((char *)((src))) + sizeof(UTString)), 60);
	else {
		buff[0] = '?';
		buff[1] = '\0';
	}
	return luaO_pushfstring(L, "%s:%d: %s", buff, line, msg);
}

void __declspec(noreturn) luaG_errormsg(lua_State *L) {
	if (L->errfunc != 0) {
		StkId errfunc = ((TValue *)((char *)L->stack + (L->errfunc)));
		{
			TValue *io1 = (L->top);
			*io1 = *(L->top - 1);
			(void)L;
			((void)0);
		};
		{
			TValue *io1 = (L->top - 1);
			*io1 = *(errfunc);
			(void)L;
			((void)0);
		};
		L->top++;
		luaD_callnoyield(L, L->top - 2, 1);
	}
	luaD_throw(L, 2);
}

void __declspec(noreturn) luaG_runerror(lua_State *L, const char *fmt, ...) {
	CallInfo *ci = L->ci;
	const char *msg;
	va_list argp;
	(argp = (va_list)(&(fmt)) + ((sizeof(fmt) + sizeof(int) - 1) & ~(sizeof(int) - 1)));
	msg = luaO_pushvfstring(L, fmt, argp);
	(argp = (va_list)0);
	if (((ci)->callstatus & (1 << 1)))
		luaG_addinfo(L, msg, (((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))))->p->source, currentline(ci));
	luaG_errormsg(L);
}

void luaG_traceexec(lua_State *L) {
	CallInfo *ci = L->ci;
	lu_byte mask = L->hookmask;
	int counthook = (--L->hookcount == 0 && (mask & (1 << 3)));
	if (counthook)
		(L->hookcount = L->basehookcount);
	else if (!(mask & (1 << 2)))
		return;
	if (ci->callstatus & (1 << 6)) {
		ci->callstatus &= ~(1 << 6);
		return;
	}
	if (counthook)
		luaD_hook(L, 3, -1);
	if (mask & (1 << 2)) {
		Proto *p = (((&((((union GCUnion *)(((((ci)->func)->value_).gc))))->cl.l))))->p;
		int npc = (((int)((ci->u.l.savedpc) - (p)->code)) - 1);
		int newline = (((p)->lineinfo) ? (p)->lineinfo[npc] : -1);
		if (npc == 0 ||
			ci->u.l.savedpc <= L->oldpc ||
			newline != (((p)->lineinfo) ? (p)->lineinfo[(((int)((L->oldpc) - (p)->code)) - 1)] : -1))
			luaD_hook(L, 2, newline);
	}
	L->oldpc = ci->u.l.savedpc;
	if (L->status == 1) {
		if (counthook)
			L->hookcount = 1;
		ci->u.l.savedpc--;
		ci->callstatus |= (1 << 6);
		ci->func = L->top - 1;
		luaD_throw(L, 1);
	}
}

