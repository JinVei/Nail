#pragma once
#include "common/ref.h"
#include "VertexData.h"
#include "Material.h"

#include <vector>

namespace nail {
    class Mesh {
        // AABB
    public:
        //virtual void use() = 0;
        virtual ref<VertexData> getVertexData() = 0;
        virtual void setVertexData(ref<VertexData> vertex_data) = 0;
        virtual ref<Material> getMaterial() = 0;
        virtual void setMaterial(ref<Material> material) = 0;
    };
    using MeshPtr = ref<Mesh>;
    using MeshParentIndex = int;
    using MeshList = std::vector<MeshPtr>;
    using MeshTree = std::vector<std::pair<MeshParentIndex,MeshList>>;
}