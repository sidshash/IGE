#pragma once
#include <vector>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Physics/Physics.h"
#include "Editor/Editor.h"


class Application {
	Window* windowHandler;

	Renderer* renderer;
	Physics* physics;
	Editor* editor;
	std::vector<GameObject*> gameObjects;
protected:
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnEnd() = 0;
public:
	Application();
	GameObject* CreateGameObject(const char* n = "GameObject");
	void Run();
	Window* GetWindow();
	Editor* GetEditor();
	std::vector<GameObject*>* GetObjectList();
};