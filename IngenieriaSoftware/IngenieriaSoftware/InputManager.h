#pragma once
#include "windows.h" //needed for async key input and sleep
#include "LogicManager.h"

class InputManager
{
private:
	InputManager();
	bool m_bEscape = false;

	//This stores the layout, needed for getting async key input
	HKL m_kbl = GetKeyboardLayout(0);

	bool GetKeyInput(char _cInput);

public:
	// Singleton.
	static InputManager& GetInstance();
	InputManager(InputManager const&) = delete;
	void operator = (InputManager const&) = delete;	

	void CheckInput();
	bool GetEscape();
};

