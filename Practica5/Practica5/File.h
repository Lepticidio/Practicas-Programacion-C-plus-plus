#pragma once

void* OpenFile(const char* _sFileName, const char* _sMode);
int CloseFile(void*);
unsigned int ReadFile(void* _pFile, char* _pBuffer, unsigned int _uBufferSize);
unsigned int WriteFile(void* _pFile, const char* _pBuffer, unsigned int _uBufferSize);