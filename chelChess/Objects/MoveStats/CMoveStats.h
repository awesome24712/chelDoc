#ifndef CHEL_CHESS_MOVESTATS
#define CHEL_CHESS_MOVESTATS

class CMoveStats {
	friend class CBasePiece;
protected:
	float m_flMoveDelay;
	float m_flMoveSpeed;
	
	float m_flStamina;
	float m_flMorale;
	
	float m_flBaseStaminaRegenRate;
	float m_flBaseMoraleRegenRate;
	
public:
	
};

#endif //CHEL_CHESS_MOVESTATS