#version 150
out vec4 outColor;
in vec4 theColor;
in vec3 thePosition;

void main(){
	float color = sqrt(sin(pow(length(thePosition),3)));
	outColor = vec4(vec3(color), 1.0);
}
