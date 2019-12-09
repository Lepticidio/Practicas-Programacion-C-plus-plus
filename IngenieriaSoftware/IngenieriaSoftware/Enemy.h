#pragma once
#include "MovableObject.h"
#include "Player.h"
#include "Bullet.h"

class Enemy : public MovableObject	
{
	private:
		Player* m_pPlayer;
	public:
		Enemy(int _iX, Player* _pPlayer);
		virtual void Update();
		virtual void CheckCollision(MovableObject* _pOtherObject);
		void MoveTowardsPlayer();
		void MoveAwayFromPlayer();
};

