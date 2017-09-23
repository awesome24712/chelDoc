//#include "../chelTypes/chelTypes.hpp"
#include "../chelMath/chelMath.hpp"
#include "../chelTypes/chelTypes.hpp"
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "typeinfo"

#include "Array/CArray.hpp"
#include "Array/CArray.hpp"

int main() {
	CTree<String> pTree("Hello World!");
	
	CTree<String> firstChild = pTree.addChild("First Child!");
	firstChild.addChild("1");
	firstChild.addChild("2");
	firstChild.addChild("3").addChild("3.5");
	
	pTree.addChild("Second Child!").addChild("2.5");
	
	String stringRep;
	treeToString(pTree, stringRep);
	printf(stringRep);
}