#ifndef CHEL_PERFTEST_HPP
#define CHEL_PERFTEST_HPP

#include <stdio.h>
#include <ctime>

double perfTest(void (*procedure)(void), const char * testName);

#endif //CHEL_PERFTEST_HPP