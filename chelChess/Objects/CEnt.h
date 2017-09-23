#ifndef CHEL_CHESS_ENT
#define CHEL_CHESS_ENT

#include "../base.h"

class CEnt;

class CMoveInfo {
	Coord2D m_cFrom;
	Coord2D m_cTo;
	
	CEnt* m_pMover;
	CEnt* m_pCaptured;
};

/**
 * @class CEnt
 * @author Awesome
 * @date 28/06/2017
 * @file CEnt.h
 * @brief Base entity class for all instantiable entities in a chess game
 */
class CEnt : public CNameable {
	CLASS_ALIASES(CNameable, CEnt)
private:
	char m_char;
	
public:
	char toChar() const { return m_char; }
	
	/**
	 * @brief Called after a move is chosen yet before it is applied to the board
	 * @param info - the movement information
	 */
	virtual void itemPreMove(const CMoveInfo& info) {}
	
	/**
	 * @brief Called after a move is made and applied to the board
	 * 		AND after the game rules updates round/match status
	 * @param info - the movement information
	 */
	virtual void itemPostMove(const CMoveInfo& info) {}
	
private:
	bool m_bEnabled = true;
	
public:
	inline bool isEnabled() const { return m_bEnabled; }
	void setEnabled(bool is);
	
	virtual void onEnabled() {}
	virtual void onDisabled() {}
	
private:
	bool m_bVisible = true;
public:
	inline bool isVisible() const { return m_bVisible; }
	inline void setVisible(bool is) { m_bVisible = is; }
	
private:
	bool m_bClickable = true;
	
public:
	inline bool isClickable() const { return m_bClickable; }
	inline void setClickable(bool is) { m_bClickable = is; }
	
protected:
	//Inherited from CNameable
	virtual void postConstruct(CNameableFactory* pFactory) override { BaseClass::postConstruct(pFactory); }
};

#endif //CHEL_CHESS_ENT