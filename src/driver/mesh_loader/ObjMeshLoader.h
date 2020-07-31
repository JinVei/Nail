#pragma once
#include "scene/MeshLoader.h"
namespace nail {
    class ObjMeshLoader : public MeshLoader {
        ref<Mesh> load(String path) override;
    };
}