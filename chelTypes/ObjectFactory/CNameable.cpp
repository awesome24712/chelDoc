#include "CNameable.h"
#include "GNameList.h"

CNameableFactory::CNameableFactory(String cppClassName, String scriptClassName, String visualClassName) {
	//check if we first need to build the global list
	if (!g_pEntList)
		g_pEntList = new GNameList;
		
	m_sCPPClassName = 		cppClassName;
	m_sScriptClassName = 	scriptClassName;
	m_sVisualClassName = 	visualClassName;
	
	//register ourself in the list's map
	g_pEntList->m_factoryMap.add(scriptClassName, this);
}

CNameable* CNameableFactory::create() {
	CNameable* pObj = new CNameable;
	g_pEntList->insertAtEmptyIndex(pObj, this);
	return pObj;
}

void CNameable::postConstruct(CNameableFactory* pFactory) {
	//for later reference
	m_pFactory = pFactory;
	
	//instance script name is the class' script name appended by the production count
	m_sInstanceScriptName = pFactory->m_sScriptClassName + String::fromInt(pFactory->productionCount());
	
	//default visual instance name is copied from the visual class name
	m_sInstanceVisualName = pFactory->m_sVisualClassName;
}

void CNameable::destroy() {
	g_pEntList->destroyByIndex(this->entIndex(), this);
}

