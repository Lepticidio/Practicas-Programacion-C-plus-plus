
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
	float fDeltaTime = 0;
	float fTotalTime = 0;
	float fLogicTime = 0;
	float fVirtualTimeFactor = 1.;
	float fFixedTime = 1. / 60. ;
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
		

		std::string sMessageFrames = "FPS:";
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
		float fVirtualTime = fVirtualTimeFactor * fDeltaTime;
		while (fVirtualTime > fFixedTime)
		{			
			logic.Update(fFixedTime);
			fLogicTime += fFixedTime;
			fVirtualTime -= fFixedTime;
			fDeltaTime = fVirtualTime / fVirtualTimeFactor;
		}
		sMessageFrames += " LOGIC TIME:";
		sTemp = std::to_string(fLogicTime);
		sTemp.resize(5);
		sMessageFrames += sTemp;
		render.Update(logic, sMessageFrames);
		//SYS_Sleep(17);


		
	}
	Shutdown();
	return 0;
}
