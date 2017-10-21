#include "ConCommand.h"



namespace Commands {
	CHMap<String, ConCommandBase*> g_mCommands(31);
}

ConCommandBase::ConCommandBase(const char* _pszName) {
	m_sName = _pszName;
	Commands::g_mCommands.add(m_sName, this);
}


void CArgs::parseFromString(const String& str) {
	//make a copy
	String str2 = str;
	
	//remove initial command
	str2.trimSpaces();
	str2.push(' '); //an extra space for the indexing to work
	int nextSpaceIndex = str2.indexOf(' ');
	while (nextSpaceIndex != -1) {
		str2.removeByIndexes(0, nextSpaceIndex + 1);
		
		nextSpaceIndex = str2.indexOf(' ');
		if (nextSpaceIndex != -1) {
			m_Args.push(str2.subString(0, nextSpaceIndex));
		}
	}
}