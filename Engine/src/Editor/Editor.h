#pragma once
#include "../EventSystem/Subject/Subject.h"
#include "Panel/Panel.h"
#include "../Locator/Locator.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Window;
class Editor : public Observer, public Subject
{
	Window* windowHandler;
	Panel* panel;
	void onNotify(Event* e) override;
public:
	Editor();
	void Init();
	void Draw(int fps);
	void OnClose();
	using Subject::AddObserver;
};

