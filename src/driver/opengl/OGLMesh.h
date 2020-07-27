#pragma once
#include "renderer/Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace nail {
    class OGLMesh: public Mesh {
    public:
        struct Vertex {
            glm::vec3 Position;
            glm::vec3 Normal;
            glm::vec2 TexCoords;
            glm::vec3 Tangent;
            glm::vec3 Bitangent;
        };
        enum class VertexIndexMode {
            Arrays,
            Elements,
        };
        void use() override;
        VertexIndexMode getVertexIndexMode();
        int getVertexNum();
        int getVertexElementNum();
    private:
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        unsigned int VAO;
    };
}