#include "InputManager.h"

//This function makes key input more readeable
//If key of char is pressed, returns true
bool InputManager::GetKeyInput(char _cInput)
{
	return (GetAsyncKeyState(VkKeyScanEx(_cInput, m_kbl)));
}

InputManager::InputManager(std::vector<MovableObject*> _tObjects, bool _bExit, int _iWidth): m_pExit(&_bExit), m_pWidth(&_iWidth)
{
	for (int i = 0; i < _tObjects.size(); i++)
	{
		if (_tObjects[i]->GetType() == PLAYER)
		{
			m_pPlayer = static_cast<Player*>(_tObjects[i]);
		}
		else if (_tObjects[i]->GetType() == BULLET)
		{
			Bullet* pBullet = static_cast<Bullet*>(_tObjects[i]);
			if (pBullet->IsMovingRight())
			{
				m_tRightBullets.push_back(pBullet);
			}
			else
			{
				m_tLeftBullets.push_back(pBullet);
			}
		}
	}
}

void InputManager::CheckInput()
{
	//Process input
	if (GetKeyInput('h'))
	{
		if (m_pPlayer->GetX() > 0)
		{
			m_pPlayer->MoveLeft();
		}
	}

	if (GetKeyInput('l'))
	{
		if (m_pPlayer->GetX() < *m_pWidth - 1)
		{
			m_pPlayer->MoveRight();
		}
	}

	if (GetKeyInput('j'))
	{
		int iCounter = 0;
		while (iCounter < m_tLeftBullets.size())
		{
			if (m_tLeftBullets[iCounter]->IsOutsideWorld())
			{
				m_tLeftBullets[iCounter]->SetX(m_pPlayer->GetX() - 1);
				iCounter = m_tLeftBullets.size();
			}
			iCounter++;
		}
	}

	if (GetKeyInput('k'))
	{
		int iCounter = 0;
		while (iCounter < m_tRightBullets.size())
		{
			if (m_tRightBullets[iCounter]->IsOutsideWorld())
			{
				m_tRightBullets[iCounter]->SetX(m_pPlayer->GetX() + 1);
				iCounter = m_tRightBullets.size();
			}
			iCounter++;
		}
	}
}