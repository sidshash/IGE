#include "Mesh.h"


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

	float aspect = 16.0f / 9.0f;
	float viewHeight = 100.0f;
	float viewWidth = viewHeight * aspect;

	glm::mat4 projection = glm::ortho(
		0.0f, 16.0f,       // left, right
		0.0f, 9.0f,      // bottom, top
		-1.0f, 1.0f
	);

	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(t->position.x, t->position.y, t->position.z));
	model = glm::scale(model, glm::vec3(t->scale.x, t->scale.y, t->scale.z));

	glm::mat4 mvp = projection * model;

	shader->UniformMat4("u_MVP", mvp);

	glBindVertexArray(vao);
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
		3,
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

void Mesh::DrawInspectable() {
	if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen)) {
		ImGui::Text("Color");
		//ImGui::SameLine();
		ImGui::InputFloat3("##Color", &color.x);
		ImGui::Text("Mesh File");
		ImGui::Text(meshFilePath.c_str());
		if (ImGui::Button("Choose Mesh File")) {
			const char* filterPatterns[1] = { "*.mesh" };
			const char* filePath = tinyfd_openFileDialog("Choose a mesh file", "", 1, filterPatterns, NULL, 0);

			if (filePath) {
				LoadMesh(filePath);
			}
		}
	}
}