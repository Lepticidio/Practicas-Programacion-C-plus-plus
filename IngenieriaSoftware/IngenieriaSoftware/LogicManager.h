#pragma once
#include "World.h"
class LogicManager
{
private:	
	std::vector<Enemy*> m_tEnemies;
	const int iMaxBulletsSide = 5;
	const int iMaxEnemies = 8;
	int iWidth = 40;
	float fPercentajePorbabilityEnemySpawn = 10.;
public:
	LogicManager();
	
};

