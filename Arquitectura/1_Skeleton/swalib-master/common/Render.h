#pragma once
#include "Logic.h"
#include "font.h"
#include <iostream>  
class Render
{
public:
	GLuint* texbkg;
	GLuint* texsmallball;
	void Initialize(const Logic& _logic);
	void Update(const Logic& _logic, const std::string& _sMessageFrames);
	void Shutdown();
private:
	int iCounter = 0;
};