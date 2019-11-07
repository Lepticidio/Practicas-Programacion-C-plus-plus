#include "Text.h"

Text::Text(const char* _text, Vec2 _vPosition, Font _font, float _r, float _g, float _b, float _fSpeed)
	:sText(_text), vPosition(_vPosition), font(_font), r(_r), g(_g), b(_b), fSpeed(_fSpeed)
{

}
void Text::Draw()
{
	lgfx_setcolor(r, g, b, 1);
	font.draw(sText, vPosition);
}