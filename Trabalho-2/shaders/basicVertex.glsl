#version 150
in vec3 position;
uniform mat4 transform;
in vec4 color;

out vec4 theColor;
out vec3 thePosition;

void main(){
    gl_Position = vec4(position,1.0);
    gl_Position = transform * gl_Position;
    theColor = color;
    thePosition = position;
}