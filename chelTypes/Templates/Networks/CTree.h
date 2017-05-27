#ifndef CHEL_TREE_H
#define CHEL_TREE_H
#include "../Lists/CDynList.hpp"
#include "../Wrappers/Ptr.hpp"

template<class T> class CTree;

template <class T> class CTreeNode {
	friend class CTree<T>;
private:
	T m_value;
	CTree<T> m_parent;
	CDynList<CTree<T>> m_children;
	
	CTreeNode<T>() {}
	CTreeNode<T>(T value) { m_value = value; }
	CTreeNode<T>(T value, CTree<T> parent) {
		m_parent = parent; m_value = value;
	}
};

template <class T> class CTree {
	friend class CTreeNode<T>;
private:
	Ptr<CTreeNode<T>> m_pNode;
	
	CTree<T>(Ptr<CTreeNode<T>> node);
public:
	CTree<T>();
	CTree<T>(T value);
	CTree<T>(const CTree<T>& parent, T value);

	inline T 		value() const { return m_pNode->m_value; }
	inline void		set(T value) { m_pNode->m_value = value; }
	
	CTree<T>		child(int index) const;
	CTree<T>		addChild();
	CTree<T>		addChild(T value);
	void			addChild(CTree<T>& otherTree);
	
	inline int 		numChildren() const { return m_pNode->m_children.length(); }
	inline bool 	isLeaf() const { return numChildren() == 0; }
	
	operator 		bool() { return m_pNode; }
	inline CTree<T> getParent() const { return m_pNode->m_parent; }
	inline bool 	hasParent() const { return getParent(); }
	inline bool		isHead() const { return !hasParent(); }
	void 			setParent( CTree<T>& parent );
	
	static bool 	treesShareAncestor(const CTree<T>& t1, const CTree<T>& t2);
};


#endif //CHEL_TREE_H