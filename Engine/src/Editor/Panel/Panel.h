#pragma once
#include "LeftPanel/LeftPanel.h"
#include "ViewportPanel/ViewportPanel.h"
#include "RightPanel/RightPanel.h"
#include "BottomPanel/BottomPanel.h"

class Panel : public IPanel {

	ImGuiWindowFlags mainFlags =
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoTitleBar;

	LeftPanel leftPanel;

	ViewportPanel vpPanel;

	RightPanel rightPanel;

	BottomPanel bottomPanel;

public:

	Panel(const char* t);

	void SetSelected(IInspectable* selectedItem);

	void OnDraw() override;

	void OnEnd() override;

	void PreWindow() override;

	void DrawDockSpace();
};