#ifndef __SQL_SENTENCE__H__
#define __SQL_SENTENCE__H__

//sql”Ôæ‰∂®“Â
#define UPDATE_USER_DATA          "update UserInfo set money = %d, diamond = %d, point = %d, LastLoginTime = now() where RoleID = %d"
#define UPDATE_USER_DATA_BIND     "update UserInfo set money = ?,  diamond = ?,  point = ?   where RoleID = %d"

#define UPDATE_USER_POINT         "update UserInfo set point = %d  where RoleID = %d"


#endif