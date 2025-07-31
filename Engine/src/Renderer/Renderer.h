#pragma once
#include <vector>
#include "Shader/Shader.h"
#include "../Components/GameObject.h"
#include "../Components/Mesh/Mesh.h"
#include "../Locator/Locator.h"
#include <GLFW/glfw3.h>
class Editor;
class Renderer
{
	int fps = 0;
	GLFWwindow* window;
public:
	Renderer(GLFWwindow* win) : window(win) 
	{
		Locator::SetRenderer(this);
		Logger::Log(LogLevel::Info, "Renderer Created", "Application");
	}
	void Init();
	void DrawEditor(Editor* editor);
	void Draw(std::vector<GameObject*> &gameObjects);
	void SetFPS(int gFps);
};

