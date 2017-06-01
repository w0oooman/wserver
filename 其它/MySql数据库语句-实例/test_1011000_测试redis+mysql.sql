/*
Navicat MySQL Data Transfer

Source Server         : 本地
Source Server Version : 50620
Source Host           : localhost:3306
Source Database       : test_1011000

Target Server Type    : MYSQL
Target Server Version : 50620
File Encoding         : 65001

Date: 2017-02-25 13:44:05
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `userinfo`
-- ----------------------------
DROP TABLE IF EXISTS `userinfo`;
CREATE TABLE `userinfo` (
  `account` varchar(45) NOT NULL DEFAULT '' COMMENT '角色名字(组成：真实账户+服务器ID，服务器ID为数据库名后4位，合服的时候帐号不至于重复)',
  `PassWord` varchar(45) DEFAULT '' COMMENT '用户密码',
  `RoleID` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT '角色ID(组成：服务器ID(4位)+用户ID(6位)，服务器ID为数据库名的后4位，这样保证合服时RoleID不会重复)',
  `RoleName` varchar(45) NOT NULL DEFAULT '',
  `money` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '用户金币',
  `diamond` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '用户钻石',
  `point` int(10) NOT NULL DEFAULT '0' COMMENT '用户积分',
  `RegisterTime` datetime DEFAULT NULL COMMENT '注册时间',
  `LoginTimes` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '登录次数',
  `LastLoginTime` datetime DEFAULT NULL COMMENT '最近登录时间',
  `LastSaveTime` datetime DEFAULT NULL COMMENT '最近保存时间',
  `RoleData` blob COMMENT '角色数据(序列化后保存)',
  PRIMARY KEY (`RoleID`),
  UNIQUE KEY `user_account` (`account`) USING BTREE,
  UNIQUE KEY `user_RoleID` (`RoleID`),
  UNIQUE KEY `user_RoleName` (`RoleName`) USING BTREE
) ENGINE=MyISAM AUTO_INCREMENT=1000100012 DEFAULT CHARSET=utf8 COMMENT='用户信息';

-- ----------------------------
-- Records of userinfo
-- ----------------------------
INSERT INTO `userinfo` VALUES ('zhangfei', '', '1000100010', 'Feifei', '10', '0', '2', '2017-02-21 15:43:01', '0', '2017-02-21 15:43:01', '2017-02-21 15:43:01', null);
INSERT INTO `userinfo` VALUES ('liubei', '', '1000100011', 'Liubei', '20', '0', '100', '2017-02-21 15:43:01', '0', '2017-02-21 15:43:01', '2017-02-21 15:43:01', null);

-- ----------------------------
-- Procedure structure for `SP_LoadData`
-- ----------------------------
DROP PROCEDURE IF EXISTS `SP_LoadData`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_LoadData`()
BEGIN
    #加载活跃用户数据
    declare difftime int;
    set difftime = 3*24*60*60;
    select account,PassWord,RoleID,RoleName,money,diamond,point from UserInfo
        where unix_timestamp(now()) - unix_timestamp(LastLoginTime) <= difftime;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `SP_LoadUserData_RoleName`
-- ----------------------------
DROP PROCEDURE IF EXISTS `SP_LoadUserData_RoleName`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_LoadUserData_RoleName`(IN `_RoleName` varchar(45))
BEGIN
    select account,PassWord,RoleID,RoleName,money,diamond,point from UserInfo
        where binary UserInfo.RoleName = _RoleName;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `SP_LoadUserData_UserID`
-- ----------------------------
DROP PROCEDURE IF EXISTS `SP_LoadUserData_UserID`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_LoadUserData_UserID`(IN `_RoleID` int)
BEGIN
    select account,PassWord,RoleID,RoleName,money,diamond,point from UserInfo
        where UserInfo.RoleID = _RoleID;
END
;;
DELIMITER ;
