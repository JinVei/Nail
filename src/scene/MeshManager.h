#pragma once
#include "common/ref.h"
#include "Mesh.h"
#include "MeshLoader.h"
#include "ResourceManager.h"

namespace nail
{
    class MeshManager : public ResourceManager {
    private:
        std::map<ExtensionName, ref<MeshLoader>> _mesh_loaders;
        wref<MeshManager> _self;
    public:
        MeshManager();
        void setSelf(wref<MeshManager>);
        ref<MeshTree> retrieveOrCreate(ConstString path);
        bool registerMeshLoader(ExtensionName extend_name, ref<MeshLoader> loader);

    };
} // namespace nail
