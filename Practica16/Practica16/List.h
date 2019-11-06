#pragma once

// Clase: Creación de una lista enlazada “TList” que tenga los siguientes métodos 
//	   a. int Size(); // Retorna el número de elementos.
//	   b. int Push(const char *psz); // Añade la cadena a la lista.
//	   c. const char * First(); // retorna el primer elemento de la lista.
//	   d. const char *Next(); // retorna el siguiente elemento de la lista.
//	   e. const char * Pop(); // Elimina y retorna el primer elemento de la lista.
//	   f. void Reset(); // Elimina todos los elementos de la lista.

class IListElement
{
public:
	virtual void PrintElement() = 0;
};

class TListNode
{
public:
	TListNode(IListElement* _pValue);

	IListElement* m_pValue;
	TListNode* m_pNext;
};

class TList
{
public:
	TList();
	~TList();

	int Size(); // Retorna el número de elementos.
	int Push(IListElement* _pValue); // Añade la cadena a la lista.
	IListElement* First(); // retorna el primer elemento de la lista.
	IListElement* Next(); // retorna el siguiente elemento de la lista.
	// Elimina y retorna el primer elemento de la lista.
	IListElement* Pop();
	void Reset(); // Elimina todos los elementos de la lista.

private:
	TListNode* m_pFirst;
	unsigned int m_uSize;
	// For iteration
	TListNode* m_pCurrent;
};