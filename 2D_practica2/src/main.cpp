
#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include <stb_image.h>

using namespace std;

int iWidth = 1000;
int iHeight = 1000;

void DrawTileable(ltex_t* pTexture)
{
	ltex_t texture = *pTexture;
	for (int i = 0; i < iWidth / texture.width + 1; i++)
	{
		for (int j = 0; j < iHeight / texture.height + 1; j++)
		{
			ltex_draw(pTexture, i*texture.width, j*texture.height);
		}
	}
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
	
	int iWidthWall = 0;
	int iHeightWall = 0;
	int iWidthGrille = 0;
	int iHeightGrille = 0;
	int iWidthFire = 0;
	int iHeightFire = 0;
	int iWidthLight = 0;
	int iHeightLight= 0;
	float fFireRotSpeed = 10;
	float fFireScaleSpeed = 0.5f;
	float fFireAngle = 0;
	float fFireMaxAngle = 10;
	float fFireMinAngle = -10;
	float fFireScale = 1;
	float fFireMaxScale = 1.2f;
	float fFireMinScale = 0.8f;
	double deltaTime = 0;
	double previousTime = glfwGetTime();
	double dXMouse = 0;
	double dYMouse = 0;
	double* pXMouse = &dXMouse;
	double* pYMouse = &dYMouse;
	unsigned char* sWallBytes = stbi_load("resources/wall.jpg", &iWidthWall, &iHeightWall, nullptr, 4);
	unsigned char* sGrilleBytes = stbi_load("resources/grille.png", &iWidthGrille, &iHeightGrille, nullptr, 4);
	unsigned char* sFireBytes = stbi_load("resources/fire.png", &iWidthFire, &iHeightFire, nullptr, 4);
	unsigned char* sLightBytes = stbi_load("resources/light.png", &iWidthLight, &iHeightLight, nullptr, 4);



	if (sWallBytes == nullptr)
	{
		printf("is null\n");
	}
	else
	{
		printf("cargado con exito\n");

	}
	ltex_t* pTextureWall = nullptr;
	ltex_t* pTextureGrille = nullptr;
	ltex_t* pTextureFire = nullptr;
	ltex_t* pTextureLight = nullptr;
	pTextureWall = ltex_alloc(iWidthWall, iHeightWall, 1);
	pTextureGrille = ltex_alloc(iWidthGrille, iHeightGrille, 1);
	pTextureFire = ltex_alloc(iWidthFire, iHeightFire, 1);
	pTextureLight = ltex_alloc(iWidthLight, iHeightLight, 1);
	ltex_setpixels(pTextureWall, sWallBytes);
	ltex_setpixels(pTextureGrille, sGrilleBytes);
	ltex_setpixels(pTextureFire, sFireBytes);
	ltex_setpixels(pTextureLight, sLightBytes);
	stbi_image_free(sWallBytes);
	stbi_image_free(sGrilleBytes);
	stbi_image_free(sFireBytes);
	stbi_image_free(sLightBytes);
	ltex_t textureFire = *pTextureFire;
	ltex_t textureLight = *pTextureLight;

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
		fFireAngle += fFireRotSpeed*deltaTime;
		if (fFireAngle > fFireMaxAngle)
		{
			fFireAngle = fFireMaxAngle;
			fFireRotSpeed *= -1;
		}
		else if (fFireAngle < fFireMinAngle)
		{
			fFireAngle = fFireMinAngle;
			fFireRotSpeed *= -1;
		}
		fFireScale += fFireScaleSpeed * deltaTime;
		if (fFireScale > fFireMaxScale)
		{
			fFireScale = fFireMaxScale;
			fFireScaleSpeed *= -1;
		}
		else if (fFireScale < fFireMinScale)
		{
			fFireScale = fFireMinScale;
			fFireScaleSpeed *= -1;
		}

		//5.4) Limpiamos el backbuffer
		lgfx_clearcolorbuffer(1,1,1);

		//5.5) Renderizamos la escena.

		DrawTileable(pTextureWall);
		lgfx_setblend(BLEND_ALPHA);
		printf("scale: %f rotation: %f \n", fFireScale, fFireAngle);
		//ltex_drawrotsized(pTextureFire, dXMouse - textureFire.width/2, dYMouse - textureFire.height / 2, fFireAngle, 0.5f, 0.5f, fFireScale, fFireScale, 0, 0, 1, 1);
		//ltex_drawrot(pTextureFire, dXMouse, dYMouse, fFireAngle, 0.5f, 0.8f);
		ltex_drawrotsized(pTextureFire, dXMouse, dYMouse, fFireAngle, 0.5f, 0.8f, fFireScale*textureFire.width, fFireScale*textureFire.height, 0, 0, 1, 1);
		DrawTileable(pTextureGrille);
		lgfx_setblend(BLEND_MUL);
		ltex_drawrotsized(pTextureLight, dXMouse, dYMouse, 0, 0.5f, 0.5f, fFireScale*textureLight.width, fFireScale*textureLight.height, 0, 0, 1, 1);
		lgfx_setblend(BLEND_SOLID);
		lgfx_setcolor(0, 0, 0, 1);
		lgfx_drawrect(dXMouse + fFireScale * textureLight.width / 2, dYMouse - iHeight, iWidth * 2, iHeight * 2);
		lgfx_drawrect(dXMouse - fFireScale * textureLight.width / 2- iWidth*2, dYMouse - iHeight, iWidth*2, iHeight * 2);
		lgfx_drawrect(dXMouse - iWidth, dYMouse + fFireScale * textureLight.height / 2, iWidth*2, iHeight * 2);
		lgfx_drawrect(dXMouse - iWidth, dYMouse - fFireScale * textureLight.height / 2 - iHeight*2, iWidth * 2, iHeight * 2);
		lgfx_setcolor(1, 1, 1, 1);

		//5.6) Cambiamos el backbuffer por el frontbuffer
		glfwSwapBuffers(pWindow);

		//5.7) Procesamos eventos
		glfwPollEvents();

	}
	//6) Liberamos los recursos.
	ltex_free(pTextureWall);
	ltex_free(pTextureGrille);
	ltex_free(pTextureFire);
	ltex_free(pTextureLight);
	glfwTerminate();
}
