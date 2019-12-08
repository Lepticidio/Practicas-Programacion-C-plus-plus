#pragma once
#include <iostream>
class MovableObject abstract
{
protected:
	int m_iX;
	char m_cSprite;
	MovableObject(int _iX, char _cSprite);

public:
	void Print();
	void SetX(int _iX);
	void MoveRight();
	void MoveLeft();
	int GetX();
	


};

