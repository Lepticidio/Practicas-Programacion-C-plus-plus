#include "Background.h"
Background::Background(const ltex_t* tex) : Drawable(tex)
{

}
void Background::SetScrollRatio(float _fScrollRatio)
{
	fScrollRatio = _fScrollRatio;
}
void Background::SetScrollSpeed(Vec2 _vScrollSpeed)
{
	vScrollSpeed = _vScrollSpeed;
}
float Background::GetScrollRatio()
{
	return fScrollRatio;
}
Vec2 Background::GetScrollSpeed()
{
	return vScrollSpeed;
}