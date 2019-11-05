// Ejercicio Componentes.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

class CComponentA
{
public:
	CComponentA(int _iValue) : m_iValue(_iValue)
	{
		printf("Created ComponentA\n");

	}
	int m_iValue;
};

class CComponentB
{
public:
	CComponentB(int _iValue) : m_iValue(_iValue)
	{
		printf("Created ComponentB\n");

	}
	int m_iValue;
};

class CComponentC
{
public:
	CComponentC(int _iValue): m_iValue(_iValue)
	{
		printf("Created ComponentC\n");

	}
	int m_iValue;
};
class CEntity
{
public:
	CEntity(int _iValue): m_oComponentA(_iValue), m_oComponentB(_iValue), m_oComponentC(_iValue)
	{
		printf("Created CEntity\n");
	}
	CComponentA m_oComponentA;
	CComponentB m_oComponentB;
	CComponentC m_oComponentC;

};


int main()
{
	CEntity* pCEntity = new CEntity(1);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
