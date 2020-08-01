#pragma once
#include "common/ref.h"
#include "Mesh.h"
#include <vector>
namespace nail {
    using ExtensionName = std::string_view;
    class MeshLoader {
    public:
        virtual MeshTree load(ConstString path) = 0;
    };
}