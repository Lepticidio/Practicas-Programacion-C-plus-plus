#include "LogicManager.h"

LogicManager::LogicManager()
{
	Player player(iWidth / 2);
	m_tObjects.push_back(&player);

	for (int i = 0; i < iMaxBulletsSide; i++)
	{
		Bullet* rightBullet = new Bullet(iWidth + 1, true, iWidth);
		m_tObjects.push_back(rightBullet);

		Bullet* leftBullet = new Bullet(-1, false, iWidth);
		m_tObjects.push_back(leftBullet);
	}
	for (int i = 0; i < iMaxEnemies; i++)
	{
		Enemy* enemy = new Enemy(-1, iWidth, &player);
		m_tObjects.push_back(enemy);
		m_tEnemies.push_back(enemy);
		enemy->Reset();
	}
}
