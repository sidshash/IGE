#include "Panel.h"

Panel::Panel(const char* t) :

	IPanel("DockHost"),
	leftPanel(this),
	vpPanel(),
	rightPanel()

{
	Fullscreen = true;
	SetFlags(mainFlags);
}

void Panel::SetSelected(IInspectable* selectedItem) {
	rightPanel.SetSelected(selectedItem);
}

void Panel::OnDraw() {


	leftPanel.Draw();
	vpPanel.Draw();
	rightPanel.Draw();

}

void Panel:: OnEnd() {
	vpPanel.DrawOnFB();
}

void Panel::PreWindow() {
	DrawDockSpace();
}

void Panel::DrawDockSpace()
{
	ImGuiWindowFlags hostFlags =
		ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus |
		ImGuiWindowFlags_NoBackground;               // host is invisible

	ImGuiViewport* vp = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(vp->WorkPos);
	ImGui::SetNextWindowSize(vp->WorkSize);
	ImGui::SetNextWindowViewport(vp->ID);

	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::Begin("DockHost", nullptr, hostFlags);    //  host
	ImGui::PopStyleVar();
	ImGui::PopStyleVar();

	ImGuiID dockID = ImGui::GetID("MainDockSpace");
	ImGui::DockSpace(dockID, ImVec2(0, 0), ImGuiDockNodeFlags_None);

	ImGui::End();
	static bool firstTime = true;
	if (firstTime)
	{
		firstTime = false;

		ImGui::DockBuilderRemoveNode(dockID);              // clear old layout
		ImGui::DockBuilderAddNode(dockID, ImGuiDockNodeFlags_DockSpace);
		ImGui::DockBuilderSetNodeSize(dockID, vp->WorkSize);

		// Split: 20?% left, 60?% middle, 20?% right
		ImGuiID left, center, right;
		ImGui::DockBuilderSplitNode(dockID, ImGuiDir_Left, 0.20f, &left, &center);
		ImGui::DockBuilderSplitNode(center, ImGuiDir_Right, 0.25f, &right, &center);

		// Dock our windows by *name*
		ImGui::DockBuilderDockWindow("Hierarchy", left);
		ImGui::DockBuilderDockWindow("Viewport", center);
		ImGui::DockBuilderDockWindow("Inspector", right);

		ImGui::DockBuilderFinish(dockID);                   // done
	}
}
