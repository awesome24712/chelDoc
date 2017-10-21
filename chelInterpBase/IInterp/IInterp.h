#ifndef IInterp
#define IInterp

// extend this class for each Interpreter.
class IInterp {
private:
	String m_sLanguageName;
	static CDynList<IInterp> g_lInterpreters;
public:
	// Add itself to g_lInterpreters anytime a new Interpreter is created.
	IInterp(String& lanName) {
		m_LanguageName = lanName;
		g_lInterpreters.push(this);
	}
	// Every interpreter should have a language name.
	const String& getLanguageName() { return m_sLanguageName; }
	void setLanguageName(String lan) { m_sLanguageName = lan; }
}


#endif //IInterp