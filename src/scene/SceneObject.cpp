#include "SceneObject.h"

using namespace nail;

SceneObject::SceneObject(std::weak_ptr<SceneManager> owner) {
    _owner = owner;
    _id = GuidCreatetor::create();
}

std::weak_ptr<SceneManager> SceneObject::getManager() {
    return _owner;
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