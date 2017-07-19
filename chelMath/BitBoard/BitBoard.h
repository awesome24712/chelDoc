#ifndef CHEL_BITBOARD_H
#define CHEL_BITBOARD_H

#include "stdint.h"
#include "../Coord/Coord2D.h"

struct BitBoard {
private:
	int m_iWidth;
	int m_iHeight;
	int m_iSize;
	
	uint8_t** m_pBoardRows;
	
public:
	BitBoard(int height, int width);
	
	bool get(Coord2D pos) const;
	void set(Coord2D pos, bool value);

	inline int	width() const { return m_iWidth; }
	inline int 	height() const { return m_iHeight; }
	inline int 	size() const { return m_iSize; }
	
	BitBoard operator &(const BitBoard& other);
	BitBoard operator |(const BitBoard& other);
	BitBoard& operator &=(const BitBoard& other);
	BitBoard& operator |=(const BitBoard& other);
};

#endif //ChEL_BITBOARD_H