#include "IPanel.h"


void IPanel::Draw() {
	//if (Fullscreen) {
	//	ImGuiViewport* vp = ImGui::GetMainViewport();
	//	ImGui::SetNextWindowPos(vp->WorkPos);
	//	ImGui::SetNextWindowSize(ImVec2(vp->WorkSize.x, vp->WorkSize.y));
	//}
	PreWindow();
	/*ImGui::PushStyleColor(ImGuiCol_WindowBg, bgColor);
	ImGui::PushStyleColor(ImGuiCol_TitleBg, titleColor);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));*/
	ImGui::Begin(title, nullptr, windowFlags);
	//ImGui::PopStyleVar();
	//ImGui::PopStyleColor();
	//ImGui::PopStyleColor();
	OnDraw();
	ImGui::End();
	OnEnd();
}

void IPanel::ColoredText(const char* text, ImU32 color, float barHeight) {
	//// Calculate text size

	ImVec2 barMin = ImGui::GetWindowPos();

	ImVec2 barMax = ImVec2(
		barMin.x + ImGui::GetWindowSize().x,
		barMin.y + barHeight
	);


	//// Get position

	// Draw background rectangle
	ImGui::GetWindowDrawList()->AddRectFilled(
		barMin,
		barMax,
		color // Background color (RGBA)
	);

	ImGui::TextUnformatted(text);
}
