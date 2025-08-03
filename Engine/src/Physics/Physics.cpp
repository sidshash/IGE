#include "Physics.h"

void Physics::Update(std::vector<GameObject*>& gameObjects) {

	//FIRST APPLY FORCES HERE
	registry.updateForces();

	for (GameObject* gameObject : gameObjects) {
		Rigidbody* rb = gameObject->GetComponent<Rigidbody>();
		if (rb != nullptr) {
			ApplyPhysics(*rb);
		}
	}
}

void Physics::ApplyPhysics(Rigidbody& rb)
{
	rb.Integrate(Time::GetDeltaTime());
}

void Physics::AddForce(Vector3 force, Rigidbody* rb) {
	Vector3 acceleration = rb->GetAcceleration();
	acceleration = acceleration + force;
	rb->SetAcceleration(acceleration);
}

void Physics::RegisterForce(Rigidbody* rigidbody)
{
	Drag* dragForce = new Drag();
	registry.Add(dragForce, rigidbody);
}





