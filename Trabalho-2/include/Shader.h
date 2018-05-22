#ifndef __SHADER__
#define __SHADER__
#include <GL/glew.h>
#include <GL/gl.h>
#include "../helpers/checkShaderCompileStatus.h"
#include "../helpers/loaders.h"
#include <string>
#include <vector>

struct Shader{
    GLuint id;
    Shader(std::string file_path, GLuint type);
};
#endif