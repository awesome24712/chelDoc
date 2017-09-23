#include "CBasePiece.h"

LINK_CLASS_TO_NAME(CBasePiece, "piece_base", "Default Piece")

void CBasePiece::notifyMove(const CMoveInfo& info) {
	m_lifeStats.notifyMove(info);
	m_matchStats.notifyMove(info);
	m_roundStats.notifyMove(info);
	
	if (info.m_pMover == this) {
		m_cPos = info.m_cTo;
		onMoved(info);
		if (info.m_pCaptured) {
			onCapture(info);
		}
	} else if (info.m_pCaptured = this) {
		onCaptured(info);
		setEnabled(false);
	}
}

void CBasePiece::onRoundStart() {
	m_roundStats.reset();
}

void CBasePiece::onMatchStart() {
	m_roundStats.reset();
}