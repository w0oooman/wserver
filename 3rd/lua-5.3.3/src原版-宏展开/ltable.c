
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

#pragma once

#pragma once

void __declspec(dllimport) __cdecl _vacopy(va_list *, va_list);

#pragma once

__declspec(dllimport) extern int * __cdecl _errno(void);

errno_t __cdecl _set_errno(int _Value);
errno_t __cdecl _get_errno(int * _Value);

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

static const Node dummynode_ = {
		{
			{
				((void *)0)
			}, 0
		},
		{
			{
				{
					((void *)0)
				}, 0, 0
			} }
};

static int l_hashfloat(lua_Number n) {
	int i;
	lua_Integer ni;
	n = (lua_Number)frexp(n, &i) * -((lua_Number)(((-2147483647 - 1))));
	if (!((n) >= (double)((-9223372036854775807i64 - 1)) && (n) < -(double)((-9223372036854775807i64 - 1)) && (*(&ni) = (long long)(n), 1))) {
		((void)0);
		return 0;
	}
	else {
		unsigned int u = ((unsigned int)(i)) + ((unsigned int)(ni));
		return ((int)((u <= ((unsigned int)(2147483647)) ? u : ~u)));
	}
}

static Node *mainposition(const Table *t, const TValue *key) {
	switch ((((key)->tt_) & 0x3F)) {
	case (3 | (1 << 4)) :
		return ((&(t)->node[(((((int)((((((key)->value_).i))) & ((((1 << ((t)->lsizenode)))) - 1))))))]));
	case (3 | (0 << 4)) :
		return ((&(t)->node[((l_hashfloat((((key)->value_).n))) % ((((1 << ((t)->lsizenode))) - 1) | 1))]));
	case (4 | (0 << 4)) :
		return ((&(t)->node[(((((int)((((((&((((union GCUnion *)((((key)->value_).gc))))->ts))))->hash)) & ((((1 << ((t)->lsizenode)))) - 1))))))]));
	case (4 | (1 << 4)) :
		return ((&(t)->node[(((((int)(((luaS_hashlongstr(((&((((union GCUnion *)((((key)->value_).gc))))->ts)))))) & ((((1 << ((t)->lsizenode)))) - 1))))))]));
	case 1:
		return ((&(t)->node[(((((int)((((((key)->value_).b))) & ((((1 << ((t)->lsizenode)))) - 1))))))]));
	case 2:
		return ((&(t)->node[((((unsigned int)((size_t)((((key)->value_).p)) & 0xffffffff))) % ((((1 << ((t)->lsizenode))) - 1) | 1))]));
	case (6 | (1 << 4)) :
		return ((&(t)->node[((((unsigned int)((size_t)((((key)->value_).f)) & 0xffffffff))) % ((((1 << ((t)->lsizenode))) - 1) | 1))]));
	default:
		((void)0);
		return ((&(t)->node[((((unsigned int)((size_t)((((key)->value_).gc)) & 0xffffffff))) % ((((1 << ((t)->lsizenode))) - 1) | 1))]));
	}
}

static unsigned int arrayindex(const TValue *key) {
	if (((((key))->tt_) == ((3 | (1 << 4))))) {
		lua_Integer k = (((key)->value_).i);
		if (0 < k && (lua_Unsigned)k <= (1u << ((int)((sizeof(int) * 8 - 1)))))
			return ((unsigned int)(k));
	}
	return 0;
}

static unsigned int findindex(lua_State *L, Table *t, StkId key) {
	unsigned int i;
	if (((((key))->tt_) == (0))) return 0;
	i = arrayindex(key);
	if (i != 0 && i <= t->sizearray)
		return i;
	else {
		int nx;
		Node *n = mainposition(t, key);
		for (;
			;
			) {

			if (luaV_equalobj(((void *)0), ((const TValue*)((&(n)->i_key.tvk))), key) ||
				(((((((const TValue*)((&(n)->i_key.tvk)))))->tt_) == ((9 + 1))) && (((key)->tt_) & (1 << 6)) &&
				(((void *)(((((const TValue*)((&(n)->i_key.tvk))))->value_).gc))) == (((key)->value_).gc))) {
				i = ((int)((n - (&(t)->node[0]))));

				return (i + 1) + t->sizearray;
			}
			nx = ((n)->i_key.nk.next);
			if (nx == 0)
				luaG_runerror(L, "invalid key to 'next'");
			else n += nx;
		}
	}
}

