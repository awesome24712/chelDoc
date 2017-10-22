#ifndef CHEL_DIRECTORY_SCANNER
#define CHEL_DIRECTORY_SCANNER

#include "../../chelDocBase/Task/CTask.h"


namespace NDirectoryScanner {

	void fromPath(const char* absolutePath, CTask* pathsList);
	
	void startupDirectory(String& dir);
	
	inline int testFunc() { return 3; }
}

#endif //CHEL_DIRECTORY_SCANNER