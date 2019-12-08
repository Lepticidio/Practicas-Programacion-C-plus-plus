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
		
	int iWidth = 20;
	Player player (iWidth / 2);
	Bullet bulletRight(iWidth + 1, true);
	Bullet bulletLeft(-1, false);

	while (!bExit)
	{
		system("cls");
		//Render
		printf("\r");
		for (int i = 0; i < iWidth; i++)
		{
			if (i == player.GetX())
			{
				player.Print();
			}
			else if (i == bulletLeft.GetX())
			{
				bulletLeft.Print();
			}
			else if (i == bulletRight.GetX())
			{
				bulletRight.Print();
			}
			else
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
			if (bulletLeft.GetX() < 0)
			{
				bulletLeft.SetX(player.GetX() - 1);
			}
		}

		if (GetKeyInput('k'))
		{
			if (bulletRight.GetX() > iWidth)
			{
				bulletRight.SetX(player.GetX() + 1);
			}
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			bExit = true;
		}
		
		//Move bullets
		if (bulletLeft.GetX() >= 0)
		{
			bulletLeft.Move();
		}
		if (bulletRight.GetX() <= iWidth)
		{
			bulletRight.Move();
		}
		Sleep(50);

	}
}