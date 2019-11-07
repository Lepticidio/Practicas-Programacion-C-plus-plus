// Practica11.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "List.h"

int main()
{
	TList tList;
	printf("Size = %d (debería ser 0)\n", tList.Size());
	tList.Push("Uno");
	tList.Push("Dos");
	tList.Push("Tres");
	tList.Push("Cuatro");
	tList.Push("Cinco");
	printf("Size = %d (debería ser 5)\n", tList.Size());

	TList tList2 (tList);

	const char* sPop = tList.Pop();


	TList tReverseList;
	tList.GetReverseList(tList, tReverseList);
	printf("Pop = %s (debería ser Cinco)\n", sPop);
	printf("Size = %d (debería ser 4)\n", tList.Size());

	const char* sCurrentValue = tList.First();
	unsigned int uIndex(0);
	while (sCurrentValue != nullptr)
	{
		printf("original tList %d ->  %s \n", uIndex, sCurrentValue);
		uIndex++;
		sCurrentValue = tList.Next();
	}
	uIndex = 0;
	sCurrentValue = tList2.First();
	while (sCurrentValue != nullptr)
	{
		printf("tList2 %d ->  %s \n", uIndex, sCurrentValue);
		uIndex++;
		sCurrentValue = tList2.Next();
	}
	uIndex = 0;
	sCurrentValue = tReverseList.First();
	while (sCurrentValue != nullptr)
	{
		printf("tReverseList %d ->  %s \n", uIndex, sCurrentValue);
		uIndex++;
		sCurrentValue = tReverseList.Next();
	}
	printf("tList: Antes del reset size = %d (debería ser 4)\n", tList.Size());
	printf("tList2: Antes del reset size = %d (debería ser 5)\n", tList2.Size());
	tList.Reset();
	printf("Tras reset size = %d (debería ser 0)\n", tList.Size());

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
