#include "OpenglVertexBufferFactory.h"
#include "OpenglVertexBuffer.h"
#include "OpenglVertexAttribIndex.h"
#include "common/assert.h"

using namespace nail;

ref<RenderVertexBuffer> OpenglVertexBufferFactory::createVertexBuffer(VertexDataDescription descr, float* vertex_buffer, unsigned int* indices_buffer) {
    NAIL_ASSERT(vertex_buffer != nullptr && 0 < descr._vertex_num && descr._vertex_offset != descr.unset);

    auto gl_vertex_buffer = ref<OpenglVertexBuffer>(new OpenglVertexBuffer(vertex_buffer, descr._vertex_num));
    if (0 < descr._vertex_indices_num) {
        NAIL_ASSERT(indices_buffer != nullptr);
        gl_vertex_buffer->setIndices(indices_buffer, descr._vertex_indices_num);
    }
    int64_t vertex_num = descr._vertex_num;
    int64_t stride = descr._stride;

    gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::Vertex), vertex_num, stride, descr._vertex_offset);

    if (descr._normal_offset != descr.unset) {
        gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::Normal), vertex_num, stride, descr._normal_offset);
    }

    if (descr._texture_coord_offset != descr.unset) {
        gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::TextureCoord), vertex_num, stride, descr._texture_coord_offset);
    }

    if (descr._tangent_offset != descr.unset) {
        gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::Tangent), vertex_num, stride, descr._tangent_offset);
    }

    if (descr._bitangent_offset != descr.unset) {
        gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::Bitangent), vertex_num, stride, descr._bitangent_offset);
    }

    return gl_vertex_buffer;
}