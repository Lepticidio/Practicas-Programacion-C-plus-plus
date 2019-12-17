#pragma once
#include <vector>	//needed to use dynamic tables of objects
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
class World
{
private:
	World();
	const int m_iMaxBulletsSide = 5;
	const int m_iMaxEnemies = 8;
	const int m_iWidth = 40;
	Player m_player;
	std::vector<MovableObject*> m_tObjects;
public:
	// Singleton.
	static World& GetInstance();
	World(World const&) = delete;
	void operator = (World const&) = delete;

	int GetMaxBulletsSide();
	int GetMaxEnemies();
	int GetWidth();
	int GetNumberObjects();
	MovableObject* GetObjectAtIndex(int _iIndex);
	Player* GetPlayer();
	Enemy* GetEnemyAtIndex(int _iIndex);
	Bullet* GetBulletAtIndex(int _iIndex, bool _bRight);
};

