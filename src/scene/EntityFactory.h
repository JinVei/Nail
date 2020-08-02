#pragma once
#include "common/ref.h"
#include "SceneObject.h"
#include "SceneObjectFactory.h"
#include "MeshLoader.h"
#include "Entity.h"

namespace nail {
    class EntityFactory : public SceneObjectFactory {
    public:
        ref<SceneObject> createImpl(ParamList param_list) override;
    private:
        ref<Entity> _createEntityRecursive(ref<MeshTree>);

        ref<MeshLoader> _mesh_loader;
    };
    struct EntityFactoryParamName {
        static ConstString RESOURCE_PATH;
        static ConstString ENTITY_NAME;
    };
}