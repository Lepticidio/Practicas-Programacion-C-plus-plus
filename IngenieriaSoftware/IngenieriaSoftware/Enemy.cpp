#include "Enemy.h"



Enemy::Enemy(int _iX, int _iWidth, Player* _pPlayer) : MovableObject(ENEMY, _iX, '*'), m_iWidth(_iWidth), m_pPlayer(_pPlayer)
{

}
void Enemy::Update()
{
	if (m_bIsActive)
	{
		MoveTowardsPlayer();
	}
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
				m_pPlayer->GetScore();
				Reset();
				m_bIsActive = false;
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
void Enemy::Reset()
{
	int iFlip = rand() % 2;
	if (iFlip == 0)
	{
		SetX(-1);
	}
	else
	{
		SetX(m_iWidth);
	}
	m_bIsActive = false;
}
void Enemy::Activate()
{
	m_bIsActive = true;
}
bool Enemy::GetIsActive()
{
	return m_bIsActive;
}