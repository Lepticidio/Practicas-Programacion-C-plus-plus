#pragma once
#include <iostream>

//Needed for collisions
enum ObjectType
{
	BULLET,
	ENEMY,
	PLAYER
};
//This class stores values and methods common to Bullet, Enemy and Player
class MovableObject abstract
{
	protected:
		int m_iX;
		char m_cSprite;
		ObjectType m_eType;
		MovableObject(ObjectType _eType, int _iX, char _cSprite);

	public:
		void Render();
		void SetX(int _iX);
		void MoveRight();
		void MoveLeft();
		virtual void Update();
		virtual void CheckCollision(MovableObject* _pOtherObject);
		ObjectType GetType();
		int GetX();
};

