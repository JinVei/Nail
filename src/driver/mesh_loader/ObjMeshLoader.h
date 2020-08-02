#pragma once
#include "scene/MeshLoader.h"
namespace nail {
    class ObjMeshLoader : public MeshLoader {
    public:
        ref<MeshTree> load(ConstString path) override;
    private:
        ExtensionName _extension_name = "obj";
    };
}