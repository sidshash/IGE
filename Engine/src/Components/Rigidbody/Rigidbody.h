#pragma once

#include "../Component.h"
#include "../GameObject.h"
#include "../../Locator/Locator.h"
#include <Core.h>

class Application;

class Rigidbody : public Component, public IRigidbody
{
	friend class Writer;
	friend class Reader;
	friend class RightPanel;

	//LINEAR
	bool mGravity;
	float mInverseMass;
	Vector3 mVelocity, mAcceleration;
	float mRestitution;
	float mDrag;

	//ROTATION
	Vector3 mAngularVelocity, mAngularAcceleration;

public:
	Rigidbody(GameObject* gO);
	
	//GETTERS
	bool isGravity() const override;
	Vector3 GetVelocity() const override;
	Vector3 GetAcceleration() const override;
	float GetRestitution() const override;
	float GetInverseMass() const override;
	float GetDrag() const override;

	//SETTERS
	void SetGravity(const bool a) override;
	void SetVelocity(const Vector3& velocity) override;
	void SetAcceleration(const Vector3& acceleration) override;
	void SetRestitution(const float restitution) override;
	void SetInverseMass(float inverseMass) override;
	void SetDrag(const float drag) override;

	void Integrate(float dt);
	ComponentType GetType() override {
		return ComponentType::Rigidbody;
	}
	void AddForce(Vector3 force) override;
};
