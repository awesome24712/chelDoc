#ifndef CHEL_CHESS_MOVE
#define CHEL_CHESS_MOVE
#include "../Base/base.h"

/**
 * @class CSingleMove
 * @author Awesome
 * @date 10/07/2017
 * @file CSingleMove.h
 * @brief Stores a single move via a coordinate displacement
 * 		along with several boolean flags.
 * 		Each type of move is created as a singleton which is then referenced by all piece
 * 			classes.
 */
class CSingleMove : public CNameable {
	CLASS_ALIASES(CNameable, CSingleMove)
protected:
	Coord2D m_displacement;
	uint8 m_iMaxTravelDist = 255;
	uint32 m_flags;
	
#define FL_MOVE_LEAPING 	1U << 0 //Can this move jump over other pieces?
#define FL_MOVE_FLIP_X		1U << 1 //switch signs of displacement coordinates when calculating moves?
#define FL_MOVE_FLIP_Y		1U << 2
#define FL_MOVE_INVERTED	1U << 3 //switch X and Y coordinates when calculating moves?
#define FL_MOVE_ALLDIRECT	(FL_MOVE_FLIP_X | FL_MOVE_FLIP_Y | FL_MOVE_INVERTED)

#define FL_MOVE_CAPTUREONLY	1U << 4 //only allow this move when it captures a piece?
#define FL_MOVE_MOVEONLY	1U << 5 //only allow this move when it DOESN"T capture a piece?

#define FL_MOVE_BIGMOVE 	1U << 6 //only allow this move if the piece hasn't already moved?
#define FL_MOVE_PASSANT		1U << 7 //does this move create en-passant squares?

	CDynList<Coord2D> m_aDisps;
	
	void buildCoordList();
	virtual void postConstruct(CNameableFactory* pFactory) override;
	
public:
	inline Coord2D disp() const { return m_displacement; }
	inline CDynList<Coord2D>* dispList() const { return &m_aDisps; }
	
	inline uint32 flags() const { return m_flags; }
	
	inline uint8 maxDist() const { return m_iMaxTravelDist; }
	
	inline bool isLeaping() 	const { return m_flags & FL_MOVE_LEAPING; }
	inline bool isFlipX() 		const { return m_flags & FL_MOVE_FLIP_X; }
	inline bool isFlipY()		const { return m_flags & FL_MOVE_FLIP_Y; }
	inline bool isInverted() 	const { return m_flags & FL_MOVE_INVERTED;}
	
	inline bool isCaptureOnly() const { return m_flags & FL_MOVE_CAPTUREONLY; }
	inline bool isMoveOnly() 	const { return m_flags & FL_MOVE_MOVEONLY; }
	
	inline bool isBigMove() 	const { return m_flags & FL_MOVE_BIGMOVE; }
	inline bool isPassant() 	const { return m_flags & FL_MOVE_PASSANT; }
};

/*
ALL SCRIPT NAMES OF THE MOVES IN ONE PLACE FOR EASY LOOK-UP
*/

#define MV_CLASSIC_PAWN_FWD "move_pawn_classic_fwd"
#define MV_CLASSIC_PAWN_CAP	"move_pawn_classic_cap"
#define MV_CLASSIC_PAWN_BIG "move_pawn_classic_big"

#define MV_BEROLINA_FWD		"move_pawn_berolina_fwd"
#define MV_BEROLINA_CAP		"move_pawn_berolina_cap"
#define MV_BEROLINA_BIG		"move_pawn_berolina_big"

#define MV_WAZIR			"move_pawn_wazir"
#define MV_FERZ				"move_pawn_ferz"
#define MV_HALF				"move_pawn_half"
//#define MV_SARISSA			"move_pawn_sarissa" //combo of MV_CLASSIC_PAWN_CAP and MV_HALF
//#define MV_MANN				"move_pawn_mann" //"King" movement //combination of wazir and ferz

#define MV_ALFIL			"move_leap_alfil"
#define MV_DABABBA			"move_leap_dababba"
#define MV_CAMEL			"move_leap_camel"
#define MV_KNIGHT			"move_leap_knight"
//#define MV_KIRIN			"move_leap_kirin" //separate definition not necessary or practical - moves as Ferz/Dabbaba

#define MV_BISHOP			"move_ray_bishop"
#define MV_ROOK				"move_ray_rook"

#endif //CHEL_CHESS_MOVE