#pragma once
#include "../../ENGINE_API.h"
#include "../../Math/Vectors/Vector3.h"
#include "../../Math/Vectors/Vector2.h"

class ENGINE_API Vertex {
public:
	Vector3 position;
	Vector2 texCoord;
	Vector3 color;
	Vertex(Vector3 p, Vector2 t, Vector3 c):
		position(p),
		texCoord(t),
		color(c)
	{}
	Vertex():
		position(0),
		texCoord(0),
		color(1)
	{}
};
