#pragma once
#include <iostream>

//Needed for collisions
enum ObjectType
{
	BULLET,
	ENEMY,
	PLAYER
};
class MovableObject abstract
{
	protected:
		int m_iX;
		char m_cSprite;
		ObjectType m_eType;
		MovableObject(ObjectType _eType, int _iX, char _cSprite);

	public:
		void Print();
		void SetX(int _iX);
		void MoveRight();
		void MoveLeft();
		virtual void Update();
		virtual void CheckCollision(MovableObject* _pOtherObject);
		ObjectType GetType();
		int GetX();
};

