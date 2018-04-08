/*
** $Id: lserialize.c,v 1.286 2016/11/25 15:53:09 whb Exp $
** serialize functions to binary
** only string/table/number(int/bool/double) can be serialized
*/

#include "lprefix.h"


#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lua.h"
#include "lauxlib.h"

#include "ldebug.h"
#include "ldo.h"
#include "lgc.h"
#include "lmem.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "lvm.h"
#include "llimits.h"
#include "luaconf.h"
#include "lapi.h"

/* #define seri_lua_registryindex (LUA_REGISTRYINDEX - 99) */
#define seri_lua_registryindex LUA_REGISTRYINDEX
#define seri_lua_registryname  "seri_lua_r"

/* 此版本的LUA用64位来存储整形,所以hash表分别用1个字节来表示key/value序列化信息,
** 格式如下:0000 0000:右边4位表示类型,左边4位表示长度(因此，如果是数字,4位二进制
** 最多为0-15位,而2^16已经远远大于64位整数的范围,如果是字符，则最多可以表示15个字
** 符的长度,大于15个字节的字符后面跟00表示此字符结束!),
** 如{[7] = 257},开始四个字节表示table总长度,一个字节表示key长度，一个字节表示key数据，
** 一个字节表示value长度，两个字节表示257的长度，所以编码后结果为:07 00 00 00 11 07 21 01 01
** 07 00 00 00表示长度，编码后数据占7个字节,第一个11表示key是数字且占一个字节,
** 同理21表示value是数字且占两个字节07和0101表示数字值
** 对于table,则以特殊标志作为开始和结束(seri_table_begin/seri_table_end)
*/
#define seri_header_int       0x01
#define seri_header_string    0x02
#define seri_header_double    0x03
#define seri_header_bool      0x04

// begin and end sigh of lua table 
#define seri_table_begin      0x0e
#define seri_table_end        0x0f

#define serialize_short         0   // buf too short
#define serialize_sucess        1
#define serialize_typeerr      -1
#define serialize_trunc        -2
#define serialize_null         -3
#define serialize_long         -4   // buf too long
#define unserialize_long       -5 
#define serialize_unknow       -6

#define serialize_looptable    -50

int serialize_table(lua_State *L, Table *t, void **buf, int *psize);

typedef struct{
	int errcode;
	char *errinfo;
}error_info;

static error_info error_info_[] = 
{
	{ serialize_typeerr , "serialize type error."},
	{ serialize_trunc, "serialize data truncate.." },
	{ serialize_null, "serialize data null or buff size short." },
	{ serialize_long, "serialize size too long." },
	{ unserialize_long, "unserialize data too long." },
	{ serialize_unknow, "serialize unknow error." }
};

#define unserialize_table_end  -100 // table end


#define seri_maxlen      ((((unsigned int)~0)>>5)+1)  // max serialize length,should be <= 2^27!!
#define seri_lenbytes    4                            // serialize length bytes
#define seri_lenstring   15                           // longer than 15 then use 00 endian

static const unsigned char ucLuaIntLen_ = sizeof(lua_Integer);  // len of lua_Integer
static char strShortBuf_[seri_lenstring + 1];                   // short buf

#define seri_conv_pchar(v) \
	((char*)(v))
#define seri_conv_pint(v) \
	((lua_Integer*)(v))

#define seri_conv_char(v) \
	((char)(v))
#define seri_conv_int(v) \
	((lua_Integer)(v))


#define seri_bufadd_char(buf) \
	seri_conv_pchar(buf)++

#define seri_bufadd_int(buf) \
	seri_conv_pint(buf)++

#define seri_bufadd_len(buf,len) \
	seri_conv_pchar(buf) = seri_conv_pchar(buf) + len


#define seri_jumpbegin(buf) \
	seri_conv_pchar(buf)+seri_lenbytes

