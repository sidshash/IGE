#pragma once
class Panel;
#include <vector>
#include "../IPanel.h"
#include "../../../Components/GameObject.h"
#include "../.././../Locator/Locator.h"
#include "../../../Util/Writer.h"
#include "../../../Util/Reader.h"

class LeftPanel: public IPanel
{
	std::vector<GameObject*>* gameObjects;
	ImGuiWindowFlags flags =
		ImGuiWindowFlags_NoTitleBar |
		//ImGuiWindowFlags_NoResize |
		//ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_MenuBar |
		ImGuiWindowFlags_NoCollapse;
	Panel* mPanel;

public:
	LeftPanel(Panel* panel);
	void PreWindow() override;
	void OnDraw() override;
};

