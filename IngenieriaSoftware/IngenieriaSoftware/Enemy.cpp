#include "Enemy.h"
#include "World.h"



Enemy::Enemy(int _iX, Player* _pPlayer) : MovableObject(ENEMY, _iX, '*'), m_pPlayer(_pPlayer)
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
//As other objects other react to collisions with enemies, enemy controls all the consequences 
//This avoids code duplications
void Enemy::CheckCollision(MovableObject* _pOtherObject)
{
	if (_pOtherObject->GetX() > m_iX -1 && _pOtherObject->GetX() < m_iX + 1)
	{
		//Collision with bullet : Resets enemy and bullet, and increases score
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
		//Collision with player : Player is dead, and game will end
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
//Puts it outside the world, so it isn't rendered, and deactivates it
void Enemy::Reset()
{
	int iFlip = rand() % 2;
	if (iFlip == 0)
	{
		SetX(-1);
	}
	else
	{
		SetX(World::GetInstance().GetWidth());
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
//Used by the State Machine to know if it has to flee
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