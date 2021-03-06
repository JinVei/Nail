#pragma once
#include "common/ref.h"
#include "Mesh.h"
#include <vector>
namespace nail {
    using ExtensionName = std::string_view;
    class MeshLoader {
    public:
        virtual ~MeshLoader(){}
        virtual ref<MeshTree> load(ConstString path) = 0;
        virtual ExtensionName getExtensionName() = 0;
    };
}