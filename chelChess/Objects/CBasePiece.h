#ifndef CHEL_CHESS_BASEPIECE
#define CHEL_CHESS_BASEPIECE

#include "CEnt.h"
#include "StatTrack/CStatTracker.h"

class CBasePiece : public CEnt {
	CLASS_ALIASES(CEnt, CBasePiece)
protected:
	Coord2D m_cPos;
	CTeam* m_pTeam;
	
	uint16 m_iStaticValue;
	
	CStatTracker m_lifeStats;
	CStatTracker m_matchStats;
	CStatTracker m_roundStats;
	
public:
	CBasePiece();
	
	/**
	 * @brief Given a move, checks and does state changes for being captured
	 * 		or not captured, moving or not moving, etc.
	 * 		Also notifies stat trackers
	 * @param info - the move
	 */
	void notifyMove(const CMoveInfo& info);
	
	inline Coord2D pos() const { return m_cPos; }
	
	virtual bool isCaptureableBy(const CMoveInfo& proposedInfo) { return true; }
	virtual bool isMoveable() const;
	
	//For piece-specific event effects
	virtual void onMoved(const CMoveInfo& info) {}
	virtual void onCapture(const CMoveInfo& info) {}
	virtual void onCaptured(const CMoveInfo& info) {}
	
	virtual void onRoundStart();
	virtual void onMatchStart();
	
	//Inherited from CEnt
	virtual void itemPreMove(const CMoveInfo& info) 	override {}
	virtual void itemPostMove(const CMoveInfo& info) 	override {}
	virtual void onEnabled() 							override {}
	
protected:
	//Inherited from CNameable
	virtual void postConstruct(CNameableFactory* pFactory) override { BaseClass::postConstruct(pFactory); }
}

#if DEBUG
#define ToBasePiece(p) dynamic_cast<CBasePiece>(p)
#else
#define ToBasePiece(p) static_cast<CBasePiece>(p)
#endif

#endif //CHEL_CHESS_BASEPIECE