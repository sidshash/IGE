#pragma once
#include <GL/glew.h>
#include <fstream>
#include <string>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Logger/Logger.h"
class Shader
{
	GLuint vertexShaderId, fragmentShaderId, programId;
	std::string Read(const char* shaderLocation);
	void CheckCompileStatus(GLuint shader);
public:
	Shader(const char* vertexShaderLocation, const char* fragmentShaderLocation);
	void Use() const;
	void UniformMat4(std::string location, glm::mat4 mat);
};

