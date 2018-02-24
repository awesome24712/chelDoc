#include <stdio.h>
#include "windows.h"
#include <../chelConsole/Console/CConsole.h>
#include "../chelTester/CTestCase.h"
#include "../chelDoc/chelDoc.h"

#include "../chelTypes/chelTypes.hpp"

int main()
{
	CConsole con;
	con.Clear();


	//This recursively does all post-startup initializations
	NInitializations::ChelDoc();
	
	while(!con.m_bQuit) {
		try {
			g_pConsole->EnterCommandCycle();
		} catch(CChelException* e){
			e->handle();
			//system("pause");
		}	
	}
}
