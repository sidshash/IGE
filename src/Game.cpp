#include "Application.h"
#include "Logger/Logger.h"
#include <iostream>

class MyGame : public Application {
protected:
	void OnStart() override {

		Logger::Log(LogLevel::Info, "Engine Started", "Application");

		
	}
	void OnUpdate() override {

	}
	void OnEnd() override {
		Logger::Log(LogLevel::Info, "Engine Ended", "Application");
	}
};

int main() {
	MyGame game;
	game.Run();
	return 0;
}