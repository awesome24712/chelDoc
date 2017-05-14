#include "CBitfield.h"

BitFlag::BitFlag(short sFlagNum) {
	x = sFlagNum / 8;
	y = sFlagNum % 8;
}

CBitField::CBitField(short sSize) {
	m_pField = new CList<uint8_t>(sSize / 8 + 1);
}

CBitField::operator bool() const {
	uint8_t curByte;
	bool bFound = false;
	for (int i = 0; !bFound && i < (*m_pField).length(); i++)
		bFound = (*m_pField).get(i);
	
	return bFound;
}

CBitField CBitField::operator &(const CBitField& other) {
	AssertTrue(this->size() == other.size(), "Equal length of CBitField operands");
	
}