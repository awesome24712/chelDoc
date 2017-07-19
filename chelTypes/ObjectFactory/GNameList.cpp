#include "GNameList.h"

int GNameList::insertAtEmptyIndex(CNameable* pObj, CNameableFactory* pFactory) {
	AssertTrue(pObj, "In GNameList::insertAtEmptyIndex , added pObj is non-null");
	int smallestEmpty = m_aList.indexOf(nullptr);
	
	//if we found an empty slot...
	if (smallestEmpty != -1)
		m_aList.set(smallestEmpty, pObj);
	//otherwise just push it on
	else {
		smallestEmpty = m_aList.length();
		m_aList.push(pObj);
	}
	
	//let the object know its own index
	pObj->m_iIndex = smallestEmpty;
	
	pObj->postConstruct(pFactory);
	
	return smallestEmpty;
}

bool GNameList::destroyByIndex(int index, CNameable* pDestroyer) {
	CNameable* pDestroyMe = m_aList.get(index);
	
	if (pDestroyMe) {
		pDestroyMe->onDestroyed(pDestroyer);
		delete pDestroyMe;
		m_aList.set(index, nullptr);
	}
	
	return pDestroyMe;
}

GNameList* g_pEntList = nullptr;

CNameable* GNameList::createByCppName(String cppName) {
	CNameable* 			pObj = nullptr;
	CNameableFactory* 	pFactory;
	
	for (int i = 0; i < m_factoryMap.size(); i++) {
		if (m_factoryMap.valueByIndex(i)->nameClassCpp() == cppName) {
			pFactory = m_factoryMap.valueByIndex(i);
			break;
		}
	}
	
	if (pFactory)
		pObj = pFactory->create();
	
	return pObj;
}

CNameable* GNameList::createByScriptName(String scriptName) {
	CNameable* pObj = nullptr;
	AssertTrue(m_factoryMap.hasKey(scriptName), "Class script name exists");
	
	return m_factoryMap.value(scriptName)->create();
}

CNameable* GNameList::createOrFindSingleton(String scriptClassName) {
	CNameable* pSingleton = nullptr;
	
	for (int i = 0; i < m_aList.length() && !pSingleton; i++) {
		CNameable* pObj = m_aList.get(i);
		if (pObj && pObj->nameClassScript() == scriptClassName)
			pSingleton = pObj;
	}
	
	if (!pSingleton)
		pSingleton = createByScriptName(scriptClassName);
	
	return pSingleton;
}

CNameable* GNameList::findByScriptName(String scriptName) const {
	CNameable* pObj;
	int i;
	for (i = 0; i < m_aList.length(); i++) {
		pObj = m_aList.get(i);
		if (pObj && pObj->nameScript() == scriptName) {
			break;
		}
	}
	//return null if we reached the end of the list without a match
	if (i == m_aList.length())
		pObj = nullptr;
		
	return pObj;
}
