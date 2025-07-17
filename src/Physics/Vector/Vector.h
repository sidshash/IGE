#pragma once
class Vector
{
public:
	float x, y, z;
	Vector(float a, float b, float c) : x(a), y(b), z(c) {}
	Vector(float _X) : x(_X), y(_X), z(_X) {}
};

