// LoopManager.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "RenderManager.h"

int main()
{
	bool bExit = false;
	  
	World::GetInstance().Initialize();
	while (!bExit)
	{
		InputManager::GetInstance().CheckInput();
		LogicManager::GetInstance().UpdateLogic();
		RenderManager::GetInstance().Render();

		bExit = World::GetInstance().GetPlayer()->GetIsDead();
		Sleep(50);
	}
}