#include "Render.h"
void Render::Initialize(const Logic& _logic)
{
	texbkg = new GLuint;
	texsmallball = new GLuint;
	FONT_Init();	// Characters and symbols inicialization to draw on screen.

	// Load textures
	*texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	*texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);

	// Set up rendering.
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Specifies clear values for the color buffers.
	glMatrixMode(GL_PROJECTION);	// Specifies projection matrix is the current matrix.
	glLoadIdentity();	// Replaces the current matrix with the identity matrix.
	glOrtho(0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);	// Multiplies the current matrix by an orthographic matrix.
	glEnable(GL_TEXTURE_2D);	// Enabling two-dimensional texturing.
	// NOTA: Mirar diferencias comentando las 2 siguientes funciones.
	glEnable(GL_BLEND);	// Blend the incoming RGBA color values with the values in the color buffers.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Blend func. for alpha color.
	for (int i = 0; i < _logic.NUM_BALLS; i++)
	{
		_logic.balls[i].gfx = *texsmallball;
	}


}
void Render::Update(const Logic &_logic)
{
	// Render
	glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.

	// Render backgground
	for (int i = 0; i <= SCR_WIDTH / 128; i++)
	{
		for (int j = 0; j <= SCR_HEIGHT / 128; j++)
		{
			CORE_RenderCenteredSprite(vmake(i * 128.f + 64.f, j * 128.f + 64.f), vmake(128.f, 128.f), *texbkg);
		}
	}

	// Render balls
	for (int i = 0; i < _logic.NUM_BALLS; i++)
	{
		CORE_RenderCenteredSprite(_logic.balls[i].pos, vmake(_logic.balls[i].radius * 2.f, _logic.balls[i].radius * 2.f), _logic.balls[i].gfx);
	}

	// Text
	FONT_DrawString(vmake(SCR_WIDTH / 2 - 6 * 16, 16), "HELLO WORLD!");

	// Exchanges the front and back buffers
	SYS_Show();

	SYS_Pump();	// Process Windows messages.
	SYS_Sleep(17);	// To force 60 fps

}

void Render::Shutdown()
{
	// Unload textures.
	CORE_UnloadPNG(*texbkg);
	CORE_UnloadPNG(*texsmallball);

}