#pragma once
#include <string>
#include <fstream>
#include <cstdint>
#include "../Physics/Vector/Vector.h"
#include "../Renderer/Vertex.h"
#include "../Components/GameObject.h"
#include "../Logger/Logger.h"
class Writer {
public:

	// STRING WRITER
	static void WriteString(std::string& string, std::ofstream& out) {
		uint32_t size = string.size();
		WriteInt(size, out);
		out.write(string.c_str(), size);
	}

	// INT WRITER
	static void WriteInt(int& x, std::ofstream& out) {
		out.write(reinterpret_cast<char*>(&x), sizeof(x));
	}

	// UNSIGNED INT WRITER
	static void WriteInt(uint32_t& x, std::ofstream& out) {
		out.write(reinterpret_cast<char*>(&x), sizeof(x));
	}

	//  FLOAT WRITER
	static void WriteFloat(float& x, std::ofstream& out) {
		out.write(reinterpret_cast<char*>(&x), sizeof(x));
	}

	// BOOLEAN WRITER
	static void WriteBool(bool& b, std::ofstream& out) {
		out.write(reinterpret_cast<char*>(&b), sizeof(bool));
	}

	// VECTOR WRITER
	static void WriteVector(Vector& vector, std::ofstream& out) {
		WriteFloat(vector.x, out);
		WriteFloat(vector.y, out);
		WriteFloat(vector.z, out);
	}

	//	VERTEX WRITER
	static void WriteVertex(Vertex& vertex, std::ofstream& out) {
		WriteVector(vertex.position, out);
		WriteVector(vertex.texCoord, out);
		WriteVector(vertex.color, out);
	}
			
	//	TRANSFORM COMPONENT WRITER
	static void WriteTransform(Transform& transform, std::ofstream& out) {
		WriteVector(transform.position, out);
		WriteVector(transform.scale, out);
		WriteVector(transform.rotation, out);
		Logger::Log(LogLevel::Debug, "WROTE TRANSFORM", "WRITER");
	}

	//	VECTOR OF VERTICES WRITER
	static void WriteVertices(std::vector<Vertex>& vertices, std::ofstream& out) {
		uint32_t size = vertices.size();
		WriteInt(size, out);
		out.write(reinterpret_cast<char*>(vertices.data()), sizeof(Vertex) * size);
	}

	// VECTOR OF INDICES WRITER
	static void WriteIndices(std::vector<GLuint>& indices, std::ofstream& out) {
		uint32_t size = indices.size();
		WriteInt(size, out);
		out.write(reinterpret_cast<char*>(indices.data()), sizeof(GLuint) * size);
	}

	//	MESH COMPONENT WRITER
	static void WriteMesh(Mesh& mesh, std::ofstream& out) {
		WriteString(mesh.meshFilePath, out);
		WriteVector(mesh.color, out);
		Logger::Log(LogLevel::Debug, "WROTE MESH", "WRITER");

	}

	//	RIGIDBODY COMPONENT WRITER
	static void WriteRigidbody(Rigidbody& rb, std::ofstream& out) {
		WriteBool(rb.gravity, out);
		WriteVector(rb.velocity, out);
		WriteVector(rb.acceleration, out);
		WriteFloat(rb.restitution, out);
		Logger::Log(LogLevel::Debug, "WROTE RIGIDBODY", "WRITER");
	}

	//	BOX COLLIDER 2D COMPONENT WRITER
	static void WriteBoxCollider2D(BoxCollider2D& bc, std::ofstream& out) {
		WriteBool(bc.isStationary, out);
		Logger::Log(LogLevel::Debug, "WROTE BOX COLLIDER 2D", "WRITER");
	}

	//	 GAMEOBJECT WRITER
	static void WriteGameObject(GameObject& gameobject, std::ofstream& out) {
		// NAME STRING
		WriteString(gameobject.name, out);
		
		// COMPONENT SERIALIZATION
		uint32_t size = gameobject.components.size();
		WriteInt(size, out);
		for (Component* component : gameobject.components) {
			ComponentType type = component->GetType();
			uint32_t id = static_cast<uint32_t>(type);
			WriteInt(id, out);
			switch (type) {
			case ComponentType::Transform: {	//TRANSFORM COMPONENT
				WriteTransform(static_cast<Transform&>(*component), out);
				break;
			}
			case ComponentType::Mesh: {
				WriteMesh(static_cast<Mesh&>(*component), out);
				break;
			}
			case ComponentType::Rigidbody: {
				WriteRigidbody(static_cast<Rigidbody&>(*component), out);
				break;
			}
			case ComponentType::BoxCollider2D: {
				WriteBoxCollider2D(static_cast<BoxCollider2D&>(*component), out);
				break;
			}
			}
		}
	}

	//	WRITE SECENE
	static void WriteScene(std::vector<GameObject*>& gameobjects, std::ofstream& out) {
		uint32_t size = gameobjects.size();
		WriteInt(size, out);
		for (GameObject* gameobject : gameobjects) {
			WriteGameObject(*gameobject, out);
		}
	}
};

