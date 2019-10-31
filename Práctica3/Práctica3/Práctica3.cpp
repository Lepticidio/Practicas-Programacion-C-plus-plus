// Práctica3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#pragma warning (disable : 6293)

const char* tTablaDeCadenas[] =
{
	"cadena0",
	"cadena1",
	"cadena2",
	"cadena3",
	"cadena4"
};
const char* GetString(unsigned int _uIndex)
{
	unsigned int uNumCadenas = sizeof(tTablaDeCadenas) / sizeof(const char*);
	if (_uIndex < uNumCadenas)
	{
		return tTablaDeCadenas[_uIndex];
	}
	return nullptr;
}
const bool GetString(unsigned int _uIndex, const char*& psCadena)
{
	unsigned int uNumCadenas = sizeof(tTablaDeCadenas) / sizeof(const char*);
	if (_uIndex < uNumCadenas)
	{
		psCadena = tTablaDeCadenas[_uIndex];
		return true;
	}
	return false;
}
bool GetInvertedString(unsigned int _uIndex, char* sString)
{
	unsigned int uNumCadenas = sizeof(tTablaDeCadenas) / sizeof(char*);
	
	if (_uIndex < uNumCadenas)
	{
		const char* pSelectedString = tTablaDeCadenas[_uIndex];
		unsigned int uLen = strlen(pSelectedString);

		for (unsigned int uIndex = uLen -1; uIndex < uLen; --uIndex)
		{
			unsigned int uNewIndex = (uLen - 1) - uIndex;
			*(sString + uNewIndex) = *(pSelectedString + uIndex);

		}
		*(sString + uLen) = '\0';
		return true;
	}
	return false;
}
/*
const bool GetString(unsigned int _uIndex, const char** psCadena)
{
	if(psCadena != nullptr )
	{ }
	if (_uIndex < uNumCadenas)
	{
		psCadena = tTablaDeCadenas[_uIndex];
		return true;
	}
	return false;
}

*/

int main()
{
	printf("%d\n", sizeof(tTablaDeCadenas));
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(char*));
	const char* sCadena1 = GetString(1);
	printf("%s\n", sCadena1);

	const char* sCadena2;
	GetString(2 , sCadena2);
	printf("%s\n", sCadena2);
	
	char sCadena3Invertida[256];
	GetInvertedString(3, sCadena3Invertida);
	printf("%s\n", sCadena3Invertida);
	const char* sCadena3 = GetString(3);
	printf("%s\n", sCadena3);
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
