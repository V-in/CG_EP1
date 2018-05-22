#ifndef __CAMERA__
#define __CAMERA__
#include <glm/glm.hpp>

class Camera{
    public:
    glm::vec3 pos;
    glm::vec3 lookAt;
    glm::vec3 up;
    //We will use velocity information later
    glm::vec3 vel  = glm::vec3(0,0,0);
    glm::vec3 acel = glm::vec3(0,0,0);
    Camera(){}
    Camera(glm::vec3 pos,  
           glm::vec3 lookAt,
           glm::vec3 up_,
           glm::vec3 vel_    = glm::vec3(0,0,0),
           glm::vec3 acel_   = glm::vec3(0,0,0));
};
#endif

