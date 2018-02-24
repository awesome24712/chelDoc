#ifndef CHEL_CONCOMMAND
#define CHEL_CONCOMMAND

#include "../../String/String.h"
#include "../../Templates/Networks/Net_Templates.hpp"

class CArgs {
private:
	CDynList<char*> m_Args;
	
public:
	CArgs(String& str) { parseFromString(str); }
	void parseFromString(String& str);
	const char* get(int i) const { return *(m_Args.getPtr(i)); }
	int argCount() const { return m_Args.length(); }
	
	const char* operator[](int i) { return get(i); }
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
		class ConCommand_##name : public ConCommandBase { \
			public: ConCommand_##name(const char* _pszName) : ConCommandBase(_pszName) {} \
			virtual void performCommand(CArgs* args) override; \
		}; \
		ConCommand_##name name(#name); \
		void ConCommand_##name::performCommand(CArgs* args)
		
namespace Commands {
	extern CHMap<String, ConCommandBase*> g_mCommands;
}
		

#endif //CHEL_CONCOMMAND