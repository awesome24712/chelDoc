#ifndef IInterp
#define IInterp

class IInterp {
private:
	String languageName;
	static CDynList<IInterp> g_lInterpreters;
public:
	IInterp(String& lanName) {
		languageName = lanName;
		g_lInterpreters.push(this);
	}
	const String& getLanguageName() { return languageName; }
	void setLanguageName(String lan) { languageName = lan; }
	//call incrementInterpreters in any constructor of interpreters
}


#endif //IInterp