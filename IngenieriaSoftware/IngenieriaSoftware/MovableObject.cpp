#include "MovableObject.h"

MovableObject::MovableObject(ObjectType _eType, int _iX, char _cSprite) : m_eType(_eType), m_iX(_iX), m_cSprite(_cSprite)
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
ObjectType MovableObject::GetType()
{
	return m_eType;
}
void MovableObject::Render()
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
void MovableObject::Update()
{

}
void MovableObject::CheckCollision(MovableObject* _pOtherObject)
{

}