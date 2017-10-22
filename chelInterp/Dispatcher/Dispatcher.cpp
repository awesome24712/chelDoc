#include "Dispatcher.h"
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;


IInterp* NDispatcher::getInterpreterFor(String& filePath) {
	char* filePathType;
	int dot = filePath.lastIndexOf('.');
	for(int i = filePath.length()-1; i >= dot; i--){
		filePathType += filePath.pop();
	}
	IInterp* pResult = nullptr;
	filePath += filePathType;
	for(int i = 0; i < g_lInterpreters.length(); i++){
		if(filePathType == g_lInterpreters.get(i)->getFileExtension()){
			pResult = g_lInterpreters.get(i);
			break;
		}
	}
	
	return pResult;
	
}

//Use function to get interp. AssertTrue(interp). Call function
//to get documentation for file.
Ptr<NChelDoc::CDocTree> NDispatcher::getDocumentationFor(String& filePath){
	IInterp* forFile = getInterpreterFor(filePath);
	AssertTrue(forFile, "No interpreter found for this file type.");
	
	return forFile->interpFile(filePath);
	
}