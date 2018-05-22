#include "main.h"
#include <glm/gtx/transform.hpp>
//-----------------------------------------------------------------------------
	

void cast(int n){
	for(float i = 0; i <= n; i++){
		//RightSide
		drawLine(Vertex(Position(IMAGE_WIDTH/2 - 1, IMAGE_HEIGHT/2 - 1),Colors::red), Vertex(Position(IMAGE_WIDTH-1,0 + i/n * (IMAGE_HEIGHT - 1) ), Colors::green));		
		//LeftSide
		drawLine(Vertex(Position(IMAGE_WIDTH/2 - 1, IMAGE_HEIGHT/2 - 1),Colors::red), Vertex(Position(0, 0 + i/n * (IMAGE_HEIGHT -1)), Colors::green));	
		//UpperSide
		drawLine(Vertex(Position(IMAGE_WIDTH/2 - 1, IMAGE_HEIGHT/2 - 1),Colors::red), Vertex(Position(0 + i/n * (IMAGE_WIDTH - 1),0), Colors::blue));		
		//LowerSide
		drawLine(Vertex(Position(IMAGE_WIDTH/2 - 1, IMAGE_HEIGHT/2 - 1),Colors::red), Vertex(Position(0 + i/n * (IMAGE_WIDTH - 1),IMAGE_HEIGHT - 1), Colors::green));		
	}
}

Vertex v1, v2, v3;
Triangle t;

int argc_;
int n;

void MyGlDraw()
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	if(argc_ > 2){
		t.draw();
	}
	else 
		cast(n);
	
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	argc_ = argc;
	if(argc == 2){
		n = std::atoi(argv[1]);
	}
	else{
		v1 = Vertex(std::atoi(argv[1]), std::atoi(argv[2]), std::atoi(argv[3]), std::atoi(argv[4]), std::atoi(argv[5]));
		v2 = Vertex(std::atoi(argv[6]), std::atoi(argv[7]), std::atoi(argv[8]), std::atoi(argv[9]), std::atoi(argv[10]));
		v3 = Vertex(std::atoi(argv[11]), std::atoi(argv[12]), std::atoi(argv[13]), std::atoi(argv[14]), std::atoi(argv[15]));
		t = Triangle(v1,v2,v3);
	}
	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	
	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

