
#include "file.h"
#include "stdio.h"
#include "assert.h"

	namespace file
	{
		int SFile::OpenFile(const char* _sFileName, const char* _sMode)
		{
			assert(_sFileName != nullptr);
			if (_sFileName != nullptr && m_pFile == nullptr)
			{
				FILE* pFile = static_cast<FILE*>(m_pFile);
				fopen_s(&pFile, _sFileName, _sMode);
				return 1;
			}
			return 0;
		}
		int SFile::CloseFile()
		{
			assert(m_pFile != nullptr);
			if (m_pFile != nullptr)
			{
				return fclose(static_cast<FILE*>(m_pFile));
				m_pFile = nullptr;
			}
			return EOF;

		}

		unsigned int SFile::ReadFile(char* _pBuffer, unsigned int _uBufferSize)
		{
			assert(m_pFile != nullptr);
			assert(_pBuffer != nullptr);
			if (m_pFile != nullptr && _pBuffer != nullptr)
			{
				return fread(_pBuffer, sizeof(char), _uBufferSize, static_cast<FILE*>(m_pFile));
			}
			return 0;
		}

		unsigned int SFile::WriteFile(const char* _pBuffer, unsigned int _uBufferSize)
		{
			assert(m_pFile != nullptr);
			assert(_pBuffer != nullptr);
			if (m_pFile != nullptr && _pBuffer != nullptr)
			{
				return fwrite(_pBuffer, sizeof(char), _uBufferSize, static_cast<FILE*>(m_pFile));
			}
			return 0;
		}





	};



