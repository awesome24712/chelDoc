#include "CXmlTree.h"

CXmlTree::CXmlTree(String label, bool isTag) {
	SXml xmlInfo(label, isTag);
	m_pNode = new CTreeNode<SXml>(xmlInfo);
}

void CXmlTree::setIsTag(bool bIsTag) {
	valuePtr()->m_bIsTag = bIsTag;
	
	//non-tag nodes can't have attributes, so flush them
	if (!bIsTag)
		valuePtr()->m_attributes.flush();
}