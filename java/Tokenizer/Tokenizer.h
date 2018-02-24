#ifndef CHEL_TOKENIZER
#define CHEL_TOKENIZER

/**
 * 
 * A "block" is
 * 		A declaration of package
 * 		A block of comments
 * 		A function header with definition removed
 * 		A namespace-member variable declaration
 * 		A class, interface, or enum header
 * 		An open or close curly brace { } 
 * 
 * 		No new line characters, except in comments
 * 		No Tabs characters
 * 		No spaces at ends
 * 		No substrings of spaces longer than length 1
 * 		
 * 
 * @param str
 * @clears str
 * @param blocks - location of output
 */
void splitIntoBlocks(const String& str, CDynList<String>& blocks);

#endif //CHEL_TOKENIZER