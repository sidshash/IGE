#include "LeftPanel.h"
#include "../Panel.h"
#include "../../../Application.h"

LeftPanel::LeftPanel(Panel* panel) :
    IPanel("Hierarchy"),
    gameObjects(Locator::GetApplication()->GetObjectList()),
    mPanel(panel)
{
    AddObserver(Locator::GetApplication()->GetEditor());
    SetFlags(flags);
}

void LeftPanel::OnDraw(){



    //// label on the left
    //ColoredText("Explorer", IM_COL32(10, 10, 10, 100), 35);

    //ImGui::SameLine(ImGui::GetWindowSize().x - 18); // Right-aligned
    ////ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
    //if (ImGui::Button("+"))
    //    ImGui::OpenPopup("AddObjectPopup");
    ////ImGui::PopStyleColor();
    //if (ImGui::BeginPopup("AddObjectPopup")) {
    //    if (ImGui::MenuItem("GameObject")) {
    //        onEvent(new Event({Events::CREATE_GAME_OBJECT, Events::EDITOR}));
    //    }
    //    if (ImGui::MenuItem("Camera")) { /* create */ }
    //    if (ImGui::MenuItem("Light")) { /* create */ }
    //    // etc...
    //    ImGui::EndPopup();
    //}

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Create")) {
            if (ImGui::MenuItem("GameObject")) { 
                onEvent(new Event({Events::CREATE_GAME_OBJECT, Events::EDITOR}));
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

	for (int i = 0; i < gameObjects->size(); i++) {
        char text[128];
        std::snprintf(text, sizeof(text), "%s##%d", (*gameObjects)[i]->name.c_str(), (*gameObjects)[i]->id);
        if(ImGui::Selectable(text))
            mPanel->SetSelected((*gameObjects)[i]);
	}

}

void LeftPanel::PreWindow() {
    //ImGuiIO io = ImGui::GetIO();
    //ImGui::SetNextWindowPos(ImGui::GetCursorPos());
}
