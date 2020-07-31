#pragma once
#include "scene/Mesh.h"
#include "Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace nail {
    class OGLMesh: public Mesh {
    public:
        struct Vertex {
            glm::vec3 position;
            glm::vec3 normal;
            glm::vec2 texCoords;
            glm::vec3 tangent;
            glm::vec3 bitangent;
        };
        enum class VertexDrawMode {
            Arrays,
            Elements,
        };
        void use() override;
        VertexDrawMode getVertexIndexMode();
        int getVertexNum();
        int getVertexElementNum();
    private:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<ref<Texture>> textures;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
    };
}