
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
void __cdecl _invoke_watson(  const wchar_t *,   const wchar_t *,   const wchar_t *, unsigned int, uintptr_t);

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

errno_t __cdecl _set_errno(  int _Value);
errno_t __cdecl _get_errno(  int * _Value);

__declspec(dllimport) extern unsigned long  __cdecl __threadid(void);

__declspec(dllimport) extern uintptr_t __cdecl __threadhandle(void);

#pragma once

#pragma once

void __declspec(dllimport) __cdecl _vacopy(  va_list *,   va_list);

typedef struct lua_State lua_State;

typedef double lua_Number;

typedef long long lua_Integer;

typedef unsigned long long lua_Unsigned;

typedef ptrdiff_t lua_KContext;

typedef int (*lua_CFunction) (lua_State *L);

typedef int (*lua_KFunction) (lua_State *L, int status, lua_KContext ctx);

typedef const char * (*lua_Reader) (lua_State *L, void *ud, size_t *sz);

typedef int (*lua_Writer) (lua_State *L, const void *p, size_t sz, void *ud);

typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);

extern const char lua_ident[];

extern lua_State *(lua_newstate) (lua_Alloc f, void *ud);
extern void       (lua_close) (lua_State *L);
extern lua_State *(lua_newthread) (lua_State *L);

extern lua_CFunction (lua_atpanic) (lua_State *L, lua_CFunction panicf);

extern const lua_Number *(lua_version) (lua_State *L);

extern int   (lua_absindex) (lua_State *L, int idx);
extern int   (lua_gettop) (lua_State *L);
extern void  (lua_settop) (lua_State *L, int idx);
extern void  (lua_pushvalue) (lua_State *L, int idx);
extern void  (lua_rotate) (lua_State *L, int idx, int n);
extern void  (lua_copy) (lua_State *L, int fromidx, int toidx);
extern int   (lua_checkstack) (lua_State *L, int n);

extern void  (lua_xmove) (lua_State *from, lua_State *to, int n);

extern int             (lua_isnumber) (lua_State *L, int idx);
extern int             (lua_isstring) (lua_State *L, int idx);
extern int             (lua_iscfunction) (lua_State *L, int idx);
extern int             (lua_isinteger) (lua_State *L, int idx);
extern int             (lua_isuserdata) (lua_State *L, int idx);
extern int             (lua_type) (lua_State *L, int idx);
extern const char     *(lua_typename) (lua_State *L, int tp);

extern lua_Number      (lua_tonumberx) (lua_State *L, int idx, int *isnum);
extern lua_Integer     (lua_tointegerx) (lua_State *L, int idx, int *isnum);
extern int             (lua_toboolean) (lua_State *L, int idx);
extern const char     *(lua_tolstring) (lua_State *L, int idx, size_t *len);
extern size_t          (lua_rawlen) (lua_State *L, int idx);
extern lua_CFunction   (lua_tocfunction) (lua_State *L, int idx);
extern void	       *(lua_touserdata) (lua_State *L, int idx);
extern lua_State      *(lua_tothread) (lua_State *L, int idx);
extern const void     *(lua_topointer) (lua_State *L, int idx);

extern void  (lua_arith) (lua_State *L, int op);

extern int   (lua_rawequal) (lua_State *L, int idx1, int idx2);
extern int   (lua_compare) (lua_State *L, int idx1, int idx2, int op);

extern void        (lua_pushnil) (lua_State *L);
extern void        (lua_pushnumber) (lua_State *L, lua_Number n);
extern void        (lua_pushinteger) (lua_State *L, lua_Integer n);
extern const char *(lua_pushlstring) (lua_State *L, const char *s, size_t len);
extern const char *(lua_pushstring) (lua_State *L, const char *s);
extern const char *(lua_pushvfstring) (lua_State *L, const char *fmt,
                                                      va_list argp);
extern const char *(lua_pushfstring) (lua_State *L, const char *fmt, ...);
extern void  (lua_pushcclosure) (lua_State *L, lua_CFunction fn, int n);
extern void  (lua_pushboolean) (lua_State *L, int b);
extern void  (lua_pushlightuserdata) (lua_State *L, void *p);
extern int   (lua_pushthread) (lua_State *L);

extern int (lua_getglobal) (lua_State *L, const char *name);
extern int (lua_gettable) (lua_State *L, int idx);
extern int (lua_getfield) (lua_State *L, int idx, const char *k);
extern int (lua_geti) (lua_State *L, int idx, lua_Integer n);
extern int (lua_rawget) (lua_State *L, int idx);
extern int (lua_rawgeti) (lua_State *L, int idx, lua_Integer n);
extern int (lua_rawgetp) (lua_State *L, int idx, const void *p);

extern void  (lua_createtable) (lua_State *L, int narr, int nrec);
extern void *(lua_newuserdata) (lua_State *L, size_t sz);
extern int   (lua_getmetatable) (lua_State *L, int objindex);
extern int  (lua_getuservalue) (lua_State *L, int idx);

extern void  (lua_setglobal) (lua_State *L, const char *name);
extern void  (lua_settable) (lua_State *L, int idx);
extern void  (lua_setfield) (lua_State *L, int idx, const char *k);
extern void  (lua_seti) (lua_State *L, int idx, lua_Integer n);
extern void  (lua_rawset) (lua_State *L, int idx);
extern void  (lua_rawseti) (lua_State *L, int idx, lua_Integer n);
extern void  (lua_rawsetp) (lua_State *L, int idx, const void *p);
extern int   (lua_setmetatable) (lua_State *L, int objindex);
extern void  (lua_setuservalue) (lua_State *L, int idx);

