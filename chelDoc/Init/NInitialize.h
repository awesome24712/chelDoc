#ifndef CHEL_INITIALIZE
#define CHEL_INITIALIZE

#include "../chelInterp/chelInterp.h"
#include "../chelProjectScanner/chelProjectScanner.h"

namespace NChelDoc {
	void Initialize();
	
	void LoadCommonConfigs();
	
	void LoadRuntimeLibraries();
	
	void LoadConfigForLang(const String& langName);
}


#endif //CHEL_INITIALIZE