//small endian
#define seri_setlen(buf,v) \
	int i_ = 0; \
	for (;i_ < seri_lenbytes; i_++) { \
	   *(seri_conv_pchar(buf)++) = (char)((v) >> i_*8); \
		}

#define seri_getlen(buf,len) \
do { \
	int i_ = 0; \
    for (; i_ < seri_lenbytes; i_++) { \
	   *seri_conv_pchar(seri_conv_pchar(len)+i_) = *seri_conv_pchar(seri_conv_pchar(buf)+i_); \
	} \
}while(0);

// length of data put high 4 byte
#define seri_shift4(v) \
	(v<<4)

#define seri_setbufchar_add(buf,v) \
	*seri_conv_pchar(buf) = seri_conv_char(v);seri_bufadd_char(buf);
#define seri_setbufchar_dec(buf) \
    seri_conv_pchar(buf)--

#define seri_setbufchar(buf,v) \
	*seri_conv_pchar(buf) = seri_conv_char(v);

#define seri_setbufint(buf,v) \
	*seri_conv_pint(buf) = seri_conv_int(v);seri_bufadd_int(buf);

static char* get_error_info(errcode)
{
	int size = sizeof(error_info_) / sizeof(error_info_[0]);
	int i = 0;
	for (; i < size; i++)
	{
		if (errcode == error_info_[i].errcode)
			return error_info_[i].errinfo;
	}
	return "unknow error";
}

// get "one int header" how much bytes?such as 257:0x0100,two bytes
static int seri_get_int_bytes(lua_Integer iValue)
{
	static long long int_array[] =
	{
		256, 65536, 16777216, 4294967296, 1099511627776,
		281474976710656, 72057594037927936,
		9223372036854775807 // 2^63 - 1
	};

	if (iValue >= 0){
		int i = 0;
		for (; i < 8/*sizeof(int_array)/sizeof(int_array[0])*/; i++)
		{
			if (iValue < int_array[i])
				break;
		}
		return min(i + 1, ucLuaIntLen_);
	}
	else
	{
		//lua_Integer iTemp = iValue;
		//int iLen = 0;
		//iTemp = iTemp << 1;
		//while (iTemp == iValue)
		//{
		//	iTemp = iTemp << 1;
		//	iLen++;
		//}
		//return (64 - iLen) / 8 + ((64 - iLen) & 7) ? 1 : 0); //1、64 == sizeof(lua_Integer)  2、7 == 8 - 1
		return sizeof(lua_Integer);
	}
}

// string to number, not use atof()
#define seri_str2number(pushbuf) \
    luaO_str2numEx(pushbuf)

// check size is enough or not
#define seri_isenough_size(size,len) \
	if ((size) < len) {\
	    return serialize_short; \
	} \
	(size) -= (len);

#define seri_encode_header(buf,len,itype) \
	seri_setbufchar_add(buf,seri_shift4(len)|itype)

//small endian
#define seri_encode_hash(buf,pValue,len) do{ \
	char *buf_= seri_conv_pchar(buf); \
	char *pValue_ = seri_conv_pchar(pValue); \
	int i_ = 0; \
	for(; i_ < (len); i_++) *(buf_ + i_) = *(pValue_ + i_); \
	seri_bufadd_len(buf,len);} while(0);

#define seri_encode_string(buf,size,lenRe,tsLen,pstr,itype) \
    if (tsLen <= seri_lenstring) { \
			lenRe = tsLen + 1; \
			seri_isenough_size(size, lenRe); \
			seri_encode_header(buf, tsLen, itype); \
			seri_encode_hash(buf, pstr, tsLen); \
	} else{ \
		lenRe = tsLen + 2; \
		seri_isenough_size(size, lenRe); \
		seri_encode_header(buf, 0, itype); \
		seri_encode_hash(buf, pstr, tsLen); \
		seri_setbufchar_add(buf, 0) \
    }

