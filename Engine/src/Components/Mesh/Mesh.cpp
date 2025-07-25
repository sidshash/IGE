#include "Mesh.h"
#include "../../Camera/Camera.h"

Mesh::Mesh(GameObject* gameObject) :
	Component(gameObject),
	mColor(1),
	drawMode(GL_TRIANGLES)
{
	Shader* s = new Shader("src/Assets/Shaders/shader.vs", "src/Assets/Shaders/shader.fs");
	shader = s;
}

void Mesh::LoadMesh(const char* location) {
	
	std::ifstream in(location, std::ios::binary);
	
	//read vertices size
	uint32_t vertSize;
	in.read(reinterpret_cast<char*>(&vertSize), sizeof(uint32_t));

	//read vertices data
	vertices.resize(vertSize);
	in.read(reinterpret_cast<char*>(vertices.data()), sizeof(Vertex) * vertSize);

	//read indices size
	uint32_t indSize;
	in.read(reinterpret_cast<char*>(&indSize), sizeof(indSize));

	//read indices data
	indices.resize(indSize);
	in.read(reinterpret_cast<char*>(indices.data()), sizeof(uint32_t) * indSize);
	meshFilePath = location;
	Upload();
}

void Mesh::Draw() {
	shader->Use();

	ImGuiIO& io = ImGui::GetIO();

	Transform* t = gameObject->GetComponent<Transform>();
	
	if(t == nullptr){
		return;
	}

	glm::mat4 projection = Locator::GetCamera()->GetProjection();
	//glm::mat4 model(1);
	Vector3 position = t->GetPosition();
	Vector3 scale = t->GetScale();
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, position.z));
	model = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));

	glm::mat4 mvp = projection * model;

	shader->UniformMat4("u_MVP", mvp);
	shader->Uniform3f("outColor", mColor);

	glBindVertexArray(vao);

	if (drawMode == GL_FRONT_AND_BACK)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::Upload() {
	//generate arrays and buffers
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * indices.size(), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0); // position
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(void*)offsetof(Vertex, position)
	);

	glEnableVertexAttribArray(1); // texCoord
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(void*)offsetof(Vertex, texCoord)
	);

	glEnableVertexAttribArray(2); // color
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(void*)offsetof(Vertex, color)
	);
}

void Mesh::SetDrawMode(GLenum mode) {
	drawMode = mode;
}

void Mesh::WriteMesh() {

	std::ofstream out(meshFilePath, std::ios::binary);

	//write vertices size
	uint32_t vertSize = vertices.size();
	out.write(reinterpret_cast<char*>(&vertSize), sizeof(uint32_t));

	//write vertices data
	out.write(reinterpret_cast<char*>(vertices.data()), sizeof(Vertex) * vertSize);

	//write indices size
	uint32_t indSize = indices.size();;
	out.write(reinterpret_cast<char*>(&indSize), sizeof(indSize));

	//write indices data
	out.write(reinterpret_cast<char*>(indices.data()), sizeof(uint32_t) * indSize);
}

Vector3 Mesh::GetColor() const {
	return mColor;
}