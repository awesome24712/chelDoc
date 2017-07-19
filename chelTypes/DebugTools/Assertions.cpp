#include "Assertions.h"
#include "stdio.h"

void AssertTrue(bool bCondition, const char * pszMsg) {
#if DEBUG
	if (!bCondition) {
		printf("------------Assertion \"%s\" failed!---------------\n", pszMsg);
	}
#endif
}

void AssertFalse(bool bCondition, const char* pszMsg) {
	AssertTrue(!bCondition, pszMsg);
}