#pragma once
#include "Entity.h"
#include "SceneObjectFactory.h"
#include "SceneObjectType.h"
#include <map>

namespace nail {
    class SceneManager {
    public:
        using SceneObjectFactoryTable = std::map<SceneObjectType, ref<SceneObjectFactory>>;

        ref<Entity> createEntity(std::string entity_name, std::string resource_path);
        void addSceneObjectFactoty(SceneObjectType type, ref<SceneObjectFactory> factory);
        ref<SceneObjectFactory> getSceneObjectFactoty(SceneObjectType type);
    private:
        SceneObjectFactoryTable _scene_object_factotys;
    };
}