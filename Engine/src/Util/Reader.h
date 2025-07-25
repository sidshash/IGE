#pragma once
#include <fstream>
#include <string>
#include <cstdint>
#include <Core.h>
#include "../Components/GameObject.h"
#include "ScriptAPI.h"

class Reader {
public:
	//	READ INT
	static void ReadInt(int& x, std::ifstream& in) {
		in.read(reinterpret_cast<char*>(&x), sizeof(int));
	}

	// READ UINT
	static void ReadInt(uint32_t& x, std::ifstream& in) {
		in.read(reinterpret_cast<char*>(&x), sizeof(int));
	}

	//	READ FLOAT
	static void ReadFloat(float& x, std::ifstream& in) {
		in.read(reinterpret_cast<char*>(&x), sizeof(float));
	}

	//	READ STRING
	static void ReadString(std::string& str, std::ifstream& in) {
		uint32_t size;
		in.read(reinterpret_cast<char*>(&size), sizeof(size));
		str.resize(size);
		in.read(reinterpret_cast<char*>(str.data()), size);
	}

	//	READ BOOLEAN
	static void ReadBoolean(bool& x, std::ifstream& in) {
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
	}

	//	READ VECTOR
	static void ReadVector3(Vector3& vector, std::ifstream& in) {
		ReadFloat(vector.x, in);
		ReadFloat(vector.y, in);
		ReadFloat(vector.z, in);
	}
	static void ReadVector2(Vector2& vector, std::ifstream& in) {
		ReadFloat(vector.x, in);
		ReadFloat(vector.y, in);
	}

	//	READ VERTEX
	static void ReadVertex(Vertex& vertex, std::ifstream& in) {
		ReadVector3(vertex.position, in);
		ReadVector2(vertex.texCoord, in);
		ReadVector3(vertex.color, in);
	}

	//	READ TRANSFORM
	static void ReadTransform(Transform& transform, std::ifstream& in) {
		ReadVector3(transform.mPosition, in);
		ReadVector3(transform.mScale, in);
		ReadVector3(transform.mRotation, in);
	}

	//	READ VECTOR OF VERTICES
	static void ReadVertices(std::vector<Vertex>& vertices, std::ifstream& in) {
		uint32_t size;
		ReadInt(size, in);
		vertices.resize(size);
		in.read(reinterpret_cast<char*>(vertices.data()), sizeof(Vertex) * size);
	}

	// READ VECTOR OF INDICES
	static void ReadIndices(std::vector<GLuint>& indices, std::ifstream& in) {
		uint32_t size;
		ReadInt(size, in);
		indices.resize(size);
		in.read(reinterpret_cast<char*>(indices.data()), sizeof(GLuint) * size);
	}

	// READ MESH COMPONENT
	static void ReadMesh(Mesh& mesh, std::ifstream& in) {
		ReadString(mesh.meshFilePath, in);
		ReadVector3(mesh.mColor, in);
		mesh.LoadMesh(mesh.meshFilePath.c_str());
	}

	//	READ RIGIDBODY COMPONENT
	static void ReadRigidbody(Rigidbody& rb, std::ifstream& in){
		ReadBoolean(rb.mGravity, in);
		ReadVector3(rb.mVelocity, in);
		ReadVector3(rb.mAcceleration, in);
		ReadFloat(rb.mRestitution, in);
	}

	//	READ BOX COLLIDER 2D COMPONENT 
	static void ReadBoxcollider2D(BoxCollider2D& bc, std::ifstream& in) {
		ReadBoolean(bc.mStationary, in);
	}

	static void ReadScript(Script& script, std::ifstream& in) {
		ReadString(script.mName, in);
	}

	// READ GAMEOBJECT
	static void ReadGameObject(GameObject& gameobject, std::ifstream& in) {
		ReadString(gameobject.mName, in);

		//COMPONENT DESERIALIZATION
		uint32_t size;
		ReadInt(size, in);

		for (uint32_t i = 0; i < size; i++) {
			uint32_t id;
			ReadInt(id, in);
			ComponentType type = static_cast<ComponentType>(id);
			switch (type) {
			case ComponentType::Transform: {
				Transform* t = new Transform(&gameobject);
				ReadTransform(*t, in);
				gameobject.components.push_back(t);
				break;
			}
			case ComponentType::Mesh: {
				Mesh* m = new Mesh(&gameobject);
				ReadMesh(*m, in);
				gameobject.components.push_back(m);
				break;
			}
			case ComponentType::Rigidbody: {
				Rigidbody* rb = new Rigidbody(&gameobject);
				ReadRigidbody(*rb, in);
				gameobject.components.push_back(rb);
				break;
			}
			case ComponentType::BoxCollider2D: {
				BoxCollider2D* bc = new BoxCollider2D(&gameobject);
				ReadBoxcollider2D(*bc, in);
				gameobject.components.push_back(bc);
				break;
			}
			case ComponentType::Script: {
				Script* script = new Script(&gameobject);
				ReadScript(*script, in);
				ScriptAPI::CompileScript("src/Assets/Scripts/", script->mName);
				HMODULE hModule = ScriptAPI::LoadScript(script->mName);
				script->mHModule = hModule;
				ScriptBehaviour* behaviour = ScriptAPI::CreateBehaviour(hModule);
				behaviour->SetGameObject(&gameobject);
				script->SetBehaviour(behaviour);
				gameobject.components.push_back(script);
				break;
			}
			}
		}
	}

	//	READ SCENE
	static void ReadScene(std::vector<GameObject*>& gameobjects, std::ifstream& in) {
		uint32_t size;
		ReadInt(size, in);
		for (uint32_t i = 0; i < size; i++) {
			GameObject* gameObject = new GameObject("GameObject");
			ReadGameObject(*gameObject, in);
			gameobjects.push_back(gameObject);
		}
	}
};