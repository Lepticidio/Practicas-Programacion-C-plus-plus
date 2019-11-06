
#include <iostream>
#include <string>
#include "List.h"

class CMyClase : public IListElement
{
public:
	CMyClase(const char* _sValue) : m_sValue(_sValue) {}
	virtual void PrintElement() override { printf("%s\n", m_sValue); }
private:
	const char* m_sValue = nullptr;
};

int main()
{
	TList tList;

	printf("Size = %d [%s]\n", tList.Size(), tList.Size() == 0 ? "SUCCESS" : "FAILED");

	tList.Push(new CMyClase("Uno"));
	tList.Push(new CMyClase("Dos"));
	tList.Push(new CMyClase("Tres"));
	tList.Push(new CMyClase("Cuatro"));
	tList.Push(new CMyClase("Cinco"));

	printf("Size = %d [%s]\n", tList.Size(), tList.Size() == 5 ? "SUCCESS" : "FAILED");

	IListElement* sPop = tList.Pop();
	sPop->PrintElement();
	printf("Size = %d [%s]\n", tList.Size(), tList.Size() == 4 ? "SUCCESS" : "FAILED");

	printf("--- Print tList (size = %d) ---\n", tList.Size());
	unsigned int uIndex(0);
	IListElement* sCurrentValue = tList.First();
	while (sCurrentValue != nullptr)
	{
		printf("[%d] ", uIndex);
		sCurrentValue->PrintElement();
		uIndex++;
		sCurrentValue = tList.Next();
	}

	tList.Reset();
	printf("Size = %d [%s]\n", tList.Size(), tList.Size() == 0 ? "SUCCESS" : "FAILED");

}