#include "Rigidbody.h"
#include "../../Application.h"

Rigidbody::Rigidbody(GameObject* gO) :
	Component(gO),
	velocity(0),
	acceleration(0),
	gravity(false),
	restitution(1)
{
}

void Rigidbody::DrawInspectable() {
	if (ImGui::CollapsingHeader("Rigidbody", ImGuiTreeNodeFlags_DefaultOpen)) {
		ImGui::Checkbox("Gravity", &gravity);
		ImGui::DragFloat3("Velocity", &velocity.x);
		ImGui::DragFloat3("Acceleration", &acceleration.x);
		ImGui::DragFloat("Restitution", &restitution, 0.1f);
	}
}

void Rigidbody::Update(float deltaTime) {

	Transform* t = gameObject->GetComponent<Transform>();

	if (t == nullptr) return;

	acceleration.y = 0;

	if (gravity) {
		acceleration.y = -9.81f;
	}

	velocity = velocity + (acceleration * deltaTime);

	t->position = t->position + (velocity * deltaTime);

}