int luaH_next(lua_State *L, Table *t, StkId key) {
	unsigned int i = findindex(L, t, key);
	for (;
		i < t->sizearray;
		i++) {
		if (!((((&t->array[i]))->tt_) == (0))) {
				{
					TValue *io = (key);
					((io)->value_).i = (i + 1);
					((io)->tt_ = ((3 | (1 << 4))));
				};
				{
					TValue *io1 = (key + 1);
					*io1 = *(&t->array[i]);
					(void)L;
					((void)0);
				};
			return 1;
		}
	}
	for (i -= t->sizearray;
		((int)((i))) < ((1 << ((t)->lsizenode)));
		i++) {
		if (!(((((&((&(t)->node[i]))->i_val)))->tt_) == (0))) {
				{
					TValue *io1 = (key);
					*io1 = *(((const TValue*)((&((&(t)->node[i]))->i_key.tvk))));
					(void)L;
					((void)0);
				};
				{
					TValue *io1 = (key + 1);
					*io1 = *((&((&(t)->node[i]))->i_val));
					(void)L;
					((void)0);
				};
			return 1;
		}
	}
	return 0;
}

static unsigned int computesizes(unsigned int nums[], unsigned int *pna) {
	int i;
	unsigned int twotoi;
	unsigned int a = 0;
	unsigned int na = 0;
	unsigned int optimal = 0;

	for (i = 0, twotoi = 1;
		*pna > twotoi / 2;
		i++, twotoi *= 2) {
		if (nums[i] > 0) {
			a += nums[i];
			if (a > twotoi / 2) {
				optimal = twotoi;
				na = a;
			}
		}
	}
	((void)0);
	*pna = na;
	return optimal;
}

static int countint(const TValue *key, unsigned int *nums) {
	unsigned int k = arrayindex(key);
	if (k != 0) {
		nums[luaO_ceillog2(k)]++;
		return 1;
	}
	else
		return 0;
}

static unsigned int numusearray(const Table *t, unsigned int *nums) {
	int lg;
	unsigned int ttlg;
	unsigned int ause = 0;
	unsigned int i = 1;

	for (lg = 0, ttlg = 1;
		lg <= ((int)((sizeof(int) * 8 - 1)));
		lg++, ttlg *= 2) {
		unsigned int lc = 0;
		unsigned int lim = ttlg;
		if (lim > t->sizearray) {
			lim = t->sizearray;
			if (i > lim)
				break;
		}

		for (;
			i <= lim;
			i++) {
			if (!((((&t->array[i - 1]))->tt_) == (0)))
				lc++;
		}
		nums[lg] += lc;
		ause += lc;
	}
	return ause;
}

static int numusehash(const Table *t, unsigned int *nums, unsigned int *pna) {
	int totaluse = 0;
	int ause = 0;
	int i = ((1 << ((t)->lsizenode)));
	while (i--) {
		Node *n = &t->node[i];
		if (!(((((&(n)->i_val)))->tt_) == (0))) {
			ause += countint(((const TValue*)((&(n)->i_key.tvk))), nums);
			totaluse++;
		}
	}
	*pna += ause;
	return totaluse;
}

