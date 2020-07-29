#pragma once
namespace nail {
    class Mesh {
        // VertexData
        // VertexData->buf
        // VertexData->VertexDescription
        // IndexData
    public:
        virtual void use() = 0;
    };
}