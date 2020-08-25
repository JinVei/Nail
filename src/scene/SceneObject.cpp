#include "SceneObject.h"

using namespace nail;

SceneObject::SceneObject(wref<SceneManager> owner) {
    _owner = owner;
    _id = GuidCreatetor::create();
}

wref<SceneManager> SceneObject::getManager() {
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