// Práctica 1 de Miguel Andújar Navarro

#include <iostream>

#define BIT_0 0x00000001
#define BIT_1 0x00000002
#define BIT_2 0x00000003
#define BIT_3 0x00000004
#define BULLET_MASK 0x00FF0000

unsigned int GetBullets(unsigned int _uValue)
{
	unsigned int uRet = _uValue & BULLET_MASK;
	uRet = uRet >> 16;
	return uRet;
}

unsigned int AddBullets(unsigned int _uBulletsToAdd, unsigned int _uValue)
{
	unsigned int uCurrentNumBullets = GetBullets(_uValue);
	unsigned int uNewNumBullets = uCurrentNumBullets + _uBulletsToAdd;
	unsigned int uRet = _uValue &= ~BULLET_MASK;
	unsigned int uMaskNewBullets = uNewNumBullets << 16;
	uRet = uRet |= uMaskNewBullets;
	return uRet;
}

bool IsInfiniteAmmoEnabled(unsigned int _uValue)
{
	bool bIsInfiniteAmmoEnabled(false);
	if ((_uValue & BIT_1) != 0)
	{
		bIsInfiniteAmmoEnabled = true;
	}
	return bIsInfiniteAmmoEnabled;
}

int SetInfiniteAmmo(bool _bEnabled, unsigned int _uValue)
{
	unsigned int uRet = _uValue;
	if (_bEnabled)
	{
		uRet = uRet |= BIT_1;
	}
	else
	{
		uRet = uRet &= ~BIT_1;
	}
	return uRet;
}

int main()
{


	unsigned int uPersonaje = 0xFF07A545;


	std::cout << "Está activado el modo infinitas balas: " << IsInfiniteAmmoEnabled(uPersonaje) << std::endl;
	uPersonaje = SetInfiniteAmmo(true, uPersonaje);
	std::cout << "Tras activarlo: " << IsInfiniteAmmoEnabled(uPersonaje) << std::endl;
	std::cout << "Número de balas: " << GetBullets(uPersonaje) << std::endl;
	uPersonaje = AddBullets(3, uPersonaje);
	std::cout << "Número de balas tras sumarle 3: " << GetBullets(uPersonaje) << std::endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
