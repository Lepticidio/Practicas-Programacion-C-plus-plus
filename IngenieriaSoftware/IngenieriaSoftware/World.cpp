#include "World.h"

World& World::GetInstance()
{
	static World world;
	return world;
}
World::World() : m_iWidth(40), m_iMaxEnemies(8), m_iMaxBulletsSide(5), m_player(m_iWidth/2)
{
	m_tObjects.push_back(&m_player);

	for (int i = 0; i < m_iMaxBulletsSide; i++)
	{
		Bullet* rightBullet = new Bullet(m_iWidth + 1, true, m_iWidth);
		m_tObjects.push_back(rightBullet);

		Bullet* leftBullet = new Bullet(-1, false, m_iWidth);
		m_tObjects.push_back(leftBullet);
	}
	for (int i = 0; i < m_iMaxEnemies; i++)
	{
		Enemy* enemy = new Enemy(-1, m_iWidth, &m_player);
		m_tObjects.push_back(enemy);
		enemy->Reset();
	}
}
int World::GetMaxBulletsSide()
{
	return m_iMaxBulletsSide;
}
int World::GetMaxEnemies()
{
	return m_iMaxEnemies;
}
int World::GetWidth()
{
	return m_iWidth;
}
int World::GetNumberObjects()
{
	return m_tObjects.size();
}
Player* World::GetPlayer()
{
	return &m_player;
}
MovableObject* World::GetObjectAtIndex(int _iIndex)
{
	return m_tObjects[_iIndex];
}
Enemy* World::GetEnemyAtIndex(int _iIndex)
{
	Enemy* pResult = nullptr;
	int iCounter = 0;
	for (int i = 0; i < GetNumberObjects(); i++)
	{
		MovableObject* pObject = m_tObjects[i];
		if (pObject->GetType() == ENEMY && iCounter == _iIndex)
		{
			pResult = static_cast<Enemy*>(pObject);
		}
		iCounter++;
	}
	return pResult;
}
Bullet* World::GetBulletAtIndex(int _iIndex, bool _bRight)
{
	Bullet* pResult = nullptr;
	for (int i = 0; i < GetNumberObjects(); i++)
	{
		MovableObject* pObject = m_tObjects[i];
		if (pObject->GetType() == BULLET)
		{
			Bullet* pBullet = static_cast<Bullet*>(pObject);
			if (pBullet->IsMovingRight() == _bRight)
			{
				pResult = pBullet;
			}
		}
	}
	return pResult;
}