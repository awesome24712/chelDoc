#ifndef INTERP_JAVA
#define INTERP_JAVA

#include "../../chelInterpBase/IInterp/IInterp.h"

// extend this class for each Interpreter.
class CInterp : public IInterp {
public:
	// Add itself to g_lInterpreters anytime a new Interpreter is created.
	CInterp() : IInterp() { }
	
	~IInterp() {}
	
	// Every interpreter should have a language name.
	// This should be the same name as the library.
	// ex. java.dll should return "java"
	virtual const String& getLanguageName();
	
	// File Extension should not include "."
	virtual const String& getFileExtension();
	
	virtual Ptr<NChelDoc::CDocTree> interpFile(const SFilePath& path);
};

void loadFile(const char* pFile, String& dest);

void outputFile(const char* dest, const String& str);

#endif //INTERP_JAVA