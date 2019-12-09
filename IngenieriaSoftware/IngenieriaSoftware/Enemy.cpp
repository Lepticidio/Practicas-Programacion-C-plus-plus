#include "Enemy.h"

Enemy::Enemy(int _iX, Player* _pPlayer) : MovableObject(ENEMY, _iX, '*'), m_pPlayer(_pPlayer)
{

}
void Enemy::Update()
{
	MoveTowardsPlayer();
}
void Enemy::CheckCollision(MovableObject* _pOtherObject)
{

	if (_pOtherObject->GetX() > m_iX -2 && _pOtherObject->GetX() < m_iX + 2)
	{
		if (_pOtherObject->GetType() == BULLET)
		{
			Bullet* _pBullet = static_cast<Bullet*>(_pOtherObject);
			if (!_pBullet->IsOutsideWorld())
			{
				SetX(-1);
				_pBullet->ResetPosition();
			}
		}
		else if (_pOtherObject->GetType() == PLAYER)
		{
			static_cast<Player*>(_pOtherObject)->SetIsDead(true);
		}
	}
}
void Enemy::MoveTowardsPlayer()
{
	if (m_pPlayer->GetX() < m_iX)
	{
		MoveLeft();
	}
	else
	{
		MoveRight();
	}
}
void Enemy::MoveAwayFromPlayer()
{
	if (m_pPlayer->GetX() > m_iX)
	{
		MoveLeft();
	}
	else
	{
		MoveRight();
	}

}