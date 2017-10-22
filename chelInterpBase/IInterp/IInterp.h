#ifndef CHEL_IINTERP
#define CHEL_IINTERP

#include "../../chelDocBase/chelDocBase.h"

class IInterp;

extern CDynList<IInterp*> g_lInterpreters;



// extend this class for each Interpreter.
class IInterp {
public:
	// Add itself to g_lInterpreters anytime a new Interpreter is created.
	IInterp() {
		g_lInterpreters.push(this);
	}
	
	~IInterp() {}
	
	// Every interpreter should have a language name.
	// This should be the same name as the library.
	// ex. java.dll should return "java"
	virtual const String& getLanguageName() = 0;
	
	// File Extension should not include "."
	virtual const String& getFileExtension() = 0;
	
	virtual Ptr<NChelDoc::CDocTree> interpFile(const SFilePath& path) = 0;
	
	static const CDynList<IInterp*>* interpreterList() { return &g_lInterpreters; }
};


#endif //CHEL_IINTERP