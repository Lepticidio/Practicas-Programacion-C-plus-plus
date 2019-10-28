#pragma once
#include "stdio.h"
namespace file
{
	struct SFile
	{
		FILE* pFile;

		void* OpenFile(const char* _sFileName, const char* _sMode);
		int CloseFile();
		unsigned int ReadFile(char* _pBuffer, unsigned int _uBufferSize);
		unsigned int WriteFile(const char* _pBuffer, unsigned int _uBufferSize);


	};
}