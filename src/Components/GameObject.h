#pragma once
#include <vector>
#include "Component.h"
#include <iostream>
#include <IMGUI/imgui.h>
#include <IMGUI/imgui_stdlib.h>
#include "../Util/Random.hpp"
#include "Transform/Transform.h"
#include "Mesh/Mesh.h"
#include "Rigidbody/Rigidbody.h"
#include "BoxCollider2D/BoxCollider2D.h"
class GameObject: public IInspectable
{
	std::vector<Component*> components;

public:
	std::string name;
	int id;
	template <class T>
	T* GetComponent();
	template <class T>
	void AddComponent();
	~GameObject() { for (Component *c : components) delete c; }
	GameObject(std::string n) : name(n), id(Random::GenerateRandomID()) {}
	void DrawInspectable() override;
};

template <class T>

T* GameObject::GetComponent() {
	for (Component* c : components) {
		if (auto* casted = dynamic_cast<T*>(c)) {
			return casted;
		}
	}
	return nullptr;
}


template <class T>

void GameObject::AddComponent() {
	if (GetComponent<T>() == nullptr) {
		T* comp = new T(this);
		components.push_back(new T(this));
	}
}

