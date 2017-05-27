#include "GArgs.h"

GArgsLst gArgs;

void GArgsLst::parseGlobalsArgs(int argc, char** argv) {
	while (argc > 0) {
		m_argLst.push(argv[--argc]);
	}
}

void GArgsLst::printArgs() const {
	for (int i = 0; i < m_argLst.length(); i++)
		printf(m_argLst.get(i));
}