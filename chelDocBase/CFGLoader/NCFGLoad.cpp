#include <CFGLoader/NCFGLoad.h>
#include "../chelTypes/chelTypes.hpp"
#include "../ConsoleInterface/IConsole.h"
#include <fstream>
#include <iostream>
using namespace std;


string currentcommand;


namespace NCFGLoad{
	void fromFile(const char* pszPath){

		ifstream infile;
		infile.open(pszPath);
		while(!infile.eof()){
			getline(infile,currentcommand);
			String command = currentcommand.c_str();
			g_pConsole->ProcessCommand(command);
		}
		infile.close();
	}
}

CON_COMMAND(print) {
	Msg(args->get(1));
}