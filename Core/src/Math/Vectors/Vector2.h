#pragma once
#include <cmath>
#include "../../ENGINE_API.h"
class ENGINE_API Vector2
{
public:
	float x, y;

	Vector2(float a, float b) : x(a), y(b) {}

	Vector2(float _X) : x(_X), y(_X) {}

	Vector2() : x(0), y(0) {}

	Vector2 operator+(const Vector2& other);	//vector addition

	Vector2 operator-(const Vector2& other);	//vector subtaction

	Vector2 operator*(const float val); //scalar multiplication

	Vector2 operator*(const Vector2& other);

	float Length() const {
		return std::sqrt(x * x + y * y);
	}

	Vector2 Normalized() const {
		float len = Length();
		if (len == 0.0f)
			return Vector2(0.0f, 0.0f); // Avoid division by zero
		return Vector2(x / len, y / len);
	}
};

