#pragma once
namespace file
{
	struct SFile
	{
		void* m_pFile;

		int OpenFile(const char* _sFileName, const char* _sMode);
		int CloseFile();
		unsigned int ReadFile(char* _pBuffer, unsigned int _uBufferSize);
		unsigned int WriteFile(const char* _pBuffer, unsigned int _uBufferSize);

	};
}