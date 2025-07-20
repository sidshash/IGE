#pragma once
#include "../Component.h"
#include "../../Physics/Vector/Vector.h"
#include "../GameObject.h"
#include <format>

class BoxCollider2D: public Component
{
	bool showCollider;

	float temp;

public:

	bool isStationary;

	BoxCollider2D(GameObject* gameObject);

	void DrawInspectable() override;

	bool GetShowCollider();

	//Vector GetPosition();

	//Vector GetSize();

	bool CheckCollision(BoxCollider2D* b, float deltaTime);

	void ResolveCollision(BoxCollider2D* bc, float deltaTime);

};

