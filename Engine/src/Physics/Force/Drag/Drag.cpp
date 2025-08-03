#include "Drag.h"

Drag::Drag()
{
}

void Drag::ApplyForce(Rigidbody& rb)
{
	float drag = rb.GetDrag();
	Vector3 acceleration = rb.GetAcceleration();
	Vector3 velocity = rb.GetVelocity();
	acceleration = acceleration - (velocity * velocity) * drag;
	rb.SetAcceleration(acceleration);
}
