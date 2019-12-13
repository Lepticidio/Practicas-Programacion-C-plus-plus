#pragma once
#include <vector>	//needed to use dynamic tables of objects
#include "windows.h" //needed for async key input and sleep
#include "Player.h"
#include "Bullet.h"

class InputManager
{
private:
	bool* m_pExit;
	int* m_pWidth;
	Player* m_pPlayer = nullptr;
	std::vector<Bullet*> m_tRightBullets;
	std::vector<Bullet*> m_tLeftBullets;
	//This stores the layout, needed for getting async key input
	HKL m_kbl = GetKeyboardLayout(0);
	bool GetKeyInput(char _cInput);
public:
	InputManager(std::vector<MovableObject*> _tObjects, bool _bExit, int _iWidth);
	void CheckInput();
};

