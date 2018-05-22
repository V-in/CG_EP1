#include "../include/Context.h"

Context::Context(std::string window_name_, int width_, int height_){
    window_name = window_name_;
    width       = width_;
    height      = height_;
}

void Context::addObject(Object& obj){
    objects.push_back(obj);
}

void Context::init(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(600,600,window_name.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

}

void Context::setCamera(glm::vec3 pos, glm::vec3 lookAt, glm::vec3 up){
    camera = Camera(pos, lookAt, up);
}

glm::mat4 Context::getTransformMatrix(Object& obj){
    //Model
    glm::mat4 transform(obj.getTransformMatrix(camera));
    return transform;
}

void Context::loop(){
    while(!glfwWindowShouldClose(window)){
		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0,0,width,height);
        for(auto& obj : objects){
            glBindVertexArray(obj.VAO);
            glBindBuffer(GL_ARRAY_BUFFER, obj.VBO);

            GLint transformLocation = glGetUniformLocation(obj.shaderProgram, "transform");
            glm::mat4 transform = getTransformMatrix(obj);

            

            glUniformMatrix4fv(transformLocation, 1, GL_FALSE, &transform[0][0]); 

            obj.draw();
        }
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

Context::~Context(){
    glfwTerminate();
}

