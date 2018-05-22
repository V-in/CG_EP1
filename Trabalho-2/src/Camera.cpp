#include "../include/Camera.h"

Camera::Camera (glm::vec3 pos_,  
                glm::vec3 lookAt_,
                glm::vec3 up_,
                glm::vec3 vel_,
                glm::vec3 acel_){

    pos    = pos_;
    lookAt = lookAt_;
    up     = up_;
    vel    = vel_;
    acel   = acel_;
}