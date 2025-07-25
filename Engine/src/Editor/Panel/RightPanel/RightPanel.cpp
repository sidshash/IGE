#include "RightPanel.h"
#include "../../../Components/GameObject.h"
void RightPanel::PreWindow() {

}

void RightPanel::SetSelected(IInspectable* selectedItem) {
    mSelectedItem = selectedItem;
}

void RightPanel::DrawInspectable(IInspectable* inspectable) {
    InspectableType inspectableType = inspectable->GetType();

    if (inspectableType == InspectableType::Gameobject) {
        GameObject* gameObject = dynamic_cast<GameObject*>(inspectable);
        DrawGameObject(gameObject);
    }

    else if (inspectableType == InspectableType::Component) {

    }

}

void RightPanel::OnDraw() {
	if(mSelectedItem != nullptr)
		DrawInspectable(mSelectedItem);
}

void RightPanel::DrawGameObject(GameObject* gameObject) {
	int& id = gameObject->mId;
	std::string& name = gameObject->mName;
	std::vector<Component*>& components = gameObject->components;
	//gameobject
	if (ImGui::CollapsingHeader("Gameobject", ImGuiTreeNodeFlags_DefaultOpen)) {
		ImGui::InputText(std::format("Name##{}", id).c_str(), &name);
	}
	//components
	if (components.size())
		ImGui::Separator();
	for (Component* component : components) {
		DrawComponent(component);
	}

	ImGui::Separator();
	//add component

	std::string scriptName;
	static bool openScriptPopup = false;

	if (ImGui::Button("Add Component")) {
		ImGui::OpenPopup("AddComponentPopup");
	}

	if (ImGui::BeginPopup("AddComponentPopup")) {
		if (ImGui::MenuItem("Transform")) {
			gameObject->AddComponent<Transform>();
		}
		if (ImGui::MenuItem("Mesh")) {
			gameObject->AddComponent<Mesh>();
		}
		if (ImGui::MenuItem("Rigidbody")) {
			gameObject->AddComponent<Rigidbody>();
		}
		if (ImGui::MenuItem("BoxCollider2D")) {
			gameObject->AddComponent<BoxCollider2D>();
		}
		if (ImGui::MenuItem("Script")) {
			openScriptPopup = true;  // flag to open the next popup
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	if (openScriptPopup) {
		ImGui::OpenPopup("AddScriptPopup");
		openScriptPopup = false;
	}

	if (ImGui::BeginPopup("AddScriptPopup")) {
		static char buffer[128] = "";
		ImGui::InputText("Script Name", buffer, IM_ARRAYSIZE(buffer));

		if (ImGui::Button("Create")) {
			if (strlen(buffer) > 0) {
				scriptName = buffer;
				ScriptAPI::CreateScript(scriptName);
				//Logger::Log(LogLevel::Debug, "Create Script Called");
				buffer[0] = '\0';
				HMODULE hModule = ScriptAPI::LoadScript(scriptName);
				ScriptBehaviour* behaviour = ScriptAPI::CreateBehaviour(hModule);
				behaviour->SetGameObject(gameObject);
				gameObject->AddComponent<Script>();
				Script* script = gameObject->GetComponent<Script>();
				script->mHModule = hModule;
				script->SetName(scriptName);
				script->SetBehaviour(behaviour);
				ImGui::CloseCurrentPopup();
			}
		}

		ImGui::SameLine();
		if (ImGui::Button("Cancel")) {
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}
}



void RightPanel::DrawComponent(Component* component) {
	ComponentType type = component->GetType();
	switch (type) {
		case ComponentType::Transform: {
			DrawTransform((Transform*)component);
			break;
		}
		case ComponentType::Mesh: {
			DrawMesh((Mesh*)component);
			break;
		}
		case ComponentType::Rigidbody: {
			DrawRigidbody((Rigidbody*)component);
			break;
		}
		case ComponentType::BoxCollider2D: {
			DrawBoxCollider2D((BoxCollider2D*)component);
			break;
		}
		case ComponentType::Script: {
			DrawScript((Script*)component);
			break;
		}
	}
}

void RightPanel::DrawTransform(Transform* transform) {
	if (ImGui::CollapsingHeader("Transform", ImGuiTreeNodeFlags_DefaultOpen)) {
		//ImGui::Text("Position");
		//ImGui::SameLine();
		ImGui::DragFloat3("Position", &transform->mPosition.x);
		ImGui::DragFloat3("Scale", &transform->mScale.x);
		ImGui::DragFloat3("Rotation", &transform->mRotation.x);
	}
}

void RightPanel::DrawMesh(Mesh* m) {
	if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen)) {
		if (ImGui::BeginCombo("Drawing Mode", "Triangles")) {
			if (ImGui::Selectable("Triangle"))
				m->SetDrawMode(GL_TRIANGLES);
			if (ImGui::Selectable("Wireframe"))
				m->SetDrawMode(GL_FRONT_AND_BACK);
			ImGui::EndCombo();
		}
		ImGui::DragFloat3("Color", &m->mColor.x, 0.1f);
		//ImGui::SameLine();
		ImGui::Text("Mesh File");
		ImGui::TextWrapped(m->meshFilePath.c_str());
		if (ImGui::Button("Choose Mesh File")) {
			const char* filterPatterns[1] = { "*.mesh" };
			const char* filePath = tinyfd_openFileDialog("Choose a mesh file", "", 1, filterPatterns, NULL, 0);

			if (filePath) {
				m->LoadMesh(filePath);
			}
		}
		if (!m->meshFilePath.empty()) {
			if (ImGui::Button("Edit Mesh")) {
				ImGui::OpenPopup("EditMeshPopup");
			}
		}
		if (ImGui::BeginPopup("EditMeshPopup")) {
			ImGui::Text("Edit Mesh Data");
			ImGui::Separator();

			for (int i = 0; i < m->vertices.size(); i++) {
				Vertex& v = m->vertices[i];
				ImGui::DragFloat3(std::format("Position {}", i).c_str(), &(v.position.x));
				ImGui::DragFloat3(std::format("Tex Coord {}", i).c_str(), &(v.texCoord.x));
				ImGui::DragFloat3(std::format("Color {}", i).c_str(), &(v.color.x)); // If applicable
			}
			for (int i = 0; i < m->indices.size(); i++) {
				GLuint& n = m->indices[i];
				ImGui::DragScalar(std::format("Position {}", i).c_str(), ImGuiDataType_U32, &(n));
			}
			if (ImGui::Button("Edit")) {
				m->WriteMesh();
			}
			if (ImGui::Button("Close")) {
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();
		}
	}
}

void RightPanel::DrawRigidbody(Rigidbody* rb) {
	if (ImGui::CollapsingHeader("Rigidbody", ImGuiTreeNodeFlags_DefaultOpen)) {
		ImGui::Checkbox("Gravity", &rb->mGravity);
		ImGui::DragFloat3("Velocity", &rb->mVelocity.x);
		ImGui::DragFloat3("Acceleration", &rb->mAcceleration.x);
		ImGui::DragFloat("Restitution", &rb->mRestitution, 0.1f);
	}
}

void RightPanel::DrawBoxCollider2D(BoxCollider2D* bc) {
	if (ImGui::CollapsingHeader("BoxCollider2D", ImGuiTreeNodeFlags_DefaultOpen)) {

		//ImGui::Checkbox("Show Collider", &showCollider);
		ImGui::Checkbox("Stationary", &bc->mStationary);
	}
}

void RightPanel::DrawScript(Script* script)
{
	if (ImGui::CollapsingHeader("Script", ImGuiTreeNodeFlags_DefaultOpen)) {

		ImGui::TextWrapped(script->mName.c_str());

		if (ImGui::Button("Reload")) {
			ScriptAPI::Reload(script);
		}
	}
}
