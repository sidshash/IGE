#pragma once
#include "../Component.h"
#include "../GameObject.h"
#include <Core.h>
#define NOMINMAX
#include <Windows.h>
#include "../../Util/ScriptAPI.h"
class Script: public Component, public IScript
{
	friend class ScriptAPI;
	friend class Writer;
	friend class Reader;
	friend class RightPanel;
	std::string mName, mLocation;
	HMODULE mHModule;
	ScriptBehaviour* mBehaviour = nullptr;
public:
	Script(GameObject* gameObject);
	~Script();
	ScriptBehaviour* GetScriptBehaviour() const;
	void SetName(std::string name);
	void SetBehaviour(ScriptBehaviour* behaviour);
	ComponentType GetType() override { return ComponentType::Script; }
};

