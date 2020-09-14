#include "SceneManager.h"
#include "common/assert.h"
#include "EntityFactory.h"
#include "common/assert.h"

using namespace nail;

SceneManager::SceneManager() {
    _root = createSceneNode();
}

SceneManager::~SceneManager() {
}

void SceneManager::setSelf(wref<SceneManager> self) {
    _self = self;
}

ref<EntityNode> SceneManager::createEntity(std::string entity_name, std::string resouce_path) {
    ParamList param_list;
    param_list[EntityFactoryParamName::ENTITY_NAME] = entity_name;
    param_list[EntityFactoryParamName::RESOURCE_PATH] = resouce_path;
    ref<SceneObjectFactory> factoty = getSceneObjectFactoty(SceneObjectType::ENTITY);
    if (factoty == nullptr) {
        NAIL_ASSERT(false && (factoty == nullptr));
        return nullptr;
    }
    ref<SceneObject> scene_object = factoty->create(param_list); 
    ref<EntityNode> entity =  std::dynamic_pointer_cast<EntityNode>(scene_object);
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
    return ref<SceneNode>(new SceneNode(_self));
}

ref<SceneNode> SceneManager::createSceneNode(ref<SceneObject> scene_obj) {
    return ref<SceneNode>(new SceneNode(_self, scene_obj));
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

// ref<Light> SceneManager::createLight() {
//     auto factory = getSceneObjectFactoty(SceneObjectType::LIGHT);
//     NAIL_ASSERT(factory != nullptr);
//     ParamList param_list;
//     ref<SceneObject> scence_obj = factory->create(param_list);
//     ref<Light> light = std::dynamic_pointer_cast<Light>(scence_obj);
//     if (light != nullptr) {
//         _lights.push_back(light);
//     }

//     return light;
// }

ref<PointLight> SceneManager::createPointLight(vec3 position, Color color) {
    auto light = ref<PointLight>(new PointLight(_self, position, color));
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

// ref<Camera> SceneManager::createCamera() {
//     auto factory = getSceneObjectFactoty(SceneObjectType::LIGHT);
//     NAIL_ASSERT(factory != nullptr);
//     ParamList param_list;
//     ref<SceneObject> scence_obj = factory->create(param_list);
//     ref<Camera> camera = std::dynamic_pointer_cast<Camera>(scence_obj);
//     if (camera != nullptr) {
//         _cameras[camera->getGUID()] = camera;
//     }

//     return camera;
// }
ref<Camera> SceneManager::createCamera(vec3 direction, Position pos, float fovy, float near, float far) {
    auto camera = ref<Camera>(new Camera(_self, direction, pos, fovy, near, far));
    _cameras[camera->getGUID()] = camera;
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

ref<SceneNode> SceneManager::getRootNode() {
    return _root;
}

void SceneManager::render() {
    for( auto& camera : _cameras) {
        camera.second->render();
    }
}