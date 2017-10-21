#include <stdio.h>
#include <../chelConsole/Console/CConsole.h>

int main()
{
	try {
		g_pConsole->EnterCommandCycle();
	} catch(CChelException* e){
		e->handle();
	}
}
