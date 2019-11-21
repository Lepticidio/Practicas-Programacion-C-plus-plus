
#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include "Sprite.h"
#include <stb_image.h>


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
	int iWidthWasp = 0;
	int iHeightWasp = 0;
	double deltaTime = 0;
	double previousTime = glfwGetTime();
	double dXMouse = 0;
	double dYMouse = 0;
	double* pXMouse = &dXMouse;
	double* pYMouse = &dYMouse;

	unsigned char* sWaspBytes = stbi_load("data//wasp_anim.png", &iWidthWasp, &iHeightWasp, nullptr, 4);
	ltex_t* pTextureWasp = nullptr;
	pTextureWasp = ltex_alloc(iWidthWasp, iHeightWasp, 1);
	ltex_setpixels(pTextureWasp, sWaspBytes);
	stbi_image_free(sWaspBytes);

	Sprite wasp(pTextureWasp, 8, 1);

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

		wasp.setPosition(Vec2(dXMouse, dYMouse));

		//5.4) Limpiamos el backbuffer
		lgfx_clearcolorbuffer(0, 0, 0);

		//5.5) Renderizamos la escena.
		wasp.draw();

		//5.6) Cambiamos el backbuffer por el frontbuffer
		glfwSwapBuffers(pWindow);

		//5.7) Procesamos eventos
		glfwPollEvents();

	}
	//6) Liberamos los recursos.
	glfwTerminate();
	

		

    return 0;
}
