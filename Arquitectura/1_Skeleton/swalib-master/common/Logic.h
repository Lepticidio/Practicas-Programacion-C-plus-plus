#pragma once
#include "Ball.h"
class Logic
{
public:
	//-----------------------------------------------------------------------------
	// Logic Info.
	Logic()
	{
		balls = new Ball[NUM_BALLS];
	}

	const unsigned int NUM_BALLS = 10;	// Max. num balls.
	Ball* balls;	// Array of balls.
	const float MAX_BALL_SPEED = 8.f;	// Max vel. of ball. (pixels/?).
	void Initialize();
	void Update();
};

