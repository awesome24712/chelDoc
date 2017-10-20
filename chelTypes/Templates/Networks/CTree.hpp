#ifndef CHEL_CTREE_HPP
#define CHEL_CTREE_HPP

#include "CTree.h"

template<class T> void CTree<T>::dispatchProcedure(void (*pProcedure)(T*)) {
	(*pProcedure)(valuePtr());
	for (int i = 0; i < numChildren(); i++) {
		child(i)->dispatchProcedure(pProcedure);
	}
}

template<class T> template<class R> CTree<R>* CTree<T>::dispatchFunctionRecurse(R (*pFunction)(T*)) {
	CTree<R>* resultNode = new CTree<T>((*pFunction)(valuePtr()));
	
	for (int i = 0; i < numChildren(); i++) {
		resultNode.addChild(child(i)->dispatchFunctionRecruse(pFunction));
	}
}

template<class T> int CTree<T>::indexOfChild(const T& childValue) const {
	int foundIndex = -1;
	for (int i = 0; i < numChildren(); i++) {
		if (child(i).value() == childValue) {
			foundIndex = i;
			goto end;
		}
	}
	end:
	return foundIndex;
}

template<class T> CTree<T>* CTree<T>::insertSubParent(const T& value) {
	CTree<T>* subParent = new CTree<T>(value);
	subParent->m_pParent = this;
	for (int i = 0; i < numChildren(); i++) {
		child(i)->m_pParent = subParent;
	}
	return subParent;
}

template<class T> void CTree<T>::toString(String& dest, void (*pFunc)(String&, const T&), int iIndentLevel) const {
	//print indents
	for (int i = 0; i < iIndentLevel; i++)
		dest.push('\t');
		
	//now print our own value
	String toStr;
	(*pFunc)(toStr, this->value());
	dest += toStr + "\n";
	
	//increment indent level and print children's values
	iIndentLevel++; 
	for (int i = 0; i < this->numChildren(); i++) {
		this->child(i)->treeToString(dest, pFunc, iIndentLevel);
	}
}

template<class T> int CTree<T>::size() const {
	int size = 1;
	for (int i = 0; i < numChildren(); i++) {
		size += child(i)->size();
	}
	return size;
}

void treeToString(const CTree<String>* t, String& dest, int indentlevel = 0);
void treeToString(const CTree<int>* t, String& dest, int indentlevel = 0);

#endif //CHEL_CTREE_HPP