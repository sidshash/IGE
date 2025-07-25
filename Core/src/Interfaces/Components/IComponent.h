#pragma once
#include "../../ENGINE_API.h"

enum class ENGINE_API ComponentType {
	Transform,
	Mesh,
	Rigidbody,
	BoxCollider2D,
	Script
};

class ENGINE_API IComponent {
protected:
	IComponent() = default;
	virtual ~IComponent() = default;
};