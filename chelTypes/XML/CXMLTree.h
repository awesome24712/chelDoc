#ifndef CHEL_CXMLTREE_H
#define CHEL_CXMLTREE_H

#include "../String/String.h"
#include "../Templates/Networks/CMap.hpp"
#include "../Templates/Networks/CTree.hpp"

//forward declaration
class CXMLTree;

/**
 * @class CXMLTreeHandle
 * @author Chel
 * @date 19/10/2017
 * @file CXMLTree.h
 * @brief An CXMLTree which handles the memory of itself and its children.
 * 		The value at this and all children are removed from heap
 * 			when all copies of this are destroyed.
 */
class CXMLTreeHandle {
private:
	friend class CXMLTree;
	Ptr<CXMLTree> m_pNode;

public:
	
	CXMLTreeHandle(CXMLTree* treeOnHeap) { m_pNode = treeOnHeap; }
	CXMLTreeHandle(const String& _sLabel);
	
	CXMLTree& get() { return *m_pNode; }
	CXMLTree* getPtr() { return m_pNode; }
	
	operator CXMLTree*() const { return m_pNode; }
	operator CXMLTree&() const { return *m_pNode; } 
	CXMLTree* operator->() const { return m_pNode; }
	CXMLTree& operator*() const { return *m_pNode; }
};

/**
 * @class CXMLTree
 * @author Chel
 * @date 20/10/2017
 * @file CXMLTree.h
 * @brief CXMLTree models the XML format.
 * 		Use CXMLTreeHandle to declare a root before using CXMLTree.
 */
class CXMLTree {
	friend class CXMLTreeHandle;
	friend class Ptr<CXMLTree>;
protected:
	String 					m_sLabel;
	CMap<String, String>	m_mAttributes;
	bool 					m_bIsTag; //whether or not our label is inside </>
	
	CXMLTree* 				m_pParent;
	CDynList<CXMLTree*> 	m_aChildren;
	
	CXMLTree(const String& _sLabel) {
		m_sLabel  	= _sLabel;
		m_pParent 	= nullptr;
		m_bIsTag 	= false;
	}
	~CXMLTree() {
		for (int i = 0; i < m_aChildren.length(); i++) {
			delete m_aChildren.get(i);
		}
		printf("Destorying tree node\n");
	}
	
	
public:
	
	/**
	 * @brief Given a procedure which takes a pointer to T as a parameter,
	 * 	dispatches the procedure onto the value at this and onto all children.
	 * 	Order is depth-first.
	 */
	void dispatchProcedure(void (*pProcedure)(CXMLTree*));
	
	/**
	 * @brief Given a function which takes a pointer to T and returns R,
	 * 		dispatches the function onto the value of this and onto all
	 * 		children, recursively. Returns a tree of results matching the
	 * 		original shape and ordering of the tree at this.
	 * @return - the tree of results
	 */
	template<class R> CTreeHandle<R> dispatchFunction(R (*pFunction)(CXMLTree*)) {
		return CTreeHandle<R>(dispatchFunctionRecurse(pFunction));
	}
	
private:
	template<class R> CTree<R>* dispatchFunctionRecurse(R (*pFunction)(CXMLTree*));
	
	//requires that otherTree has no parent already
	CXMLTree*	addChild(CXMLTree* otherTree) {
		AssertFalse(otherTree->hasParent(), "added tree must not already have parent");
		AssertFalse(this->isTag(), "this must not be tag");
		
		otherTree->m_pParent = this;
		this->m_aChildren.push(otherTree);
		return otherTree;
	}
public:
	
	int numChildren() const { return m_aChildren.length(); }
	
	/**
	 * @brief Pushes a child onto this.
	 * @param label - the label of the child node.
	 * @return - address of added child.
	 */
	CXMLTree*	addChild(const String& label) {
		CXMLTree* pChild = new CXMLTree(label);
		pChild->m_pParent = this;
		m_aChildren.push(pChild);
		return m_aChildren.getEnd(0);
	}
	
	/**
	 * @brief Retrieves address of child, by index
	 * @param index
	 * @return 
	 */
	CXMLTree* 	child(int index) const {
		return m_aChildren.get(index);
	}
	
	/**
	 * @brief Given a String, returns the index of the first found child
	 * 		whose label() matches. Returns -1 otherwise.
	 * @param childLabel - the label to look for
	 * @return - the index of the firstfound child with that value, -1 otherwise.
	 */
	int 		indexOfChild(const String& childLabel) const;
	
	/**
	 * @brief Detaches a child ang gives it back as a CXMLTreeHandle
	 * @param index - the index of the child to remove
	 * @return - a CXMLTreeHandle for that child
	 */
	CXMLTreeHandle removeChild(int index) { return CXMLTreeHandle(m_aChildren.remove(index)); }
	
