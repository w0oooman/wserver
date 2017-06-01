#include "DBServer.h"
#include "IniParser.h"
#include "dump.h"


int main()
{
	InitMinDump();
	try
	{
		USHORT DBPort;

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
				DBPort = parser.GetIniInt("DB", "login_db_port", DISTRI_DB_LOGIN_PORT);
				parser.Close();
			}
		}

		CDBServer DBServer;
		if (!DBServer.Init(1, DBPort)) throw "DBServer Init Error.";
		Log("starting DBServer...");
		if (!DBServer.Start()) throw "DBServer Start Error.";
		Log("start DBServer finish!");

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