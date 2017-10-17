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
	printf("Begin main\n");
	{
		CTreeHandle<int> t = 3;
		t->addChild(4)->addChild(67);
		printf("%i\n", t->child(0)->value());
	}
	printf("End main\n");
}