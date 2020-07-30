#include "SceneManager.h"
using namespace nail;

ref<Entity> SceneManager::createEntity(std::string entity_name, std::string resouce_path) {
    ParamList param_list;
    param_list["name"] = entity_name;
    param_list["resouce_path"] = resouce_path;
    ref<SceneObjectFactoty> factoty = getSceneObjectFactoty(SceneObjectType::ENTITY);
    if (factoty == nullptr) {
        return nullptr;
    }
    factoty->create(param_list);
}

ref<SceneObjectFactoty> SceneManager::getSceneObjectFactoty(SceneObjectType type) {
    if (_scene_object_factotys.find(type) == _scene_object_factotys.end()) {
        JV_ASSERT(false && _scene_object_factotys.find(type) == _scene_object_factotys.end());
        return nullptr;
    }
    return _scene_object_factotys[type];
}
void SceneManager::addSceneObjectFactoty(SceneObjectType type, ref<SceneObjectFactoty> factory) {
    _scene_object_factotys[type] = factory;
}