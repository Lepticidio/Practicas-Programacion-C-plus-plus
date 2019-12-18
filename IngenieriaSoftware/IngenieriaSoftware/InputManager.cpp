#include "InputManager.h"

InputManager& InputManager::GetInstance()
{
	static InputManager input;
	return input;
}
InputManager::InputManager()
{
}
//This function makes key input more readeable
//If key of char is pressed, returns true
bool InputManager::GetKeyInput(char _cInput)
{
	return (GetAsyncKeyState(VkKeyScanEx(_cInput, m_kbl)));
}
//Process input
void InputManager::CheckInput()
{
	m_bEscape = false;
	int iMaxNumberBulletsSide = World::GetInstance().GetMaxBulletsSide();
	Player* pPlayer = World::GetInstance().GetPlayer();

	//Player control
	if (GetKeyInput('h'))
	{
		if (pPlayer->GetX() > 0)
		{
			pPlayer->MoveLeft();
		}
	}

	if (GetKeyInput('l'))
	{
		if (pPlayer->GetX() < World::GetInstance().GetWidth() - 1)
		{
			pPlayer->MoveRight();
		}
	}

	//Bullet spawning
	//With 'j' and 'k' Gets a currently deactivated bullet and, if limit has not been reached, spawns a new bullet
	//This is made considering bullets outside world as deactivated, and bringing them near the player
	if (GetKeyInput('j'))
	{
		int iCounter = 0;
		while (iCounter < iMaxNumberBulletsSide)
		{
			Bullet* pBullet = World::GetInstance().GetBulletAtIndex(iCounter, false);
			if (pBullet->IsOutsideWorld())
			{
				pBullet->SetX(pPlayer->GetX() - 1);
				iCounter = iMaxNumberBulletsSide;
			}
			iCounter++;
		}
	}
	if (GetKeyInput('k'))
	{
		int iCounter = 0;
		while (iCounter < iMaxNumberBulletsSide)
		{
			Bullet* pBullet = World::GetInstance().GetBulletAtIndex(iCounter, true);
			if (pBullet->IsOutsideWorld())
			{
				pBullet->SetX(pPlayer->GetX() + 1);
				iCounter = iMaxNumberBulletsSide;
			}
			iCounter++;
		}
	}
	//Exit the game with esc key
	m_bEscape = GetAsyncKeyState(VK_ESCAPE);
}
bool InputManager::GetEscape()
{
	return m_bEscape;
}