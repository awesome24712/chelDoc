#include "CConsole.h"

#include "string"
#include "iostream"

ConVar con_tab_level("con_tab_level", "0", "Use this to indent all console output.");

char g_pszBuffer[128];

void CConsole::VMsg(const char* pszFormat, va_list args){
	vsnprintf(g_pszBuffer, 128, pszFormat, args);
	m_sPreviousOutput += g_pszBuffer;
	
	int tabLevel = con_tab_level.getInt();
	for (int i = 0; i < tabLevel; i++)
		printf("\t");
	
	printf(g_pszBuffer);
	
	if(m_sPreviousOutput.length()>10000){
		m_sPreviousOutput.removeByIndexes(0,2000);
	}
}

void CConsole::EnterCommandCycle(){
	
	while(!m_bQuit){
		std::string currentCommand;
		
		std::getline(std::cin, currentCommand);
		ProcessCommand(currentCommand.c_str());

	}
}

void CConsole::ProcessCommand(const String& sCommand) {
	String cmd = sCommand;
		
	cmd.trimSpaces();
	
	if (cmd.length() == 0)
		return;
	
	if(cmd.contains(' ')){
		int spIndex = cmd.indexOf(' ');
		String subcmd = cmd.subString(0,spIndex);
		bool isConVar = ConVar::exists(subcmd);
		if(isConVar){
			String varValue = cmd.subString(spIndex + 1);
			ConVar* pVar = ConVar::findByName(subcmd);
			Msg("Setting value to %s\n", (char*) varValue);
			pVar->setValue(varValue);
		}
		else if(ConCommandBase::exists(subcmd)){
			CArgs args = String(cmd.subString(spIndex+1));
			ConCommandBase::getCommand(subcmd)->performCommand(&args);
		}
	}
	else if(ConCommandBase::exists(cmd)){
			//CArgs args = cmd;
			ConCommandBase::getCommand(cmd)->performCommand(nullptr);
	}
	else if(ConVar::exists(cmd)){
		ConVar* pVar = ConVar::findByName(cmd);
		const char* pName 		= (char*) (*(pVar->getName()));
		const char* pToolTip 	= (char*) (*(pVar->getToolTip()));
		const char* pValue 		= pVar->getCStr();
		
		Msg("\n\t %s = \"%s\"\n\t\t\"%s\"\n\n", pName, pValue, pToolTip);
	}
	else{
		Msg("Unknown command\n");
	}
}

CON_COMMAND(quit){
	dynamic_cast<CConsole*>(g_pConsole)->m_bQuit = true;
}

String g_sEmptyLines(100,'\n');

CON_COMMAND(cls){
	Msg(g_sEmptyLines);
}

CON_COMMAND(printstars) {
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			Msg("*");
		}
		Msg("\n");
	}
}
