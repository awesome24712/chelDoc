#ifndef CHEL_CCONSOLE
#define CHEL_CCONSOLE

#include "../../chelDocBase/chelDocBase.h"

class CConsole : public IConsole {
private:
	String m_sPreviousOutput;
	
	
	
public:
	~CConsole() {}

	bool m_bQuit = false;
	
	CConsole() : IConsole() {
		m_sPreviousOutput.setReserveBuffer(5000);
	}
	
	void VMsg(const char* pszFormat, va_list args); //prints to console
	
	void Log(const char* pszFormat, ...) {}//print to file
	 
	 //Enters input stream so that user can start typing commands
	void EnterCommandCycle();
	
	void ProcessCommand(const String& sCommand);
	
};

#endif //CHEL_CCONSOLE

