#include "Scene.h"
#include "../Application.h"

void Scene::LoadScene(const char* location) {
	std::ifstream in(location, std::ios::binary);
	Reader::ReadScene(*(Locator::GetApplication()->GetObjectList()), in);
}

void Scene::SaveScene(const char* location) {
	std::ofstream out(location, std::ios::binary);
	Writer::WriteScene(*(Locator::GetApplication()->GetObjectList()), out);

}