//small endian
#define seri_decode_hash(buf,v,len) \
do { \
	char *buf_= seri_conv_pchar(buf); \
	char *v_ = seri_conv_pchar(v); \
	int i_ = 0; \
	for(;i_ < (len); i_++) { \
	    *(v_ + i_) = *(buf_ + i_); \
	} \
}while(0);

#define seri_decode_int(buf,v,len) \
	if (len > ucLuaIntLen_) \
        return unserialize_long; \
	seri_decode_hash(buf,v,len);

#define unseri_get_header(buf) \
	(*seri_conv_pchar(buf) & 0xF)

#define unseri_get_len(buf) \
	((*seri_conv_pchar(buf) & 0xF0)>>4)

#define unseri_string_judge(buf,len,lenRet,lenTemp) \
	seri_isenough_size(len, lenTemp + 1); \
	lenRet = lenTemp + 1;

#define unseri_string_getbuf(buf, pushbuf, len, lenRet, lenTemp) \
	if (lenTemp > 0) { \
		unseri_string_judge(*buf, len, lenRet, lenTemp); \
		seri_bufadd_char(*buf); \
		seri_decode_hash(*buf, strShortBuf_, lenTemp); \
		strShortBuf_[lenTemp] = 0; \
		pushbuf = strShortBuf_; \
					}else{ \
		seri_bufadd_char(*buf); \
		lenTemp = strlen(*buf) + 1; \
		unseri_string_judge(*buf, len, lenRet, lenTemp); \
		pushbuf = *buf; \
					}

// size short,then add subed len(revert *psize)
#define seri_isvalid_return(psize, lenEncode, leftLen) \
	if (lenEncode < serialize_short) \
		return lenEncode; \
	if (serialize_short == lenEncode){ \
		*psize += leftLen; \
		return lenEncode; \
								}

#define serialize_table_logic(L, v, buf, size) \
do { \
	int noldsize, nresult; \
	seri_isenough_size(size, 1);\
	lenTemp = 1; \
    seri_setbufchar_add(*buf, seri_table_begin); \
	noldsize = size;\
	nresult = serialize_table(L, gco2t(gcvalue(v)), buf, &size);\
	if (nresult < serialize_sucess){ \
	    if(serialize_looptable == nresult){ \
            seri_setbufchar_dec(*buf); \
			lenTemp = 0; \
			seri_encode_string(*buf, size, lenTemp, sizeof("_@self"), "_@self", seri_header_string) \
		} else return nresult; \
	} else{ \
		lenTemp += noldsize - size; \
		seri_isenough_size(size, 1); \
		lenTemp += 1; \
		seri_setbufchar_add(*buf, seri_table_end); \
	} \
}while(0);

#define seri_decode_int_logic(L,buf,len,lenRet) \
do { \
	int lenTemp = unseri_get_len(*buf); \
	lua_Integer iValue = 0; \
	seri_isenough_size(len, lenTemp + 1); \
	lenRet = lenTemp + 1; \
	seri_bufadd_char(*buf); \
	seri_decode_int(*buf, &iValue, lenTemp); \
	lua_pushinteger(L, iValue); \
	seri_bufadd_len(*buf, lenTemp); \
}while(0);

#define seri_decode_string_logic(L,buf,len,lenRet) \
do { \
	int lenTemp = unseri_get_len(*buf); \
	char *pushbuf_; \
	unseri_string_getbuf(buf, pushbuf_, len, lenRet, lenTemp) \
	lua_pushstring(L, pushbuf_); \
	seri_bufadd_len(*buf, lenTemp); \
}while(0);

#define seri_decode_double_logic(L, buf, len, lenRet) \
do { \
	int lenTemp = unseri_get_len(*buf); \
	char *pushbuf_; \
	unseri_string_getbuf(buf, pushbuf_, len, lenRet, lenTemp) \
	seri_str2number(pushbuf_); \
	lua_pushnumber(L,seri_str2number(pushbuf_)); \
	seri_bufadd_len(*buf, lenTemp); \
}while(0);

