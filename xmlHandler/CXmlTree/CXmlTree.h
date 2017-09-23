#ifndef CHEL_CXMLTREE_H
#define CHEL_CXMLTREE_H

#include "../chelTypes/chelTypes.hpp"
#include "../SXml/SXml.h"

class CXmlTree : CTree<SXml> {
	
public:
	CXmlTree(String label, bool isTag = false);


	inline String 	label() const { return value().m_sLabel; }
	inline bool 	isTag() const { return value().m_bIsTag; }
	void			setIsTag(bool bIsTag);
	
	inline int 		numAttributes() const { return value().m_attributes.size(); }
	inline bool		hasAttribute(String attribute) { return value().m_attributes.hasKey(attribute); }
	String 			valueOf(String attribute) const;
	void			removeAttribute(String attribute);
};

#endif //CHEL_CXMLTREE_H