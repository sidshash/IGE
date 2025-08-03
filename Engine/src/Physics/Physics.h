#pragma once
#include "../Locator/Locator.h"
#include "../Components/GameObject.h"
#include "Force/ForceRegistry.hpp"
#include "Force/Drag/Drag.h"
#include <Core.h>
class Physics
{
	ForceRegistry registry;
public:
	Physics()
	{
		Locator::SetPhysics(this);
		Logger::Log(LogLevel::Info, "Physics Engine Created", "Application");
		registry = ForceRegistry();
	}
	void Update(std::vector<GameObject*> &gameObjects);
	void ApplyPhysics(Rigidbody& rb);
	void AddForce(Vector3 force, Rigidbody* rb);
	void RegisterForce(Rigidbody* rigidbody);
};
