#ifndef CHEL_TREE_HPP
#define CHEL_TREE_HPP
#include "CTree.h"

template<class T> CTree<T>::CTree(Ptr<CTreeNode<T>> node) {
	m_pNode = node;
}

template<class T> CTree<T>::CTree(T value) {
	m_pNode = new CTreeNode<T>(value);
}

template<class T> CTree<T>::CTree(const CTree<T>& parent, T value) {
	m_pNode = new CTreeNode<T>(value);
	parent.addChild(*this);
}

template<class T> CTree<T> CTree<T>::child(int index) const {
	AssertTrue(index >= 0 && index < numChildren(), "Valid index for CTree child access");
	return m_pNode->m_children.get(index);
}

template<class T> CTree<T> CTree<T>::addChild() {
	CTree<T> child = Ptr<CTreeNode<T>>(new CTreeNode<T>());
	child.setParent(*this);
	return child;
}

template<class T> CTree<T> CTree<T>::addChild(T value) {
	CTree<T> child = Ptr<CTreeNode<T>>(new CTreeNode<T>(value));
	child.setParent(*this);
	return child;
}

template<class T> void CTree<T>::addChild(CTree<T>& otherTree) {
	AssertTrue(otherTree.isRoot(), "For CTree<T>::addChild(CTree<T>& otherTree), otherTree has not parent");
	otherTree.setParent(*this);
}

template<class T> bool CTree<T>::hasChildValue(const T& value) const {
	bool hasValue = false;
	for (int i = 0; i < numChildren() && !hasValue; i++)
		hasValue = child(i).value() == value;
	return hasValue;
}

template<class T> bool CTree<T>::hasChildRecurse(const CTree<T>& otherTree) const {
	bool bHasChild = otherTree == *this;
	
	for (int i = 0; i < numChildren() && !bHasChild; i++) {
		bHasChild = child(i).hasChildRecurse(otherTree);
	}
	
	return bHasChild;
}

template<class T> bool CTree<T>::hasChildValueRecurse(const T& value) const {
	bool bHasChildValue = this->value() == value;
	
	for (int i = 0; i < numChildren() && !bHasChildValue; i++) {
		bHasChildValue = child(i).hasChildValueRecurse(value);
	}
	
	return bHasChildValue;
}

template<class T> CTree<T> CTree<T>::removeChild(int index) {
	CTree<T> tChild = m_pNode->m_children.remove(index);
	tChild.m_pNode->m_parent.m_pNode.nullify();
	return tChild;
}

template<class T> CTree<T> CTree<T>::removeParent() {
	AssertTrue(this->hasParent(), "Removed CTree<> parent exists");
	CTree<T> parent = getParent();
	getParent().removeChild(parent.m_pNode->m_children.indexOf(*this));
	return parent;
}

template<class T> CTree<T> CTree<T>::insertParent() {
	CTree<T> newParent(new CTreeNode<T>());
	insertParent(newParent);
	return newParent;
}

template<class T> CTree<T> CTree<T>::insertParent(T value) {
	CTree<T> newParent(new CTreeNode<T>(value));
	insertParent(newParent);
	return newParent;
}

template<class T> void CTree<T>::insertParent(CTree<T>& parent) {
	CTree<T> prevParent = this->removeParent();
	this->setParent(parent);
	parent.setParent(prevParent);
}

template<class T> CTree<T> CTree<T>::getRoot() const {
	CTree<T> curParent = *this;
	while (!curParent.isRoot())
		curParent = curParent.getParent();
	return curParent;
}

template<class T> void CTree<T>::setParent(CTree<T>& parent) {
	AssertFalse(hasParent(), "In CTree<T>::setParent(CTree<T>&), this does not already have parent.");
	
	m_pNode->m_parent = parent;
	parent.m_pNode->m_children.push(*this);
}

template<class T> CTree<T> CTree<T>::lowestCommonAncestor(const CTree<T>& t1, const CTree<T>& t2) {
	AssertTrue(treesShareAncestor(t1, t2), "Trees share ancestor");
	
	CTree<T> result;
	
	//this is kind of like pointer arithmetic except as an iterative singly-linked list of sorts
	CTree<T> firstTreeParent = t1;
	CTree<T> secondTreeParent = t2;
	
	bool bAlternateNextParent = false;
	
	//loop until we find a result
	while (!result) {
		if (firstTreeParent == secondTreeParent) {
			result = firstTreeParent;
			break;
		}
		
		if (bAlternateNextParent) {
			firstTreeParent = firstTreeParent.getParent();
		}
		else {
			secondTreeParent = secondTreeParent.getParent();
		}
		bAlternateNextParent = !bAlternateNextParent;
	}
	
	return result;
}



#endif //CHEL_TREE_HPP
