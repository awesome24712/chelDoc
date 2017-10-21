#ifndef CHEL_CCONSOLE
#define CHEL_CCONSOLE

#include "IConsole.h"

class CConsole;

class CConsole {
	
private:
	String m_sPreviousOutput;
public:
	bool m_bQuit=false;
	
	CConsole(){
		m_sPreviousOutput.setReserveBuffer(5000);
	}
	
	void Msg(const char* pszFormat, ...); //prints to console
	
	 void Log(const char* pszFormat...) {}//print to file
	 
	 //Enters input stream so that user can start typing commands
	void EnterCommandCycle();
	
	
	
}

#endif //CHEL_CCONSOLE

