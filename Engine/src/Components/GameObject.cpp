#include "GameObject.h"


GameObject::GameObject(std::string n) : 
    mName(n), mId(Random::GenerateRandomID())
{

}

//GETTERS
int GameObject::GetId() const
{
    return mId;
}

std::string GameObject::GetName() const
{
    return mName;
}

//SETTERS
void GameObject::SetId(const int id)
{
    mId = id;
}

void GameObject::SetName(const std::string name)
{
    mName = name;
}

//INTERNAL OVERRIDES

ITransform* GameObject::GetTransform()
{
    return GetComponent<Transform>();
}

IMesh* GameObject::GetMesh()
{
    return GetComponent<Mesh>();
}

IRigidbody* GameObject::GetRigidbody()
{
    return GetComponent<Rigidbody>();
}

IBoxCollider2D* GameObject::GetBoxCollider2D()
{
    return GetComponent<BoxCollider2D>();
}
