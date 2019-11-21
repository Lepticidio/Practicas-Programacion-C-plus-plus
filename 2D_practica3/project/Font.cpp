#include "Font.h"


Font* Font::load(const char* filename, float height)
{

	if (filename != nullptr)
	{
		FILE* pFile(nullptr);
		fopen_s(&pFile, filename,"r");
		fseek(pFile, 0, SEEK_END);
		const unsigned int uFileSize = (unsigned int)ftell(pFile);
		fclose(pFile);
		fopen_s(&pFile, filename, "r");
		if (pFile != nullptr)
		{
			unsigned char* sBuffer = new unsigned char[uFileSize];
			int readResult = fread(sBuffer, sizeof(unsigned char), uFileSize, pFile);
			printf("readResult is %d\n", readResult);
			printf("size is %d\n", uFileSize);
			Vec2 vTextureSize = Vec2(height * 12, height * 12);
			unsigned char* pAlphaPixels = new unsigned char[vTextureSize.x * vTextureSize.y];
			printf("going to create charData pointer\n");
			stbtt_bakedchar* pCharData = new stbtt_bakedchar[128];
			printf("chardata pointer created\n");
			int iCorrectlyLoaded = stbtt_BakeFontBitmap(sBuffer, 0, height, pAlphaPixels, vTextureSize.x, vTextureSize.y, 0, 128, pCharData);
			printf("chars baked\n");
			fclose(pFile);

			if (iCorrectlyLoaded > 0)
			{
				int iSizeColorBuffer = vTextureSize.x * vTextureSize.y * 4;
				unsigned char* sColorPixels = new unsigned char[iSizeColorBuffer];
				for (int i = 0; i < iSizeColorBuffer; i++)
				{
					if (i % 4 == 3)
					{
						sColorPixels[i] = pAlphaPixels[(i - 3) / 4];
					}
					else
					{
						sColorPixels[i] = (unsigned char)255;
					}
				}
				Font* pResult = new Font(height, *pCharData);
				const ltex_t* pTexture = new ltex_t;
				pTexture = ltex_alloc(vTextureSize.x, vTextureSize.y, 0);
				pResult->texture = *pTexture;
				//const unsigned char* pColor = new unsigned char [iSizeColorBuffer];
				ltex_setpixels(pTexture, sColorPixels);

				printf("truly loaded\n");
				printf("\n");
				return pResult;
			}
			else
			{
				printf("error loading\n");
				return nullptr;
			}
		}
		else
		{
			printf("error finding file\n");
			return nullptr;

		}
	}
	else
	{
		printf("filename null\n");
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
	printf("text: %s  has length %d\n", text, strlen(text));
	for (int i = 0; i < std::strlen(text); i++)
	{
		int c = (int)text[i];
		printf("fCharPos of %c is %f\n", c, xPos);
		stbtt_aligned_quad quad;// = new stbtt_aligned_quad;
		//printf("Drawing character of index %d \n",(int)c);
		stbtt_GetBakedQuad(&bakedChars, texture.width, texture.height, c, &xPos, &yPos, &quad, 1);
		//ltex_drawrotsized(&texture, fCharPos, yPos, 0, 0, 0, quad->x0 - quad->x1, quad->y0 - quad->y1, quad->s0, quad->t0, quad->s1, quad->t1);
		ltex_drawrotsized(&texture, quad.x0, quad.y0, 0, 0, 0, quad.x1 - quad.x0, quad.y1 - quad.y0, quad.s0, quad.t0, quad.s1, quad.t1);
	}
}
