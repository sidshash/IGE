#pragma once
#include "../Util/Writer.h"
#include "../Util/Reader.h"
#include "../Locator/Locator.h"
class Application;

class Scene
{
public:
	Scene() {
		Locator::SetScene(this);
	}
	static void LoadScene(const char* location);
	static void SaveScene(const char* location);
};

