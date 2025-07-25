#include "Script.h"

Script::Script(GameObject* gameObject):
	Component(gameObject)
{

}

Script::~Script()
{
	ScriptAPI::DestroyScript(mHModule);
	//delete mBehaviour;
}

ScriptBehaviour* Script::GetScriptBehaviour() const
{
	return mBehaviour;
}

void Script::SetName(std::string name) {
	mName = name;
}

void Script::SetBehaviour(ScriptBehaviour* behaviour)
{
	mBehaviour = behaviour;
	mBehaviour->OnStart();
}

