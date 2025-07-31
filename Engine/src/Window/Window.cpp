#include "Window.h"

Window::Window(int w, int h, const char* title)
{
    AddObserver(this);
    WIDTH = w;
    HEIGHT = h;
    TITLE = title;
    status = Init();
    Logger::Log(LogLevel::Info, "Window Created", "Application");
}

int Window::Init() {
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    
    /* Create a windowed mode window and its OpenGL context */
    glfwInit();
    //glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window = glfwCreateWindow(800, 600, TITLE, nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        return -1;

    
}


void Window::HandleInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        onEvent(new Event({ EventName::KEYPRESS, EventType::INPUT, reinterpret_cast<void*>(static_cast<uintptr_t>(KEY::ESC))}));
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        onEvent(new Event({ EventName::KEYPRESS, EventType::INPUT, reinterpret_cast<void*>(static_cast<uintptr_t>(KEY::W))}));
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        onEvent(new Event({ EventName::KEYPRESS, EventType::INPUT, reinterpret_cast<void*>(static_cast<uintptr_t>(KEY::A))}));
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        onEvent(new Event({ EventName::KEYPRESS, EventType::INPUT, reinterpret_cast<void*>(static_cast<uintptr_t>(KEY::S))}));
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        onEvent(new Event({ EventName::KEYPRESS, EventType::INPUT, reinterpret_cast<void*>(static_cast<uintptr_t>(KEY::D))}));

}

void Window::onNotify (Event *e) {
    switch (e->name) {      //switch case for different window events
    case EventName::KEYPRESS:
        KEY key = static_cast<KEY>(reinterpret_cast<uintptr_t>(e->data));
        switch (key) {     //switch case for individual key check
        case KEY::ESC:
            glfwSetWindowShouldClose(window, true);
            break;
        }

        break;
    }
}
