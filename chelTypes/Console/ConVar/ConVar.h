#ifndef CHEL_CONVAR_H
#define CHEL_CONVAR_H

#include "String/String.h"

class ConVar {
protected:
	const String 	m_sName;
	String 			m_sValue;
	const String	m_sToolTip
	int				m_iFlags;
	
public:
	ConVar(const char* pszName, const char* pszDefaultValue);


	const String* 	getName() 	const { return &m_sName; }
	const String* 	getToolTip	const { return &m_sName; }
	int				getFlags() 	const { return m_iFlags; }

	const char* getCStr() 	const { return (char*) m_sValue; }
	String*		getStrPtr() { return &m_sValue; }
	int			getInt()	const { return atoi(m_sValue); }
	bool		getBool()	const { return !!getInt();  }
	float		getFloat()	const { return strtof(m_sValue, nullptr); };
	
	void setValue(const char* pszValue);
	void setValue(int iValue);
	void setValue(float flValue);
	
	static ConVar* 	findByName(const String& sName);
	static int 		numConVars();
};

#endif //CHEL_CONVAR_H