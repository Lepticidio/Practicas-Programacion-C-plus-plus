#pragma once
#include "MovableObject.h"
class StateMachine
{
public:
	typedef void (*State)(MovableObject*);
private:
	State m_currentState;
public:
	StateMachine();
	void CheckState(MovableObject* _object);
};