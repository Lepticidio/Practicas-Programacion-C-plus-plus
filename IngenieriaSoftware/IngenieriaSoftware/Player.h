#pragma once
#include "MovableObject.h"

class Player: public MovableObject
{
	private:
		bool bIsDead = false;
	public:
		Player(int _iX);
		virtual void Update();
		virtual void CheckCollision(MovableObject* _pOtherObject);
		void SetIsDead(bool _bIsDead);
		bool GetIsDead();
};