	/**
	 * @brief Gets the parent of this
	 * @return - pointer to parent
	 */
	CXMLTree* 	parent() const { return m_pParent; }
	
	/**
	 * @brief Checks whether or not this has a parent
	 * @return 
	 */
	bool 		hasParent() const { return m_pParent; }
	
	/**
	 * @brief Inserts a node between this and the children of this.
	 * @updates this, this.children
	 * @param label - the label at the new node
	 * @return - address of the new node
	 */
	CXMLTree* 	insertSubParent(const String& label);
	
	/**
	 * @brief Allocates more space for children. This happens automatically anyway
	 * 			but doing it manually can improve performance.
	 * @perf Use this if you are about to add more children, and you know
	 * 		about how many you will add.
	 * 		Larger amounts will allow for faster growing/shrinking, but take
	 * 		up more memory.
	 * @param newSpace - the number of extra children to allocate for.
	 */
	void 		reserve(int newSpace) {
		m_aChildren.reserve(newSpace);
	}
	
	/**
	 * @brief Modifiers the amount by which extra space is reserved when
	 * 		adding additional children to this requires re-allocation
	 * 		of the array. Larger values allow for faster adding/removing, but
	 * 		take up more memory.
	 * @perf Use larger values when the expected number of children is small,
	 * 		small values otherwise.
	 * @param iBuffer - the amount by which to grow
	 */
	void 		setReserveBuffer(int iBufferSize) {
		m_aChildren.setReserveBuffer(iBufferSize);
	}
	
	//void toString(String& dest, void (*pFunc)(String&, const T&), int iIndentLevel = 0) const;
	
	/**
	 * @brief Recursively counts the number subtrees + 1
	 * @return - number of subtrees + 1
	 */
	int 		size() const;
	
	
public:
	
	/**
	 * @brief Returns const reference to the label of this
	 * @return reference to the label of this
	 */
	inline const String& 	label() const { return m_sLabel; }
	
	/**
	 * @brief Returns mutable reference to the label of this
	 * @return - reference to label of this
	 */
	inline String&			labelMutable() { return m_sLabel; }
	
	/**
	 * @brief Sets the label of this
	 * @param _sLabel - the new label.
	 */
	inline void				setLabel(const String& _sLabel) { m_sLabel = _sLabel; }
	
	/**
	 * @brief Given the name of the attribute, returns whether or not
	 * 		this has that attribute.
	 * @param sAttribute - the attribute to look for
	 * @return whether or not it's there, duh
	 */
	inline bool 			hasAttribute(const String& sAttribute) const { return m_mAttributes.hasKey(sAttribute); }
	
	/**
	 * @brief Given an index, returns const reference to the attribute at that index
	 * @param pos - the index
	 * @return - the attribute
	 */
	inline const String& 	attributeByIndex(int pos) const { return m_mAttributes.keyByIndex(pos); }
	
	/**
	 * @brief Retrieves reference to value of attribute
	 * @param attribute - the attribute to look for
	 * @return - the value of the attribute
	 */
	inline String& 	attributeValue(const String& sAttribute) const { 
		AssertTrue(this->hasAttribute(sAttribute), String("CXMLTree with label <") + label() + String("> has attribute: ") + sAttribute);
		return *(m_mAttributes.valuePtr(sAttribute)); 
	}
	
	/**
	 * @return the number of attributes in this
	 */
	inline int 		numAttributes() const { return m_mAttributes.size(); }
	
	/**
	 * @brief Adds an attribute-value pair to this
	 * @param sAttribute - the name of the new attribute
	 * @param sValue - the value of the new attribute
	 */
	inline void		addAttribute(const String& sAttribute, const String& sValue) { 
		AssertFalse(this->hasAttribute(sAttribute), String("CXMLTree with label <") + label() + String("> does already have attribute: ") + sAttribute);
		AssertFalse(this->isTag(),  String("CXMLTree with label <") + label() + String("> must be a tag to add attribute: ") + sAttribute);
		m_mAttributes.add(sAttribute, sValue); 
	}
	
	/**
	 * @brief Given a name of an attribute, removes it from this
	 * @param sAttribute - the attribute to remove
	 * @return - a copy of the value of attribute
	 */
	inline String  removeAttribute(const String& sAttribute) {
		AssertTrue(this->hasAttribute(sAttribute), String("CXMLTree with label <") + label() + String("> has attribute to remove: ") + sAttribute);
		return m_mAttributes.remove(sAttribute);
	}
	
	/**
	 * @return Whether or not the label of this is in </>
	 */
	inline bool 	isTag() const { return m_bIsTag; }
	
	void toString(String& dest, int iIndentLevel = 0);
};



#endif //CHEL_CXMLTREE_H