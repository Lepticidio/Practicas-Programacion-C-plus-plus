#pragma once
class TList
{
public:
	char *pChain;
	unsigned int uSize;
	int Size();
	int Push(const char* psz);
	const char* Get();
	const char* First();
	const char* Next();
	const char* Pop();
	void Reset();
};

