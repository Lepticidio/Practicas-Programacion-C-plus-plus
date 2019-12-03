#include "CircleCollider.h"

CircleCollider::CircleCollider(float _fRadius, Vec2 _vPosition) : fRadius(_fRadius), vPosition(_vPosition)
{
	type = COLLISION_CIRCLE;
}
bool CircleCollider::collides(Collider& other) 
{
	if (&other == nullptr)
	{
		return false;
	}
	else
	{
		switch (other.type)
		{
			case COLLISION_CIRCLE:
			{
				Collider* pCollider = &other;
				CircleCollider* pCircle = static_cast<CircleCollider*>(pCollider);
				return checkCircleCircle(vPosition, fRadius, pCircle->vPosition, pCircle->fRadius);
			}
			break;
			case COLLISION_RECT:
			{
				return false;
			}
			break;
			default:
			{
				return false;
			}
		}

	}
}
bool CircleCollider::collides(const Vec2& circlePos, float circleRadius)
{
	return checkCircleCircle(vPosition, fRadius, circlePos, circleRadius);
}
bool CircleCollider::collides(const Vec2& rectPos, const Vec2& rectSize)
{
	return checkCircleRect(vPosition, fRadius, rectPos, rectSize);
}
bool CircleCollider::collides(const Vec2& pixelsPos, const Vec2& pixelsSize,
	const uint8_t* pixels) 
{
	return checkCirclePixels(vPosition, fRadius, pixelsPos, pixelsSize, pixels);
}