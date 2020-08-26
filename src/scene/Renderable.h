#pragma once
#include "Mesh.h"

namespace nail {
    class Renderable {
    public:
        virtual ~Renderable(){}
        virtual MeshList getMeshs() = 0;
    };
}