#define seri_decode_bool_logic(L, buf, len, lenRet) \
do { \
	int nboolValue_ = 0; \
	seri_bufadd_char(*buf); \
	lenRet = 2; \
	seri_isenough_size(len, lenRet); \
	seri_decode_hash(*buf, &nboolValue_, 1); \
	lua_pushboolean(L, nboolValue_); \
    seri_bufadd_char(*buf); \
} while(0);


/* maximum length of the conversion of a number to a string */
#define SERI_MAXNUMBER2STR	50
static int serialize_number(TValue *v, void **buf, int size)
{
	int len = serialize_typeerr;

	switch (rttype(v)){
	case LUA_TNUMINT:{
		lua_Integer iValue = ivalue(v);
		int lenTemp = seri_get_int_bytes(iValue);  // length of (key or value)
		len = lenTemp + 1;                         // header and (key or value) = 1 + lenTemp

		seri_isenough_size(size, len);             // sub header and (key or value)
		seri_encode_header(*buf, lenTemp, seri_header_int);     // encode header
		seri_encode_hash(*buf, &iValue, lenTemp);  // encode (key or value) of hash
	}break;
	case LUA_TNUMFLT:{
		char buff2str[SERI_MAXNUMBER2STR];
		int len2str = lua_number2str(buff2str, sizeof(buff2str), nvalue(v));
		seri_encode_string(*buf, size, len, len2str, buff2str, seri_header_double);
	}break;
	default:return serialize_typeerr;
	}

	return len;
}

static int serialize_string(TValue *v, void **buf, int size)
{
	int len = serialize_typeerr;

	TString *ts = tsvalue(v);
	int tsLen = tsslen(ts);
	char *pstr = getstr(ts);

	switch (ttype(v)){
	case LUA_TSHRSTR:{ // short strings
		seri_encode_string(*buf, size, len, tsLen, pstr ,seri_header_string);
	}break;
	case LUA_TLNGSTR:{ // long strings
		seri_encode_string(*buf, size, len, tsLen, pstr, seri_header_string);
	}break;
	default:return serialize_typeerr;
	}

	return len;
}

static int serialize_bool(TValue *v, void **buf, int size)
{
	int len = 2; // 2 == header:1byte + data:1byte

	seri_isenough_size(size, len);            // sub header and (key or value),
	seri_encode_header(*buf, 0, seri_header_bool);     // encode header
	seri_setbufchar_add(*buf, bvalue(v));     // encode (key or value) of hash

	return len;
}

static int serialize_all(lua_State *L, TValue *v, void **buf, int size)
{
	int lenTemp = serialize_typeerr;

	switch (ttnov(v)){                       // encode value of hash
	case LUA_TNUMBER:{
		lenTemp = serialize_number(v, buf, size);
	}break;
	case LUA_TSTRING:{
		lenTemp = serialize_string(v, buf, size);
	}break;
	case LUA_TTABLE:{
		serialize_table_logic(L, v, buf, size);
	}break;
	case LUA_TBOOLEAN:{
		lenTemp = serialize_bool(v, buf, size);
	}break;
	case LUA_TLIGHTUSERDATA:{
		int tsLen = sizeof("_@lightuserdata");
		seri_encode_string(*buf, size, lenTemp, tsLen, "_@lightuserdata", seri_header_string);
	}break;
	case LUA_TFUNCTION:{
		int tsLen = sizeof("_@function");
		seri_encode_string(*buf, size, lenTemp, tsLen, "_@function", seri_header_string);
	}break;
	case LUA_TUSERDATA:{
		int tsLen = sizeof("_@userdata");
		seri_encode_string(*buf, size, lenTemp, tsLen, "_@userdata", seri_header_string);
	}break;
	case LUA_TTHREAD:{
		int tsLen = sizeof("_@thread");
		seri_encode_string(*buf, size, lenTemp, tsLen, "_@thread", seri_header_string);
	}break;
	default:{
		int tsLen = sizeof("_@unknow_type");
		seri_encode_string(*buf, size, lenTemp, tsLen, "_@unknow_type", seri_header_string);
	}break;
	}

	return lenTemp;
}

