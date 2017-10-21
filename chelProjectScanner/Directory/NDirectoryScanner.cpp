#include "Windows.h"
#include <filesystem>
namespace fs = std::filesystem;

void NDirectoryScanner::fromPath(const char* absolutePath, CTask* pathsList) {
	
	// Iterate through all files in path and add them to pathsList.
	for(auto& p : fs::recursive_directory_iterator(absolutePath)){
		pathsList->addFilePath(p);
	}
}

void NDirectoryScanner::startupDirectory(String& dir) {
	
	// Set dir to the current directory
	dir = fs.current_path;
}