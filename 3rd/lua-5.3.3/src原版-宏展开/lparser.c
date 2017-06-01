
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

typedef struct BlockCnt {
	struct BlockCnt *previous;
	int firstlabel;
	int firstgoto;
	lu_byte nactvar;
	lu_byte upval;
	lu_byte isloop;
} BlockCnt;

static void statement(LexState *ls);
static void expr(LexState *ls, expdesc *v);

static void __declspec(noreturn) semerror(LexState *ls, const char *msg) {
	ls->t.token = 0;
	luaX_syntaxerror(ls, msg);
}

static void __declspec(noreturn) error_expected(LexState *ls, int token) {
	luaX_syntaxerror(ls,
		luaO_pushfstring(ls->L, "%s expected", luaX_token2str(ls, token)));
}

static void __declspec(noreturn) errorlimit(FuncState *fs, int limit, const char *what) {
	lua_State *L = fs->ls->L;
	const char *msg;
	int line = fs->f->linedefined;
	const char *where = (line == 0)
		? "main function"
		: luaO_pushfstring(L, "function at line %d", line);
	msg = luaO_pushfstring(L, "too many %s (limit is %d) in %s",
		what, limit, where);
	luaX_syntaxerror(fs->ls, msg);
}

static void checklimit(FuncState *fs, int v, int l, const char *what) {
	if (v > l) errorlimit(fs, l, what);
}

static int testnext(LexState *ls, int c) {
	if (ls->t.token == c) {
		luaX_next(ls);
		return 1;
	}
	else return 0;
}

static void check(LexState *ls, int c) {
	if (ls->t.token != c)
		error_expected(ls, c);
}

static void checknext(LexState *ls, int c) {
	check(ls, c);
	luaX_next(ls);
}

static void check_match(LexState *ls, int what, int who, int where) {
	if (!testnext(ls, what)) {
		if (where == ls->linenumber)
			error_expected(ls, what);
		else {
			luaX_syntaxerror(ls, luaO_pushfstring(ls->L,
				"%s expected (to close %s at line %d)",
				luaX_token2str(ls, what), luaX_token2str(ls, who), where));
		}
	}
}

static TString *str_checkname(LexState *ls) {
	TString *ts;
	check(ls, TK_NAME);
	ts = ls->t.seminfo.ts;
	luaX_next(ls);
	return ts;
}

static void init_exp(expdesc *e, expkind k, int i) {
	e->f = e->t = (-1);
	e->k = k;
	e->u.info = i;
}

static void codestring(LexState *ls, expdesc *e, TString *s) {
	init_exp(e, VK, luaK_stringK(ls->fs, s));
}

static void checkname(LexState *ls, expdesc *e) {
	codestring(ls, e, str_checkname(ls));
}

