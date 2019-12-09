#include "Player.h"

Player::Player(int _iX) : MovableObject(PLAYER, _iX, 'X')
{

}
void Player::Update()
{

}
void Player::CheckCollision(MovableObject* _pOtherObject)
{
	if (_pOtherObject->GetX() > m_iX - 2 && _pOtherObject->GetX() < m_iX + 2)
	{
		if (_pOtherObject->GetType() == ENEMY)
		{
			_pOtherObject->CheckCollision(this);
		}
	}
}
void Player::SetIsDead(bool _bIsDead)
{
	bIsDead = _bIsDead;
}
bool Player::GetIsDead()
{
	return bIsDead;
}