#pragma once
#include "../Component.h"
#include "../GameObject.h"
#include <format>
#include <Core.h>
#include <algorithm>

class BoxCollider2D: public Component, public IBoxCollider2D
{
	bool mShowCollider;

	friend class RightPanel;
	friend class Writer;
	friend class Reader;

	bool mStationary;
public:


	BoxCollider2D(GameObject* gameObject);

	//GETTERS
	bool isShowCollider() const override;
	bool isStationary() const override;

	//SETTERS
	void SetShowCollider(const bool a);
	void SetStationary(const bool a);
	

	bool CheckCollision(BoxCollider2D* b, float deltaTime);

	void ResolveCollision(BoxCollider2D* bc, float deltaTime);

	ComponentType GetType() override {
		return ComponentType::BoxCollider2D;
	}
};

