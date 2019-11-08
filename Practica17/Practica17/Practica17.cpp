// Practica17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "EnumMacros.h"

//#define ENUM_MY_EXAMPLE_VALUES(_CALL) \
//	_CALL(ExampleA) \
//    _CALL(ExampleB) \
//    _CALL(ExampleC) \
//    _CALL(ExampleD) \
//	_CALL(ExampleE)
//DECLARE_ENUM_OLD(EMyExample, ENUM_MY_EXAMPLE_VALUES)

DECLARE_ENUM(EMyExample, ExampleA, ExampleB, ExampleC, ExampleD, ExampleE, ExampleF, ExampleG)

int main()
{
	for (unsigned int uIndex = 0; uIndex < EMyExample::Count; ++uIndex)
	{
		printf("%d. %s\n",
			uIndex,
			EMyExample::AsStr(static_cast<EMyExample::Enum>(uIndex)));
	}

	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleA")));
	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleB")));
	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleC")));
	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleD")));
	printf("Ejemplo %s\n", EMyExample::AsStr(EMyExample::AsEnum("ExampleE")));
}