#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../EventSystem/Subject/Subject.h"
#include <Core.h>
class Window : public Observer, public Subject
{
	const char* TITLE;
	int Init();
	void onNotify (Event *e);

public:
	int WIDTH, HEIGHT, status;
	GLFWwindow* window;
	void HandleInput();
	Window(int w, int h, const char* title);
};

