#include <Core.h>
#include <iostream>
enum class MovementDirection {
    None,
    Up,
    Down,
    Left,
    Right
};

MovementDirection movementState = MovementDirection::None;
float speed = 5.0f;
IRigidbody* rbptr;

class Controller : public ScriptBehaviour {
public:
    void OnStart() override {
        // This code runs on instantiation
        rbptr = GetComponent<IRigidbody>();
    }

    void OnUpdate() override {
        // This code runs on update
        //speed.y = 0.0f;

        if (rbptr != nullptr) {
            IRigidbody& rb = *rbptr;
            switch (movementState) {
            case MovementDirection::Up:
                rb.SetVelocity(Vector3(0, 1, 0) * speed);
                break;
            case MovementDirection::Down:
                rb.SetVelocity(Vector3(0, -1, 0) * speed);
                break;
            case MovementDirection::Left:
                rb.SetVelocity(Vector3(-1, 0, 0) * speed);
                break;
            case MovementDirection::Right:
                rb.SetVelocity(Vector3(1, 0, 0) * speed);
                break;
            default:
                rb.SetVelocity(Vector3(0));
                break;
            }

            // Reset after applying, if movement is event-driven
            movementState = MovementDirection::None;
        }
    }

    void OnFixedUpdate() override {
        // This code runs on fixed update
    }

    void OnEvent(Event* e) override {
        if (e == nullptr) return;
        Event event = *e;

        if (event.type == EventType::INPUT) {
            KEY key = *static_cast<KEY*>(event.data);
            switch (key) {
            case KEY::W:
                movementState = MovementDirection::Up;
                break;
            case KEY::S:
                movementState = MovementDirection::Down;
                break;
            case KEY::A:
                movementState = MovementDirection::Left;
                break;
            case KEY::D:
                movementState = MovementDirection::Right;
                break;
            default:
                movementState = MovementDirection::None;
            }
        }
    }
};

extern "C" __declspec(dllexport) ScriptBehaviour* CreateScriptInstance() {
    return new Controller();
}
