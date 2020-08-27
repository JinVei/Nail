#pragma once
#include "Mesh.h"
#include "common/vec.h"

namespace nail {
    class IRenderable {
    public:
        virtual ~IRenderable(){}
        virtual MeshList getMeshs() = 0;

        virtual void setModelMatrix(mat4) = 0;
        virtual mat4 getModelMatrix() = 0;
    };
}