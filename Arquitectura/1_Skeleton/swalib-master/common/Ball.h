#pragma once
#include "Timer.h"

class Ball
{

private: 
	int index;
	GLuint gfx;	// OpenGL for id. for visualization purposes. 
	float  radius;	// Radius.
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.

public:
	unsigned int* NUM_BALLS;
	Ball* balls;
	void Slot(float _fDeltaTime);
	int GetIndex();
	GLuint GetGfx();
	float GetRadius();
	vec2 GetPos();
	vec2 GetVel();
	void SetIndex(int _index);
	void SetGfx(GLuint _gfx);
	void SetRadius(float _radius);
	void SetPos(vec2 _pos);
	void SetVel(vec2 _vel);

};

