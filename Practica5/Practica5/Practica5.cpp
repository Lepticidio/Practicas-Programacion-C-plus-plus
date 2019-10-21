// Practicas 5, 6 y 7 de Miguel Andújar

#include <iostream>
#include "file.h"
#include "FileUtils.h"

using namespace file;
using namespace utils;

int main()
{	
	const unsigned int uBUFFER_SIZE = 100;
	char sBuffer[uBUFFER_SIZE];
	const char* sFile1Path = "test.txt";
	void* pFile1 = OpenFile(sFile1Path, "r");
	
	if (pFile1 != nullptr)
	{
		unsigned int uReadBytes = ReadFile(pFile1, sBuffer, uBUFFER_SIZE);
		printf("Se han leído %d bytes del fichero %s\n", uReadBytes, sFile1Path);
		printf("Buffer:\n");
		printf("--------------\n");
		printf("%.*s\n", uReadBytes, sBuffer);
		printf("--------------\n");
		int iClosefileResult = CloseFile(pFile1);
		printf("El resultado de cerrar el fichero %s ha sido %d\n", sFile1Path, iClosefileResult);
		
	}
	else
	{
		printf("ERROR: no se encontró el fichero %s", sFile1Path);
	}

	const char* pCadena{"Los mejores mamiferos"};
	char sBuffer2[uBUFFER_SIZE];
	const char* sFile2Path = "test2.txt";
	void* pFile2 = OpenFile(sFile2Path, "w");
	if (pFile1 != nullptr)
	{
		WriteFile(pFile2, pCadena, strlen(pCadena) + 1);
		//unsigned int uReadBytes2 = ReadFile(pFile2, sBuffer2, uBUFFER_SIZE);
		//printf("SE REESCRIBE EL FICHERO\n");
		//printf("Se han leído %d bytes del fichero %s\n", uReadBytes2, sFile2Path);
		//printf("Buffer:\n");
		//printf("--------------\n");
		//printf("%.*s\n", uReadBytes2, sBuffer2);
		//printf("--------------\n");
		int iClosefileResult = CloseFile(pFile2);
		printf("El resultado de cerrar el fichero %s ha sido %d\n", sFile2Path, iClosefileResult);


	}
	else
	{
		printf("ERROR: no se encontró el fichero %s", sFile1Path);
	}
	const char* pCadenaABuscar{ "hoholaperritohoholahoholahohoholaperrito" };
	const char* pCadenaBuscada{ "hohola" };
	unsigned int uNumberStrings = CountStringsInString(pCadenaBuscada, pCadenaABuscar);
	printf("Hay %d cadenas\n", uNumberStrings);
	unsigned int uStringsInFile = CountStringsInFile("test3.txt", pCadenaBuscada);
	printf("Hay %d cadenas en el archivo\n", uStringsInFile);
	const char* pCadenaABuscarInts{ "11hola 8 perrito1gatito 100" };
	unsigned int uSumIntsInChain = AddIntsInString(pCadenaABuscarInts);
	printf("La suma de ints en la cadena %s es %d\n", pCadenaABuscarInts, uSumIntsInChain);
	unsigned int uSumIntsFile = SumIntsInFile("test4.txt");
	printf("La suma de ints en el archivo %s es %d\n", "test4.txt", uSumIntsFile);
	printf("\n\n\n\n");

}


