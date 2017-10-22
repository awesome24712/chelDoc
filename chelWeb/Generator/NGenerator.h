#ifndef NGENERATOR
#define NGENERATOR
#include <fstream>

class CHTMLWriter;
class TreeViewer;

class CHTMLWriter{
	
private:
	CHTMLWriter(); //constructor declaration
	~CHTMLWriter(); //destructor declaration
	
	ofstream outfile;
	
	CHTMLWriter(outputFileName){
		outfile.open(outputFileName);
	}
	
	~CHTMLWriter(){
		outfile.close();
	}

	void createHeaders(const String& title);
	void createTable(CDynList<String>& headers);
	void createTableRows(CDynList<String>& cells);
	void closeTable(const String& tableFooter);
	void createFooter();
	void createLink(const String& link, const String& linkName);
	void encloseLink(const String& link, String& str);
	void printParagraph(const String& paragraph);
	void printPreParagraph(const String& PreParagraph);
}

class CWebGenerator{
	
	CHTMLWriter m_Writer;
	
	/**
	 * @brief 
	 * @param treeList - list of trees to process
	 * @param outputMap - map of CDocTree* to file output locations
	 * @param identifierMap - map of identifiers to output locations
	 */
	void mapOutputLocations(CDynList<CDocTree*>& treeList, CHMap<CDocTree* , String>& outputMap, CHMap<String , String>& identifierMap);
	
	void fullyQualifiedName(CDocTree* pTree, CDynList<String>& result);
	
	/**
	 * @brief 
	 * @param treeList - list of trees to process
	 * @param namespaceGrouping - map of partial namespace identifiers to a list of all identical partial namespace identifiers.
	 */
	void mapNamespaces(CDynList<CDocTree*>& treeList, CMap<CDocTree*, CDynList<CDocTree*>>& namespaceGrouping);
	
	CDynList<CDocTree*>* fullNamespaceDefinition(CDocTree*, CMap<CDocTree*, CDynList<CDocTree*>>& namespaceGrouping);
	
	/**
	 * Dispatches functions to generate HTML documentation
	 */ 
	void processJob(CDynList<CDocTree*>& treeList);
	
private:
	/**
	* prints HTML information about a function and creates a table of its parameters
	* @param pFunction
	*/
	void printFunction(CDocTree* pFunction);
	
	/**
	 * prints a row in a table describing the parameter
	 * @param pParameter
	 */
	void printParameter(CDocTree* pParameter, int numberOfColumns);
	
	/**
	 * @brief prints information about namespace and brief description of all of its members
	 * @param pNamespace
	 */
	void printNamespace(CDocTree* pNamespace);
	
	/**
	 * prints brief description of function
	 * @param pFunction
	 */
	void printFunctionBrief(CDocTree* pFunction);
	
	/**
	 * @brief prints information about the variable
	 * @param pVariable
	 */
	void printVariable(CDocTree* pVariable);
}


#endif NGENERATOR