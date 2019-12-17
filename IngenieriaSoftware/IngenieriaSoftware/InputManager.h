#pragma once
#include "windows.h" //needed for async key input and sleep
#include "LogicManager.h"

class InputManager
{
private:
	bool* m_pExit;
	//This stores the layout, needed for getting async key input
	HKL m_kbl = GetKeyboardLayout(0);
	bool GetKeyInput(char _cInput);
	static InputManager* m_pInstance;
public:
	static InputManager GetInstance();
	InputManager();
	void CheckInput();
};

