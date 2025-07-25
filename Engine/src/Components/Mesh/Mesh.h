#pragma once
#include <GL/glew.h>
#include <vector>
#include <fstream>
#include <cstdint>
#include "../Component.h"
#include "../../Renderer/Shader/Shader.h"
#include <FileDialog/tinyfiledialogs.h>
#include <glm/glm.hpp>
#include "../Transform/Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <format>
#include <Core.h>
class Camera;

class Mesh: public Component, public IMesh
{
	friend class Writer;
	friend class Reader;
	friend class RightPanel;
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	Vector3 mColor;
	Shader* shader;
	std::string meshFilePath;
	GLuint vao, vbo, ibo;
	void Upload();
	GLenum drawMode;
	void WriteMesh();
public:
	Mesh(GameObject* o);
	void LoadMesh(const char* location);
	void Draw();
	void SetDrawMode(GLenum mode);
	Shader* GetShader() const { return shader; }
	ComponentType GetType() override {
		return ComponentType::Mesh;
	}
	Vector3 GetColor() const override;
};

