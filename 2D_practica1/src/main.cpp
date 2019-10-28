
#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include <Vec2.h>

using namespace std;


Vec2 abs(Vec2 const& obj)
{
	Vec2 res;
	res.x = abs(obj.x);
	res.y = abs(obj.y);
	return res;
}


ostream& operator<<(ostream& os, const Vec2& v)
{
	os << '(';
	os << v.x;
	os << ',';
	os << v.y;
	os << ')';


	return os;
}

void CheckVec2Methods()
{

	Vec2 v1 = Vec2(1, 2);
	Vec2 v2 = Vec2(3, 4);
	Vec2 v3 = Vec2(-4, 3);
	Vec2 v4 = Vec2(-4000, 3005);
	Vec2 v5 = Vec2(8, 4);
	std::cout << v2 << " + " << 4 << " = " << v2 + 4 << std::endl;
	std::cout << v2 << " + " << v1 << " = " << v2 + v1 << std::endl;
	std::cout << v2 << " - " << 4 << " = " << v2 - 4 << std::endl;
	std::cout << v2 << " - " << v1 << " = " << v2 - v1 << std::endl;
	std::cout << v2 << " * " << 4 << " = " << v2 * 4 << std::endl;
	std::cout << v2 << " * " << v1 << " = " << v2 * v1 << std::endl;
	std::cout << v2 << " / " << 4 << " = " << v2 / 4 << std::endl;
	std::cout << v2 << " / " << v1 << " = " << v2 / v1 << std::endl;
	std::cout << v3 << " Abs: " << abs(v3) << std::endl;
	std::cout << v2 << " Length: " << v2.Length() << std::endl;
	std::cout << v2 << " Normalized: " << v2.Normalize() << std::endl;
	std::cout << "Dot product of " << v2 << " and " << v1 << " = " << v2.Dot(v1) << std::endl;
	std::cout << "Angle of " << v2 << " and " << v1 << " = " << v2.Angle(v1) << std::endl;
	std::cout << "Angle of " << v2 << " and " << v3 << " = " << v2.Angle(v3) << std::endl;
	std::cout << "Angle of " << v2 << " and " << v4 << " = " << v2.Angle(v4) << std::endl;
	std::cout << "Angle of " << v2 << " and " << -v2 << " = " << v2.Angle(-v2) << std::endl;
	std::cout << "Distance of " << v2 << " and " << v5 << " = " << v2.Distance(v5) << std::endl;
	std::cout << "Rotate " << v2 << " " << 90 << " degrees = " << v2.Rotate(90) << std::endl;
	std::cout << "Rotate " << v2 << " " << 180 << " degrees = " << v2.Rotate(180) << std::endl;
}



int main() {
	
	// Uncomment below line to check in console that all Vec2 methods work properly
	CheckVec2Methods();

	//1) Iniciamos la librería GFWX
	glfwInit();

	//2) Creamos una ventana
	GLFWwindow* pWindow = glfwCreateWindow(1000, 1000, "", nullptr, nullptr);

	//3) Asociamos el contexto de OpenGL a la ventana
	glfwMakeContextCurrent(pWindow);

	//4) Iniciamos la librería LiteGFX
	lgfx_setup2d(1000, 1000);

	bool bOpen = true;
	double previousTime = glfwGetTime();
	double deltaTime = 0;
	float fSquareSize = 100;
	float fCircleSize = 100;
	float fDistance = 150;
	double dXMouse = 0;
	double dYMouse = 0;
	double* pXMouse = &dXMouse;
	double* pYMouse = &dYMouse;
	Vec2 vPosCursor;
	Vec2 vDirectionCircle (fDistance, 0);
	Vec2 vPosCircle;

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
		glfwGetCursorPos(pWindow, pXMouse,	pYMouse);

		//5.3) Actualizamos lógica de juego
		vPosCursor.x = (float)dXMouse;
		vPosCursor.y = (float)dYMouse;

		vDirectionCircle = vDirectionCircle.Rotate(32.f*(float)deltaTime);
		vPosCircle = vPosCursor + vDirectionCircle;

		std::cout <<" deltaTime " << deltaTime << " posCursor " << vPosCursor << " dirCircle " << vDirectionCircle << " poscircle " << vPosCircle << std::endl;

		//5.4) Limpiamos el backbuffer
		lgfx_clearcolorbuffer(0.5f, 0.5f, 0.5f);

		//5.5) Renderizamos la escena.
		lgfx_setcolor(0.9f, 0.6f, 0.5f, 1);
		lgfx_drawrect(450, 450, fSquareSize, fSquareSize);
		if (pXMouse != nullptr && pYMouse != nullptr)
		{
			lgfx_setcolor(0.5f, 0.9f, 0.6f, 1);
			lgfx_drawrect(dXMouse-fSquareSize/2, dYMouse-fSquareSize/2, fSquareSize, fSquareSize);
			lgfx_setcolor(0.6f, 0.5f, 0.9f, 1);
			lgfx_drawoval(vPosCircle.x - fCircleSize / 2, vPosCircle.y - fCircleSize / 2, fCircleSize, fCircleSize);
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
