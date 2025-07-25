#pragma once
#include "../Interfaces/IGameObject.h"
#include "../ENGINE_API.h"

class ENGINE_API ScriptBehaviour
{
    IGameObject* gameObject = nullptr;
public:
    ~ScriptBehaviour() {
        delete gameObject;
    }
    void SetGameObject(IGameObject* gO);

    virtual void OnStart() = 0;

    virtual void OnUpdate() = 0;

    virtual void OnFixedUpdate() = 0;

    template<class T>
    T* GetComponent() {
        return gameObject->GetComponent<T>();
    }


};

