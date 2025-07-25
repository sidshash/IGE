#include "Vector3.h"


Vector3 Vector3::operator+(const Vector3& other) {
	return *(new Vector3(x + other.x, y + other.y, z + other.z));
}
Vector3 Vector3::operator-(const Vector3& other) {
	return *(new Vector3(x - other.x, y - other.y, z - other.z));
}
Vector3 Vector3::operator*(const float val) {
	return *(new Vector3(x * val, y * val, z * val));
}

Vector3 Vector3::operator*(const Vector3& other) {
	Vector3 result(0);
	result.x = x * other.x;
	result.y = y * other.y;
	result.z = z * other.z;
	return *(new Vector3(result.x, result.y, result.z));
}