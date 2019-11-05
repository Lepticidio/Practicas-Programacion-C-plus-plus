#include "Font.h"
#include <vector>
#include <stb_truetype.h>
#include <litegfx.h>


Font* Font::load(const char* filename, float height)
{

	FILE* pFile(nullptr);	
	fopen_s(&pFile, filename, "r");
	fseek(pFile, 0, SEEK_END);
	const unsigned int uFileSize = (unsigned int)ftell(pFile);
	unsigned char* sBuffer = new unsigned char[uFileSize];
	fread(sBuffer, sizeof(char), uFileSize, pFile);
	Vec2 vTextureSize = Vec2(height * 12, height * 12);
	unsigned char* pAlphaPixels = new unsigned char[vTextureSize.x*vTextureSize.y];
	stbtt_bakedchar* pCharData = new stbtt_bakedchar[128];
	int iCorrectlyLoaded = stbtt_BakeFontBitmap(sBuffer, 0, height, pAlphaPixels, vTextureSize.x, vTextureSize.y,	0, 128, pCharData);
	fclose(pFile);

	if (iCorrectlyLoaded > 0)
	{
		
		const unsigned char* pColorPixels;
		unsigned char* sColorPixels = new unsigned char[vTextureSize.x * vTextureSize.y * 4];
		pColorPixels = sColorPixels;
		printf("%d \n", sizeof(pColorPixels));
		for (int i = 0; i < sizeof(pColorPixels); i++)
		{
			if (i % 4 == 3)
			{
				sColorPixels[i] = pAlphaPixels[(i - 3) / 4];
			}
			else
			{
				sColorPixels[i] = 255;
			}
		}
		Font font = Font(height, *pCharData);
		Font* pResult;
		const ltex_t* pTexture;
		font.texture = *ltex_alloc(vTextureSize.x, vTextureSize.y, 0);
		pTexture = &font.texture;
		ltex_setpixels(pTexture, pColorPixels);

		pResult = &font;
		return pResult;
	}
	else
	{
		return nullptr;
	}

}
Font::Font(const float _height, const stbtt_bakedchar _bakedChars) 
		: height(_height), bakedChars(_bakedChars)
{

}

float Font::getHeight() const
{
	return height;
}
Vec2 Font::getTextSize(const char* text) const
{
	return Vec2(height, std::strlen(text) * height);
}
void Font::draw(const char* text, const Vec2& pos) const
{
	float xPos = pos.x;
	float yPos = pos.y;
	for (int i = 0; i < std::strlen(text); i++)
	{
		char c = text[i];
		stbtt_aligned_quad* quad = nullptr;
		stbtt_GetBakedQuad(&bakedChars, texture.width, texture.height, (int)c, &xPos, &yPos, quad, 1);
		ltex_drawrotsized(&texture, quad->x0, quad->y0, 0, 0, 0, texture.width, texture.height, quad->s0, quad->t0, quad->s1, quad->t1);

	}
}
