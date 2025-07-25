#include "Application.h"
#include "Logger/Logger.h"
#include <iostream>

class MyGame : public Application {
};

int main() {
	MyGame game;
	game.Run();
	return 0;
}