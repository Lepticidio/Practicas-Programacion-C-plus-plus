#include "Imagen.h"

class CPng : public CImagen
{
public:
	int SetPngFile(const char *pszFile);
	void RemoveAlpha();

private:
	int UncompressImage();
};