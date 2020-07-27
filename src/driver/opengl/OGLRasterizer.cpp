

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "OGLRasterizer.h"
#include "OGLMesh.h"
#include "OGLShader.h"

using namespace nail;

void OGLRasterizer::draw(ref<Mesh> mesh, ref<Shader> shader) {
    if (mesh != nullptr && std::dynamic_pointer_cast<OGLMesh>(mesh) != nullptr) {
        mesh->use();
    }
    ref<OGLMesh>oglMesh = std::dynamic_pointer_cast<OGLMesh>(mesh);

    if (shader != nullptr && std::dynamic_pointer_cast<OGLShader>(shader) != nullptr) {
        shader->use();
    }
    ref<OGLShader> oglShader = std::dynamic_pointer_cast<OGLShader>(shader);

    OGLMesh::VertexDrawMode mode =  oglMesh->getVertexIndexMode();
    if (mode == OGLMesh::VertexDrawMode::Arrays) {
        glDrawArrays(GL_TRIANGLES, 0, oglMesh->getVertexNum());
    } else if (mode == OGLMesh::VertexDrawMode::Elements) {
        glDrawElements(GL_TRIANGLES, oglMesh->getVertexElementNum(), GL_UNSIGNED_INT, 0);
    }
}