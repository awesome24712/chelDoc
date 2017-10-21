#include "CConsole.h"
#include "string"
#include "iostream"

CConsole g_console;


char g_pszBuffer[128];


void CConsole::Msg(const char* pszFormat, ...){
	snprintf(g_pszBuffer, 128, pszFormat, ...);
	m_sPreviousOutput += g_pszBuffer;
	printf(g_pszBuffer);
	
	if(m_sPreviousOutput.length()>10000){
		m_sPreviousOutput.removeByIndexes(0,2000);
	}
}

void CConsole::EnterCommandCycle(){
	
	while(!m_bQuit){
		std::string currentCommand;
		
		std::getline(std::cin, currentCommand);
		String cmd = currentCommand.c_str();
		
		cmd.trimSpaces();
		if(cmd.contains(' ')){
			int spIndex = cmd.indexOf(' ');
			String subcmd = cmd.subString(0,spIndex);
			bool isConVar = exists(subcmd);
			if(isConVar){
				String varValue = cmd.subString(spIndex+1,cmd.length());
				ConVar* pVar = ConVar::findByName(subcmd);
				pVar->setValue(varValue);
			}
			else if(ConCommandBase::exists(subcmd)){
				CArgs args = cmd;
				ConCommandBase::getCommand(subcmd)->performCommand(&args);
			}
		}
		else if(ConCommandBase::exists(cmd)){
				CArgs args = cmd;
				ConCommandBase::getCommand(cmd)->performCommand(&args);
		}
		else if(ConVar::exists(cmd)){
			ConVar* pVar = ConVar::findByName(cmd);
			Msg(pVar->getToolTip());
		}
		else{
			Msg("Unknown command");
		}
	}
}



CON_COMMAND(quit){
	g_console.m_bQuit = true;
}

String g_sEmptyLines(100,'\n');
CON_COMMAND(cls){
	Msg(g_sEmptyLines);
}
