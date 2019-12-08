// IngenieriaSoftware.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "windows.h"

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
		
	int WIDTH = 20;
	int g_x = WIDTH / 2;
	int g_blx = -1;
	int g_brx = WIDTH + 1;

	while (!bExit)
	{
		system("cls");
		//Render
		printf("\r");
		for (int i = 0; i < WIDTH; i++)
		{
			if (i == g_x)
			{
				printf("X");
			}
			else if (i == g_blx)
			{
				printf("<");
			}
			else if (i == g_brx)
			{
				printf(">");
			}
			else
			{
				printf("-");
			}
		}
		//Process input
		HKL kbl = GetKeyboardLayout(0);
		if (GetKeyInput('h'))
		{
			if (g_x > 0)
			{
				g_x--;
			}
		}

		if (GetKeyInput('l'))
		{
			if (g_x < WIDTH - 1)
			{
				g_x++;
			}
		}

		if (GetKeyInput('j'))
		{
			if (g_blx < 0)
			{
				g_blx = g_x - 1;
			}
		}

		if (GetKeyInput('k'))
		{
			if (g_brx > WIDTH)
			{
				g_brx = g_x + 1;
			}
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			bExit = true;
		}
		
		//Move bullets
		if (g_blx >= 0)
		{
			g_blx--;
		}
		if (g_brx <= WIDTH)
		{
			g_brx++;
		}
		Sleep(50);

	}
}