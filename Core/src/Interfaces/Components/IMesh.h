#pragma once
#include "../../ENGINE_API.h"
#include "IComponent.h"
#include "../../Math/Vectors/Vector3.h"
#include "../../Renderer/Vertex/Vertex.h"
class ENGINE_API IMesh: public IComponent {
public:
	IMesh();
	virtual ~IMesh();
	virtual Vector3 GetColor() const = 0;
};
