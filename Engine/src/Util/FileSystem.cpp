#include "FileSystem.h"

std::vector<const char*> FileSystem::routes = {
	"src",
	"Assets"
};
std::vector<Path> FileSystem::paths = std::vector<Path>();


void FileSystem::SearchAssets()
{

	std::filesystem::path path = std::filesystem::current_path();
	for (const char* c : routes) {
		path = path / c;
	}

	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		std::string filename = entry.path().filename().string();
		std::string pathName = entry.path().string();
		if (std::filesystem::is_directory(entry)) {
			Path path({ filename, pathName, PathType::DIRECTORY });
			paths.push_back(path);
		}
		else if (std::filesystem::is_regular_file(entry)) {
			if (entry.path().extension() == ".cpp") {
				Path path({ filename, pathName, PathType::SCRIPT });
				paths.push_back(path);
			}
			else {
				Path path({ filename, pathName, PathType::FILE });
				paths.push_back(path);
			}
		}

	}
}

std::vector<Path> FileSystem::GetPaths()
{
	return paths;
}

void FileSystem::PushPath(const char* path)
{
	routes.push_back(path);
	paths.clear();
	SearchAssets();
}

bool FileSystem::isHome() {
	return routes.size() <= 2;
}

void FileSystem::PopPath() {
	routes.pop_back();
	paths.clear();
	SearchAssets();
}
