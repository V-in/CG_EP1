#include <iostream>
#ifndef __LOADER__
#define __LOADER__
#include <string>
#include <fstream>
#include <glm/glm.hpp>
#include <sstream>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <functional>
#include <assimp/scene.h>

int loadMesh( const std::string file_name, std::function<void(glm::dvec3,glm::dvec3,glm::dvec3)> function);
std::string loadShader(const std::string file_name);
#endif