#include "CTestCase.h"

CTestPlan Test_Map("CMap");

TEST(mapConstructor) {
	CMap<int, int> test;
	CMap<int, int> ref;
	
	assertEquals(test, ref);
	assertEquals(test.size(), 0);
}

TEST(mapAdd) {
	CMap<int,int> test;
	test.add(0, 42);
	test.add(1, 42);
	test.add(2, 42);
	
	assertTrue(test.hasKey(0));
	assertTrue(test.hasKey(1));
	assertTrue(test.hasKey(2));
}

TEST(mapHasKey) {
	CMap<String, int> test;
	test.add("Hello", 42);
	assertTrue(test.hasKey("Hello"));
	assertFalse(test.hasKey("olleH"));
}

TEST(mapsEqual) {
	CMap<String, int> test;
	CMap<String, int> ref;
	
	//assertEquals(test, ref);
	
	test.add("Hello", 42);
	ref.add("world", 42);
	
	assertFalse(test == ref);
	
	test.add("world", 42);
	ref.add("Hello", 42);
	assertEquals(test, ref);
}

TEST(mapRemove) {
	CMap<int, int> test;
	
	test.add(3, 42);
	assertEquals(test.remove(3), 42);
	assertEquals(test.size(), 0);
}