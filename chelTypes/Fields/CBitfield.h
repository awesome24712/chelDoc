#ifndef BITFIELD_H
#define BITFIELD_H

#include "../Templates/Lists/List_Templates.hpp"
#include "../Templates/Wrappers/Ptr.hpp"
#include "stdint.h"

/**
 * @class BitFlag
 * @author Awesome
 * @date 28/05/2017
 * @file CBitfield.h
 * @brief Abstracts a bitflag for use with CBitField
 */
struct BitFlag {
	friend class CBitField;
private:
	uint8_t x;
	uint8_t y;
	
public:
	/**
	 * Builds a BitFlag with a unique identifier number
	 * Bitflags are usually declared in namespace scope
	 * @param sFlagNum - the position of the bit for this bitflag
	 * 		In a list of BitFlags, these numbers generally start at
	 * 		0 and increase.
	 * @requires - the BitFlag not be used with {CBitField}s or {BitFlag}s where
	 * 		{sFlagNum} is equal the number of bits in the field/flag
	 */
	BitFlag(short sFlagNum);
};

/**
 * @class CBitField
 * @author Awesome
 * @date 28/05/2017
 * @file CBitfield.h
 * @brief Abstracts a bitfield of a staticly-sized arbitrary list of bits
 * 		Provides basic bitwise operators for working with {BitFlag}s and
 * 			other {CBitField}s.
 * 		Allows for implicit conversion to bool, but the has(...) function
 * 			is a more efficient way to check for individual flags
 * 		Passing by value performs deep copy so you should pass by reference
 * 			when applicable
 */
class CBitField {
private:
	CList<uint8_t>* m_pField;
public:
	/**
	 * Builds a zero-value {CBitField} of the given size
	 */
	CBitField(short sSize);
	
	/**
	 * Copy constructor performs deep copy
	 * TODO is this function even necessary?
	 */
	CBitField(const CBitField& other);
	
	/**
	 * @brief Returns the number of bits allocated for the bitfield
	 * @return - the number of bits first allocated by constructor,
	 * 		rounded up to the nearest multiple of 8
	 * TODO store this in a variable? Store intended number of bits too?
	 */
	short size() const {return m_pField->length() * 8;}
	
	/**
	 * @brief Checks if any bit in the field is a 1
	 * @return 
	 */
	operator bool() const;
	
	bool has (const BitFlag& flag) const;
	
	CBitField operator&(const CBitField& other);
	CBitField operator|(const CBitField& other);
	CBitField& operator&=(const CBitField& other);
	CBitField& operator|=(const CBitField& other);
	
	CBitField operator~();
	
	CBitField operator&(const BitFlag& flag);
	CBitField operator|(const BitFlag& flag);
	CBitField& operator&=(const BitFlag& flag);
	CBitField& operator|=(const BitFlag& flag);
};
#endif //BITFIELD_H
