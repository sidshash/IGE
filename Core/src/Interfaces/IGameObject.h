#pragma once
#include "../ENGINE_API.h"
#include "Components/ITransform.h"
#include "Components/IMesh.h"
#include "Components/IRigidbody.h"
#include "Components/IBoxCollider2D.h"
#include <string>
#include <typeinfo>

class ENGINE_API IGameObject {
protected:
	virtual ITransform* GetTransform() = 0;
	virtual IMesh* GetMesh() = 0;
	virtual IRigidbody* GetRigidbody() = 0;
	virtual IBoxCollider2D* GetBoxCollider2D() = 0;
public:
	IGameObject();
	virtual ~IGameObject();


	//GETTERS
	virtual int GetId() const = 0;
	virtual std::string GetName() const = 0;

	//SETTERS
	virtual void SetId(const int id) = 0;
	virtual void SetName(const std::string name) = 0;

	//COMPONENT RELATED FUNCTIONS

	template<class T>
	T* GetComponent();
};

template<>
inline ITransform* IGameObject::GetComponent<ITransform>() {
	return GetTransform();
}

template<>
inline IRigidbody* IGameObject::GetComponent<IRigidbody>() {
	return GetRigidbody();
}

template<>
inline IMesh* IGameObject::GetComponent<IMesh>() {
	return GetMesh();
}

template<>
inline IBoxCollider2D* IGameObject::GetComponent<IBoxCollider2D>() {
	return GetBoxCollider2D();
}
