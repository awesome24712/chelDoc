#ifndef CHEL_TREE_H
#define CHEL_TREE_H
#include "CDynList.hpp"
#include "Ptr.hpp"

template <class T> class CTreeNode;

template <class T>
using CTree = Ptr<CTreeNode<T>>;

template<class T> class CTreeNode {
private:
	Ptr<T> m_ptValue;
	CTree m_pParent;
	Ptr<CDynList<CTree<T>>>> m_aChildren;
	
public:
	//CTree<T>(T label, int reservation = 5);
	CTree<T>(T* pValue, int reservation = 5);
	
	inline bool isLeaf() {return ((CDynList<T>*)(m_aChildren))->length() == 0;}
	inline int 	numberOfChildren() {return ((CDynList<T>*)(m_aChildren))->length();}
	
	inline CTree getParent() {return m_pParent;}
	inline void	setParent(CTree parent) {m_pParent = parent;}
	
	inline CTree child(int pos) {return (*m_aChildren).get(pos);}
	
};
#endif //CHEL_TREE_H