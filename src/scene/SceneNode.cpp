#include "SceneNode.h"

using namespace nail;

SceneNode::SceneNode(wref<SceneManager> manager): SceneObject(manager, SceneObjectType::NODE) {
}

SceneNode::SceneNode(wref<SceneManager> manager, ref<SceneObject> scene_object): SceneNode(manager) {
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

    _childs.insert(std::pair(node->getGUID(), node));
    return true;
}

std::map<GUID, ref<SceneNode>> SceneNode::getChilds() {
    return _childs;
}

ref<SceneNode> SceneNode::getChild(GUID id) {
    auto found = _childs.find(id);
    if (found == _childs.end()) {
        return nullptr;
    }
    return found->second;
}


void SceneNode::setElement(ref<SceneObject> scene_obj) {
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
            callback(node.second->getElement());
        }
        node.second->traverseSceneObject(callback);
    }
}

void SceneNode::rotate(float angle, Axis axis) {
    auto rotateHandle = [&angle, &axis](ref<SceneObject> scene_obj) -> bool {
        auto rotatable_obj =  ref_cast<IRotatable>(scene_obj);
        if (rotatable_obj != nullptr) {
            rotatable_obj->rotate(angle, axis);
        }
        return true;
    };
    traverseSceneObject(rotateHandle);
}

void SceneNode::scale(vec3 v) {
    auto scaleHandle = [&v](ref<SceneObject> scene_obj) -> bool {
        auto rotatable_obj =  ref_cast<IScalable>(scene_obj);
        if (rotatable_obj != nullptr) {
            rotatable_obj->scale(v);
        }
        return true;
    };
    traverseSceneObject(scaleHandle);
}