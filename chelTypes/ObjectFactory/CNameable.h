#ifndef CHEL_NAMEABLE_H
#define CHEL_NAMEABLE_H

#include "../String/String.h"

class CNameable;

#define CLASS_ALIASES(base, derived) \
	typedef base BaseClass; \
	typedef derived ThisClass;

class CNameableFactory {
	friend class CNameable;
private:
	String m_sCPPClassName;		// CNameableFactory
	String m_sScriptClassName;	// object_factory
	String m_sVisualClassName;	// Object Factory
	
	//each factory also keeps track of its own production, 
	//CDynList<CNameable*> m_aProductions;
	
	int m_iProductionCount = 0;
public:
	//constructor adds the facotry to the global map of factories
	CNameableFactory(String cppClassName, String scriptClassName, String visualClassName);
	virtual CNameable* create();

	inline String nameClassCpp() const { return m_sCPPClassName; }
	inline String nameClassScript() const { return m_sScriptClassName; }
	inline String nameClassVisual() const { return m_sVisualClassName; }
	
	inline int productionCount() const { return m_iProductionCount; }
};

/**
 * @class CNameable
 * @author Chel
 * @date 21/06/2017
 * @file INameable.h
 * @brief Interface which provides handles for creating and finding specificly named instances
 * 		of a class.
 * 		Maintains string values for C++ these kinds of names:
 * 		C++ class name				-> INameable					CAK47
 * 			- displayed to programmers to assist with debugging
 * 		Underscored class name		-> nameable_item				weapon_ak
 * 			- shown to external script writers, level designers, etc.
 * 		Visual class name			-> Nameable Item				AK47
 * 			- shown to clients as a category or general name
 * 		Underscored instance name	-> nameable_item1				weapon_ak1
 * 			- so script writers etc. can identify specific instances of the type
 * 		Visual instance name		-> Special Magical Item			Chel's AK
 * 			- shown to clients when the instance has a special name
 * 
 * 		Accessing member variables of this class in a derived class' constructor
 * 			will not produce valid bahavior; override the post-constructor if such
 * 			information is necessary.
 */
class CNameable {
private:
	friend class CNameableFactory;
	friend class GNameList;
	//class names are static to the class, so save memory here
	//by maintaining reference to the single factory for this class which
	//contains the information
	CNameableFactory* m_pFactory;
	
	String m_sInstanceScriptName;
	String m_sInstanceVisualName;
	
	int m_iIndex;
	
protected:
	/**
	 * @brief This function is called immediately after construction from a factory
	 * 		and a pointer to the object is inserted into the global list.
	 * 		The default behavior of this is what gives the object its name,
	 * 		so make sure you call the base class' post construct too if you override
	 * 		this.
	 * 		entIndex() is a valid call to make
	 * @param pFactory - the factory that produce the object.
	 */
	virtual void postConstruct(CNameableFactory* pFactory);
	
public:
	
	/**
	 * @brief Destroys the object and removes it from the global
	 * 		CNameable/entity list
	 */
	void destroy();
	
	/**
	 * @brief Called when this object is destroyed by any means,
	 * 		before it is removed the the CNameable/entity list
	 * @param pDestroyer
	 */
	virtual void onDestroyed(CNameable* pDestroyer) {}

	/**
	 * @brief Returns the index of {this} inside the global CNameable/entity list
	 * @return - the index
	 */
	inline int entIndex() const { return m_iIndex; }
	
	/**
	 * @brief Name accessors expose all the different kinds of names to client
	 */
	inline String nameScript() const { return m_sInstanceScriptName; }
	inline String nameVisual() const { return m_sInstanceVisualName; }
	inline String nameClassVisual() const { return m_pFactory->nameClassVisual(); }
	inline String nameClassCpp() const { return m_pFactory->nameClassCpp(); }
	inline String nameClassScript() const { return m_pFactory->nameClassScript(); }
};

#endif //CHEL_NAMEABLE_H