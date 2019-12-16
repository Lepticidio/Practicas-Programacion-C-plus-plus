// IngenieriaSoftware.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Enemy.h"
#include "RenderManager.h"

int main()
{
	bool bExit = false;
	   


	InputManager inputManager(tObjects, bExit, iWidth);
	RenderManager renderManager(tObjects, iWidth);

	while (!bExit)
	{
		inputManager.CheckInput();
		//Spawn Enemies
		float fProbability = (float)(rand() % 100);
		if (fPercentajePorbabilityEnemySpawn > fProbability)
		{
			int iCounter = 0;
			while (iCounter < tEnemies.size())			
			{
				if (!(tEnemies[iCounter]->GetIsActive()))
				{
					tEnemies[iCounter]->Activate();
					iCounter = tEnemies.size();
				}
				iCounter++;
			}
		}
		
		//Update Objects
		for (int i = 0; i < tObjects.size(); i++)
		{
			tObjects[i]->Update();
		}

		//Check for collisions
		for (int i = 0; i < tObjects.size(); i++)
		{
			//Check and compute collisions
			for (int j = i + 1; j < tObjects.size(); j++)
			{
				tObjects[i]->CheckCollision(tObjects[j]);
			}
		}
		bExit = player.GetIsDead();

		renderManager.Render();


		Sleep(50);
	}
}