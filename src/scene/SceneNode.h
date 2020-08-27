#pragma once
#include "common/ref.h"
#include "SceneObject.h"
#include <map>
#include "common/GUID.h"
#include "Movable.h"
#include <functional>
#include "IRotatable.h"

namespace nail {
    class SceneNode : public Movable, IRotatable{
        GUID _id;
        ref<SceneObject> _element;
        std::map<GUID, ref<SceneNode>> _childs;
    public:
        SceneNode(GUID id);
        bool delChild(GUID id);
        bool addChild(ref<SceneNode>);
        void attachSceneObject(ref<SceneObject>);
        ref<SceneObject> findSceneObject(GUID id);
        void traverseSceneObject(std::function<bool(ref<SceneObject>)> callback);
        ref<SceneObject> getElement(); //
        void rotate(float angle, Axis axis) override;
    };
}