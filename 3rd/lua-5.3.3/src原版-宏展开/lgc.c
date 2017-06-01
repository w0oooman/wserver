
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

static void reallymarkobject(global_State *g, GCObject *o);

static void removeentry(Node *n) {
	((void)0);
	if (((((((const TValue*)((&(n)->i_key.tvk))))->tt_) & (1 << 6)) && ((((((((const TValue*)((&(n)->i_key.tvk))))->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))))
		(((&(n)->i_key.nk))->tt_ = ((9 + 1)));
}

static int iscleared(global_State *g, const TValue *o) {
	if (!(((o)->tt_) & (1 << 6))) return 0;
	else if ((((((((o))->tt_)) & 0x0F)) == (4))) {
			{
				if ((((((&((((union GCUnion *)((((o)->value_).gc))))->ts))))->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((((&((((union GCUnion *)((((o)->value_).gc))))->ts))))))->gc))));
			};
		return 0;
	}
	else return ((((((o)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))));
}

void luaC_barrier_(lua_State *L, GCObject *o, GCObject *v) {
	global_State *g = (L->l_G);
	((void)0);
	if (((g)->gcstate <= 1))
		reallymarkobject(g, v);
	else {
		((void)0);
		(o->marked = ((lu_byte)(((o->marked & (~((1 << (2)) | ((1 << (0)) | (1 << (1)))))) | ((lu_byte)((g)->currentwhite & ((1 << (0)) | (1 << (1)))))))));
	}
}

void luaC_barrierback_(lua_State *L, Table *t) {
	global_State *g = (L->l_G);
	((void)0);
	((t->marked) &= ((lu_byte)(~((1 << (2))))));
	((t)->gclist = (g->grayagain), (g->grayagain) = ((&(((union GCUnion *)((t)))->gc))));
}

void luaC_upvalbarrier_(lua_State *L, UpVal *uv) {
	global_State *g = (L->l_G);
	GCObject *o = (((uv->v)->value_).gc);
	((void)0);
	if (((g)->gcstate <= 1))
	{
		if ((((o)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((o)))->gc))));
	};
}

void luaC_fix(lua_State *L, GCObject *o) {
	global_State *g = (L->l_G);
	((void)0);
	((o->marked) &= ((lu_byte)(~(((1 << (0)) | (1 << (1)))))));
	g->allgc = o->next;
	o->next = g->fixedgc;
	g->fixedgc = o;
}

GCObject *luaC_newobj(lua_State *L, int tt, size_t sz) {
	global_State *g = (L->l_G);
	GCObject *o = ((GCObject *)(luaM_realloc_(L, ((void *)0), ((tt)& 0x0F), (sz))));
	o->marked = ((lu_byte)((g)->currentwhite & ((1 << (0)) | (1 << (1)))));
	o->tt = tt;
	o->next = g->allgc;
	g->allgc = o;
	return o;
}

