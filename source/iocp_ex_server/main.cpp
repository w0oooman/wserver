//#include  "include/vld.h"
#include  <iostream>
#include  "MainMgr.h"
#include  "Log.h"
#include  "DistriServerHandle.h"
#include  "DistriClientHandle.h"
#include  "LuaManager.h"
using namespace std;
//#pragma comment(lib,"lib/Win32/vld.lib")


void timer_test(void* data)
{
	Log("++++++++++++timer_test data=%d\n", (int)data);
}
class CTimerTest
{
public:
	static void timer_test(void* data)
	{
		//printf("++++++++++++CTimerTest::timer_test data=%d\n", (int)data);
		Log("++++++++++++CTimerTest::timer_test data=%d\n", (int)data);
	}
	static void timer_test2(void* data)
	{
		Log("++++++++++++CTimerTest::timer_test2 data=%d\n", (int)data);
	}
};

//序列化 反序列化测试
void SerializerTest()
{
#include "Serializer.h"
	struct  SQGetCharacterListMsg
	{
		DWORD	dwServerId;					// 发起请求的服务器ID
		char	streamData[1024];
	};

	SQGetCharacterListMsg msg;
	lite::Serializer slm(msg.streamData, sizeof(msg.streamData));
	slm(4);
	slm("helloworld.");
	printf("---序列化后长度为=%d\n", sizeof(msg.streamData) - slm.EndEdition());

	//SQGetCharacterListMsg msg2;
	lite::Serialreader slr(msg.streamData);
	printf("---slr()=%d\n", (int)slr());
	printf("---slr()=%s\n", (LPCSTR)slr());
}

#include "MysqlDBProcess.h"
#include "IniParser.h"
int main()
{
	//测试Log过滤器
	//Log("%d",123, 2, "55");
	//Log("%d 200%", 999);
	//Log("%d 100% 20%.", 456);
	//Log("%d 20%% 100%%", 777); //控制台上打印出来是"777 20%"，奇怪，后面的数据不见了!!! 直接用printf("%d 20%% 100%%", 777);又不会出现问题..找到原因了.whb
	//Log("%d 20%%q100%%", 888);

	//CDBManager dbs;
	//dbs.InitRedis((char*)"127.0.0.1", 6379);
	//dbs.InitDB(TEXT("root"), TEXT("000000"), TEXT("127.0.0.1"), TEXT("test_1011000"));
	////share_sleep(10000);
	//dbs.LoadUserData();
	//dbs.GetUserData(1000100010);
	//dbs.SaveUserData(true);
	//dbs.LoadUserData();
	//dbs.SaveUserData();

	//SerializerTest();

	try
	{
		CIniParser parser;
		int   nLogicPort;
		int   nLimitConnect;

		if (!parser.Open(SERVER_CONFIG)){
			Log(parser.GetLastError());
			throw(1);
		}
		else
		{
			nLogicPort = parser.GetIniInt("gateway", "user_port", GATESERVER_PORT);
			nLimitConnect = parser.GetIniInt("gateway", "user_nums_limit", MAX_CLIENT_NUM);
		}

		CMainMgr  MainMgr;
		if (!MainMgr.Init(nLimitConnect, nLogicPort)) throw "NetMgr.Init error!";
		if (!MainMgr.UseMySql()) throw "usemysql error!";
		if (!MainMgr.UseLua()) throw "usemylua error!";
		cout << "starting..." << endl;
		if (!MainMgr.Start()) throw "NetMgr.Start() error!";
		cout << "start finish!" << endl;

		//游戏服务器 定时器实例:
		//MainMgr.AddEvent(30, 80, NULL, (void*)30);  //whb 
		MainMgr.AddEvent(110, 5 * 1000);  //whb test
		MainMgr.AddEvent(111, 4 * 1000, NULL, (void*)4);  //whb 

		MainMgr.AddEvent(112, 6537 * 1000, timer_test, (void*)112);  //whb test
		MainMgr.AddEvent(114, 6537 * 1000, NULL, (void*)114);  //whb test
		MainMgr.AddEvent(113, 10 * 1000, &CTimerTest::timer_test, (void*)10);  //whb test
		MainMgr.AddEvent(12345, 63 * 1000);  //whb test
		MainMgr.AddEvent(12345, 2300 * 1000);  //whb test
		MainMgr.AddEvent(23456, 28400 * 1000);  //whb test
		MainMgr.AddEvent(34567, 500000 * 1000, &CTimerTest::timer_test, (void*)34567);  //whb test

		////分布式时 做服务器 服务端 实例:
		//CMainMgr DistriServer;
		//if (!MainMgr.InitDistri(10, DISTRI_SERVER_PORT)) throw "DistriServer.Init error!";
		//if (!MainMgr.StartDistri()) throw "DistriServer.Start() error!";
		////DistriServer.AddEvent(5555, 10 * 1000, &CTimerTest::timer_test, (void*)10);  //whb test
		////DistriServer.AddEvent(6666, 13 * 1000, &CTimerTest::timer_test, (void*)13);  //whb test
		////DistriServer.AddEvent(7777, 14 * 1000, NULL, (void*)14);  //whb test

		//分布式时 做服务器 客户端 实例:
		//CDistriClientHandle DistriClient;
		//try{
		//	//DistriClient.AddEvent(8888, 15 * 1000, &CTimerTest::timer_test, (void*)15);  //whb test
		//	//DistriClient.AddEvent(9999, 18 * 1000, &CTimerTest::timer_test, (void*)18);  //whb test
		//	//DistriClient.AddEvent(10000, 19 * 1000, NULL, (void*)19);  //whb test
		//	//DistriClient.AddEvent(10001, 230 * 1000, NULL, (void*)20);  //whb test
		//	if (!DistriClient.Init("192.168.2.172", DISTRI_SERVER_PORT)) throw "DistriClient.Init error!";
		//	if (!DistriClient.Start()) throw "DistriClient.Start error!";
		//}
		//catch (char *e){
		//	cout << e << endl;
		//}
		//catch (CNetErr& err){
		//	cout << (char*)err << endl;
		//}
		//catch (...){
		//	printf("catch (...)");
		//}

		//while (1) share_sleep(2000);
		system("pause");

	}
	catch (CNetErr& err){ 
		cout << (char*)err << endl; 
		//Log(); //whb
	}
	catch (char *e){
		cout << e << endl;
	}
	catch (...){

	}

	LogAll();
	system("pause");
	return 0;
}
