USE [master] 
GO

/**********创建数据库************************/
-----------------------------------------------------------
Create database [TEST_DB] ON PRIMARY
( NAME = N'TEST_DB', FILENAME = N'D:\DB\TEST_DB.mdf' , SIZE = 41216KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'TEST_DB_log', FILENAME = N'D:\DB\TEST_DB_log.LDF' , SIZE = 13632KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
-----------------------------------------------------------



/***********创建数据表**********************/
USE [TEST_DB]
GO
-----------------------------------------------------------
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[LoginTimes]
(
    --[ID]    [int] not null PRIMARY KEY,
    [ID]    [INT] DEFAULT(1) PRIMARY KEY,
    [Times] [INT] DEFAULT(0),
    [ByteNum] [BIGINT]
) ON [PRIMARY]
GO
EXEC dbo.sp_addextendedproperty @name=N'MS_Description', @value=N'玩家总登陆次数' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'LoginTimes', @level2type=N'COLUMN',@level2name=N'Times'
GO
EXEC dbo.sp_addextendedproperty @name=N'MS_Description', @value=N'发送字节总数' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'LoginTimes', @level2type=N'COLUMN',@level2name=N'ByteNum'
GO
-----------------------------------------------------------



/**************创建存储过程***********************/
USE [TEST_DB]
GO
-----------------------------------------------------------
IF EXISTS (SELECT * FROM DBO.SYSOBJECTS WHERE ID = OBJECT_ID(N'[dbo].[SP_LoginTimes]') and OBJECTPROPERTY(ID, N'IsProcedure') = 1)
DROP PROCEDURE [dbo].[SP_LoginTimes]
GO
SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

CREATE PROC SP_LoginTimes
    @ByteNum BIGINT  --发送字节数
--WITH ENCRYPTION    --加密
AS

--属性设置
SET NOCOUNT ON
    
    DECLARE @Column int
    SET @Column=0
    BEGIN
        SELECT @Column=COUNT(*) from [dbo].[LoginTimes]
        if @Column<=0 
            BEGIN
                INSERT [dbo].[LoginTimes] (Times,ByteNum) VALUES (1,@ByteNum)
            END
        else
           BEGIN
                UPDATE [dbo].[LoginTimes] SET Times=Times+1,ByteNum=ByteNum+@ByteNum
           END

        SELECT ByteNum from [dbo].[LoginTimes]
    END
RETURN 0
GO
-----------------------------------------------------------