static void reallymarkobject(global_State *g, GCObject *o) {
reentry:
	((o->marked) &= ((lu_byte)(~(((1 << (0)) | (1 << (1)))))));
	switch (o->tt) {
	case (4 | (0 << 4)) : {
		(((o)->marked) |= ((1 << (2))));
		g->GCmemtrav += (sizeof(union UTString) + (((&((((union GCUnion *)((o))))->ts))->shrlen) + 1) * sizeof(char));
		break;
	}
	case (4 | (1 << 4)) : {
		(((o)->marked) |= ((1 << (2))));
		g->GCmemtrav += (sizeof(union UTString) + (((&((((union GCUnion *)((o))))->ts))->u.lnglen) + 1) * sizeof(char));
		break;
	}
	case 7: {
		TValue uvalue;
		{
			if ((&((((union GCUnion *)((o))))->u))->metatable) {
				if (((((&((((union GCUnion *)((o))))->u))->metatable)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)(((&((((union GCUnion *)((o))))->u))->metatable)))->gc))));
			};
		};
		(((o)->marked) |= ((1 << (2))));
		g->GCmemtrav += (sizeof(union UUdata) + (((&((((union GCUnion *)((o))))->u)))->len));
		{
			TValue *io = (&uvalue);
			const Udata *iu = ((&((((union GCUnion *)((o))))->u)));
			io->value_ = iu->user_;
			((io)->tt_ = (iu->ttuv_));
			((void)0);
		};
		if (((((&uvalue)->tt_) & (1 << 6)) && ((((((&uvalue)->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) {
			o = (((&uvalue)->value_).gc);
			goto reentry;
		}
		break;
	}
	case (6 | (0 << 4)) : {
		(((&((((union GCUnion *)((o))))->cl.l)))->gclist = (g->gray), (g->gray) = ((&(((union GCUnion *)(((&((((union GCUnion *)((o))))->cl.l)))))->gc))));
		break;
	}
	case (6 | (2 << 4)) : {
		(((&((((union GCUnion *)((o))))->cl.c)))->gclist = (g->gray), (g->gray) = ((&(((union GCUnion *)(((&((((union GCUnion *)((o))))->cl.c)))))->gc))));
		break;
	}
	case 5: {
		(((&((((union GCUnion *)((o))))->h)))->gclist = (g->gray), (g->gray) = ((&(((union GCUnion *)(((&((((union GCUnion *)((o))))->h)))))->gc))));
		break;
	}
	case 8: {
		(((&((((union GCUnion *)((o))))->th)))->gclist = (g->gray), (g->gray) = ((&(((union GCUnion *)(((&((((union GCUnion *)((o))))->th)))))->gc))));
		break;
	}
	case 9: {
		(((&((((union GCUnion *)((o))))->p)))->gclist = (g->gray), (g->gray) = ((&(((union GCUnion *)(((&((((union GCUnion *)((o))))->p)))))->gc))));
		break;
	}
	default: ((void)0);
		break;
	}
}

static void markmt(global_State *g) {
	int i;
	for (i = 0;
		i < 9;
		i++)
	{
		if (g->mt[i]) {
			if ((((g->mt[i])->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((g->mt[i])))->gc))));
		};
	};
}

static void markbeingfnz(global_State *g) {
	GCObject *o;
	for (o = g->tobefnz;
		o != ((void *)0);
		o = o->next)
	{
		if ((((o)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((o)))->gc))));
	};
}

