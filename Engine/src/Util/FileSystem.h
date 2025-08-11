#pragma once
#include <iostream>
#include <filesystem>

enum class PathType {
	DIRECTORY,
	MESH,
	SCRIPT,
	SCENE,
	FILE
};

struct Path {
	const std::string filename;
	const std::string path;
	const PathType type;
};

class FileSystem
{
	static std::vector<Path> paths;
	static std::string currentPath;
	static std::string originalPath;
public:
	static void SearchAssets();
	static std::vector<Path> GetPaths();
	static std::vector<const char* > routes;
	static void PushPath(const char* path);
	static bool isHome();
	static void PopPath();
};

