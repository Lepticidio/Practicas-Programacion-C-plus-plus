
#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include "World.h"

using namespace std;

int iWidth = 1200;
int iHeight = 600;

Vec2 vMousePos;

void SpriteCallback(Sprite& _sprite, float _deltaTime)
{
	Vec2 vCurrentPosition = _sprite.getPosition();
	Vec2 vDir = vMousePos - vCurrentPosition;
	Vec2 vVelocity = vDir.Resize(128 * _deltaTime);

	float fRotationSpeed = 32 * _deltaTime;

	float fAngle = _sprite.getAngle();
	if (vDir.Length() > 10 && vDir.x > 0 && fAngle > -15)
	{
		_sprite.setAngle(fAngle - fRotationSpeed);
	}
	else if (vDir.Length() > 10 && vDir.x < 0 && fAngle < 15)
	{
		_sprite.setAngle(fAngle + fRotationSpeed);
	}
	else if (fAngle > 0)
	{
		_sprite.setAngle(fAngle - fRotationSpeed);
	}
	else if (fAngle < 0)
	{
		_sprite.setAngle(fAngle + fRotationSpeed);
	}

	_sprite.setPosition(vCurrentPosition + vVelocity);
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
	int iWidthLevel = 0;
	int iHeightLevel = 0;
	int iWidthTrees1 = 0;
	int iHeightTrees1 = 0;
	int iWidthTrees2 = 0;
	int iHeightTrees2 = 0;
	int iWidthClouds = 0;
	int iHeightClouds = 0;
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
	wasp.setPivot(Vec2(0.5f, 0.5f));
	wasp.setFps(8);
	wasp.setCallback(SpriteCallback);

	unsigned char* sLevelBytes = stbi_load("data//level.png", &iWidthLevel, &iHeightLevel, nullptr, 4);
	ltex_t* pTextureLevel = nullptr;
	pTextureLevel = ltex_alloc(iWidthLevel, iHeightLevel, 1);
	ltex_setpixels(pTextureLevel, sLevelBytes);
	stbi_image_free(sLevelBytes);

	unsigned char* sTrees1 = stbi_load("data//trees1.png", &iWidthTrees1, &iHeightTrees1, nullptr, 4);
	ltex_t* pTextureTrees1 = nullptr;
	pTextureTrees1 = ltex_alloc(iWidthTrees1, iHeightTrees1, 1);
	ltex_setpixels(pTextureTrees1, sTrees1);
	stbi_image_free(sTrees1);

	unsigned char* sTrees2 = stbi_load("data//trees2.png", &iWidthTrees2, &iHeightTrees2, nullptr, 4);
	ltex_t* pTextureTrees2 = nullptr;
	pTextureTrees2 = ltex_alloc(iWidthTrees2, iHeightTrees2, 1);
	ltex_setpixels(pTextureTrees2, sTrees2);
	stbi_image_free(sTrees2);

	unsigned char* sCloudsBytes = stbi_load("data//clouds.png", &iWidthClouds, &iHeightClouds, nullptr, 4);
	ltex_t* pTextureClouds = nullptr;
	pTextureClouds = ltex_alloc(iWidthClouds, iHeightClouds, 1);
	ltex_setpixels(pTextureClouds, sCloudsBytes);
	stbi_image_free(sCloudsBytes);

	World world(0.8f, 0.8f, 0.8f, pTextureLevel, pTextureTrees1, pTextureTrees2, pTextureClouds);
	world.addSprite(wasp);

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
		vMousePos = Vec2(dXMouse, dYMouse);
		vMousePos = vMousePos + world.getCameraPosition();

		//5.3) Actualizamos lógica de juego
		world.update(deltaTime);

		//5.4-5) Limpiamos el backbuffer y renderizamos la escena.
		world.draw(Vec2(iWidth, iHeight));

		//5.6) Cambiamos el backbuffer por el frontbuffer
		glfwSwapBuffers(pWindow);

		//5.7) Procesamos eventos
		glfwPollEvents();
	}
	//6) Liberamos los recursos.
	glfwTerminate();

	return 0;
}