#include "Vector.h"


Vector& Vector::operator+(const Vector& other) {
	return *(new Vector(x + other.x, y + other.y, z + other.z));
}
Vector& Vector::operator-(const Vector& other) {
	return *(new Vector(x - other.x, y - other.y, z - other.z));
}
Vector& Vector::operator*(const float val) {
	return *(new Vector(x * val, y * val, z * val));
}

Vector& Vector::operator*(const Vector& other) {
	Vector result(0);
	result.x = x * other.x;
	result.y = y * other.y;
	result.z = z * other.z;
	return *(new Vector(result.x, result.y, result.z));
}