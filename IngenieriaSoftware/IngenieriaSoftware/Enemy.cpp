#include "Enemy.h"
#include "World.h"



Enemy::Enemy(int _iX, int _iWidth, Player* _pPlayer) : MovableObject(ENEMY, _iX, '*'), m_iWidth(_iWidth), m_pPlayer(_pPlayer)
{
	m_stateMachine = StateMachine();
}
void Enemy::Update()
{
	if (m_bIsActive)
	{
		m_stateMachine.CheckState(this);
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
				m_pPlayer->IncreaseScore();
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
	if (m_pPlayer->GetX() > m_iX && m_iX > 0)
	{
		MoveLeft();
	}
	else if(m_pPlayer->GetX() < m_iX&& m_iX < World::GetInstance().GetWidth() - 1)
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
bool Enemy::IsNearBullet()
{
	int iMinX = GetX() - m_iBulletFleeDistance;
	int iMaxX = GetX() + m_iBulletFleeDistance;
	int iWidthWorld = World::GetInstance().GetWidth();
	if (iMinX < 0)
	{
		iMinX = 0;
	}
	if (iMaxX >= iWidthWorld)
	{
		iMaxX = iWidthWorld - 1;
	}
	for (int i = iMinX; i < iMaxX + 1; i++)
	{
		if (World::GetInstance().CheckPositionForObjectType(i, BULLET))
		{
			return true;
		}
	}
	return false;
}