#include "Bullet.h"   
#include "World.h"

Bullet::Bullet(int _iX, bool _bRightMovement) : MovableObject(BULLET,_iX, '>'), m_bRightMovement(_bRightMovement)
{
	if (m_bRightMovement)
	{
		m_cSprite = '>';
	}
	else
	{
		m_cSprite = '<';
	}
}
void Bullet::Update()
{
	if (!IsOutsideWorld())
	{
		if (m_bRightMovement)
		{
			MoveRight();
		}
		else
		{
			MoveLeft();
		}
	}
}
//Only reacts to collision with enemy, if that happens calls enemy's collision method
//This avoids code duplication
void Bullet::CheckCollision(MovableObject* _pOtherObject)
{
	if (_pOtherObject->GetX() > m_iX - 1 && _pOtherObject->GetX() < m_iX + 1)
	{
		if (_pOtherObject->GetType() == ENEMY)
		{
			_pOtherObject->CheckCollision(this);
		}
	}
}
void Bullet::ResetPosition()
{
	if (m_bRightMovement)
	{
		m_iX = World::GetInstance().GetWidth();
	}
	else
	{
		m_iX = -1;
	}
}
bool Bullet::IsOutsideWorld()
{
	return ((m_bRightMovement && m_iX > World::GetInstance().GetWidth()) || (!m_bRightMovement && m_iX < 0));
}
bool Bullet::IsMovingRight()
{
	return m_bRightMovement;
}