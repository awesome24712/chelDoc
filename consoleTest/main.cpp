#include <stdio.h>
#include "stdint.h"
#include "../chelTypes/chelTypes.hpp"
#include "../chelMath/perfTest.hpp"

int main(int argc, char **argv) {
	gArgs.parseGlobalsArgs(argc, argv);
	
	if (gArgs.hasArg("testarg"))
		printf("Command line arg found!");
	else
		printf("Command line arg not found!");
}

