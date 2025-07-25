#pragma once
#include "../../ENGINE_API.h"
#include "IComponent.h"
#include "../../Math/Vectors/Vector3.h"
class ENGINE_API ITransform: public virtual IComponent
{
public:
	ITransform();
	virtual ~ITransform();
	virtual Vector3 GetPosition() const = 0;
	virtual void SetPosition(const Vector3& position) = 0;

	virtual Vector3 GetScale() const = 0;
	virtual void SetScale(const Vector3& scale) = 0;

	virtual Vector3 GetRotation() const = 0;
	virtual void SetRotation(const Vector3& rotation) = 0;
};