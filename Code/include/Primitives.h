#ifndef PIXEL_
#define PIXEL_
#include <glm/glm.hpp>

using Color = glm::tvec3<unsigned char>;
using Position = glm::tvec2<int>;


struct Vertex{
    Color color;
    Position pos;
    public:
    Vertex(){};
    Vertex(Position p, Color c) : pos(p), color(c){}
    Vertex(int x, int y, unsigned char r, unsigned char g, unsigned char b) :  pos(x,y),color(r,g,b){}
    Vertex(int x, int y, Color c) : pos(x,y), color(c){}
};

extern void drawLine(Vertex&, Vertex&);
extern void drawLine(Vertex&&, Vertex&&);


namespace Colors{
    Color red(255,0,0);
    Color green(0,255,0);
    Color blue(0,0,255);
};

class Triangle{
    Vertex vertices[3];
    public:
    Triangle(){}
    Triangle(Vertex a, Vertex b, Vertex c);
    void draw();
};

Triangle::Triangle(Vertex a, Vertex b, Vertex c){
    vertices[0] = a;
    vertices[1] = b;
    vertices[2] = c;
}

void Triangle::draw(){
    drawLine(vertices[0], vertices[1]);
    drawLine(vertices[0], vertices[2]);
    drawLine(vertices[1], vertices[2]);
}
#endif