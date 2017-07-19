#ifndef CHEL_NAMELIST_H
#define CHEL_NAMELIST_H

#include "CNameable.h"
#include "../Templates/Lists/CDynList.hpp"
#include "../Templates/Networks/CMap.hpp"

/**
 * @class GNameList
 * @author Awesome
 * @date 26/06/2017
 * @file GNameList.h
 * @brief Organizes all nameable objects under a list of pointers to those objects.
 * 		This class contains basic functionality, it is recommended to extend this
 * 		class into your own engine/library
 */
class GNameList {
	friend class CNameableFactory;
	friend class CNameable;
public:
	CDynList<CNameable*> m_aList;
	
	//Key-value pairs of script names to their factories
	CMap<String, CNameableFactory*> m_factoryMap;
	
	/**
	 * @brief Inserts a given reference to an new heap-allocated object into
	 * 			the global list. It is inserted at the smallest empty index.
	 * 		This is used by CNameableFactory to insert an object into the list
	 * 			and then lets the object know of its own index.
	 * @param pObj - the object to insert
	 * @return - the index it was inserted at
	 */
	int insertAtEmptyIndex(CNameable* pObj, CNameableFactory* pFactory);
	
	
	/**
	 * @brief Given an index, calls the onDestoryed(...) of the to-be-destroyed object,
	 * 		and then deletes the object from memory and nullifies its pointer.
	 * @param index - the index of the object to destroy.
	 * @param pDestroyer - the other CNameable which is destroying the object
	 * @return - whether or not an object was destoryed. It will be false if there
	 * 		was not already an object at the index.
	 */
	bool destroyByIndex(int index, CNameable* pDestroyer);
	
	inline bool hasObjAtIndex(int index) const { return m_aList.get(index); }
	
	/**
	 * @brief 
	 * @param cppName
	 * @perfwarn - It is more effecient to use createByScriptName(...) because the script names are what
	 * 		are actually stored in the factory map. Using createByCppName(...) forces pointer access of
	 * 		each factory itself
	 * @return - a pointer to the newly created object.
	 */
	CNameable* createByCppName(String cppName);
	
	/**
	 * @brief Given the script name of a class derived from CNameable, creates a new heap-allocated
	 * 		object of that class.
	 * @param scriptName - the script name of the class.
	 * @return - a pointer to the object.
	 */
	CNameable* createByScriptName(String scriptName);
	
	/**
	 * @brief Given the script class name of a class, finds the first instance of the class in the global
	 * 		list or otherwise creates one
	 * @param scriptClassName - the script name of the singleton to look for
	 * @return - pointer to the singleton
	 */
	CNameable* createOrFindSingleton(String scriptClassName);
	
	inline int indexOf(CNameable* pObj) const { return m_aList.indexOf(pObj); }
	
	CNameable* findByScriptName(String scriptName) const;
	
	inline int size() const { return m_aList.length(); }
};

extern GNameList* g_pEntList;

/**
 * @class CTemplatedFactory - this is used via macros to bind a class
 * 		to names. Only one factory exists for each class.
 * 		Templated factories produce objects whose dynamic type
 * 		matches their template parameter.
 * @author Awesome
 * @date 27/06/2017
 * @file GNameList.h
 * @brief 
 */
template<class T>
class CTemplatedFactory : public CNameableFactory {
public:
	CTemplatedFactory(String cppClassName, String scriptClassName, String visualClassName) 
		: CNameableFactory(cppClassName, scriptClassName, visualClassName) {}
		
	virtual CNameable* create() override;
};

template<class T> CNameable* CTemplatedFactory<T>::create() {
	CNameable* pObj = new T;
	g_pEntList->insertAtEmptyIndex(pObj, this);
	return pObj;
}

/**
 * Use this macro to bind a class derived from CNameable to a set of names
 */
#define LINK_CLASS_TO_NAME(CppClassName, ScriptClassName, VisualClassName) \
	namespace ObjectFactory { \
		CTemplatedFactory<CppClassName> For##CppClassName(#CppClassName, ScriptClassName, VisualClassName); \
	}

#endif //CHEL_NAMELIST_H