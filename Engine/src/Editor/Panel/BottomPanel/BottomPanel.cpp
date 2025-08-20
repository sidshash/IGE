#include "BottomPanel.h"

void BottomPanel::DrawFolder(const char* name, GLuint id)
{
	ImVec2 cardSize(80, 100);
	std::string assetId = "##asset_" + std::string(name);
	if (ImGui::InvisibleButton(assetId.c_str(), cardSize)) {

	}
	if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
		FileSystem::PushPath(name);
	}
	ImVec2 p = ImGui::GetItemRectMin();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	

	if (ImGui::IsItemHovered()) {
		draw_list->AddRectFilled(p, ImGui::GetItemRectMax(),
			IM_COL32(100, 100, 255, 50));
	}

	draw_list->AddImage(id,
		ImVec2(p.x + 8, p.y + 8),
		ImVec2(p.x + 72, p.y + 72));

	std::string displayName = name;
	float maxTextWidth = cardSize.x - 8; 
	if (ImGui::CalcTextSize(displayName.c_str()).x > maxTextWidth) {
		while (!displayName.empty() &&
			ImGui::CalcTextSize((displayName + "...").c_str()).x > maxTextWidth) {
			displayName.pop_back();
		}
		displayName += "...";
	}

	ImGui::SetCursorScreenPos(ImVec2(p.x + 4, p.y + 80));
	ImGui::PushTextWrapPos(p.x + cardSize.x - 4);
	ImGui::TextUnformatted(displayName.c_str());
	ImGui::PopTextWrapPos();
}

BottomPanel::BottomPanel() :
	IPanel("Assets")
{
	CreateTexture(1, "src/Assets/Icons/folder.png", folderTextureID);
	CreateTexture(2, "src/Assets/Icons/cpp.png", cppTextureID);
	CreateTexture(3, "src/Assets/Icons/file.png", defaultTextureID);
	FileSystem::SearchAssets();
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

void BottomPanel::OnDraw() {
	if (!FileSystem::isHome()) {
		if (ImGui::Button("Back")) {
			FileSystem::PopPath();
		}
	}

	for (const Path& path : FileSystem::GetPaths()) {
		if (path.type == PathType::DIRECTORY) {
			DrawFolder(path.filename.c_str(), folderTextureID);
		}
		else if (path.type == PathType::SCRIPT) {
			DrawFolder(path.filename.c_str(), cppTextureID);
		}
		else {
			DrawFolder(path.filename.c_str(), defaultTextureID);
		}
	}
}
