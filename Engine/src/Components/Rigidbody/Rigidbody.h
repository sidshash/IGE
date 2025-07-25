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
	bool mGravity;

	Vector3 mVelocity, mAcceleration;

	float mRestitution;

public:
	Rigidbody(GameObject* gO);
	void Update(float deltaTime);
	
	//GETTERS
	bool isGravity() const override;
	Vector3 GetVelocity() const override;
	Vector3 GetAcceleration() const override;
	float GetRestitution() const override;

	//SETTERS
	void SetGravity(const bool a) override;
	void SetVelocity(const Vector3& velocity) override;
	void SetAcceleration(const Vector3& acceleration) override;
	void SetRestitution(const float restitution) override;

	ComponentType GetType() override {
		return ComponentType::Rigidbody;
	}
};

