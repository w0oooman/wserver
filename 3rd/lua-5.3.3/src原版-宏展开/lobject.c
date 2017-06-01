
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

void __declspec(dllimport) __cdecl _vacopy(va_list *, va_list);

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

const TValue luaO_nilobject_ = {
		{
			((void *)0)
		}, 0
};

int luaO_int2fb(unsigned int x) {
	int e = 0;
	if (x < 8) return x;
	while (x >= (8 << 4)) {
		x = (x + 0xf) >> 4;
		e += 4;
	}
	while (x >= (8 << 1)) {
		x = (x + 1) >> 1;
		e++;
	}
	return ((e + 1) << 3) | (((int)((x))) - 8);
}

int luaO_fb2int(int x) {
	return (x < 8) ? x : ((x & 7) + 8) << ((x >> 3) - 1);
}

int luaO_ceillog2(unsigned int x) {
	static const lu_byte log_2[256] = {
		0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
	};
	int l = 0;
	x--;
	while (x >= 256) {
		l += 8;
		x >>= 8;
	}
	return l + log_2[x];
}

static lua_Integer intarith(lua_State *L, int op, lua_Integer v1,
	lua_Integer v2) {
	switch (op) {
	case 0: return ((lua_Integer)(((lua_Unsigned)(v1)) + ((lua_Unsigned)(v2))));
	case 1:return ((lua_Integer)(((lua_Unsigned)(v1)) - ((lua_Unsigned)(v2))));
	case 2:return ((lua_Integer)(((lua_Unsigned)(v1)) * ((lua_Unsigned)(v2))));
	case 3: return luaV_mod(L, v1, v2);
	case 6: return luaV_div(L, v1, v2);
	case 7: return ((lua_Integer)(((lua_Unsigned)(v1)) & ((lua_Unsigned)(v2))));
	case 8: return ((lua_Integer)(((lua_Unsigned)(v1)) | ((lua_Unsigned)(v2))));
	case 9: return ((lua_Integer)(((lua_Unsigned)(v1)) ^ ((lua_Unsigned)(v2))));
	case 10: return luaV_shiftl(v1, v2);
	case 11: return luaV_shiftl(v1, -v2);
	case 12: return ((lua_Integer)(((lua_Unsigned)(0)) - ((lua_Unsigned)(v1))));
	case 13: return ((lua_Integer)(((lua_Unsigned)(~((lua_Unsigned)(0)))) ^ ((lua_Unsigned)(v1))));
	default: ((void)0);
		return 0;
	}
}

static lua_Number numarith(lua_State *L, int op, lua_Number v1,
	lua_Number v2) {
	switch (op) {
	case 0: return ((v1)+(v2));
	case 1: return ((v1)-(v2));
	case 2: return ((v1)*(v2));
	case 5: return ((v1) / (v2));
	case 4: return ((void)L, (lua_Number)pow(v1, v2));
	case 6: return ((void)L, ((lua_Number)floor(((v1) / (v2)))));
	case 12: return (-(v1));
	case 3: {
		lua_Number m;
		{
			(m) = (lua_Number)fmod(v1, v2);
			if ((m)*(v2) < 0) (m) += (v2);
		};
		return m;
	}
	default: ((void)0);
		return 0;
	}
}

void luaO_arith(lua_State *L, int op, const TValue *p1, const TValue *p2,
	TValue *res) {
	switch (op) {
	case 7: case 8: case 9:
	case 10: case 11:
	case 13: {
		lua_Integer i1;
		lua_Integer i2;
		if ((((((p1))->tt_) == ((3 | (1 << 4)))) ? (*(&i1) = (((p1)->value_).i), 1) : luaV_tointeger(p1, &i1, 0)) && (((((p2))->tt_) == ((3 | (1 << 4)))) ? (*(&i2) = (((p2)->value_).i), 1) : luaV_tointeger(p2, &i2, 0))) {
				{
					TValue *io = (res);
					((io)->value_).i = (intarith(L, op, i1, i2));
					((io)->tt_ = ((3 | (1 << 4))));
				};
			return;
		}
		else break;
	}
	case 5: case 4: {
		lua_Number n1;
		lua_Number n2;
		if ((((((p1))->tt_) == ((3 | (0 << 4)))) ? (*(&n1) = (((p1)->value_).n), 1) : luaV_tonumber_(p1, &n1)) && (((((p2))->tt_) == ((3 | (0 << 4)))) ? (*(&n2) = (((p2)->value_).n), 1) : luaV_tonumber_(p2, &n2))) {
				{
					TValue *io = (res);
					((io)->value_).n = (numarith(L, op, n1, n2));
					((io)->tt_ = ((3 | (0 << 4))));
				};
			return;
		}
		else break;
	}
	default: {
		lua_Number n1;
		lua_Number n2;
		if (((((p1))->tt_) == ((3 | (1 << 4)))) && ((((p2))->tt_) == ((3 | (1 << 4))))) {
				{
					TValue *io = (res);
					((io)->value_).i = (intarith(L, op, (((p1)->value_).i), (((p2)->value_).i)));
					((io)->tt_ = ((3 | (1 << 4))));
				};
			return;
		}
		else if ((((((p1))->tt_) == ((3 | (0 << 4)))) ? (*(&n1) = (((p1)->value_).n), 1) : luaV_tonumber_(p1, &n1)) && (((((p2))->tt_) == ((3 | (0 << 4)))) ? (*(&n2) = (((p2)->value_).n), 1) : luaV_tonumber_(p2, &n2))) {
				{
					TValue *io = (res);
					((io)->value_).n = (numarith(L, op, n1, n2));
					((io)->tt_ = ((3 | (0 << 4))));
				};
			return;
		}
		else break;
	}
	}

	((void)0);
	luaT_trybinTM(L, p1, p2, res, ((TMS)((op - 0) + TM_ADD)));
}

