#include <stdio.h>
#include "windows.h"
#include <../chelConsole/Console/CConsole.h>
#include "../chelDoc/chelDoc.h"

int main()
{
	//Create console, automatically linking it to the global pointer
	CConsole con;
	SendCommand("cls");
	
	NChelDoc::Initialize();
	
	try {
		g_pConsole->EnterCommandCycle();
	} catch(CChelException* e){
		e->handle();
		system("pause");
	}
}
