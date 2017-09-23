#include "CSingleMove.h"

void CSingleMove::buildCoordList() {
	//first push on the default displacement
	m_aDisps.push(m_displacement);
	
	//now check flags
	if (isFlipX()) {
		Coord2D flipped = m_aDisps.front();
		flipped.X = -flipped.X;
		m_aDisps.push(flipped);
	}
	if (isFlipY()) {
		int origLen = m_aDisps.length();
		for (int i = 0; i < origLen; i++) {
			Coord2D flipped = m_aDisps.get(i);
			flipped.Y = -flipped.Y;
			m_aDisps.push(flipped);
		}
	}
	if (isInverted()) {
		int origLen = m_aDisps.length();
		for (int i = 0; i < origLen; i++) {
			Coord2D inverted = m_aDisps.get(i);
			int tmp = inverted.X;
			inverted.X = inverted.Y;
			inverted.Y = tmp;
			m_aDisps.push(inverted);
		}
	}
}

void CSingleMove::postConstruct(CNameableFactory* pFactory) {
	BaseClass::postConstruct(pFactory);
	buildCoordList();
}

#define DEF_MOVE(className, moveName) \
	class className : public CSingleMove { \
		className(); \
	}; \
	LINK_CLASS_TO_NAME(className, moveName, moveName) \
	className::className()

/**
 * CLASSIC PAWN - moveset is split into different single moves!
 */
DEF_MOVE(CMoveClassicPawn_Fwd, MV_CLASSIC_PAWN_FWD) {
	m_displacement = Coord2D(0,1);
	m_flags |= FL_MOVE_MOVEONLY;
	m_flags |= FL_MOVE_LEAPING;
}

DEF_MOVE(CMoveClassicPawn_Cap, MV_CLASSIC_PAWN_CAP) {
	m_displacement = Coord2D(1,1);
	m_flags |= FL_MOVE_FLIP_X;
	m_flags |= FL_MOVE_LEAPING;
	m_flags |= FL_MOVE_CAPTUREONLY;
}

DEF_MOVE(CMoveClassicPawn_Big, MV_CLASSIC_PAWN_BIG) {
	m_displacement = Coord2D(0, 1);
	m_flags |= FL_MOVE_MOVEONLY;
	m_flags |= FL_MOVE_BIGMOVE;
	m_flags |= FL_MOVE_PASSANT;
	
	m_iMaxTravelDist = 2;
}

/**
 * BEROLINA PAWN - moveset is split into different moves!
 */
DEF_MOVE(CMoveBerolina_Fwd, MV_BEROLINA_FWD) {
	m_displacement = Coord2D(1,1);
	m_flags |= FL_MOVE_MOVEONLY;
	m_flags |= FL_MOVE_FLIP_X;
	m_flags |= FL_MOVE_LEAPING;
	
	m_iMaxTravelDist = 2;
}

DEF_MOVE(CMoveBerolina_Cap, MV_BEROLINA_CAP) {
	m_displacement = Coord2D(0,1);
	m_flags |= FL_MOVE_CAPTUREONLY;
	m_flags |= FL_MOVE_LEAPING;
}

DEF_MOVE(CMoveBerolina_Big, MV_BEROLINA_BIG) {
	m_displacement = Coord2D(2,2);
	m_flags |= FL_MOVE_MOVEONLY;
	m_flags |= FL_MOVE_FLIP_X;
	m_flags |= FL_MOVE_BIGMOVE;
	m_flags |= FL_MOVE_PASSANT;
	
	m_iMaxTravelDist = 2;
}

/**
 * WAZIR - moves one square orthogonally in any direction
 */
 DEF_MOVE(CMoveWazir, MV_WAZIR) {
	m_displacement = Coord2D(0,1);
	m_flags |= FL_MOVE_LEAPING;
	m_flags |= FL_MOVE_ALLDIRECT;
 }
 
 /**
 * FERZ - moves one square diagonally in any direction
 */
 DEF_MOVE(CMoveFerz, MV_FERZ) {
	 m_displacement = Coord2D(1,1);
	 m_flags |= FL_MOVE_LEAPING;
	 m_flags |= FL_MOVE_ALLDIRECT;
 }
 
 /**
 * HALF-PAWN - moves and captures forward
 */
 DEF_MOVE(CMoveHalf, MV_HALF) {
	 m_displacement = Coord2D(0,1);
	 m_flags |= FL_MOVE_LEAPING;
 }
 
 /**
 * ALFIL - moves two spaces diagonally in any direction, leaping
 */
 DEF_MOVE(CMoveAlfil, MV_ALFIL) {
	 m_displacement = Coord2D(2,2);
	 m_flags |= FL_MOVE_LEAPING;
	 m_flags |= FL_MOVE_ALLDIRECT;
 }
 
 /**
 * DABABBA - moves two spaces orthogonally in any direction, leaping
 */
  DEF_MOVE(CMoveDababba, MV_DABABBA) {
	 m_displacement = Coord2D(0,2);
	 m_flags |= FL_MOVE_LEAPING;
	 m_flags |= FL_MOVE_ALLDIRECT;
 }
 
 /**
 * CAMEL - moves as a (1,3) leaper
 */
 DEF_MOVE(CMoveCamel, MV_CAMEL) {
	 m_displacement = Coord2D(1,3);
	 m_flags |= FL_MOVE_LEAPING;
	 m_flags |= FL_MOVE_ALLDIRECT;
 }
 
 /**
 * KNIGHT - as long as you have a knight never give up
 */
 DEF_MOVE(CMoveKnight, MV_KNIGHT) {
	 m_displacement = Coord2D(1,2);
	 m_flags |= FL_MOVE_LEAPING;
	 m_flags |= FL_MOVE_ALLDIRECT;
 }
 
 /**
 * BISHOP - the one with the funny hat
 */
 DEF_MOVE(CMoveBishop, MV_BISHOP) {
	 m_displacement = Coord2D(1,1);
	 m_flags |= FL_MOVE_ALLDIRECT;
	 m_flags |= FL_MOVE_PASSANT;
 }
 
 /**
 * ROOK - the fortress no?
 */
 DEF_MOVE(CMoveRook, MV_ROOK) {
	 m_displacement = Coord2D(1,1);
	 m_flags |= FL_MOVE_ALLDIRECT;
	 m_flags |= FL_MOVE_PASSANT;
 }
 
 /**
 * 
 */

