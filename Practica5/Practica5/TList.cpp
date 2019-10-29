#include "TList.h"
#include <iostream>
int TList::Size()
{
	return uSize;
}
int TList::Push(const char* psz)
{
	unsigned int uNumberChar = 0;
	if (strlen(pChain) > 0)
	{
		for (int i = 0; i < uSize; i++)
		{
			uNumberChar += strlen(pChain + i);
		}
	}
	char* pTempChain = new char[uNumberChar + strlen(psz)];

	for (int i = 0; i < uNumberChar; i++)
	{
		printf("i: %d, uNumberChar %d, sizeof pTempChain %d, size of pChain %d, srlen(pTempChain) %d", i, uNumberChar, sizeof(pTempChain), sizeof(pChain), strlen(pTempChain));
		pTempChain[i] = pChain[i];
	}
	for (int i = 0; i < strlen(psz); i++)
	{
		pTempChain[uNumberChar + i] = psz[i];
	}
	pTempChain[uNumberChar + strlen(psz)] = psz[strlen(psz)];
	uSize++;
	return 1;
}
const char* TList::Get()
{
	return pChain;
}
const char* TList::First()
{
	return nullptr;
}
const char* TList::Next()
{
	return nullptr;

}
const char* TList::Pop()
{
	uSize--;
	return nullptr;
}
void TList::Reset()
{

}
