#ifndef IInterp
#define IInterp

#include "/../../chelDocBase/"

// extend this class for each Interpreter.
class IInterp {
private:
	static CDynList<IInterp*> g_lInterpreters;
public:
	// Add itself to g_lInterpreters anytime a new Interpreter is created.
	IInterp() {
		g_lInterpreters.push(this);
	}
	// Every interpreter should have a language name.
	virtual const String& getLanguageName() = 0;
	
	// File Extension should not include "."
	virtual const String& getFileExtension() = 0;
	
	virtual Ptr<CDocTree> interpFile(const SFilePath& path) = 0;
}


#endif //IInterp