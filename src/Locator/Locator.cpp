#include "Locator.h"
#include "../Physics/Physics.h"
#include "../Renderer/Renderer.h"
#include "../Application.h"

Physics* Locator::mPhysics = nullptr;
Renderer* Locator::mRenderer= nullptr;
Application* Locator::mApplication = nullptr;

Physics* Locator::GetPhysics() {
	return mPhysics;
}

Renderer* Locator::GetRenderer() {
	return mRenderer;
}

void Locator::SetPhysics(Physics* physics) {
	mPhysics = physics;
}

void Locator::SetRenderer(Renderer* renderer) {
	mRenderer = renderer;
}

Application* Locator::GetApplication() {
	return mApplication;
}
void Locator::SetApplication(Application* application) {
	mApplication = application;
}