#ifndef CHEL_CHESS_BOARDHANDLE
#define CHEL_CHESS_BOARDHANDLE

#include "../base/base.h"
#include "../Objects/CEnt.h"
#include "CChessBoard.h"

#define BOARDHANDLE_EMPTY_CHAR ' '

/**
 * @class CBoardHandle
 * @author Awesome
 * @date 28/06/2017
 * @file CBoardHandle.h
 * @brief Handles a simple character representation of a chess board.
 * 		A board handle is solely meant to assist in interpreting the state
 * 		of the board.
 * 		A global board handle exists, but its state is only reflective of
 * 			the actual CChessBoard created for the game.
 */
class CBoardHandle {
	CField<char> m_cField;
	
	CBoardHandle(const GNameList* pEntList);
	
	CBoardHandle(const CChessBoard* pChessBoard);
	
	//Applies a move to the temporary handle. Does not affect any externals.
	void applyMove(const CMoveInfo& info);
	
	/**
	 * @brief Builds the handle into a line-separated String
	 * @return the string
	 */
	inline String toString() const {
		String result(m_cField.size() + m_cField.height() + 1);
		for (int j = 0; j < m_cField.height(); j++) {
			int i;
			for (i = 0; i < m_cField.width(); i++) {
				//this formula accounts for the '\n' line separators
				result.set(j * m_cField.width() + j + i, m_cField.get(j, i));
			}
			result.set(j * m_cField.width() + j + i, '\n');
		}
		return result;
	}
	
	inline bool hasPieceAt(Coord2D pos) { return m_cField.get(pos.Y, pos.X) != BOARDHANDLE_EMPTY_CHAR; }
	
	inline void setPieceAt(Coord2D pos, char cPiece) { m_cField.set(pos.Y, pos.X, cPiece); }
	
	inline char getPieceAt(Coord2D pos) { return m_cField.get(pos.Y, pos.X); }
}

extern CBoardHandle* g_pBoardHandle;

#endif //CHEL_CHESS_BOARDHANDLE