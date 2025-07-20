#pragma once
#include "../Locator/Locator.h"
#include "../Logger/Logger.h"
#include "../Components/GameObject.h"
#include "../Logger/Logger.h"
class Physics
{
	double mDeltaTime;
public:
	Physics() :
		mDeltaTime(0)
	{
		Locator::SetPhysics(this);
		Logger::Log(LogLevel::Info, "Physics Engine Created", "Application");
	}
	void SetDeltaTime(float deltaTime);
	void Update(std::vector<GameObject*> gameObjects);
};

