
#include "Render.h"

Logic logic;
Render render;



void Initialization()
{
	logic.Initialize();
	render.Initialize(logic);
}

void Shutdown()
{
	render.Shutdown();
	// End app.
	FONT_End();

}

//-----------------------------------------------------------------------------
int Main(void)
{
	LARGE_INTEGER iFrecuency ;
	LARGE_INTEGER iCounter ;
	QueryPerformanceFrequency(&iFrecuency);
	QueryPerformanceCounter(&iCounter);
	long long int iPreviousCount = iCounter.QuadPart;
	long long int iCurrentCount = iPreviousCount;
	float fFixedTime = 1. / 60.;
	float fDeltaTime = 0;
	float fTotalTime = 0;
	float fLogicTime = 0;
	float fRoundedTime = 0;
	Initialization();
	while (!SYS_GottaQuit()) // Controlling a request to terminate an application.
	{
		QueryPerformanceCounter(&iCounter);
		iCurrentCount = iCounter.QuadPart;
		long long int iDeltaCount = iCurrentCount - iPreviousCount;
		iPreviousCount = iCurrentCount;
		float fRealDeltaTime = (float)iDeltaCount / (float)iFrecuency.QuadPart;
		fDeltaTime += fRealDeltaTime;
		fTotalTime += fRealDeltaTime; 
		

		std::string sMessageFrames = "FPS: ";
		sMessageFrames += std::to_string(1. / fDeltaTime);
		sMessageFrames += " \nTOTAL TIME: ";
		sMessageFrames += std::to_string(fTotalTime);

		while (fDeltaTime > fFixedTime)
		{
			
			fRoundedTime = floor(fTotalTime * 100.)/100.;
			logic.Update();
			fLogicTime += fFixedTime;
			fDeltaTime -= fFixedTime;

		}
		sMessageFrames += " \nLOGIC TIME: ";
		sMessageFrames += std::to_string(fLogicTime);
		render.Update(logic, sMessageFrames);


		
	}
	Shutdown();
	return 0;
}
