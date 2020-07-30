#pragma once
#include "Entity.h"
#include "SceneObjectFactoty.h"
#include "SceneObjectType.h"
#include <map>

namespace nail {
    class SceneManager {
    public:
        using SceneObjectFactotyTable = std::map<SceneObjectType, ref<SceneObjectFactoty>>;
        ref<Entity> createEntity(std::string entity_name, std::string resource_path);
        void addSceneObjectFactoty(SceneObjectType type, ref<SceneObjectFactoty> factory);
        ref<SceneObjectFactoty> getSceneObjectFactoty(SceneObjectType type);
    private:
        SceneObjectFactotyTable _scene_object_factotys;
    };
}