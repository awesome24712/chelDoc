#include "CTask.h"

String g_sWorkingDirectory;
char slashChar;

static void CTask::setWorkingDirectory(String& dir){
	g_sWorkingDirectory = dir;
}

static void SFilePath::goUpDirectory() {
	//Get index of last meaningful forward or backward slash.
	char last = g_sWorkingDirectory->end();
	bool hasLast = (last == "\\" || last == "/");
	int slashLoc = g_sWorkingDirectory->   .indexOf(last);
	
	//Remove extra slash if there is one.
	if(hasLast){
		g_sWorkingDirectory->remove(slashLoc)
		slashLoc = g_sWorkingDirectory.indexOf(last);
	}
	
	//If there are no more slashes, goUpDirectory won't do anything.
	//To make it do something, add an else block.
	if(slashLoc != -1) {
		g_sWorkingDirectory.removeByIndexes(slashLoc, 
						g_sWorkingDirectory.length());
	}
}

static void SFilePath::goDownDirectory(String& subfile){
	//Get a char with the appropriate slash.
	if(slashChar = NULL){
		char slash = getSlashChar();
	}
	//Get rid of slashes on Working Directory and subfile
	if(g_sWorkingDirectory.end() == slashChar){
		g_sWorkingDirectory.pop();
	}
	if(subfile.front() == slashChar){
		subfile.popFront();
	}
	
	g_sWorkingDirectory.push(slashChar);
	g_sWorkingDirectory += subfile;
}

static char SFilePath::getSlashChar(){
	char slash;
	if(g_sWorkingDirectory.contains("\")){
		slash = "\";
	} else if(g_sWorkingDirectory.contains"/") {
		slash = "/";
	} else {    // Set the default to / if no slashes are found.
		slash = "/";
	}
}

