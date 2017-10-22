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

void CWebGenerator::printFunction(CDocTree* pFunction){
	String& accessiibility = pVariable->asVariable.m_sAccessibility;
	String& parameter = pVariable->asVariable.m_sParameter;
	String m_sReturnType;
	bool m_bIsFirstClass;
	bool m_bCanOverride;
	bool m_sIsVirtual;
	//TO-DO use m_Writer to print.
}

void CWebGenerator::printParameter(CDocTree* pParameter, int numberOfColumns){
	//TO-DO use m_Writer to print.
}

void CWebGenerator::printNamespace(CDocTree* pNamespace){
	//To-Do use m_Writer to print.
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
	//TO-DO use m_Writer to print.
}