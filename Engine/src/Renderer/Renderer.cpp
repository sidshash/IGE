#include "Renderer.h"
#include "../Editor/Editor.h"

void Renderer::Draw(std::vector<GameObject*>& gameObjects) {
	for (GameObject* g : gameObjects) {
		Mesh* mesh = g->GetComponent<Mesh>();
		if (mesh != nullptr) {
			mesh->Draw();
		}
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	ImGui::Render();
	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Renderer::Init() {
	//V-SYNC 1 = ON, 0 = OFF
	glfwSwapInterval(0);
	glEnable(GL_DEPTH_TEST);
}



void Renderer::SetFPS(float gFps) {
	fps = gFps;
}

void Renderer::DrawEditor(Editor *editor) {
	editor->Draw(fps);
}