#ifndef CTask
#define CTask

#include "/../../chelTypes/chelTypes.hpp"

struct SFilePath{
private:
	String m_sRelativePath;
	static char getSlashChar();
public:
	String getFilePath() {  return m_sRelativePath;  }
	
	// Constructor with path as a parameter
	SFilePath(String& path){
		m_sRelativePath = path;
	}
	//Static methods for navigating Working Directory
	static const String& getWorkingDirectory();
	static void goUpDirectory();
	static void goDownDirectory(String& subfile);
	static void setWorkingDirectory(String& dir);
	void setRelativePath(String& path) { m_sRelativePath = path; }
	const String& getRelativePath() { return m_sRelativePath; }
};



class CTask {
private:
	const CDynList<SFilePath> m_aFilePaths;
	int m_iNextIndex;
	
public:
	
	CDynList<SFilePath>* getFilePaths() { return &m_aFilePaths;  }
	
	void addFilePath(const SFilePath& toAdd) { m_aFilePaths->push(toAdd); }
	
	bool m_bMirrorDir;
};

#endif //CTask