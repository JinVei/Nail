#include "ObjMeshLoader.h"
#include "stb_image/stb_image.h"
#include "common/assert.h"
#include "scene/VertexData.h"
#include "scene/VertexDataDescription.h"
#include "renderer/RenderSystem.h"
#include "scene/CommonMesh.h"
#include "scene/MaterialImpl.h"
#include "scene/CommonPass.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace nail;

ExtensionName ObjMeshLoader::getExtensionName() {
    return _extension_name;
}

static ref<MeshTree> processNode(aiNode *node, const aiScene *scene);
static std::vector<String> getMaterialTextures(aiMaterial *mat, aiTextureType type);
static MeshPtr processMesh(aiMesh *ai_mesh, const aiScene *scene);

ref<MeshTree> ObjMeshLoader::load(ConstString path) {
    String mesh_file_path(path);
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(String(path), aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        NAIL_ASSERT(false && (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) && importer.GetErrorString());
        return nullptr;
    }
    ref<MeshTree> mesh_tree;
    String directory = mesh_file_path.substr(0, path.find_last_of('/'));
    mesh_tree = processNode(scene->mRootNode, scene);
    return mesh_tree;
}

ref<MeshTree>  processNode(aiNode *node, const aiScene *scene) {
    // process each mesh located at the current node
    ref<MeshList> meshes = ref<MeshList>(new MeshList());
    for(unsigned int i = 0; i < node->mNumMeshes; i++) {
        // the node object only contains indices to index the actual objects in the scene. 
        // the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes->push_back(processMesh(mesh, scene));
    }

    ref<MeshTree> mesh_tree = ref<MeshTree>(new MeshTree());
    // after we've processed all of the meshes (if any) we then recursively process each of the children nodes
    mesh_tree->_data = meshes;
    
    for(unsigned int i = 0; i < node->mNumChildren; i++) {
        ref<MeshTree> sub_tree = processNode(node->mChildren[i], scene);
        mesh_tree->_childs.push_back(sub_tree);
    }
    return mesh_tree;
}

MeshPtr processMesh(aiMesh *ai_mesh, const aiScene *scene) {
    // Walk through each of the mesh's vertices
    ref<VertexData> vertex_data = ref<VertexData>(new VertexData());
    VertexDataDescription descr;
    descr._vertex_num = ai_mesh->mNumVertices;

    int offset = 0;
    // positions
    descr._vertex_offset = offset;
    offset += 3*sizeof(float);
    // normals
    descr._normal_offset = offset;
    offset += 3*sizeof(float);
    // texture coordinates
    descr._texture_coord_offset = offset;
    offset += 2*sizeof(float);
    // tangent
    descr._tangent_offset = offset;
    offset += 3*sizeof(float);
    // bitangent
    descr._bitangent_offset = offset;
    offset += 3*sizeof(float);

    descr._stride = offset;

    std::vector<float> vertex_buffer;
    vertex_buffer.resize(descr._vertex_num * offset);

    descr._vertex_indices_num = ai_mesh->mNumFaces;
    std::vector<unsigned int> vertex_indices_buffer;
    vertex_buffer.resize(descr._vertex_indices_num);

    for(unsigned int i = 0; i < ai_mesh->mNumVertices; i++)
    {
        // positions
        vertex_buffer.push_back(ai_mesh->mVertices[i].x);
        vertex_buffer.push_back(ai_mesh->mVertices[i].y);
        vertex_buffer.push_back(ai_mesh->mVertices[i].z);
        // normals
        vertex_buffer.push_back(ai_mesh->mNormals[i].x);
        vertex_buffer.push_back(ai_mesh->mNormals[i].y);
        vertex_buffer.push_back(ai_mesh->mNormals[i].z);
        // texture coordinates
        if(ai_mesh->mTextureCoords[0]) {
            vertex_buffer.push_back(ai_mesh->mTextureCoords[0][i].x);
            vertex_buffer.push_back(ai_mesh->mTextureCoords[0][i].y);
        } else {
            vertex_buffer.push_back(0.0);
            vertex_buffer.push_back(0.0);
        }
        // tangent
        vertex_buffer.push_back(ai_mesh->mTangents[i].x);
        vertex_buffer.push_back(ai_mesh->mTangents[i].y);
        vertex_buffer.push_back(ai_mesh->mTangents[i].z);
        // bitangent
        vertex_buffer.push_back(ai_mesh->mBitangents[i].x);
        vertex_buffer.push_back(ai_mesh->mBitangents[i].y);
        vertex_buffer.push_back(ai_mesh->mBitangents[i].z);
    }

    for(unsigned int i = 0; i < ai_mesh->mNumFaces; i++) {
        aiFace face = ai_mesh->mFaces[i];
        // retrieve all indices of the face and store them in the indices vector
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            vertex_indices_buffer.push_back(face.mIndices[j]);
        }
    }

    auto render_system = RenderSystem::getSingleton();
    NAIL_ASSERT(render_system != nullptr);
    auto render_vertex_buffer_factory =  render_system->getRenderVertexBufferFactory();
    NAIL_ASSERT(render_vertex_buffer_factory != nullptr);
    auto render_vertex_buffer = render_vertex_buffer_factory->createVertexBuffer(descr, &vertex_buffer[0], &vertex_indices_buffer[0]);
    
    vertex_data->setVertexDataDescription(ref<VertexDataDescription>(new  VertexDataDescription(descr)));
    vertex_data->setRenderVertexBuffer(render_vertex_buffer);

    MeshPtr mesh = MeshPtr(new CommonMesh());
    mesh->setVertexData(vertex_data);

    // process materials
    aiMaterial* ai_material = scene->mMaterials[ai_mesh->mMaterialIndex];    

    // 1. diffuse maps
    std::vector<String> diffuseMaps = getMaterialTextures(ai_material, aiTextureType_DIFFUSE);
    // 2. specular maps
    std::vector<String> specularMaps = getMaterialTextures(ai_material, aiTextureType_SPECULAR);
    // 3. normal maps
    std::vector<String> normalMaps = getMaterialTextures(ai_material, aiTextureType_HEIGHT);
    // 4. height maps
    std::vector<String> heightMaps = getMaterialTextures(ai_material, aiTextureType_AMBIENT);
    
    ref<Pass> pass = ref<Pass>(new Pass());
    pass->setDiffuseMaps(diffuseMaps[0]);
    pass->setSpecularMaps(specularMaps[0]);
    pass->setNormalMaps(normalMaps[0]);
    pass->setHeightMaps(heightMaps[0]);

    ref<Material> material = ref<Material>(new MaterialImpl());
    material->addPass(pass);
    mesh->setMaterial(material);
    
    return mesh;
}

std::vector<String> getMaterialTextures(aiMaterial *mat, aiTextureType type) {
    std::vector<String> texture_sources;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString source;
        mat->GetTexture(type, i, &source);
        texture_sources.push_back(source.C_Str());
    }
    return texture_sources;
}