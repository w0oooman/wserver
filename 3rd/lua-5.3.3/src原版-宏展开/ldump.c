
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

void __declspec(dllimport) __cdecl _vacopy(  va_list *,   va_list);

#pragma once

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

extern int luaO_int2fb (unsigned int x);
extern int luaO_fb2int (int x);
extern int luaO_utf8esc (char *buff, unsigned long x);
extern int luaO_ceillog2 (unsigned int x);
extern void luaO_arith (lua_State *L, int op, const TValue *p1,
                           const TValue *p2, TValue *res);
extern size_t luaO_str2num (const char *s, TValue *o);
extern int luaO_hexavalue (int c);
extern void luaO_tostring (lua_State *L, StkId obj);
extern const char *luaO_pushvfstring (lua_State *L, const char *fmt,
                                                       va_list argp);
extern const char *luaO_pushfstring (lua_State *L, const char *fmt, ...);
extern void luaO_chunkid (char *out, const char *source, size_t len);

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

extern const char *luaT_objtypename (lua_State *L, const TValue *o);

extern const TValue *luaT_gettm (Table *events, TMS event, TString *ename);
extern const TValue *luaT_gettmbyobj (lua_State *L, const TValue *o,
                                                       TMS event);
extern void luaT_init (lua_State *L);

extern void luaT_callTM (lua_State *L, const TValue *f, const TValue *p1,
                            const TValue *p2, TValue *p3, int hasres);
extern int luaT_callbinTM (lua_State *L, const TValue *p1, const TValue *p2,
                              StkId res, TMS event);
extern void luaT_trybinTM (lua_State *L, const TValue *p1, const TValue *p2,
                              StkId res, TMS event);
extern int luaT_callorderTM (lua_State *L, const TValue *p1,
                                const TValue *p2, TMS event);

extern void __declspec(noreturn) luaM_toobig (lua_State *L);

extern void *luaM_realloc_ (lua_State *L, void *block, size_t oldsize,
                                                          size_t size);
extern void *luaM_growaux_ (lua_State *L, void *block, int *size,
                               size_t size_elem, int limit,
                               const char *what);

typedef struct Zio ZIO;

typedef struct Mbuffer {
  char *buffer;
  size_t n;
  size_t buffsize;
} Mbuffer;

extern void luaZ_init (lua_State *L, ZIO *z, lua_Reader reader,
                                        void *data);
extern size_t luaZ_read (ZIO* z, void *b, size_t n);	

struct Zio {
  size_t n;			
  const char *p;		
  lua_Reader reader;		
  void *data;			
  lua_State *L;			
};

extern int luaZ_fill (ZIO *z);

struct lua_longjmp;  

#pragma once

typedef int sig_atomic_t;

extern void * * __cdecl __pxcptinfoptrs(void);

__declspec(dllimport) void (__cdecl * __cdecl signal(  int _SigNum,   void (__cdecl * _Func)(int)))(int);

__declspec(dllimport) int __cdecl raise(  int _SigNum);

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

extern void luaE_setdebt (global_State *g, l_mem debt);
extern void luaE_freethread (lua_State *L, lua_State *L1);
extern CallInfo *luaE_extendCI (lua_State *L);
extern void luaE_freeCI (lua_State *L);
extern void luaE_shrinkCI (lua_State *L);

extern LClosure* luaU_undump (lua_State* L, ZIO* Z, const char* name);

extern int luaU_dump (lua_State* L, const Proto* f, lua_Writer w,
                         void* data, int strip);

typedef struct {
  lua_State *L;
  lua_Writer writer;
  void *data;
  int strip;
  int status;
} DumpState;

static void DumpBlock (const void *b, size_t size, DumpState *D) {
  if (D->status == 0 && size > 0) {
    ((void) 0);
    D->status = (*D->writer)(D->L, b, size, D->data);
    ((void) 0);
  }
}

static void DumpByte (int y, DumpState *D) {
  lu_byte x = (lu_byte)y;
  DumpBlock(&x,(1)*sizeof((&x)[0]),D);
}

static void DumpInt (int x, DumpState *D) {
  DumpBlock(&x,(1)*sizeof((&x)[0]),D);
}

static void DumpNumber (lua_Number x, DumpState *D) {
  DumpBlock(&x,(1)*sizeof((&x)[0]),D);
}

static void DumpInteger (lua_Integer x, DumpState *D) {
  DumpBlock(&x,(1)*sizeof((&x)[0]),D);
}

