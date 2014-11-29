#pragma once
#include <iostream>

/** 
Struct that represents a Vector2
*/
struct Vec2
{
	/// X position
	float x;
	/// Y position
	float y;

	/** 
	Creates a Vec2 with no initialization
	*/
	Vec2() { }

	/**
	Creates a Vec2 with full initialization

	@param float - X position
	@param float - Y position
	*/
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
	// if a Vec2 is cout'd it will form this structure: Vec2(x,y) 
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