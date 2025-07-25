#include "Transform.h"

Transform::Transform(GameObject* gameObject) :
	Component(gameObject),
	mPosition(0),
	mScale(1),
	mRotation(0)
{
}

Vector3 Transform::GetPosition() const
{
	return mPosition;
}

Vector3 Transform::GetScale() const
{
	return mScale;
}

Vector3 Transform::GetRotation() const
{
	return mRotation;
}

void Transform::SetPosition(const Vector3& position)
{
	mPosition = position;
}

void Transform::SetScale(const Vector3& scale)
{
	mScale = scale;
}

void Transform::SetRotation(const Vector3& rotation)
{
	mRotation = rotation;
}




