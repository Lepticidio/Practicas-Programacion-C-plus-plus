// Practica15.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>


struct CStream
{
	enum class EMode
	{
		Read,
		Write,
		ReadWrite
	};
	virtual int Open(const char* _pszName, EMode _eMode)
	{
		printf("Opening stream \n");
		return 0;
	}
	virtual int Close(int _iIdStream)
	{
		printf("Closing stream \n");
		return 0;
	}
	virtual int Write(int _iId, unsigned char* _pBuffer, unsigned int _uSize)
	{
		printf("Writing stream \n");
		return 0;
	}
};
struct CFile: CStream
{
	virtual int Open(const char* _pszName, EMode _eMode) override
	{
		printf("Opening file \n");
		return 0;
	}
	virtual int Close(int _iIdStream) override
	{
		printf("Closing file \n");
		return 0;
	}
	virtual int Write(int _iId, unsigned char* _pBuffer, unsigned int _uSize) override
	{
		printf("Writing file \n");
		return 0;
	}
};
struct CCom : CFile
{
	virtual int Open(const char* _pszName, EMode _eMode) override
	{
		printf("Opening communication \n");
		return 0;
	}
	virtual int Close(int _iIdStream) override
	{
		printf("Closing communication \n");
		return 0;
	}
	virtual int Write(int _iId, unsigned char* _pBuffer, unsigned int _uSize) override
	{
		printf("Writing communication \n");
		return 0;
	}
};
struct CTcp : CCom
{
	virtual int Open(const char* _pszName, EMode _eMode) override
	{
		printf("Opening connection TCP\n");
		return 0;
	}
	virtual int Close(int _iIdStream) override
	{
		printf("Closing communication TCP\n");
		return 0;
	}
	virtual int Write(int _iId, unsigned char* _pBuffer, unsigned int _uSize) override
	{
		printf("Writing communication TCP\n");
		return 0;
	}
};

int main()
{
	CStream oStream;
	CFile oFile;
	CCom oCom;
	CTcp oTcp;

	const char* sStreamName ("Stream");
	const char* sFileName("File");
	const char* sComName("Com");
	const char* sTcpName("Tcp");

	CStream::EMode eMode = CStream::EMode::Read;

	oStream.Open(sStreamName, eMode);
	oFile.Open(sFileName, eMode);
	oCom.Open(sComName, eMode);
	oTcp.Open(sTcpName, eMode);
}
