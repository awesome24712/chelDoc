#include "windows.h"
#include "NDirectoryScanner.h"
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

char directoryBuffer[512];

namespace NDirectoryScanner {
	void fromPath(const char* absolutePath, CTask* pathsList) {
		// Iterate through all files in path and add them to pathsList.
		for(auto& p : fs::recursive_directory_iterator(absolutePath)){
			wcstombs(directoryBuffer, p.path().c_str(), 512);
			pathsList->addFilePath(SFilePath(String(directoryBuffer)));
		}
	}
	
	void startupDirectory(String& dir) {
		// Set dir to the current directory
		wcstombs(directoryBuffer, fs::current_path().root_path().c_str(), 512);
		dir = directoryBuffer;
	}
}