/* now, metatable serialize is not supportted! */
static int serialize_table(lua_State *L, Table *t, void **buf, int *psize)
{
	unsigned int i, unNodeSize;
	/* handle loop table */
	lua_pushliteral(L, seri_lua_registryname); /* lua_getfield(L, seri_lua_registryindex, seri_lua_registryname); */
	lua_rawget(L, seri_lua_registryindex);
	lua_pushlightuserdata(L, t); /* push addr of table t */
	lua_pushvalue(L, -1); /* copy addr */
	if (LUA_TNIL != lua_rawget(L, -3)){ /* is ever serialize? */
		lua_pop(L, 3);
		return serialize_looptable;
	}
	else{
		lua_pop(L, 1);
		lua_pushnumber(L, 1); /* not LUA_TNIL then ok. */
		lua_rawset(L, -3);
		lua_pop(L, 1);
	}

	// array
	for (i = 1; i <= t->sizearray; i++) {
		TValue *v = &t->array[i - 1];
		int lenTemp, leftLen, lenEncode;

		if (ttisnil(v))
			continue;

		lenTemp = seri_get_int_bytes(i);       // length of i
		leftLen = lenTemp + 1;
		seri_isenough_size(*psize, leftLen);       // sub header and key
		seri_encode_header(*buf, lenTemp, seri_header_int);  // encode header
		seri_encode_hash(*buf, &i, lenTemp);       // encode key of hash

		lenEncode = serialize_all(L, v, buf, *psize);       // encode value of hash
		seri_isvalid_return(psize, lenEncode, leftLen);      // check return isvalid
		*psize -= lenEncode;
	}


	// node
	unNodeSize = sizenode(t);
	for (i = 0; i < (int)unNodeSize; i++)
	{
		Node *n = gnode(t, i);
		int lenTemp, lenEncode;

		if (ttisnil(gval(n)))
			continue;

		lenTemp = serialize_all(L, gkey(n), buf, *psize);       // encode key of hash
		if (lenTemp <= serialize_short) return lenTemp;
		*psize -= lenTemp;

		lenEncode = serialize_all(L, gval(n), buf, *psize);     // encode value of hash
		seri_isvalid_return(psize, lenEncode, lenTemp);          // check return isvalid
		*psize -= lenEncode;
	}

	return serialize_sucess;
}

/* serialize lua data to binary data
** only string/table/number(int/bool/double) can be serialized
** begin 4 byte is for len of binary data
** idx:      table index
** buf:      serialize buf
** size:     serialize size
** return:
** success:  return serialize data len（> 0）
** len == 0: buf short,data truncate.
** error:    return < 0
*/
LUALIB_API int luaEx_Serialize(lua_State *L, int idx, void *buf, int size)
{
	Table *t;
	int seriSize, oldsize, len, datasize;
	char *bufbegin;
	if (!buf || size <= seri_lenbytes)
	{
		lua_pushstring/*luaG_runerror*/(L, get_error_info(serialize_null));
		return serialize_null;
	}

	if (size > seri_maxlen)
	{
		lua_pushstring/*luaG_runerror*/(L, get_error_info(serialize_long));
		return serialize_long;
	}
		
	if (lua_type(L, idx) != LUA_TTABLE)
	{
		lua_pushstring/*luaG_runerror*/(L, get_error_info(serialize_typeerr));
		return serialize_typeerr;
	}

	t = lua_topointer(L, idx);
	seriSize = size - seri_lenbytes;
	oldsize = seriSize;
	bufbegin = seri_jumpbegin(buf);

	/* handle loop table */
	lua_pushliteral(L, seri_lua_registryname);
	lua_newtable(L);
	lua_rawset(L, seri_lua_registryindex);

	len = serialize_table(L, t, &bufbegin, &seriSize);

	if (len < serialize_sucess)
	{
		if (len != serialize_short){
			lua_pushstring/*luaG_runerror*/(L, get_error_info(len));
		}
	}

	datasize = oldsize - seriSize;
	if (datasize > 0)
	{
		seri_setlen(buf, datasize);
	}
	else
	{
		lua_pushstring/*luaG_runerror*/(L, get_error_info(serialize_unknow));
		return serialize_unknow;
	}
	
	return datasize + seri_lenbytes;
}

