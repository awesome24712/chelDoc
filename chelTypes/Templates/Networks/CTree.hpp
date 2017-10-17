#ifndef CHEL_CTREE_HPP
#define CHEL_CTREE_HPP

#include "CTree.h"

template<class T> void CTree<T>::dispatchProcedure(void (*pProcedure)(T*)) {
	(*pProcedure)(valuePtr());
	for (int i = 0; i < numChildren(); i++) {
		child(i)->dispatchProcedure(pProcedure);
	}
}

template<class T> int CTree<T>::indexOfChild(const T& childValue) {
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


#endif //CHEL_CTREE_HPP