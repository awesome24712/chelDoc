#ifndef CHEL_SXML_H
#define CHEL_SXML_H

#include "../chelTypes/chelTypes.hpp"

/**
 * @struct SXml
 * @author Awesome
 * @date 27/05/2017
 * @file SXml.h
 * @brief Wrapper class which contains by-value information for a single node
 * 		in a Xml structure.
 */
struct SXml {
	friend class CXmlTree;
private:
	//Label of an Xml node is what's inside the </>, identifies the node
	String 	m_sLabel;
	
	//whether or not this contained in </>, otherwise is a raw string
	bool 	m_bIsTag;
	
	//each attribute has a name and a value
	CMap<String, String> m_attributes;
	
	//private default contructor prevents instantiation
	SXml() {}
	
	SXml(String label, bool isTag = true);
};

#endif //CHEL_SXML_H