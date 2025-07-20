#include "Mesh.h"
#include "../../Camera/Camera.h"

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
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(t->position.x, t->position.y, t->position.z));
	model = glm::scale(model, glm::vec3(t->scale.x, t->scale.y, t->scale.z));

	glm::mat4 mvp = projection * model;

	shader->UniformMat4("u_MVP", mvp);
	shader->Uniform3f("outColor", color);

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
		if (ImGui::BeginCombo("Drawing Mode", "Triangles")) {
			if (ImGui::Selectable("Triangle"))
				SetDrawMode(GL_TRIANGLES);
			if(ImGui::Selectable("Wireframe"))
				SetDrawMode(GL_FRONT_AND_BACK);
			ImGui::EndCombo();
		}
		ImGui::DragFloat3("Color", &color.x, 0.1f);
		//ImGui::SameLine();
		ImGui::Text("Mesh File");
		ImGui::TextWrapped(meshFilePath.c_str());
		if (ImGui::Button("Choose Mesh File")) {
			const char* filterPatterns[1] = { "*.mesh" };
			const char* filePath = tinyfd_openFileDialog("Choose a mesh file", "", 1, filterPatterns, NULL, 0);

			if (filePath) {
				LoadMesh(filePath);
			}
		}
		if (!meshFilePath.empty()) {
		if (ImGui::Button("Edit Mesh")) {
			ImGui::OpenPopup("EditMeshPopup");
		}
		}
		if (ImGui::BeginPopup("EditMeshPopup")) {
				ImGui::Text("Edit Mesh Data");
				ImGui::Separator();

				for (int i = 0; i < vertices.size(); i++) {
					Vertex& v = vertices[i];
					ImGui::DragFloat3(std::format("Position {}", i).c_str(), &(v.position.x));
					ImGui::DragFloat3(std::format("Tex Coord {}", i).c_str(), &(v.texCoord.x));
					ImGui::DragFloat3(std::format("Color {}", i).c_str(), &(v.color.x)); // If applicable
				}
				for (int i = 0; i < indices.size(); i++) {
					GLuint& n = indices[i];
					ImGui::DragScalar(std::format("Position {}", i).c_str(), ImGuiDataType_U32, &(n));
				}
				if (ImGui::Button("Edit")) {
					WriteMesh();
				}
				if (ImGui::Button("Close")) {
					ImGui::CloseCurrentPopup();
				}
			ImGui::EndPopup();
		}
	}
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