#pragma once
#include "MovableObject.h"
#include "Player.h"
#include "Bullet.h"
#include "StateMachine.h"


class Enemy : public MovableObject	
{
	private:
		bool m_bIsActive = false;
		int m_iWidth;
		int m_iBulletFleeDistance = 3;
		Player* m_pPlayer;
		StateMachine m_stateMachine;
	public:
		Enemy(int _iX, int _iWidth, Player* _pPlayer);
		virtual void Update();
		virtual void CheckCollision(MovableObject* _pOtherObject);
		void MoveTowardsPlayer();
		void MoveAwayFromPlayer();
		void Reset();
		void Activate();
		bool GetIsActive();
		bool IsNearBullet();
};

