#pragma once
#include "../../Util/AssetLoader.h"
#include "../IPanel.h"
#include "GL/glew.h"
class BottomPanel: public IPanel
{
	unsigned char* image;
	GLuint folderTextureID;
	GLuint cppTextureID;
	void DrawFolder(const char* name, GLuint id);
public:
	BottomPanel();
	void CreateTexture(int index, const char* path, GLuint& id);
	void OnDraw() override;
};

