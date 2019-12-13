#ifndef _WORLD_H_
#define _WORLD_H_

#include "../Global/timer.h"

// forward declaration
class cEntity;
class cBackground;

class cWorld
{
public:
	typedef std::vector<cEntity *>	tEntities;	// Typedef array of entities.

private:
	static const size_t m_bMaxEntities = 10;	// Max. num balls.

	tEntities m_Entities;	// Vector of entities.
	cBackground	*m_pBackground;	// Backgroung game.
	cTimer m_Timer;	// Time to control game time.

public:
	// Singleton.
	static cWorld& GetInstance();
	cWorld(cWorld const&) = delete;
	void operator = (cWorld const&) = delete;

	inline tEntities &GetEntities() { return m_Entities; }

	void Init();
	void Terminate();
	void Slot();

private:
	cWorld();

	void EntitySlot(double fTimeDiff);
};

#endif // !_WORLD_H_
