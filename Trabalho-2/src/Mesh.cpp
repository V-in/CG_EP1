#include "../include/Mesh.h"

Mesh::Mesh(std::string path_to_obj) {
    loadMesh(path_to_obj, [this](glm::dvec3 a_, glm::dvec3 b_, glm::dvec3 c_)->void{
        auto a = static_cast<glm::vec3>(a_);
        a *= 0.5f;
        auto b = static_cast<glm::vec3>(b_);
        b *= 0.5f;
        auto c = static_cast<glm::vec3>(c_);
        c *= 0.5f;

        vertices.push_back(Vertex(a));
        vertices.push_back(Vertex(b));
        vertices.push_back(Vertex(c));
    });

	
}

Mesh::Mesh(std::vector<Vertex> vertices_){
    vertices = vertices_;
}

