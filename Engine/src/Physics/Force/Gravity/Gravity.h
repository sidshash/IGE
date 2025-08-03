#pragma once
#include "../ForceGenerator.h"
class Gravity: public ForceGenerator
{
	void ApplyForce(Rigidbody& rb) override;
};

