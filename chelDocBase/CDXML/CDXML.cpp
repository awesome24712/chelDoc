#include <CDXML/CDXML.h>

namespace NChelDoc{
	
	String& CDXML::getStringName(){
		switch(m_eType) {
			case FILEDESC: return m_pFile->m_sName;
			case VARIABLE: return m_pVariable->m_sName;
			case NAMESPACE: return m_pNamespace->m_sName;
			case FUNCTION: return m_pFunction->m_sName;
			default : return m_pParameter->m_sName;
		}
	}
	
	String g_aEnumTable[5] = {
		"FILEDESC", 
		"VARIABLE",
		"FUNCTION",
		"PARAMETER",
		"NAMESPACE"
	};
	
	EType getETypeName(String sType){
		
		#define check(a) \
		if(sType==g_aEnumTable[a]){ \
			return a; \
		}
		
		check(FILEDESC)
		check(VARIABLE)
		check(FUNCTION)
		check(PARAMETER)
		return FILEDESC;
		#undef check
	}
	
	String& getStringName(EType eType){
		return g_aEnumTable[eType];
	}
}