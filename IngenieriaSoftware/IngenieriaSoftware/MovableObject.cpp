#include "MovableObject.h"

MovableObject::MovableObject(int _iX, char _cSprite) : m_iX(_iX), m_cSprite(_cSprite)
{

}
void MovableObject::SetX(int _iX)
{
	m_iX = _iX;
}
int MovableObject::GetX()
{
	return m_iX;
}
void MovableObject::Print()
{
	printf("%c", m_cSprite);
}
void MovableObject::MoveRight()
{
	m_iX++;
}
void MovableObject::MoveLeft()
{
	m_iX--;
}