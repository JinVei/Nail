#include "SceneObject.h"

using namespace nail;

SceneObject::SceneObject(wref<SceneManager> manager) {
    _manager = manager;
    _id = GuidCreatetor::create();
}

wref<SceneManager> SceneObject::getManager() {
    return _manager;
}

void SceneObject::setName(std::string name) {
    _name = std::move(name);
}

ConstString SceneObject::getName() {
    return _name;
}

GUID SceneObject::getGUID() {
    return _id;
}