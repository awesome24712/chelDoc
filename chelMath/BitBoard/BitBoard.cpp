#include "BitBoard.h"

BitBoard::BitBoard(int height, int width) {
	m_iHeight = height;
	m_iWidth = width;
	m_iSize = width * height;
	
	m_pBoardRows = new uint8_t*[height];
	
	for (int i = 0; i < height; i++)
		m_pBoardRows[i] = new uint8_t[width];
}

bool BitBoard::get(Coord2D pos) const {
	return m_pBoardRows[pos.Y][pos.X];
}

void BitBoard::set(Coord2D pos, bool value) {
	m_pBoardRows[pos.Y][pos.X] = value;
}

BitBoard BitBoard::operator ~() {
	BitBoard result(m_iHeight, m_iWidth);
	Coord2D pos;
	for (pos.Y = 0; pos.Y < height(); pos.Y++)
		for (pos.X = 0; pos.X < width(); pos.X++)
			result.set(pos, !this->get(pos));
	return result;
}

BitBoard BitBoard::operator &(const BitBoard& other) {
	//AssertTrue(other.width() == this->width() && other.height() == this->height(), "BitBoard operands are of equal size in operator &");
	BitBoard result(m_iHeight, m_iWidth);
	Coord2D pos;
	for (pos.Y = 0; pos.Y < height(); pos.Y++)
		for (pos.X = 0; pos.X < width(); pos.X++)
			result.set(pos, this->get(pos) && other.get(pos));
			
	return result;
}

BitBoard BitBoard::operator |(const BitBoard& other) {
	//AssertTrue(other.width() == this->width() && other.height() == this->height(), "BitBoard operands are of equal size in operator |");
	BitBoard result(m_iHeight, m_iWidth);
	Coord2D pos;
	for (pos.Y = 0; pos.Y < height(); pos.Y++)
		for (pos.X = 0; pos.X < width(); pos.X++)
			result.set(pos, this->get(pos) || other.get(pos));
			
	return result;
}

BitBoard& BitBoard::operator &=(const BitBoard& other) {
	//AssertTrue(other.width() == this->width() && other.height() == this->height(), "BitBoard operands are of equal size in operator &=");
	Coord2D pos;
	for (pos.Y = 0; pos.Y < height(); pos.Y++)
		for (pos.X = 0; pos.X < width(); pos.X++)
			this->set(pos, this->get(pos) && other.get(pos));
	
	return *this;
}

BitBoard& BitBoard::operator |=(const BitBoard& other) {
	//AssertTrue(other.width() == this->width() && other.height() == this->height(), "BitBoard operands are of equal size in operator |=");
	Coord2D pos;
	for (pos.Y = 0; pos.Y < height(); pos.Y++)
		for (pos.X = 0; pos.X < width(); pos.X++)
			this->set(pos, this->get(pos) || other.get(pos));
	
	return *this;
}