#pragma once
#include <iostream>
#include <Vec2.h>
float ToDegrees(float radians)
{
	return radians * 57.2958f;
}	
Vec2::Vec2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
Vec2::Vec2()
	{
		x = 0;
		y = 0;
	}
Vec2 Vec2:: operator-()
	{
		Vec2 res;
		res.x = -x;
		res.y = -y;
		return res;
	}
Vec2 Vec2:: operator = (float const& obj)
	{
		Vec2 res;
		res.x = x;
		res.y = y;
		return res;
	}

Vec2 Vec2:: operator = (Vec2 const& obj)
	{
		Vec2 res;
		res.x = obj.x;
		res.y = obj.y;
		return res;
	}
Vec2 Vec2:: operator + (float const& obj)
	{
		Vec2 res;
		res.x = x + obj;
		res.y = y + obj;
		return res;
	}

Vec2 Vec2::operator + (Vec2 const& obj)
	{
		Vec2 res;
		res.x = x + obj.x;
		res.y = y + obj.y;
		return res;
	}

Vec2 Vec2:: operator - (float const& obj)
	{
		Vec2 res;
		res.x = x - obj;
		res.y = y - obj;
		return res;
	}

Vec2 Vec2:: operator - (Vec2 const& obj)
	{
		Vec2 res;
		res.x = x - obj.x;
		res.y = y - obj.y;
		return res;
	}
Vec2 Vec2:: operator * (float const& obj)
	{
		Vec2 res;
		res.x = x * obj;
		res.y = y * obj;
		return res;
	}

Vec2 Vec2:: operator * (Vec2 const& obj)
	{
		Vec2 res;
		res.x = x * obj.x;
		res.y = y * obj.y;
		return res;
	}

Vec2 Vec2:: operator / (float const& obj)
	{
		Vec2 res;
		res.x = x / obj;
		res.y = y / obj;
		return res;
	}

Vec2 Vec2:: operator / (Vec2 const& obj)
	{
		Vec2 res;
		res.x = x / obj.x;
		res.y = y / obj.y;
		return res;
	}

float Vec2::Length()
{
	return sqrt(x * x + y * y);
}

Vec2 Vec2:: Normalize()
{
	Vec2 res(x, y);
	const float length = Length();
	return res / length;
}

float Vec2:: Dot(Vec2 const& _v2)
{
	return x * _v2.x + y * _v2.y;
}

float Vec2::Angle(const Vec2& other) const
{
	return ToDegrees(atan2(other.y, other.x) - atan2(y, x));
}
float Vec2::Distance(const Vec2& other) const
{
	return Vec2(x - other.x, y - other.y).Length();
}
