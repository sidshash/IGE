#include "Shader.h"

Shader::Shader(const char* vertexShaderLocation, const char* fragmentShaderLocation) {
	std::string vShaderString = Read(vertexShaderLocation);
	std::string fShaderString = Read(fragmentShaderLocation);

	const char* vShaderSource = vShaderString.c_str();
	const char* fShaderSource = fShaderString.c_str();

	vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShaderId, 1, &vShaderSource, 0);
	glShaderSource(fragmentShaderId, 1, &fShaderSource, 0);

	glCompileShader(vertexShaderId);
	glCompileShader(fragmentShaderId);

	Logger::Log(LogLevel::Info, "Compiling Shaders", "Renderer");

	CheckCompileStatus(vertexShaderId);
	CheckCompileStatus(fragmentShaderId);

	programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glLinkProgram(programId);

	glDeleteShader(vertexShaderId);
	glDeleteShader(vertexShaderId);
}

std::string Shader::Read(const char* shaderLocation) {
	std::ifstream in(shaderLocation);
	std::string line, code;
	while (std::getline(in, line)) {
		code += line + "\n";
	}
	return code;
}

void Shader::Use() const {
	glUseProgram(programId);
}


void Shader::CheckCompileStatus(GLuint shader) {
	// Check compile status
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) {
		GLint logLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

		GLchar errorLog[512];
		glGetShaderInfoLog(shader, logLength, nullptr, errorLog);

		Logger::Log(LogLevel::Error, "Shader Compilation Failed", "Renderer");
	}
		Logger::Log(LogLevel::Info, "Shader Compiled", "Renderer");
}

void Shader::UniformMat4(std::string location, glm::mat4 mat) {
	GLint mLocation = glGetUniformLocation(programId, location.c_str());
	glUniformMatrix4fv(mLocation, 1, GL_FALSE, glm::value_ptr(mat));
}
void Shader::Uniform3f(std::string location, Vector val) {
	GLint mLocation = glGetUniformLocation(programId, location.c_str());
	glUniform4f(mLocation, val.x, val.y, val.z, 1.0f);
}
