#include "LeftPanel.h"
#include "../Panel.h"
#include "../../../Application.h"
#include "../../../Scene/Scene.h"

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
                onEvent(new Event({EventName::CREATE_GAME_OBJECT, EventType::EDITOR}));
            }
            ImGui::EndMenu();
        }
        if (ImGui::Button("Save")) {
            const char* filterPatterns[1] = { "*.cn" };
            const char* filePath = tinyfd_saveFileDialog("Save As", "", 1, filterPatterns, NULL);

            if (filePath) {
                Locator::GetScene()->SaveScene(filePath);
            }
        }
        if (ImGui::Button("Load")) {
            const char* filterPatterns[1] = { "*.cn" };
            const char* filePath = tinyfd_openFileDialog("Choose a scene file", "", 1, filterPatterns, NULL, 0);

            if (filePath) {
                Locator::GetScene()->LoadScene(filePath);
            }
        }
        ImGui::EndMenuBar();
    }

	for (int i = 0; i < gameObjects->size(); i++) {
        char text[128];
        std::snprintf(text, sizeof(text), "%s##%d", (*gameObjects)[i]->GetName().c_str(), (*gameObjects)[i]->GetId());
        if(ImGui::Selectable(text))
            mPanel->SetSelected((*gameObjects)[i]);
	}

}

void LeftPanel::PreWindow() {
    //ImGuiIO io = ImGui::GetIO();
    //ImGui::SetNextWindowPos(ImGui::GetCursorPos());
}
