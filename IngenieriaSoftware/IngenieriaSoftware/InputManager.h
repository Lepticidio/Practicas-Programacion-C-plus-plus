#pragma once
#include "windows.h" //needed for async key input and sleep
#include "LogicManager.h"

class InputManager
{
private:
	InputManager();
	bool* m_pExit;
	//This stores the layout, needed for getting async key input
	HKL m_kbl = GetKeyboardLayout(0);
	bool GetKeyInput(char _cInput);
	static InputManager* m_pInstance;
public:
	// Singleton.
	static InputManager& GetInstance();
	InputManager(InputManager const&) = delete;
	void operator = (InputManager const&) = delete;
	
	void CheckInput();
};

