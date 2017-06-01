#include "GatewayServer.h"
#include "GatewayServerLogic.h"
#include "GatewayServerLogin.h"
#include "IniParser.h"
#include "dump.h"

int main()
{
	InitMinDump();
	try
	{
		//CIniParser parser;
		//int UserNums, LoginServerNums, LogicServerNums;
		//USHORT UserPort, LoginPort, LogicPort;

		//if (!parser.Open("server.ini")){
		//	Log(parser.GetLastError());
		//	throw(1);
		//}
		//else
		//{
		//	UserNums = parser.GetIniInt("gateway", "user_nums_limit", 300);
		//	LoginServerNums = parser.GetIniInt("gateway", "loginserver_nums_limit", 1);
		//	LogicServerNums = parser.GetIniInt("gateway", "logicserver_nums_limit", 1);

		//	UserPort = parser.GetIniInt("gateway", "user_port", 10001);
		//	LoginPort = parser.GetIniInt("gateway", "login_gateway_port", 10002);
		//	LogicPort = parser.GetIniInt("gateway", "logic_gateway_port", 10003);
		//}

		CGatewayServer  MainMgr;
		if (!MainMgr.Init()) throw "NetMgr.Init error!";
		Log("starting GateServer...");
		if (!MainMgr.Start()) throw "NetMgr.Start() error!";
		Log("start GateServer finish!");

		//CGatewayServerLogin  MainMgr2;
		//if (!MainMgr2.Init(LoginServerNums, LoginPort)) throw "NetMgr.Init error!";
		//Log("starting GateServer...");
		//if (!MainMgr2.Start()) throw "NetMgr.Start() error!";
		//Log("start GateServer finish!");

		//CGatewayServerLogic  MainMgr3;
		//if (!MainMgr3.Init(LogicServerNums, LogicPort)) throw "NetMgr.Init error!";
		//Log("starting GateServer...");
		//if (!MainMgr3.Start()) throw "NetMgr.Start() error!";
		//Log("start GateServer finish!");
		
		system("pause");

	}
	catch (CNetErr& err){
		Log((char*)err);
	}
	catch (char *e){
		Log(e);
	}
	catch (...){

	}

	LogAll();
	system("pause");
	return 0;
}