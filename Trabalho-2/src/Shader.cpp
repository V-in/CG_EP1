#include "../include/Shader.h"

Shader::Shader(std::string file_path, GLuint type){
    if(type ==  GL_VERTEX_SHADER){
    	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

        id = vertexShaderID;

        std::string vertexShaderCode_ = loadShader(file_path);
        const char* vertexShaderCode = vertexShaderCode_.c_str();

        glShaderSource(vertexShaderID, 1, &vertexShaderCode, NULL);
        glCompileShader(vertexShaderID);
        checkShaderCompileStatus(vertexShaderID);
    }
    else if(type == GL_FRAGMENT_SHADER){
        GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        id = fragmentShaderID;

        std::string fragmentShaderCode_ = loadShader(file_path);
        const char* fragmentShaderCode = fragmentShaderCode_.c_str();

        glShaderSource(fragmentShaderID, 1, &fragmentShaderCode, NULL);
        glCompileShader(fragmentShaderID);
        checkShaderCompileStatus(fragmentShaderID);
    }
}