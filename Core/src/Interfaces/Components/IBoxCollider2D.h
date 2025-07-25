#pragma once
#include "IComponent.h"
#include "../../ENGINE_API.h"

class ENGINE_API IBoxCollider2D: public IComponent {
public:
	IBoxCollider2D();
	virtual ~IBoxCollider2D();
	//GETTERS
	virtual bool isShowCollider() const = 0;
	virtual bool isStationary() const = 0;

	//SETTER
	virtual void SetShowCollider(const bool a) = 0;
	virtual void SetStationary(const bool a) = 0;
};
