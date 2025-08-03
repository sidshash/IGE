#pragma once
#include <cmath>
#include "../../ENGINE_API.h"
class ENGINE_API Vector3
{
public:
	float x, y, z;

	Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
		  
	Vector3(float _X) : x(_X), y(_X), z(_X) {}

	Vector3() : x(0), y(0), z(0) {}
		  
	Vector3 operator+(const Vector3& other) const;	//vector addition
		  
	Vector3 operator-(const Vector3& other) const;	//vector subtaction
		  
	Vector3 operator*(const float val) const; //scalar multiplication
		  
	Vector3 operator*(const Vector3& other) const;

	float Length() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	Vector3 Normalized() const {
		float len = Length();
		if (len == 0.0f)
			return Vector3(0.0f, 0.0f, 0.0f); // Avoid division by zero
		return Vector3(x / len, y / len, z / len);
	}
	
	static const Vector3 UP;
	static const Vector3 DOWN;
	static const Vector3 RIGHT;
	static const Vector3 LEFT;
};

