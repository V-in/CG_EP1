objects := $(wildcard ./src/*.cpp)

all:
	g++ -std=c++14 -Wall ${objects} main.cpp  -lGLEW -lglfw -lassimp -lGL -lGLU -o build/main  && ./build/main
