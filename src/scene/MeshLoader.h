#pragma once
#include "common/ref.h"
#include "Mesh.h"
namespace nail {
    class MeshLoader {
    public:
        virtual ref<Mesh> load(String path) = 0;
    };
}