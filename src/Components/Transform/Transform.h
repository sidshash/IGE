#pragma once
#include "../Component.h"
#include "../../Physics/Physics.h"
#include "../GameObject.h"
class Transform : public Component
{
public:
	Transform(GameObject* gO): 
		Component(gO),
		position(1),
		scale(1),
		rotation(0)
	{}
	Vector position, scale, rotation;
	void DrawInspectable() override;
};

