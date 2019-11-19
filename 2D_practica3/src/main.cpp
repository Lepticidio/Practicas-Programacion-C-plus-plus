
#define LITE_GFX_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION

#include "..\project\Text.h"

using namespace std;

int iWidth = 1000;
int iHeight = 1000;

bool SlotAvailable(bool* bBoolArray, int iArraySize)
{
	bool bResult = false;
	for (int i = 0; i < iArraySize; i++)
	{
		if (!bBoolArray[i])
		{
			bResult = true;
		}
	}
	return bResult;
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

	double deltaTime = 0;
	double previousTime = glfwGetTime();
	double dXMouse = 0;
	double dYMouse = 0;
	double* pXMouse = &dXMouse;
	double* pYMouse = &dYMouse;


	 Font* pFont1 = Font::load("SFSlapstickComic.ttf", 96);
	 Font* pFont2 = Font::load("Orange.ttf", 96);

	 const int iMaxNumberMessages = 4;

	 Text* oMessages [iMaxNumberMessages];
	 bool bActivedMessages[iMaxNumberMessages]{ false };


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
			char* sMessage = new char[12];
			sMessage = "Hello world";
			printf("sMessage is %s \n", sMessage);
			float fR = (float)(rand() % 255) / (float)255;
			float fG = (float)(rand() % 255) / (float)255;
			float fB = (float)(rand() % 255) / (float)255;

			//Text text(sMessage, Vec2(iWidth, 500), *pFont, (rand() % 255) / 255, (rand() % 255)/255, (rand() % 255) / 255, rand() % 180 + 20);
			
			for (int i = 0; i < iMaxNumberMessages; i++)
			{
				printf("iteración %d  de %d\n", i, iMaxNumberMessages);
				if (oMessages == nullptr || !bActivedMessages[i])
				{
					printf("%d es sobreescrito\n", i);
					//Text* pText = new Text(sMessage, Vec2(iWidth, 500), *pFont, fR, fG, fB, rand() % 180 + 20);
					Text* pText = new Text(sMessage, Vec2(iWidth, 500), *pFont, 1., 1., 1., rand() % 180 + 20);
					oMessages[i] = pText;
					bActivedMessages[i] = true;
					i = iMaxNumberMessages;
				}
			}

			

		}

		//5.4) Limpiamos el backbuffer
		lgfx_clearcolorbuffer(0.f, 0.f, 0.f);

		//5.5) Renderizamos la escena.
		lgfx_setblend(BLEND_ALPHA);
		for (int i = 0; i < iMaxNumberMessages; i++)
		{
			if (oMessages != nullptr && bActivedMessages[i])
			{
				printf("sText de oMessage es %s\n", oMessages[i]->sText);
				printf("drawing text %d\n", i);
				oMessages[i]->vPosition.x -= oMessages[i]->fSpeed * deltaTime;
				printf("x del texto %d es %f", i, oMessages[i]->vPosition.x);
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
