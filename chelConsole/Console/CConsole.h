#ifndef CHEL_CCONSOLE
#define CHEL_CCONSOLE

#include "../../chelDocBase/ConsoleInterface/IConsole.h"

class CConsole {
	
private:
	String m_sPreviousOutput;
public:
	bool m_bQuit=false;
	
	CConsole(){
		m_sPreviousOutput.setReserveBuffer(5000);
	}
	
	void VMsg(const char* pszFormat, va_list args); //prints to console
	
	void Log(const char* pszFormat, ...) {}//print to file
	 
	 //Enters input stream so that user can start typing commands
	void EnterCommandCycle();
	
<<<<<<< .mine
};
||||||| .r22
	
	
}
=======
	virtual void ProcessCommand(const String& sCommand);
	
}
>>>>>>> .r33

#endif //CHEL_CCONSOLE

