#pragma once
#include <vector>
#include "Physics/Physics.h"
#include "Camera/Camera.h"
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Editor/Editor.h"
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

class Application: public Observer {
	//MULTITHREADING STUFF
	std::thread updateThread;
	std::mutex gameObjectMutex;
	std::atomic<bool> running;
	std::atomic<bool> physicsRunning;
	//////////////////////

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
	std::atomic<bool>& GetPhysicsState();
};