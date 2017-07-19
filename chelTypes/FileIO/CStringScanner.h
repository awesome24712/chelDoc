#ifndef CHEL_STRING_SCANNER
#define CHEL_STRING_SCANNER

#include "../String/String.h"

class CStringScanner {
private:
	String m_string;
	const String* m_pSeparatorCharacters;
	
public:
	CStringScanner(String str);
	CStringScanner(String str, const String* separatorCharacters);
	
	inline bool atEOS() { return m_string.isEmpty(); }
	
	/**
	 * @brief Returns the next sequence of characters until the given character
	 * 		or end of stream.
	 * 		Does not pop off the search character, so calling this twice would
	 * 		return an empty String
	 * @return - the substring from the current start of the string to the given char
	 */
	String nextUntil(char c);
	
	/**
	 * @brief Retrieves the next line of text from the string, and pops off
	 * 		the new line character.
	 * @return 
	 */
	String nextLine();
	
	/**
	 * @brief Retrieves the next available sequence of characters which does not contain
	 * 		any of the separator characters
	 * @requires - the scanner has not reached the end of the string
	 * @return - the next 'word'
	 */
	String next();
	
	/**
	 * @brief Exposes the internalized String for external manipulation
	 * @return - a pointer to the string
	 */
	String* accessStr() { return &m_string; }
};

void loadFileToCString(const char* pszFileName, char** dest);

#endif //CHEL_STRING_SCANNER