#include "windows.h"
#include <filesystem>
namespace fs = std::filesystem;
// Be sure to include NDirectoryScanner somehow in the chain.

ClkLst<HINSTANCE> dllLibraries;
int lastSlash(String str){
	int slash = filePath.lastIndexOf("/");
	int backslash = filePath.lastIndexOf("\\");
	if(backslash > slash)
		slash = backslash;
	return slash;
}

void getLastFileName(String filePath, String& result) {
	slash = lastSlash(filePath);
	result = filePath.remove(slash, filePath.length());
}

void loadFromCfgFiles(CTask* cfgFiles){
	String startupPath = fs::currentPath().root_path().c_str();
	CDynList<SFilePath> cfgs = *(cfgFiles.getFilePaths());
	CDynList<String> interpFiles;
	for(int i = 0; i < cfgs->length(); i++) {
		
		
		String dllPath = startupPath + cfgs.getPtr(i)->getRelativePath();
		
		String lastFile = "";
		getLastFileName(dllPath, lastFile);
		
		dllPath = startupPath + "/interp/" + lastFile +".dll";
		
		// Open .dll file and store to dllLibraries.
		HINSTANCE getDLL = LoadLibrary(dllPath);
		AssertTrue(getDll, String("Library ") + dllPath + String(" does not exist"));
		dllLibraries.get(i) = getDLL;
	}
}