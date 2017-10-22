#include <NCFGLoad.h>
#include <fstream>
#include <iostream>
using namespace std;


string currentcommand;


namespace NCFGLoad{
	void fromFile(const char* pszPath){

		ifstream infile();
		infile.open(pszPath);
		while(!infile.eof){
			getline(infile,currentcommand);
			String command = currentcommand.c_str();
			CConsole::ProcessCommand(command);
		}
		infile.close();
	}
}