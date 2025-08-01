#pragma once
#include "../IPanel.h"
#include <functional>
#include <iostream>
#include "../../../Locator/Locator.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Window;
class ViewportPanel: public IPanel
{
	GLuint fbo, depthRbo, colorTexture;
	int fbWidth, fbHeight;
	Window* windowHandler;
	bool isRunning;
	std::function<void(int, int)> ResizeFramebuffer;
	ImGuiWindowFlags windowFlags =
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse;
		//ImGuiWindowFlags_NoMove;
	void Init();
public:
	ViewportPanel();
	void DrawOnFB();
	void OnDraw() override;
	void PreWindow() override;
};

