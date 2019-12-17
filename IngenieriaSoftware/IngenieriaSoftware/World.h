#pragma once
#include <vector>	//needed to use dynamic tables of objects
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
class World
{
private:
	World();
	const int m_iMaxBulletsSide;
	const int m_iMaxEnemies;
	const int m_iWidth;
	Player m_player;
	std::vector<MovableObject*> m_tObjects;
	static World* m_pInstance;
public:
	static World GetInstance();
	int GetMaxBulletsSide();
	int GetMaxEnemies();
	int GetWidth();
	int GetNumberObjects();
	MovableObject* GetObjectAtIndex(int _iIndex);
	Player* GetPlayer();
	Enemy* GetEnemyAtIndex(int _iIndex);
	Bullet* GetBulletAtIndex(int _iIndex, bool _bRight);
};

