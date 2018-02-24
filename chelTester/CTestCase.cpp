#include "CTestCase.h"
#include <ctime>
#include <sys/time.h>
#include "stdio.h"

CDynList<CTestPlan*>*		g_papTestPlans = nullptr;
CTestPlan* 					g_pCurTestPlan;

CTestPlan::CTestPlan(const char* pszName) {
	if (!g_papTestPlans) {
		g_papTestPlans = new CDynList<CTestPlan*>();
	}
	
	m_sName = pszName;
	g_pCurTestPlan = this;
	g_papTestPlans->push(this);
}

CTestCase::CTestCase(const char* pszName) {
	m_pszName = pszName;
	g_pCurTestPlan->m_aTestCases.push(this);
}

double getTime() {
	timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	return ms / 1000.0;
}

const char* g_pszPassMsg = "Passed!";
const char* g_pszFailMsg = "FAILED";
#define TEST_CASE_NAME_CODE "%-30s"

void CTestPlan::runTestPlan() {
	m_iErrorCount = 0;
	int iNumPassed = 0;
	double dRunTime = 0.0;
	
	//Run test cases first, then display results
	for (int i = 0; i < m_aTestCases.length(); i++) {
		double dStartTime = getTime();
		CTestCase* pCase = m_aTestCases.get(i);
		
		//catch exceptions for each test case
		try {
			pCase->runTest();
		} catch (CChelException* e) {
			pCase->m_bPassed = false;
			pCase->m_bException = true;
			pCase->m_sExceptionMsg = e->errorMsg();
			pCase->m_aErrorList.push(e->errorMsg());
			delete e;
		}
		double dInterval = getTime() - dStartTime;
		m_aTestCases.get(i)->m_dRunTime = dInterval;
		dRunTime += dInterval;
		
		int* pIncremented = m_aTestCases.get(i)->passed() ? &iNumPassed : &m_iErrorCount;
		(*pIncremented)++;
	}
	
	m_bPassed = !m_iErrorCount;
	const char* pszResultMsg = m_bPassed ? g_pszPassMsg : g_pszFailMsg;
	
	//Print test plan header
	printf("Test plan: %s %s\n", (char*) m_sName, pszResultMsg);
	printf("-> %i passed, %i failed! (%lfs)\n", iNumPassed, m_iErrorCount, dRunTime);
	
	//Display results of individual test cases and their errors
	for (int i = 0; i < m_aTestCases.length(); i++) {
		CTestCase* pCase = m_aTestCases.get(i);
		if (!pCase->passed()) {
			printf("\tTest case " TEST_CASE_NAME_CODE " failed!\n", pCase->name());
			for (int i = 0; i < pCase->m_aErrorList.length(); i++) {
				printf("\t\t%s\n", (char*) (*(pCase->m_aErrorList.getPtr(i))));
			}
		} else {
			printf("\tTest case " TEST_CASE_NAME_CODE " passed! (%lfs)\n", pCase->name(), pCase->m_dRunTime);
		}
	}
}