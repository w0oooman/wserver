
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

__declspec(dllimport) extern int __mb_cur_max;

__declspec(dllimport) int __cdecl ___mb_cur_max_func(void);
__declspec(dllimport) int __cdecl ___mb_cur_max_l_func(_locale_t);

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

__declspec(dllimport) void __cdecl perror(const char * _ErrMsg);

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

__declspec(dllimport) void __cdecl _wperror(const wchar_t * _ErrMsg);

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

static int tonumeral(expdesc *e, TValue *v) {
	if (((e)->t != (e)->f))
		return 0;
	switch (e->k) {
	case VKINT:
		if (v) {
			TValue *io = (v);
			((io)->value_).i = (e->u.ival);
			((io)->tt_ = ((3 | (1 << 4))));
		};
		return 1;
	case VKFLT:
		if (v) {
			TValue *io = (v);
			((io)->value_).n = (e->u.nval);
			((io)->tt_ = ((3 | (0 << 4))));
		};
		return 1;
	default: return 0;
	}
}

void luaK_nil(FuncState *fs, int from, int n) {
	Instruction *previous;
	int l = from + n - 1;
	if (fs->pc > fs->lasttarget) {
		previous = &fs->f->code[fs->pc - 1];
		if ((((OpCode)(((*previous) >> 0) & ((~((~(Instruction)0) << (6))) << (0))))) == OP_LOADNIL) {
			int pfrom = (((int)(((*previous) >> (0 + 6)) & ((~((~(Instruction)0) << (8))) << (0)))));
			int pl = pfrom + (((int)(((*previous) >> (((0 + 6) + 8) + 9)) & ((~((~(Instruction)0) << (9))) << (0)))));
			if ((pfrom <= from && from <= pl + 1) ||
				(from <= pfrom && pfrom <= l + 1)) {
				if (pfrom < from) from = pfrom;
				if (pl > l) l = pl;
				((*previous) = (((*previous)&(~((~((~(Instruction)0) << (8))) << ((0 + 6))))) | ((((Instruction)(from)) << (0 + 6))&((~((~(Instruction)0) << (8))) << ((0 + 6))))));
				((*previous) = (((*previous)&(~((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))) | ((((Instruction)(l - from)) << (((0 + 6) + 8) + 9))&((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))));
				return;
			}
		}
	}
	luaK_codeABC(fs, OP_LOADNIL, from, n - 1, 0);
}


static int getjump(FuncState *fs, int pc) {
	int offset = ((((int)(((fs->f->code[pc]) >> ((0 + 6) + 8)) & ((~((~(Instruction)0) << ((9 + 9)))) << (0))))) - (((1 << (9 + 9)) - 1) >> 1));
	if (offset == (-1))
		return (-1);
	else
		return (pc + 1) + offset;
}

static void fixjump(FuncState *fs, int pc, int dest) {
	Instruction *jmp = &fs->f->code[pc];
	int offset = dest - (pc + 1);
	((void)0);
	if (abs(offset) > (((1 << (9 + 9)) - 1) >> 1))
		luaX_syntaxerror(fs->ls, "control structure too long");
	(((*jmp)) = ((((*jmp))&(~((~((~(Instruction)0) << ((9 + 9)))) << (((0 + 6) + 8))))) | ((((Instruction)(((unsigned int)((offset)+(((1 << (9 + 9)) - 1) >> 1))))) << ((0 + 6) + 8))&((~((~(Instruction)0) << ((9 + 9)))) << (((0 + 6) + 8))))));
}

void luaK_concat(FuncState *fs, int *l1, int l2) {
	if (l2 == (-1)) return;
	else if (*l1 == (-1))
		*l1 = l2;
	else {
		int list = *l1;
		int next;
		while ((next = getjump(fs, list)) != (-1))
			list = next;
		fixjump(fs, list, l2);
	}
}

int luaK_jump(FuncState *fs) {
	int jpc = fs->jpc;
	int j;
	fs->jpc = (-1);
	j = luaK_codeABx(fs, OP_JMP, 0, ((-1)) + (((1 << (9 + 9)) - 1) >> 1));
	luaK_concat(fs, &j, jpc);
	return j;
}

void luaK_ret(FuncState *fs, int first, int nret) {
	luaK_codeABC(fs, OP_RETURN, first, nret + 1, 0);
}

static int condjump(FuncState *fs, OpCode op, int A, int B, int C) {
	luaK_codeABC(fs, op, A, B, C);
	return luaK_jump(fs);
}

int luaK_getlabel(FuncState *fs) {
	fs->lasttarget = fs->pc;
	return fs->pc;
}

static Instruction *getjumpcontrol(FuncState *fs, int pc) {
	Instruction *pi = &fs->f->code[pc];
	if (pc >= 1 && (luaP_opmodes[(((OpCode)(((*(pi - 1)) >> 0) & ((~((~(Instruction)0) << (6))) << (0)))))] & (1 << 7)))
		return pi - 1;
	else
		return pi;
}

static int patchtestreg(FuncState *fs, int node, int reg) {
	Instruction *i = getjumpcontrol(fs, node);
	if ((((OpCode)(((*i) >> 0) & ((~((~(Instruction)0) << (6))) << (0))))) != OP_TESTSET)
		return 0;
	if (reg != ((1 << 8) - 1) && reg != (((int)(((*i) >> (((0 + 6) + 8) + 9)) & ((~((~(Instruction)0) << (9))) << (0))))))
		((*i) = (((*i)&(~((~((~(Instruction)0) << (8))) << ((0 + 6))))) | ((((Instruction)(reg)) << (0 + 6))&((~((~(Instruction)0) << (8))) << ((0 + 6))))));
	else {

		*i = ((((Instruction)(OP_TEST)) << 0) | (((Instruction)((((int)(((*i) >> (((0 + 6) + 8) + 9)) & ((~((~(Instruction)0) << (9))) << (0))))))) << (0 + 6)) | (((Instruction)(0)) << (((0 + 6) + 8) + 9)) | (((Instruction)((((int)(((*i) >> ((0 + 6) + 8)) & ((~((~(Instruction)0) << (9))) << (0))))))) << ((0 + 6) + 8)));
	}
	return 1;
}

static void removevalues(FuncState *fs, int list) {
	for (;
		list != (-1);
		list = getjump(fs, list))
		patchtestreg(fs, list, ((1 << 8) - 1));
}

static void patchlistaux(FuncState *fs, int list, int vtarget, int reg,
	int dtarget) {
	while (list != (-1)) {
		int next = getjump(fs, list);
		if (patchtestreg(fs, list, reg))
			fixjump(fs, list, vtarget);
		else
			fixjump(fs, list, dtarget);
		list = next;
	}
}

static void dischargejpc(FuncState *fs) {
	patchlistaux(fs, fs->jpc, fs->pc, ((1 << 8) - 1), fs->pc);
	fs->jpc = (-1);
}

void luaK_patchtohere(FuncState *fs, int list) {
	luaK_getlabel(fs);
	luaK_concat(fs, &fs->jpc, list);
}

void luaK_patchlist(FuncState *fs, int list, int target) {
	if (target == fs->pc)
		luaK_patchtohere(fs, list);
	else {
		((void)0);
		patchlistaux(fs, list, target, ((1 << 8) - 1), target);
	}
}

void luaK_patchclose(FuncState *fs, int list, int level) {
	level++;
	for (;
		list != (-1);
		list = getjump(fs, list)) {
		((void)0);
		((fs->f->code[list]) = (((fs->f->code[list])&(~((~((~(Instruction)0) << (8))) << ((0 + 6))))) | ((((Instruction)(level)) << (0 + 6))&((~((~(Instruction)0) << (8))) << ((0 + 6))))));
	}
}

static int luaK_code(FuncState *fs, Instruction i) {
	Proto *f = fs->f;
	dischargejpc(fs);

	if ((fs->pc) + 1 > (f->sizecode)) ((f->code) = ((Instruction *)(luaM_growaux_(fs->ls->L, f->code, &(f->sizecode), sizeof(Instruction), 2147483647, "opcodes"))));
	f->code[fs->pc] = i;

	if ((fs->pc) + 1 > (f->sizelineinfo)) ((f->lineinfo) = ((int *)(luaM_growaux_(fs->ls->L, f->lineinfo, &(f->sizelineinfo), sizeof(int), 2147483647, "opcodes"))));
	f->lineinfo[fs->pc] = fs->ls->lastline;
	return fs->pc++;
}

int luaK_codeABC(FuncState *fs, OpCode o, int a, int b, int c) {
	((void)0);
	((void)0);
	((void)0);
	((void)0);
	return luaK_code(fs, ((((Instruction)(o)) << 0) | (((Instruction)(a)) << (0 + 6)) | (((Instruction)(b)) << (((0 + 6) + 8) + 9)) | (((Instruction)(c)) << ((0 + 6) + 8))));
}

int luaK_codeABx(FuncState *fs, OpCode o, int a, unsigned int bc) {
	((void)0);
	((void)0);
	((void)0);
	return luaK_code(fs, ((((Instruction)(o)) << 0) | (((Instruction)(a)) << (0 + 6)) | (((Instruction)(bc)) << ((0 + 6) + 8))));
}

static int codeextraarg(FuncState *fs, int a) {
	((void)0);
	return luaK_code(fs, ((((Instruction)(OP_EXTRAARG)) << 0) | (((Instruction)(a)) << (0 + 6))));
}

int luaK_codek(FuncState *fs, int reg, int k) {
	if (k <= ((1 << (9 + 9)) - 1))
		return luaK_codeABx(fs, OP_LOADK, reg, k);
	else {
		int p = luaK_codeABx(fs, OP_LOADKX, reg, 0);
		codeextraarg(fs, k);
		return p;
	}
}

void luaK_checkstack(FuncState *fs, int n) {
	int newstack = fs->freereg + n;
	if (newstack > fs->f->maxstacksize) {
		if (newstack >= 255)
			luaX_syntaxerror(fs->ls,
			"function or expression needs too many registers");
		fs->f->maxstacksize = ((lu_byte)((newstack)));
	}
}

void luaK_reserveregs(FuncState *fs, int n) {
	luaK_checkstack(fs, n);
	fs->freereg += n;
}

static void freereg(FuncState *fs, int reg) {
	if (!((reg)& (1 << (9 - 1))) && reg >= fs->nactvar) {
		fs->freereg--;
		((void)0);
	}
}

static void freeexp(FuncState *fs, expdesc *e) {
	if (e->k == VNONRELOC)
		freereg(fs, e->u.info);
}

static void freeexps(FuncState *fs, expdesc *e1, expdesc *e2) {
	int r1 = (e1->k == VNONRELOC) ? e1->u.info : -1;
	int r2 = (e2->k == VNONRELOC) ? e2->u.info : -1;
	if (r1 > r2) {
		freereg(fs, r1);
		freereg(fs, r2);
	}
	else {
		freereg(fs, r2);
		freereg(fs, r1);
	}
}

static int addk(FuncState *fs, TValue *key, TValue *v) {
	lua_State *L = fs->ls->L;
	Proto *f = fs->f;
	TValue *idx = luaH_set(L, fs->ls->h, key);
	int k, oldsize;
	if (((((idx))->tt_) == ((3 | (1 << 4))))) {
		k = ((int)(((((idx)->value_).i))));

		if (k < fs->nk && (((&f->k[k])->tt_) & 0x3F) == (((v)->tt_) & 0x3F) &&
			luaV_equalobj(((void *)0), &f->k[k], v))
			return k;
	}

	oldsize = f->sizek;
	k = fs->nk;

	{
		TValue *io = (idx);
		((io)->value_).i = (k);
		((io)->tt_ = ((3 | (1 << 4))));
	};
	if ((k)+1 > (f->sizek)) ((f->k) = ((TValue *)(luaM_growaux_(L, f->k, &(f->sizek), sizeof(TValue), ((1 << (9 + 9 + 8)) - 1), "constants"))));
	while (oldsize < f->sizek) ((&f->k[oldsize++])->tt_ = (0));
	{
		TValue *io1 = (&f->k[k]);
		*io1 = *(v);
		(void)L;
		((void)0);
	};
	fs->nk++;
	(((((v)->tt_) & (1 << 6)) && (((f)->marked) & ((1 << (2)))) && ((((((v)->value_).gc))->marked) & (((1 << (0)) | (1 << (1)))))) ? luaC_barrier_(L, ((&(((union GCUnion *)((f)))->gc))), (((v)->value_).gc)) : ((void)((0))));
	return k;
}

int luaK_stringK(FuncState *fs, TString *s) {
	TValue o;
	{
		TValue *io = (&o);
		TString *x_ = (s);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = (((x_->tt) | (1 << 6))));
		((void)0);
	};
	return addk(fs, &o, &o);
}

int luaK_intK(FuncState *fs, lua_Integer n) {
	TValue k, o;
	{
		TValue *io = (&k);
		((io)->value_).p = (((void*)(((size_t)(n)))));
		((io)->tt_ = (2));
	};
	{
		TValue *io = (&o);
		((io)->value_).i = (n);
		((io)->tt_ = ((3 | (1 << 4))));
	};
	return addk(fs, &k, &o);
}

static int luaK_numberK(FuncState *fs, lua_Number r) {
	TValue o;
	{
		TValue *io = (&o);
		((io)->value_).n = (r);
		((io)->tt_ = ((3 | (0 << 4))));
	};
	return addk(fs, &o, &o);
}

static int boolK(FuncState *fs, int b) {
	TValue o;
	{
		TValue *io = (&o);
		((io)->value_).b = (b);
		((io)->tt_ = (1));
	};
	return addk(fs, &o, &o);
}

static int nilK(FuncState *fs) {
	TValue k, v;
	((&v)->tt_ = (0));

	{
		TValue *io = (&k);
		Table *x_ = (fs->ls->h);
		((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
		((io)->tt_ = (((5) | (1 << 6))));
		((void)0);
	};
	return addk(fs, &k, &v);
}

void luaK_setreturns(FuncState *fs, expdesc *e, int nresults) {
	if (e->k == VCALL) {
		((((fs)->f->code[(e)->u.info])) = (((((fs)->f->code[(e)->u.info]))&(~((~((~(Instruction)0) << (9))) << (((0 + 6) + 8))))) | ((((Instruction)(nresults + 1)) << ((0 + 6) + 8))&((~((~(Instruction)0) << (9))) << (((0 + 6) + 8))))));
	}
	else if (e->k == VVARARG) {
		Instruction *pc = &((fs)->f->code[(e)->u.info]);
		((*pc) = (((*pc)&(~((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))) | ((((Instruction)(nresults + 1)) << (((0 + 6) + 8) + 9))&((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))));
		((*pc) = (((*pc)&(~((~((~(Instruction)0) << (8))) << ((0 + 6))))) | ((((Instruction)(fs->freereg)) << (0 + 6))&((~((~(Instruction)0) << (8))) << ((0 + 6))))));
		luaK_reserveregs(fs, 1);
	}
	else ((void)0);
}

void luaK_setoneret(FuncState *fs, expdesc *e) {
	if (e->k == VCALL) {

		((void)0);
		e->k = VNONRELOC;
		e->u.info = (((int)(((((fs)->f->code[(e)->u.info])) >> (0 + 6)) & ((~((~(Instruction)0) << (8))) << (0)))));
	}
	else if (e->k == VVARARG) {
		((((fs)->f->code[(e)->u.info])) = (((((fs)->f->code[(e)->u.info]))&(~((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))) | ((((Instruction)(2)) << (((0 + 6) + 8) + 9))&((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))));
		e->k = VRELOCABLE;
	}
}

void luaK_dischargevars(FuncState *fs, expdesc *e) {
	switch (e->k) {
	case VLOCAL: {
		e->k = VNONRELOC;
		break;
	}
	case VUPVAL: {
		e->u.info = luaK_codeABC(fs, OP_GETUPVAL, 0, e->u.info, 0);
		e->k = VRELOCABLE;
		break;
	}
	case VINDEXED: {
		OpCode op;
		freereg(fs, e->u.ind.idx);
		if (e->u.ind.vt == VLOCAL) {
			freereg(fs, e->u.ind.t);
			op = OP_GETTABLE;
		}
		else {
			((void)0);
			op = OP_GETTABUP;
		}
		e->u.info = luaK_codeABC(fs, op, 0, e->u.ind.t, e->u.ind.idx);
		e->k = VRELOCABLE;
		break;
	}
	case VVARARG: case VCALL: {
		luaK_setoneret(fs, e);
		break;
	}
	default: break;
	}
}

static void discharge2reg(FuncState *fs, expdesc *e, int reg) {
	luaK_dischargevars(fs, e);
	switch (e->k) {
	case VNIL: {
		luaK_nil(fs, reg, 1);
		break;
	}
	case VFALSE: case VTRUE: {
		luaK_codeABC(fs, OP_LOADBOOL, reg, e->k == VTRUE, 0);
		break;
	}
	case VK: {
		luaK_codek(fs, reg, e->u.info);
		break;
	}
	case VKFLT: {
		luaK_codek(fs, reg, luaK_numberK(fs, e->u.nval));
		break;
	}
	case VKINT: {
		luaK_codek(fs, reg, luaK_intK(fs, e->u.ival));
		break;
	}
	case VRELOCABLE: {
		Instruction *pc = &((fs)->f->code[(e)->u.info]);
		((*pc) = (((*pc)&(~((~((~(Instruction)0) << (8))) << ((0 + 6))))) | ((((Instruction)(reg)) << (0 + 6))&((~((~(Instruction)0) << (8))) << ((0 + 6))))));
		break;
	}
	case VNONRELOC: {
		if (reg != e->u.info)
			luaK_codeABC(fs, OP_MOVE, reg, e->u.info, 0);
		break;
	}
	default: {
		((void)0);
		return;
	}
	}
	e->u.info = reg;
	e->k = VNONRELOC;
}

static void discharge2anyreg(FuncState *fs, expdesc *e) {
	if (e->k != VNONRELOC) {
		luaK_reserveregs(fs, 1);
		discharge2reg(fs, e, fs->freereg - 1);
	}
}

static int code_loadbool(FuncState *fs, int A, int b, int jump) {
	luaK_getlabel(fs);
	return luaK_codeABC(fs, OP_LOADBOOL, A, b, jump);
}

static int need_value(FuncState *fs, int list) {
	for (;
		list != (-1);
		list = getjump(fs, list)) {
		Instruction i = *getjumpcontrol(fs, list);
		if ((((OpCode)(((i) >> 0) & ((~((~(Instruction)0) << (6))) << (0))))) != OP_TESTSET) return 1;
	}
	return 0;
}

static void exp2reg(FuncState *fs, expdesc *e, int reg) {
	discharge2reg(fs, e, reg);
	if (e->k == VJMP)
		luaK_concat(fs, &e->t, e->u.info);
	if (((e)->t != (e)->f)) {
		int final;
		int p_f = (-1);
		int p_t = (-1);
		if (need_value(fs, e->t) || need_value(fs, e->f)) {
			int fj = (e->k == VJMP) ? (-1) : luaK_jump(fs);
			p_f = code_loadbool(fs, reg, 0, 1);
			p_t = code_loadbool(fs, reg, 1, 0);
			luaK_patchtohere(fs, fj);
		}
		final = luaK_getlabel(fs);
		patchlistaux(fs, e->f, final, reg, p_f);
		patchlistaux(fs, e->t, final, reg, p_t);
	}
	e->f = e->t = (-1);
	e->u.info = reg;
	e->k = VNONRELOC;
}

void luaK_exp2nextreg(FuncState *fs, expdesc *e) {
	luaK_dischargevars(fs, e);
	freeexp(fs, e);
	luaK_reserveregs(fs, 1);
	exp2reg(fs, e, fs->freereg - 1);
}

int luaK_exp2anyreg(FuncState *fs, expdesc *e) {
	luaK_dischargevars(fs, e);
	if (e->k == VNONRELOC) {
		if (!((e)->t != (e)->f))
			return e->u.info;
		if (e->u.info >= fs->nactvar) {
			exp2reg(fs, e, e->u.info);
			return e->u.info;
		}
	}
	luaK_exp2nextreg(fs, e);
	return e->u.info;
}

void luaK_exp2anyregup(FuncState *fs, expdesc *e) {
	if (e->k != VUPVAL || ((e)->t != (e)->f))
		luaK_exp2anyreg(fs, e);
}

void luaK_exp2val(FuncState *fs, expdesc *e) {
	if (((e)->t != (e)->f))
		luaK_exp2anyreg(fs, e);
	else
		luaK_dischargevars(fs, e);
}


int luaK_exp2RK(FuncState *fs, expdesc *e) {
	luaK_exp2val(fs, e);
	switch (e->k) {
	case VTRUE: e->u.info = boolK(fs, 1);
		goto vk;
	case VFALSE: e->u.info = boolK(fs, 0);
		goto vk;
	case VNIL: e->u.info = nilK(fs);
		goto vk;
	case VKINT: e->u.info = luaK_intK(fs, e->u.ival);
		goto vk;
	case VKFLT: e->u.info = luaK_numberK(fs, e->u.nval);
		goto vk;
	case VK:
	vk :
		e->k = VK;
	   if (e->u.info <= ((1 << (9 - 1)) - 1))
		   return ((e->u.info) | (1 << (9 - 1)));
	   else break;
	default: break;
	}

	return luaK_exp2anyreg(fs, e);
}

void luaK_storevar(FuncState *fs, expdesc *var, expdesc *ex) {
	switch (var->k) {
	case VLOCAL: {
		freeexp(fs, ex);
		exp2reg(fs, ex, var->u.info);
		return;
	}
	case VUPVAL: {
		int e = luaK_exp2anyreg(fs, ex);
		luaK_codeABC(fs, OP_SETUPVAL, e, var->u.info, 0);
		break;
	}
	case VINDEXED: {
		OpCode op = (var->u.ind.vt == VLOCAL) ? OP_SETTABLE : OP_SETTABUP;
		int e = luaK_exp2RK(fs, ex);
		luaK_codeABC(fs, op, var->u.ind.t, var->u.ind.idx, e);
		break;
	}
	default: ((void)0);
	}
	freeexp(fs, ex);
}

void luaK_self(FuncState *fs, expdesc *e, expdesc *key) {
	int ereg;
	luaK_exp2anyreg(fs, e);
	ereg = e->u.info;
	freeexp(fs, e);
	e->u.info = fs->freereg;
	e->k = VNONRELOC;
	luaK_reserveregs(fs, 2);
	luaK_codeABC(fs, OP_SELF, e->u.info, ereg, luaK_exp2RK(fs, key));
	freeexp(fs, key);
}

static void negatecondition(FuncState *fs, expdesc *e) {
	Instruction *pc = getjumpcontrol(fs, e->u.info);
	((void)0);
	((*pc) = (((*pc)&(~((~((~(Instruction)0) << (8))) << ((0 + 6))))) | ((((Instruction)(!((((int)(((*pc) >> (0 + 6)) & ((~((~(Instruction)0) << (8))) << (0)))))))) << (0 + 6))&((~((~(Instruction)0) << (8))) << ((0 + 6))))));
}

static int jumponcond(FuncState *fs, expdesc *e, int cond) {
	if (e->k == VRELOCABLE) {
		Instruction ie = ((fs)->f->code[(e)->u.info]);
		if ((((OpCode)(((ie) >> 0) & ((~((~(Instruction)0) << (6))) << (0))))) == OP_NOT) {
			fs->pc--;
			return condjump(fs, OP_TEST, (((int)(((ie) >> (((0 + 6) + 8) + 9)) & ((~((~(Instruction)0) << (9))) << (0))))), 0, !cond);
		}

	}
	discharge2anyreg(fs, e);
	freeexp(fs, e);
	return condjump(fs, OP_TESTSET, ((1 << 8) - 1), e->u.info, cond);
}

void luaK_goiftrue(FuncState *fs, expdesc *e) {
	int pc;
	luaK_dischargevars(fs, e);
	switch (e->k) {
	case VJMP: {
		negatecondition(fs, e);
		pc = e->u.info;
		break;
	}
	case VK: case VKFLT: case VKINT: case VTRUE: {
		pc = (-1);
		break;
	}
	default: {
		pc = jumponcond(fs, e, 0);
		break;
	}
	}
	luaK_concat(fs, &e->f, pc);
	luaK_patchtohere(fs, e->t);
	e->t = (-1);
}

void luaK_goiffalse(FuncState *fs, expdesc *e) {
	int pc;
	luaK_dischargevars(fs, e);
	switch (e->k) {
	case VJMP: {
		pc = e->u.info;
		break;
	}
	case VNIL: case VFALSE: {
		pc = (-1);
		break;
	}
	default: {
		pc = jumponcond(fs, e, 1);
		break;
	}
	}
	luaK_concat(fs, &e->t, pc);
	luaK_patchtohere(fs, e->f);
	e->f = (-1);
}

static void codenot(FuncState *fs, expdesc *e) {
	luaK_dischargevars(fs, e);
	switch (e->k) {
	case VNIL: case VFALSE: {
		e->k = VTRUE;
		break;
	}
	case VK: case VKFLT: case VKINT: case VTRUE: {
		e->k = VFALSE;
		break;
	}
	case VJMP: {
		negatecondition(fs, e);
		break;
	}
	case VRELOCABLE:
	case VNONRELOC: {
		discharge2anyreg(fs, e);
		freeexp(fs, e);
		e->u.info = luaK_codeABC(fs, OP_NOT, 0, e->u.info, 0);
		e->k = VRELOCABLE;
		break;
	}
	default: ((void)0);
	}

  {
	  int temp = e->f;
	  e->f = e->t;
	  e->t = temp;
  }
	removevalues(fs, e->f);
	removevalues(fs, e->t);
}

void luaK_indexed(FuncState *fs, expdesc *t, expdesc *k) {
	((void)0);
	t->u.ind.t = t->u.info;
	t->u.ind.idx = luaK_exp2RK(fs, k);
	t->u.ind.vt = (t->k == VUPVAL) ? VUPVAL : VLOCAL;
	t->k = VINDEXED;
}

static int validop(int op, TValue *v1, TValue *v2) {
	switch (op) {
	case 7: case 8: case 9:
	case 10: case 11: case 13: {
		lua_Integer i;
		return ((((((v1))->tt_) == ((3 | (1 << 4)))) ? (*(&i) = (((v1)->value_).i), 1) : luaV_tointeger(v1, &i, 0)) && (((((v2))->tt_) == ((3 | (1 << 4)))) ? (*(&i) = (((v2)->value_).i), 1) : luaV_tointeger(v2, &i, 0)));
	}
	case 5: case 6: case 3:
		return (((((((v2))->tt_) == ((3 | (1 << 4)))) ? ((lua_Number)(((((v2)->value_).i)))) : (((v2)->value_).n))) != 0);
	default: return 1;
	}
}

static int constfolding(FuncState *fs, int op, expdesc *e1, expdesc *e2) {
	TValue v1, v2, res;
	if (!tonumeral(e1, &v1) || !tonumeral(e2, &v2) || !validop(op, &v1, &v2))
		return 0;
	luaO_arith(fs->ls->L, op, &v1, &v2, &res);
	if (((((&res))->tt_) == ((3 | (1 << 4))))) {
		e1->k = VKINT;
		e1->u.ival = (((&res)->value_).i);
	}
	else {
		lua_Number n = (((&res)->value_).n);
		if ((!(((n)) == ((n)))) || n == 0)
			return 0;
		e1->k = VKFLT;
		e1->u.nval = n;
	}
	return 1;
}

static void codeunexpval(FuncState *fs, OpCode op, expdesc *e, int line) {
	int r = luaK_exp2anyreg(fs, e);
	freeexp(fs, e);
	e->u.info = luaK_codeABC(fs, op, 0, r, 0);
	e->k = VRELOCABLE;
	luaK_fixline(fs, line);
}

static void codebinexpval(FuncState *fs, OpCode op,
	expdesc *e1, expdesc *e2, int line) {
	int rk1 = luaK_exp2RK(fs, e1);
	int rk2 = luaK_exp2RK(fs, e2);
	freeexps(fs, e1, e2);
	e1->u.info = luaK_codeABC(fs, op, 0, rk1, rk2);
	e1->k = VRELOCABLE;
	luaK_fixline(fs, line);
}

static void codecomp(FuncState *fs, BinOpr opr, expdesc *e1, expdesc *e2) {
	int rk1 = (e1->k == VK) ? ((e1->u.info) | (1 << (9 - 1)))
		: (e1->u.info);
	int rk2 = luaK_exp2RK(fs, e2);
	freeexps(fs, e1, e2);
	switch (opr) {
	case OPR_NE: {
		e1->u.info = condjump(fs, OP_EQ, 0, rk1, rk2);
		break;
	}
	case OPR_GT: case OPR_GE: {

		OpCode op = ((OpCode)((opr - OPR_NE) + OP_EQ));
		e1->u.info = condjump(fs, op, 1, rk2, rk1);
		break;
	}
	default: {
		OpCode op = ((OpCode)((opr - OPR_EQ) + OP_EQ));
		e1->u.info = condjump(fs, op, 1, rk1, rk2);
		break;
	}
	}
	e1->k = VJMP;
}

void luaK_prefix(FuncState *fs, UnOpr op, expdesc *e, int line) {
	static expdesc ef = {
		VKINT, {
			0
		}, (-1), (-1)
	};
	switch (op) {
	case OPR_MINUS: case OPR_BNOT:
		if (constfolding(fs, op + 12, e, &ef))
			break;

	case OPR_LEN:
		codeunexpval(fs, ((OpCode)(op + OP_UNM)), e, line);
		break;
	case OPR_NOT: codenot(fs, e);
		break;
	default: ((void)0);
	}
}

void luaK_infix(FuncState *fs, BinOpr op, expdesc *v) {
	switch (op) {
	case OPR_AND: {
		luaK_goiftrue(fs, v);
		break;
	}
	case OPR_OR: {
		luaK_goiffalse(fs, v);
		break;
	}
	case OPR_CONCAT: {
		luaK_exp2nextreg(fs, v);
		break;
	}
	case OPR_ADD: case OPR_SUB:
	case OPR_MUL: case OPR_DIV: case OPR_IDIV:
	case OPR_MOD: case OPR_POW:
	case OPR_BAND: case OPR_BOR: case OPR_BXOR:
	case OPR_SHL: case OPR_SHR: {
		if (!tonumeral(v, ((void *)0)))
			luaK_exp2RK(fs, v);

		break;
	}
	default: {
		luaK_exp2RK(fs, v);
		break;
	}
	}
}

void luaK_posfix(FuncState *fs, BinOpr op,
	expdesc *e1, expdesc *e2, int line) {
	switch (op) {
	case OPR_AND: {
		((void)0);
		luaK_dischargevars(fs, e2);
		luaK_concat(fs, &e2->f, e1->f);
		*e1 = *e2;
		break;
	}
	case OPR_OR: {
		((void)0);
		luaK_dischargevars(fs, e2);
		luaK_concat(fs, &e2->t, e1->t);
		*e1 = *e2;
		break;
	}
	case OPR_CONCAT: {
		luaK_exp2val(fs, e2);
		if (e2->k == VRELOCABLE &&
			(((OpCode)(((((fs)->f->code[(e2)->u.info])) >> 0) & ((~((~(Instruction)0) << (6))) << (0))))) == OP_CONCAT) {
			((void)0);
			freeexp(fs, e1);
			((((fs)->f->code[(e2)->u.info])) = (((((fs)->f->code[(e2)->u.info]))&(~((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))) | ((((Instruction)(e1->u.info)) << (((0 + 6) + 8) + 9))&((~((~(Instruction)0) << (9))) << ((((0 + 6) + 8) + 9))))));
			e1->k = VRELOCABLE;
			e1->u.info = e2->u.info;
		}
		else {
			luaK_exp2nextreg(fs, e2);
			codebinexpval(fs, OP_CONCAT, e1, e2, line);
		}
		break;
	}
	case OPR_ADD: case OPR_SUB: case OPR_MUL: case OPR_DIV:
	case OPR_IDIV: case OPR_MOD: case OPR_POW:
	case OPR_BAND: case OPR_BOR: case OPR_BXOR:
	case OPR_SHL: case OPR_SHR: {
		if (!constfolding(fs, op + 0, e1, e2))
			codebinexpval(fs, ((OpCode)(op + OP_ADD)), e1, e2, line);
		break;
	}
	case OPR_EQ: case OPR_LT: case OPR_LE:
	case OPR_NE: case OPR_GT: case OPR_GE: {
		codecomp(fs, op, e1, e2);
		break;
	}
	default: ((void)0);
	}
}

void luaK_fixline(FuncState *fs, int line) {
	fs->f->lineinfo[fs->pc - 1] = line;
}

void luaK_setlist(FuncState *fs, int base, int nelems, int tostore) {
	int c = (nelems - 1) / 50 + 1;
	int b = (tostore == (-1)) ? 0 : tostore;
	((void)0);
	if (c <= ((1 << 9) - 1))
		luaK_codeABC(fs, OP_SETLIST, base, b, c);
	else if (c <= ((1 << (9 + 9 + 8)) - 1)) {
		luaK_codeABC(fs, OP_SETLIST, base, b, 0);
		codeextraarg(fs, c);
	}
	else
		luaX_syntaxerror(fs->ls, "constructor too long");
	fs->freereg = base + 1;
}

