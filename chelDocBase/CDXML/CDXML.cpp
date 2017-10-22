#include <CDXML/CDXML.h>

namespace NChelDoc{
	
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