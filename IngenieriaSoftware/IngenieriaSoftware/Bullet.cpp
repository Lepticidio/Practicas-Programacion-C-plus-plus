#include "Bullet.h"

Bullet::Bullet(int _iX, bool _bRightMovement) : MovableObject(_iX, '>'), m_bRightMovement(_bRightMovement)
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
void Bullet::Move()
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