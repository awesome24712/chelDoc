#ifndef CHEL_ICONSOLE
#define CHEL_ICONSOLE

#include "../../chelTypes/chelTypes.hpp"

extern ConVar con_devmsg;

class IConsole;

extern IConsole* g_pConsole;

class IConsole {
	
	IConsole(){
		g_pConsole = this;
	}
	
	virtual void Msg(const char* pszFormat, ...) = 0; //prints to console
	
	//prints to 
	virtual void DevMsg(const char* pszFormat, ...) { if (con_devmsg.getBool()) Msg(pszFormat, ...); }
	
	virtual void Log(const char* pszFormat...) = 0; //print to file
	
	//Enters input stream so that user can start typing commands
	virtual void EnterCommandCycle() = 0;
	
	
	virtual void ProcessCommand(const String& sCommand) = 0;
};



inline void Msg(const char* pszFormat, ...) { g_pConsole->Msg(pszMsg, ...); }
inline void DevMsg(const char* pszFormat, ...) { g_pConsole->DevMsg(pszMsg, ...); }
inline void Log(const char* pszFormat, ...) { g_pConsole->Log(pszMsg, ...); }

#endif //CHEL_ICONSOLE