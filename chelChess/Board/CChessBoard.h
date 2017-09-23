#ifndef CHEL_CHESSBOARD
#define CHEL_CHESSBOARD

#include "../Base/base.h"
#include "../Objects/CBasePiece.h"

class CChessBoard {
private:
	CField<CBasePiece*> m_fPieces;
	
public:
	CChessBoard(GNameList* pEntList);
	
	inline CBasePiece* pieceAt(Coord2D pos) const { return m_fPieces.get(pos.Y, pos.X); }
	inline bool hasPieceAt(Coord2D pos) const { return pieceAt(pos); }
	
	inline int height() const { return m_fPieces.height(); }
	inline int width() const { return m_fPieces.width(); }
};

#endif //CHEL_CHESSBOARD