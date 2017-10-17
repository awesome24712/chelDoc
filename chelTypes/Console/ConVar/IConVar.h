#ifndef CHEL_ICONVAR_H
#define CHEL_ICONVAR_H

class IConVar {
protected:
	IConVar();
	
public:
	virtual const char* getName() 	const;

	virtual const char* getCStr() 	const;
	virtual int			getInt()	const;
	virtual bool		getBool()	const;
	virtual float		getFloat()	const;
	
	void setValue(const char* pszValue);
	void setValue(int iValue);
	void setValue(float flValue);
	
	static IConVar* find(const char* pszName);
};

#endif //CHEL_ICONVAR_H