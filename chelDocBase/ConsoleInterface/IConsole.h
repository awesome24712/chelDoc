#ifndef CHEL_ICONSOLE
#define CHEL_ICONSOLE

#include "../../chelTypes/chelTypes.hpp"
#include "stdarg.h"

extern ConVar con_devmsg;

class IConsole;

extern IConsole* g_pConsole;

class IConsole {
public:
	//prints to console
	virtual void Msg(const char* pszFormat, ...) {
		va_list args;
		va_start(args, pszFormat);
		VMsg(pszFormat, args);
		va_end(args);
	}
	
	
	virtual void VMsg(const char* pszFormat, va_list args) = 0;
	
	//prints to 
	virtual void DevMsg(const char* pszFormat, ...) { 
		if (con_devmsg.getBool()) {
			va_list args;
			va_start(args, pszFormat);
			VMsg(pszFormat, args);
			va_end(args);
		}
	}
	
	void VDevMsg(const char* pszFormat, va_list args) {
		if (con_devmsg.getBool())
			VMsg(pszFormat, args);
	}
	
	virtual void Log(const char* pszFormat...); //print to file
	
	//Enters input stream so that user can start typing commands
	virtual void EnterCommandCycle();
};

inline void Msg(const char* pszFormat, ...) {
	va_list args;
	va_start(args, pszFormat);
	g_pConsole->VMsg(pszFormat, args);
	va_end(args);
}
inline void DevMsg(const char* pszFormat, ...) { 
	va_list args;
	va_start(args, pszFormat);
	g_pConsole->VDevMsg(pszFormat, args);
	va_end(args);
}
//inline void Log(const char* pszFormat, ...) { g_pConsole->Log(pszMsg, ...); }

#endif //CHEL_ICONSOLE