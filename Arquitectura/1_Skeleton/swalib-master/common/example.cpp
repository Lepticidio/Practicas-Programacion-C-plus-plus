
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
	Initialization();
	while (!SYS_GottaQuit()) // Controlling a request to terminate an application.
	{	
		logic.Update();
		render.Update(logic);
	}
	Shutdown();
	return 0;
}
