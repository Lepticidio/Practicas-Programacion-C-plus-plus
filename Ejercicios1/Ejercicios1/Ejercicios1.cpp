// Ejercicios1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

struct SPruebaBools
{
	bool bA, bB, bC, bD;
};
struct SPruebaInts
{
	int iA;
};

void SetIntTo10(int& iValue)
{
	iValue = 10;
}

void AddValue(int _iAmountToAdd, int& _iValue_)
{
	_iValue_ += _iAmountToAdd;
}


int g_iValue = 198;


void GetValuePtr(int*& pPtr_)
{
	pPtr_ = &g_iValue;
}

#include <stdarg.h>

int AddThemAll(int numargs, ...)
{
	va_list listPointer;
	va_start(listPointer, numargs);

	int iSum = 0;
	for (int i = 0; i < numargs; ++i)
	{
		int arg = va_arg(listPointer, int);
		printf("arg[%d] = %d\n", i, arg);
		iSum += arg;
	}
	printf("TOTAL = %d", iSum);
	return iSum;
}



int Resta(int primerValor, int segundoValor)
{
	return primerValor - segundoValor;
}
int Multiplicacion(int primerValor, int segundoValor)
{
	return primerValor * segundoValor;
}
int AddOne(int primerValor)
{
	return primerValor++;
}
float Suma(int primerValor, int segundoValor)
{
	return primerValor + segundoValor;
}

typedef int (*funInt)(int, int);

//Práctica 2
int iPrueba = 1;



class CParent
{
	CParent() { printf("Creando CParent \n"); }
	CParent() { printf("Destruyendo CParent \n"); }
};

class CMiSingleton
{
	private:
		CMiSingleton() {}
		~CMiSingleton()
		{

		}
	public:
		static CMiSingleton* GetInstance()
		{
			if (s_pPtr == nullptr)
			{
				delete s_pPtr;
				s_pPtr = new CMiSingleton;
			}
			return s_pPtr;
		}
		static void Destroy()
		{
			if (s_pPtr == nullptr)
			{
				delete s_pPtr;
			}
		}
		float GetValue() const { return m_fValue; }
		void SetValue(float fValue) { m_fValue = fValue; }
	private:
		static CMiSingleton* s_pPtr;
		float m_fValue = 0.0f;
};

CMiSingleton* MiSingleton = nullptr;




