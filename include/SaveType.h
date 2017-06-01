#ifndef __SAVE_TYPE_H__
#define __SAVE_TYPE_H__


//保存数据类型定义
enum SAVE_DATA_TYPE
{
    SAVE_MONEY = 1,        //金币
	SAVE_DIAMOND,          //钻石
	SAVE_POINT,            //积分
	SAVE_LOGIN_TIMES,      //登录次数

	SAVE_FACTION_LEVEL,    //帮会等级


	SAVE_USER_ALL,         //保存用户所有数据
	SAVE_FACTION_ALL,      //保存帮会所有数据
};






//保存DB类型
enum SAVE_DB_TYPE
{
	SAVE_DB_ATONCE,        //实时保存(同步保存DB和redis)
	SAVE_DB_REDIS,         //延时保存(先保存redis,由redis定时保存DB)
	SAVE_DB_OFFLINE,       //下线保存(数据改变,不发送到DB服,下线时保存一次就行)
};
    
//实时保存DB的数据类型集合
static int g_nSaveDBSetAtOnce[] =
{
	SAVE_MONEY,
	SAVE_DIAMOND,
	SAVE_POINT,
};

//判断保存DB类型
inline int GetSaveDBType(int nType)
{
	int nums = sizeof(g_nSaveDBSetAtOnce) / sizeof(g_nSaveDBSetAtOnce[0]);
	for (int i = 0; i < nums; i++)
	{
		if (g_nSaveDBSetAtOnce[i] == nType)
			return SAVE_DB_ATONCE;
	}
	return SAVE_DB_REDIS;
}

#endif