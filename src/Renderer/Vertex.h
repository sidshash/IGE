#pragma once

#include "../Physics/Vector/Vector.h"
#include <iostream>


struct Vertex {
	Vector position = Vector(1);
	Vector texCoord = Vector(1);
	Vector color = Vector(1);
};

inline std::ostream& operator << (std::ostream& os, Vertex& v) {
	os << "--Position--\n";
	os << v.position.x << ", " << v.position.y << ", " << v.position.z << "\n";
	
	os << "--Texture Coordinates--\n";
	os << v.texCoord.x << ", " << v.texCoord.y << ", " << v.texCoord.z << "\n";
	
	os << "--Color--\n";
	os << v.color.x << ", " << v.color.y << ", " << v.color.z << "\n";
	return os;
}