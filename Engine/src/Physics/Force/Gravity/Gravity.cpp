#include "Gravity.h"

void Gravity::ApplyForce(Rigidbody& rb)
{
	float inverseMass = rb.GetInverseMass();
	rb.AddForce(Vector3(0, -10.0f / inverseMass, 0));
}



