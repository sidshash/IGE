#define STB_IMAGE_IMPLEMENTATION
#include "AssetLoader.h"
#include <filesystem>

unsigned char* AssetLoader::LoadImage(const char* path, int& width, int& height, int& channels)
{
    unsigned char* data = stbi_load(path, &width, &height, &channels, 4);
    if (!data) {
        Logger::Log(LogLevel::Error, "Failed to Load Image");
        return nullptr;
    }
    return data;
}
