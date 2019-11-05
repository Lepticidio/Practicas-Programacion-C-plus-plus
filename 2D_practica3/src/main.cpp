
#define LITE_GFX_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <stb_truetype.h>
#include <iostream>
#include "..\project\Font.h"
#include "..\project\Text.h"

using namespace std;

int iWidth = 1000;
int iHeight = 1000;

int main() 
{

	//1) Iniciamos la librería GFWX
	glfwInit();

	//2) Creamos una ventana
	GLFWwindow* pWindow = glfwCreateWindow(iWidth, iHeight, "", nullptr, nullptr);

	//3) Asociamos el contexto de OpenGL a la ventana
	glfwMakeContextCurrent(pWindow);

	//4) Iniciamos la librería LiteGFX
	lgfx_setup2d(iWidth, iHeight);

	bool bOpen = true;

	double deltaTime = 0;
	double previousTime = glfwGetTime();
	double dXMouse = 0;
	double dYMouse = 0;
	double* pXMouse = &dXMouse;
	double* pYMouse = &dYMouse;


	 Font* pFont1 = Font::load("SFSlapstickComic.ttf", 1);
	 Font* pFont2 = Font::load("Orange.ttf", 1);

	 const int iMaxNumberMessages = 200;

	 Text* oMessages [iMaxNumberMessages];


	//5) Bucle principal
	while (!glfwWindowShouldClose(pWindow) && bOpen)
	{
		//5.1) Actualizamos delta de tiempo
		deltaTime = glfwGetTime() - previousTime;
		previousTime = glfwGetTime();

		//5.2) Leemos input del usuario
		if (glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			bOpen = false;
		}
		glfwGetCursorPos(pWindow, pXMouse, pYMouse);

		//5.3) Actualizamos lógica de juego

		if (rand() % 100 == 0)
		{
			Font* pFont;
			if (rand() % 2 == 0)
			{
				pFont = pFont1;
			}
			else
			{
				pFont = pFont2;
			}

			int iHeightMessage = rand() % iHeight;

			Text text("Hello World", Vec2(iWidth, iHeightMessage), *pFont, (rand() % 255) / 255, (rand() % 255)/255, (rand() % 255) / 255, rand() % 180 + 20);
			for (int i = 0; i < iMaxNumberMessages; i++)
			{
				if (oMessages == nullptr || !oMessages[i]->active)
				{
					oMessages[i] = &text;
				}
			}

		}

		//5.4) Limpiamos el backbuffer
		lgfx_clearcolorbuffer(1, 1, 1);

		//5.5) Renderizamos la escena.
		for (int i = 0; i < iMaxNumberMessages; i++)
		{
			if (oMessages != nullptr && oMessages[i]->active)
			{
				oMessages[i]->vPosition.x += oMessages[i]->fSpeed * deltaTime;
				oMessages[i]->Draw();
			}
		}


		//5.6) Cambiamos el backbuffer por el frontbuffer
		glfwSwapBuffers(pWindow);

		//5.7) Procesamos eventos
		glfwPollEvents();

	}
	//6) Liberamos los recursos.

	glfwTerminate();
	

		

    return 0;
}
