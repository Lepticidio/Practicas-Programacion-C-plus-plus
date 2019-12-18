// LoopManager.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "RenderManager.h"

int main()
{
	//This will be checked to know if we must stay in the loop
	bool bExit = false;
	  
	World::GetInstance().Init();
	while (!bExit)
	{
		InputManager::GetInstance().CheckInput();
		LogicManager::GetInstance().UpdateLogic();
		RenderManager::GetInstance().Render();

		//If player is dead or escaped was pressed, loop ends
		bExit = (World::GetInstance().GetPlayer()->GetIsDead() || InputManager::GetInstance().GetEscape());

		//To have reasonable FPS
		Sleep(50);
	}
}