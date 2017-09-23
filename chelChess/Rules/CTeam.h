#ifndef CHEL_CHESS_TEAM
#define CHEL_CHESS_TEAM

#include "../Objects/CEnt.h"

class CTeam : public CEnt {
	CLASS_ALIASES(CEnt, CTeam)
private:
	ColorRGB m_color;
	
	int m_iTeamNumber;
	int m_iMoney;
	
public:
	void init(ColorRGB teamColor, String teamName);
};

#endif //CHEL_CHESS_TEAM