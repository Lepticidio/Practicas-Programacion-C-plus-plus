#pragma once
#include "Logic.h"
#include "font.h"
class Render
{
public:
	GLuint* texbkg;
	GLuint* texsmallball;
	void Initialize(const Logic& _logic);
	void Update(const Logic& _logic);
	void Shutdown();
};