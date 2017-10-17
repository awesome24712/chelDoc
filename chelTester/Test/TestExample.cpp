//Get access to testing facilities
#include "CTestCase.h"

//Declare a test plan
CTestPlan testExample("Principles of Math");
//all following test cases will fall under this test plan.
//The Macro'd black magic works that way.

TEST(negativePlusPositiveIsZero) {
	int someNum = -3;
	int someOtherNum = 3;
	assertEquals(someNum + someOtherNum, 0);
}

TEST(anythingTimesZeroIsZero) {
	assertEquals(3*0, 0);
	assertEquals(1*0, 1);
	assertEquals(4*0, 0);
	assertEquals(5*0, 0);
}

TEST(listAverage) {
	CDynList<int> aNums;
	aNums.setReserveBuffer(1000);
	for (int i = 0; i < 100000; i++) {
		aNums.push(RandInt());
	}
	
	int sum = aNums.pop();
	int count = 1;
	while (!aNums.isEmpty()) {
		int curNum = (aNums.pop());
		int difference = (curNum - sum) / count + 1;
		sum += difference;
	}
	assertTrue(aNums.isEmpty());
	assertTrue(sum > 0);
}