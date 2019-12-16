#pragma once
#include <vector>	//needed to use dynamic tables of objects
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
class World
{
private:
	std::vector<MovableObject*> m_tObjects;
	static World* m_pInstance;
public:
	static World GetInstance();
	std::vector<MovableObject*>GetTObjects();	
};

