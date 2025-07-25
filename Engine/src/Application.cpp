#include "Application.h"

void Application::OnStart()
{
    //gameObjects
}

void Application::OnUpdate()
{
    for (GameObject* g : gameObjects) {
        Script* script = (*g).GetComponent<Script>();
        if (script != nullptr) {
            script->GetScriptBehaviour()->OnUpdate();
        }
    }
}

void Application::OnEnd() {

}

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
    float  gLastTime = (float)glfwGetTime();
    int     gFrameCount = 0;
    double  gFPS = 0.0;

    
    renderer->Init();

    editor->Init();

    OnStart();

    float lastTimeFpsSet = (float)glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {

        ++gFrameCount;
        float now = (float)glfwGetTime();
        if (now - gLastTime >= 1.0) {  // If more than 1 second passed
            gFPS = gFrameCount / (now - gLastTime);
            gFrameCount = 0;
        }

        physics->SetDeltaTime(now - gLastTime);

        glfwPollEvents();
        windowHandler->HandleInput();

        OnUpdate();

	    physics->Update(gameObjects);

        if ((now - lastTimeFpsSet) > 1.0) {
            renderer->SetFPS((int)(1.0f / (now - gLastTime)));
            lastTimeFpsSet = now;
        }

        renderer->DrawEditor(editor);

        renderer->Draw(gameObjects);

        glfwSwapBuffers(window);
        gLastTime = now;
    }

    OnEnd();
    editor->OnClose();
    glfwTerminate();
}


GameObject* Application::CreateGameObject(const char* n) {
    GameObject* obj = new GameObject(n);
    obj->AddComponent<Transform>();
    gameObjects.push_back(obj);
    return obj;
}

Window* Application::GetWindow() { return windowHandler; }

Editor* Application::GetEditor() { return editor; }

std::vector<GameObject*>* Application::GetObjectList() {
    return &gameObjects;
}




