#pragma once
#include <GL/glew.h>
#include <vector>
#include <fstream>
#include <cstdint>
#include "../Component.h"
#include "../../Renderer/Vertex.h"
#include "../../Renderer/Shader/Shader.h"
#include "../../Physics/Vector/Vector.h"
#include <FileDialog/tinyfiledialogs.h>
#include <glm/glm.hpp>
#include "../Transform/Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <format>
class Camera;

class Mesh: public Component
{
	friend class Writer;
	friend class Reader;
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	Vector color;
	Shader* shader;
	std::string meshFilePath;
	GLuint vao, vbo, ibo;
	void Upload();
	GLenum drawMode;
	void WriteMesh();
public:
	Mesh(GameObject* o) :
		Component(o),
		color(1),
		drawMode(GL_TRIANGLES)
	{
		Shader* s = new Shader("src/Assets/Shaders/shader.vs", "src/Assets/Shaders/shader.fs");
		shader = s;
	}
	void LoadMesh(const char* location);
	void Draw();
	void DrawInspectable() override;
	void SetDrawMode(GLenum mode);
	Shader* GetShader() const { return shader; }
	ComponentType GetType() override {
		return ComponentType::Mesh;
	}
};

