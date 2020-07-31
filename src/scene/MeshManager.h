#pragma once
#include "common/ref.h"
#include "Mesh.h"
#include "MeshLoader.h"

namespace nail
{
    class MeshManager {
        using ExtensionName = String;
    public:
        ref<Mesh> tryOrCreate();
        bool registerMeshloader(ExtensionName name, ref<MeshLoader> loader);
    private:
        std::map<ExtensionName, ref<MeshLoader>> _mesh_loaders;
    };
} // namespace nail
