#include "ConCommand.h"



namespace Commands {
	CHMap<String, ConCommandBase*> g_mCommands(31);
}

ConCommandBase::ConCommandBase(const char* _pszName) {
	m_sName = _pszName;
	Commands::g_mCommands.add(m_sName, this);
}

bool ConCommandBase::exists(const String& sName){
	return Commands::g_mCommands.hasKey(sName);
}

ConCommandBase* ConCommandBase::getCommand(const String& sName){
	return Commands::g_mCommands.value(sName);
}


void CArgs::parseFromString(const String& str) {
	//make a copy
	printf("Received string \"%s\"\n", (char*) str);
	String str2 = str;
	
	
	//remove initial command
	str2.trimSpaces();
	str2.push(' '); //an extra space for the indexing to work
	str2.pushFront(' ');
	
	int prevSpaceIndex = 0;
	int nextSpaceIndex = str2.indexOfBounded(' ', prevSpaceIndex + 1, str2.length());
	while (nextSpaceIndex != -1) {
		printf("Parsing string \"%s\"\n", (char*) str2);
		String arg = str2.subString(prevSpaceIndex + 1, nextSpaceIndex);
		arg.pop(); //pop off the space
		printf("Parsed \"%s\"\n", (char*) arg);
		m_Args.push(arg); 
		
		if (nextSpaceIndex == str2.length() - 1)
			break;
		
		prevSpaceIndex = nextSpaceIndex;
		nextSpaceIndex = str2.indexOfBounded(' ', prevSpaceIndex + 1, str2.length());;
	}
}