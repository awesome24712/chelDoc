#ifndef CHEL_TEST_CASE
#define CHEL_TEST_CASE

#include "../chelTypes/chelTypes.hpp"
#include "../chelMath/chelMath.hpp"

class CTestPlan;
class CTestCase;

class CTestCase {
	friend class CTestPlan;
private:
	double 				m_dRunTime = 0.0; //assigned from the outside
	bool				m_bPassed = true; //only if all assertions pass
	bool				m_bException; //did we catch an exception?
	String				m_sExceptionMsg; //exception message
	const char*			m_pszName;
	CDynList<String>	m_aErrorList;
protected:
	template<class T> void assert_imp(const T& t1, const T& t2, const char* pszT1, const char* pszT2) {
		if (!(t1 == t2)) {
			m_bPassed = false;
			m_aErrorList.push(String() + "Assertion: (" + String(pszT1) + " == " + String(pszT2) + ") failed!");
		}
	}
#define assertEquals(t1, t2) 	assert_imp((t1), (t2), #t1, #t2)
#define assertTrue(t1)			assert_imp((t1), true, #t1, "true")
#define assertFalse(t1)			assert_imp((t1), false, #t1, "false")
	
public:
	CTestCase(const char* pszName);
	
	virtual void	runTest() = 0;
	inline 	bool	passed() const { return m_bPassed; }
	inline const char* name() const { return m_pszName; }
};

#define TEST(name) \
	class CTest_##name : public CTestCase { \
	public: \
		void runTest() override; \
		CTest_##name(const char* pszName) : CTestCase(pszName) {} \
	}; \
	CTest_##name test_##name(#name); \
	void CTest_##name::runTest()

class CTestPlan {
	friend class CTestCase;
private:
	CDynList<CTestCase*> 	m_aTestCases;
	bool					m_bPassed;
	String					m_sName;
	int						m_iErrorCount;
	
public:
	CTestPlan(const char* pszName);
	void					runTestPlan();
	
	static void				RunAll();
};

#endif //CHEL_TEST_CASE