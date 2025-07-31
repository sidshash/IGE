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

void Application::onNotify(Event* e)
{
    for (GameObject* g : gameObjects) {
        Script* script = g->GetComponent<Script>();
        if (script != nullptr) {
            script->GetScriptBehaviour()->OnEvent(e);
        }
    }
}

Application::Application()
{
    Locator::SetApplication(this);
    windowHandler = new Window(600, 600, "IGE");
    editor = new Editor();
    renderer = new Renderer(windowHandler->window);
    physics = new Physics();

    //SET OBSERVER
    windowHandler->AddObserver(this);
    editor->AddObserver(this);
}

void Application::Run() {
	GLFWwindow* window = windowHandler->window;

    renderer->Init();

    editor->Init();

    OnStart();

    Time::mLastTime = glfwGetTime();
    Time::mLastSecond = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {

        Time::mCurrentTime = glfwGetTime();

        //physics->SetDeltaTime(now - gLastTime);
        //Time::SetDeltaTime(now - lastTime);
        Time::mDeltaTime = Time::mCurrentTime - Time::mLastTime;

        glfwPollEvents();
        windowHandler->HandleInput();

        OnUpdate();

	    physics->Update(gameObjects);

        renderer->DrawEditor(editor);

        renderer->Draw(gameObjects);

        glfwSwapBuffers(window);
        if (Time::mCurrentTime - Time::mLastSecond > 1.0) {
            Time::mFPS = (1 / Time::mDeltaTime);
            Time::mLastSecond = Time::mCurrentTime;
        }
        Time::mLastTime = Time::mCurrentTime;
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




