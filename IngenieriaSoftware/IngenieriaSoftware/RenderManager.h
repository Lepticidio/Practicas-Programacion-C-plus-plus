#pragma once
#include "InputManager.h"

class RenderManager
{
private:
	static RenderManager* m_pInstance;
public:
	RenderManager();
	void Render();
	static RenderManager GetInstance();
};

