#pragma once
#include "InputManager.h"

class RenderManager
{
private:
	RenderManager();
public:
	// Singleton.
	static RenderManager& GetInstance();
	RenderManager(RenderManager const&) = delete;
	void operator = (RenderManager const&) = delete;

	void Render();
};

