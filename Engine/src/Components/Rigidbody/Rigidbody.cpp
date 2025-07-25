#include "Rigidbody.h"
#include "../../Application.h"

Rigidbody::Rigidbody(GameObject* gO) :
	Component(gO),
	mVelocity(0),
	mAcceleration(0),
	mGravity(false),
	mRestitution(1)
{
}



void Rigidbody::Update(float deltaTime) {

	Transform* t = gameObject->GetComponent<Transform>();

	if (t == nullptr) return;

	mVelocity = mVelocity + ((mGravity? Vector3(mAcceleration.x, mAcceleration.y - 9.81f, mAcceleration.z) : mAcceleration) * deltaTime);

	Vector3 position = t->GetPosition();

	position = position + (mVelocity * deltaTime);

	t->SetPosition(position);

}

// GETTERS

bool Rigidbody::isGravity() const
{
	return mGravity;
}

Vector3 Rigidbody::GetVelocity() const
{
	return mVelocity;
}

Vector3 Rigidbody::GetAcceleration() const
{
	return mAcceleration;
}

float Rigidbody::GetRestitution() const
{
	return mRestitution;
}

//	SETTERS

void Rigidbody::SetGravity(const bool a)
{
	mGravity = a;
}

void Rigidbody::SetVelocity(const Vector3& velocity)
{
	mVelocity = velocity;
}

void Rigidbody::SetAcceleration(const Vector3& acceleration)
{
	mAcceleration = acceleration;
}

void Rigidbody::SetRestitution(const float restitution)
{
	mRestitution = restitution;
}
