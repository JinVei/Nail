#include "SceneNode.h"

using namespace nail;

SceneNode::SceneNode(GUID id) {
    _id = id;
}

SceneNode::SceneNode(GUID id, ref<SceneObject> scene_object): SceneNode(id) {
    _element = scene_object;
}

bool SceneNode::delChild(GUID id) {
    auto found = _childs.find(id);
    if (found == _childs.end()) {
        return false;
    }

    _childs.erase(found);
    return true;

}

bool SceneNode::addChild(ref<SceneNode> node) {
    if (node == nullptr) {
        return false;
    }

    _childs.insert(std::pair(node->_id, node));
    return true;
}

void SceneNode::attachSceneObject(ref<SceneObject> scene_obj) {
    _element = scene_obj;
}

ref<SceneObject> SceneNode::findSceneObject(GUID id) {
    auto scene_obj = getElement();
    if (scene_obj != nullptr && scene_obj->getGUID() == id) {
        return scene_obj;
    }

    for (auto it_child : _childs) {
        auto child = it_child.second;

        auto found = child->findSceneObject(id);
        if (found != nullptr) {
            return found;
        }
    }
    return nullptr;
}

ref<SceneObject> SceneNode::getElement() {
    return _element;
}

void SceneNode::traverseSceneObject(std::function<bool(ref<SceneObject>)> callback) {
    if (_element != nullptr) {
        callback(_element);
    }
    for (auto& node : _childs) {
        if (node.second->getElement() != nullptr) {
            callback(_element);
        }
    }
}

void SceneNode::rotate(float angle, Axis axis) {
    auto rotateHandle = [&](ref<SceneObject> scene_obj) -> bool {
        auto rotatable_obj =  std::dynamic_pointer_cast<IRotatable>(scene_obj);
        if (rotatable_obj != nullptr) {
            rotatable_obj->rotate(angle, axis);
        }
        return true;
    };
    traverseSceneObject(rotateHandle);
}