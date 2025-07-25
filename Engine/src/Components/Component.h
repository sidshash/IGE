#pragma once
#include "../Editor/Inspectable/IInspectable.h"
#include <cstdint>
#include <Core.h>
class GameObject;

class Component: public IInspectable, public virtual IComponent
{
protected:
	GameObject* gameObject;
public:
	Component(GameObject* gO): gameObject(gO) {}
	virtual ComponentType GetType() = 0;
	virtual ~Component() = default;
	InspectableType GetType() const override { return InspectableType::Component; }
};