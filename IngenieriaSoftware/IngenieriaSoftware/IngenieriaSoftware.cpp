// IngenieriaSoftware.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "windows.h"
#include "MovableObject.h"
#include "Player.h"
#include "Bullet.h"

//This stores the layout, needed for getting async key input
HKL kbl = GetKeyboardLayout(0);

//This method makes key input more readeable
//If key of char is pressed, returns true

bool GetKeyInput(char _cInput)
{
	return (GetAsyncKeyState(VkKeyScanEx(_cInput, kbl)));
}
int main()
{
    std::cout << "Hello World!\n";

	bool bExit = false;;
	const int iMaxBulletsSide = 5;
	int iWidth = 40;
	Player player (iWidth / 2);
	Bullet bulletsRight[iMaxBulletsSide] = {Bullet(iWidth + 1, true), Bullet(iWidth + 1, true), Bullet(iWidth + 1, true), Bullet(iWidth + 1, true), Bullet(iWidth + 1, true) };
	Bullet bulletsLeft[iMaxBulletsSide] = { Bullet(-1, false), Bullet(-1, false), Bullet(-1, false), Bullet(-1, false), Bullet(-1, false) };

	while (!bExit)
	{
		system("cls");
		//Render
		printf("\r");
		for (int i = 0; i < iWidth; i++)
		{
			bool bEmptyPosition = true;
			int iCounter = 0;
			while (iCounter < iMaxBulletsSide && bEmptyPosition)
			{

				if (i == bulletsLeft[iCounter].GetX())
				{
					bulletsLeft[iCounter].Print();
					bEmptyPosition = false;
				}
				else if (i == bulletsRight[iCounter].GetX())
				{
					bulletsRight[iCounter].Print();
					bEmptyPosition = false;
				}
				iCounter++;
			}
				
			if (i == player.GetX() && bEmptyPosition)
			{
				player.Print();
				bEmptyPosition = false;
			}
			else if (bEmptyPosition)
			{
				printf("-");
			}
		}
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
			bool bAvailableBulletFound = false;
			int iCounter = 0;
			while (iCounter < iMaxBulletsSide && !bAvailableBulletFound)
			{
				
				if (bulletsLeft[iCounter].GetX() < 0)
				{
					bulletsLeft[iCounter].SetX(player.GetX() - 1);
					bAvailableBulletFound = true;
				}
				iCounter++;
			}
		}

		if (GetKeyInput('k'))
		{
			bool bAvailableBulletFound = false;
			int iCounter = 0;
			while (iCounter < iMaxBulletsSide && !bAvailableBulletFound)
			{
				if (bulletsRight[iCounter].GetX() > iWidth)
				{
					bulletsRight[iCounter].SetX(player.GetX() + 1);
					bAvailableBulletFound = true;
				}
				iCounter++;
			}
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			bExit = true;
		}
		
		//Move bullets
		for (int i = 0; i < iMaxBulletsSide; i++)
		{
			bulletsLeft[i].Move();
			bulletsRight[i].Move();
		}

		Sleep(50);

	}
}