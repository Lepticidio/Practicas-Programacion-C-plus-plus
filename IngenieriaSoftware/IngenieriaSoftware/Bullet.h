#pragma once
#include "MovableObject.h"

class Bullet : public MovableObject
{
	private:
		//if true moves to the right, if false moves to the left
		bool m_bRightMovement;
	public:
		Bullet(int _iX, bool _bRightMovement);
		virtual void Update();
		virtual void CheckCollision(MovableObject* _pOtherObject);
		void ResetPosition();
		bool IsOutsideWorld();
		bool IsMovingRight();
};

