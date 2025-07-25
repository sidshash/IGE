#include "Vector2.h"


Vector2 Vector2::operator+(const Vector2& other) {
	return (Vector2(x + other.x, y + other.y));
}
Vector2 Vector2::operator-(const Vector2& other) {
	return (Vector2(x - other.x, y - other.y));
}
Vector2 Vector2::operator*(const float val) {
	return (Vector2(x * val, y * val));
}

Vector2 Vector2::operator*(const Vector2& other) {
	Vector2 result(0);
	result.x = x * other.x;
	result.y = y * other.y;
	return (Vector2(result.x, result.y));
}