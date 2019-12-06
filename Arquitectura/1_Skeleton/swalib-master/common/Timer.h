#pragma once
#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include <string>  
class Timer
{
private:

	LARGE_INTEGER iFrecuency;
	LARGE_INTEGER iCounter;
	long long int iPreviousCount = 0;
	long long int iCurrentCount = 0;
	float fDeltaTime = 0;
	float fTotalTime = 0;
	float fLogicTime = 0;
	float fVirtualTime = 0;
	float fVirtualTimeFactor = 1.;
	const float fFixedTime = 1. / 60.;
	std::string sMessageFrames = "FPS:";
public :
	void Initialize();
	void InitSlotsToProcess();
	bool ProcessSlots();
	float GetFixedTime();
	std::string GetMessageFrames();
};

