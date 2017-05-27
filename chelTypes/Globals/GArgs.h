#ifndef CHEL_GARGS
#define CHEL_GARGS

#include "../Templates/Lists/CDynList.hpp"
#include "../String/String.h"

struct GArgsLst {
private:
	CDynList<String> m_argLst;
public:
	void parseGlobalsArgs(int argc, char **argv);
	
	bool hasArg(String arg) const { return m_argLst.indexOf(arg) != -1; }
	void printArgs() const;
};

extern GArgsLst gArgs;

#endif //CHEL_GARGS