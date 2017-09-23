#ifndef CHEL_CHESS_STATTRACKER
#define CHEL_CHESS_STATTRACKER

#include "../Base/base.h"
#include "../CEnt.h"

class CStatTracker {
private:
	uint32 		m_iMoves;
	uint32 		m_iCaptures;
	uint32 		m_iDeaths;
	CEnt* 		m_pOwner;
public:
	CStatTracker(CEnt* pOwner);
	void reset();
	void notifyMove(const CMoveInfo& info);
	
	inline uint32 moves() const { return m_iMoves; }
	inline uint32 captures() const { return m_iCaptures; }
	inline uint32 deaths() const { return m_iDeaths; }
	inline CEnt* owner() const { return m_pOwner; }
};

#endif //CHEL_CHESS_STATTRACKER