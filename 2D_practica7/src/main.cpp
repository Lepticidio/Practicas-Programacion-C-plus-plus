
#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include "World.h"

using namespace std;

int iWidth = 800;
int iHeight = 800;

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
	int iWidthRun = 0;
	int iHeighRun = 0;
	int iWidthClouds = 0;
	int iHeightClouds = 0;
	double deltaTime = 0;
	double previousTime = glfwGetTime();

	double dXMouse = 0;
	double dYMouse = 0;
	double* pXMouse = &dXMouse;
	double* pYMouse = &dYMouse;

	unsigned char* sRunBytes = stbi_load("data//run.png", &iWidthRun, &iHeighRun, nullptr, 4);
	ltex_t* pTextureRun = nullptr;
	pTextureRun = ltex_alloc(iWidthRun, iHeighRun, 1);
	ltex_setpixels(pTextureRun, sRunBytes);
	stbi_image_free(sRunBytes);

	Sprite player(pTextureRun, 6, 1);
	player.setPivot(Vec2(0.5f, 0.5f));
	player.setFps(6);
	player.setCallback(SpriteCallback);


	unsigned char* sCloudsBytes = stbi_load("data//clouds.png", &iWidthClouds, &iHeightClouds, nullptr, 4);
	ltex_t* pTextureClouds = nullptr;
	pTextureClouds = ltex_alloc(iWidthClouds, iHeightClouds, 1);
	ltex_setpixels(pTextureClouds, sCloudsBytes);
	stbi_image_free(sCloudsBytes);

	World world(0.8f, 0.8f, 0.8f, pTextureClouds);
	world.addSprite(player);
	world.loadMap("data//map.tmx", 1);

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