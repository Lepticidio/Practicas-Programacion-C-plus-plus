#include "Sprite.h"
const ltex_t* Sprite::getTexture() const
{
	return &texture;
}
void Sprite::setTexture(const ltex_t* tex, int hframes = 1, int vframes = 1)
{

}
lblend_t Sprite::getBlend() const
{
	return blend;
}
void Sprite::setBlend(lblend_t mode)
{
	blend = mode;
}
float Sprite::getRed() const
{
	return fRed;
}
float Sprite::getGreen() const
{
	return fGreen;
}
float Sprite::getBlue() const
{
	return fBlue;
}
float Sprite::getAlpha() const
{
	return fAlpha;
}
void Sprite::setColor(float r, float g, float b, float a)
{
	fRed = r;
	fGreen = g;
	fBlue = b;
	fAlpha = a;
}
const Vec2& Sprite::getPosition() const
{
	return vPosition;
}
void Sprite::setPosition(const Vec2& pos)
{
	vPosition = pos;
}
float Sprite::getAngle() const
{
	return fAngle;
}
void Sprite::setAngle(float angle)
{
	fAngle = angle;
}
const Vec2& Sprite::getScale() const
{
	return vScale;
}
void Sprite::setScale(const Vec2& scale)
{
	vScale = scale;
}
int Sprite::getHframes() const
{
	return iHorizontalFrames;
}
int Sprite::getVframes() const
{
	return iVerticalFrames;
}
void Sprite::update(float deltaTime)
{

}
void Sprite::draw() const
{

}