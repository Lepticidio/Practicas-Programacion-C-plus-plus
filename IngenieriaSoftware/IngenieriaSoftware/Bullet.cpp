#include "Bullet.h"   

Bullet::Bullet(int _iX, bool _bRightMovement, int _iWidthWorld) : MovableObject(_iX, '>'), m_bRightMovement(_bRightMovement),  m_iWidthWorld(_iWidthWorld)
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
bool Bullet::IsOutsideWorld()
{
	return ((m_bRightMovement && m_iX > m_iWidthWorld) || (!m_bRightMovement && m_iX < 0));
}
void Bullet::Update()
{

	printf(" updating bullet");
	if (!IsOutsideWorld())
	{
		printf(" not outside");
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