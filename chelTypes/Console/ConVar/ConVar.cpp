#include "ConVar.h"
#include "../../Templates/Networks/HashMap/CHMap.hpp"
#include "../../Templates/Networks/HashMap/CHMap.hpp"

CHMap<String, ConVar*> g_mConVarDictionary(31);

ConVar::ConVar(const char* pszName, const char* pszDefaultValue) : m_sName(pszName), m_sValue(pszDefaultValue) {
	printf("Beginning ConVar construction\n");
	g_mConVarDictionary.add(m_sName, this);
	printf("Finished ConVar construction\n");
}

ConVar::ConVar(const char* pszName, const char* pszDefaultValue, const char* pszToolTip) : m_sName(pszName), m_sValue(pszDefaultValue), m_sToolTip(pszToolTip) {
	printf("Beginning ConVar construction\n");
	g_mConVarDictionary.add(m_sName, this);
	printf("Finished ConVar construction\n");
}

ConVar* ConVar::findByName(const String& sName) {
	return g_mConVarDictionary.value(sName);
}

bool ConVar::exists(const String& sName){
	return g_mConVarDictionary.hasKey(sName);
}

int ConVar::numConVars() { return g_mConVarDictionary.size(); }