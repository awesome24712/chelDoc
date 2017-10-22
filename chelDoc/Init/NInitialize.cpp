#include "Init/NInitialize.h"

namespace NChelDoc {
	void Initialize() {
		LoadCommonConfigs();
		LoadRuntimeLibraries();
	}
	
	void LoadCommonConfigs() {
		//get startup directory
		String loc;
		NDirectoryScanner::startupDirectory(loc);
		loc /= "autoexec.cfg";
		NCFGLoad::fromFile(loc);
		
		NDirectoryScanner::startupDirectory(loc);
		loc /= "interp.cfg";
		NCFGLoad::fromFile(loc);
		
		NDirectoryScanner::startupDirectory(loc);
		loc /= "web.cfg";
		NCFGLoad::fromFile(loc);
	}
	
	void LoadRuntimeLibraries() {
		//TODO make CTask for file in confif folder and dispatch that
		//to the NDynamicLoader!
		
		//CTask* cfgFiles;
		//NDynamicLoad::loadFromCfgFiles(cfgFiles);
		
	}
	
	void LoadConfigForLang(const String& langName) {
		//get startup directory
		String loc;
		NDirectoryScanner::startupDirectory(loc);
		loc /= "config/";
		loc /= langName;
		NCFGLoad::fromFile(loc);
	}
}