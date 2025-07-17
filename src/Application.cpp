#include "Application.h"

Application::Application()
{
    Locator::SetApplication(this);
    windowHandler = new Window(600, 600, "IGE");
    editor = new Editor();
    renderer = new Renderer(windowHandler->window);
    physics = new Physics();
}

void Application::Run() {
	GLFWwindow* window = windowHandler->window;


    //frame rate
    double  gLastTime = glfwGetTime();
    int     gFrameCount = 0;
    double  gFPS = 0.0;
    
    renderer->Init();

    editor->Init();

    OnStart();

    while (!glfwWindowShouldClose(window))
    {

        ++gFrameCount;
        double now = glfwGetTime();
        if (now - gLastTime >= 1.0) {  // If more than 1 second passed
            gFPS = gFrameCount / (now - gLastTime);
            gFrameCount = 0;
            gLastTime = now;
        }

        glfwPollEvents();
        windowHandler->HandleInput();

        renderer->SetFPS(gFPS);

        renderer->DrawEditor(editor);

        renderer->Draw(gameObjects);

        glfwSwapBuffers(window);
    }

    OnEnd();
    editor->OnClose();
    glfwTerminate();
}


GameObject* Application::CreateGameObject(const char* n) {
    GameObject* obj = new GameObject(n);
    gameObjects.push_back(obj);
    return obj;
}

Window* Application::GetWindow() { return windowHandler; }

Editor* Application::GetEditor() { return editor; }

std::vector<GameObject*>* Application::GetObjectList() {
    return &gameObjects;
}




