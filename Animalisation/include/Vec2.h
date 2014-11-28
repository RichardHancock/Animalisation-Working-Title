#pragma once
#include <iostream>

struct Vec2
{
	float x;
	float y;
	Vec2()
	{

	}
	Vec2(float initX, float initY)
	{
		x = initX;
		y = initY;
	}

	//Operator Overloading

	Vec2* operator += (Vec2 b)
	{
		x += b.x;
		y += b.y;
		return this;
	}
	Vec2* operator -= (Vec2 b)
	{
		x -= b.x;
		y -= b.y;
		return this;
	}

};

inline Vec2 operator + (Vec2 a, Vec2 b)
{
	Vec2 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return result;
}
inline Vec2 operator - (Vec2 a, Vec2 b)
{
	Vec2 result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return result;
}
inline Vec2 operator / (Vec2 a, Vec2 b)
{
	Vec2 result;
	result.x = a.x / b.x;
	result.y = a.y / b.y;
	return result;
}
inline Vec2 operator * (Vec2 a, Vec2 b)
{
	Vec2 result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	return result;
}
inline std::ostream& operator << (std::ostream& os, const Vec2& a)
{
	os << "Vec2(" << a.x << "," << a.y << ") ";
	return os;
}
inline bool operator == (const Vec2& a, const Vec2& b)
{
	return (a.x == b.x && a.y == b.y) ? true : false;
}
inline bool operator != (const Vec2& a, const Vec2& b)
{
	return (a.x != b.x || a.y != b.y) ? true : false;
}