#pragma once
#include "common/ref.h"
#include "Mesh.h"
#include "MeshLoader.h"

namespace nail
{
    class MeshManager {
    public:
        ref<Mesh> RetrieveOrCreate(ConstString name, ConstString path);
        bool registerMeshloader(ExtensionName extend_name, ref<MeshLoader> loader);
    private:
        std::map<ExtensionName, ref<MeshLoader>> _mesh_loaders;
    };
} // namespace nail
