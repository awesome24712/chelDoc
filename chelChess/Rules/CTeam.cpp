#include "CTeam.h"

LINK_CLASS_TO_NAME(CTeam, "team", "Playable Team")

void CTeam::init(ColorRGB teamColor, String teamName) {
	m_iTeamNumber = m_pFactory->productionCount() - 1;
	m_sInstanceVisualName = teamName;
}