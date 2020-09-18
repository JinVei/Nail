#pragma once
#include "common/ref.h"
#include "SceneObject.h"
#include "SceneObjectFactory.h"
#include "MeshLoader.h"
#include "Entity.h"

namespace nail {
    class EntityFactory : public SceneObjectFactory {
    private:
        ref<SceneObject> createImpl(ParamList param_list) override;
        ref<EntityNode> _createEntityRecursive(ref<MeshTree>);
    public:
        EntityFactory(wref<SceneManager> manager);
    };
    struct EntityFactoryParamName {
        static ConstString RESOURCE_PATH;
        static ConstString ENTITY_NAME;
    };
}