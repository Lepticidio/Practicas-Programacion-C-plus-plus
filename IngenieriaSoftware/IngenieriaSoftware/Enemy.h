#pragma once
#include "MovableObject.h"
#include "Player.h"
#include "Bullet.h"

class Enemy : public MovableObject	
{
	private:
		bool m_bIsActive = false;
		int m_iWidth;
		Player* m_pPlayer;
	public:
		Enemy(int _iX, int _iWidth, Player* _pPlayer);
		virtual void Update();
		virtual void CheckCollision(MovableObject* _pOtherObject);
		void MoveTowardsPlayer();
		void MoveAwayFromPlayer();
		void Reset();
		void Activate();
		bool GetIsActive();
};

