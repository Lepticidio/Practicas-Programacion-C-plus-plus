#pragma once
#include "MovableObject.h"
class StateMachine
{
	typedef void (*State)(MovableObject*&);
	State currentState;
};

