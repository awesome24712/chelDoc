#include "CXMLTree.h"

inline void printTabs(String& dest, int iIndentLevel) {
	dest.reserve(iIndentLevel + 1);
	for (int i = 0; i < iIndentLevel; i++)
		dest += "\t";
}

void CXMLTree::toString(String& dest, int iIndentLevel) {
	//print tabs
	printTabs(dest, iIndentLevel);
	
	//print header and attributes
	dest += String("<") + label();
	for (int i = 0; i < numAttributes(); i++) {
		const String& curAttribute = m_mAttributes.keyByIndex(i);
		dest += String(" ") + curAttribute + String("=\"") + attributeValue(curAttribute) + String("\"");
	}
	
	dest += "\n";
	
	//make the recursive call
	iIndentLevel++;
	for (int i = 0; i < numChildren(); i++) {
		child(i)->toString(dest, iIndentLevel);
	}
	
	//print footer
	iIndentLevel--;
	printTabs(dest, iIndentLevel);
	dest += "</";
	dest += label();
	dest += ">\n";
}