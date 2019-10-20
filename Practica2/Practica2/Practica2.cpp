// Practica 2 de Miguel Andújar Navarro
#include <iostream>

int main()
{

	//PRIMERA PARTE

	unsigned int uValue = 0xA4F012D4;
	unsigned char* pChar = reinterpret_cast<unsigned char*> (&uValue);

	
	unsigned char byte1 = *pChar;
	unsigned char byte2 = *(pChar + 1);
	unsigned char byte3 = *(pChar + 2);
	unsigned char byte4 = *(pChar + 3);

	printf("integer:%8X\n", uValue);
	printf("byte1: %02hhX\n", byte1);
	printf("byte2: %02hhX\n", byte2);
	printf("byte3: %02hhX\n", byte3);
	printf("byte4: %02hhX\n", byte4);

	//SEGUNDA PARTE

	//He declarado estos ints aquí, porque si escribía los números directamente en la tabla se ponen por defecto como
	//unsigned int, y al poner que los warnings se traten como errores no me dejaba compilar por el aviso del casteo automático
	signed int first = 1, second = 3, third = 2, fourth = 5, fifth = 3, sixth = 0xFFFFFFFF, seventh = 2;
	signed int tabla[] = { first, second, third, fourth, fifth, sixth, seventh};

	signed int* pTabla = tabla;
	signed int iMax = tabla[0];
	for (int i = 1; i < sizeof(tabla)/sizeof(unsigned int); i++)
	{
		if (*(pTabla + i) > iMax)
		{
			iMax = *(pTabla + i);
		}
	}
	printf("El mayor int de la tabla es %d\n", iMax);

	//TERCERA PARTE

	unsigned char* pChar2 = reinterpret_cast<unsigned char*> (pTabla);
	unsigned char cMaxByte = *pChar2;
	for (int i = 1; i < sizeof(tabla) / sizeof(unsigned char); i++)
	{
		if (*(pChar2 + i) > cMaxByte)
		{
			cMaxByte = *(pChar2 + i);
		}
	}
	printf("El mayor byte de la tabla es %02hhX\n", cMaxByte);

	//CUARTA PARTE

	char sCadena[] = "Hola mundo";
	char* pChar3 = sCadena;
	printf("La cadena original es %s\n", sCadena);	

	int iCounter = 0;
	while (iCounter < sizeof(sCadena)/2)
	{
		char cAux = *(pChar3 + iCounter);
		*(pChar3 + iCounter)= *(pChar3 + sizeof(sCadena) - iCounter - 2);
		* (pChar3 + sizeof(sCadena) - iCounter - 2)  = cAux;
		iCounter++;
	}
	printf("La cadena invertida es %s\n", sCadena);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
