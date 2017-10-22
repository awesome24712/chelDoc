#ifndef CHEL_ASSERTIONS_H
#define CHEL_ASSERTIONS_H

//#include "../String/String.h"
#include "stdio.h"
#include "string.h" //for strcpy

#define ASSERTION_HEADER "**********************************ASSERTION FAILED**********************************\n"
#define ASSERTION_FOOTER "************************************************************************************\n"

class CChelException {
private:
	char* m_pszErrorMsg;
	
public:
	CChelException(const char* pszPrefix, const char* pszMsg) {
		m_pszErrorMsg = new char[strlen(pszPrefix) + strlen(pszMsg) + 2];
		strcpy(m_pszErrorMsg, pszPrefix);
		strcpy(m_pszErrorMsg + strlen(pszPrefix), pszMsg);
	}
	
	~CChelException() {
		delete[] m_pszErrorMsg;
	}
	
	const 	char* 	errorMsg() const { return m_pszErrorMsg; }
	virtual void 	handle() const {
		printf(ASSERTION_HEADER "%s\n" ASSERTION_FOOTER, errorMsg());
	}
};

#define STRINGIZE_internal(a) #a
#define STRINGIZE(a) STRINGIZE_internal(a)

#if DEBUG

/**
 * Use these assertions to test preconditions
 * @param bCondition - the condition to test for
 * @param pszMsg - additional message printed out when assertion fails
 */ 
#define AssertTrue(bCondition, pszMsg) \
	do { \
		if (!(bCondition)) { \
			throw new CChelException("In file " STRINGIZE(__FILE__) " line:" STRINGIZE(__LINE__) ",\n\tviolation of precondition: " #bCondition " -- ", pszMsg); \
		}\
	} while(false)

//#define AssertTrue(bCondition) AssertTrue(bCondition, "")
#define AssertFalse(bCondition, pszMsg) AssertTrue(!(bCondition), pszMsg)
//#define AssertFalse(bCondition) AssertTrue(!bCondition)


#else
#define AssertTrue(a,b)
#define AssertFalse(a,b)
#endif
//void AssertTrue(bool bCondition, const char * pszMsg);

//void AssertFalse(bool bCondition, const char * pszMsg);

#endif //CHEL_ASSERTIONS_H