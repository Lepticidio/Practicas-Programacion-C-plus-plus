#pragma once
#include <iostream>
#include <glfw3.h>
#include <litegfx.h>
#include <stb_truetype.h>
#include <Vec2.h>
class Font
{
	const float height;
	const stbtt_bakedchar* pBakedChars;
	ltex_t* pTexture;
	float getHeight() const;
	Vec2 getTextSize(const char* text) const;
	Font(const float _height, const stbtt_bakedchar* _pBakedChars);
	public:
		static Font* load(const char* filename, float height);
		void draw(const char* text, const Vec2& pos) const;
};

