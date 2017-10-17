#include "CTestCase.h"

/**
 * @class CTree
 * @author Chel
 * @date 02/10/2017
 * @file Test_CTree.cpp
 * @brief - rigorously tests all functions of CTree
 */
CTestPlan Test_CTree("CTree");

CTree<int> GetUnbalancedTree() {
	CTree<int> t(1);
	t.addChild(0).addChild(1).addChild(2).addChild(3).addChild(4);
	t.addChild(1);
	return t;
}

TEST(measureUnbalancedTree) {
	CTree<int> t = GetUnbalancedTree();
	
	assertEquals(t.size(), 7);
	assertEquals(t.height(), 6);
}

TEST(children) {
	CTree<int> t(-1);
	for (int i = 0; i < 5; i++) {
		t.addChild(i);
		assertEquals(t.child(i).value(), i);
		assertEquals(t.child(i).getParent(), t);
	}
	assertEquals(t.numChildren(), 5);
	
}