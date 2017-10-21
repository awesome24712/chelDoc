#ifndex NDirectoryScanner
#define NDirectoryScanner

#include "/../../chelDocBase/Task/CTask.h"


namespace NDirectoryScanner {

	void fromPath(const char* absolutePath, CTask* pathsList);
	
	void startupDirectory(String& dir);
}

#endif //NDirectoryScanner