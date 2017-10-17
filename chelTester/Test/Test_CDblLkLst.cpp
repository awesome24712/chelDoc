#include "CTestCase.h"

CTestPlan test_CDblLkLst("CDblLkLst Test");

TEST(defaultConstructor) {
	CDblLkLst<int> test;
	CDblLkLst<int> other;
	
	assertEquals(test.length(), 0);
	assertEquals(other.length(), 0);
	assertEquals(test, other);
}

TEST(push) {
	CDblLkLst<int> test;
	CDblLkLst<int> ref;
	
	test.push(1);
	test.push(2);
	test.push(3);
	
	assertFalse(test == ref);
	
	assertEquals(test.length(), 3);
	assertEquals(test.get(0), 1);
	assertEquals(test.get(1), 2);
	assertEquals(test.get(2), 3);
}

TEST(pop) {
	CDblLkLst<int> test;
	CDblLkLst<int> ref;
	test.push(1);
	test.push(2);
	test.push(3);
	
	assertFalse(test == ref);
	
	assertEquals(test.pop(), 3);
	assertEquals(test.pop(), 2);
	assertEquals(test.pop(), 1);
	
	assertEquals(test, ref);
}

TEST(pushAfterPop) {
	CDblLkLst<int> test;
	CDblLkLst<int> ref;
	
	test.push(1);
	ref.push(1);
	
	test.pop();
	test.push(1);
	assertEquals(test, ref);
}

TEST(length) {
	CDblLkLst<int> test;
	
	assertEquals(test.length(), 0);
	test.push(RandInt());
	assertEquals(test.length(), 1);
	test.push(RandInt());
	assertEquals(test.length(), 2);
}

TEST(lengthOnAddRandom) {
	CDblLkLst<int> test;
	
	for (int i = 0; i < 100; i++) {
		assertEquals(test.length(), i);
		int nextIndex = RandInt(0, test.length());
		test.add(nextIndex, RandInt());
	}
}

TEST(add) {
	CDblLkLst<int> test;
	
	test.push(0);
	test.push(2);
	test.add(1, 1);
	
	assertEquals(test.length(), 3);
	assertEquals(test.get(0), 0);
	assertEquals(test.get(1), 1);
	assertEquals(test.get(2), 2);
}

TEST(randomAccessPerformance) {
	CDblLkLst<int> test;
	for (int i = 0; i < 100; i++) {
		test.push(RandInt());
	}
	int sum = 0;
	for(int i = 0; i < 1000000; i++) {
		sum += test.get(RandInt(0, test.length() - 1));
	}
	printf("\t\t%i\n", sum);
}