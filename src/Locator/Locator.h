#pragma once

class Physics;
class Renderer;
class Application;
class Camera;

class Locator
{
	static Physics* mPhysics;
	static Renderer* mRenderer;
	static Application* mApplication;
	static Camera* mCamera;
public:
	static Physics* GetPhysics();
	static void SetPhysics(Physics* physics);

	static Renderer* GetRenderer();
	static void SetRenderer(Renderer* renderer);

	static Application* GetApplication();
	static void SetApplication(Application* application);

	static Camera* GetCamera();
	static void SetCamera(Camera* camera);
};


