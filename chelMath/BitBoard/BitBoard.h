#ifndef CHEL_BITBOARD_H
#define CHEL_BITBOARD_H

#include "stdint.h"

struct BitBoard {
private:
	const int m_iWidth;
	const int m_iHeight;
	const int m_iSize;
	
	uint8_t** m_pBoardRows;
	
public:
	BitBoard(int height, int width);

	inline int	width() const { return m_iWidth; }
	inline int 	height() const { return m_iHeight; }
	inline int 	size() const { return m_iSize; }
};

#endif //ChEL_BITBOARD_H