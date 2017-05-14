#ifndef BITFIELD_H
#define BITFIELD_H

#include "../Lists/List_Templates.hpp"
#include "../Wrappers/Ptr.hpp"
#include "stdint.h"
struct BitFlag {
	friend class CBitField;
private:
	uint8_t x;
	uint8_t y;
	
public:
	BitFlag(short sFlagNum);
};

class CBitField {
private:
	Ptr<CList<uint8_t>> m_pField;
public:
	CBitField(short sSize);
	
	short size() const {return (*m_pField).length() * 8;}
	
	operator bool() const;
	
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
