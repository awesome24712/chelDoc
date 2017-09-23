#include "CStatTracker.h"

CStatTracker::CStatTracker(CEnt* pOwner) {
	m_pOwner = pOwner;
	reset();
}


void CStatTracker::reset() {
	m_iCaptures = 0;
	m_iDeaths = 0;
	m_iMoves = 0;
}

void CStatTracker::notifyMove(const CMoveInfo& info) {
	if (info.m_pMover == m_pOwner) {
		m_iMoves++;
		if (info.m_pCaptured) {
			m_iCaptures++;
		}
	} else if (info.m_pCaptured == m_pOwner) {
		m_iDeaths++;
	}
}