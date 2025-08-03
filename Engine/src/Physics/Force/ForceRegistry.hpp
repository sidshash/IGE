#pragma once
#include "ForceGenerator.h"
#include <unordered_map>

class ForceRegistry {
	std::unordered_map<ForceGenerator*, Rigidbody*> registry;
public:
	void updateForces();
	void Add(ForceGenerator* forceGenerator, Rigidbody* rigidbody);
};