#include "LogicServer.h"
#include "IniParser.h"
#include "dump.h"
#include "CommonList.h"

int main()
{
	InitMinDump();
	try
	{
		CLogicServer mgr;
		if(!mgr.Init()) throw "login server Init error.";
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