static void setarrayvector(lua_State *L, Table *t, unsigned int size) {
	unsigned int i;
	((t->array) = ((TValue *)((((sizeof(size) >= sizeof(size_t) && ((size_t)((size))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(TValue))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (t->array), (t->sizearray)*(sizeof(TValue)), (size)*(sizeof(TValue)))))));
	for (i = t->sizearray;
		i<size;
		i++)
		((&t->array[i])->tt_ = (0));
	t->sizearray = size;
}

static void setnodevector(lua_State *L, Table *t, unsigned int size) {
	int lsize;
	if (size == 0) {
		t->node = ((Node *)((&dummynode_)));
		lsize = 0;
	}
	else {
		int i;
		lsize = luaO_ceillog2(size);
		if (lsize > (((int)((sizeof(int) * 8 - 1))) - 1))
			luaG_runerror(L, "table overflow");
		size = (1 << (lsize));
		t->node = ((Node *)((((sizeof(size) >= sizeof(size_t) && ((size_t)((size))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(Node))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (((void *)0)), (0)*(sizeof(Node)), (size)*(sizeof(Node))))));
		for (i = 0;
			i < (int)size;
			i++) {
			Node *n = (&(t)->node[i]);
			((n)->i_key.nk.next) = 0;
			(((&(n)->i_key.nk))->tt_ = (0));
			(((&(n)->i_val))->tt_ = (0));
		}
	}
	t->lsizenode = ((lu_byte)((lsize)));
	t->lastfree = (&(t)->node[size]);
}

void luaH_resize(lua_State *L, Table *t, unsigned int nasize,
	unsigned int nhsize) {
	unsigned int i;
	int j;
	unsigned int oldasize = t->sizearray;
	int oldhsize = t->lsizenode;
	Node *nold = t->node;
	if (nasize > oldasize)
		setarrayvector(L, t, nasize);

	setnodevector(L, t, nhsize);
	if (nasize < oldasize) {
		t->sizearray = nasize;

		for (i = nasize;
			i < oldasize;
			i++) {
			if (!((((&t->array[i]))->tt_) == (0)))
				luaH_setint(L, t, i + 1, &t->array[i]);
		}

		((t->array) = ((TValue *)((((sizeof(nasize) >= sizeof(size_t) && ((size_t)((nasize))) + 1 > ((size_t)(~(size_t)0)) / (sizeof(TValue))) ? luaM_toobig(L) : ((void)((0)))), luaM_realloc_(L, (t->array), (oldasize)*(sizeof(TValue)), (nasize)*(sizeof(TValue)))))));
	}

	for (j = (1 << (oldhsize)) - 1;
		j >= 0;
		j--) {
		Node *old = nold + j;
		if (!(((((&(old)->i_val)))->tt_) == (0))) {

				{
					TValue *io1 = (luaH_set(L, t, ((const TValue*)((&(old)->i_key.tvk)))));
					*io1 = *((&(old)->i_val));
					(void)L;
					((void)0);
				};
		}
	}
	if (!((nold) == (&dummynode_)))
		luaM_realloc_(L, (nold), (((size_t)((1 << (oldhsize)))))*sizeof(*(nold)), 0);
}

void luaH_resizearray(lua_State *L, Table *t, unsigned int nasize) {
	int nsize = ((t->node) == (&dummynode_)) ? 0 : ((1 << ((t)->lsizenode)));
	luaH_resize(L, t, nasize, nsize);
}

static void rehash(lua_State *L, Table *t, const TValue *ek) {
	unsigned int asize;
	unsigned int na;
	unsigned int nums[((int)((sizeof(int) * 8 - 1))) + 1];
	int i;
	int totaluse;
	for (i = 0;
		i <= ((int)((sizeof(int) * 8 - 1)));
		i++) nums[i] = 0;
	na = numusearray(t, nums);
	totaluse = na;
	totaluse += numusehash(t, nums, &na);

	na += countint(ek, nums);
	totaluse++;

	asize = computesizes(nums, &na);

	luaH_resize(L, t, asize, totaluse - na);
}

Table *luaH_new(lua_State *L) {
	GCObject *o = luaC_newobj(L, 5, sizeof(Table));
	Table *t = (&((((union GCUnion *)((o))))->h));
	t->metatable = ((void *)0);
	t->flags = ((lu_byte)((~0)));
	t->array = ((void *)0);
	t->sizearray = 0;
	setnodevector(L, t, 0);
	return t;
}

void luaH_free(lua_State *L, Table *t) {
	if (!((t->node) == (&dummynode_)))
		luaM_realloc_(L, (t->node), (((size_t)(((1 << ((t)->lsizenode))))))*sizeof(*(t->node)), 0);
	luaM_realloc_(L, (t->array), (t->sizearray)*sizeof(*(t->array)), 0);
	luaM_realloc_(L, (t), sizeof(*(t)), 0);
}

static Node *getfreepos(Table *t) {
	while (t->lastfree > t->node) {
		t->lastfree--;
		if (((((((const TValue*)((&(t->lastfree)->i_key.tvk)))))->tt_) == (0)))
			return t->lastfree;
	}
	return ((void *)0);
}

TValue *luaH_newkey(lua_State *L, Table *t, const TValue *key) {
	Node *mp;
	TValue aux;
	if (((((key))->tt_) == (0))) luaG_runerror(L, "table index is nil");
	else if (((((key))->tt_) == ((3 | (0 << 4))))) {
		lua_Integer k;
		if (luaV_tointeger(key, &k, 0)) {
				{
					TValue *io = (&aux);
					((io)->value_).i = (k);
					((io)->tt_ = ((3 | (1 << 4))));
				};
			key = &aux;
		}
		else if ((!((((((key)->value_).n))) == (((((key)->value_).n))))))
			luaG_runerror(L, "table index is NaN");
	}
	mp = mainposition(t, key);
	if (!(((((&(mp)->i_val)))->tt_) == (0)) || ((mp) == (&dummynode_))) {
		Node *othern;
		Node *f = getfreepos(t);
		if (f == ((void *)0)) {
			rehash(L, t, key);

			return luaH_set(L, t, key);
		}
		((void)0);
		othern = mainposition(t, ((const TValue*)((&(mp)->i_key.tvk))));
		if (othern != mp) {

			while (othern + ((othern)->i_key.nk.next) != mp)
				othern += ((othern)->i_key.nk.next);
			((othern)->i_key.nk.next) = ((int)((f - othern)));
			*f = *mp;
			if (((mp)->i_key.nk.next) != 0) {
				((f)->i_key.nk.next) += ((int)((mp - f)));
				((mp)->i_key.nk.next) = 0;
			}
			(((&(mp)->i_val))->tt_ = (0));
		}
		else {

			if (((mp)->i_key.nk.next) != 0)
				((f)->i_key.nk.next) = ((int)(((mp + ((mp)->i_key.nk.next)) - f)));
			else ((void)0);
			((mp)->i_key.nk.next) = ((int)((f - mp)));
			mp = f;
		}
	}
  {
	  TKey *k_ = (&mp->i_key);
	  const TValue *io_ = (key);
	  k_->nk.value_ = io_->value_;
	  k_->nk.tt_ = io_->tt_;
	  (void)L;
	  ((void)0);
  };
	(((((key)->tt_) & (1 << 6)) && (((t)->marked) & ((1 << (2)))) && ((((((key)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrierback_(L, t) : ((void)((0))));
	((void)0);
	return (&(mp)->i_val);
}

const TValue *luaH_getint(Table *t, lua_Integer key) {

	if (((lua_Unsigned)(key)) - 1 < t->sizearray)
		return &t->array[key - 1];
	else {
		Node *n = ((&(t)->node[(((((int)(((key)) & ((((1 << ((t)->lsizenode)))) - 1))))))]));
		for (;
			;
			) {
			if (((((((const TValue*)((&(n)->i_key.tvk)))))->tt_) == ((3 | (1 << 4)))) && (((((const TValue*)((&(n)->i_key.tvk))))->value_).i) == key)
				return (&(n)->i_val);
			else {
				int nx = ((n)->i_key.nk.next);
				if (nx == 0) break;
				n += nx;
			}
		}
		return (&luaO_nilobject_);
	}
}

const TValue *luaH_getshortstr(Table *t, TString *key) {
	Node *n = ((&(t)->node[(((((int)((((key)->hash)) & ((((1 << ((t)->lsizenode)))) - 1))))))]));
	((void)0);
	for (;
		;
		) {
		const TValue *k = ((const TValue*)((&(n)->i_key.tvk)));
		if (((((k))->tt_) == ((((4 | (0 << 4))) | (1 << 6)))) && ((((&((((union GCUnion *)((((k)->value_).gc))))->ts)))) == (key)))
			return (&(n)->i_val);
		else {
			int nx = ((n)->i_key.nk.next);
			if (nx == 0)
				return (&luaO_nilobject_);
			n += nx;
		}
	}
}

static const TValue *getgeneric(Table *t, const TValue *key) {
	Node *n = mainposition(t, key);
	for (;
		;
		) {
		if (luaV_equalobj(((void *)0), ((const TValue*)((&(n)->i_key.tvk))), key))
			return (&(n)->i_val);
		else {
			int nx = ((n)->i_key.nk.next);
			if (nx == 0)
				return (&luaO_nilobject_);
			n += nx;
		}
	}
}

const TValue *luaH_getstr(Table *t, TString *key) {
	if (key->tt == (4 | (0 << 4)))
		return luaH_getshortstr(t, key);
	else {
		TValue ko;
		{
			TValue *io = (&ko);
			TString *x_ = (key);
			((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void)0);
		};
		return getgeneric(t, &ko);
	}
}

const TValue *luaH_get(Table *t, const TValue *key) {
	switch ((((key)->tt_) & 0x3F)) {
	case (4 | (0 << 4)) : return luaH_getshortstr(t, ((&((((union GCUnion *)((((key)->value_).gc))))->ts))));
	case (3 | (1 << 4)) : return luaH_getint(t, (((key)->value_).i));
	case 0: return (&luaO_nilobject_);
	case (3 | (0 << 4)) : {
		lua_Integer k;
		if (luaV_tointeger(key, &k, 0))
			return luaH_getint(t, k);

	}
	default:
		return getgeneric(t, key);
	}
}

TValue *luaH_set(lua_State *L, Table *t, const TValue *key) {
	const TValue *p = luaH_get(t, key);
	if (p != (&luaO_nilobject_))
		return ((TValue *)(p));
	else return luaH_newkey(L, t, key);
}

void luaH_setint(lua_State *L, Table *t, lua_Integer key, TValue *value) {
	const TValue *p = luaH_getint(t, key);
	TValue *cell;
	if (p != (&luaO_nilobject_))
		cell = ((TValue *)(p));
	else {
		TValue k;
		{
			TValue *io = (&k);
			((io)->value_).i = (key);
			((io)->tt_ = ((3 | (1 << 4))));
		};
		cell = luaH_newkey(L, t, &k);
	}
	((void)L, *(cell) = *(value), ((void)0));
}

static int unbound_search(Table *t, unsigned int j) {
	unsigned int i = j;
	j++;

	while (!((((luaH_getint(t, j)))->tt_) == (0))) {
		i = j;
		if (j > ((unsigned int)(2147483647)) / 2) {

			i = 1;
			while (!((((luaH_getint(t, i)))->tt_) == (0))) i++;
			return i - 1;
		}
		j *= 2;
	}

	while (j - i > 1) {
		unsigned int m = (i + j) / 2;
		if (((((luaH_getint(t, m)))->tt_) == (0))) j = m;
		else i = m;
	}
	return i;
}

int luaH_getn(Table *t) {
	unsigned int j = t->sizearray;
	if (j > 0 && ((((&t->array[j - 1]))->tt_) == (0))) {

		unsigned int i = 0;
		while (j - i > 1) {
			unsigned int m = (i + j) / 2;
			if (((((&t->array[m - 1]))->tt_) == (0))) j = m;
			else i = m;
		}
		return i;
	}

	else if (((t->node) == (&dummynode_)))
		return j;
	else return unbound_search(t, j);
}

