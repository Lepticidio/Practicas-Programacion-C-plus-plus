
#include "file.h"
#include "stdio.h"
#include "assert.h"
namespace file
{
	void* SFile::OpenFile(const char* _sFileName, const char* _sMode)
	{
		assert(_sFileName != nullptr);
		if (_sFileName != nullptr)
		{
			
			fopen_s(&pFile, _sFileName, _sMode);
			return pFile;
		}
		return nullptr;
	}
	int SFile::CloseFile()
	{
		assert(pFile != nullptr);
		if (pFile != nullptr)
		{
			return fclose(pFile);
		}
		return EOF;

	}

	unsigned int SFile::ReadFile(char* _pBuffer, unsigned int _uBufferSize)
	{
		assert(pFile != nullptr);
		assert(_pBuffer != nullptr);
		if (pFile != nullptr && _pBuffer != nullptr)
		{
			return fread(_pBuffer, sizeof(char), _uBufferSize, pFile);
		}
		return 0;
	}

	unsigned int SFile::WriteFile(const char* _pBuffer, unsigned int _uBufferSize)
	{
		assert(pFile != nullptr);
		assert(_pBuffer != nullptr);
		if (pFile != nullptr && _pBuffer != nullptr)
		{
			return fwrite(_pBuffer, sizeof(char), _uBufferSize, pFile);
		}
		return 0;
	}





}

