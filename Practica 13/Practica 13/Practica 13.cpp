// Practica 13.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "Jpg.h"
#include "Png.h"

void PrintImageInfo(const CImagen& oImagen);
void RemoveAlphaInPngs(CImagen* _oImages, int _iNumberImages);

int main()
{
	// Práctica Imagen
	const int iNumberImages = 4;

	CPng oPng1;
	CPng oPng2;
	CJpg oJpg1;
	CJpg oJpg2;

	oPng1.SetPngFile("FicheroPng1.png");
	oPng2.SetPngFile("FicheroPng2.png");
	oJpg1.SetJpgFile("FicheroJpg1.jpg");
	oJpg2.SetJpgFile("FicheroJpg2.jpg");

	CImagen tImageArray[iNumberImages]
	{
		oPng1, oJpg1, oPng2, oJpg2
	};

	for (int i = 0; i < iNumberImages; i++)
	{
		PrintImageInfo(tImageArray[i]);
	}

	printf("\n\nREMOVING ALPHA\n\n");

	RemoveAlphaInPngs(tImageArray, iNumberImages);

	for (int i = 0; i < iNumberImages; i++)
	{
		PrintImageInfo(tImageArray[i]);
	}

	getchar();

	return 0;
}

// ***************************************************
//
// ***************************************************
void PrintImageInfo(const CImagen& oImagen)
{
	printf("NumColors: %d \nNumPixes: %d \nSize: %d\n", oImagen.GetNumColors(), oImagen.GetNumPixels(), oImagen.GetUncompressedSize());
}

void RemoveAlphaInPngs(CImagen* _oImages, int _iNumberImages)
{
	for (int i = 0; i < _iNumberImages; i++)
	{
		if (_oImages[i].type == CImagen::Png)
		{
			CPng* pPng = static_cast<CPng*>(_oImages + i);
			pPng->RemoveAlpha();
		}
	}
}