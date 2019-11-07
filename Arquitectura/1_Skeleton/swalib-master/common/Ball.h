#pragma once
#include "Render.h"

class Ball
{
public:
	unsigned int* NUM_BALLS;
	Ball* balls;
	int index;
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	GLuint gfx;	// OpenGL for id. for visualization purposes. 
	float  radius;	// Radius.
	void logic();
	void render();
};

