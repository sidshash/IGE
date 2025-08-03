#include "ForceRegistry.hpp"

void ForceRegistry::updateForces()
{
	for (const std::pair<ForceGenerator*, Rigidbody*> pair : registry) {
		if (pair.first != nullptr && pair.second != nullptr) {

			ForceGenerator& fg = *pair.first;
			Rigidbody& rb = *pair.second;

			fg.ApplyForce(rb);
		}
	}
}

void ForceRegistry::Add(ForceGenerator* forceGenerator, Rigidbody* rigidbody)
{
	registry[forceGenerator] = rigidbody;
}
