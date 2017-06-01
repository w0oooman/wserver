/*
Navicat MySQL Data Transfer

Source Server         : 本地
Source Server Version : 50620
Source Host           : localhost:3306
Source Database       : test_db

Target Server Type    : MYSQL
Target Server Version : 50620
File Encoding         : 65001

Date: 2016-10-13 16:04:20
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `test_table`
-- ----------------------------
DROP TABLE IF EXISTS `test_table`;
CREATE TABLE `test_table` (
  `test` int(11) DEFAULT NULL,
  `ID` int(11) DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of test_table
-- ----------------------------
INSERT INTO `test_table` VALUES ('29', '1');
INSERT INTO `test_table` VALUES ('29', '1');

-- ----------------------------
-- Procedure structure for `test_get`
-- ----------------------------
DROP PROCEDURE IF EXISTS `test_get`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `test_get`()
BEGIN
    select test,ID from test_table where ID = 1;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `test_getex`
-- ----------------------------
DROP PROCEDURE IF EXISTS `test_getex`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `test_getex`(IN `num` int,IN `str` varchar(50))
BEGIN
  if str then
			select test,ID from test_table;
	end if;
END
;;
DELIMITER ;
