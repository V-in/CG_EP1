#ifndef BRESENHAM
#define BRESENHAM
#include <cmath>
#include "Primitives.h"
#include <iostream>


extern void putPixel(glm::tvec2<int>,  glm::tvec3<unsigned char>);

//----------------------------------------//
namespace Transformations{
    //Transformations to be applied according to input vector's octant
    glm::mat2 transformations[8] = {{ 1, 0, 0, 1},
                                    { 0, 1, 1, 0},
                                    { 0,-1, 1, 0},
                                    {-1, 0, 0, 1},
                                    {-1, 0, 0,-1},
                                    { 0,-1,-1, 0},
                                    { 0, 1,-1, 0},
                                    { 1, 0, 0,-1}};
    //Inverses
    glm::mat2 inverse_transform[8] ={{ 1, 0, 0, 1},
                                     { 0, 1, 1, 0},
                                     { 0, 1,-1, 0},
                                     {-1, 0, 0, 1},
                                     {-1, 0, 0,-1},
                                     { 0,-1,-1, 0},
                                     { 0, -1,1, 0},
                                     { 1, 0, 0,-1}};
};


//---------------Helpers------------------//
inline int getOctant(Position p){
    if(abs(p.y) > abs(p.x)){
        if(p.x<0)
            return (p.y<0)? 6 : 3;
        else
            return (p.y<0)? 7 : 2;
    }
    else{
        if(p.x<0)
            return (p.y<0)? 5 : 4;
        else
            return (p.y<0)? 8 : 1;  
    }
}

inline glm::mat2& getT(int octant){
    return Transformations::transformations[octant-1];
}

inline glm::mat2& getInverseT(int octant){
    return Transformations::inverse_transform[octant-1];
} 

inline int dy(Vertex a, Vertex b){
	return b.pos.y - a.pos.y;
}

inline int dx(Vertex a, Vertex b){
	return b.pos.x - a.pos.x;
}

inline float slope(Vertex a,Vertex b){
	return (float)dy(a,b) / (float)dx(a,b);
}

inline void bhmLine(Vertex a_, Vertex b_, glm::mat2 transform, glm::mat2 inverseTransform){
    //Setup////////////////////////////////////////////////
   	Vertex a = a_;
    Vertex b = b_;
    Color color0 = a_.color;
    Color colorI = a_.color;
    float stepR, stepG, stepB;

    //Project vertices into the vector space upon which Bresenham's algorithm works
    a.pos = transform*a.pos;
    b.pos = transform*b.pos;
       
    int dX = dx(a,b);
	int dY = dy(a,b);
	int thresh = dX/2;
	int ry = 0;
	int j = a.pos.y;

    putPixel(a_.pos, a.color);
    //////////////////////////////////////////////////////
	for(int i = a.pos.x + 1, c = 1; i < b.pos.x; c++,i++){
		ry += dY;
		if(ry > thresh){
			j++;
			ry -= dX;
		}
        //Color interpolation
        stepR = (b_.color.r - a_.color.r)/(float)dX;
        stepG = (b_.color.g - a_.color.g)/(float)dX;
        stepB = (b_.color.b - a_.color.b)/(float)dX;
        colorI.r = color0.r + c*stepR;
        colorI.g = color0.g + c*stepG;
        colorI.b = color0.b + c*stepB;
        /////////////////////
		putPixel(inverseTransform * Position(i,j) ,  colorI); 
	}
}

//----------------------------------------//
void drawLine(Vertex& fst,Vertex& snd){
    Position a = fst.pos;
    Position b = snd.pos;

    int octant = getOctant(b-a);
    bhmLine(fst, snd, getT(octant), getInverseT(octant) );
}
void drawLine(Vertex&& fst,Vertex&& snd){
    Position a = fst.pos;
    Position b = snd.pos;

    int octant = getOctant(b-a);
    bhmLine(fst, snd, getT(octant), getInverseT(octant) );
}
#endif