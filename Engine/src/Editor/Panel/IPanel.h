#pragma once
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "../../EventSystem/Subject/Subject.h"
class IPanel: public Subject
{
protected:
	const char* title;
	ImVec4 bgColor;
	ImVec4 titleColor;
	ImGuiWindowFlags windowFlags = 0;
	virtual void OnEnd() {}
	virtual void OnDraw() {}
	virtual void PreWindow() {}
public:
	bool Fullscreen = false;
	IPanel(const char* t) : title(t), bgColor(0.3f, 0.3f, 0.3f, 1.0f), titleColor(0.2f, 0.2f, 0.2f, 1.0f) {}
	IPanel(const char* t, ImVec4 c, ImVec4 tc) : title(t), bgColor(c), titleColor(tc) {}
	void SetFlags(ImGuiWindowFlags flags) {
		windowFlags = flags;
	}
	void Draw();
	void ColoredText(const char* text, ImU32 color, float barHeight);
};

