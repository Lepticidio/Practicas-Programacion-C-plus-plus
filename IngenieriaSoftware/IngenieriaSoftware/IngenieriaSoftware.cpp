// IngenieriaSoftware.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>	//needed to use dynamic tables of objects
#include "windows.h" //needed for async key input and sleep
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

//This stores the layout, needed for getting async key input
HKL kbl = GetKeyboardLayout(0);

//This function makes key input more readeable
//If key of char is pressed, returns true
bool GetKeyInput(char _cInput)
{
	return (GetAsyncKeyState(VkKeyScanEx(_cInput, kbl)));
}
int main()
{
	bool bExit = false;;
	const int iMaxBulletsSide = 5;
	const int iMaxEnemies = 8;
	int iWidth = 40;
	float fPercentajePorbabilityEnemySpawn = 25.;
	std::vector<MovableObject*> tObjects;
	std::vector<Bullet*> tRightBullets;
	std::vector<Bullet*> tLeftBullets;
	std::vector<Enemy*> tEnemies;
	Player player(iWidth / 2);
	tObjects.push_back(&player);
	for (int i = 0; i < iMaxBulletsSide; i++)
	{
		Bullet* rightBullet = new Bullet(iWidth + 1, true, iWidth);
		tObjects.push_back(rightBullet);
		tRightBullets.push_back(rightBullet);

		Bullet* leftBullet = new Bullet(-1, false, iWidth);
		tObjects.push_back(leftBullet);
		tLeftBullets.push_back(leftBullet);
	}
	for (int i = 0; i < iMaxEnemies; i++)
	{
		Enemy* enemy = new Enemy(-1, iWidth, &player);
		tObjects.push_back(enemy);
		tEnemies.push_back(enemy);
		enemy->Reset();
	}

	while (!bExit)
	{
		system("cls");
		//Process input
		if (GetKeyInput('h'))
		{
			if (player.GetX() > 0)
			{
				player.MoveLeft();
			}
		}

		if (GetKeyInput('l'))
		{
			if (player.GetX() < iWidth - 1)
			{
				player.MoveRight();
			}
		}

		if (GetKeyInput('j'))
		{
			int iCounter = 0;
			while (iCounter < iMaxBulletsSide)
			{				
				if (tLeftBullets[iCounter]->IsOutsideWorld())
				{
					tLeftBullets[iCounter]->SetX(player.GetX() - 1);
					iCounter = iMaxBulletsSide;
				}
				iCounter++;
			}
		}

		if (GetKeyInput('k'))
		{			
			int iCounter = 0;
			while (iCounter < iMaxBulletsSide)
			{
				if (tRightBullets[iCounter]->IsOutsideWorld())
				{
					tRightBullets[iCounter]->SetX(player.GetX() + 1);
					iCounter = iMaxBulletsSide;
				}
				iCounter++;
			}
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			bExit = true;
		}

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