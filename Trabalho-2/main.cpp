#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "./helpers/loaders.h"
#include "./helpers/checkShaderCompileStatus.h"
#include "./include/Object.h"
#include "./include/Context.h"
#include "./include/Shader.h"
#include <iostream>
using namespace glm;


int main(){
    Context context("Opengl", 600,600);
    context.init();

    Mesh mesh = Mesh("./monkey_head2.obj");
    Shader vertex = Shader("./shaders/basicVertex.glsl", GL_VERTEX_SHADER);
    Shader fragment = Shader("./shaders/basicFragment.glsl", GL_FRAGMENT_SHADER);

    Object obj(mesh);
    obj.setShaders(vertex, fragment);
    obj.setUpAttributes();

    context.addObject(obj);

    context.setCamera({0,0, 1.3}, {0,0,-1}, {0,1,0});

    context.loop();
}