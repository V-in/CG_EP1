#ifndef __ENTITY__
#define __ENTITY__
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Shader.h"
#include <glm/gtx/transform.hpp>
#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
class Object{
    protected:
    glm::vec3 pos;
    glm::vec3 lookAt;
    glm::vec3 vel;
    glm::vec3 acel;
    Mesh mesh;
    GLuint VAO, VBO;
    GLuint vertexShaderID, fragmentShaderID;
    public:
    GLuint shaderProgram;

    Object(){}
    Object(Mesh&, 
           glm::vec3 pos    = glm::vec3(0,0,0),  
           glm::vec3 lookAt = glm::vec3(0,0,0),
           glm::vec3 vel    = glm::vec3(0,0,0),
           glm::vec3 acel   = glm::vec3(0,0,0));
    void draw();
    void setUpAttributes();
    void setShaders(Shader, Shader);
    void moveTo(glm::vec3& newPos);
    //Context interfaces with the following function
    glm::mat4 getTransformMatrix(Camera&);
    friend class Context;
};
#endif 