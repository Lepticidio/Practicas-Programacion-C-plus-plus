#pragma once
#include "World.h"
class LogicManager
{
private:	
	float fPercentajePorbabilityEnemySpawn = 10.;
	LogicManager();

public:
	// Singleton.
	static LogicManager& GetInstance();
	LogicManager(LogicManager const&) = delete;
	void operator = (LogicManager const&) = delete;

	void UpdateLogic();	
};

