#pragma once
#include "MovableObject.h"
#include "Player.h"

class Enemy : public MovableObject	
{
	private:
		Player m_player;
		void UpdateEnemy();
	public:
		Enemy(int _iX, Player _player);
		void MoveTowardsPlayer();
		void MoveAwayFromPlayer();
		virtual void Update();
};

