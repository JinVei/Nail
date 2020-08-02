#include "SceneManager.h"
#include "common/assert.h"
#include "EntityFactory.h"

using namespace nail;

SceneManager* nail::g_scene_manager = nullptr;

ref<Entity> SceneManager::createEntity(std::string entity_name, std::string resouce_path) {
    ParamList param_list;
    param_list[EntityFactoryParamName::ENTITY_NAME] = entity_name;
    param_list[EntityFactoryParamName::RESOURCE_PATH] = resouce_path;
    ref<SceneObjectFactory> factoty = getSceneObjectFactoty(SceneObjectType::ENTITY);
    if (factoty == nullptr) {
        NAIL_ASSERT(false && (factoty == nullptr));
        return nullptr;
    }
    ref<SceneObject> scene_object = factoty->create(param_list); 
    ref<Entity> entity =  std::dynamic_pointer_cast<Entity>(scene_object);
    NAIL_ASSERT(entity != nullptr);

    return entity;
}

ref<SceneObjectFactory> SceneManager::getSceneObjectFactoty(SceneObjectType type) {
    if (_scene_object_factotys.find(type) == _scene_object_factotys.end()) {
        NAIL_ASSERT(false && _scene_object_factotys.find(type) == _scene_object_factotys.end());
        return nullptr;
    }
    return _scene_object_factotys[type];
}
void SceneManager::addSceneObjectFactoty(SceneObjectType type, ref<SceneObjectFactory> factory) {
    _scene_object_factotys[type] = factory;
}