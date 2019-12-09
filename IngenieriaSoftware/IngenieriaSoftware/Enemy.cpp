#include "Enemy.h"

Enemy::Enemy(int _iX, Player _player) : MovableObject(_iX, '*'), m_player(_player)
{

}
void Enemy::MoveTowardsPlayer()
{
	if (m_player.GetX() < m_iX)
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
	if (m_player.GetX() > m_iX)
	{
		MoveLeft();
	}
	else
	{
		MoveRight();
	}

}
void Enemy::Update()
{
	MoveTowardsPlayer();
}