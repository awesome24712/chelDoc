/**
 * This file wraps together includes for implementable list class templates
 * 
 */
#ifndef CHEL_LIST_TEMPLATES_H
#define CHEL_LIST_TEMPLATES_H

#include "CDynList.hpp"
#include "CList.hpp"
#include "CLkList.hpp"

/**
 * Prints a list to console
 * @param list - the list to print out, which must implement {.length()} and {.get(int)}
 * @param format - the {const char *} format, ex. {"%s"}, {"%i"}. Concatenated to {'\n'}
 */
#define printList(list, format) \
	for (int i = 0; i < (list).length(); i++) \
		printf((format "\n"), *((list).get(i))); \
	printf("Length: %i\n", (list).length()); \
	printf("ResLength: %i\n", (list).reservedLength())

#endif //CHEL_LIST_TEMPLATES_H