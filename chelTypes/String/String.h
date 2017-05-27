#ifndef CHEL_STRING_H
#define CHEL_STRING_H
#include "../Templates/Lists/CDynList.hpp"

/**
 * @brief Measures length of null-terminated character string.
 * @param str - the string to measure
 * @return - the length of the string
 */
int strlen(const char * str);

/**
 * @class String
 * @author Chel
 * @date 17/04/2017
 * @file String.h
 * @brief A dynamicly sizeable array-indexed list of characters. 
 * 			The character array is located on the heap, and is reallocated
 * 			to larger and smaller sizes as necessary.
 * 			The array reserves space on either end of itself to allow for
 * 			efficient popping/pushing from either end.
 * 			Allows for implicit conversions to and from {const char *}
 * 
 * 
 */
class String : public CDynList<char> {
private:
	
	
public:

	String() : CDynList<char>() {}
	
	String(int reservation) : CDynList<char>(reservation) {}

	String(int num, char initial) : CDynList<char>(num, initial) {}
	
	String(const char * str);
	
	String(const String& str);
	
	String(const CDynList<char>& str);
	
	String& operator=(const CDynList<char>& str);
	
	String& operator= (const char* str);
	
	bool operator==(const String& other);
	
	String operator+(const char* str);
	
	String& operator+=(const char* str);
	
	/*operator char*();*/
};
#endif //CHEL_STRING_H