extern void  (lua_callk) (lua_State *L, int nargs, int nresults,
                           lua_KContext ctx, lua_KFunction k);

extern int   (lua_pcallk) (lua_State *L, int nargs, int nresults, int errfunc,
                            lua_KContext ctx, lua_KFunction k);

extern int   (lua_load) (lua_State *L, lua_Reader reader, void *dt,
                          const char *chunkname, const char *mode);

extern int (lua_dump) (lua_State *L, lua_Writer writer, void *data, int strip);

extern int  (lua_yieldk)     (lua_State *L, int nresults, lua_KContext ctx,
                               lua_KFunction k);
extern int  (lua_resume)     (lua_State *L, lua_State *from, int narg);
extern int  (lua_status)     (lua_State *L);
extern int (lua_isyieldable) (lua_State *L);

extern int (lua_gc) (lua_State *L, int what, int data);

extern int   (lua_error) (lua_State *L);

extern int   (lua_next) (lua_State *L, int idx);

extern void  (lua_concat) (lua_State *L, int n);
extern void  (lua_len)    (lua_State *L, int idx);

extern size_t   (lua_stringtonumber) (lua_State *L, const char *s);

extern lua_Alloc (lua_getallocf) (lua_State *L, void **ud);
extern void      (lua_setallocf) (lua_State *L, lua_Alloc f, void *ud);

typedef struct lua_Debug lua_Debug;  

typedef void (*lua_Hook) (lua_State *L, lua_Debug *ar);

extern int (lua_getstack) (lua_State *L, int level, lua_Debug *ar);
extern int (lua_getinfo) (lua_State *L, const char *what, lua_Debug *ar);
extern const char *(lua_getlocal) (lua_State *L, const lua_Debug *ar, int n);
extern const char *(lua_setlocal) (lua_State *L, const lua_Debug *ar, int n);
extern const char *(lua_getupvalue) (lua_State *L, int funcindex, int n);
extern const char *(lua_setupvalue) (lua_State *L, int funcindex, int n);

extern void *(lua_upvalueid) (lua_State *L, int fidx, int n);
extern void  (lua_upvaluejoin) (lua_State *L, int fidx1, int n1,
                                               int fidx2, int n2);

extern void (lua_sethook) (lua_State *L, lua_Hook func, int mask, int count);
extern lua_Hook (lua_gethook) (lua_State *L);
extern int (lua_gethookmask) (lua_State *L);
extern int (lua_gethookcount) (lua_State *L);

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

extern const char *const luaP_opnames[(((int)(OP_EXTRAARG)) + 1)+1];  

 const char *const luaP_opnames[(((int)(OP_EXTRAARG)) + 1)+1] = {
  "MOVE",
  "LOADK",
  "LOADKX",
  "LOADBOOL",
  "LOADNIL",
  "GETUPVAL",
  "GETTABUP",
  "GETTABLE",
  "SETTABUP",
  "SETUPVAL",
  "SETTABLE",
  "NEWTABLE",
  "SELF",
  "ADD",
  "SUB",
  "MUL",
  "MOD",
  "POW",
  "DIV",
  "IDIV",
  "BAND",
  "BOR",
  "BXOR",
  "SHL",
  "SHR",
  "UNM",
  "BNOT",
  "NOT",
  "LEN",
  "CONCAT",
  "JMP",
  "EQ",
  "LT",
  "LE",
  "TEST",
  "TESTSET",
  "CALL",
  "TAILCALL",
  "RETURN",
  "FORLOOP",
  "FORPREP",
  "TFORCALL",
  "TFORLOOP",
  "SETLIST",
  "CLOSURE",
  "VARARG",
  "EXTRAARG",
  ((void *)0)
};

 const lu_byte luaP_opmodes[(((int)(OP_EXTRAARG)) + 1)] = {

  (((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgN)<<2) | (iABx))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgN)<<4) | ((OpArgN)<<2) | (iABx))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgU)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((0)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((0)<<6) | ((OpArgU)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((0)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgU)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgR)<<2) | (iABC))		
 ,(((0)<<7) | ((0)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iAsBx))		
 ,(((1)<<7) | ((0)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((1)<<7) | ((0)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((1)<<7) | ((0)<<6) | ((OpArgK)<<4) | ((OpArgK)<<2) | (iABC))		
 ,(((1)<<7) | ((0)<<6) | ((OpArgN)<<4) | ((OpArgU)<<2) | (iABC))		
 ,(((1)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgU)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgU)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgU)<<2) | (iABC))		
 ,(((0)<<7) | ((0)<<6) | ((OpArgU)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iAsBx))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iAsBx))		
 ,(((0)<<7) | ((0)<<6) | ((OpArgN)<<4) | ((OpArgU)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgR)<<4) | ((OpArgN)<<2) | (iAsBx))		
 ,(((0)<<7) | ((0)<<6) | ((OpArgU)<<4) | ((OpArgU)<<2) | (iABC))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgN)<<2) | (iABx))		
 ,(((0)<<7) | ((1)<<6) | ((OpArgU)<<4) | ((OpArgN)<<2) | (iABC))		
 ,(((0)<<7) | ((0)<<6) | ((OpArgU)<<4) | ((OpArgU)<<2) | (iAx))		
};

