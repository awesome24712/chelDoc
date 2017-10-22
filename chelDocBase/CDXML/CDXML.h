#ifndef CDXML
#define CDXML

#include <../chelTypes/chelTypes.hpp>



namespace NChelDoc{
	
	
	struct SFile{
		String m_sName;
		int m_iNumberOfLines;
		String m_sDateLastEdit;
		String m_sFileExtension;
		String m_sNameOfLanguage;
		int m_iNumberOfComments;
	};
	struct SNamespace{
		String m_sAccessibility;
		bool m_bInstantiable;
		String m_sName;
		String m_sScope;
		
	};
	struct SFunction{
		String m_sAccessibility;
		String m_sParameter;
		String m_sReturnType;
		bool m_bIsFirstClass;
		bool m_bCanOverride;
		bool m_sIsVirtual;
	};
	struct SVariable{
		String m_sAccessibility;
		String m_sType;
		bool m_bIsPointer;
		bool m_bOnHeap;
	};
	struct SParameter{
		String m_sAccessibility;
		String m_sType;
		String m_sName;
		String m_sDefaultVal;
		bool m_sIsConst;
		bool m_sIsVolatile;
	};
	enum EType{
		FILEDESC = 0,
		VARIABLE,
		FUNCTION,
		PARAMETER,
		NAMESPACE,
	};
	
	EType getETypeName(String sType);
	String& getStringName(EType eType);
	
	class CDocTree : public CXMLTree {
	private:
		
		Ptr<SFile> 		m_pFile;
		Ptr<SNamespace> m_pNamespace;
		Ptr<SFunction> 	m_pFunction;
		Ptr<SVariable> 	m_pVariable;
		Ptr<SParameter> m_pParameter;
		
		EType m_eType;
		String m_sOriginalDec;
		
	public:
		EType 			getEType()		{ return m_eType; }
		Ptr<SFile> 		asFile()		{ return m_pFile; }
		Ptr<SNamespace> asNamespace()	{ return m_pNamespace; }
		Ptr<SFunction>	asFunction()	{ return m_pFunction; }
		Ptr<SVariable>	asVariable()	{ return m_pVariable; }
		Ptr<SParameter> asParameter()	{ return m_pParameter; }
		String&			getName();
		
		CDocTree(Ptr<SFile> pFile) : CXMLTree("FILE") {
			m_pFile = pFile;
		}
		CDocTree(Ptr<SNamespace> pNamespace) : CXMLTree("NAMESPACE") {
			m_pNamespace = pNamespace;
		}
		CDocTree(Ptr<SFunction> pFunction) : CXMLTree("FUNCTION") {
			m_pFunction = pFunction;
		}
		CDocTree(Ptr<SParameter> pParameter) : CXMLTree("PARAMETER") {
			m_pParameter = pParameter;
		}
		CDocTree(Ptr<SVariable> pVariable) : CXMLTree("VARIABLE"){
			m_pVariable = pVariable;
		}
		
		const String& getOriginalDec() {  return m_sOriginalDec;  }
		
		

	};
	
	inline CDocTree* ToDoc(CXMLTree* pTree){ return static_cast<CDocTree*>(pTree);}
	
}


#endif //CDXML