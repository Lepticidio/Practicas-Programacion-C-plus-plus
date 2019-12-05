#include "Collider.h"

float clamp(float n, float lower, float upper)
{
	n = (n > lower)* n + !(n > lower)* lower;
	return (n < upper) * n + !(n < upper) * upper;
}

bool Collider::collides(Collider& other)
{
	return false;
}
bool Collider::collides(const Vec2& circlePos, float circleRadius)
{
	return false;
}
bool Collider::collides(const Vec2& rectPos, const Vec2& rectSize)
{
	return false;
}
bool Collider::collides(const Vec2& pixelsPos, const Vec2& pixelsSize,
	const uint8_t* pixels)
{
	return false;
}
bool Collider::checkCircleCircle(const Vec2& pos1, float radius1,
	const Vec2& pos2, float radius2)
{
	Vec2 vDifference(pos1.x - pos2.x, pos1.y - pos2.y);
	if (vDifference.Length() > radius1 + radius2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Collider::checkCircleRect(const Vec2& circlePos, float circleRadius,
	const Vec2& rectPos, const Vec2& rectSize)
{ 
	float closestX = clamp(circlePos.x, rectPos.x - rectSize.x/2, rectPos.x + rectSize.x/2);
	float closestY = clamp(circlePos.y, rectPos.y - rectSize.y/2, rectPos.y + rectSize.y/2);
	return (Vec2(closestX, closestY) - circlePos).Length() < circleRadius;
}
bool Collider::checkRectRect(const Vec2& rectPos1, const Vec2& rectSize1,
	const Vec2& rectPos2, const Vec2& rectSize2)
{
	if (rectPos1.x > rectPos2.x - rectSize2.x / 2.  - rectSize1.x/2. && rectPos1.x < rectPos2.x + rectSize2.x / 2. + rectSize1.x / 2. &&
		rectPos1.y > rectPos2.y - rectSize2.y / 2. - rectSize1.y / 2. && rectPos1.y < rectPos2.y + rectSize2.y / 2. + rectSize1.y / 2.)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Collider::checkCirclePixels(const Vec2& circlePos, float circleRadius,
	const Vec2& pixelsPos, const Vec2& pixelsSize, const uint8_t* pixels)
{
	return false;
}
bool Collider::checkPixelsPixels(
	const Vec2& pixelsPos1, const Vec2& pixelsSize1, const uint8_t* pixels1,
	const Vec2& pixelsPos2, const Vec2& pixelsSize2, const uint8_t* pixels2)
{
	float minX1 = pixelsPos1.x - pixelsSize1.x / 2.f;
	float maxX1 = pixelsPos1.x + pixelsSize1.x / 2.f;
	float minY1 = pixelsPos1.y - pixelsSize1.y / 2.f;
	float maxY1 = pixelsPos1.y + pixelsSize1.y / 2.f;
	float minX2 = pixelsPos2.x - pixelsSize2.x / 2.f;
	float maxX2 = pixelsPos2.x + pixelsSize2.x / 2.f;
	float minY2 = pixelsPos2.y - pixelsSize2.y / 2.f;
	float maxY2 = pixelsPos2.y + pixelsSize2.y / 2.f;

	printf("%f > %f, %f < %f, %f > %f, %f < %f\n",  maxX1, minX2, minX1, maxX2, maxY1, minY2, minY1, maxY2);

	if (maxX1 > minX2&& minX1 < maxX2 && maxY1 > minY2&& minY1 < maxY2)
	{

		float minOverlapX1 = 0;
		float maxOverlapX1 = 1;
		float minOverlapY1 = 0;
		float maxOverlapY1 = 1;
		float minOverlapX2 = 0;
		float maxOverlapX2 = 1;
		float minOverlapY2 = 0;
		float maxOverlapY2 = 1;

		if (minX1 < minX2)
		{
			minOverlapX1 = minX2 / maxX1;
		}
		else
		{
			minOverlapX2 = minX1 / maxX2;
		}
		if (maxX1 > maxX2)
		{
			maxOverlapX2 = maxX2 / maxX1;
		}
		else
		{
			maxOverlapX1 = maxX1 / maxX2;
		}

		if (minY1 < minY2)
		{
			minOverlapY1 = minY2 / maxY1;
		}
		else
		{
			minOverlapY2 = minY1 / maxY2;
		}
		if (maxY1 > maxY2)
		{
			maxOverlapY2 = maxY2 / maxY1;
		}
		else
		{
			maxOverlapY1 = maxY1 / maxY2;
		}
		int iWidthOverlap1 = (int)((maxOverlapX1 - minOverlapX1) * pixelsSize1.x);
		int iHeightOverlap1 = (int)((maxOverlapY1 - minOverlapY1) * pixelsSize1.y);
		int iWidthOverlap2 = (int)((maxOverlapX2 - minOverlapX2) * pixelsSize2.x);
		int iHeightOverlap2 = (int)((maxOverlapY2 - minOverlapY2) * pixelsSize2.y);

		return true;
	}
	else
	{
		return false;
	}
}
bool Collider::checkPixelsRect(
	const Vec2& pixelsPos, const Vec2& pixelsSize, const uint8_t* pixels,
	const Vec2& rectPos, const Vec2& rectSize)
{
	return false;
}
