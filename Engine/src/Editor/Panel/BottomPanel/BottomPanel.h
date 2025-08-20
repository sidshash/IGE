#pragma once
#include "../../../Util/AssetLoader.h"
#include "../IPanel.h"
#include "GL/glew.h"
#include "../../../Util/FileSystem.h"



class BottomPanel: public IPanel
{
	unsigned char* image;
	GLuint folderTextureID;
	GLuint cppTextureID;
	GLuint defaultTextureID;
	void DrawFolder(const char* name, GLuint id);
public:
	BottomPanel();
	void CreateTexture(int index, const char* path, GLuint& id);
	void OnDraw() override;
};

