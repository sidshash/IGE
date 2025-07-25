#pragma once
#include <vector>
#include "Window/Window.h"
#include "Physics/Physics.h"
#include "Renderer/Renderer.h"
#include "Editor/Editor.h"
#include "Camera/Camera.h"

class Application: public Observer {
	Window* windowHandler;

	Renderer* renderer;
	Camera camera;
	Physics* physics;
	Editor* editor;
	std::vector<GameObject*> gameObjects;
	void OnStart();
	void OnUpdate();
	void OnEnd();
	void onNotify(Event* e) override;
public:
	Application();
	GameObject* CreateGameObject(const char* n = "GameObject");
	void Run();
	Window* GetWindow();
	Editor* GetEditor();
	std::vector<GameObject*>* GetObjectList();
};