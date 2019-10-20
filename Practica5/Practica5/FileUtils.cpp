#include "FileUtils.h"
#include "File.h"
#include <iostream>

unsigned int CountStringsInString(const char* _sSearchedString, const char* _sReadedString)
{
	unsigned int uResult = 0;
	printf("The readed string is: %s\n", _sReadedString);
	for (int i = 0; i < strlen(_sReadedString); i++)
	{
		bool bStringFound = true;
		for (int j = 0; j < strlen(_sSearchedString); j++)
		{
			if ((i + j) < strlen(_sReadedString))
			{

				if (_sReadedString[i + j] != _sSearchedString[j])
				{
					bStringFound = false;
					break;
				}
			}
			else
			{
				bStringFound = false;
				break;
			}
		}
		if (bStringFound)
		{
			uResult++;
		}
	}
	return uResult;
}

//unsigned int CountStringsInFile(const char* _sFileName, const char* _sString)
//{
//
//	//Tengo que hacer esto para cualquier tamaño de archivo 
//	const unsigned int uBUFFER_SIZE = 100;
//	char sBuffer[uBUFFER_SIZE];
//	void* pFile1 = OpenFile(_sFileName, "r");
//
//	if (pFile1 != nullptr)
//	{
//		unsigned int uReadBytes = ReadFile(pFile1, sBuffer, uBUFFER_SIZE);
//		printf("Bytes read: %d\n", uReadBytes);
//		int iClosefileResult = CloseFile(pFile1);
//		printf("El resultado de cerrar el fichero %s ha sido %d\n", _sFileName, iClosefileResult);
//
//	}
//	return CountStringsInString(_sString, sBuffer);
//
//}

unsigned int CountStringsInFile(const char* _sFileName, const char* _sString)
{

	//Tengo que hacer esto para cualquier tamaño de archivo 
	void* pFile1 = OpenFile(_sFileName, "r");

	if (pFile1 != nullptr)
	{
		const unsigned int uBUFFER_SIZE = GetFileSize(pFile1) + 1;
		printf("El tamaño es %d\n", uBUFFER_SIZE);
		char* pBuffer = new char[uBUFFER_SIZE];
		for (int i = 0; i < uBUFFER_SIZE; i++)
		{
			pBuffer[i] = 'z';
		}
		pBuffer[uBUFFER_SIZE - 1] = '\0';
		unsigned int uReadBytes = ReadFile(pFile1, pBuffer, uBUFFER_SIZE);
		printf("Bytes read: %d\n", uReadBytes);
		int iClosefileResult = CloseFile(pFile1);
		printf("El resultado de cerrar el fichero %s ha sido %d\n", _sFileName, iClosefileResult);
		return CountStringsInString(_sString, pBuffer);

	}
	return 0;

}

unsigned int AddIntsInString(const char* _sString)
{

	bool bSameNumber = false;
	unsigned int uResult = 0;
	unsigned int uCurrentNumber = 0;
	for (int i = 0; i < strlen(_sString); i++)
	{
		//(int) char converts a char to its ASCI value. as '0' is in the position 48, we can know if a char is an int checking its ASCI position
		if ((int)_sString[i] >47 && (int)_sString[i]< 58)
		{
			if (bSameNumber)
			{
				uCurrentNumber *= 10;
			}
			uCurrentNumber += (int)_sString[i] - 48;
			bSameNumber = true;
		}
		else
		{
			if (bSameNumber)
			{
				uResult += uCurrentNumber;
				uCurrentNumber = 0;
				bSameNumber = false;

			}

		}

	}
	uResult += uCurrentNumber;
	return uResult;

}

unsigned int SumIntsInFile(const char* _sFileName)
{

	//Tengo que hacer esto para cualquier tamaño de archivo 
	const unsigned int uBUFFER_SIZE = 100;
	char sBuffer[uBUFFER_SIZE];
	void* pFile1 = OpenFile(_sFileName, "r");

	if (pFile1 != nullptr)
	{
		unsigned int uReadBytes = ReadFile(pFile1, sBuffer, uBUFFER_SIZE);
		int iClosefileResult = CloseFile(pFile1);
		printf("El resultado de cerrar el fichero %s ha sido %d\n", _sFileName, iClosefileResult);
	}
	return AddIntsInString(sBuffer);

}

unsigned int GetFileSize(void* _pFile)
{
	FILE* pTrueFile = static_cast<FILE*>(_pFile);
	fseek(pTrueFile, 0, SEEK_END);
	return (unsigned int)ftell(pTrueFile);
}