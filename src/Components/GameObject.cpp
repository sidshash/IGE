#include "GameObject.h"

void GameObject::DrawInspectable() {
	//gameobject
	if (ImGui::CollapsingHeader("Gameobject", ImGuiTreeNodeFlags_DefaultOpen)) {
		ImGui::Text("Id: %d", id);
		ImGui::Text("Name");
		//ImGui::SameLine();
		ImGui::InputText("##Name", &name);
	}
	//components
	if(components.size())
		ImGui::Separator();
	for (IInspectable* inspectable : components) {
		inspectable->DrawInspectable();
	}
	
	ImGui::Separator();
	//add component
	if (ImGui::Button("Add Component")) {
		ImGui::OpenPopup("AddComponentPopup");
	}

	if (ImGui::BeginPopup("AddComponentPopup")) {
		if (ImGui::MenuItem("Transform")) {
			AddComponent<Transform>();
		}
		if (ImGui::MenuItem("Mesh")) {
			AddComponent<Mesh>();
		}
		ImGui::EndPopup();
	}
}

