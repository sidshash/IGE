#pragma once
#include "../Editor/Inspectable/IInspectable.h"
#include <IMGUI/imgui.h>
#include <IMGUI/imgui_stdlib.h>

class GameObject;

class Component: public IInspectable
{
protected:
	GameObject* gameObject;
public:
	Component(GameObject* gO): gameObject(gO) {}
	virtual ~Component() = default;
};