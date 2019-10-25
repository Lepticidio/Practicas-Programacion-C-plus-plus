#pragma once
#include <iostream>

class Vec2
{
public:

	float x;
	float y;
	Vec2(float _x, float _y);
	Vec2();
	Vec2 operator-();
	Vec2 operator = (float const& obj);

	Vec2 operator = (Vec2 const& obj);
	Vec2 operator + (float const& obj);

	Vec2 operator + (Vec2 const& obj);

	Vec2 operator - (float const& obj);
	Vec2 operator - (Vec2 const& obj);

	Vec2 operator * (float const& obj);

	Vec2 operator * (Vec2 const& obj);

	Vec2 operator / (float const& obj);

	Vec2 operator / (Vec2 const& obj);
	float Length();
	Vec2 Normalize();
	float Dot(Vec2 const& _v2);
	float Angle(const Vec2& other) const;
	float Distance(const Vec2& other) const;

};
