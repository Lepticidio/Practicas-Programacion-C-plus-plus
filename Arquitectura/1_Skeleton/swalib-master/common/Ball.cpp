#include "Ball.h"
void Ball::logic(float _fDeltaTime)
{

	// New Pos.
	vscale(vel, _fDeltaTime);
	vec2 newpos = vadd(pos, vel);

	// Collision detection.
	bool collision = false;
	int colliding_ball = -1;
	for (int j = 0; j < *NUM_BALLS; j++)
	{
		if (index != j)
		{
			float limit2 = (radius + balls[j].radius) * (radius + balls[j].radius);
			if (vlen2(vsub(newpos, balls[j].pos)) <= limit2)
			{
				collision = true;
				colliding_ball = j;
				break;
			}
		}
	}

	if (!collision)
	{
		pos = newpos;
	}
	else
	{
		// Rebound!
		vel = vscale(vel, -1.f);
		balls[colliding_ball].vel = vscale(balls[colliding_ball].vel, -1.f);
	}

	// Rebound on margins.
	if ((pos.x > SCR_WIDTH) || (pos.x < 0))
	{
		vel.x *= -1.0;
	}
	if ((pos.y > SCR_HEIGHT) || (pos.y < 0))
	{
		vel.y *= -1.0;
	}
}