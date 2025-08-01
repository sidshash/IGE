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

    Time::mLastTime = (float)glfwGetTime();
    Time::mLastSecond = (float)glfwGetTime();

    //MULTITHREADING STUFF
    running = true;
    updateThread = std::thread([this]() {
        while (running) {
            float now = (float)glfwGetTime();
            float deltaTime = now - Time::mLastTime;
            Time::mLastTime = now;
            Time::mDeltaTime = deltaTime;

            {
                std::lock_guard<std::mutex> lock(gameObjectMutex);
                this->OnUpdate();
                this->physics->Update(gameObjects);
            }

            // Sleep a bit to prevent CPU spinning
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        });
    //////////////////////

    while (!glfwWindowShouldClose(window))
    {

        Time::mCurrentTime = (float)glfwGetTime();

        //physics->SetDeltaTime(now - gLastTime);
        //Time::SetDeltaTime(now - lastTime);
        Time::mDeltaTime = Time::mCurrentTime - Time::mLastTime;

        glfwPollEvents();
        windowHandler->HandleInput();

        OnUpdate();

	    //physics->Update(gameObjects);
        {
            std::lock_guard<std::mutex> lock(gameObjectMutex);


            renderer->DrawEditor(editor);

            renderer->Draw(gameObjects);
        }

        glfwSwapBuffers(window);
        if (Time::mCurrentTime - Time::mLastSecond > 1.0) {
            Time::mFPS = (int)(1.0f / Time::mDeltaTime);
            Time::mLastSecond = Time::mCurrentTime;
        }
        Time::mLastTime = Time::mCurrentTime;
    }
    // Shutdown
    OnEnd();
    running = false;
    if (updateThread.joinable())
        updateThread.join();
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





