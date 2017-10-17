#include "CTreeOld.hpp"

void treeToString(CTree<String> t, String& dest, int indentlevel) {
	//print indents
	for (int i = 0; i < indentlevel; i++)
		dest.push('\t');
		
	//now print our own value
	dest += t.value() + "\n";
	
	//increment indent level and print children's values
	indentlevel++; 
	for (int i = 0; i < t.numChildren(); i++) {
		treeToString(t.child(i), dest, indentlevel);
	}
}