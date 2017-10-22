#include "NGenerator.h"

#include "../../chelDocBase/chelDocBase.h";
#include "../../chelTypes/chelTypes.hpp";
#include <filesystem>
namespace fs = std::filesystem;


void CWebGenerator::getRootDirectory(){
	wcstombs(directoryBuffer, fs::current_path().root_path().c_str(), 512);
	g_sRootNodeDirectory = directoryBuffer;
}
void CWebGenerator::mapOutputLocations(CDynList<CDocTree*>& treeList, CMap<CDocTree* , String>& outputMap, CMap<String , String>& identifierMap){
	for(int i = 0; i < treeList.length(); i++){
		mapOutputLocations(treelist.get(i), outputMap, identifierMap);
	}
}

//Given a CDocTree*, return the associated file path.
//i.e. "C://Users/Awesome/chelDoc/namespace_1/function_1/variable_1"
void filePathForNode(CDocTree* tree, String& filePath){
	//Assume the working directory is the root directory of the tree
	//From there, add the fullyQualifiedName of the path to node
	CDynList<String> result;
	fullyQualifiedName(tree, result);
	filePath = "";
	for(int i = 0; i < result.length(); i++) {
		filePath += result(i);
	}
	filePath.pushFront(g_sRootNodeDirectory);
}

