#include "CTestCase.h"

CTestPlan xmlplan("CXMLTree and CXMLTreeHandle");

TEST(xmlConstruct) {
	CXMLTreeHandle t("Root");
	
	assertEquals(t->label(), "Root");
	assertEquals(t->size(), 1);
	assertEquals(t->numAttributes(), 0);
}