#pragma once
#include "../../Components/Rigidbody/Rigidbody.h"

enum class ForceType {
	GRAVITY,
	TORQUE,
	FRICTION
};

class ForceGenerator
{
public:
	virtual void ApplyForce(Rigidbody& rb) = 0;
};

