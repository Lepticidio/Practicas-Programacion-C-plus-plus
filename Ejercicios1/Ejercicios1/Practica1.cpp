// Ejercicios1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

struct SPruebaBools
{
	bool bA, bB, bC, bD;
};
struct SPruebaInts
{
	int iA;
};

int main()
{
	bool bTest01 = 0;
	bool bTest02 = 1;
	bool bTest03 = (bool)7;

	std::cout << "bTest01: " << bTest01 << std::endl;
	std::cout << "bTest02: " << bTest02 << std::endl;
	std::cout << "bTest03: " << bTest03 << std::endl;

	int iTest01 = (int)3.7f;
	
	std::cout << "iTest01: " << iTest01 << std::endl;

	unsigned char uTest01 = 255u;
	unsigned char uTest02 = 256u;
	unsigned char uTest03 = 255u;
	++uTest03;

	printf("uTest01: ");

	unsigned u = 10;
	int i = -42;

	std::cout << "i + i : " << i + +i << std:endl;
	std::cout << "u + i : " << u + +i << std:endl;
	std::cout << "i + u : " << i + u << std:endl;

	bool bTest02 = 0;
	bool bTest03 = 0;
	bool bTest04 = 0;




}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
