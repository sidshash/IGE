#include "BottomPanel.h"

void BottomPanel::DrawFolder(const char* name, GLuint id)
{
	ImGui::BeginGroup();
	ImGui::Image((void*)(intptr_t)id, ImVec2(64, 64));
	ImGui::TextWrapped(name);
	ImGui::EndGroup();
}

BottomPanel::BottomPanel() :
	IPanel("Assets")
{
	CreateTexture(1, "src/Assets/Icons/folder.png", folderTextureID);
	CreateTexture(2, "src/Assets/Icons/cpp.png", cppTextureID);
}


void BottomPanel::CreateTexture(int index, const char* path, GLuint& id) {
	int width, height, channels;
	unsigned char* texture;
	texture = AssetLoader::LoadImage(path, width, height, channels);
	glGenTextures(index, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);

	// Texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void BottomPanel::OnDraw()
{
	DrawFolder("Meshes", folderTextureID);
	DrawFolder("Controller.cpp", cppTextureID);

}
