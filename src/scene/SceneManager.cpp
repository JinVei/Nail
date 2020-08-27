#include "SceneManager.h"
#include "common/assert.h"
#include "EntityFactory.h"
#include "common/assert.h"

using namespace nail;

ref<SceneManager> SceneManager::_singleton = nullptr;

ref<SceneManager> SceneManager::singleton() {
    NAIL_ASSERT(_singleton != nullptr);
    return _singleton;
}

void SceneManager::set(ref<SceneManager> mgr) {
    _singleton = mgr;
}

SceneManager::SceneManager() {
    _root = createSceneNode();
}

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

ref<SceneNode> SceneManager::createSceneNode() {
    return ref<SceneNode>(new SceneNode(GuidCreatetor::create()));
}


ref<Light> SceneManager::getLight(GUID id) {
    for (auto& light_it : _lights) {
        if (light_it->getGUID() == id) {
            return light_it;
        }
    }
    return nullptr;
}

std::list<ref<Light>> SceneManager::getLights() {
    return _lights;
}

ref<Light> SceneManager::createLight() {
    auto factory = getSceneObjectFactoty(SceneObjectType::LIGHT);
    NAIL_ASSERT(factory != nullptr);
    ParamList param_list;
    ref<SceneObject> scence_obj = factory->create(param_list);
    ref<Light> light = std::dynamic_pointer_cast<Light>(scence_obj);
    if (light != nullptr) {
        _lights.push_back(light);
    }

    return light;
}

void SceneManager::deleteLight(GUID id) {
    for (auto light_it = _lights.begin(); light_it != _lights.end(); light_it++) {
        if ((*light_it)->getGUID() == id) {
            _lights.erase(light_it);
            return;
        }
    }
}

ref<Camera> SceneManager::getCamera(GUID id) {
    auto found = _cameras.find(id);
    if (found == _cameras.end()) {
        return nullptr;
    }
    return found->second;
}

ref<Camera> SceneManager::createCamera() {
    auto factory = getSceneObjectFactoty(SceneObjectType::LIGHT);
    NAIL_ASSERT(factory != nullptr);
    ParamList param_list;
    ref<SceneObject> scence_obj = factory->create(param_list);
    ref<Camera> camera = std::dynamic_pointer_cast<Camera>(scence_obj);
    if (camera != nullptr) {
        _cameras[camera->getGUID()] = camera;
    }

    return camera;
}

void SceneManager::deleteCamera(GUID id) {
    auto found = _cameras.find(id);
    if (found != _cameras.end()) {
        _cameras.erase(found);
    }
}

std::vector<ref<IRenderable>> SceneManager::getAllRenderableSceneObjects() {
    std::vector<ref<IRenderable>> renderable_objs;
    auto handle = [&](ref<SceneObject> scene_obj) -> bool {
        auto renderable_obj = std::dynamic_pointer_cast<IRenderable>(scene_obj);
        if (renderable_obj != nullptr) {
            renderable_objs.push_back(renderable_obj);
        }
        return true;
    };

    _root->traverseSceneObject(handle);

    return std::move(renderable_objs);
}