#pragma once
#include "common/ref.h"
#include "SceneObject.h"
#include <map>
#include "common/GUID.h"
#include "Movable.h"
#include <functional>
#include "IRotatable.h"

namespace nail {
    class SceneNode : public SceneObject, public Movable, public IRotatable {
        ref<SceneObject> _element;
        std::map<GUID, ref<SceneNode>> _childs;
    public:
        SceneNode(wref<SceneManager> manager);
        SceneNode(wref<SceneManager> manager, ref<SceneObject>);
        bool delChild(GUID id);
        bool addChild(ref<SceneNode>);
        std::map<GUID, ref<SceneNode>> getChilds();
        ref<SceneNode> getChild(GUID);

        void setElement(ref<SceneObject>);
        ref<SceneObject> findSceneObject(GUID id);
        void traverseSceneObject(std::function<bool(ref<SceneObject>)> callback);
        ref<SceneObject> getElement(); //
        void rotate(float angle, Axis axis) override;
    };
}