#include "InputManager.h"

//This function makes key input more readeable
//If key of char is pressed, returns true
bool InputManager::GetKeyInput(char _cInput)
{
	return (GetAsyncKeyState(VkKeyScanEx(_cInput, m_kbl)));
}

InputManager::InputManager()
{
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
InputManager InputManager::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new InputManager();
	}
	return *m_pInstance;
}
InputManager* InputManager::m_pInstance = &InputManager::GetInstance();