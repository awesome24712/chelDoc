#include "String.h"
#include "Character.h"

/**
 * @brief Measures length of null-terminated character string.
 * @param str - the string to measure
 * @return - the length of the string
 */
/*int strlen(const char * str) {
	int length = 0;
	while (*(str++)) length++;
	return length;
}*/

String::String(const char * str) {
	int num = strlen(str);
	m_array = new char[num];
	m_iReservedLength = num;
	m_iReserveBuffer = (int) (num * 1.3);
	m_iEndIndex = num;
	for (int i = 0; i < num; i++)
		m_array[i] = str[i];
}

String& String::operator =(const CDynList<char>& str) {
	if (this != &str) {
		delete[] m_array;
		m_iReservedLength 	= str.m_iReservedLength;
		m_array 			= new char[m_iReservedLength];
		m_iReserveBuffer 	= str.m_iReserveBuffer;
		m_iEndIndex 		= str.m_iEndIndex;
		m_iStartIndex 		= str.m_iStartIndex;
		for (int i = 0; i < str.length(); i++) {
			m_array[i] = str.m_array[i];
		}
	}
	return *this;
}

String::String(const CDynList<char>& str) {
	m_iReservedLength 	= str.m_iReservedLength;
	m_array 			= new char[m_iReservedLength];
	m_iReserveBuffer 	= str.m_iReserveBuffer;
	m_iEndIndex 		= str.m_iEndIndex;
	m_iStartIndex 		= str.m_iStartIndex;
	m_bAutoTrim			= str.m_bAutoTrim;
	for (int i = m_iStartIndex; i < m_iEndIndex; i++) {
		m_array[i] = str.m_array[i];
	}
}

String::String(const String& str) {
	m_iReservedLength 	= str.m_iReservedLength;
	m_array 			= new char[m_iReservedLength];
	m_iReserveBuffer 	= str.m_iReserveBuffer;
	m_iEndIndex 		= str.m_iEndIndex;
	m_iStartIndex 		= str.m_iStartIndex;
	m_bAutoTrim			= str.m_bAutoTrim;
	for (int i = m_iStartIndex; i < m_iEndIndex; i++) {
		m_array[i] = str.m_array[i];
	}
}

#define STRING_MAX_INT_SIZE 33
String String::fromInt(int toStr) {
	char pStr[33];
	sprintf(pStr, "%i", toStr);
	return String(pStr);
}

void String::toUpperCase() {
	for (int i = 0; i < length(); i++)
		Character::toUpperCase(getPtr(i));
}

void String::toLowerCase() {
	for (int i = 0; i < length(); i++)
		Character::toLowerCase(getPtr(i));
}

String& String::operator=(const char * str) {
	flush();
	delete[] m_array;
	
	int num = strlen(str);
	m_array = new char[num];
	m_iReservedLength = num;
	m_iReserveBuffer = (int) (num * 1.3);
	m_iEndIndex = num;
	for (int i = 0; i < num; i++)
		m_array[i] = str[i];
		
	return *this;
}

bool String::operator ==(const String& other) const {
	return this->length() == other.length() && (this->length() == 0 || this->indexOf(other) != -1);
}

String String::operator+(const char * str) {
	String copy = *this;
	
	int reservedBack = reservedLength() - m_iEndIndex;
	int otherLength = strlen(str);
	if (otherLength >= reservedBack) {
		copy.reserve(otherLength + m_iReserveBuffer);
	}
	for (int i = 0; i < otherLength; i++)
		copy.push(str[i]);
	
	return copy;
}
		
String& String::operator +=(const char* str) {
	int reservedBack = reservedLength() - m_iEndIndex;
	int otherLength = strlen(str);
	if (otherLength >= reservedBack) {
		this->reserve(otherLength + m_iReserveBuffer);
	}
	for (int i = 0; i < otherLength; i++)
		this->push(str[i]);
		
	return *this;
}
