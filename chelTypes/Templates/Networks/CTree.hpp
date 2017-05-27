#ifndef CHEL_TREE_HPP
#define CHEL_TREE_HPP
#include "CTree.h"

template<class T> CTree<T>::CTree(Ptr<CTreeNode<T>> node) {
	m_pNode = node;
}

template<class T> CTree<T>::CTree() {
	//m_pNode = new CTreeNode<T>();
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
	//TODO ensure trees don't share children!
	
	otherTree.setParent(*this);
}

template<class T> void CTree<T>::setParent(CTree<T>& parent) {
	m_pNode->m_parent = parent;
	parent.m_pNode->m_children.push(*this);
}

template<class T> bool CTree<T>::treesShareAncestor(const CTree<T>& t1, const CTree<T>& t2) {
	bool foundMatch = false;
	
	//this is kind of like pointer arithmetic except as an iterative singly-linked list of sorts
	CTree<T> firstTreeParent = t1.getParent();
	while (firstTreeParent && !foundMatch) {
		CTree<T> secondTreeParent = t2.getParent();
		while (secondTreeParent && !foundMatch) {
			foundMatch = (firstTreeParent == secondTreeParent);
			secondTreeParent = secondTreeParent.getParent();
		}
		firstTreeParent = firstTreeParent.getParent();
	}
	
	return foundMatch;
}



#endif //CHEL_TREE_HPP
