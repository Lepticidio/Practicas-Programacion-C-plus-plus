#pragma once
#include "World.h"
class LogicManager
{
private:	
	float fPercentajePorbabilityEnemySpawn = 10.;
	static LogicManager* m_pInstance;

public:
	LogicManager();
	void UpdateLogic();
	static LogicManager GetInstance();
	
};

