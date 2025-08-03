#include "Gravity.h"

void Gravity::ApplyForce(Rigidbody& rb)
{
	Vector3 acceleration = rb.GetAcceleration();
	acceleration.y -= 9.91f;
	rb.SetAcceleration(acceleration);
}



