#include "Transform.h"

void Transform::DrawInspectable() {
	if (ImGui::CollapsingHeader("Transform", ImGuiTreeNodeFlags_DefaultOpen)) {
		ImGui::Text("Position");
		//ImGui::SameLine();
		ImGui::InputFloat3("##Position", &position.x);
	}
}
