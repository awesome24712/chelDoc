#include "CChessBoard.h"

CChessBoard::CChessBoard(GNameList* pEntList) {
	AssertTrue(pEntList, "CBoardHandle::CBoardHandle(GNameList*) - list is non-null");
	
	//Iterates through it once to build an array of pieces and find the max coordinates
	int xMax = 0;
	int yMax = 0;
	int len = pEntList->size();
	CDynList<CBasePiece*> piecePtrList(len);
	
	for (int i = 0; i < len; i++) {
		CBasePiece* pPiece = dynamic_cast<CBasePiece*> pEntList->m_aList.get(i);
		if (pPiece) {
			piecePtrList.push(pPiece);
			Coord2D pos = pPiece->pos();
			if (pos.X > xMax) xMax = pos.X;
			if (pos.Y > yMax) yMax = pos.Y;
		}
	}
	
	//now create the field to the correct size and fill it
	m_cField = CField<CBasePiece*>(yMax, xMax, nullptr);
	
	for (int i = 0; i < piecePtrList.length(); i++) {
		Coord2D curCoord = piecePtrList.get(i)->pos();
		m_cField.set(curCoord.Y, curCoord.X, piecePtrList.get(i));
	}
}