
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
	Timer timer;
	timer.Initialize();
	Initialization();
	while (!SYS_GottaQuit()) // Controlling a request to terminate an application.
	{
		timer.InitSlotsToProcess();
		while (timer.ProcessSlots())
		{			
			logic.Update(timer.GetFixedTime());
		}
		render.Update(logic, timer.GetMessageFrames());
		//SYS_Sleep(17);


		
	}
	Shutdown();
	return 0;
}
