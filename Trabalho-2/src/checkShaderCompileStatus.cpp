#include "../helpers/checkShaderCompileStatus.h"

void checkShaderCompileStatus(GLuint shaderID){
	GLint status;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
	auto success = std::string("Compiled successfully");
	auto failure = std::string("Failed to compile");
	std::cerr << "Shader compile status: " << ((status == GL_TRUE)?  success : failure) << std::endl;
	char buffer[512];
	glGetShaderInfoLog(shaderID, 512, NULL, buffer);
	std::cerr << buffer << std::endl;
}