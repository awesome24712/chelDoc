#pragma once
#include <stdio.h>
#include <ctime>

double perfTest(void (*procedure)(void), const char * testName) {
	std::clock_t start = std::clock();
	
	(*procedure)();
	
	double duration = (std::clock() - start) / CLOCKS_PER_SEC;
	
	printf("----Completed task \"%s\" in %.3f seconds------", testName, duration);
	
	return duration;
}