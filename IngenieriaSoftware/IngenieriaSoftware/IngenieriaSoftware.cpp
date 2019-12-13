// IngenieriaSoftware.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Enemy.h"
#include "InputManager.h"

int main()
{
	bool bExit = false;;
	const int iMaxBulletsSide = 5;
	const int iMaxEnemies = 8;
	int iWidth = 40;
	float fPercentajePorbabilityEnemySpawn = 25.;
	std::vector<MovableObject*> tObjects;
	std::vector<Enemy*> tEnemies;
	Player player(iWidth / 2);
	tObjects.push_back(&player);

	for (int i = 0; i < iMaxBulletsSide; i++)
	{
		Bullet* rightBullet = new Bullet(iWidth + 1, true, iWidth);
		tObjects.push_back(rightBullet);

		Bullet* leftBullet = new Bullet(-1, false, iWidth);
		tObjects.push_back(leftBullet);
	}
	for (int i = 0; i < iMaxEnemies; i++)
	{
		Enemy* enemy = new Enemy(-1, iWidth, &player);
		tObjects.push_back(enemy);
		tEnemies.push_back(enemy);
		enemy->Reset();
	}

	InputManager inputManager(tObjects, bExit, iWidth);

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

		//Render
		system("cls");
		printf("\r");
		for (int i = 0; i < iWidth; i++)
		{
			bool bEmptyPosition = true;
			int iCounter = 0;
			while (iCounter < tObjects.size() && bEmptyPosition)
			{

				if (tObjects[iCounter]->GetX() == i)
				{
					tObjects[iCounter]->Print();
					bEmptyPosition = false;
				}
				iCounter++;
			}
			if (bEmptyPosition)
			{
				printf("-");
			}
		}
		printf("%d", player.GetScore());

		Sleep(50);
	}
}