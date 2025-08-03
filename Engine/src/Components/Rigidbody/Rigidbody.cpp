#include "Rigidbody.h"
#include "../../Application.h"

Rigidbody::Rigidbody(GameObject* gO) :
	Component(gO),
	mVelocity(0),
	mAcceleration(0),
	mGravity(false),
	mRestitution(1),
	mInverseMass(1),
	mAngularVelocity(0),
	mAngularAcceleration(0),
	mDrag(0.5f)
{
	Locator::GetPhysics()->RegisterForce(this);
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

unsigned int Rigidbody::GetInverseMass() const
{
	return mInverseMass;
}

float Rigidbody::GetDrag() const
{
	return mDrag;
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

void Rigidbody::SetInverseMass(const unsigned int inverseMass)
{
	mInverseMass = inverseMass;
}

void Rigidbody::SetDrag(const float drag)
{
	mDrag = drag;
}

void Rigidbody::Integrate(float dt)
{

	Transform* transform = gameObject->GetComponent<Transform>();
	if (transform == nullptr) return;	//TRANSFORM DOESN'T EXIST TO UPDATE POSITION

	Transform& t = *transform;

	//INTEGRATE POSITION
	
	mVelocity = mVelocity + mAcceleration * dt;

	Vector3 position = t.GetPosition();
	position = position + mVelocity * dt;
	t.SetPosition(position);

	//INTEGRATE ROTATION
	mAngularVelocity = mAngularVelocity + mAngularAcceleration * dt;
	Vector3 rotation = t.GetRotation();
	rotation = rotation + mAngularVelocity * dt;
	t.SetRotation(rotation);

	//RESET ACCUMULATORS
	mAcceleration = Vector3(0);
	mAngularAcceleration = Vector3(0);

}

void Rigidbody::AddForce(Vector3 force)
{
	Locator::GetPhysics()->AddForce(force, this);
}
