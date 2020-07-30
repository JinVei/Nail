#pragma once
#include "SceneObject.h"
#include "Mesh.h"
#include "common/ref.h"
namespace nail {
    class Entity : public SceneObject {
        ref<Mesh> _mesh;
    };
}