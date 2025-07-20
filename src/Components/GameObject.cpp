#include "GameObject.h"

void GameObject::DrawInspectable() {
	//gameobject
	if (ImGui::CollapsingHeader("Gameobject", ImGuiTreeNodeFlags_DefaultOpen)) {
		ImGui::InputText(std::format("Name##{}", id).c_str(), &name);
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
		if (ImGui::MenuItem("Rigidbody")) {
			AddComponent<Rigidbody>();
		}
		if (ImGui::MenuItem("BoxCollider2D")) {
			AddComponent<BoxCollider2D>();
		}
		ImGui::EndPopup();
	}
}

