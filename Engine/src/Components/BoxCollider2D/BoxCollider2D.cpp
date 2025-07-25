#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D(GameObject* gameObject):  
	Component(gameObject),  
	mShowCollider(false),  
	mStationary(false)
{  
}

//GETTERS

bool BoxCollider2D::isShowCollider() const
{
    return mShowCollider;
}

bool BoxCollider2D::isStationary() const
{
    return mStationary;
}

//SETTERS

void BoxCollider2D::SetShowCollider(const bool a)
{
    mShowCollider = a;
}

void BoxCollider2D::SetStationary(const bool a)
{
    mStationary = a;
}


bool BoxCollider2D::CheckCollision(BoxCollider2D* b, float deltaTime) {
    Transform* t = gameObject->GetComponent<Transform>();
    Transform* t_ = b->gameObject->GetComponent<Transform>();

    if (t == nullptr || t_ == nullptr) return false;

    Vector3 p = t->GetPosition();
    Vector3 p_ = t_->GetPosition();
    Vector3 s = t->GetScale();
    Vector3 s_ = t_->GetScale();

    Vector3 halfSize = s * 0.5f;
    Vector3 halfSize_ = s_ * 0.5f;

    float rightA = p.x + halfSize.x;

    float leftA = p.x - halfSize.x;

    float topA = p.y + halfSize.y;

    float bottomA = p.y - halfSize.y;

    float rightB = p_.x + halfSize_.x;

    float leftB = p_.x - halfSize_.x;

    float topB =  p_.y + halfSize_.y;

    float bottomB = p_.y - halfSize_.y;

    bool isColliding =
        (rightA > leftB) &&
        (leftA < rightB) &&
        (topA > bottomB) &&
        (bottomA < topB);

    if (isColliding) {

        //Logger::Log(LogLevel::Debug, "---- A ----");
        //Logger::Log(LogLevel::Debug, "TopA: " + std::to_string(topA));
        //Logger::Log(LogLevel::Debug, "BottomA: " + std::to_string(bottomA));
        //Logger::Log(LogLevel::Debug, "LeftA: " + std::to_string(leftA));
        //Logger::Log(LogLevel::Debug, "RightA: " + std::to_string(rightA));
        //Logger::Log(LogLevel::Debug, "---- B ----");
        //Logger::Log(LogLevel::Debug, "TopB: " + std::to_string(topB));
        //Logger::Log(LogLevel::Debug, "BottomB: " + std::to_string(bottomB));
        //Logger::Log(LogLevel::Debug, "LeftB: " + std::to_string(leftB));
        //Logger::Log(LogLevel::Debug, "RightB: " + std::to_string(rightB));

        float overlapX = std::min(rightA, rightB) - std::max(leftA, leftB);
        float overlapY = std::min(topA, topB) - std::max(bottomA, bottomB);

        if (overlapX < overlapY) {
            p.x = p_.x + (p.x < p_.x ? -halfSize_.x - halfSize.x : halfSize_.x + halfSize.x);
            t->SetPosition(p);
        }
        else {
            if (overlapY > 0.01f) {
                // correct position
                p.y = p_.y + (p.y < p_.y ? -halfSize_.y - halfSize.y : halfSize_.y + halfSize.y);
                t->SetPosition(p);
            }

        }
        return true;
    }

}


void BoxCollider2D::ResolveCollision(BoxCollider2D* bc, float deltaTime) {

	Rigidbody* rb = gameObject->GetComponent<Rigidbody>();
	Rigidbody* rb_ = bc->gameObject->GetComponent<Rigidbody>();

	if (rb != nullptr) {
		//float restitution = std::min(rb->GetRestitution(), rb_->GetRestitution());

		Vector3 thisFinalVel = (rb->GetVelocity() * (rb->GetRestitution() * -1.0f));
		rb->SetVelocity(thisFinalVel);
        if (!bc->isStationary()) {
            Vector3 otherFinalVel = (rb_->GetVelocity() * (rb_->GetRestitution() * -1.0f));
            rb_->SetVelocity(otherFinalVel);
        }

	}

}
