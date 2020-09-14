#include "OpenglVertexBufferFactory.h"
#include "OpenglVertexBuffer.h"
#include "OpenglVertexAttribIndex.h"
#include "common/assert.h"

using namespace nail;

ref<RenderVertexBuffer> OpenglVertexBufferFactory::createVertexBuffer(
    VertexDataDescription descr, 
    std::vector<float>& vertex_buffer,
    std::vector<unsigned int>& indices_buffer)
{
    NAIL_ASSERT( 0 < vertex_buffer.size() && 0 < descr._vertex_num && descr._vertex_offset != descr.unset);

    auto gl_vertex_buffer = ref<OpenglVertexBuffer>(new OpenglVertexBuffer(vertex_buffer));
    if (0 < descr._vertex_indices_num) {
        NAIL_ASSERT( 0 < indices_buffer.size());
        gl_vertex_buffer->setIndices(indices_buffer);
    }
    int64_t vertex_num = descr._vertex_num;
    int64_t stride = descr._stride;

    gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::Vertex), descr._vertex_size, stride, descr._vertex_offset);

    if (descr._normal_offset != descr.unset) {
        gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::Normal), descr._normal_size, stride, descr._normal_offset);
    }

    if (descr._texture_coord_offset != descr.unset) {
        gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::TextureCoord), descr._texture_coord_size, stride, descr._texture_coord_offset);
    }

    if (descr._tangent_offset != descr.unset) {
        gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::Tangent), descr._tangent_size, stride, descr._tangent_offset);
    }

    if (descr._bitangent_offset != descr.unset) {
        gl_vertex_buffer->setAttribPointer(static_cast<GLuint>(OpenglVertexAttribIndex::Bitangent), descr._bitangent_size, stride, descr._bitangent_offset);
    }

    return gl_vertex_buffer;
}