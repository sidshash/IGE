#pragma once

#include "../Component.h"
#include "../GameObject.h"
#include "../../Physics/Vector/Vector.h"
#include "../../Locator/Locator.h"
#include "../../Logger/Logger.h"

class Application;

class Rigidbody : public Component
{
	bool gravity;

	Vector velocity, acceleration;

	float restitution;

public:
	Rigidbody(GameObject* gO);
	void DrawInspectable() override;
	void Update(float deltaTime);
	float GetRestitution() const { return restitution; }
	void SetVelocity(Vector vel) { velocity = vel; }
	Vector GetVelocity() const { return velocity; }
};

