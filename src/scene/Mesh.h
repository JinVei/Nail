#pragma once
#include "common/ref.h"
#include "common/Tree.h"
#include "VertexData.h"
#include "Material.h"
#include "Resource.h"
#include <vector>

namespace nail {
    class Mesh : public Resource{
        // AABB
    public:
        virtual ref<VertexData> getVertexData() = 0;
        virtual void setVertexData(ref<VertexData> vertex_data) = 0;
        virtual ref<Material> getMaterial() = 0;
        virtual void setMaterial(ref<Material> material) = 0;
    };
    using MeshPtr = ref<Mesh>;
    using MeshParentIndex = int;
    using MeshList = std::vector<MeshPtr>;
    using MeshTree = Tree<MeshList>;
    using MeshTreeRs = ResourceWrapper<ref<MeshTree>>;
}