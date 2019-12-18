#include "LogicManager.h"

LogicManager::LogicManager()
{
}

LogicManager& LogicManager::GetInstance()
{
	static LogicManager logic;
	return logic;
}
void LogicManager::UpdateLogic()
{
	int iNumberObjects = World::GetInstance().GetNumberObjects();
	int iNumberEnemies = World::GetInstance().GetMaxEnemies();
	//Spawn Enemies
	//For each frame, there is a probability of an enemy being spawned
	//If max not reached, we get a deactivated enemy (outside the world) and activate it
	float fProbability = (float)(rand() % 100);
	if (fPercentajePorbabilityEnemySpawn > fProbability)
	{
		int iCounter = 0;
		while (iCounter < iNumberEnemies)
		{
			Enemy* pEnemy = World::GetInstance().GetEnemyAtIndex(iCounter);
			if (pEnemy != nullptr)
			{
				if (!(pEnemy->GetIsActive()))
				{
					pEnemy->Activate();
					iCounter = iNumberEnemies;
				}
			}
			iCounter++;
		}
	}

	//Update Objects
	for (int i = 0; i < iNumberObjects; i++)
	{
		World::GetInstance().GetObjectAtIndex(i)->Update();
	}

	//Check for collisions
	for ( int i = 0; i < iNumberObjects; i++)
	{
		//Check and compute collisions
		for (int j = i + 1; j < iNumberObjects; j++)
		{
			MovableObject* pObject = World::GetInstance().GetObjectAtIndex(i);
			MovableObject* pOtherObject = World::GetInstance().GetObjectAtIndex(j);
			pObject->CheckCollision(pOtherObject);
		}
	}
}