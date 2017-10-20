//#include "../chelTypes/chelTypes.hpp"
#include "../chelMath/chelMath.hpp"
#include "../chelTypes/chelTypes.hpp"
#include "stdio.h"
//#include "stdlib.h"
//#include "memory.h"
//#include "typeinfo"

//#include "Array/CArray.hpp"
//#include "Array/CArray.hpp"



void treeTest() {
	printf("Begin tree test\n");
	{
		CTreeHandle<int> t = 3;
		printf("Built tree handle\n");
		//int var = t->child(-1)->value();
		t->addChild(2)->addChild(67);
		printf("Added two children\n");
		
		t->addChild(5);
		t->addChild(42)->addChild(101)->addChild(32);
		
		CTree<int>* ch = t->child(1);
		ch->addChild(1);
		ch->addChild(2);
		ch->addChild(2);
		
		printf("Finished adding children\n");
		
		String treeAsString;
		
		//void (*pProcedure)(const CTree<int>*, String&, int) = &treeToString;
		
		printf("Converting tree to string\n");
		treeToString(t.getPtr(), treeAsString, 0);
		
		printf("Printing tree as string\n");
		printf(treeAsString);
		printf("Finished tree test\n");
	}
	printf("End tree test\n");
}




int main() {
	try {
		
	} catch (CChelException* e) {
		printf("Begin exception handling\n");
		e->handle();
	}
}