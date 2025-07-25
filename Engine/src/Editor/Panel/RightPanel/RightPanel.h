#pragma once
#include "../IPanel.h"
#include "../../Inspectable/IInspectable.h"
#include "../../../Components/Component.h"
#include "../../../Components/GameObject.h"
#include "../../../Util/ScriptAPI.h"
#include <format>
class GameObject;
class RightPanel : public IPanel
{
		ImGuiWindowFlags flags =
		ImGuiWindowFlags_NoTitleBar |
		//ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse;
		//ImGuiWindowFlags_NoMove;
		IInspectable* mSelectedItem = nullptr;
		void DrawComponent(Component* c);
		void DrawTransform(Transform* t);
		void DrawMesh(Mesh* m);
		void DrawRigidbody(Rigidbody* rb);
		void DrawBoxCollider2D(BoxCollider2D* bc);
		void DrawScript(Script* script);
public:
	RightPanel() :
		IPanel("Inspector")
	{
		SetFlags(flags);
	}
	void PreWindow() override;
	void OnDraw() override;
	void SetSelected(IInspectable* selectedItem);
	void DrawInspectable(IInspectable* inspectable);
	void DrawGameObject(GameObject* gameObject);
};

