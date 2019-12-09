#include "Bullet.h"   

Bullet::Bullet(int _iX, bool _bRightMovement, int _iWidthWorld) : MovableObject(BULLET,_iX, '>'), m_bRightMovement(_bRightMovement),  m_iWidthWorld(_iWidthWorld)
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
void Bullet::CheckCollision(MovableObject* _pOtherObject)
{
	//printf("\nbullet checking");
	if (_pOtherObject->GetX() > m_iX - 2 && _pOtherObject->GetX() < m_iX + 2)
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
		m_iX = m_iWidthWorld;
	}
	else
	{
		m_iX = -1;
	}
}
bool Bullet::IsOutsideWorld()
{
	return ((m_bRightMovement && m_iX > m_iWidthWorld) || (!m_bRightMovement && m_iX < 0));
}