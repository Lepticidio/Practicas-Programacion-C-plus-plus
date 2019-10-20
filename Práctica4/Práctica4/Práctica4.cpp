// practica4.cpp
//
#include <stdio.h>
#include "consola.h"

struct TEntity;
typedef void (*funcEntity)(TEntity*);

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity* m_funcs;
	TEntity(funcEntity* funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

void Draw1(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("1");
}

void Move1(TEntity* _pEntity)
{
	_pEntity->m_ix++;
	_pEntity->m_iy++;

}

void Draw2(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	int counter = 0;
	while (counter < _pEntity->m_ix)
	{
		printf("2");
		counter++;
	}
}

void Move2(TEntity* _pEntity)
{
	_pEntity->m_ix++;

}

void Draw3(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("3");
}

void Move3(TEntity* _pEntity)
{
	_pEntity->m_ix++;
	if (_pEntity->m_ix % 2 == 0)
	{
		_pEntity->m_iy += 4;
	}
	else
	{
		_pEntity->m_iy -= 4;
	}

}

void Draw4(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("4: %d", _pEntity->m_iy);
}

void Move4(TEntity* _pEntity)
{
	_pEntity->m_iy++;
}



// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[])
{
	funcEntity functionArray1[2];
	functionArray1[0] = Draw1;
	functionArray1[1] = Move1;
	funcEntity functionArray2[2];
	functionArray2[0] = Draw2;
	functionArray2[1] = Move2;
	funcEntity functionArray3[2];
	functionArray3[0] = Draw3;
	functionArray3[1] = Move3;
	funcEntity functionArray4[2];
	functionArray4[0] = Draw4;
	functionArray4[1] = Move4;
	TEntity* tEntities[4];
	tEntities[0] = new TEntity(functionArray1, 5, 0);
	tEntities[1] = new TEntity(functionArray2, 2, 3);
	tEntities[2] = new TEntity(functionArray3, 3, 2);
	tEntities[3] = new TEntity(functionArray4, 0, 5);

	while (true)
	{
		//Borro la pantalla
		clear();
		//for a todas las entidades
		for (int i = 0; i < sizeof(tEntities)/sizeof(TEntity*); i++)
		{
			tEntities[i]->m_funcs[1](tEntities[i]);
			tEntities[i]->m_funcs[0](tEntities[i]);
		}
		//Espero
		Sleep(1000);
	}
	
	
}

