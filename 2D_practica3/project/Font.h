#pragma once
#include <Vec2.h>
#include <stb_truetype.h>
#include <litegfx.h>
class Font
{
	const float height;
	stbtt_bakedchar bakedChars;
	ltex_t texture;
	float getHeight() const;
	Vec2 getTextSize(const char* text) const;
	Font(const float _height, const stbtt_bakedchar _bakedChars);
	public:
		static Font* load(const char* filename, float height);
		void draw(const char* text, const Vec2& pos) const;
};

