#pragma once
#include "IComponent.h"
#include "../../ENGINE_API.h"
#include "../../Math/Vectors/Vector3.h"

class ENGINE_API IRigidbody: public IComponent {
public:
	IRigidbody();
	virtual ~IRigidbody();
//	GETTERS
	virtual bool isGravity() const = 0;
	virtual Vector3 GetVelocity() const = 0;
	virtual Vector3 GetAcceleration() const = 0;
	virtual float GetRestitution() const = 0;
	virtual unsigned int GetInverseMass() const = 0;
	virtual float GetDrag() const = 0;

//	 SETTER
	virtual void SetGravity(const bool a) = 0;
	virtual void SetVelocity(const Vector3& velocity) = 0;
	virtual void SetAcceleration(const Vector3& acceleration) = 0;
	virtual void SetRestitution(const float restitution) = 0;
	virtual void AddForce(const Vector3 force) = 0;
	virtual void SetInverseMass(const unsigned int mass) = 0;
	virtual void SetDrag(const float drag) = 0;
};