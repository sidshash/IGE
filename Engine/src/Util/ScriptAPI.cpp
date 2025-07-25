#include "ScriptAPI.h"
#include "../Components/Script/Script.h"


 void ScriptAPI::Reload(Script* script){
     //delete script->mBehaviour;
     DestroyScript(script->mHModule);
     CompileScript("src/Assets/Scripts/", script->mName);
     script->mHModule = LoadScript(script->mName);
     ScriptBehaviour* behaviour = CreateBehaviour(script->mHModule);
     behaviour->SetGameObject(script->gameObject);
     script->SetBehaviour(behaviour);
    }
