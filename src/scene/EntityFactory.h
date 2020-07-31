#pragma once
#include "common/ref.h"
#include "SceneObject.h"
#include "SceneObjectFactoty.h"
#include "MeshLoader.h"
namespace nail {
    class EntityFactory : public SceneObjectFactoty {
    public:
        ref<SceneObject> createImpl(ParamList param_list) override;
    private:
        ref<MeshLoader> _mesh_loader;
    };
}