#include "Physics.h"

void Physics::Update(std::vector<GameObject*>& gameObjects) {
	for(GameObject* g : gameObjects) {
		Rigidbody* rb = g->GetComponent<Rigidbody>();
		BoxCollider2D* bc = g->GetComponent<BoxCollider2D>();
		
		if (rb != nullptr) {

			rb->Update(Time::GetDeltaTime());

		}
	}

	for (GameObject* g : gameObjects) {
		Rigidbody* rb = g->GetComponent<Rigidbody>();
		BoxCollider2D* bc = g->GetComponent<BoxCollider2D>();
		if (rb != nullptr && bc != nullptr) {
			for (GameObject* g_ : gameObjects) {
				if (g != g_) {
					Rigidbody* rb_ = g_->GetComponent<Rigidbody>();
					BoxCollider2D* bc_ = g_->GetComponent<BoxCollider2D>();

					if (rb_ != nullptr && bc_ != nullptr) {
						if (bc->CheckCollision(bc_, Time::GetDeltaTime())) {
							bc->ResolveCollision(bc_, Time::GetDeltaTime());
						}
					}
				}
			}
		}
	}

}



