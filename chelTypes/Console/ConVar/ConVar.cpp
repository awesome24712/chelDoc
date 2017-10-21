#include "ConVar.h"
#include "../../Templates/Networks/HashMap/CHMap.hpp"
#include "../../Templates/Networks/HashMap/CHMap.hpp"

CHMap<String, ConVar*> g_mConVarDictionary(31);

ConVar::ConVar(const char* pszName, const char* pszDefaultValue) : m_sName(pszName), m_sValue(pszDefaultValue) {
	g_mConVarDictionary.add(m_sName, this);
}

ConVar* ConVar::findByName(const String& sName) {
	return g_mConVarDictionary.value(sName);
}

int ConVar::numConVars() { return g_mConVarDictionary.size(); }