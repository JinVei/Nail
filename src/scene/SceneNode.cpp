#include "SceneNode.h"

using namespace nail;

SceneNode::SceneNode(GUID id) {
    _id = id;
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

ref<SceneNode> SceneNode::findChild() {
    if (_childs.size() == 0) {
        return nullptr;
    }

    for (auto it_child : _childs) {
        auto child = it_child.second;
        auto found = child->findChild();
        if (found != nullptr) {
            return found;
        }
    }
    return nullptr;
}