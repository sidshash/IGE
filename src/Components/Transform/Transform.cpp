#include "Transform.h"

void Transform::DrawInspectable() {
	if (ImGui::CollapsingHeader("Transform", ImGuiTreeNodeFlags_DefaultOpen)) {
		//ImGui::Text("Position");
		//ImGui::SameLine();
		ImGui::DragFloat3("Position", &position.x);
		ImGui::DragFloat3("Scale", &scale.x);
		ImGui::DragFloat3("Rotation", &rotation.x);
	}
}
