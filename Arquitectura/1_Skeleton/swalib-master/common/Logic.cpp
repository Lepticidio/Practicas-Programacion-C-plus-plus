#include "Logic.h"

void Logic::Initialize()
{

	// Init game state.
	for (int i = 0; i < NUM_BALLS; i++)
	{	
		balls[i].NUM_BALLS = &NUM_BALLS;
		balls[i].balls = balls;
		balls[i].index = i;
		balls[i].pos = vmake(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT));
		balls[i].vel = vmake(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED));
		balls[i].radius = 16.f;
	}

}

void Logic::Update(float _fDeltaTime)
{
	// Run balls
	for (int i = 0; i < NUM_BALLS; i++)
	{
		balls[i].logic(_fDeltaTime);
	}
	//SYS_Sleep(17);

}