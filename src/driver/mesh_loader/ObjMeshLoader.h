#pragma once
#include "scene/MeshLoader.h"
namespace nail {
    class ObjMeshLoader : public MeshLoader {
    private:
        ExtensionName _extension_name = "obj";
    public:
        ref<MeshTree> load(ConstString path) override;
        ExtensionName getExtensionName() override;
    };
}