// add by whb
static void lua_pushvalueEx(lua_State *L, TValue *pvalue) {
	lua_lock(L);
	setobj2s(L, L->top, pvalue);
	api_incr_top(L);
	lua_unlock(L);
}

// push lua stack data
static int unserialize_push(lua_State *L, void **buf, int *plen)
{
	int lenRet = serialize_typeerr;

	switch (unseri_get_header(*buf))
	{
	case seri_header_int:
	{
		seri_decode_int_logic(L, buf, *plen, lenRet);
	}break;
	case seri_header_string:
	{
		seri_decode_string_logic(L, buf, *plen, lenRet);
	}break;
	case seri_header_double:
	{
		seri_decode_double_logic(L, buf, *plen, lenRet);
	}break;
	case seri_header_bool:
	{
		seri_decode_bool_logic(L, buf, *plen, lenRet);
	}break;
	case seri_table_begin:
	{
		int rawlen = *plen;
		TValue *tablecopy;
		seri_isenough_size(*plen, 1); // 1 byte begin of table
		seri_bufadd_char(*buf);

		lua_newtable(L);                   // new sub table
		tablecopy = L->top - 1;    // copy the TValue* address of sub table
		lua_settable(L, -3);               // t[k] = v
		lua_pushvalueEx(L, tablecopy);     // push sub table

		if (unserialize_table(L, buf, plen) == serialize_sucess)
			return unserialize_table_end;
	}break;
	case seri_table_end:
	{
		lenRet = 1;                  // 1 byte begin of end
		seri_isenough_size(*plen, lenRet);
		seri_bufadd_char(*buf);
		lua_pop(L, 1);               // pop sub table
		return unserialize_table_end;
	}break;
	default:return serialize_typeerr;
	}

	return lenRet;
}

static int unserialize_table(lua_State *L, void **buf, int *plen)
{
	while (*plen > 0)
	{
		// key
		int lenTemp = unserialize_push(L, buf, plen);
		if (unserialize_table_end == lenTemp) continue;
		if (lenTemp <= 0 || *plen <= 0) // if *plen <= 0 then not need push valus of table
		{
			lua_pushstring/*luaG_runerror*/(L, get_error_info(lenTemp));
			return lenTemp;
		}

		// value
		lenTemp = unserialize_push(L, buf, plen);
		if (unserialize_table_end == lenTemp) continue;
		if (lenTemp <= 0)
		{
			lua_pushstring/*luaG_runerror*/(L, get_error_info(lenTemp));
			return lenTemp;
		}

		lua_settable(L,-3);  //t[k] = v
	}

	return serialize_sucess;
}

/* unserialize binary data to lua data
** buf:      serialize buf
** success:  return > 0
** error:    return <= 0
*/
LUALIB_API int luaEx_Unserialize(lua_State *L, const void *buf)
{
	int len = 0;
	char *bufbegin;
	if (!L || !buf)
	{
		lua_pushstring(L, get_error_info(serialize_null));
		return serialize_null;
	}

	seri_getlen(buf, &len);

	if (len <= 0)
	{
		lua_pushstring(L, get_error_info(serialize_short));
		return serialize_short;
	}

	if (len > seri_maxlen)
	{
		lua_pushstring(L, get_error_info(serialize_long));
		return serialize_long;
	}

	// outside tabel
	lua_newtable(L); 

	bufbegin = seri_jumpbegin(buf);
	return unserialize_table(L, &bufbegin, &len);
}