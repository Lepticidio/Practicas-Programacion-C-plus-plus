// Practica14.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>



class CParentNoVirtual
{

	void Prueba()
	{
		printf("Llama a prueba en CParentNoVirtual\n");
	}
};

class CParent
{

	virtual void Prueba()
	{
		printf("Llama a prueba en CParent\n");
	}
public:
	CParent()
	{
		Prueba();
	}
};

class CA : public CParent
{
	virtual void Prueba()
	{
		printf("Llama a prueba en CA\n");
	}

};

class CB : public CA
{

	virtual void Prueba()
	{
		printf("Llama a prueba en CB\n");
	}
};


int main()
{
	//A) ¿Cuánto ocupa la tabla de funciones virtuales? 4 bytes (lo que ocupa un puntero) por cada función virtual que haya
	//B) ¿Dónde está situada esta tabla? 

	CB* pB = new CB();
	CB* pB2 = new CB();


	//vpointer
	//CParent int
	//CA float
	//CB int

	int** pVirtualTable = reinterpret_cast<int**> (pB);
	int** pVirtualTable2 = reinterpret_cast<int**> (pB2);

	printf("La dirección de la vtable es %08X\n", reinterpret_cast<int>(*pVirtualTable));
	printf("La dirección de la vtable es %08X\n", reinterpret_cast<int>(*pVirtualTable2));
	//C) ¿Cuánto ocupa más por tener funciones virtuales?

	CParent* pP = new CParent();
	CParentNoVirtual* pP2 = new CParentNoVirtual();

	printf("Tamaño con virtuales : %d, tamaño sin virtuales: %d", sizeof(*pP), sizeof(*pP2));

	//D) ¿Qué pasa si llamo a un metodo virtual desde el constructor?
	//Si lo llamo desde el constructor de la clase padre, llama al metodo del padre. Si lo llamo en el constructor del hijo, llama al método del hijo



	//E) ¿Cuántos pasos extra tiene que darse para llamar a una función virtual?
	//Primero se tiene que buscar en la tabla de funciones virtuales, y luego se llama, en vez de llamarse directamente
	delete pB;
	delete pB2;


}
