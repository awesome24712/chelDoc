#include "CBitfield.h"

BitFlag::BitFlag(short sFlagNum) {
	x = sFlagNum / 8;
	y = sFlagNum % 8;
}

CBitField::CBitField(short sSize) {
	m_pField = CList<uint8_t>(sSize / 8 + 1);
}

CBitField::CBitField(const CBitField& other) {
	m_pField = Clist<uint8_t>(other.size());
	for (int i = 0; i < m_pField.length(); i++)
		*(m_pField.getPtr(i)) = (other.m_pField).get(i);
}

CBitField::operator bool() const {
	uint8_t curByte;
	bool bFound = false;
	for (int i = 0; !bFound && i < m_pField.length(); i++)
		bFound = (m_pField).get(i);
	
	return bFound;
}

bool CBitField::has(const BitFlag& flag) const {
	return m_pField.get(flag.x) & flag.y;
}

CBitField CBitField::operator &(const CBitField& other) {
	AssertTrue(this->size() == other.size(), "Equal length of CBitField operands");
	
	CBitField result(this->size());
	
	for (int i = 0; i < m_pField.length(); i++)
		*result.m_pField.getPtr(i) = this->m_pField.get(i) & (other.m_pField).get(i);
		
	return result;
}

CBitField CBitField::operator |(const CBitField& other) {
	AssertTrue(this->size() == other.size(), "Equal length of CBitField operands");
	
	CBitField result(this->size());
	
	for (int i = 0; i < m_pField.length(); i++)
		*result.m_pField.getPtr(i) = this->m_pField.get(i) | other.m_pField.get(i);
		
	return result;
}

CBitField& CBitField::operator &=(const CBitField& other) {
	AssertTrue(this->size() == other.size(), "Equal length of CBitField operands");
	
	for (int i = 0; i < m_pField.length(); i++)
		*m_pField.getPtr(i) &= other.m_pField.get(i);
		
	return *this;
}

CBitField& CBitField::operator |=(const CBitField& other) {
	AssertTrue(this->size() == other.size(), "Equal length of CBitField operands");
	
	for (int i = 0; i < m_pField.length(); i++)
		*m_pField.getPtr(i) |= other.m_pField.get(i);
		
	return *this;
}

CBitField CBitField::operator ~() {
	CBitField result(this->size());
	
	for (int i = 0; i < m_pField.length(); i++)
		*result.m_pField.getPtr(i) = ~result.m_pField.get(i);
		
	return result;
}

CBitField CBitField::operator &(const BitFlag& flag) {
	CBitField result(*this);
	
	*result.m_pField.getPtr(flag.x)) &= flag.y; 
	
	return result;
}

CBitField CBitField::operator |(const BitFlag& flag) {
	CBitField result(*this);
	
	*result.m_pField.getPtr(flag.x)) |= flag.y; 
	
	return result;
}

CBitField& CBitField::operator &=(const BitFlag& flag) {
	*m_pField.getPtr(flag.x) &= flag.y; 
	
	return result;
}

CBitField& CBitField::operator |=(const BitFlag& flag) {
	*m_pField.getPtr(flag.x) |= flag.y; 
	
	return result;
}



