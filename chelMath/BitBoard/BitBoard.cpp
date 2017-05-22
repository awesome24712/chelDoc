#include "BitBoard.h"

BitBoard::BitBoard(int height, int width) {
	m_iHeight = height;
	m_iWidth = width;
	m_iSize = width * height;
	
	m_pBoardRows = new uint8_t*[height];
	
}