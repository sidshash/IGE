#pragma once
#include "../Locator/Locator.h"
#include "Vector/Vector.h"
#include "../Logger/Logger.h"
class Physics
{
public:
	Physics()
	{
		Locator::SetPhysics(this);
		Logger::Log(LogLevel::Info, "Physics Engine Created", "Application");
	}
};

