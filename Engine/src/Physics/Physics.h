#pragma once
#include "../Locator/Locator.h"
#include "../Components/GameObject.h"
#include <Core.h>
class Physics
{
public:
	Physics()
	{
		Locator::SetPhysics(this);
		Logger::Log(LogLevel::Info, "Physics Engine Created", "Application");
	}
	void Update(std::vector<GameObject*> &gameObjects);
};

