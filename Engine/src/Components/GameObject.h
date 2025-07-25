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
#include "Script/Script.h"
#include <Core.h>
class GameObject: public IInspectable, public IGameObject
{
	friend class Writer;
	friend class Reader;
	friend class RightPanel;
	std::vector<Component*> components;
	std::string mName;
	int mId;
public:
	~GameObject() { for (Component *c : components) delete c; }
	GameObject(std::string n);
	
	template <class T>
	T* GetComponent();

	template <class T>
	void AddComponent();

	InspectableType GetType() const override { return InspectableType::Gameobject; }


	//GETTERS
	int GetId() const override;
	std::string GetName() const override;

	//SETTERS
	void SetId(const int id) override;
	void SetName(const std::string name) override;

	//INTERNAL FUNCTIONS
	ITransform* GetTransform() override;
	IMesh* GetMesh() override;
	IRigidbody* GetRigidbody() override;
	IBoxCollider2D* GetBoxCollider2D() override;
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


