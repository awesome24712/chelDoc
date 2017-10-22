#include "windows.h"
#include "../Dispatcher/Dispatcher.h"
#include "../../chelInterpBase/IInterp/IInterp.h"
#include "../../chelProjectScanner/chelProjectScanner.h"

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
// Be sure to include NDirectoryScanner somehow in the chain.



CLkLst<HINSTANCE> dllLibraries;

int lastSlash(const String& filePath){
	int slash = filePath.lastIndexOf('/');
	int backslash = filePath.lastIndexOf('\\');
	if(backslash > slash)
		slash = backslash;
	return slash;
}

void getLastFileName(String filePath, String& result) {
	int slash = lastSlash(filePath);
	result = filePath.remove(slash, filePath.length());
}

void NDynamicLoad::loadFromCfgFiles(CTask* cfgFiles){
	String startupPath;
	::NDirectoryScanner::startupDirectory(startupPath);
	CDynList<SFilePath> cfgs = *(cfgFiles->getFilePaths());
	CDynList<String> interpFiles;
	for(int i = 0; i < cfgs.length(); i++) {
		
		
		String dllPath = startupPath + cfgs.getPtr(i)->getRelativePath();
		
		String lastFile = "";
		getLastFileName(dllPath, lastFile);
		
		dllPath = startupPath + "/interp/" + lastFile +".dll";
		
		// Open .dll file and store to dllLibraries.
		HINSTANCE getDLL = LoadLibrary(dllPath);
		AssertTrue(getDLL, String("Library ") + dllPath + String(" does not exist"));
		dllLibraries.push(getDLL);
	}
}