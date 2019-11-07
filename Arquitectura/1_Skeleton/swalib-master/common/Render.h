#pragma once
#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "Logic.h"
class Render
{
public:
	GLuint* texbkg;
	GLuint* texsmallball;
	void Initialize();
	void Update(const Logic& _logic);
	void Shutdown();
};