void CWebGenerator::mapOutputLocations(CDocTree* tree, CMap<CDocTree*, String> & outputMap, CMap<CDynList<String>, String>& identifierMap){
	CDynList<String> name;
	fullyQualifiedName(tree, name);
	//If there's already a CDynList by this name, get the resulting string for the outputMap.
	if(identifierMap.hasKey(name)){
		CMap.add(tree, identifierMap.value(name));
		//If Key already exists, no need to add it to outputMap.
	} else {
		//otherwise, create a unique string label for the tree that corresponds to its fully qualified name.
		String nodePath;
		filePathForNode(tree, nodePath);
		identifierMap.add(name, nodePath);
		outputMap.add(tree, nodePath);
	}
	outputMap.add(tree, name);
	identifierMap.add(
	for(int i = 0; i < tree->numChildren(); i++){
		mapOutputLocations(tree.child(i), CMap<CDocTree*, String> & outputMap, CMap(String, String>& identifierMap);
	}
}

void CWebGenerator::fullyQualifiedName(CDocTree* pTree, CDynList<String>& result) {
	if(!pTree->parent()->asFile){
		fullyQualifiedName(pTree->parent);
		result += pTree->getName();
	}
}

bool namespacesEqual(CDocTree* a, CDocTree* b) {
	return a->asNamespace().m_sName == b->asNamespace().m_sName && (a->parent() == b->parent() || (ToDoc(a->parent())->asFile() && ToDoc(b->parent())->asFile()));
}
void CWebGenerator::mapNamespaces(CDynList<CDocTree*>& treeList, CMap<CDocTree*, CDynList<CDocTree*>>& namespaceGrouping) {
	for(int i = 0; i < treeList.length(); i++){
		mapNamespaces(treeList.get(i), namespaceGrouping);
	}
}

void CWebGenerator::mapNamespaces(CDocTree* tree, CMap<CDocTree*, CDynList<CDocTree*>>& namespaceGrouping){
	if(tree->asNamespace()){
		CDocTree* equalsTree = nullptr;
		for(int i = 0; i < namespaceGrouping->size(); i++){
			if(namespacesEqual(namespaceGrouping.keyByIndex(i), tree)) {
				equalsTree = namespaceGrouping.keyByIndex(i);
				break;
			}
		}
		if(equalsTree){
			namespaceGrouping.valuePtr(equalsTree)->add(tree);
			
		} else {
			CDynList<CDocTree*> grouping;
			grouping.push(this);
			namespaceGrouping.add(tree, grouping);
		}
		for(int i = 0; i < tree.numChildren(); i++){
			mapNamespaces(tree.child(i), namespaceGrouping);
		}
	}
}

CDynList<CDocTree*>* CWebGenerator::fullNamespaceDefinition(CDocTree*, CMap<CDocTree*, CDynList<CDocTree*>>& namespaceGrouping){
	CDocTree* equalsTree = nullptr;
	for(int i = 0; i < namespaceGrouping->size(); i++){
		if(namespacesEqual(namespaceGrouping.keyByIndex(i), tree)) {
			equalsTree = namespaceGrouping.keyByIndex(i);
			break;
		}
	}
	AssertTrue(equalsTree, "Namespace does not exist");
	return equalsTree;
}

void CWebGenerator::processJob(CDynList<CDocTree*>& treeList) {
	
}

//Create a file that contains the html output for this function.
//Call printParameter for each child that is a Parameter and
//	printVariable for each child that is a variable
void CWebGenerator::printFunction(CDocTree* pFunction){
	String& accessiibility = pFunction->asVariable.m_sAccessibility;
	String& parameter = pFunction->asVariable.m_sParameter;
	String& name = pFunction->asVariable.m_sName;
	String& returnType = pFunction->asVarialbe.m_sFunction;
	bool isFirstClass = pFunction->asVariable.m_sIsFirstClass;
	bool canOverride = pFunction->asVariable.m_sCannOverride;
	bool isVirtual = pFunction->asVariable.m_sIsVirtual;
	
	// Open a file to the relative path. This is temporary.
	String relativePath;
	fullyQualifiedName(pFunction, relativePath&);
	
	CHTMLWriter.open(relativePath);
	CHTMLWriter.createHeaders("Function" + pFunction->asFunction.getName());
	//TO-DO print Function attributes (accessibility, parameter, etc)
	
	//Print parameters
	if(numChildren() > 0){
		CDynList<String> headers; headers.add("Parameter"); headers.add("Accessibility"); headers.add("Type"); headers.add("Name");
			headers.add("Default Value"); headers.add("Is Constant"); headers.add("Is Volatile");
			CHTMLWriter.createTable(headers);
	}
	for(int i = 0; i < pFunction->numChildren(); i++){
		String type = pFunction.child(i)->getEType();
		if(type == "PARAMETER")
			printParameter(pFunction -> getChild(i));
	}
	CHTMLWriter.closeTable("Parameters");
	CHTMLWriter.createFooter();
	CHTMLWriter.close(relativePath);
}

void CWebGenerator::printParameter(CDocTree* pParameter){
	
	CDynList<String> pInfo; pInfo.add(pFunction->asVariable.m_sName); pInfo.add(pFunction->asVariable.m_sAccessibility); pInfo.add(pFunction->asVariable.m_sType);
				pInfo.add(pFunction->asVariable.m_sName); pInfo.add(pFunction->asVariable.m_sDefaultVal); pInfo.add(pFunction->asVariable.m_sIsConst); pInfo.add(pFunction->asVariable.m_sIsVolatile);
	CHTMLWriter.createTableRow(pInfo);
	
}

void CWebGenerator::printNamespace(CDocTree* pNamespace){
	String accessibility = pNamespace->asNamespace().m_accessibility;
	boolean isInstantiable = pNamespace->asNamespace().m_bisInstantiable;
	String name = pNamespace->asNamespace().m_sName;
	String scope = pNamespace->asNamespace().m_sScope;
	
	String relativePath;
	fullyQualifiedName(pNamespace, relativePath&);
	CHTMLWriter.open(relativePath);
	CHTMLWriter.createHeaders("Namespace");
	//TO-DO print Table with Namespace values
	
	// For each child, call the appropriate print method
	for(int i = 0; i < pNamespace.numChildren(); i++){
		switch (pNamespace.child(i).getEType){
			case FUNCTION : printFunctionBrief(pNamespace.child(i));
			case VARIABLE : printVariable(pNamespace.child(i));
			default NAMESPACE : printNamespace(pNamespace.child(i));
		}
	}
}

void CWebGenerator::printFunctionBrief(CDocTree* pFunction){
	String& accessiibility = pVariable->asVariable.m_sAccessibility;
	String& parameter = pVariable->asVariable.m_sParameter;
	//TO-DO use m_Writer to print.
}

void CWebGenerator::printVariable(CDocTree* pVariable){
	String& varType = pVariable->asVariable.m_sReturnType;
	String& accessibility = pVariable->asVariable.m_sAccessibility;
	bool isPointer = pVariable->asVariable.m_bIsPointer;
	bool isOnHeap = pVariable->asVariable.m_bIsOnHeap;
	
	//TO-DO
}