#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <iostream>
#include <cassert>
#include "./include/bresenham.h"
#include <glm/glm.hpp>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(Position pos, Color color){
	//Draw only pixels that are within the window
	if(pos.x < IMAGE_WIDTH && pos.y < IMAGE_HEIGHT){
		int fstByte = ((pos.y) * IMAGE_WIDTH + pos.x)*sizeof(unsigned char)*4;
		FBptr[fstByte] = color.r;
		FBptr[fstByte + sizeof(unsigned char)] = color.g;
		FBptr[fstByte + sizeof(unsigned char)*2] = color.b;
	}
}




#endif // _MYGL_H_

