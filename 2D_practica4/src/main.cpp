
#define LITE_GFX_IMPLEMENTATION


#include "Sprite.h"


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


		//5.4) Limpiamos el backbuffer
		lgfx_clearcolorbuffer(0, 0, 0);

		//5.5) Renderizamos la escena.


		lgfx_setblend(BLEND_ALPHA);

		lgfx_setcolor(1, 1, 1, 1);

		//5.6) Cambiamos el backbuffer por el frontbuffer
		glfwSwapBuffers(pWindow);

		//5.7) Procesamos eventos
		glfwPollEvents();

	}
	//6) Liberamos los recursos.
	glfwTerminate();
	

		

    return 0;
}
