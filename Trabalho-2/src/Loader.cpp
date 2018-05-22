#include "../helpers/loaders.h"
int loadMesh( const std::string file_name, std::function<void(glm::dvec3,glm::dvec3,glm::dvec3)> function)
{
    std::ifstream fin( file_name.c_str() );
    if( !fin.fail() )
        fin.close();
    else{
        std::cerr << "Couldn't open file: " << file_name << std::endl;
        return EXIT_FAILURE;
    }
    Assimp::Importer assimp_importer;
    const aiScene* assimp_scene_ = assimp_importer.ReadFile( file_name, aiProcess_Triangulate );
    if( !assimp_scene_ ){
        std::cerr << assimp_importer.GetErrorString() << std::endl;
        return EXIT_FAILURE;
    }
    if( assimp_scene_-> HasMeshes() ){
        for( unsigned int mesh_id = 0; mesh_id < assimp_scene_->mNumMeshes; mesh_id++ ){
            const aiMesh *mesh_ptr = assimp_scene_->mMeshes[mesh_id];
            for( unsigned int vertex_id = 0; vertex_id < mesh_ptr->mNumVertices;vertex_id += 3 )    {
                const aiVector3D *vertex_ptr = &mesh_ptr->mVertices[vertex_id];
                glm::dvec3 v0{ vertex_ptr[0].x, vertex_ptr[0].y, vertex_ptr[0].z };
                glm::dvec3 v1{ vertex_ptr[1].x, vertex_ptr[1].y, vertex_ptr[1].z };
                glm::dvec3 v2{ vertex_ptr[2].x, vertex_ptr[2].y, vertex_ptr[2].z };
                function(v0,v1,v2);
            }
        } 
    }
    return EXIT_SUCCESS;
}

std::string loadShader(std::string file_name)
{
    std::ifstream file (file_name);
    if (!file) std::cout << "Error loading shader" << std::endl;

    std::stringstream ss;
    ss << file.rdbuf();
    file.close();

    return ss.str();
}