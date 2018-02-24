#include "ConCommand.h"

namespace Commands {
	CHMap<String, ConCommandBase*> g_mCommands(31);
}

ConCommandBase::ConCommandBase(const char* _pszName) {
	printf("Building console command %s\n", _pszName);
	m_sName = _pszName;
	Commands::g_mCommands.add(m_sName, this);
}

bool ConCommandBase::exists(const String& sName){
	return Commands::g_mCommands.hasKey(sName);
}

ConCommandBase* ConCommandBase::getCommand(const String& sName){
	return Commands::g_mCommands.value(sName);
}


void CArgs::parseFromString(String& str) {
	//make a copy
	str.trimSpaces();
	char* firstChar = (char*) str;
	for (int i = 0; i < str.length(); i++) {
		if (str.get(i) == ' ' && str.get(i+1) != ' ') {
			str.set(i, '\0');
			m_Args.push(firstChar + i + 1);
		}
	}
}

/*CON_COMMAND(parseargs) {
	printf("Received args:\n");
	for (int i = 0; i < args->argCount(); i++)
		printf("\t%s\n", args->get(i));
	printf("Finished command\n");
}*/