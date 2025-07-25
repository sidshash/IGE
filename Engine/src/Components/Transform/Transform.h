#pragma once
#include "../Component.h"
#include "../GameObject.h"
#include <Core.h>
class Transform : public Component, public ITransform
{
	Vector3 mPosition, mScale, mRotation;
	friend class RightPanel;
	friend class Writer;
	friend class Reader;
public:
	Transform(GameObject* gameObject);

	//GETTERS
	Vector3 GetPosition() const override;
	Vector3 GetScale() const override;
	Vector3 GetRotation() const override;

	//SETTERS
	void SetPosition(const Vector3& position) override;
	void SetScale(const Vector3& scale) override;
	void SetRotation(const Vector3& rotation) override;


	ComponentType GetType() override {
		return ComponentType::Transform;
	}
};