int main()
{
	//Sumar dos números

	/*
	int iNumberA, iNumberB, iResult;
	float fA;
	char cA;
	long int iNumberC;
	long float fNumberB;
	std::cin >> iNumberA;
	std::cin >> iNumberB;
	iResult = iNumberA + iNumberB;
	printf("La suma de %d y %d es %d \n", iNumberA, iNumberB, iResult);	
	*/

	// Ver peso tipo variable y valores extremos
	/*
	std::cout << "Size of bool: " << sizeof(bool) << " bytes (" << sizeof(bool) * 8 << " bits)" <<"\n";
	std::cout << "Size of int: " << sizeof(int) << " bytes (" << sizeof(int) * 8 << " bits)" << "\n";
	std::cout << "Size of long int: " << sizeof(long int) << " bytes (" << sizeof(long int) * 8 << " bits)" << "\n";
	std::cout << "Size of short int: " << sizeof(short int) << " bytes (" << sizeof(short int) * 8 << " bits)" << "\n";
	std::cout << "Size of float: " << sizeof(float) << " bytes (" << sizeof(float) * 8 << " bits)";
	std::cout << "Size of long float: " << sizeof(long float) << " bytes (" << sizeof(long float) * 8 << " bits)" << "\n";
	std::cout << "max char : " << CHAR_MAX << std::endl;
	std::cout << "max int : " << INT_MAX << std::endl;
	std::cout << "max float : " << FLT_MAX << std::endl;
	std::cout << "min char : " << CHAR_MIN << std::endl;
	std::cout << "min int : " << INT_MIN << std::endl;
	std::cout << "min float : " << FLT_MIN << std::endl;
	*/

	//Tamaños structs

	/*
	std::cout << "Size of SpruebaBool: " << sizeof(SPruebaBools) << " bytes (" << sizeof(SPruebaBools) * 8 << " bits)" << "\n";
	std::cout << "Size of SpruebaBool: " << sizeof(SPruebaInts) << " bytes (" << sizeof(SPruebaInts) * 8 << " bits)" << "\n";
	
	*/

	/*
		bool bTest01 = 0;
	bool bTest02 = 1;
	bool bTest03 = (bool)7;

	std::cout << "bTest01: " << bTest01 << std::endl;
	std::cout << "bTest02: " << bTest02 << std::endl;
	std::cout << "bTest03: " << bTest03 << std::endl;

	int iTest01 = (int)3.7f;

	std::cout << "iTest01: " << iTest01 << std::endl;

	unsigned char uTest01 = 255u;
	unsigned char uTest02 = 256u;
	unsigned char uTest03 = 255u;
	++uTest03;

	printf("uTest01: ");

	unsigned int u = 10;
	int i = -42;

	std::cout << "i + i : " << i + +i << std::endl;
	std::cout << "u + i : " << u + +i << std::endl;
	std::cout << "i + u : " << i + u << std::endl;
	*/


	/*
	unsigned int ui1 = 1;

	if (ui1 > -1)
	{
		ui1 = 0;
	}

	std::cout << ui1 << std::endl;
	
	*/

	// Cuando el resultado no es un número
	/*
	float fValue(10.f);
	fValue -= 10.f;
	float fPrueb = 10.f / fValue;
	float fPrueb2 = 37.0f;
	int i = 8;

	fPrueb2 *= fPrueb2 * fPrueb;

	if (fPrueb != fPrueb)
	{
		i = 0;
	}

	std::cout << fPrueb << fPrueb2 << i << std::endl;
	*/

	//Practica 2 (tambien tiene código antes del main)
	/*
	std::cout << "iPrueba  Global= " << iPrueba << std::endl;
	int iPrueba = 2;
	std::cout << "iPrueba Local = " << iPrueba << std::endl;
	std::cout << "iPrueba Global = " << ::iPrueba << std::endl;
	*/

	//Práctica 3 enum antiguos vs nuevos
/*
	enum EColor 
	{
		red, 
		yellow, 
		green
	};
	enum class EPeppers
	{
		red,
		yellow,
		green
	};
EColor eyes = green;
EPeppers p = EPeppers::green;
//EColor eyes2 = EPeppers::green;


*/

//Iteración por array de char
/*
char sText[] = "Hola";
for (int i = 0; sText[i] != '\0'; i++)
{
	std::cout << sText[i]<< std::endl;
}
std::cout <<  std::endl;
for (int i = 0; i < strlen(sText); i++)
{
	std::cout << sText[i] << std::endl;
}
std::cout << std::endl;
for (int i = 0; i < sizeof(sText); i++)
{
	std::cout << sText[i] << std::endl;
}

*/

//Uso de referencias


/*
	int iValue = 10;
	int& rValue = iValue;
	printf("%i\n", iValue);
	rValue = 78886;
	printf("%i\n", iValue);

*/


	/*

	int iValor = 0;
	printf("%d\n", iValor);
	SetIntTo10(iValor);
	printf("%d\n", iValor);
	AddValue(7, iValor);
	printf("%d\n", iValor);

	int* pMiPtr = nullptr;
	GetValuePtr(pMiPtr);
	printf("%d\n", *pMiPtr);
	
	
	*/
	/*
	//Funciones con número indeterminado de parámetros
	AddThemAll(3, 1, 2, 3, 4);
	

	*/
	//Puntero a función
	//int(*pResta)(int, int) = &Resta;
	/*
	//Typedef con función
	funInt miFuncion = Multiplicacion;
	int iResultado = (*miFuncion)(8, 2);
	printf("%d\n", iResultado);
	*/

	CMiSingleton::GetInstance()->SetValue(1000.f);
	//std::cout<<CMiSingleton::GetInstance()->GetValue();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
