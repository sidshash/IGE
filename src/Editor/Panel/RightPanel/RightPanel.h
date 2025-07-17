#pragma once
#include "../IPanel.h"
#include "../../Inspectable/IInspectable.h"
class RightPanel : public IPanel
{
		ImGuiWindowFlags flags =
		ImGuiWindowFlags_NoTitleBar |
		//ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse;
		//ImGuiWindowFlags_NoMove;
		IInspectable* mSelectedItem = nullptr;
public:
	RightPanel() :
		IPanel("Inspector")
	{
		SetFlags(flags);
	}
	void PreWindow() override;
	void OnDraw() override;
	void SetSelected(IInspectable* selectedItem);
};

