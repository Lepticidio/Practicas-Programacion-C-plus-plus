#pragma once
#include "InputManager.h"

class RenderManager
{
private:
	int m_iWidth;
	Player* m_pPlayer = nullptr;
	std::vector<MovableObject*> m_tObjects;
public:
	RenderManager(std::vector<MovableObject*> _tObjects, int _iWidth);
	void Render();
};

