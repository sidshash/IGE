#include "Vector3.h"

const Vector3 Vector3::UP = Vector3(0, 1, 0);
const Vector3 Vector3::DOWN = Vector3(0, -1, 0);
const Vector3 Vector3::LEFT = Vector3(-1, 0, 0);
const Vector3 Vector3::RIGHT = Vector3(1, 0, 0);

Vector3 Vector3::operator+(const Vector3& other) const {
	return (Vector3(x + other.x, y + other.y, z + other.z));
}
Vector3 Vector3::operator-(const Vector3& other) const {
	return (Vector3(x - other.x, y - other.y, z - other.z));
}
Vector3 Vector3::operator*(const float val) const {
	return (Vector3(x * val, y * val, z * val));
}

Vector3 Vector3::operator*(const Vector3& other) const {
	Vector3 result(0);
	result.x = x * other.x;
	result.y = y * other.y;
	result.z = z * other.z;
	return (Vector3(result.x, result.y, result.z));
}

const float Vector3::Magnitude() const {
	return sqrtf(x * x + y * y + z * z);
}