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
	float inverseMass = rb->GetInverseMass();
	acceleration = acceleration + force * inverseMass;
	rb->SetAcceleration(acceleration);
}

void Physics::RegisterForce(Rigidbody* rigidbody)
{
	//REGISTER DRAG FORCE
	Drag* dragForce = new Drag();
	registry.Add(dragForce, rigidbody);

	//REGISTER GRAVITATIONAL FORCE	
	//if (rigidbody->isGravity()) {
		Gravity* gravity = new Gravity();
		registry.Add(gravity, rigidbody);
	//}
}





