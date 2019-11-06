#pragma once
#include "File.h"
#include "List.h"
namespace file
{
	namespace utils
	{
		struct SFileUtils : public SFile
		{
			unsigned int CountStringsInString(const char* _sSearchedString, const char* _sReadedString);
			unsigned int CountStringsInFile(const char* _sFileName, const char* _sString);
			unsigned int SumIntsInFile(const char* _sFileName);
			TList MakeNumberListFromString(const char* _sString);
			void PrintNumbersInFile(const char* _sFileName);
			unsigned int AddIntsInString(const char* _sString);
			unsigned int GetFileSize(void* _pFile);
		};
	}
}