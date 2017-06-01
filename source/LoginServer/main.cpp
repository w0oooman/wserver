#include "LoginServer.h"
#include "IniParser.h"
#include "dump.h"

int main()
{
	InitMinDump();
	try
	{
		char  LogicIP[64];
		int   nLogicPort;

		if (1)
		{
			CIniParser parser;
			if (!parser.Open(SERVER_CONFIG)){
				parser.Close();
				Log(parser.GetLastError());
				throw(1);
			}
			else
			{
				parser.GetIniString("gateway", "ip", LogicIP, sizeof(LogicIP), "127.0.0.1");
				nLogicPort = parser.GetIniInt("gateway", "login_gateway_port", DISTRI_GATE_LOGIN_PORT);
				parser.Close();
			}
		}

		CLoginServer mgr;
		if (!mgr.Init(LogicIP, nLogicPort)) throw "login server Init error.";
		if (!mgr.Start()) throw "login server Start error.";
		cout << "start all thread success!" << endl;

		while (1) share_sleep(2000);
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