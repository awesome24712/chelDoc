#include <stdio.h>
#include "../chelTypes/chelTypes.hpp"
#include "CTestCase.h"

extern CDynList<CTestPlan*>* g_papTestPlans;

void CTestPlan::RunAll() {
	RandSeed();
	SendCommand("cls");
	Msg("Beginning test plans...\n");
	Msg("(%i plans)\n", g_papTestPlans->length());
	
	int iErrorCount = 0;
	for (int i = 0; i < g_papTestPlans->length(); i++) {
		CTestPlan* pPlan = g_papTestPlans->get(i);
		if (pPlan) {
			pPlan->runTestPlan();
			iErrorCount += pPlan->m_iErrorCount;
		}
	}
	Msg("\nFinished (%i errors)!\n", iErrorCount);
}

/**
 * @brief This command runs all test cases.
 * 		DON'T MODIFY THIS FILE! Use the test folder instead!
 */
CON_COMMAND(run_tests) {
	CTestPlan::RunAll();
}
