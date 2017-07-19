#ifndef CHEL_STRINGCASE_H
#define CHEL_STRINGCASE_H

#include "../Templates/Fields/DBitfield.h"
#include "String.h"

//FCSC stands for "Flag for CStringCase"
BITFIELD_BEGIN()
	#define FCSC_REPLACE_SPACES 			1U << 0//replace spaces with underscores?
	#define FCSC_REMOVE_SPACES				1U << 1//overrides replace spaces
	
	#define FCSC_REPLACE_UNDERSCORES 		1U << 2//replace underscores with spaces? if both FCSC_REPLACE_SPACES and FCSC_REPLACE_UNDERSCORES are true, the first is applied
	#define FCSC_IGNORE_UNDERSCORE_PREFIXES 1U << 3//if set, then FCSC_REMOVE_UNDERSCORES will not remove underscores in the first three indexes
	#define FCSC_REMOVE_UNDERSCORES			1U << 4//overrides replace underscores
	
	#define FCSC_ADD_SPACES					1U << 5//i.e. CamelCase to spaces. Adds spaces between capital letters
													//only applied when no other space/underscore flags are active
	
	#define FCSC_FORCE_CASE 				1U << 7//force all letters to a certain case?
	#define FCSC_FORCE_CASE_IS_LOWERCASE	1U << 8//forced case is lower case?
	
	#define FCSC_CAPITALIZE_FIRST_LETTERS	1U << 9//applied before removing/changing/adding spaces. Applies to underscored and spaced words
	
	#define FCSC_REMOVE_LETTERS				1U << 10
	#define FCSC_REMOVE_NUMBERS				1U << 11
	#define FCSC_REMOVE_SYMBOLS				1U << 12 //removes anything that's not a letter or number
	
	#define FCSC_PREFIX_PREAPPLY			1U << 13 //if set, the prefix is applied before anything else. The prefix will be affected by all other settings
	#define FCSC_SUFFIX_PREAPPLY			1U << 14 //same as above
BITFIELD_END()

class CStringCase {
protected:
	unsigned int m_iFlags;
	String* m_pAppliedString; //so we don't have to pass it to private member functions
	
	String m_sBannedCharacters;
	String m_sBannedPrefixingCharacters;
	
	String m_sAppliedPrefix;
	String m_sAppliedSuffix;
	
	inline bool hasPrefix() { return m_sAppliedPrefix.length() > 0; }
	inline bool hasSuffix() { return m_sAppliedSuffix.length() > 0; }
	
	virtual bool applyPrefixTo(String& str) { return true; }
	virtual bool applySuffixTo(String& str) { return true; }
	
	//applies prefixes and suffixes no questions asked. Does not check for flags, do that elsewhere
	void applyPrefixesAndSuffixes();
	
	//checks flags to see if we're changing or removing spaces (does not check for adding them)
	bool isModifyingSpaces();
	
	//only call this if isModifyingSpaces() is false. Adds spaces before capital letters, excluding the first one
	//essential converts CamelCase into separate words.
	void addSpaces();
	
	
public:
	CStringCase(unsigned int flags);

	//For public knowledge of 
	inline unsigned int flags() { return m_iFlags; }
	inline bool has(unsigned int flag) { return m_iFlags & flag; }
	
	/**
	 * @brief Applies this CStringCase's settings to the given string
	 * @param str - the String to apply it to
	 */
	void apply(String& str);
};

#endif //CHEL_STRINGCASE_H
