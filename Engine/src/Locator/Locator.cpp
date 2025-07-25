#include "Locator.h"
#include "../Physics/Physics.h"
#include "../Renderer/Renderer.h"
#include "../Application.h"
#include "../Camera/Camera.h"
#include "../Scene/Scene.h"

Physics* Locator::mPhysics = nullptr;
Renderer* Locator::mRenderer= nullptr;
Application* Locator::mApplication = nullptr;
Camera* Locator::mCamera = nullptr;
Scene* Locator::mScene = nullptr;

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
Camera* Locator::GetCamera() {
	return mCamera;
}
void Locator::SetCamera(Camera* camera) {
	mCamera = camera;
}

Scene* Locator::GetScene() {
	return mScene;
}
void Locator::SetScene(Scene* scene) {
	mScene = scene;
}