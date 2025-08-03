#include "Drag.h"

Drag::Drag()
{
}

void Drag::ApplyForce(Rigidbody& rb)
{
	float drag = rb.GetDrag();
	Vector3 velocity = rb.GetVelocity();
	Vector3 force = velocity * velocity.Magnitude() * -drag;
	rb.AddForce(force);
}
