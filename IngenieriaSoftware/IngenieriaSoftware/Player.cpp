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
	m_bIsDead = _bIsDead;
}
void Player::IncreaseScore()
{
	m_iScore++;
}
bool Player::GetIsDead()
{
	return m_bIsDead;
}
int Player::GetScore()
{
	return m_iScore;
}