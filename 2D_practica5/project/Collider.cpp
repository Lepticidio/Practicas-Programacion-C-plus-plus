#include "Collider.h"

bool Collider::collides(const Collider& other)
{

}
bool Collider::collides(const Vec2& circlePos, float circleRadius)
{

}
bool Collider::collides(const Vec2& rectPos, const Vec2& rectSize)
{

}
bool Collider::collides(const Vec2& pixelsPos, const Vec2& pixelsSize,
	const uint8_t* pixels)
{

}
bool Collider::checkCircleCircle(const Vec2& pos1, float radius1,
	const Vec2& pos2, float radius2)
{

}
bool Collider::checkCircleRect(const Vec2& circlePos, float circleRadius,
	const Vec2& rectPos, const Vec2& rectSize)
{

}
bool Collider::checkRectRect(const Vec2& rectPos1, const Vec2& rectSize1,
	const Vec2& rectPos2, const Vec2& rectSize2)
{

}
bool Collider::checkCirclePixels(const Vec2& circlePos, float circleRadius,
	const Vec2& pixelsPos, const Vec2& pixelsSize, const uint8_t* pixels)
{

}
bool Collider::checkPixelsPixels(
	const Vec2& pixelsPos1, const Vec2& pixelsSize1, const uint8_t* pixels1,
	const Vec2& pixelsPos2, const Vec2& pixelsSize2, const uint8_t* pixels2)
{

}
bool Collider::checkPixelsRect(
	const Vec2& pixelsPos, const Vec2& pixelsSize, const uint8_t* pixels,
	const Vec2& rectPos, const Vec2& rectSize)
{

}
