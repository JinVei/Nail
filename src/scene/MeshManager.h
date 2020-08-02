#pragma once
#include "common/ref.h"
#include "Mesh.h"
#include "MeshLoader.h"
#include "ResourceManager.h"
#include "Context.h"

namespace nail
{
    class MeshManager : public ResourceManager {
        friend class nail::Context;
    private:
        std::map<ExtensionName, ref<MeshLoader>> _mesh_loaders;
        static ref<MeshManager> g_mesh_mgr;
        MeshManager() {}
        static void set(ref<MeshManager>);
    public:
        ref<MeshTree> RetrieveOrCreate(ConstString path);
        bool registerMeshLoader(ExtensionName extend_name, ref<MeshLoader> loader);
        static MeshManager& singleton();

    };
} // namespace nail