static int registerlocalvar(LexState *ls, TString *varname) {
	FuncState *fs = ls->fs;
	Proto *f = fs->f;
	int oldsize = f->sizelocvars;
	if ((fs->nlocvars) + 1 > (f->sizelocvars)) ((f->locvars) = ((LocVar *)(luaM_growaux_(ls->L, f->locvars, &(f->sizelocvars), sizeof(LocVar), 32767, "local variables"))));
	while (oldsize < f->sizelocvars)
		f->locvars[oldsize++].varname = ((void *)0);
	f->locvars[fs->nlocvars].varname = varname;
	(((((f)->marked) & ((1 << (2)))) && (((varname)->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(ls->L, ((&(((union GCUnion *)((f)))->gc))), ((&(((union GCUnion *)((varname)))->gc)))) : ((void)((0))));
	return fs->nlocvars++;
}

static void new_localvar(LexState *ls, TString *name) {
	FuncState *fs = ls->fs;
	Dyndata *dyd = ls->dyd;
	int reg = registerlocalvar(ls, name);
	checklimit(fs, dyd->actvar.n + 1 - fs->firstlocal,
		200, "local variables");
	if ((dyd->actvar.n + 1) + 1 > (dyd->actvar.size)) ((dyd->actvar.arr) = ((Vardesc *)(luaM_growaux_(ls->L, dyd->actvar.arr, &(dyd->actvar.size), sizeof(Vardesc), 2147483647, "local variables"))));
	dyd->actvar.arr[dyd->actvar.n++].idx = ((short)(reg));
}

static void new_localvarliteral_(LexState *ls, const char *name, size_t sz) {
	new_localvar(ls, luaX_newstring(ls, name, sz));
}

static LocVar *getlocvar(FuncState *fs, int i) {
	int idx = fs->ls->dyd->actvar.arr[fs->firstlocal + i].idx;
	((void)0);
	return &fs->f->locvars[idx];
}

static void adjustlocalvars(LexState *ls, int nvars) {
	FuncState *fs = ls->fs;
	fs->nactvar = ((lu_byte)((fs->nactvar + nvars)));
	for (;
		nvars;
		nvars--) {
		getlocvar(fs, fs->nactvar - nvars)->startpc = fs->pc;
	}
}

static void removevars(FuncState *fs, int tolevel) {
	fs->ls->dyd->actvar.n -= (fs->nactvar - tolevel);
	while (fs->nactvar > tolevel)
		getlocvar(fs, --fs->nactvar)->endpc = fs->pc;
}

static int searchupvalue(FuncState *fs, TString *name) {
	int i;
	Upvaldesc *up = fs->f->upvalues;
	for (i = 0;
		i < fs->nups;
		i++) {
		if (((up[i].name) == (name))) return i;
	}
	return -1;
}

static int newupvalue(FuncState *fs, TString *name, expdesc *v) {
	Proto *f = fs->f;
	int oldsize = f->sizeupvalues;
	checklimit(fs, fs->nups + 1, 255, "upvalues");
	if ((fs->nups) + 1 > (f->sizeupvalues)) ((f->upvalues) = ((Upvaldesc *)(luaM_growaux_(fs->ls->L, f->upvalues, &(f->sizeupvalues), sizeof(Upvaldesc), 255, "upvalues"))));
	while (oldsize < f->sizeupvalues)
		f->upvalues[oldsize++].name = ((void *)0);
	f->upvalues[fs->nups].instack = (v->k == VLOCAL);
	f->upvalues[fs->nups].idx = ((lu_byte)((v->u.info)));
	f->upvalues[fs->nups].name = name;
	(((((f)->marked) & ((1 << (2)))) && (((name)->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(fs->ls->L, ((&(((union GCUnion *)((f)))->gc))), ((&(((union GCUnion *)((name)))->gc)))) : ((void)((0))));
	return fs->nups++;
}

static int searchvar(FuncState *fs, TString *n) {
	int i;
	for (i = ((int)((fs->nactvar))) - 1;
		i >= 0;
		i--) {
		if (((n) == (getlocvar(fs, i)->varname)))
			return i;
	}
	return -1;
}

static void markupval(FuncState *fs, int level) {
	BlockCnt *bl = fs->bl;
	while (bl->nactvar > level)
		bl = bl->previous;
	bl->upval = 1;
}

static void singlevaraux(FuncState *fs, TString *n, expdesc *var, int base) {
	if (fs == ((void *)0))
		init_exp(var, VVOID, 0);
	else {
		int v = searchvar(fs, n);
		if (v >= 0) {
			init_exp(var, VLOCAL, v);
			if (!base)
				markupval(fs, v);
		}
		else {
			int idx = searchupvalue(fs, n);
			if (idx < 0) {
				singlevaraux(fs->prev, n, var, 0);
				if (var->k == VVOID)
					return;

				idx = newupvalue(fs, n, var);
			}
			init_exp(var, VUPVAL, idx);
		}
	}
}

static void singlevar(LexState *ls, expdesc *var) {
	TString *varname = str_checkname(ls);
	FuncState *fs = ls->fs;
	singlevaraux(fs, varname, var, 1);
	if (var->k == VVOID) {
		expdesc key;
		singlevaraux(fs, ls->envn, var, 1);
		((void)0);
		codestring(ls, &key, varname);
		luaK_indexed(fs, var, &key);
	}
}

static void adjust_assign(LexState *ls, int nvars, int nexps, expdesc *e) {
	FuncState *fs = ls->fs;
	int extra = nvars - nexps;
	if (((e->k) == VCALL || (e->k) == VVARARG)) {
		extra++;
		if (extra < 0) extra = 0;
		luaK_setreturns(fs, e, extra);
		if (extra > 1) luaK_reserveregs(fs, extra - 1);
	}
	else {
		if (e->k != VVOID) luaK_exp2nextreg(fs, e);
		if (extra > 0) {
			int reg = fs->freereg;
			luaK_reserveregs(fs, extra);
			luaK_nil(fs, reg, extra);
		}
	}
}

static void enterlevel(LexState *ls) {
	lua_State *L = ls->L;
	++L->nCcalls;
	checklimit(ls->fs, L->nCcalls, 200, "C levels");
}

static void closegoto(LexState *ls, int g, Labeldesc *label) {
	int i;
	FuncState *fs = ls->fs;
	Labellist *gl = &ls->dyd->gt;
	Labeldesc *gt = &gl->arr[g];
	((void)0);
	if (gt->nactvar < label->nactvar) {
		TString *vname = getlocvar(fs, gt->nactvar)->varname;
		const char *msg = luaO_pushfstring(ls->L,
			"<goto %s> at line %d jumps into the scope of local '%s'",
			(((char *)((gt->name))) + sizeof(UTString)), gt->line, (((char *)((vname))) + sizeof(UTString)));
		semerror(ls, msg);
	}
	luaK_patchlist(fs, gt->pc, label->pc);

	for (i = g;
		i < gl->n - 1;
		i++)
		gl->arr[i] = gl->arr[i + 1];
	gl->n--;
}

static int findlabel(LexState *ls, int g) {
	int i;
	BlockCnt *bl = ls->fs->bl;
	Dyndata *dyd = ls->dyd;
	Labeldesc *gt = &dyd->gt.arr[g];

	for (i = bl->firstlabel;
		i < dyd->label.n;
		i++) {
		Labeldesc *lb = &dyd->label.arr[i];
		if (((lb->name) == (gt->name))) {
			if (gt->nactvar > lb->nactvar &&
				(bl->upval || dyd->label.n > bl->firstlabel))
				luaK_patchclose(ls->fs, gt->pc, lb->nactvar);
			closegoto(ls, g, lb);
			return 1;
		}
	}
	return 0;
}

static int newlabelentry(LexState *ls, Labellist *l, TString *name,
	int line, int pc) {
	int n = l->n;
	if ((n)+1 > (l->size)) ((l->arr) = ((Labeldesc *)(luaM_growaux_(ls->L, l->arr, &(l->size), sizeof(Labeldesc), 32767, "labels/gotos"))));
	l->arr[n].name = name;
	l->arr[n].line = line;
	l->arr[n].nactvar = ls->fs->nactvar;
	l->arr[n].pc = pc;
	l->n = n + 1;
	return n;
}

static void findgotos(LexState *ls, Labeldesc *lb) {
	Labellist *gl = &ls->dyd->gt;
	int i = ls->fs->bl->firstgoto;
	while (i < gl->n) {
		if (((gl->arr[i].name) == (lb->name)))
			closegoto(ls, i, lb);
		else
			i++;
	}
}

static void movegotosout(FuncState *fs, BlockCnt *bl) {
	int i = bl->firstgoto;
	Labellist *gl = &fs->ls->dyd->gt;

	while (i < gl->n) {
		Labeldesc *gt = &gl->arr[i];
		if (gt->nactvar > bl->nactvar) {
			if (bl->upval)
				luaK_patchclose(fs, gt->pc, bl->nactvar);
			gt->nactvar = bl->nactvar;
		}
		if (!findlabel(fs->ls, i))
			i++;
	}
}

static void enterblock(FuncState *fs, BlockCnt *bl, lu_byte isloop) {
	bl->isloop = isloop;
	bl->nactvar = fs->nactvar;
	bl->firstlabel = fs->ls->dyd->label.n;
	bl->firstgoto = fs->ls->dyd->gt.n;
	bl->upval = 0;
	bl->previous = fs->bl;
	fs->bl = bl;
	((void)0);
}

static void breaklabel(LexState *ls) {
	TString *n = luaS_new(ls->L, "break");
	int l = newlabelentry(ls, &ls->dyd->label, n, 0, ls->fs->pc);
	findgotos(ls, &ls->dyd->label.arr[l]);
}

static void __declspec(noreturn) undefgoto(LexState *ls, Labeldesc *gt) {
	const char *msg = ((gt->name)->tt == (4 | (0 << 4)) && (gt->name)->extra > 0)
		? "<%s> at line %d not inside a loop"
		: "no visible label '%s' for <goto> at line %d";
	msg = luaO_pushfstring(ls->L, msg, (((char *)((gt->name))) + sizeof(UTString)), gt->line);
	semerror(ls, msg);
}

static void leaveblock(FuncState *fs) {
	BlockCnt *bl = fs->bl;
	LexState *ls = fs->ls;
	if (bl->previous && bl->upval) {

		int j = luaK_jump(fs);
		luaK_patchclose(fs, j, bl->nactvar);
		luaK_patchtohere(fs, j);
	}
	if (bl->isloop)
		breaklabel(ls);
	fs->bl = bl->previous;
	removevars(fs, bl->nactvar);
	((void)0);
	fs->freereg = fs->nactvar;
	ls->dyd->label.n = bl->firstlabel;
	if (bl->previous)
		movegotosout(fs, bl);
	else if (bl->firstgoto < ls->dyd->gt.n)
		undefgoto(ls, &ls->dyd->gt.arr[bl->firstgoto]);
}

static Proto *addprototype(LexState *ls) {
	Proto *clp;
	lua_State *L = ls->L;
	FuncState *fs = ls->fs;
	Proto *f = fs->f;
	if (fs->np >= f->sizep) {
		int oldsize = f->sizep;
		if ((fs->np) + 1 > (f->sizep)) ((f->p) = ((Proto * *)(luaM_growaux_(L, f->p, &(f->sizep), sizeof(Proto *), ((1 << (9 + 9)) - 1), "functions"))));
		while (oldsize < f->sizep)
			f->p[oldsize++] = ((void *)0);
	}
	f->p[fs->np++] = clp = luaF_newproto(L);
	(((((f)->marked) & ((1 << (2)))) && (((clp)->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(L, ((&(((union GCUnion *)((f)))->gc))), ((&(((union GCUnion *)((clp)))->gc)))) : ((void)((0))));
	return clp;
}

static void codeclosure(LexState *ls, expdesc *v) {
	FuncState *fs = ls->fs->prev;
	init_exp(v, VRELOCABLE, luaK_codeABx(fs, OP_CLOSURE, 0, fs->np - 1));
	luaK_exp2nextreg(fs, v);
}

static void open_func(LexState *ls, FuncState *fs, BlockCnt *bl) {
	Proto *f;
	fs->prev = ls->fs;
	fs->ls = ls;
	ls->fs = fs;
	fs->pc = 0;
	fs->lasttarget = 0;
	fs->jpc = (-1);
	fs->freereg = 0;
	fs->nk = 0;
	fs->np = 0;
	fs->nups = 0;
	fs->nlocvars = 0;
	fs->nactvar = 0;
	fs->firstlocal = ls->dyd->actvar.n;
	fs->bl = ((void *)0);
	f = fs->f;
	f->source = ls->source;
	f->maxstacksize = 2;
	enterblock(fs, bl, 0);
}

static void close_func(LexState *ls) {
	lua_State *L = ls->L;
	FuncState *fs = ls->fs;
	Proto *f = fs->f;
	luaK_ret(fs, 0, 0);
	leaveblock(fs);
	((f->code) = ((Instruction *)((((sizeof(fs->pc) >= sizeof(size_t) && ((size_t)((fs->pc))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(Instruction))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (f->code), (f->sizecode)*(sizeof(Instruction)), (fs->pc)*(sizeof(Instruction)))))));
	f->sizecode = fs->pc;
	((f->lineinfo) = ((int *)((((sizeof(fs->pc) >= sizeof(size_t) && ((size_t)((fs->pc))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(int))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (f->lineinfo), (f->sizelineinfo)*(sizeof(int)), (fs->pc)*(sizeof(int)))))));
	f->sizelineinfo = fs->pc;
	((f->k) = ((TValue *)((((sizeof(fs->nk) >= sizeof(size_t) && ((size_t)((fs->nk))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(TValue))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (f->k), (f->sizek)*(sizeof(TValue)), (fs->nk)*(sizeof(TValue)))))));
	f->sizek = fs->nk;
	((f->p) = ((Proto * *)((((sizeof(fs->np) >= sizeof(size_t) && ((size_t)((fs->np))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(Proto *))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (f->p), (f->sizep)*(sizeof(Proto *)), (fs->np)*(sizeof(Proto *)))))));
	f->sizep = fs->np;
	((f->locvars) = ((LocVar *)((((sizeof(fs->nlocvars) >= sizeof(size_t) && ((size_t)((fs->nlocvars))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(LocVar))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (f->locvars), (f->sizelocvars)*(sizeof(LocVar)), (fs->nlocvars)*(sizeof(LocVar)))))));
	f->sizelocvars = fs->nlocvars;
	((f->upvalues) = ((Upvaldesc *)((((sizeof(fs->nups) >= sizeof(size_t) && ((size_t)((fs->nups))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(Upvaldesc))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (f->upvalues), (f->sizeupvalues)*(sizeof(Upvaldesc)), (fs->nups)*(sizeof(Upvaldesc)))))));
	f->sizeupvalues = fs->nups;
	((void)0);
	ls->fs = fs->prev;
	{
		if ((L->l_G)->GCdebt > 0) {
			(void)0;
			luaC_step(L);
			(void)0;
		};
		((void)0);
	};
}

static int block_follow(LexState *ls, int withuntil) {
	switch (ls->t.token) {
	case TK_ELSE: case TK_ELSEIF:
	case TK_END: case TK_EOS:
		return 1;
	case TK_UNTIL: return withuntil;
	default: return 0;
	}
}

static void statlist(LexState *ls) {

	while (!block_follow(ls, 1)) {
		if (ls->t.token == TK_RETURN) {
			statement(ls);
			return;
		}
		statement(ls);
	}
}

static void fieldsel(LexState *ls, expdesc *v) {

	FuncState *fs = ls->fs;
	expdesc key;
	luaK_exp2anyregup(fs, v);
	luaX_next(ls);
	checkname(ls, &key);
	luaK_indexed(fs, v, &key);
}

static void yindex(LexState *ls, expdesc *v) {

	luaX_next(ls);
	expr(ls, v);
	luaK_exp2val(ls->fs, v);
	checknext(ls, ']');
}

struct ConsControl {
	expdesc v;
	expdesc *t;
	int nh;
	int na;
	int tostore;
};

static void recfield(LexState *ls, struct ConsControl *cc) {

	FuncState *fs = ls->fs;
	int reg = ls->fs->freereg;
	expdesc key, val;
	int rkkey;
	if (ls->t.token == TK_NAME) {
		checklimit(fs, cc->nh, 2147483647, "items in a constructor");
		checkname(ls, &key);
	}
	else
		yindex(ls, &key);
	cc->nh++;
	checknext(ls, '=');
	rkkey = luaK_exp2RK(fs, &key);
	expr(ls, &val);
	luaK_codeABC(fs, OP_SETTABLE, cc->t->u.info, rkkey, luaK_exp2RK(fs, &val));
	fs->freereg = reg;
}

static void closelistfield(FuncState *fs, struct ConsControl *cc) {
	if (cc->v.k == VVOID) return;
	luaK_exp2nextreg(fs, &cc->v);
	cc->v.k = VVOID;
	if (cc->tostore == 50) {
		luaK_setlist(fs, cc->t->u.info, cc->na, cc->tostore);
		cc->tostore = 0;
	}
}

static void lastlistfield(FuncState *fs, struct ConsControl *cc) {
	if (cc->tostore == 0) return;
	if (((cc->v.k) == VCALL || (cc->v.k) == VVARARG)) {
		luaK_setreturns(fs, &cc->v, (-1));
		luaK_setlist(fs, cc->t->u.info, cc->na, (-1));
		cc->na--;
	}
	else {
		if (cc->v.k != VVOID)
			luaK_exp2nextreg(fs, &cc->v);
		luaK_setlist(fs, cc->t->u.info, cc->na, cc->tostore);
	}
}

static void listfield(LexState *ls, struct ConsControl *cc) {

	expr(ls, &cc->v);
	checklimit(ls->fs, cc->na, 2147483647, "items in a constructor");
	cc->na++;
	cc->tostore++;
}

static void field(LexState *ls, struct ConsControl *cc) {

	switch (ls->t.token) {
	case TK_NAME: {
		if (luaX_lookahead(ls) != '=')
			listfield(ls, cc);
		else
			recfield(ls, cc);
		break;
	}
	case '[': {
		recfield(ls, cc);
		break;
	}
	default: {
		listfield(ls, cc);
		break;
	}
	}
}

static void constructor(LexState *ls, expdesc *t) {

	FuncState *fs = ls->fs;
	int line = ls->linenumber;
	int pc = luaK_codeABC(fs, OP_NEWTABLE, 0, 0, 0);
	struct ConsControl cc;
	cc.na = cc.nh = cc.tostore = 0;
	cc.t = t;
	init_exp(t, VRELOCABLE, pc);
	init_exp(&cc.v, VVOID, 0);
	luaK_exp2nextreg(ls->fs, t);
	checknext(ls, '{');
	do {
		((void)0);
		if (ls->t.token == '}') break;
		closelistfield(fs, &cc);
		field(ls, &cc);
	} while (testnext(ls, ',') || testnext(ls, ';'));
	check_match(ls, '}', '{', line);
	lastlistfield(fs, &cc);
	((fs->f->code[pc]) = (((fs->f->code[pc])&(~((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))) | ((((Instruction)(luaO_int2fb(cc.na))) << (((0 + 6) + 8) + 9))&((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))));
	((fs->f->code[pc]) = (((fs->f->code[pc])&(~((~((~(Instruction)0) << (9))) << (((0 + 6) + 8))))) | ((((Instruction)(luaO_int2fb(cc.nh))) << ((0 + 6) + 8))&((~((~(Instruction)0) << (9))) << (((0 + 6) + 8))))));
}

static void parlist(LexState *ls) {

	FuncState *fs = ls->fs;
	Proto *f = fs->f;
	int nparams = 0;
	f->is_vararg = 0;
	if (ls->t.token != ')') {
		do {
			switch (ls->t.token) {
			case TK_NAME: {
				new_localvar(ls, str_checkname(ls));
				nparams++;
				break;
			}
			case TK_DOTS: {
				luaX_next(ls);
				f->is_vararg = 2;
				break;
			}
			default: luaX_syntaxerror(ls, "<name> or '...' expected");
			}
		} while (!f->is_vararg && testnext(ls, ','));
	}
	adjustlocalvars(ls, nparams);
	f->numparams = ((lu_byte)((fs->nactvar)));
	luaK_reserveregs(fs, fs->nactvar);
}

static void body(LexState *ls, expdesc *e, int ismethod, int line) {

	FuncState new_fs;
	BlockCnt bl;
	new_fs.f = addprototype(ls);
	new_fs.f->linedefined = line;
	open_func(ls, &new_fs, &bl);
	checknext(ls, '(');
	if (ismethod) {
		new_localvarliteral_(ls, "" "self", (sizeof("self") / sizeof(char)) - 1);
		adjustlocalvars(ls, 1);
	}
	parlist(ls);
	checknext(ls, ')');
	statlist(ls);
	new_fs.f->lastlinedefined = ls->linenumber;
	check_match(ls, TK_END, TK_FUNCTION, line);
	codeclosure(ls, e);
	close_func(ls);
}

static int explist(LexState *ls, expdesc *v) {

	int n = 1;
	expr(ls, v);
	while (testnext(ls, ',')) {
		luaK_exp2nextreg(ls->fs, v);
		expr(ls, v);
		n++;
	}
	return n;
}

static void funcargs(LexState *ls, expdesc *f, int line) {
	FuncState *fs = ls->fs;
	expdesc args;
	int base, nparams;
	switch (ls->t.token) {
	case '(': {
		luaX_next(ls);
		if (ls->t.token == ')')
			args.k = VVOID;
		else {
			explist(ls, &args);
			luaK_setreturns(fs, &args, (-1));
		}
		check_match(ls, ')', '(', line);
		break;
	}
	case '{': {
		constructor(ls, &args);
		break;
	}
	case TK_STRING: {
		codestring(ls, &args, ls->t.seminfo.ts);
		luaX_next(ls);
		break;
	}
	default: {
		luaX_syntaxerror(ls, "function arguments expected");
	}
	}
	((void)0);
	base = f->u.info;
	if (((args.k) == VCALL || (args.k) == VVARARG))
		nparams = (-1);
	else {
		if (args.k != VVOID)
			luaK_exp2nextreg(fs, &args);
		nparams = fs->freereg - (base + 1);
	}
	init_exp(f, VCALL, luaK_codeABC(fs, OP_CALL, base, nparams + 1, 2));
	luaK_fixline(fs, line);
	fs->freereg = base + 1;

}

static void primaryexp(LexState *ls, expdesc *v) {

	switch (ls->t.token) {
	case '(': {
		int line = ls->linenumber;
		luaX_next(ls);
		expr(ls, v);
		check_match(ls, ')', '(', line);
		luaK_dischargevars(ls->fs, v);
		return;
	}
	case TK_NAME: {
		singlevar(ls, v);
		return;
	}
	default: {
		luaX_syntaxerror(ls, "unexpected symbol");
	}
	}
}

static void suffixedexp(LexState *ls, expdesc *v) {

	FuncState *fs = ls->fs;
	int line = ls->linenumber;
	primaryexp(ls, v);
	for (;
		;
		) {
		switch (ls->t.token) {
		case '.': {
			fieldsel(ls, v);
			break;
		}
		case '[': {
			expdesc key;
			luaK_exp2anyregup(fs, v);
			yindex(ls, &key);
			luaK_indexed(fs, v, &key);
			break;
		}
		case ':': {
			expdesc key;
			luaX_next(ls);
			checkname(ls, &key);
			luaK_self(fs, v, &key);
			funcargs(ls, v, line);
			break;
		}
		case '(': case TK_STRING: case '{': {
			luaK_exp2nextreg(fs, v);
			funcargs(ls, v, line);
			break;
		}
		default: return;
		}
	}
}

static void simpleexp(LexState *ls, expdesc *v) {

	switch (ls->t.token) {
	case TK_FLT: {
		init_exp(v, VKFLT, 0);
		v->u.nval = ls->t.seminfo.r;
		break;
	}
	case TK_INT: {
		init_exp(v, VKINT, 0);
		v->u.ival = ls->t.seminfo.i;
		break;
	}
	case TK_STRING: {
		codestring(ls, v, ls->t.seminfo.ts);
		break;
	}
	case TK_NIL: {
		init_exp(v, VNIL, 0);
		break;
	}
	case TK_TRUE: {
		init_exp(v, VTRUE, 0);
		break;
	}
	case TK_FALSE: {
		init_exp(v, VFALSE, 0);
		break;
	}
	case TK_DOTS: {
		FuncState *fs = ls->fs;
		{
			if (!(fs->f->is_vararg)) luaX_syntaxerror(ls, "cannot use '...' outside a vararg function");
		};
		fs->f->is_vararg = 1;
		init_exp(v, VVARARG, luaK_codeABC(fs, OP_VARARG, 0, 1, 0));
		break;
	}
	case '{': {
		constructor(ls, v);
		return;
	}
	case TK_FUNCTION: {
		luaX_next(ls);
		body(ls, v, 0, ls->linenumber);
		return;
	}
	default: {
		suffixedexp(ls, v);
		return;
	}
	}
	luaX_next(ls);
}

static UnOpr getunopr(int op) {
	switch (op) {
	case TK_NOT: return OPR_NOT;
	case '-': return OPR_MINUS;
	case '~': return OPR_BNOT;
	case '#': return OPR_LEN;
	default: return OPR_NOUNOPR;
	}
}

static BinOpr getbinopr(int op) {
	switch (op) {
	case '+': return OPR_ADD;
	case '-': return OPR_SUB;
	case '*': return OPR_MUL;
	case '%': return OPR_MOD;
	case '^': return OPR_POW;
	case '/': return OPR_DIV;
	case TK_IDIV: return OPR_IDIV;
	case '&': return OPR_BAND;
	case '|': return OPR_BOR;
	case '~': return OPR_BXOR;
	case TK_SHL: return OPR_SHL;
	case TK_SHR: return OPR_SHR;
	case TK_CONCAT: return OPR_CONCAT;
	case TK_NE: return OPR_NE;
	case TK_EQ: return OPR_EQ;
	case '<': return OPR_LT;
	case TK_LE: return OPR_LE;
	case '>': return OPR_GT;
	case TK_GE: return OPR_GE;
	case TK_AND: return OPR_AND;
	case TK_OR: return OPR_OR;
	default: return OPR_NOBINOPR;
	}
}

static const struct {
	lu_byte left;
	lu_byte right;
} priority[] = {
		{
			10, 10
		}, {
			10, 10
		},
		{
			11, 11
		}, {
			11, 11
		},
		{
			14, 13
		},
		{
			11, 11
		}, {
			11, 11
		},
		{
			6, 6
		}, {
			4, 4
		}, {
			5, 5
		},
		{
			7, 7
		}, {
			7, 7
		},
		{
			9, 8
		},
		{
			3, 3
		}, {
			3, 3
		}, {
			3, 3
		},
		{
			3, 3
		}, {
			3, 3
		}, {
			3, 3
		},
		{
			2, 2
		}, {
			1, 1 }
};

static BinOpr subexpr(LexState *ls, expdesc *v, int limit) {
	BinOpr op;
	UnOpr uop;
	enterlevel(ls);
	uop = getunopr(ls->t.token);
	if (uop != OPR_NOUNOPR) {
		int line = ls->linenumber;
		luaX_next(ls);
		subexpr(ls, v, 12);
		luaK_prefix(ls->fs, uop, v, line);
	}
	else simpleexp(ls, v);

	op = getbinopr(ls->t.token);
	while (op != OPR_NOBINOPR && priority[op].left > limit) {
		expdesc v2;
		BinOpr nextop;
		int line = ls->linenumber;
		luaX_next(ls);
		luaK_infix(ls->fs, op, v);

		nextop = subexpr(ls, &v2, priority[op].right);
		luaK_posfix(ls->fs, op, v, &v2, line);
		op = nextop;
	}
	((ls)->L->nCcalls--);
	return op;
}

static void expr(LexState *ls, expdesc *v) {
	subexpr(ls, v, 0);
}

static void block(LexState *ls) {

	FuncState *fs = ls->fs;
	BlockCnt bl;
	enterblock(fs, &bl, 0);
	statlist(ls);
	leaveblock(fs);
}

struct LHS_assign {
	struct LHS_assign *prev;
	expdesc v;
};

static void check_conflict(LexState *ls, struct LHS_assign *lh, expdesc *v) {
	FuncState *fs = ls->fs;
	int extra = fs->freereg;
	int conflict = 0;
	for (;
		lh;
		lh = lh->prev) {
		if (lh->v.k == VINDEXED) {

			if (lh->v.u.ind.vt == v->k && lh->v.u.ind.t == v->u.info) {
				conflict = 1;
				lh->v.u.ind.vt = VLOCAL;
				lh->v.u.ind.t = extra;
			}

			if (v->k == VLOCAL && lh->v.u.ind.idx == v->u.info) {
				conflict = 1;
				lh->v.u.ind.idx = extra;
			}
		}
	}
	if (conflict) {

		OpCode op = (v->k == VLOCAL) ? OP_MOVE : OP_GETUPVAL;
		luaK_codeABC(fs, op, extra, v->u.info, 0);
		luaK_reserveregs(fs, 1);
	}
}

static void assignment(LexState *ls, struct LHS_assign *lh, int nvars) {
	expdesc e;
	{
		if (!((VLOCAL <= (lh->v.k) && (lh->v.k) <= VINDEXED))) luaX_syntaxerror(ls, "syntax error");
	};
	if (testnext(ls, ',')) {
		struct LHS_assign nv;
		nv.prev = lh;
		suffixedexp(ls, &nv.v);
		if (nv.v.k != VINDEXED)
			check_conflict(ls, lh, &nv.v);
		checklimit(ls->fs, nvars + ls->L->nCcalls, 200,
			"C levels");
		assignment(ls, &nv, nvars + 1);
	}
	else {
		int nexps;
		checknext(ls, '=');
		nexps = explist(ls, &e);
		if (nexps != nvars) {
			adjust_assign(ls, nvars, nexps, &e);
			if (nexps > nvars)
				ls->fs->freereg -= nexps - nvars;
		}
		else {
			luaK_setoneret(ls->fs, &e);
			luaK_storevar(ls->fs, &lh->v, &e);
			return;
		}
	}
	init_exp(&e, VNONRELOC, ls->fs->freereg - 1);
	luaK_storevar(ls->fs, &lh->v, &e);
}

static int cond(LexState *ls) {

	expdesc v;
	expr(ls, &v);
	if (v.k == VNIL) v.k = VFALSE;
	luaK_goiftrue(ls->fs, &v);
	return v.f;
}

static void gotostat(LexState *ls, int pc) {
	int line = ls->linenumber;
	TString *label;
	int g;
	if (testnext(ls, TK_GOTO))
		label = str_checkname(ls);
	else {
		luaX_next(ls);
		label = luaS_new(ls->L, "break");
	}
	g = newlabelentry(ls, &ls->dyd->gt, label, line, pc);
	findlabel(ls, g);
}

static void checkrepeated(FuncState *fs, Labellist *ll, TString *label) {
	int i;
	for (i = fs->bl->firstlabel;
		i < ll->n;
		i++) {
		if (((label) == (ll->arr[i].name))) {
			const char *msg = luaO_pushfstring(fs->ls->L,
				"label '%s' already defined on line %d",
				(((char *)((label))) + sizeof(UTString)), ll->arr[i].line);
			semerror(fs->ls, msg);
		}
	}
}

static void skipnoopstat(LexState *ls) {
	while (ls->t.token == ';' || ls->t.token == TK_DBCOLON)
		statement(ls);
}

static void labelstat(LexState *ls, TString *label, int line) {

	FuncState *fs = ls->fs;
	Labellist *ll = &ls->dyd->label;
	int l;
	checkrepeated(fs, ll, label);
	checknext(ls, TK_DBCOLON);

	l = newlabelentry(ls, ll, label, line, luaK_getlabel(fs));
	skipnoopstat(ls);
	if (block_follow(ls, 0)) {

		ll->arr[l].nactvar = fs->bl->nactvar;
	}
	findgotos(ls, &ll->arr[l]);
}

static void whilestat(LexState *ls, int line) {

	FuncState *fs = ls->fs;
	int whileinit;
	int condexit;
	BlockCnt bl;
	luaX_next(ls);
	whileinit = luaK_getlabel(fs);
	condexit = cond(ls);
	enterblock(fs, &bl, 1);
	checknext(ls, TK_DO);
	block(ls);
	luaK_patchlist(fs, luaK_jump(fs), whileinit);
	check_match(ls, TK_END, TK_WHILE, line);
	leaveblock(fs);
	luaK_patchtohere(fs, condexit);
}

static void repeatstat(LexState *ls, int line) {

	int condexit;
	FuncState *fs = ls->fs;
	int repeat_init = luaK_getlabel(fs);
	BlockCnt bl1, bl2;
	enterblock(fs, &bl1, 1);
	enterblock(fs, &bl2, 0);
	luaX_next(ls);
	statlist(ls);
	check_match(ls, TK_UNTIL, TK_REPEAT, line);
	condexit = cond(ls);
	if (bl2.upval)
		luaK_patchclose(fs, condexit, bl2.nactvar);
	leaveblock(fs);
	luaK_patchlist(fs, condexit, repeat_init);
	leaveblock(fs);
}

static int exp1(LexState *ls) {
	expdesc e;
	int reg;
	expr(ls, &e);
	luaK_exp2nextreg(ls->fs, &e);
	((void)0);
	reg = e.u.info;
	return reg;
}

static void forbody(LexState *ls, int base, int line, int nvars, int isnum) {

	BlockCnt bl;
	FuncState *fs = ls->fs;
	int prep, endfor;
	adjustlocalvars(ls, 3);
	checknext(ls, TK_DO);
	prep = isnum ? luaK_codeABx(fs, OP_FORPREP, base, ((-1)) + (((1 << (9 + 9)) - 1) >> 1)) : luaK_jump(fs);
	enterblock(fs, &bl, 0);
	adjustlocalvars(ls, nvars);
	luaK_reserveregs(fs, nvars);
	block(ls);
	leaveblock(fs);
	luaK_patchtohere(fs, prep);
	if (isnum)
		endfor = luaK_codeABx(fs, OP_FORLOOP, base, ((-1)) + (((1 << (9 + 9)) - 1) >> 1));
	else {
		luaK_codeABC(fs, OP_TFORCALL, base, 0, nvars);
		luaK_fixline(fs, line);
		endfor = luaK_codeABx(fs, OP_TFORLOOP, base + 2, ((-1)) + (((1 << (9 + 9)) - 1) >> 1));
	}
	luaK_patchlist(fs, endfor, prep + 1);
	luaK_fixline(fs, line);
}

static void fornum(LexState *ls, TString *varname, int line) {

	FuncState *fs = ls->fs;
	int base = fs->freereg;
	new_localvarliteral_(ls, "" "(for index)", (sizeof("(for index)") / sizeof(char)) - 1);
	new_localvarliteral_(ls, "" "(for limit)", (sizeof("(for limit)") / sizeof(char)) - 1);
	new_localvarliteral_(ls, "" "(for step)", (sizeof("(for step)") / sizeof(char)) - 1);
	new_localvar(ls, varname);
	checknext(ls, '=');
	exp1(ls);
	checknext(ls, ',');
	exp1(ls);
	if (testnext(ls, ','))
		exp1(ls);
	else {
		luaK_codek(fs, fs->freereg, luaK_intK(fs, 1));
		luaK_reserveregs(fs, 1);
	}
	forbody(ls, base, line, 1, 1);
}

static void forlist(LexState *ls, TString *indexname) {

	FuncState *fs = ls->fs;
	expdesc e;
	int nvars = 4;
	int line;
	int base = fs->freereg;

	new_localvarliteral_(ls, "" "(for generator)", (sizeof("(for generator)") / sizeof(char)) - 1);
	new_localvarliteral_(ls, "" "(for state)", (sizeof("(for state)") / sizeof(char)) - 1);
	new_localvarliteral_(ls, "" "(for control)", (sizeof("(for control)") / sizeof(char)) - 1);

	new_localvar(ls, indexname);
	while (testnext(ls, ',')) {
		new_localvar(ls, str_checkname(ls));
		nvars++;
	}
	checknext(ls, TK_IN);
	line = ls->linenumber;
	adjust_assign(ls, 3, explist(ls, &e), &e);
	luaK_checkstack(fs, 3);
	forbody(ls, base, line, nvars - 3, 0);
}

static void forstat(LexState *ls, int line) {

	FuncState *fs = ls->fs;
	TString *varname;
	BlockCnt bl;
	enterblock(fs, &bl, 1);
	luaX_next(ls);
	varname = str_checkname(ls);
	switch (ls->t.token) {
	case '=': fornum(ls, varname, line);
		break;
	case ',': case TK_IN: forlist(ls, varname);
		break;
	default: luaX_syntaxerror(ls, "'=' or 'in' expected");
	}
	check_match(ls, TK_END, TK_FOR, line);
	leaveblock(fs);
}

static void test_then_block(LexState *ls, int *escapelist) {

	BlockCnt bl;
	FuncState *fs = ls->fs;
	expdesc v;
	int jf;
	luaX_next(ls);
	expr(ls, &v);
	checknext(ls, TK_THEN);
	if (ls->t.token == TK_GOTO || ls->t.token == TK_BREAK) {
		luaK_goiffalse(ls->fs, &v);
		enterblock(fs, &bl, 0);
		gotostat(ls, v.t);
		skipnoopstat(ls);
		if (block_follow(ls, 0)) {
			leaveblock(fs);
			return;
		}
		else
			jf = luaK_jump(fs);
	}
	else {
		luaK_goiftrue(ls->fs, &v);
		enterblock(fs, &bl, 0);
		jf = v.f;
	}
	statlist(ls);
	leaveblock(fs);
	if (ls->t.token == TK_ELSE ||
		ls->t.token == TK_ELSEIF)
		luaK_concat(fs, escapelist, luaK_jump(fs));
	luaK_patchtohere(fs, jf);
}

static void ifstat(LexState *ls, int line) {

	FuncState *fs = ls->fs;
	int escapelist = (-1);
	test_then_block(ls, &escapelist);
	while (ls->t.token == TK_ELSEIF)
		test_then_block(ls, &escapelist);
	if (testnext(ls, TK_ELSE))
		block(ls);
	check_match(ls, TK_END, TK_IF, line);
	luaK_patchtohere(fs, escapelist);
}

static void localfunc(LexState *ls) {
	expdesc b;
	FuncState *fs = ls->fs;
	new_localvar(ls, str_checkname(ls));
	adjustlocalvars(ls, 1);
	body(ls, &b, 0, ls->linenumber);

	getlocvar(fs, b.u.info)->startpc = fs->pc;
}

static void localstat(LexState *ls) {

	int nvars = 0;
	int nexps;
	expdesc e;
	do {
		new_localvar(ls, str_checkname(ls));
		nvars++;
	} while (testnext(ls, ','));
	if (testnext(ls, '='))
		nexps = explist(ls, &e);
	else {
		e.k = VVOID;
		nexps = 0;
	}
	adjust_assign(ls, nvars, nexps, &e);
	adjustlocalvars(ls, nvars);
}

static int funcname(LexState *ls, expdesc *v) {

	int ismethod = 0;
	singlevar(ls, v);
	while (ls->t.token == '.')
		fieldsel(ls, v);
	if (ls->t.token == ':') {
		ismethod = 1;
		fieldsel(ls, v);
	}
	return ismethod;
}

static void funcstat(LexState *ls, int line) {

	int ismethod;
	expdesc v, b;
	luaX_next(ls);
	ismethod = funcname(ls, &v);
	body(ls, &b, ismethod, line);
	luaK_storevar(ls->fs, &v, &b);
	luaK_fixline(ls->fs, line);
}

static void exprstat(LexState *ls) {

	FuncState *fs = ls->fs;
	struct LHS_assign v;
	suffixedexp(ls, &v.v);
	if (ls->t.token == '=' || ls->t.token == ',') {
		v.prev = ((void *)0);
		assignment(ls, &v, 1);
	}
	else {
			{
				if (!(v.v.k == VCALL)) luaX_syntaxerror(ls, "syntax error");
			};
		((((fs)->f->code[(&v.v)->u.info])) = (((((fs)->f->code[(&v.v)->u.info]))&(~((~((~(Instruction)0) << (9))) << (((0 + 6) + 8))))) | ((((Instruction)(1)) << ((0 + 6) + 8))&((~((~(Instruction)0) << (9))) << (((0 + 6) + 8))))));
	}
}

static void retstat(LexState *ls) {

	FuncState *fs = ls->fs;
	expdesc e;
	int first, nret;
	if (block_follow(ls, 1) || ls->t.token == ';')
		first = nret = 0;
	else {
		nret = explist(ls, &e);
		if (((e.k) == VCALL || (e.k) == VVARARG)) {
			luaK_setreturns(fs, &e, (-1));
			if (e.k == VCALL && nret == 1) {
				((((fs)->f->code[(&e)->u.info])) = (((((fs)->f->code[(&e)->u.info]))&(~((~((~(Instruction)0) << (6))) << (0)))) | ((((Instruction)(OP_TAILCALL)) << 0)&((~((~(Instruction)0) << (6))) << (0)))));
				((void)0);
			}
			first = fs->nactvar;
			nret = (-1);
		}
		else {
			if (nret == 1)
				first = luaK_exp2anyreg(fs, &e);
			else {
				luaK_exp2nextreg(fs, &e);
				first = fs->nactvar;
				((void)0);
			}
		}
	}
	luaK_ret(fs, first, nret);
	testnext(ls, ';');
}

static void statement(LexState *ls) {
	int line = ls->linenumber;
	enterlevel(ls);
	switch (ls->t.token) {
	case ';': {
		luaX_next(ls);
		break;
	}
	case TK_IF: {
		ifstat(ls, line);
		break;
	}
	case TK_WHILE: {
		whilestat(ls, line);
		break;
	}
	case TK_DO: {
		luaX_next(ls);
		block(ls);
		check_match(ls, TK_END, TK_DO, line);
		break;
	}
	case TK_FOR: {
		forstat(ls, line);
		break;
	}
	case TK_REPEAT: {
		repeatstat(ls, line);
		break;
	}
	case TK_FUNCTION: {
		funcstat(ls, line);
		break;
	}
	case TK_LOCAL: {
		luaX_next(ls);
		if (testnext(ls, TK_FUNCTION))
			localfunc(ls);
		else
			localstat(ls);
		break;
	}
	case TK_DBCOLON: {
		luaX_next(ls);
		labelstat(ls, str_checkname(ls), line);
		break;
	}
	case TK_RETURN: {
		luaX_next(ls);
		retstat(ls);
		break;
	}
	case TK_BREAK:
	case TK_GOTO: {
		gotostat(ls, luaK_jump(ls->fs));
		break;
	}
	default: {
		exprstat(ls);
		break;
	}
	}
	((void)0);
	ls->fs->freereg = ls->fs->nactvar;
	((ls)->L->nCcalls--);
}

static void mainfunc(LexState *ls, FuncState *fs) {
	BlockCnt bl;
	expdesc v;
	open_func(ls, fs, &bl);
	fs->f->is_vararg = 2;
	init_exp(&v, VLOCAL, 0);
	newupvalue(fs, ls->envn, &v);
	luaX_next(ls);
	statlist(ls);
	check(ls, TK_EOS);
	close_func(ls);
}

LClosure *luaY_parser(lua_State *L, ZIO *z, Mbuffer *buff,
	Dyndata *dyd, const char *name, int firstchar) {
	LexState lexstate;
	FuncState funcstate;
	LClosure *cl = luaF_newLclosure(L, 1);
	{
		TValue *io = (L->top);
		LClosure *x_ = (cl);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = ((((6 | (0 << 4))) | (1 << 6))));
		((void)0);
	};
	luaD_inctop(L);
	lexstate.h = luaH_new(L);
	{
		TValue *io = (L->top);
		Table *x_ = (lexstate.h);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = (((5) | (1 << 6))));
		((void)0);
	};
	luaD_inctop(L);
	funcstate.f = cl->p = luaF_newproto(L);
	funcstate.f->source = luaS_new(L, name);
	((void)0);
	lexstate.buff = buff;
	lexstate.dyd = dyd;
	dyd->actvar.n = dyd->gt.n = dyd->label.n = 0;
	luaX_setinput(L, &lexstate, z, funcstate.f->source, firstchar);
	mainfunc(&lexstate, &funcstate);
	((void)0);

	((void)0);
	L->top--;
	return cl;
}

