#ifndef CHEL_TREE_HPP
#define CHEL_TREE_HPP
#include "CTree.h"

template<class T> CTreeNode<T>::CTreeNode(T* pValue, int reservation) {
	m_ptValue = pValue;
	m_pParent = nullptr;
	m_aChildren = new CDynList<CTreeNode<T>>(reservation);
}
#endif //CHEL_TREE_HPP
