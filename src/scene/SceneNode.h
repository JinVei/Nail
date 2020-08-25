#pragma once
#include "common/ref.h"
#include "SceneObject.h"
#include <map>
#include "common/GUID.h"
#include "Movable.h"

namespace nail {
    class SceneNode : public Movable {
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