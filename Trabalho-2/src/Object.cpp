#include "../include/Object.h"

Object::Object(Mesh& mesh_, 
               glm::vec3 pos_, 
               glm::vec3 lookAt_,
               glm::vec3 vel_,
               glm::vec3 acel_) : mesh(mesh_){

    
    pos = pos_;
    lookAt = lookAt_;
    vel = vel_;
    acel = acel_;

    glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(GLfloat) * 3, &mesh.vertices[0], GL_STATIC_DRAW);
}

void Object::moveTo(glm::vec3& newPos){
    pos = newPos;
}

void Object::draw(){
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glUseProgram(shaderProgram);
	glDrawArrays(GL_TRIANGLES, 0, mesh.vertices.size());
}

void Object::setUpAttributes(){
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, 0);
}

float i = 0;
glm::mat4 Object::getTransformMatrix(Camera& cam){
    glm::mat4 model(1.0);
    model = glm::rotate(glm::mat4(), glm::radians(45.0f + i++ / 2), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 view = glm::lookAt(cam.pos+glm::vec3(0.0f,0.0f, 0.7f), cam.lookAt, cam.up);
    glm::mat4 projection = glm::perspective(glm::radians(60.0f),1.0f,0.1f,100.0f);
    glm::mat4 transform = projection * view * model;
    return transform;
} 

void Object::setShaders(Shader vertex, Shader fragment){
    vertexShaderID = vertex.id;
    fragmentShaderID = fragment.id;

    glBindVertexArray(VAO);

	shaderProgram = glCreateProgram(); 

	glAttachShader(shaderProgram, vertexShaderID);
	glAttachShader(shaderProgram, fragmentShaderID);
	glLinkProgram(shaderProgram);
}