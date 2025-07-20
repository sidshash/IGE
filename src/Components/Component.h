#pragma once
#include "../Editor/Inspectable/IInspectable.h"
#include <IMGUI/imgui.h>
#include <IMGUI/imgui_stdlib.h>

class GameObject;


enum class ComponentType : uint32_t {
	Transform,
	Mesh,
	Rigidbody,
	BoxCollider2D
};

class Component: public IInspectable
{
protected:
	GameObject* gameObject;
public:
	Component(GameObject* gO): gameObject(gO) {}
	virtual ComponentType GetType() = 0;
	virtual ~Component() = default;
};