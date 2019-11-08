#pragma once

class CImagen
{
public:
	~CImagen();

	int	SetImageFile (const char *pszFile);
	unsigned int GetNumPixels () const;
	unsigned int GetUncompressedSize () const;
	unsigned int GetNumColors() const;
	const unsigned char *	GetBuffer () const;
	int Draw () const;
	int InvertImage ();
	enum ImageType
	{
		Jpg, Png
	};
	ImageType type;

protected:
	unsigned int m_uResX;
	unsigned int m_uResY;
	unsigned int m_uColorBytes;
	unsigned int m_uSize;
	unsigned char *	m_pBuffer;
};