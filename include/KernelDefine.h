#ifndef  __KERNELDEFINE__H__
#define  __KERNELDEFINE__H__

#define WIN32_LEAN_AND_MEAN
#include  <windows.h>
#include  "Log.h"

#ifdef  KERNEL_EXPORTS
#define KERNEL_ENGINE_CLASS __declspec(dllexport)
#else
#define KERNEL_ENGINE_CLASS __declspec(dllimport)
#endif


//当前socket类型
#define   SOCKET_TYPE    SOCK_STREAM
//传送数据的最大长度的位数
#define   MAX_LENGTH_DATA       5
//发送或每次从缓冲区读取的最大长度
#define   MAX_MESSAGE_LENGTH    2048
//最大发送限制
#define   MAX_SEND_LIMIT  (32768/*1024*32*/)

//普通客户端连接时:服务器发送最大buffer
#define   SND_SIZE        (4096/*1024*4*/)
//普通客户端连接时:服务器接收最大buffer
#define   RCV_SIZE        (8192/*1024*8*/)  //若buf采用环形缓冲区时，最好是2的次方

//客户机连接服务端时:服务端发送最大buffer
#define   SND_SIZE_SPECIAL  (262144/*1024*256*/)
//客户机连接服务端时:服务端接收最大buffer
#define   RCV_SIZE_SPECIAL  (262144/*1024*256*/)  //若buf采用环形缓冲区时，最好是2的次方

//服务器做为客户机时:BUFFER大小
#define   CLIENT_SND_SIZE   (1024*128)
#define   CLIENT_RCV_SIZE   (1024*512)

//消息检验码
#define   MESSAGE_CHECK_CODE     (150808)

#define   WHEEL_TIMER_LOCK  //时间轮锁

//心跳检测时间间隔(秒)
#define   HEART_BEAT_TEST_TIME   (15)
//心跳检测超时次数(超过次数则断开连接)
#define   HEART_BEAT_CUT_TIMES   (3)

#define   CLIENT_RECONNECT_TIME  (5)           //客户端重连时间(秒)


//队列容量定义(一定是2的幂!!)
#define   NORMAL_QUEUE_LIMIT_SIZE  (1024*512) //普通队列
#define   BATCH_QUEUE_LIMIT_SIZE   (1024*32)  //群发队列(别配tai大!)
#define   DB_QUEUE_LIMIT_SIZE      (1024*16)  //数据库队列
#define   TIMER_QUEUE_LIMIT_SIZE   256        //定时器队列

#define   CLIENT_NORMAL_QUEUE_SIZE 128        //客户端队列大小



//#if (SOCKET_TYPE==SOCK_STREAM)
//    #define SOCKET_CONNEECT_OK
//#endif

#ifdef   WHEEL_TIMER_LOCK
typedef struct tagWheelTimer
{
	int   timerID;
	void *func;
	void *data;
	int   type;
} tagWheelTimer;
#endif

typedef void(*TimerCallBackFunc)(void *);


////////////////////////////////////
////////队列消息////////////////////
////////////////////////////////////

#define  QMD_NORMAL_DATA        1         //读取队列
#define  QMD_DB_DATA            2         //数据库队列
#define  QMD_TIMER_DATA         3         //定时器队列
#define  QMD_DELETE_TIMERDATA   4         //清除定时器数据
#define  QMD_CLOSE_SOCKET       5         //关闭连接
#define  QMD_BATCH_DATA         6         //群发队列


#endif