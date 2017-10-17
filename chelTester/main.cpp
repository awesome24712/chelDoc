#include <stdio.h>
#include "CTestCase.h"

extern CDynList<CTestPlan*>* g_papTestPlans;

/**
 * @brief This program runs test cases.
 * 		DON'T MODIFY THIS FILE! Use the test folder instead!
 */
int main() {
	RandSeed();
	printf("Beginning test plans...\n");
	printf("(%i plans)\n", g_papTestPlans->length());
	for (int i = 0; i < g_papTestPlans->length(); i++) {
		CTestPlan* pPlan = g_papTestPlans->get(i);
		if (pPlan) {
			pPlan->runTestPlan();
		}
	}
	printf("\nFinished!\n");
}
