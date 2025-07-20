#pragma once
#include <cmath>

class Vector
{
public:
	float x, y, z;

	Vector(float a, float b, float c) : x(a), y(b), z(c) {}

	Vector(float _X) : x(_X), y(_X), z(_X) {}
	
	Vector& operator+(const Vector& other);	//vector addition

	Vector& operator-(const Vector& other);	//vector subtaction

	Vector& operator*(const float val); //scalar multiplication

	Vector& operator*(const Vector& other);

	float Length() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	Vector Normalized() const {
		float len = Length();
		if (len == 0.0f)
			return Vector(0.0f, 0.0f, 0.0f); // Avoid division by zero
		return Vector(x / len, y / len, z / len);
	}
};

