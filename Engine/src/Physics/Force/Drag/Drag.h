#pragma once
#include "../ForceGenerator.h"
class Drag : public ForceGenerator
{
public:
	Drag();
	void ApplyForce(Rigidbody& rb) override;
};