int luaO_hexavalue(int c) {
	if ((luai_ctype_[(c)+1] & ((1 << (1))))) return c - '0';
	else return (((c) | ('A' ^ 'a')) - 'a') + 10;
}

static int isneg(const char **s) {
	if (**s == '-') {
		(*s)++;
		return 1;
	}
	else if (**s == '+') (*s)++;
	return 0;
}

static lua_Number lua_strx2number(const char *s, char **endptr) {
	int dot = (localeconv()->decimal_point[0]);
	lua_Number r = 0.0;
	int sigdig = 0;
	int nosigdig = 0;
	int e = 0;
	int neg;
	int hasdot = 0;
	*endptr = ((char *)(s));
	while ((luai_ctype_[(((unsigned char)((*s)))) + 1] & ((1 << (3))))) s++;
	neg = isneg(&s);
	if (!(*s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X')))
		return 0.0;
	for (s += 2;
		;
		s++) {
		if (*s == dot) {
			if (hasdot) break;
			else hasdot = 1;
		}
		else if ((luai_ctype_[(((unsigned char)((*s)))) + 1] & ((1 << (4))))) {
			if (sigdig == 0 && *s == '0')
				nosigdig++;
			else if (++sigdig <= 30)
				r = (r * ((lua_Number)((16.0)))) + luaO_hexavalue(*s);
			else e++;
			if (hasdot) e--;
		}
		else break;
	}
	if (nosigdig + sigdig == 0)
		return 0.0;
	*endptr = ((char *)(s));
	e *= 4;
	if (*s == 'p' || *s == 'P') {
		int exp1 = 0;
		int neg1;
		s++;
		neg1 = isneg(&s);
		if (!(luai_ctype_[(((unsigned char)((*s)))) + 1] & ((1 << (1)))))
			return 0.0;
		while ((luai_ctype_[(((unsigned char)((*s)))) + 1] & ((1 << (1)))))
			exp1 = exp1 * 10 + *(s++) - '0';
		if (neg1) exp1 = -exp1;
		e += exp1;
		*endptr = ((char *)(s));
	}
	if (neg) r = -r;
	return (lua_Number)ldexp(r, e);
}

static const char *l_str2dloc(const char *s, lua_Number *result, int mode) {
	char *endptr;
	*result = (mode == 'x') ? lua_strx2number(s, &endptr)
		: ((lua_Number)strtod((s), (&endptr)));
	if (endptr == s) return ((void *)0);
	while ((luai_ctype_[(((unsigned char)((*endptr)))) + 1] & ((1 << (3))))) endptr++;
	return (*endptr == '\0') ? endptr : ((void *)0);
}

static const char *l_str2d(const char *s, lua_Number *result) {
	const char *endptr;
	const char *pmode = strpbrk(s, ".xXnN");
	int mode = pmode ? ((((unsigned char)((*pmode)))) | ('A' ^ 'a')) : 0;
	if (mode == 'n')
		return ((void *)0);
	endptr = l_str2dloc(s, result, mode);
	if (endptr == ((void *)0)) {
		char buff[200 + 1];
		char *pdot = strchr(s, '.');
		if (strlen(s) > 200 || pdot == ((void *)0))
			return ((void *)0);
		strcpy(buff, s);
		buff[pdot - s] = (localeconv()->decimal_point[0]);
		endptr = l_str2dloc(buff, result, mode);
		if (endptr != ((void *)0))
			endptr = s + (endptr - buff);
	}
	return endptr;
}

static const char *l_str2int(const char *s, lua_Integer *result) {
	lua_Unsigned a = 0;
	int empty = 1;
	int neg;
	while ((luai_ctype_[(((unsigned char)((*s)))) + 1] & ((1 << (3))))) s++;
	neg = isneg(&s);
	if (s[0] == '0' &&
		(s[1] == 'x' || s[1] == 'X')) {
		s += 2;
		for (;
			(luai_ctype_[(((unsigned char)((*s)))) + 1] & ((1 << (4))));
			s++) {
			a = a * 16 + luaO_hexavalue(*s);
			empty = 0;
		}
	}
	else {
		for (;
			(luai_ctype_[(((unsigned char)((*s)))) + 1] & ((1 << (1))));
			s++) {
			int d = *s - '0';
			if (a >= ((lua_Unsigned)(9223372036854775807i64 / 10)) && (a > ((lua_Unsigned)(9223372036854775807i64 / 10)) || d > ((int)((9223372036854775807i64 % 10))) + neg))
				return ((void *)0);
			a = a * 10 + d;
			empty = 0;
		}
	}
	while ((luai_ctype_[(((unsigned char)((*s)))) + 1] & ((1 << (3))))) s++;
	if (empty || *s != '\0') return ((void *)0);
	else {
		*result = ((lua_Integer)((neg) ? 0u - a : a));
		return s;
	}
}

size_t luaO_str2num(const char *s, TValue *o) {
	lua_Integer i;
	lua_Number n;
	const char *e;
	if ((e = l_str2int(s, &i)) != ((void *)0)) {
			{
				TValue *io = (o);
				((io)->value_).i = (i);
				((io)->tt_ = ((3 | (1 << 4))));
			};
	}
	else if ((e = l_str2d(s, &n)) != ((void *)0)) {
			{
				TValue *io = (o);
				((io)->value_).n = (n);
				((io)->tt_ = ((3 | (0 << 4))));
			};
	}
	else
		return 0;
	return (e - s) + 1;
}

int luaO_utf8esc(char *buff, unsigned long x) {
	int n = 1;
	((void)0);
	if (x < 0x80)
		buff[8 - 1] = ((char)(x));
	else {
		unsigned int mfb = 0x3f;
		do {
			buff[8 - (n++)] = ((char)(0x80 | (x & 0x3f)));
			x >>= 6;
			mfb >>= 1;
		} while (x > mfb);
		buff[8 - n] = ((char)((~mfb << 1) | x));
	}
	return n;
}

void luaO_tostring(lua_State *L, StkId obj) {
	char buff[50];
	size_t len;
	((void)0);
	if (((((obj))->tt_) == ((3 | (1 << 4)))))
		len = ((void)(sizeof(buff)), sprintf((buff), "%" "ll" "d", ((((obj)->value_).i))));
	else {
		len = ((void)(sizeof(buff)), sprintf((buff), "%.14g", ((((obj)->value_).n))));

		if (buff[strspn(buff, "-0123456789")] == '\0') {
			buff[len++] = (localeconv()->decimal_point[0]);
			buff[len++] = '0';
		}

	}
  {
	  TValue *io = (obj);
	  TString *x_ = (luaS_newlstr(L, buff, len));
	  ((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
	  ((io)->tt_ = (((x_->tt) | (1 << 6))));
	  ((void)0);
  };
}

static void pushstr(lua_State *L, const char *str, size_t l) {
		{
			TValue *io = (L->top);
			TString *x_ = (luaS_newlstr(L, str, l));
			((io)->value_).gc = ((&(((union GCUnion *)((x_)))->gc)));
			((io)->tt_ = (((x_->tt) | (1 << 6))));
			((void)0);
		};
	luaD_inctop(L);
}

const char *luaO_pushvfstring(lua_State *L, const char *fmt, va_list argp) {
	int n = 0;
	for (;
		;
		) {
		const char *e = strchr(fmt, '%');
		if (e == ((void *)0)) break;
		pushstr(L, fmt, e - fmt);
		switch (*(e + 1)) {
		case 's': {
			const char *s = (*(char * *)((argp += ((sizeof(char *) + sizeof(int) - 1) & ~(sizeof(int) - 1))) - ((sizeof(char *) + sizeof(int) - 1) & ~(sizeof(int) - 1))));
			if (s == ((void *)0)) s = "(null)";
			pushstr(L, s, strlen(s));
			break;
		}
		case 'c': {
			char buff = ((char)((*(int *)((argp += ((sizeof(int) + sizeof(int) - 1) & ~(sizeof(int) - 1))) - ((sizeof(int) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
			if ((luai_ctype_[(((unsigned char)((buff)))) + 1] & ((1 << (2)))))
				pushstr(L, &buff, 1);
			else
				luaO_pushfstring(L, "<\\%d>", ((unsigned char)((buff))));
			break;
		}
		case 'd': {
				{
					TValue *io = (L->top);
					((io)->value_).i = ((*(int *)((argp += ((sizeof(int) + sizeof(int) - 1) & ~(sizeof(int) - 1))) - ((sizeof(int) + sizeof(int) - 1) & ~(sizeof(int) - 1)))));
					((io)->tt_ = ((3 | (1 << 4))));
				};
			goto top2str;
		}
		case 'I': {
				{
					TValue *io = (L->top);
					((io)->value_).i = (((lua_Integer)((*(l_uacInt *)((argp += ((sizeof(l_uacInt) + sizeof(int) - 1) & ~(sizeof(int) - 1))) - ((sizeof(l_uacInt) + sizeof(int) - 1) & ~(sizeof(int) - 1)))))));
					((io)->tt_ = ((3 | (1 << 4))));
				};
			goto top2str;
		}
		case 'f': {
				{
					TValue *io = (L->top);
					((io)->value_).n = (((lua_Number)(((*(l_uacNumber *)((argp += ((sizeof(l_uacNumber) + sizeof(int) - 1) & ~(sizeof(int) - 1))) - ((sizeof(l_uacNumber) + sizeof(int) - 1) & ~(sizeof(int) - 1))))))));
					((io)->tt_ = ((3 | (0 << 4))));
				};
		top2str:
			luaD_inctop(L);
			luaO_tostring(L, L->top - 1);
			break;
		}
		case 'p': {
			char buff[4 * sizeof(void *) + 8];
			int l = ((void)(sizeof(buff)), sprintf(buff, "%p", (*(void * *)((argp += ((sizeof(void *) + sizeof(int) - 1) & ~(sizeof(int) - 1))) - ((sizeof(void *) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
			pushstr(L, buff, l);
			break;
		}
		case 'U': {
			char buff[8];
			int l = luaO_utf8esc(buff, ((long)((*(long *)((argp += ((sizeof(long) + sizeof(int) - 1) & ~(sizeof(int) - 1))) - ((sizeof(long) + sizeof(int) - 1) & ~(sizeof(int) - 1)))))));
			pushstr(L, buff + 8 - l, l);
			break;
		}
		case '%': {
			pushstr(L, "%", 1);
			break;
		}
		default: {
			luaG_runerror(L, "invalid option '%%%c' to 'lua_pushfstring'",
				*(e + 1));
		}
		}
		n += 2;
		fmt = e + 2;
	}
	if (L->stack_last - L->top <= (1)) {
		(void)0;
		luaD_growstack(L, 1);
		(void)0;
	}
	else {
		((void)0);
	};
	pushstr(L, fmt, strlen(fmt));
	if (n > 0) luaV_concat(L, n + 1);
	return (((char *)((((&((((union GCUnion *)((((L->top - 1)->value_).gc))))->ts)))))) + sizeof(UTString));
}

const char *luaO_pushfstring(lua_State *L, const char *fmt, ...) {
	const char *msg;
	va_list argp;
	(argp = (va_list)(&(fmt)) + ((sizeof(fmt) + sizeof(int) - 1) & ~(sizeof(int) - 1)));
	msg = luaO_pushvfstring(L, fmt, argp);
	(argp = (va_list)0);
	return msg;
}

void luaO_chunkid(char *out, const char *source, size_t bufflen) {
	size_t l = strlen(source);
	if (*source == '=') {
		if (l <= bufflen)
			memcpy(out, source + 1, l * sizeof(char));
		else {
			(memcpy(out, source + 1, (bufflen - 1) * sizeof(char)), out += (bufflen - 1));
			*out = '\0';
		}
	}
	else if (*source == '@') {
		if (l <= bufflen)
			memcpy(out, source + 1, l * sizeof(char));
		else {
			(memcpy(out, "...", ((sizeof("...") / sizeof(char) - 1)) * sizeof(char)), out += ((sizeof("...") / sizeof(char) - 1)));
			bufflen -= (sizeof("...") / sizeof(char) - 1);
			memcpy(out, source + 1 + l - bufflen, bufflen * sizeof(char));
		}
	}
	else {
		const char *nl = strchr(source, '\n');
		(memcpy(out, "[string \"", ((sizeof("[string \"") / sizeof(char) - 1)) * sizeof(char)), out += ((sizeof("[string \"") / sizeof(char) - 1)));
		bufflen -= (sizeof("[string \"" "..." "\"]") / sizeof(char) - 1) + 1;
		if (l < bufflen && nl == ((void *)0)) {
			(memcpy(out, source, (l)* sizeof(char)), out += (l));
		}
		else {
			if (nl != ((void *)0)) l = nl - source;
			if (l > bufflen) l = bufflen;
			(memcpy(out, source, (l)* sizeof(char)), out += (l));
			(memcpy(out, "...", ((sizeof("...") / sizeof(char) - 1)) * sizeof(char)), out += ((sizeof("...") / sizeof(char) - 1)));
		}
		memcpy(out, "\"]", ((sizeof("\"]") / sizeof(char) - 1) + 1) * sizeof(char));
	}
}

