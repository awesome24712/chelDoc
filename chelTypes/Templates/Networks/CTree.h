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
protected:
	Ptr<CTreeNode<T>> m_pNode;
	
	CTree<T>(Ptr<CTreeNode<T>> node);
	
	//privatize emptry constructor
	//attempting to create a default-value treenode results
	//in infinite recursion
	CTree<T>() {}
public:
	/**
	 * Builds a new tree with the given initial value
	 * @param value - the initial value of the tree
	 */
	CTree<T>(T value);
	
	/**
	 * @brief Builds a new tree with the given value
	 * 		attached to a given parent
	 * @param parent - the parent to attach to
	 * @param value - the value of this new node
	 */
	CTree<T>(const CTree<T>& parent, T value);
	
	//TODO: write up recursive reference-counting algorithm
	//	that destroys the entire tree structure when
	//	there are no external references
	~CTree<T>() {}

	/**
	 * @brief Retrieves the value contained at this tree node
	 * @return the value
	 */
	inline T 		value() const { return m_pNode->m_value; }
	
	/**
	 * @brief Retrieves address of the value contained at this node
	 * @return the address of the value
	 */
	inline T*		valuePtr() const { return &(m_pNode->m_value); }
	
	/**
	 * @brief Sets the value at this node to the given value
	 * @param value - the overriding value
	 */
	inline void		set(T value) { m_pNode->m_value = value; }
	
	/**
	 * @brief Retrieves a child of this node by index
	 * @param index - the index of the child
	 * @requires {index} is a valid index
	 * @return the child
	 */
	CTree<T>		child(int index) const;
	
	/**
	 * @brief Builds a valid default-value child in-place
	 * @return the created child
	 */
	CTree<T>		addChild();
	
	/**
	 * @brief Adds a child with the given value
	 * @param value - the value of the child
	 * @return - the created child
	 */
	CTree<T>		addChild(T value);
	
	/**
	 * @brief Adds the given tree as a child of this
	 * @param otherTree - the other tree
	 * @requires - {otherTree} does not already have a parent
	 */
	void			addChild(CTree<T>& otherTree);
	
	/**
	 * @brief Removes a child by index
	 * @param index - the index of the child to be removed
	 * @return - the removed child tree
	 */
	CTree<T>		removeChild(int index);
	
	/**
	 * @brief Breaks references between parent and this
	 * @return - the removed parent
	 */
	CTree<T>		removeParent();
	
	/**
	 * @brief Inserts a default-value parent.
	 * 		If {this} already has a parent, then the new
	 * 		parent becomes a child of the old parent
	 * @return - the new parent
	 */
	CTree<T>		insertParent();
	
	/**
	 * @brief Inserts a default-value parent.
	 * 		If {this} already has a parent, then the new
	 * 		parent becomes a child of the old parent
	 * @param value - the value of the new parent
	 * @return - the new parent
	 */
	CTree<T>		insertParent(T value);
	
	/**
	 * @brief Inserts the given tree as a parent of {this}
	 * 		If {this} already has a parent, then the new
	 * 		parent becomes a child of the old parent
	 * 		The given parent maintains its other children
	 * @param parent - the new parent of {this}
	 * @requires - {this} does not already have a parent
	 */
	void 			insertParent(CTree<T>& parent);
	
	/**
	 * @return - the number of children
	 */
	inline int 		numChildren() const { return m_pNode->m_children.length(); }
	
	/**
	 * @brief Checks if this node is a leaf. A leaf is defined as a node
	 * 		that has no children.
	 * @return - if {this} is a leaf
	 */
	inline bool 	isLeaf() const { return numChildren() == 0; }
	
	/**
	 * @brief Implicit conversion to bool checks
	 * 		if this tree is non-null
	 */
	operator 		bool() { return m_pNode; }
	
	/**
	 * @brief Retrieves the parent of {this}
	 * @return the parent
	 */
	inline CTree<T> getParent() const { return m_pNode->m_parent; }
	
	/**
	 * @return - whether or not this tree has a parent
	 */
	inline bool 	hasParent() const { return getParent(); }
	
	/**
	 * @return Checks if this tree is the head of the tree.
	 * 		A head of a tree does not have a parent.
	 */
	inline bool		isHead() const { return !hasParent(); }
	
	/**
	 * @brief Links {this} as a child of the given parent
	 * @requires {this} does not already have a parent
	 * @param parent
	 */
	void 			setParent( CTree<T>& parent );
	
	/**
	 * @brief Checks if any of the ancestors of t1 are also ancestors
	 * 		of t2, i.e. if t1 and t2 are parts of a larger tree structure
	 * @param t1
	 * @param t2
	 * @return 
	 */
	static bool 	treesShareAncestor(const CTree<T>& t1, const CTree<T>& t2);
};


#endif //CHEL_TREE_H