#ifndef __CONTEXT__
#define __CONTEXT__
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Object.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
#include <string>
#include <iostream>

class Context {
    GLFWwindow* window;
    std::string window_name;
    int width, height;
    Camera camera;
    std::vector<Object> objects; 
    public:
    Context(std::string window_name, int width, int height);
    ~Context();
    void addObject(Object&);
    void setCamera(glm::vec3 pos, glm::vec3 lookAt, glm::vec3 up);
    glm::mat4 getTransformMatrix(Object& obj);
    void init();
    void loop();
};
#endif