#ifndef __TIMER_ID__
#define __TIMER_ID__

enum ServerTimerID
{
	/*************************db**********************************/
	timer_db_begin = 1,


	timer_db_end = 100,
	/*************************normal**********************************/
	timer_server_normal_begin = 101,
	timer_delay_remove_player = 102,

	timer_server_normal_end = 500,
	/*************************lua**********************************/
	timer_lua_begin = 501,
	timer_lua_1_minute = 502,    //lua 1分钟定时
	timer_lua_10_minute = 503,   //lua 10分钟定时
	timer_lua_1_hour = 504,      //lua 1小时定时

	timer_lua_end = 520,

    timer_generate_begin = 100000000, //timerID传0时自动生成的timerID最小值
	timer_generate_lua_begin = timer_generate_begin + 1000000,//lua脚本:timerID传0时自动生成的timerID最小值
};

enum DistriServerTimerID
{

};

enum DistriClientTimerID
{
    
};

#endif