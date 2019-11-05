// Practica14.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>



class CParentNoVirtual
{

	void Prueba()
	{
		printf("Llama a prueba en CParentNoVirtual");
	}
};

class CParent
{

	virtual void Prueba()
	{
		printf("Llama a prueba en CParent");
	}
};

class CA : public CParent
{

	virtual void Prueba()
	{
		printf("Llama a prueba en CA");
	}
};

class CB : public CA
{

	virtual void Prueba()
	{
		printf("Llama a prueba en CB");
	}
};


int main()
{
	//A) ¿Cuánto ocupa la tabla de funciones virtuales? 4 bytes (lo que ocupa un puntero) por cada función virtual que haya
	//B) ¿Dónde está situada esta tabla? 

	CB* pB = new CB();
	CB* pB2 = new CB();


	//vpointer
	//CParent int
	//CA float
	//CB int

	int** pVirtualTable = reinterpret_cast<int**> (pB);
	int** pVirtualTable2 = reinterpret_cast<int**> (pB2);

	printf("La dirección de la vtable es %08X\n", reinterpret_cast<int>(*pVirtualTable));
	printf("La dirección de la vtable es %08X\n", reinterpret_cast<int>(*pVirtualTable2));
	//C) ¿Cuánto ocupa más por tener funciones virtuales?

	CParent* pP = new CParent();
	CParentNoVirtual* pP2 = new CParentNoVirtual();

	printf("Tamaño con virtuales : %d, tamaño sin virtuales: %d", sizeof(*pP), sizeof(*pP2));

	//E) ¿Cuántos pasos extra tiene que darse para llamar a una función virtual?
	//Primero se tiene que buscar en la tabla de funciones virtuales, y luego se llama, en vez de llamarse directamente
	delete pB;
	delete pB2;


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
