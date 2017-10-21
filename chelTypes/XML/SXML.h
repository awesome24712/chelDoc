#ifndef CHEL_SXML_H
#define CHEL_SXML_H

#include "../String/String.h"
#include "../Templates/Networks/CMap.hpp"
#include "../Templates/Networks/CTree.hpp"

//struct SXML;
//class CXMLTree;
//class CTree<SXML>;

/**
 * @class SXML
 * @author Chel
 * @date 19/10/2017
 * @file SXML.h
 * @brief Represents the values at a node of an CXMLTree. 
 */
/*struct SXML {
	friend class CXMLTree;
	friend class CTree<SXML>;
private:
	SXML(const String& _sLabel) : m_sLabel(_sLabel) {}
	String 					m_sLabel;
	CMap<String, String>	m_mAttributes;
	bool 					m_bIsTag; //whether or not our label is inside </>
public:
	
};*/

#endif //CHEL_SXML_H