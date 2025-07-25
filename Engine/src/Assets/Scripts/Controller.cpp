#include <Core.h>

class Controller : public ScriptBehaviour {
public:
    void OnStart() override {
        // This code runs on instantiation
        ITransform* transform = GetComponent<ITransform>();
        Vector3 position(2, 2, 0);
        transform->SetPosition(position);
    }

    void OnUpdate() override {
        // This code runs on update
    }

    void OnFixedUpdate() override {
        // This code runs on fixed update
    }
};

extern "C" __declspec(dllexport) ScriptBehaviour* CreateScriptInstance() {
    return new Controller();
}
