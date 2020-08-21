#pragma once
#include "common/ref.h"
#include "SceneObject.h"
#include <map>
#include "common/GUID.h"

namespace nail {
    class SceneNode {
        GUID _id;
        ref<SceneObject> _element;
        std::map<GUID, ref<SceneNode>> _childs;
    public:
        SceneNode(GUID id);
        bool delChild(GUID id);
        bool addChild(ref<SceneNode>);
        void attachSceneObject(ref<SceneObject>);
        ref<SceneNode> findChild();
    };
}