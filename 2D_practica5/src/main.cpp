
#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include "Sprite.h"
#include <stb_image.h>


using namespace std;


int iWidth = 1000;
int iHeight = 1000;

Vec2 vMousePos;

void MouseSpriteCallback(Sprite& _sprite, float _deltaTime)
{
	_sprite.setPosition(vMousePos);
}

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
	int iWidthBall = 0;
	int iHeightBall = 0;
	int iWidthBox = 0;
	int iHeightBox = 0;
	int iWidthCircle = 0;
	int iHeightCircle = 0;
	int iWidthRect = 0;
	int iHeightRect = 0;
	double deltaTime = 0;
	double previousTime = glfwGetTime();

	double dXMouse = 0;
	double dYMouse = 0;
	double* pXMouse = &dXMouse;
	double* pYMouse = &dYMouse;

	unsigned char* sWaspBytes = stbi_load("data//wasp.png", &iWidthWasp, &iHeightWasp, nullptr, 4);
	ltex_t* pTextureWasp = nullptr;
	pTextureWasp = ltex_alloc(iWidthWasp, iHeightWasp, 1);
	ltex_setpixels(pTextureWasp, sWaspBytes);
	stbi_image_free(sWaspBytes);

	Sprite wasp(pTextureWasp, 1, 1);
	wasp.setPosition(Vec2(500, 500));

	unsigned char* sBallBytes = stbi_load("data//ball.png", &iWidthBall, &iHeightBall, nullptr, 4);
	ltex_t* pTextureBall = nullptr;
	pTextureBall = ltex_alloc(iWidthBall, iHeightBall, 1);
	ltex_setpixels(pTextureBall, sBallBytes);
	stbi_image_free(sBallBytes);

	Sprite ball(pTextureBall, 1, 1);
	ball.setPosition(Vec2(250, 500));

	unsigned char* sBoxBytes = stbi_load("data//box.png", &iWidthBox, &iHeightBox, nullptr, 4);
	ltex_t* pTextureBox = nullptr;
	pTextureBox = ltex_alloc(iWidthBox, iHeightBox, 1);
	ltex_setpixels(pTextureBox, sBoxBytes);
	stbi_image_free(sBoxBytes);

	Sprite box(pTextureBox, 1, 1);
	box.setPosition(Vec2(750, 500));

	unsigned char* sCircleBytes = stbi_load("data//circle.png", &iWidthCircle, &iHeightCircle, nullptr, 4);
	ltex_t* pTextureCircle = nullptr;
	pTextureCircle = ltex_alloc(iWidthCircle, iHeightCircle, 1);
	ltex_setpixels(pTextureCircle, sCircleBytes);
	stbi_image_free(sCircleBytes);

	Sprite mouseSprite(pTextureCircle, 1, 1);
	mouseSprite.setCallback(MouseSpriteCallback);

	unsigned char* sRectBytes = stbi_load("data//rect.png", &iWidthRect, &iHeightRect, nullptr, 4);
	ltex_t* pTextureRect = nullptr;
	pTextureRect = ltex_alloc(iWidthRect, iHeightRect, 1);
	ltex_setpixels(pTextureRect, sRectBytes);
	stbi_image_free(sRectBytes);

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
		int state = glfwGetMouseButton(pWindow, GLFW_MOUSE_BUTTON_LEFT);
		if (state == GLFW_PRESS)
		{
			mouseSprite.setTexture(pTextureCircle, 1, 1);
			mouseSprite.setCollisionType(COLLISION_CIRCLE);
		}
		state = glfwGetMouseButton(pWindow, GLFW_MOUSE_BUTTON_RIGHT);
		if (state == GLFW_PRESS)
		{
			mouseSprite.setTexture(pTextureRect, 1, 1);
			mouseSprite.setCollisionType(COLLISION_RECT);
		}
		state = glfwGetMouseButton(pWindow, GLFW_MOUSE_BUTTON_MIDDLE);
		if (state == GLFW_PRESS)
		{
			mouseSprite.setTexture(pTextureWasp, 1, 1);
			mouseSprite.setCollisionType(COLLISION_PIXELS);
		}
		glfwGetCursorPos(pWindow, pXMouse, pYMouse);
		vMousePos = Vec2(dXMouse, dYMouse);

		//5.3) Actualizamos lógica de juego
		mouseSprite.update(deltaTime);

		//5.4) Limpiamos el backbuffer
		lgfx_clearcolorbuffer(0, 0, 0);

		//5.5) Renderizamos la escena.
		wasp.draw();
		ball.draw();
		box.draw();
		mouseSprite.draw();

		//5.6) Cambiamos el backbuffer por el frontbuffer
		glfwSwapBuffers(pWindow);

		//5.7) Procesamos eventos
		glfwPollEvents();

	}
	//6) Liberamos los recursos.
	glfwTerminate();




	return 0;
}