static void DumpString (const TString *s, DumpState *D) {
  if (s == ((void *)0))
    DumpByte(0, D);
  else {
    size_t size = ((s)->tt == (4 | (0 << 4)) ? (s)->shrlen : (s)->u.lnglen) + 1;  
    const char *str = (((char *)((s))) + sizeof(UTString));
    if (size < 0xFF)
      DumpByte(((int)((size))), D);
    else {
      DumpByte(0xFF, D);
      DumpBlock(&size,(1)*sizeof((&size)[0]),D);
    }
    DumpBlock(str,(size - 1)*sizeof((str)[0]),D);  
  }
}

static void DumpCode (const Proto *f, DumpState *D) {
  DumpInt(f->sizecode, D);
  DumpBlock(f->code,(f->sizecode)*sizeof((f->code)[0]),D);
}

static void DumpFunction(const Proto *f, TString *psource, DumpState *D);

static void DumpConstants (const Proto *f, DumpState *D) {
  int i;
  int n = f->sizek;
  DumpInt(n, D);
  for (i = 0;
 i < n;
 i++) {
    const TValue *o = &f->k[i];
    DumpByte((((o)->tt_) & 0x3F), D);
    switch ((((o)->tt_) & 0x3F)) {
    case 0:
      break;
    case 1:
      DumpByte((((o)->value_).b), D);
      break;
    case (3 | (0 << 4)):
      DumpNumber((((o)->value_).n), D);
      break;
    case (3 | (1 << 4)):
      DumpInteger((((o)->value_).i), D);
      break;
    case (4 | (0 << 4)):
    case (4 | (1 << 4)):
      DumpString(((&((((union GCUnion *)((((o)->value_).gc))))->ts))), D);
      break;
    default:
      ((void)0);
    }
  }
}

static void DumpProtos (const Proto *f, DumpState *D) {
  int i;
  int n = f->sizep;
  DumpInt(n, D);
  for (i = 0;
 i < n;
 i++)
    DumpFunction(f->p[i], f->source, D);
}

static void DumpUpvalues (const Proto *f, DumpState *D) {
  int i, n = f->sizeupvalues;
  DumpInt(n, D);
  for (i = 0;
 i < n;
 i++) {
    DumpByte(f->upvalues[i].instack, D);
    DumpByte(f->upvalues[i].idx, D);
  }
}

static void DumpDebug (const Proto *f, DumpState *D) {
  int i, n;
  n = (D->strip) ? 0 : f->sizelineinfo;
  DumpInt(n, D);
  DumpBlock(f->lineinfo,(n)*sizeof((f->lineinfo)[0]),D);
  n = (D->strip) ? 0 : f->sizelocvars;
  DumpInt(n, D);
  for (i = 0;
 i < n;
 i++) {
    DumpString(f->locvars[i].varname, D);
    DumpInt(f->locvars[i].startpc, D);
    DumpInt(f->locvars[i].endpc, D);
  }
  n = (D->strip) ? 0 : f->sizeupvalues;
  DumpInt(n, D);
  for (i = 0;
 i < n;
 i++)
    DumpString(f->upvalues[i].name, D);
}

static void DumpFunction (const Proto *f, TString *psource, DumpState *D) {
  if (D->strip || f->source == psource)
    DumpString(((void *)0), D);  
  else
    DumpString(f->source, D);
  DumpInt(f->linedefined, D);
  DumpInt(f->lastlinedefined, D);
  DumpByte(f->numparams, D);
  DumpByte(f->is_vararg, D);
  DumpByte(f->maxstacksize, D);
  DumpCode(f, D);
  DumpConstants(f, D);
  DumpUpvalues(f, D);
  DumpProtos(f, D);
  DumpDebug(f, D);
}

static void DumpHeader (DumpState *D) {
  DumpBlock("\x1bLua", sizeof("\x1bLua") - sizeof(char), D);
  DumpByte((("5"[0]-'0')*16+("3"[0]-'0')), D);
  DumpByte(0, D);
  DumpBlock("\x19\x93\r\n\x1a\n", sizeof("\x19\x93\r\n\x1a\n") - sizeof(char), D);
  DumpByte(sizeof(int), D);
  DumpByte(sizeof(size_t), D);
  DumpByte(sizeof(Instruction), D);
  DumpByte(sizeof(lua_Integer), D);
  DumpByte(sizeof(lua_Number), D);
  DumpInteger(0x5678, D);
  DumpNumber(((lua_Number)((370.5))), D);
}

int luaU_dump(lua_State *L, const Proto *f, lua_Writer w, void *data,
              int strip) {
  DumpState D;
  D.L = L;
  D.writer = w;
  D.data = data;
  D.strip = strip;
  D.status = 0;
  DumpHeader(&D);
  DumpByte(f->sizeupvalues, &D);
  DumpFunction(f, ((void *)0), &D);
  return D.status;
}

