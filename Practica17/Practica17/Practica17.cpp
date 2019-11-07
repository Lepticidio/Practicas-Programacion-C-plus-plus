// Practica17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define ENUM_MY_EXAMPLE_VALUES \
	_CALL(ExampleA) \
	_CALL(ExampleB) \
	_CALL(ExampleC) \
	_CALL(ExampleD) 
#define DECLARE_ENUM(_NAME, _LIST)
struct _NAME\
{\

	};
#undef _CALL

	static const char* AsStr(Enum _eEnum)
	{
#define _CALL(_VALUE)\
		if (_eEnum == _VALUE)\
		{\
			return #_VALUE; \
		}
	}
#undef _CALL

#define _CALL(_VALUE)\
	if(strcmp(_sValue, #_VALUE)== 0)
	{
		return _VALUE;\
	}
	ENUM_MY_EXAMPLE_VALUES
#undef _CALL

	//static const char* AsStr(Enum _eEnum)
	//{
	//	if (_eEnum == ExampleA)
	//	{
	//		return "ExampleA";
	//	}
	//	else if (_eEnum == ExampleB)
	//	{
	//		return "ExampleB";
	//	}
	//	else if (_eEnum == ExampleC)
	//	{
	//		return "ExampleC";
	//	}
	//	else if (_eEnum == ExampleD)
	//	{
	//		return "ExampleD";
	//	}
	//	else if (_eEnum == Count)
	//	{
	//		return "Count";
	//	}
	//	return "Invalid";
	//}

	//static Enum AsEnum(const char* _sValue)
	//{
	//	if (strcmp(_sValue, "ExampleA") == 0)
	//	{
	//		return ExampleA;
	//	}
	//	else if (strcmp(_sValue, "ExampleB") == 0)
	//	{
	//		return ExampleB;
	//	}
	//	else if (strcmp(_sValue, "ExampleC") == 0)
	//	{
	//		return ExampleC;
	//	}
	//	else if (strcmp(_sValue, "ExampleD") == 0)
	//	{
	//		return ExampleD;
	//	}
	//	else if (strcmp(_sValue, "Count") == 0)
	//	{
	//		return Count;
	//	}
	//	return Invalid;
	//}



};

int main()
{
	EMyExample::Enum eEnum = EMyExample::ExampleC;
	const char* sEnum = EMyExample::AsStr(eEnum);
	printf(sEnum);
}