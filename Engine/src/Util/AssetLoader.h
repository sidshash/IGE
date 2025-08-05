#pragma once
#include "stb_image.h"
#include <Core.h>
class AssetLoader
{
public:
	static unsigned char* LoadImage(const char* path, int& width, int& height, int& channels);
};

