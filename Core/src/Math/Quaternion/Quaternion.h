#pragma once
#include "../../ENGINE_API.h"
#include <cmath>
#include "../../Math/Vectors/Vector3.h"
class ENGINE_API Quaternion
{
	float x, y, z, w;
public:
	Quaternion(float x_, float y_, float z_, float w_);
	static Quaternion FromEuler(float pitch, float yaw, float roll);
	inline friend Quaternion operator*(const Quaternion& q1, const Quaternion& q2);
	static Vector3 RotateVectorByQuaternion(const Vector3& v, const Quaternion& q);
	Quaternion Slerp(Quaternion a, Quaternion b, float t);

};

