// Practica11.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//


#include "List.h"
int main()
{
	TList<const char*> tList;

	printf("Size = %d (deber�a ser 0)\n", tList.Size());
	tList.Push("Uno");
	tList.Push("Dos");
	tList.Push("Tres");
	tList.Push("Cuatro");
	tList.Push("Cinco");
	printf("Size = %d (deber�a ser 5)\n", tList.Size());

	TList<const char*> tList2(tList);

	const char* sPop = tList.Pop();


	TList<const char*> tReverseList;
	tList.GetReverseList(tList, tReverseList);
	printf("Pop = %s (deber�a ser Cinco)\n", sPop);
	printf("Size = %d (deber�a ser 4)\n", tList.Size());

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
	printf("tList: size = %d (deber�a ser 4)\n", tList.Size());
	printf("tList2:  size = %d (deber�a ser 5)\n", tList2.Size());
	printf("tReverseList:  size = %d (deber�a ser 4)\n", tReverseList.Size());
	tList.Reset();
	printf("Tras reset size = %d (deber�a ser 0)\n", tList.Size());



}

// Ejecutar programa: Ctrl + F5 o men� Depurar > Iniciar sin depurar
// Depurar programa: F5 o men� Depurar > Iniciar depuraci�n

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de c�digo fuente
//   3. Use la ventana de salida para ver la salida de compilaci�n y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de c�digo, o a Proyecto > Agregar elemento existente para agregar archivos de c�digo existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
