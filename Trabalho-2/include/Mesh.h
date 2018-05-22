#ifndef __MYMESH__
#define __MYMESH__
#include <glm/glm.hpp>
#include "../helpers/loaders.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <string>
#include "Shader.h"

struct Vertex{
    glm::vec3 position;
    Vertex(glm::vec3 pos) : position(pos){}
    Vertex(GLfloat x, GLfloat y, GLfloat z) : position(glm::vec3(x,y,z)){}
};

struct Mesh {
    std::vector<Vertex> vertices;
    public:
    Mesh(){}
    Mesh(std::string);
    Mesh(std::vector<Vertex>);
};
#endif