#ifndef CHEL_ICONSOLE
#define CHEL_ICONSOLE

#include "../ConVar/ConVar.h"
#include "../../String/String.h"
#include "stdarg.h"

//extern ConVar con_devmsg;
extern bool g_bConDevMsg;

class IConsole;

extern IConsole* g_pConsole;

class IConsole {
protected:
	~IConsole() {}
public:
	IConsole() {
		g_pConsole = this;
	}

	/**
	 * @brief Variadic function for printing to console.
	 * 		these messages are always printed.
	 * @param pszFormat - c-style formating
	 */
	void Msg(const char* pszFormat, ...) {
		va_list args;
		va_start(args, pszFormat);
		VMsg(pszFormat, args);
		va_end(args);
	}
	
	virtual void VMsg(const char* pszFormat, va_list args) = 0;
	
	//prints to console iff g_bConDevMsg is true
	void DevMsg(const char* pszFormat, ...) { 
		if (g_bConDevMsg) {
			va_list args;
			va_start(args, pszFormat);
			VMsg(pszFormat, args);
			va_end(args);
		}
	}
	
	void VDevMsg(const char* pszFormat, va_list args) {
		if (g_bConDevMsg)
			VMsg(pszFormat, args);
	}
	
	virtual void Log(const char* pszFormat...) = 0; //print to file
	
	//Enters input stream so that user can start typing commands
	virtual void EnterCommandCycle() = 0;
	
	/**
	 * @brief Processes a command as if it was entered by the user.
	 * @param sCommand - the command to process
	 */
	virtual void ProcessCommand(const String& sCommand) = 0;
	
	/**
	 * @brief Clears the display, but does not necessarily delete
	 * 		previously outputed information.
	 */
	virtual void Clear() = 0;
};

inline void SendCommand(const String& sCommand) { g_pConsole->ProcessCommand(sCommand); }

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