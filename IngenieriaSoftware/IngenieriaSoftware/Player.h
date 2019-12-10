#pragma once
#include "MovableObject.h"

class Player: public MovableObject
{
	private:
		bool m_bIsDead = false;
		int m_iScore = 0;
	public:
		Player(int _iX);
		virtual void Update();
		virtual void CheckCollision(MovableObject* _pOtherObject);
		void SetIsDead(bool _bIsDead);
		void IncreaseScore();
		bool GetIsDead();
		int GetScore();
};

