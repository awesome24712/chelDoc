#ifndef CHEL_ASSERTIONS_H
#define CHEL_ASSERTIONS_H

#include "stdio.h"

void AssertTrue(bool bCondition, const char * pszMsg) {
#if DEBUG
	if (!bCondition) {
		printf("------------Assertion \"%s\" failed!---------------\n", pszMsg);
	}
#endif
}

inline void AssertFalse(bool bCondition, const char * pszMsg) {AssertTrue(!bCondition, pszMsg);}

#endif //CHEL_ASSERTIONS_H