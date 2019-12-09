#pragma once
#include "MovableObject.h"

class Player: public MovableObject
{
	private:
		void PlayerUpdate();
	public:
		Player(int _iX);
		virtual void Update();
};

