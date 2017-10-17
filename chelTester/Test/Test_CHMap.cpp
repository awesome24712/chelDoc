#include "CTestCase.h"

CTestPlan Test_CHMap("Hash Map");

TEST(constructor) {
	CHLiteralMap<int, String> test(31);
	CHLiteralMap<int, String> ref(31);
	CHLiteralMap<int, String> ref2(29);
	
	assertEquals(test.size(), 0);
	assertEquals(test, ref);
	assertFalse(test == ref2);
}

TEST(flushOnEmpty) {
	CHLiteralMap<int, String> test(31);
	CHLiteralMap<int, String> ref(31);
	
	test.flush();
	
	assertEquals(test.size(), 0);
	assertEquals(test, ref);
}

TEST(flushOnFull) {
	CHLiteralMap<int, int> test(31);
	CHLiteralMap<int, int> ref(31);
	
	test.add(10, 42);
	test.add(32, 42);
	test.add(33, 42);
	test.add(34, 42);
	test.add(35, 42);
	test.add(36, 42);
	test.add(37, 42);
	test.add(38, 42);
	test.add(39, 42);
	
	test.flush();

	assertEquals(test, ref);
}

TEST(add) {
	CHLiteralMap<int, int> test(31);
	CHLiteralMap<int, int> ref(31);
	
	for (int i = 0; i < 10; i++) {
		test.add(i, 42);
		ref.add(i, 42);
	}
	
	assertEquals(test, ref);
	
	for (int i = 0; i < 10; i++) {
		assertTrue(test.hasKey(i));
		assertTrue(ref.hasKey(i));
	}
	
	assertEquals(test.size(), 10);
	assertEquals(ref.size(), 10);
}

TEST(removeToEmpty) {
	CHLiteralMap<int,int> test(11);
	
	test.add(3,42);
	
	assertEquals(test.remove(3), 42);
	assertEquals(test.size(), 0);
}

TEST(hashHasKey) {
	CHMap<String, int> test(31);
	
	test.add("Hello", 42);
	
	assertTrue(test.hasKey("Hello"));
	assertFalse(test.hasKey("olleH"));
}

TEST(hashHasValue) {
	CHLiteralMap<int, int> test(11);
	
	test.add(1, 1);
	test.add(2, 2);
	test.add(3, 3);
	test.add(4, 4);
	
	assertFalse(test.hasValue(0));
	assertTrue(test.hasValue(1));
	assertTrue(test.hasValue(2));
	assertTrue(test.hasValue(3));
	assertTrue(test.hasValue(4));
	assertFalse(test.hasValue(5));
}

TEST(hashHasValueAfterRemoveToEmpty) {
	CHLiteralMap<int, int> test(11);
	
	test.add(1, 1);
	test.add(2, 2);
	test.add(3, 3);
	test.add(4, 4);
	
	test.remove(1);
	test.remove(2);
	test.remove(3);
	test.remove(4);
	
	assertFalse(test.hasValue(0));
	assertFalse(test.hasValue(1));
	assertFalse(test.hasValue(2));
	assertFalse(test.hasValue(3));
	assertFalse(test.hasValue(4));
	assertFalse(test.hasValue(5));
}

TEST(hashHasManyKeysAndValues) {
	CHMap<String, Ptr<String>> test(31);
	
	test.add("Hello", new String("World!"));
	test.add("World!", new String("And all"));
	test.add("And all", new String("who inhabit it!"));
	
	assertTrue(test.hasKey("Hello"));
	assertTrue(test.hasKey("World!"));
	assertTrue(test.hasKey("And all"));
	
	assertEquals(*(test.value("Hello")), String("World!"));
	assertEquals(*(test.value("World!")), String("And all"));
	assertEquals(*(test.value("And all")), String("who inhabit it!"));
	
	assertEquals(test.size(), 3);
}

TEST(hashValuePtr) {
	CHMap<String, int> test(11);
	test.add("1", 1);
	
	assertTrue((bool)test.valuePtr("1"));
	
	assertEquals(test.value("1"), 1);
	
	*(test.valuePtr("1")) = 2;
	
	assertEquals(test.value("1"), 2);
}

TEST(hashBigAmount) {
	CHLiteralMap<int, int> test(31);
	CHLiteralMap<int, int> ref(31);
	
	for (int i = 0; i < 10000; i++) {
		assertEquals(test.size(), i);
		test.add(i, RandInt());
		assertTrue(test.hasKey(i));
		assertFalse(test.hasKey(i+1));
	}
	
	for (int i = 0; i < 10000; i++) {
		assertEquals(test.size(), 10000-i);
		test.remove(i);
		if (i < 9999)
			assertTrue(test.hasKey(i+1));
		assertFalse(test.hasKey(i));
	}
	
	assertEquals(test.size(), 0);
	assertEquals(test, ref);
}