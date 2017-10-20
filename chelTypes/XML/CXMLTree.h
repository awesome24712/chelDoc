#ifndef CHEL_CXMLTREE_H
#define CHEL_CXMLTREE_H

#include "SXml.h"
#include "../Templates/Networks/CTree.hpp"

/**
 * @class CXMLTree
 * @author Chel
 * @date 20/10/2017
 * @file CXMLTree.h
 * @brief CXMLTree models the XML format. It inherits all functionalities of CTree<SXML>
 * 		Use CXMLTreeHandle to declare a root before using CXMLTree.
 */
class CXMLTree : public CTree<SXML> {
	friend class CXMLTreeHandle;
private:
	/**
	 * @brief Constructor builds tree with given label
	 * @param _label
	 */
	CXMLTree(const String& _label) : CTree<SXML>(SXML(_label)) {}
	
	
	
public:
	
	/**
	 * @brief Returns reference to the label of this
	 * @return the label
	 */
	inline const String& 	label() const { return m_tValue.m_sLabel; }
	
	/**
	 * @brief Given the name of the attribute, returns whether or not
	 * 		this has that attribute.
	 * @param sAttribute - the attribute to look for
	 * @return whether or not it's there, duh
	 */
	inline bool 	hasAttribute(const String& sAttribute) const { return m_tValue.m_mAttributes.hasKey(sAttribute); }
	
	inline const String& 	attributeByIndex(int pos) const { return m_tValue.m_mAttributes.keyByIndex(pos); }
	
	/**
	 * @brief Retrieves reference to value of attribute
	 * @param attribute - the attribute to look for
	 * @return - the value of the attribute
	 */
	inline String& 	attributeValue(const String& sAttribute) const { 
		AssertTrue(this->hasAttribute(sAttribute), String("CXMLTree with label <") + label() + String("> has attribute: ") + sAttribute);
		return *(m_tValue.m_mAttributes.valuePtr(sAttribute)); 
	}
	
	/**
	 * @return the number of attributes in this
	 */
	inline int 		numAttributes() const { return m_tValue.m_mAttributes.size(); }
	
	/**
	 * @brief Adds an attribute-value pair to this
	 * @param sAttribute - the name of the new attribute
	 * @param sValue - the value of the new attribute
	 */
	inline void		addAttribute(const String& sAttribute, const String& sValue) { 
		AssertFalse(this->hasAttribute(sAttribute), String("CXMLTree with label <") + label() + String("> does already have attribute: ") + sAttribute);
		AssertFalse(this->isTag(),  String("CXMLTree with label <") + label() + String("> must be a tag to add attribute: ") + sAttribute);
		m_tValue.m_mAttributes.add(sAttribute, sValue); 
	}
	
	/**
	 * @brief Given a name of an attribute, removes it from this
	 * @param sAttribute - the attribute to remove
	 * @return - a copy of the value of attribute
	 */
	inline String  removeAttribute(const String& sAttribute) {
		AssertTrue(this->hasAttribute(sAttribute), String("CXMLTree with label <") + label() + String("> has attribute to remove: ") + sAttribute);
		return m_tValue.m_mAttributes.remove(sAttribute);
	}
	
	/**
	 * @return Whether or not the label of this is in </>
	 */
	inline bool 	isTag() const { return m_tValue.m_bIsTag; }
	
	void toString(String& dest, int iIndentLevel = 0);
};

/**
 * @class CXMLTreeHandle
 * @author Chel
 * @date 19/10/2017
 * @file CXMLTree.h
 * @brief An CXMLTree which handles the memory of itself and its children.
 * 		The value at this and all children are removed from heap
 * 			when all copies of this are destroyed.
 */
class CXMLTreeHandle : public CTreeHandle<SXML> {
	
	CXMLTreeHandle(const String& _sLabel) : CTreeHandle<SXML>(new CXMLTree(_sLabel)) { }
	
	CXMLTree& get() { return *(static_cast<CXMLTree*>((CTree<SXML>*)m_pNode)); }
	CXMLTree* getPtr() { return (static_cast<CXMLTree*>((CTree<SXML>*)m_pNode)); }
	
	operator CXMLTree*() const { return (static_cast<CXMLTree*>((CTree<SXML>*)m_pNode)); }
	operator CXMLTree&() const { return *(static_cast<CXMLTree*>((CTree<SXML>*)m_pNode)); } 
	CXMLTree* operator->() const { return (static_cast<CXMLTree*>((CTree<SXML>*)m_pNode)); }
	CXMLTree& operator*() const { return *(static_cast<CXMLTree*>((CTree<SXML>*)m_pNode)); }
	
};

#endif //CHEL_CXMLTREE_H