static void remarkupvals(global_State *g) {
	lua_State *thread;
	lua_State **p = &g->twups;
	while ((thread = *p) != ((void *)0)) {
		((void)0);
		if ((!(((thread)->marked) & (((1 << (0)) | (1 << (1))) | (1 << (2))))) && thread->openupval != ((void *)0))
			p = &thread->twups;
		else {
			UpVal *uv;
			*p = thread->twups;
			thread->twups = thread;
			for (uv = thread->openupval;
				uv != ((void *)0);
				uv = uv->u.open.next) {
				if (uv->u.open.touched) {
						{
							((void)0);
							if (((((uv->v)->tt_) & (1 << 6)) && ((((((uv->v)->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((uv->v)->value_).gc));
						};
					uv->u.open.touched = 0;
				}
			}
		}
	}
}

static void restartcollection(global_State *g) {
	g->gray = g->grayagain = ((void *)0);
	g->weak = g->allweak = g->ephemeron = ((void *)0);
	{
		if ((((g->mainthread)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((g->mainthread)))->gc))));
	};
	{
		((void)0);
		if (((((&g->l_registry)->tt_) & (1 << 6)) && ((((((&g->l_registry)->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((&g->l_registry)->value_).gc));
	};
	markmt(g);
	markbeingfnz(g);
}

static void traverseweakvalue(global_State *g, Table *h) {
	Node *n, *limit = (&(h)->node[((size_t)(((1 << ((h)->lsizenode)))))]);

	int hasclears = (h->sizearray > 0);
	for (n = (&(h)->node[0]);
		n < limit;
		n++) {
		((void)0);
		if ((((((&(n)->i_val)))->tt_) == (0)))
			removeentry(n);
		else {
			((void)0);
			{
				((void)0);
				if (((((((const TValue*)((&(n)->i_key.tvk))))->tt_) & (1 << 6)) && ((((((((const TValue*)((&(n)->i_key.tvk))))->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((((const TValue*)((&(n)->i_key.tvk))))->value_).gc));
			};
			if (!hasclears && iscleared(g, (&(n)->i_val)))
				hasclears = 1;
		}
	}
	if (g->gcstate == 0)
		((h)->gclist = (g->grayagain), (g->grayagain) = ((&(((union GCUnion *)((h)))->gc))));
	else if (hasclears)
		((h)->gclist = (g->weak), (g->weak) = ((&(((union GCUnion *)((h)))->gc))));
}

static int traverseephemeron(global_State *g, Table *h) {
	int marked = 0;
	int hasclears = 0;
	int hasww = 0;
	Node *n, *limit = (&(h)->node[((size_t)(((1 << ((h)->lsizenode)))))]);
	unsigned int i;

	for (i = 0;
		i < h->sizearray;
		i++) {
		if (((((&h->array[i])->tt_) & (1 << 6)) && ((((((&h->array[i])->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) {
			marked = 1;
			reallymarkobject(g, (((&h->array[i])->value_).gc));
		}
	}

	for (n = (&(h)->node[0]);
		n < limit;
		n++) {
		((void)0);
		if ((((((&(n)->i_val)))->tt_) == (0)))
			removeentry(n);
		else if (iscleared(g, ((const TValue*)((&(n)->i_key.tvk))))) {
			hasclears = 1;
			if ((((((&(n)->i_val))->tt_) & (1 << 6)) && (((((((&(n)->i_val))->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))))
				hasww = 1;
		}
		else if ((((((&(n)->i_val))->tt_) & (1 << 6)) && (((((((&(n)->i_val))->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) {
			marked = 1;
			reallymarkobject(g, ((((&(n)->i_val))->value_).gc));
		}
	}

	if (g->gcstate == 0)
		((h)->gclist = (g->grayagain), (g->grayagain) = ((&(((union GCUnion *)((h)))->gc))));
	else if (hasww)
		((h)->gclist = (g->ephemeron), (g->ephemeron) = ((&(((union GCUnion *)((h)))->gc))));
	else if (hasclears)
		((h)->gclist = (g->allweak), (g->allweak) = ((&(((union GCUnion *)((h)))->gc))));
	return marked;
}

static void traversestrongtable(global_State *g, Table *h) {
	Node *n, *limit = (&(h)->node[((size_t)(((1 << ((h)->lsizenode)))))]);
	unsigned int i;
	for (i = 0;
		i < h->sizearray;
		i++)
	{
		((void)0);
		if (((((&h->array[i])->tt_) & (1 << 6)) && ((((((&h->array[i])->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((&h->array[i])->value_).gc));
	};
	for (n = (&(h)->node[0]);
		n < limit;
		n++) {
		((void)0);
		if ((((((&(n)->i_val)))->tt_) == (0)))
			removeentry(n);
		else {
			((void)0);
			{
				((void)0);
				if (((((((const TValue*)((&(n)->i_key.tvk))))->tt_) & (1 << 6)) && ((((((((const TValue*)((&(n)->i_key.tvk))))->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((((const TValue*)((&(n)->i_key.tvk))))->value_).gc));
			};
			{
				((void)0);
				if ((((((&(n)->i_val))->tt_) & (1 << 6)) && (((((((&(n)->i_val))->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, ((((&(n)->i_val))->value_).gc));
			};
		}
	}
}

static lu_mem traversetable(global_State *g, Table *h) {
	const char *weakkey, *weakvalue;
	const TValue *mode = ((h->metatable) == ((void *)0) ? ((void *)0) : ((h->metatable)->flags & (1u << (TM_MODE))) ? ((void *)0) : luaT_gettm(h->metatable, TM_MODE, (g)->tmname[TM_MODE]));
	{
		if (h->metatable) {
			if ((((h->metatable)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((h->metatable)))->gc))));
		};
	};
	if (mode && (((((((mode))->tt_)) & 0x0F)) == (4)) &&
		((weakkey = strchr((((char *)((((&((((union GCUnion *)((((mode)->value_).gc))))->ts)))))) + sizeof(UTString)), 'k')),
		(weakvalue = strchr((((char *)((((&((((union GCUnion *)((((mode)->value_).gc))))->ts)))))) + sizeof(UTString)), 'v')),
		(weakkey || weakvalue))) {
		((h->marked) &= ((lu_byte)(~((1 << (2))))));
		if (!weakkey)
			traverseweakvalue(g, h);
		else if (!weakvalue)
			traverseephemeron(g, h);
		else
			((h)->gclist = (g->allweak), (g->allweak) = ((&(((union GCUnion *)((h)))->gc))));
	}
	else
		traversestrongtable(g, h);
	return sizeof(Table) + sizeof(TValue) * h->sizearray +
		sizeof(Node) * ((size_t)(((1 << ((h)->lsizenode)))));
}

static int traverseproto(global_State *g, Proto *f) {
	int i;
	if (f->cache && (((f->cache)->marked) & (((1 << (0)) | (1 << (1))))))
		f->cache = ((void *)0);
	{
		if (f->source) {
			if ((((f->source)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((f->source)))->gc))));
		};
	};
	for (i = 0;
		i < f->sizek;
		i++)
	{
		((void)0);
		if (((((&f->k[i])->tt_) & (1 << 6)) && ((((((&f->k[i])->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((&f->k[i])->value_).gc));
	};
	for (i = 0;
		i < f->sizeupvalues;
		i++)
	{
		if (f->upvalues[i].name) {
			if ((((f->upvalues[i].name)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((f->upvalues[i].name)))->gc))));
		};
	};
	for (i = 0;
		i < f->sizep;
		i++)
	{
		if (f->p[i]) {
			if ((((f->p[i])->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((f->p[i])))->gc))));
		};
	};
	for (i = 0;
		i < f->sizelocvars;
		i++)
	{
		if (f->locvars[i].varname) {
			if ((((f->locvars[i].varname)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((f->locvars[i].varname)))->gc))));
		};
	};
	return sizeof(Proto) + sizeof(Instruction) * f->sizecode +
		sizeof(Proto *) * f->sizep +
		sizeof(TValue) * f->sizek +
		sizeof(int) * f->sizelineinfo +
		sizeof(LocVar) * f->sizelocvars +
		sizeof(Upvaldesc) * f->sizeupvalues;
}

static lu_mem traverseCclosure(global_State *g, CClosure *cl) {
	int i;
	for (i = 0;
		i < cl->nupvalues;
		i++)
	{
		((void)0);
		if (((((&cl->upvalue[i])->tt_) & (1 << 6)) && ((((((&cl->upvalue[i])->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((&cl->upvalue[i])->value_).gc));
	};
	return (((int)(sizeof(CClosure))) + ((int)(sizeof(TValue)*((cl->nupvalues) - 1))));
}

static lu_mem traverseLclosure(global_State *g, LClosure *cl) {
	int i;
	{
		if (cl->p) {
			if ((((cl->p)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((cl->p)))->gc))));
		};
	};
	for (i = 0;
		i < cl->nupvalues;
		i++) {
		UpVal *uv = cl->upvals[i];
		if (uv != ((void *)0)) {
			if (((uv)->v != &(uv)->u.value) && g->gcstate != (7 + 1))
				uv->u.open.touched = 1;
			else
			{
				((void)0);
				if (((((uv->v)->tt_) & (1 << 6)) && ((((((uv->v)->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((uv->v)->value_).gc));
			};
		}
	}
	return (((int)(sizeof(LClosure))) + ((int)(sizeof(TValue *)*((cl->nupvalues) - 1))));
}

static lu_mem traversethread(global_State *g, lua_State *th) {
	StkId o = th->stack;
	if (o == ((void *)0))
		return 1;
	((void)0);
	for (;
		o < th->top;
		o++)
	{
		((void)0);
		if (((((o)->tt_) & (1 << 6)) && ((((((o)->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((o)->value_).gc));
	};
	if (g->gcstate == (7 + 1)) {
		StkId lim = th->stack + th->stacksize;
		for (;
			o < lim;
			o++)
			((o)->tt_ = (0));

		if (!(th->twups != th) && th->openupval != ((void *)0)) {
			th->twups = g->twups;
			g->twups = th;
		}
	}
	else if (g->gckind != 1)
		luaD_shrinkstack(th);
	return (sizeof(lua_State) + sizeof(TValue) * th->stacksize +
		sizeof(CallInfo) * th->nci);
}

static void propagatemark(global_State *g) {
	lu_mem size;
	GCObject *o = g->gray;
	((void)0);
	(((o)->marked) |= ((1 << (2))));
	switch (o->tt) {
	case 5: {
		Table *h = (&((((union GCUnion *)((o))))->h));
		g->gray = h->gclist;
		size = traversetable(g, h);
		break;
	}
	case (6 | (0 << 4)) : {
		LClosure *cl = (&((((union GCUnion *)((o))))->cl.l));
		g->gray = cl->gclist;
		size = traverseLclosure(g, cl);
		break;
	}
	case (6 | (2 << 4)) : {
		CClosure *cl = (&((((union GCUnion *)((o))))->cl.c));
		g->gray = cl->gclist;
		size = traverseCclosure(g, cl);
		break;
	}
	case 8: {
		lua_State *th = (&((((union GCUnion *)((o))))->th));
		g->gray = th->gclist;
		((th)->gclist = (g->grayagain), (g->grayagain) = ((&(((union GCUnion *)((th)))->gc))));
		((o->marked) &= ((lu_byte)(~((1 << (2))))));
		size = traversethread(g, th);
		break;
	}
	case 9: {
		Proto *p = (&((((union GCUnion *)((o))))->p));
		g->gray = p->gclist;
		size = traverseproto(g, p);
		break;
	}
	default: ((void)0);
		return;
	}
	g->GCmemtrav += size;
}

static void propagateall(global_State *g) {
	while (g->gray) propagatemark(g);
}

static void convergeephemerons(global_State *g) {
	int changed;
	do {
		GCObject *w;
		GCObject *next = g->ephemeron;
		g->ephemeron = ((void *)0);
		changed = 0;
		while ((w = next) != ((void *)0)) {
			next = (&((((union GCUnion *)((w))))->h))->gclist;
			if (traverseephemeron(g, (&((((union GCUnion *)((w))))->h)))) {
				propagateall(g);
				changed = 1;
			}
		}
	} while (changed);
}

static void clearkeys(global_State *g, GCObject *l, GCObject *f) {
	for (;
		l != f;
		l = (&((((union GCUnion *)((l))))->h))->gclist) {
		Table *h = (&((((union GCUnion *)((l))))->h));
		Node *n, *limit = (&(h)->node[((size_t)(((1 << ((h)->lsizenode)))))]);
		for (n = (&(h)->node[0]);
			n < limit;
			n++) {
			if (!(((((&(n)->i_val)))->tt_) == (0)) && (iscleared(g, ((const TValue*)((&(n)->i_key.tvk)))))) {
				(((&(n)->i_val))->tt_ = (0));
				removeentry(n);
			}
		}
	}
}

static void clearvalues(global_State *g, GCObject *l, GCObject *f) {
	for (;
		l != f;
		l = (&((((union GCUnion *)((l))))->h))->gclist) {
		Table *h = (&((((union GCUnion *)((l))))->h));
		Node *n, *limit = (&(h)->node[((size_t)(((1 << ((h)->lsizenode)))))]);
		unsigned int i;
		for (i = 0;
			i < h->sizearray;
			i++) {
			TValue *o = &h->array[i];
			if (iscleared(g, o))
				((o)->tt_ = (0));
		}
		for (n = (&(h)->node[0]);
			n < limit;
			n++) {
			if (!(((((&(n)->i_val)))->tt_) == (0)) && iscleared(g, (&(n)->i_val))) {
				(((&(n)->i_val))->tt_ = (0));
				removeentry(n);
			}
		}
	}
}

void luaC_upvdeccount(lua_State *L, UpVal *uv) {
	((void)0);
	uv->refcount--;
	if (uv->refcount == 0 && !((uv)->v != &(uv)->u.value))
		luaM_realloc_(L, (uv), sizeof(*(uv)), 0);
}

static void freeLclosure(lua_State *L, LClosure *cl) {
	int i;
	for (i = 0;
		i < cl->nupvalues;
		i++) {
		UpVal *uv = cl->upvals[i];
		if (uv)
			luaC_upvdeccount(L, uv);
	}
	luaM_realloc_(L, (cl), ((((int)(sizeof(LClosure))) + ((int)(sizeof(TValue *)*((cl->nupvalues) - 1))))), 0);
}

static void freeobj(lua_State *L, GCObject *o) {
	switch (o->tt) {
	case 9: luaF_freeproto(L, (&((((union GCUnion *)((o))))->p)));
		break;
	case (6 | (0 << 4)) : {
		freeLclosure(L, (&((((union GCUnion *)((o))))->cl.l)));
		break;
	}
	case (6 | (2 << 4)) : {
		luaM_realloc_(L, (o), ((((int)(sizeof(CClosure))) + ((int)(sizeof(TValue)*(((&((((union GCUnion *)((o))))->cl.c))->nupvalues) - 1))))), 0);
		break;
	}
	case 5: luaH_free(L, (&((((union GCUnion *)((o))))->h)));
		break;
	case 8: luaE_freethread(L, (&((((union GCUnion *)((o))))->th)));
		break;
	case 7: luaM_realloc_(L, (o), ((sizeof(union UUdata) + (((&((((union GCUnion *)((o))))->u)))->len))), 0);
		break;
	case (4 | (0 << 4)) :
		luaS_remove(L, (&((((union GCUnion *)((o))))->ts)));
		luaM_realloc_(L, (o), ((sizeof(union UTString) + (((&((((union GCUnion *)((o))))->ts))->shrlen) + 1) * sizeof(char))), 0);
		break;
	case (4 | (1 << 4)) : {
		luaM_realloc_(L, (o), ((sizeof(union UTString) + (((&((((union GCUnion *)((o))))->ts))->u.lnglen) + 1) * sizeof(char))), 0);
		break;
	}
	default: ((void)0);
	}
}

static GCObject **sweeplist(lua_State *L, GCObject **p, lu_mem count);

static GCObject **sweeplist(lua_State *L, GCObject **p, lu_mem count) {
	global_State *g = (L->l_G);
	int ow = ((g)->currentwhite ^ ((1 << (0)) | (1 << (1))));
	int white = ((lu_byte)((g)->currentwhite & ((1 << (0)) | (1 << (1)))));
	while (*p != ((void *)0) && count-- > 0) {
		GCObject *curr = *p;
		int marked = curr->marked;
		if ((!(((marked) ^ ((1 << (0)) | (1 << (1)))) & (ow)))) {
			*p = curr->next;
			freeobj(L, curr);
		}
		else {
			curr->marked = ((lu_byte)(((marked & (~((1 << (2)) | ((1 << (0)) | (1 << (1)))))) | white)));
			p = &curr->next;
		}
	}
	return (*p == ((void *)0)) ? ((void *)0) : p;
}

static GCObject **sweeptolive(lua_State *L, GCObject **p) {
	GCObject **old = p;
	do {
		p = sweeplist(L, p, 1);
	} while (p == old);
	return p;
}

static void checkSizes(lua_State *L, global_State *g) {
	if (g->gckind != 1) {
		l_mem olddebt = g->GCdebt;
		if (g->strt.nuse < g->strt.size / 4)
			luaS_resize(L, g->strt.size / 2);
		g->GCestimate += g->GCdebt - olddebt;
	}
}

static GCObject *udata2finalize(global_State *g) {
	GCObject *o = g->tobefnz;
	((void)0);
	g->tobefnz = o->next;
	o->next = g->allgc;
	g->allgc = o;
	((o->marked) &= ((lu_byte)(~((1 << (3))))));
	if ((2 <= (g)->gcstate && (g)->gcstate <= 5))
		(o->marked = ((lu_byte)(((o->marked & (~((1 << (2)) | ((1 << (0)) | (1 << (1)))))) | ((lu_byte)((g)->currentwhite & ((1 << (0)) | (1 << (1)))))))));
	return o;
}

static void dothecall(lua_State *L, void *ud) {
	((void)(ud));
	luaD_callnoyield(L, L->top - 2, 0);
}

static void GCTM(lua_State *L, int propagateerrors) {
	global_State *g = (L->l_G);
	const TValue *tm;
	TValue v;
	{
		TValue *io = (&v);
		GCObject *i_g = (udata2finalize(g));
		((io)->value_).gc = i_g;
		((io)->tt_ = (((i_g->tt) | (1 << 6))));
	};
	tm = luaT_gettmbyobj(L, &v, TM_GC);
	if (tm != ((void *)0) && ((((((tm)->tt_)) & 0x0F)) == (6))) {
		int status;
		lu_byte oldah = L->allowhook;
		int running = g->gcrunning;
		L->allowhook = 0;
		g->gcrunning = 0;
		{
			TValue *io1 = (L->top);
			*io1 = *(tm);
			(void)L;
			((void)0);
		};
		{
			TValue *io1 = (L->top + 1);
			*io1 = *(&v);
			(void)L;
			((void)0);
		};
		L->top += 2;
		status = luaD_pcall(L, dothecall, ((void *)0), ((char *)(L->top - 2) - (char *)L->stack), 0);
		L->allowhook = oldah;
		g->gcrunning = running;
		if (status != 0 && propagateerrors) {
			if (status == 2) {
				const char *msg = ((((((((L->top - 1))->tt_)) & 0x0F)) == (4)))
					? (((char *)((((&((((union GCUnion *)((((L->top - 1)->value_).gc))))->ts)))))) + sizeof(UTString))
					: "no message";
				luaO_pushfstring(L, "error in __gc metamethod (%s)", msg);
				status = 5;
			}
			luaD_throw(L, status);
		}
	}
}

static int runafewfinalizers(lua_State *L) {
	global_State *g = (L->l_G);
	unsigned int i;
	((void)0);
	for (i = 0;
		g->tobefnz && i < g->gcfinnum;
		i++)
		GCTM(L, 1);
	g->gcfinnum = (!g->tobefnz) ? 0
		: g->gcfinnum * 2;
	return i;
}

static void callallpendingfinalizers(lua_State *L) {
	global_State *g = (L->l_G);
	while (g->tobefnz)
		GCTM(L, 0);
}

static GCObject **findlast(GCObject **p) {
	while (*p != ((void *)0))
		p = &(*p)->next;
	return p;
}

static void separatetobefnz(global_State *g, int all) {
	GCObject *curr;
	GCObject **p = &g->finobj;
	GCObject **lastnext = findlast(&g->tobefnz);
	while ((curr = *p) != ((void *)0)) {
		((void)0);
		if (!((((curr)->marked) & (((1 << (0)) | (1 << (1))))) || all))
			p = &curr->next;
		else {
			*p = curr->next;
			curr->next = *lastnext;
			*lastnext = curr;
			lastnext = &curr->next;
		}
	}
}

void luaC_checkfinalizer(lua_State *L, GCObject *o, Table *mt) {
	global_State *g = (L->l_G);
	if ((((o)->marked) & ((1 << (3)))) ||
		((mt) == ((void *)0) ? ((void *)0) : ((mt)->flags & (1u << (TM_GC))) ? ((void *)0) : luaT_gettm(mt, TM_GC, (g)->tmname[TM_GC])) == ((void *)0))
		return;
	else {
		GCObject **p;
		if ((2 <= (g)->gcstate && (g)->gcstate <= 5)) {
			(o->marked = ((lu_byte)(((o->marked & (~((1 << (2)) | ((1 << (0)) | (1 << (1)))))) | ((lu_byte)((g)->currentwhite & ((1 << (0)) | (1 << (1)))))))));
			if (g->sweepgc == &o->next)
				g->sweepgc = sweeptolive(L, g->sweepgc);
		}

		for (p = &g->allgc;
			*p != o;
			p = &(*p)->next) {
		}
		*p = o->next;
		o->next = g->finobj;
		g->finobj = o;
		((o->marked) |= ((1 << (3))));
	}
}

static void setpause(global_State *g) {
	l_mem threshold, debt;
	l_mem estimate = g->GCestimate / 100;
	((void)0);
	threshold = (g->gcpause < ((l_mem)(((lu_mem)(~(lu_mem)0)) >> 1)) / estimate)
		? estimate * g->gcpause
		: ((l_mem)(((lu_mem)(~(lu_mem)0)) >> 1));
	debt = ((lu_mem)((g)->totalbytes + (g)->GCdebt)) - threshold;
	luaE_setdebt(g, debt);
}

static void entersweep(lua_State *L) {
	global_State *g = (L->l_G);
	g->gcstate = 2;
	((void)0);
	g->sweepgc = sweeplist(L, &g->allgc, 1);
}

void luaC_freeallobjects(lua_State *L) {
	global_State *g = (L->l_G);
	separatetobefnz(g, 1);
	((void)0);
	callallpendingfinalizers(L);
	((void)0);
	g->currentwhite = ((1 << (0)) | (1 << (1)));
	g->gckind = 0;
	sweeplist(L, &g->finobj, ((lu_mem)(~(lu_mem)0)));
	sweeplist(L, &g->allgc, ((lu_mem)(~(lu_mem)0)));
	sweeplist(L, &g->fixedgc, ((lu_mem)(~(lu_mem)0)));
	((void)0);
}

static l_mem atomic(lua_State *L) {
	global_State *g = (L->l_G);
	l_mem work;
	GCObject *origweak, *origall;
	GCObject *grayagain = g->grayagain;
	((void)0);
	((void)0);
	g->gcstate = (7 + 1);
	g->GCmemtrav = 0;
	{
		if ((((L)->marked) & (((1 << (0)) | (1 << (1)))))) reallymarkobject(g, ((&(((union GCUnion *)((L)))->gc))));
	};

	{
		((void)0);
		if (((((&g->l_registry)->tt_) & (1 << 6)) && ((((((&g->l_registry)->value_).gc))->marked) & (((1 << (0)) | (1 << (1))))))) reallymarkobject(g, (((&g->l_registry)->value_).gc));
	};
	markmt(g);

	remarkupvals(g);
	propagateall(g);
	work = g->GCmemtrav;
	g->gray = grayagain;
	propagateall(g);
	g->GCmemtrav = 0;
	convergeephemerons(g);


	clearvalues(g, g->weak, ((void *)0));
	clearvalues(g, g->allweak, ((void *)0));
	origweak = g->weak;
	origall = g->allweak;
	work += g->GCmemtrav;
	separatetobefnz(g, 0);
	g->gcfinnum = 1;
	markbeingfnz(g);
	propagateall(g);
	g->GCmemtrav = 0;
	convergeephemerons(g);


	clearkeys(g, g->ephemeron, ((void *)0));
	clearkeys(g, g->allweak, ((void *)0));

	clearvalues(g, g->weak, origweak);
	clearvalues(g, g->allweak, origall);
	luaS_clearcache(g);
	g->currentwhite = ((lu_byte)((((g)->currentwhite ^ ((1 << (0)) | (1 << (1)))))));
	work += g->GCmemtrav;
	return work;
}

static lu_mem sweepstep(lua_State *L, global_State *g,
	int nextstate, GCObject **nextlist) {
	if (g->sweepgc) {
		l_mem olddebt = g->GCdebt;
		g->sweepgc = sweeplist(L, g->sweepgc, (((int)((((((int)((100 * sizeof(TString))))) / ((sizeof(TString) + 4) / 4)) / 4)))));
		g->GCestimate += g->GCdebt - olddebt;
		if (g->sweepgc)
			return ((((int)((((((int)((100 * sizeof(TString))))) / ((sizeof(TString) + 4) / 4)) / 4)))) * ((sizeof(TString) + 4) / 4));
	}

	g->gcstate = nextstate;
	g->sweepgc = nextlist;
	return 0;
}

static lu_mem singlestep(lua_State *L) {
	global_State *g = (L->l_G);
	switch (g->gcstate) {
	case 7: {
		g->GCmemtrav = g->strt.size * sizeof(GCObject*);
		restartcollection(g);
		g->gcstate = 0;
		return g->GCmemtrav;
	}
	case 0: {
		g->GCmemtrav = 0;
		((void)0);
		propagatemark(g);
		if (g->gray == ((void *)0))
			g->gcstate = 1;
		return g->GCmemtrav;
	}
	case 1: {
		lu_mem work;
		propagateall(g);
		work = atomic(L);
		entersweep(L);
		g->GCestimate = ((lu_mem)((g)->totalbytes + (g)->GCdebt));
		;
		return work;
	}
	case 2: {
		return sweepstep(L, g, 3, &g->finobj);
	}
	case 3: {
		return sweepstep(L, g, 4, &g->tobefnz);
	}
	case 4: {
		return sweepstep(L, g, 5, ((void *)0));
	}
	case 5: {
		(g->mainthread->marked = ((lu_byte)(((g->mainthread->marked & (~((1 << (2)) | ((1 << (0)) | (1 << (1)))))) | ((lu_byte)((g)->currentwhite & ((1 << (0)) | (1 << (1)))))))));
		checkSizes(L, g);
		g->gcstate = 6;
		return 0;
	}
	case 6: {
		if (g->tobefnz && g->gckind != 1) {
			int n = runafewfinalizers(L);
			return (n * ((sizeof(TString) + 4) / 4));
		}
		else {
			g->gcstate = 7;
			return 0;
		}
	}
	default: ((void)0);
		return 0;
	}
}

void luaC_runtilstate(lua_State *L, int statesmask) {
	global_State *g = (L->l_G);
	while (!((statesmask)& ((1 << (g->gcstate)))))
		singlestep(L);
}

static l_mem getdebt(global_State *g) {
	l_mem debt = g->GCdebt;
	int stepmul = g->gcstepmul;
	if (debt <= 0) return 0;
	else {
		debt = (debt / 200) + 1;
		debt = (debt < ((l_mem)(((lu_mem)(~(lu_mem)0)) >> 1)) / stepmul) ? debt * stepmul : ((l_mem)(((lu_mem)(~(lu_mem)0)) >> 1));
		return debt;
	}
}

void luaC_step(lua_State *L) {
	global_State *g = (L->l_G);
	l_mem debt = getdebt(g);
	if (!g->gcrunning) {
		luaE_setdebt(g, -(((int)((100 * sizeof(TString))))) * 10);
		return;
	}
	do {
		lu_mem work = singlestep(L);
		debt -= work;
	} while (debt > -(((int)((100 * sizeof(TString))))) && g->gcstate != 7);
	if (g->gcstate == 7)
		setpause(g);
	else {
		debt = (debt / g->gcstepmul) * 200;
		luaE_setdebt(g, debt);
		runafewfinalizers(L);
	}
}

void luaC_fullgc(lua_State *L, int isemergency) {
	global_State *g = (L->l_G);
	((void)0);
	if (isemergency) g->gckind = 1;
	if (((g)->gcstate <= 1)) {
		entersweep(L);
	}

	luaC_runtilstate(L, (1 << (7)));
	luaC_runtilstate(L, ~(1 << (7)));
	luaC_runtilstate(L, (1 << (6)));

	((void)0);
	luaC_runtilstate(L, (1 << (7)));
	g->gckind = 0;
	setpause(g);
}

