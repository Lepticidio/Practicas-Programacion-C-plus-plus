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
void InputManager::CheckInput()
{
	int iMaxNumberBulletsSide = World::GetInstance().GetMaxBulletsSide();
	Player* pPlayer = World::GetInstance().GetPlayer();
	//Process input
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
}