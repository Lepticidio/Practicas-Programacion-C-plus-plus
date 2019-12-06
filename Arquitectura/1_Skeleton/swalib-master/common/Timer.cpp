#include "Timer.h"


void Timer::Initialize()
{
	QueryPerformanceFrequency(&iFrecuency);
	QueryPerformanceCounter(&iCounter);
	iPreviousCount = iCounter.QuadPart;
	iCurrentCount = iPreviousCount;
}


void Timer::InitSlotsToProcess()
{
	QueryPerformanceCounter(&iCounter);
	iCurrentCount = iCounter.QuadPart;
	long long int iDeltaCount = iCurrentCount - iPreviousCount;
	iPreviousCount = iCurrentCount;
	float fRealDeltaTime = (float)iDeltaCount / (float)iFrecuency.QuadPart;
	fDeltaTime += fRealDeltaTime;
	fTotalTime += fRealDeltaTime;


	sMessageFrames = "FPS:";
	std::string sTemp = std::to_string(1. / fDeltaTime);
	sTemp.resize(5);
	sMessageFrames += sTemp;
	sMessageFrames += " TIME:";
	sTemp = std::to_string(fTotalTime);
	sTemp.resize(5);
	sMessageFrames += sTemp;

	if (fDeltaTime > 1. / 15.)
	{
		fDeltaTime = 1. / 15.;
	}

	printf("%f", fVirtualTimeFactor);
	fVirtualTime = fVirtualTimeFactor * fDeltaTime;

}

bool Timer::ProcessSlots()
{ 
	if(fVirtualTime > fFixedTime)
	{
		printf("true vt");
		fLogicTime += fFixedTime;
		fVirtualTime -= fFixedTime;
		fDeltaTime = fVirtualTime / fVirtualTimeFactor;
		return true;
	}
	else
	{
		return false;
	}

}
float Timer::GetFixedTime()
{
	return fFixedTime;
}
std::string Timer::GetMessageFrames()
{
	sMessageFrames += " LOGIC TIME:";
	std::string sTemp = std::to_string(fLogicTime);
	sTemp.resize(5);
	sMessageFrames += sTemp;
	return sMessageFrames;
}