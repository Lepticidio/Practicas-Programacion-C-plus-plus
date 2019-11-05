#pragma once
#include <Vec2.h>
#include "..\project\Font.h"
class Text
{
	public:
		const char* sText;
		bool active = false;
		Vec2 vPosition;
		Font font;
		float r;
		float g;
		float b;
		float fSpeed;

		Text(const char* _text, Vec2 _vPosition, Font _font, float _r, float _g, float _b, float _fSpeed);
		void Draw();

};

