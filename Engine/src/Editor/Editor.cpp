#include "Editor.h"
#include "../Application.h"

Editor::Editor() :
    windowHandler(Locator::GetApplication()->GetWindow()),
    panel(nullptr)
{
    Logger::Log(LogLevel::Info, "Editor Created", "Application");
}

void Editor::Init() {
    panel = new Panel("Main");

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Setup Platform/Rendererer backends
    ImGui_ImplGlfw_InitForOpenGL(Locator::GetApplication()->GetWindow()->window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();
}

void Editor::Draw() {
    // 1) Start Dear ImGui frame  ----------------------------
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // 1‑A) Build UI – we only gather size here, no renderering yet
    //panel->SetFPS(fps);
    panel->Draw();

    // 3) Rendererer scene into the (possibly) new FBO -------------

}

void Editor::OnClose() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Editor::onNotify(Event* e) {
    switch (e->name) {
    case EventName::CREATE_GAME_OBJECT:
        Locator::GetApplication()->CreateGameObject();
        break;
    }
    onEvent(new Event(*e));
}

