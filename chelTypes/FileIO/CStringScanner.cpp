#include "CStringScanner.h"

//for defining global load-to-string function;


String g_sDefaultSeparatorCharacters = " \n";

CStringScanner::CStringScanner(String str) {
	m_string = str;
	m_pSeparatorCharacters = &g_sDefaultSeparatorCharacters;
}

CStringScanner::CStringScanner(String str, const String* separatorCharacters) {
	m_string = str;
	m_pSeparatorCharacters = separatorCharacters;
}

String CStringScanner::nextUntil(char c) {
	AssertFalse(atEOS(), "In String CStringScanner::nextUntil(char), scanner is not at end of stream");
	
	int nextStop = m_string.indexOf(c);
	if (nextStop == -1)
		return m_string.remove(0, m_string.length());
	else
		return m_string.removeByIndexes(0, nextStop);
}

String CStringScanner::nextLine() {
	AssertFalse(atEOS(), "In String CStringScanner::nextLine(), scanner is not at end of stream");
	
	String result = nextUntil('\n');
	
	//remove the next line character
	if (!atEOS())
		m_string.popFront();
	
	return result;
}

String CStringScanner::next() {
	AssertFalse(atEOS(), "In String CStringScanner::next(), scanner is not at end of stream");
	
	//trim off separators from the beginning
	m_string.removeBannedPrefixingElements(*m_pSeparatorCharacters);
	
	//find the next separator
	int nextSequenceEndIndex = m_string.indexOfAnyOf(*m_pSeparatorCharacters);
	if (nextSequenceEndIndex == -1)
		nextSequenceEndIndex = m_string.length();
	
	return m_string.removeByIndexes(0, nextSequenceEndIndex);
}