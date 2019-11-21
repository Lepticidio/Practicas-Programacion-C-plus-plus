#include "Sprite.h"
using namespace std;


ostream& operator<<(ostream& os, const Vec2& v)
{
	os << '(';
	os << v.x;
	os << ',';
	os << v.y;
	os << ')';


	return os;
}
Sprite::Sprite(const ltex_t* tex, int hframes, int vframes)
	:texture(*tex), iHorizontalFrames(hframes), iVerticalFrames(vframes)
{

}
const ltex_t* Sprite::getTexture() const
{
	return &texture;
}
void Sprite::setTexture(const ltex_t* tex, int hframes, int vframes)
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
Vec2 Sprite::getSize() const
{
	return Vec2(vScale.x * texture.width / iHorizontalFrames, vScale.y * texture.height / iVerticalFrames);
}
const Vec2& Sprite::getPivot() const
{
	return vPivot;
}
void Sprite::setPivot(const Vec2& pivot)
{
	vPivot = pivot;
}
int Sprite::getHframes() const
{
	return iHorizontalFrames;
}
int Sprite::getVframes() const
{
	return iVerticalFrames;
}
int Sprite::getFps() const
{
	return iFps;
}
void Sprite::setFps(int fps)
{
	iFps = fps;
}
float Sprite::getCurrentFrame() const
{
	return iCurrentFrame;
}
void Sprite::setCurrentFrame(int frame)
{
	iCurrentFrame = frame;
}
void Sprite::update(float deltaTime)
{

}
void Sprite::draw() const
{
	Vec2 vSize = getSize();
	printf("%d\n", iCurrentFrame);
	Vec2 vPositionInArray(iCurrentFrame % iHorizontalFrames, iCurrentFrame / iHorizontalFrames);
	std::cout << vPositionInArray << std::endl;
	printf("x: %f, y: %f\n", vPositionInArray.x /(float)iHorizontalFrames, vPositionInArray.y / (float)iVerticalFrames);
	printf("x2: %f, y2: %f\n", (vPositionInArray.x + 1.) / (float)iHorizontalFrames, (vPositionInArray.y + 1.) / (float)iVerticalFrames);
	lgfx_setblend(blend);
	lgfx_setcolor(fRed, fGreen, fBlue, fAlpha);
	ltex_drawrotsized(&texture, vPosition.x, vPosition.y, fAngle, vPivot.x, vPivot.y, vSize.x, vSize.y, 
		vPositionInArray.x /(float)iHorizontalFrames, vPositionInArray.y / (float) iVerticalFrames, (vPositionInArray.x + 1.)/(float)iHorizontalFrames, (vPositionInArray.y + 1.)/(float)iVerticalFrames);
	lgfx_setcolor(1, 1, 1, 1);
}