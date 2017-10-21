#ifndef CHEL_CONCOMMAND
#define CHEL_CONCOMMAND

#include "../../String/String.h"
#include "../../Templates/Networks/Net_Templates.hpp"

class CArgs {
private:
	CDynList<String> m_Args;
	
public:
	CArgs(const String& str) { parseFromString(str); }
	void parseFromString(const String& str);
};

class ConCommandBase {
private:
	String m_sName;
	
public:
	ConCommandBase(const char* _pszName);
	
	virtual void performCommand(CArgs* args) = 0;
	
	static bool exists(const String& sName);
	
	static ConCommandBase* getCommand(const String& sName);
};



#define CON_COMMAND(name) \
	namespace Commands { \
		class ConCommand_##name : public ConCommandBase { \
			virtual void performCommand(CArgs* args) override; \
		}; \
		ConCommand_##name name(#name); \
		void ConCommand##name::performCommand(CArgs* args)
		
namespace Commands {
	extern CHMap<String, ConCommandBase*> g_mCommands;
}
		

#endif //CHEL_CONCOMMAND