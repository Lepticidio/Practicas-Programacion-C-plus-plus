// Practicas 5, 6 y 7 de Miguel Andújar

#include <iostream>
#include "File.h"
#include "FileUtils.h"
#include "TList.h"

using namespace file;
using namespace utils;

int main()
{	/*
	const unsigned int uBUFFER_SIZE = 100;
	char sBuffer[uBUFFER_SIZE];
	const char* sFile1Path = "test.txt";
	SFileUtils oFile;
	void* pFile1 = oFile.OpenFile(sFile1Path, "r");
	
	if (pFile1 != nullptr)
	{
		unsigned int uReadBytes = oFile.ReadFile(sBuffer, uBUFFER_SIZE);
		printf("Se han leído %d bytes del fichero %s\n", uReadBytes, sFile1Path);
		printf("Buffer:\n");
		printf("--------------\n");
		printf("%.*s\n", uReadBytes, sBuffer);
		printf("--------------\n");
		int iClosefileResult = oFile.CloseFile();
		printf("El resultado de cerrar el fichero %s ha sido %d\n", sFile1Path, iClosefileResult);
		
	}
	else
	{
		printf("ERROR: no se encontró el fichero %s", sFile1Path);
	}

	const char* pCadena{"Los mejores mamiferos"};
	char sBuffer2[uBUFFER_SIZE];
	const char* sFile2Path = "test2.txt";
	void* pFile2 = oFile.OpenFile(sFile2Path, "w");
	if (pFile1 != nullptr)
	{
		oFile.WriteFile( pCadena, strlen(pCadena) + 1);
		int iClosefileResult = oFile.CloseFile();
		printf("El resultado de cerrar el fichero %s ha sido %d\n", sFile2Path, iClosefileResult);


	}
	else
	{
		printf("ERROR: no se encontró el fichero %s", sFile1Path);
	}
	const char* pCadenaABuscar{ "hoholaperritohoholahoholahohoholaperrito" };
	const char* pCadenaBuscada{ "hohola" };
	unsigned int uNumberStrings = oFile.CountStringsInString(pCadenaBuscada, pCadenaABuscar);
	printf("Hay %d cadenas\n", uNumberStrings);
	unsigned int uStringsInFile = oFile.CountStringsInFile("test3.txt", pCadenaBuscada);
	printf("Hay %d cadenas en el archivo\n", uStringsInFile);
	const char* pCadenaABuscarInts{ "11hola 8 perrito1gatito 100" };
	unsigned int uSumIntsInChain = oFile.AddIntsInString(pCadenaABuscarInts);
	printf("La suma de ints en la cadena %s es %d\n", pCadenaABuscarInts, uSumIntsInChain);
	unsigned int uSumIntsFile = oFile.SumIntsInFile("test4.txt");
	printf("La suma de ints en el archivo %s es %d\n", "test4.txt", uSumIntsFile);
	printf("\n\n\n\n");
	*/

	TList tList;

//	printf("TList: (%s) Size: %d", tList.Get(), tList.Size());
	tList.Push("triasico");
	printf("TList: (%s) Size: %d", tList.Get(), tList.Size());
	tList.Push("jurasico");
	printf("TList: (%s) Size: %d", tList.Get(), tList.Size());
	tList.Push("cretacico");
	printf("TList: (%s) Size: %d", tList.Get(), tList.Size());




}


